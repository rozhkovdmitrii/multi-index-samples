#include <boost/multi_index_container.hpp>
#include <boost/multi_index/member.hpp>
#include <boost/multi_index/ordered_index.hpp>
#include <boost/multi_index/mem_fun.hpp>

#include "gtest/gtest.h"


#include "RecordingSession.h"

using namespace boost::multi_index;

typedef multi_index_container<
  RecSessData,
  indexed_by<
    ordered_unique
      <
        tag<RecSessData::recSessKey>,  member<RecSessData, RecSessKey, &RecSessData::_recSessKey>
      >,
    ordered_non_unique
      <
        tag<RecSessData::clientName>, const_mem_fun<RecSessData, const std::string &, &RecSessData::getClientName>
      >,
    ordered_non_unique<
      tag<RecSessData::mrId>,  member<RecSessData, int, &RecSessData::_mrId>
    >
  >
> RecSessRelations;

class ResearchOnMultiIndexTest : public testing::Test
{
public:
  virtual void SetUp() override;
  virtual void TearDown() override;

  typedef RecSessRelations::index<RecSessData::clientName>::type ClientIndex;
  typedef ClientIndex::iterator ClientIterator;
  typedef RecSessRelations::index<RecSessData::recSessKey>::type KeyIndex;
  typedef KeyIndex::iterator KeyIterator;
  typedef RecSessRelations::index<RecSessData::mrId>::type MRIdIndex;
  typedef MRIdIndex::iterator MRIterator;

protected:
  RecSessRelations _recSessRelations;

  static RecSessData _sample_dmitrii_1;
  static RecSessData _sample_dmitrii_2;
  static RecSessData _sample_dmitrii_3;
  static RecSessData _sample_ivan_1;
  static RecSessData _sample_ivan_2;
  static RecSessData _sample_ivan_3;
};

RecSessData ResearchOnMultiIndexTest::_sample_dmitrii_1 = { {"dmitrii", 1}, {"rtp-receive.host", "calluid", {"rtp.host", 20002}, {"rtp.host", 20004}}, 1 };
RecSessData ResearchOnMultiIndexTest::_sample_dmitrii_2 = { {"dmitrii", 2}, {"rtp-receive.host", "calluid", {"rtp.host", 20006}, {"rtp.host", 20008}}, 2 };
RecSessData ResearchOnMultiIndexTest::_sample_dmitrii_3 = { {"dmitrii", 3}, {"rtp-receive.host", "calluid", {"rtp.host", 20010}, {"rtp.host", 20012}}, 3 };
RecSessData ResearchOnMultiIndexTest::_sample_ivan_1 = { {"ivan", 1}, {"rtp-receive.host", "calluid", {"rtp.host", 20014}, {"rtp.host", 20016}}, 1 };
RecSessData ResearchOnMultiIndexTest::_sample_ivan_2 = { {"ivan", 2}, {"rtp-receive.host", "calluid", {"rtp.host", 20018}, {"rtp.host", 20020}}, 2 };
RecSessData ResearchOnMultiIndexTest::_sample_ivan_3 = { {"ivan", 3}, {"rtp-receive.host", "calluid", {"rtp.host", 20022}, {"rtp.host", 20024}}, 3 };


void ResearchOnMultiIndexTest::SetUp()
{
  _recSessRelations.insert(_sample_dmitrii_1);
  _recSessRelations.insert(_sample_ivan_1);
  _recSessRelations.insert(_sample_ivan_2);
  _recSessRelations.insert(_sample_dmitrii_2);
  _recSessRelations.insert(_sample_ivan_3);
  _recSessRelations.insert(_sample_dmitrii_3);
}
//---------------------------------------------------------------------------------
void ResearchOnMultiIndexTest::TearDown()
{
  _recSessRelations.clear();
}
//---------------------------------------------------------------------------------
// Пытаемся завести в коллекцию две записи с одинаковым RecSessKey.
// Не получается.
TEST_F(ResearchOnMultiIndexTest, DuplicateRecSessKey)
{
  auto result = _recSessRelations.insert(_sample_dmitrii_1);
  ASSERT_FALSE(result.second);
}
//---------------------------------------------------------------------------------
TEST_F(ResearchOnMultiIndexTest, GetByPrimaryKey)
{
  // Осуществляется поиск
  // 1. Из коллекции получаем индекс
  const KeyIndex & keyIndex = _recSessRelations.get<RecSessData::recSessKey>();
  // 2. По индексу получаем итератор
  KeyIndex::iterator it = keyIndex.find(RecSessKey({"ivan", 1}));
  // 3. Опять же сравниваем его с end всей коллекции
  ASSERT_NE(it, _recSessRelations.end());
  it = _recSessRelations.get<RecSessData::recSessKey>().find(RecSessKey({"ivan", 100}));
  ASSERT_EQ(it, _recSessRelations.end());
}
//---------------------------------------------------------------------------------
TEST_F(ResearchOnMultiIndexTest, GetClientRange)
{
  // Осуществляется поиск по имени клиента, в данном случае "dmitrii"
  // 1. Получаем соответствующий индекс
  const ClientIndex & clientIndex = _recSessRelations.get<RecSessData::clientName>();
  ClientIndex::iterator from, to;

  // Осуществляется поиск по имени клиента, в данном случае "dmitrii"
  // 1. Получаем соответствующий индекс
  std::tie(from, to) = clientIndex.equal_range("dmitrii");
  // 2. Дейсвительно найдено всего 3 эелемента
  auto count = std::distance(from, to);
  ASSERT_EQ(3, count);

  // 3. Проверяем в порядке сортировки
  ASSERT_EQ(RecSessKey({"dmitrii", 1}), from->_recSessKey);
  ASSERT_EQ(RecSessKey({"dmitrii", 2}), (++from)->_recSessKey);
  ASSERT_EQ(RecSessKey({"dmitrii", 3}), (++from)->_recSessKey);
  ASSERT_EQ(++from, to);
}
//---------------------------------------------------------------------------------
TEST_F(ResearchOnMultiIndexTest, GetMrIdRange)
{
  // Осуществляется поиск по MrId, например, по значению 2 - прекрасно!
  // 1. Получаем соответствующий индекс
  const MRIdIndex & mrIdIndex = _recSessRelations.get<RecSessData::mrId>();
  MRIdIndex::iterator from, to;
  // 2. Получили диапазон, ожидается 2 записи. Это _sample_dmitrii_2 и _sample_ivan_2
  std::tie(from, to) = mrIdIndex.equal_range(2);
  ASSERT_EQ(2, std::distance(from, to));

  // 3. Внимание *from - это не RecSessData!, однако, по нему можно достучаться до членов этого класса
  // Отчего то результирующие записи расположены в порядке, не соответстующем лексикографическому - "ivan" идет вперед "dmitrii"
  ASSERT_EQ(_sample_ivan_2._recSessKey, from->_recSessKey);
  ASSERT_EQ(_sample_ivan_2._recSess, from->_recSess);
  ASSERT_EQ(2, from->_mrId);

  ++from;
  ASSERT_EQ(_sample_dmitrii_2._recSessKey, from->_recSessKey);
  ASSERT_EQ(_sample_dmitrii_2._recSess, from->_recSess);
  ASSERT_EQ(2, from->_mrId);
}
//---------------------------------------------------------------------------------
TEST_F(ResearchOnMultiIndexTest, RemoveByKey)
{
  // Удаление по ключу O(log(n) + m*D(n))
  // 1. Размер коллекции до удаления элемента
  ASSERT_EQ(6, _recSessRelations.size());

  KeyIndex & keyIndex = _recSessRelations.get<RecSessData::recSessKey>();
  // 2. Удалим несуществующий элемент.
  keyIndex.erase(RecSessKey({"ivan", 100}));
  ASSERT_EQ(6, _recSessRelations.size());

  // 2. Удалим существующий элемент
  keyIndex.erase(RecSessKey({"ivan", 1}));
  ASSERT_EQ(5, _recSessRelations.size());

  // 3. Существуют перегрузки, принимающие диапазон или одиночный итератор. Сложность такая же :(
  // O(log(n) + m*D(n)), where m is the number of elements in [first,last).
  KeyIterator found = keyIndex.find(RecSessKey({"ivan", 2}));
  ASSERT_NE(keyIndex.end(), found);
  keyIndex.erase(found);
  ASSERT_EQ(4, _recSessRelations.size());

  // 4. Сколько осталось записей по "ivan" ?
  const ClientIndex & clientIndex = _recSessRelations.get<RecSessData::clientName>();
  ClientIndex::iterator from, to;
  std::tie(from, to) = clientIndex.equal_range("ivan");
  ASSERT_EQ(1, std::distance(from, to));
}
//---------------------------------------------------------------------------------
TEST_F(ResearchOnMultiIndexTest, RemoveByMRId)
{
  // 1. Удаляем по mrId 1
  MRIdIndex & mrIndex = _recSessRelations.get<RecSessData::mrId>();
  mrIndex.erase(1);
  // Должно остаться 4 записи
  ASSERT_EQ(4, mrIndex.size());

  // 2. Или так вот - по паре итераторов
  MRIterator from, to;
  tie(from, to) = mrIndex.equal_range(2);
  ASSERT_EQ(2, std::distance(from, to));
  mrIndex.erase(from, to);
  ASSERT_EQ(2, mrIndex.size());
  ASSERT_EQ(2, _recSessRelations.size());
}
//---------------------------------------------------------------------------------
TEST_F(ResearchOnMultiIndexTest, Replace)
{
  //  the whole element has to be copied twice to do the updating (https://www.boost.org/doc/libs/1_62_0/libs/multi_index/doc/tutorial/basics.html#ord_updating)
  // replace подразумевает полное копирование элемента

  // 1. Получаем уже привычный нам индекс ключа
  KeyIndex & keyIndex = _recSessRelations.get<RecSessData::recSessKey>();
  // 2. Поиск по ключу
  KeyIndex::iterator it = keyIndex.find(RecSessKey({"ivan", 1}));
  // 3. Ключ найден, итератор не "смотрит" в конец индекса
  ASSERT_NE(it, keyIndex.end());
  // 4. data инициализируется копированием из итератора и далее изменяется в соответствие нашим потребностям
  RecSessData data = *it;
  data._mrId = 111;
  data._recSessKey = {"maria", 777};

  // 5. Непосредственно replace - копирование всей структуры в позицию определяемую итератором.
  keyIndex.replace(it, data);

  // 6. Размер структуры не изменился
  ASSERT_EQ(6, _recSessRelations.size());

  // 7. Поскольку одна запись по "ivan" была заменена на "maria" - в остатке должно быть 2 записи по "ivan"
  const ClientIndex & clientIndex = _recSessRelations.get<RecSessData::clientName>();
  ClientIterator from, to;
  std::tie(from, to) = clientIndex.equal_range("ivan");
  ASSERT_EQ(2, std::distance(from, to));
}
//---------------------------------------------------------------------------------
TEST_F(ResearchOnMultiIndexTest, Modify)
{
  //  Boost.MultiIndex provides an alternative updating mechanism called modify:
  // 1. Согласно ману определяем modifier, для изменения содержимого записи без полного её копирования для снижения цены изменения
  //    modifier определяется структурой, принмающей в конструкторе то, чем будет изменятся целевой объект коллекции в операторе (),
  //    принимающем объект коллекции по ссылке
  struct KeyChanger
  {
    KeyChanger(const RecSessKey newKey) : _newKey(newKey) { }
    RecSessKey _newKey;
    void operator()(RecSessData & recSessData)
    {
      recSessData._recSessKey = _newKey;
    }
  };

  // 2. Получаем уже привычный нам индекс ключа
  KeyIndex & keyIndex = _recSessRelations.get<RecSessData::recSessKey>();
  // 3. Поиск по ключу
  KeyIndex::iterator it = keyIndex.find(RecSessKey({"ivan", 1}));
  // 4. Ключ найден, итератор не "смотрит" в конец индекса
  ASSERT_NE(it, keyIndex.end());

  // 5. modify - принимает, определенный ранее KeyChanger. После изменения - все индексы пересчитываются
  keyIndex.modify(it, KeyChanger({"maria", 777}));

  // 6. Размер структуры не изменился
  ASSERT_EQ(6, _recSessRelations.size());

  // 7. Поскольку одна запись по "ivan" была заменена на "maria" - в остатке должно быть 2 записи по "ivan"
  const ClientIndex & clientIndex = _recSessRelations.get<RecSessData::clientName>();
  ClientIterator from, to;
  std::tie(from, to) = clientIndex.equal_range("ivan");
  ASSERT_EQ(2, std::distance(from, to));
}
