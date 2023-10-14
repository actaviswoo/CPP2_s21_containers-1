#include <gtest/gtest.h>

#include <list>

#include "../headers/s21_list.h"

TEST(ListConstructor, Default) {
  std::list<int> list;
  s21::list<int> s21_list;

  ASSERT_EQ(s21_list.empty(), list.empty());
}

TEST(ListConstructor, Sized) {
  s21::list<int> s21_list(3);

  ASSERT_EQ(s21_list.size(), 3);

  for (auto& item : s21_list) ASSERT_EQ(item, 0);
}

TEST(ListConstructor, InitializerList) {
  std::list<int> list{1, 2, 3};
  s21::list<int> s21_list{1, 2, 3};
  auto it = list.cbegin();

  ASSERT_EQ(s21_list.size(), list.size());

  for (auto& item : s21_list) ASSERT_EQ(item, *(it++));
}

TEST(ListConstructor, Copy) {
  std::list<int> list{1, 2, 3}, copy(list);
  s21::list<int> s21_list{1, 2, 3}, s21_copy(s21_list);
  auto it = copy.cbegin();

  ASSERT_EQ(s21_copy.size(), copy.size());

  for (auto& item : s21_copy) ASSERT_EQ(item, *(it++));
}

TEST(ListConstructor, Move) {
  std::list<int> list{1, 2, 3}, moved(std::move(list));
  s21::list<int> s21_list{1, 2, 3}, s21_moved(std::move(s21_list));
  auto it = moved.cbegin();

  ASSERT_EQ(s21_list.empty(), list.empty());
  ASSERT_EQ(s21_moved.size(), moved.size());

  for (auto& item : s21_moved) ASSERT_EQ(item, *(it++));
}

TEST(ListConstructor, MoveOperator) {
  std::list<int> list{1, 2, 3}, moved;
  s21::list<int> s21_list{1, 2, 3}, s21_moved;

  moved = std::move(list);
  s21_moved = std::move(s21_list);

  auto it = moved.cbegin();

  ASSERT_EQ(s21_list.empty(), list.empty());
  ASSERT_EQ(s21_moved.size(), moved.size());

  for (auto& item : s21_moved) ASSERT_EQ(item, *(it++));
}

TEST(ListAccessors, Front) {
  std::list<int> list{1, 2, 3};
  s21::list<int> s21_list{1, 2, 3};

  ASSERT_EQ(s21_list.front(), list.front());
}

TEST(ListAccessors, FrontEmptyList) {
  std::list<int> list;
  s21::list<int> s21_list;

  EXPECT_THROW(s21_list.front(), std::logic_error);
}

TEST(ListAccessors, Back) {
  std::list<int> list{1, 2, 3};
  s21::list<int> s21_list{1, 2, 3};

  ASSERT_EQ(s21_list.back(), list.back());
}

TEST(ListAccessors, BackEmptyList) {
  std::list<int> list;
  s21::list<int> s21_list;

  EXPECT_THROW(s21_list.back(), std::logic_error);
}

TEST(ListIterator, DerefOperator) {
  std::list<int> list{1, 2, 3};
  s21::list<int> s21_list{1, 2, 3};
  auto it = list.begin();
  auto s21_it = s21_list.begin();

  ASSERT_EQ(*s21_it, *it);
}

TEST(ListIterator, PlusPlusOperator) {
  std::list<int> list{1, 2, 3};
  s21::list<int> s21_list{1, 2, 3};
  auto it = list.begin();
  auto s21_it = s21_list.begin();

  it++;
  s21_it++;

  ASSERT_EQ(*s21_it, *it);
}

TEST(ListIterator, ForInLoop) {
  std::list<int> list{1, 2, 3};
  s21::list<int> s21_list{1, 2, 3};
  auto it = list.begin();

  for (auto& item : list) EXPECT_EQ(item, *(it++));
}

TEST(ListIterator, ForLoop) {
  std::list<int> list{1, 2, 3};
  s21::list<int> s21_list{1, 2, 3};
  auto it = list.begin();

  for (auto s21_it = s21_list.begin(); s21_it != s21_list.end(); s21_it++)
    EXPECT_EQ(*s21_it, *(it++));
}

TEST(ListIterator, Mutations) {
  std::list<int> list{2, 4, 6};
  s21::list<int> s21_list{1, 2, 3};
  auto it = list.begin();

  for (auto& item : list) item *= 2;
  for (auto& item : list) ASSERT_EQ(item, *(it++));
}

TEST(ListConstIterator, DerefOperator) {
  std::list<int> list{1, 2, 3};
  s21::list<int> s21_list{1, 2, 3};
  auto it = list.cbegin();
  auto s21_it = s21_list.cbegin();

  ASSERT_EQ(*s21_it, *it);
}

TEST(ListConstIterator, PlusPlusOperator) {
  std::list<int> list{1, 2, 3};
  s21::list<int> s21_list{1, 2, 3};
  auto it = list.cbegin();
  auto s21_it = s21_list.cbegin();

  it++;
  s21_it++;

  ASSERT_EQ(*s21_it, *it);
}

TEST(ListConstIterator, ForLoop) {
  std::list<int> list{1, 2, 3};
  s21::list<int> s21_list{1, 2, 3};
  auto it = list.cbegin();

  for (auto s21_it = s21_list.cbegin(); s21_it != s21_list.cend(); s21_it++)
    EXPECT_EQ(*s21_it, *(it++));
}

TEST(ListCapacity, Empty) {
  std::list<int> list;
  s21::list<int> s21_list;

  ASSERT_EQ(s21_list.empty(), list.empty());
}

TEST(ListCapacity, NotEmpty) {
  std::list<int> list{1, 2};
  s21::list<int> s21_list{1, 2};

  ASSERT_EQ(s21_list.empty(), list.empty());
}

TEST(ListCapacity, SizeEmpty) {
  std::list<int> list;
  s21::list<int> s21_list;

  ASSERT_EQ(s21_list.size(), list.size());
}

TEST(ListCapacity, SizeOneItem) {
  std::list<int> list{1};
  s21::list<int> s21_list{1};

  ASSERT_EQ(s21_list.size(), list.size());
}

TEST(ListCapacity, SizeFiveItems) {
  std::list<int> list{1, 2, 3, 4, 5};
  s21::list<int> s21_list{1, 2, 3, 4, 5};

  ASSERT_EQ(s21_list.size(), list.size());
}

TEST(ListCapacity, MaxSize) {
  std::list<int> list;
  s21::list<int> s21_list;

  ASSERT_EQ(s21_list.max_size(), list.max_size());
}

TEST(ListModifiers, Clear) {
  std::list<int> list{1, 2, 3};
  s21::list<int> s21_list{1, 2, 3};

  list.clear();
  s21_list.clear();

  ASSERT_EQ(s21_list.empty(), list.empty());
}

TEST(ListModifiers, ClearEmpty) {
  std::list<int> list;
  s21::list<int> s21_list;

  list.clear();
  s21_list.clear();

  ASSERT_EQ(s21_list.empty(), list.empty());
}

TEST(ListModifiers, InsertEmpty) {
  s21::list<int> s21_list;

  auto s21_res = s21_list.insert(s21_list.begin(), 0);

  ASSERT_EQ(s21_list.front(), 0);
  ASSERT_EQ(*s21_res, 0);
}

TEST(ListModifiers, InsertAtStart) {
  std::list<int> list{0, 1, 2};
  s21::list<int> s21_list{1, 2};
  auto it = list.begin();

  auto s21_res = s21_list.insert(s21_list.begin(), 0);

  ASSERT_EQ(s21_list.front(), 0);
  ASSERT_EQ(*s21_res, 0);

  for (auto& item : s21_list) ASSERT_EQ(item, *(it++));
}

TEST(ListModifiers, InsertAtEnd) {
  std::list<int> list{1, 2, 3};
  s21::list<int> s21_list{1, 2};
  auto it = list.begin();
  auto s21_iter = s21_list.begin();

  s21_iter++;
  s21_iter++;

  auto s21_res = s21_list.insert(s21_iter, 3);

  ASSERT_EQ(s21_list.back(), 3);
  ASSERT_EQ(*s21_res, 3);

  for (auto& item : s21_list) ASSERT_EQ(item, *(it++));
}

TEST(ListModifiers, EraseAtStart) {
  s21::list<int> list{1, 2};
  list.erase(list.begin());

  ASSERT_TRUE(list.empty());
}

TEST(ListModifiers, EraseAfterFirst) {
  s21::list<int> list{1, 2, 3, 4};
  list.erase(++list.begin());

  ASSERT_EQ(list.size(), 1);
  ASSERT_EQ(list.front(), 1);
}

TEST(ListModifiers, PushBackEmpty) {
  s21::list<int> s21_list;

  s21_list.push_back(0);

  ASSERT_EQ(s21_list.back(), 0);
}

TEST(ListModifiers, PushBack) {
  s21::list<int> s21_list{1, 2, 3};

  s21_list.push_back(4);

  ASSERT_EQ(s21_list.back(), 4);
}

TEST(ListModifiers, PopBackEmpty) {
  s21::list<int> s21_list;

  s21_list.pop_back();

  ASSERT_TRUE(s21_list.empty());
}

TEST(ListModifiers, PopBackOneElement) {
  s21::list<int> s21_list{1};

  s21_list.pop_back();

  ASSERT_TRUE(s21_list.empty());
}

TEST(ListModifiers, PopBackFiveElements) {
  std::list<int> list{1, 2, 3, 4};
  s21::list<int> s21_list{1, 2, 3, 4, 5};
  auto it = list.begin();

  s21_list.pop_back();

  ASSERT_EQ(s21_list.size(), 4);

  for (auto& item : s21_list) ASSERT_EQ(item, *(it++));
}

TEST(ListModifiers, PushFrontEmpty) {
  s21::list<int> s21_list;

  s21_list.push_front(0);

  ASSERT_EQ(s21_list.front(), 0);
}

TEST(ListModifiers, PushFront) {
  s21::list<int> s21_list{1, 2, 3};

  s21_list.push_front(0);

  ASSERT_EQ(s21_list.front(), 0);
}

TEST(ListModifiers, PopFrontEmpty) {
  s21::list<int> s21_list;

  s21_list.pop_front();

  ASSERT_TRUE(s21_list.empty());
}

TEST(ListModifiers, PopFrontOneElement) {
  s21::list<int> s21_list{1};

  s21_list.pop_front();

  ASSERT_TRUE(s21_list.empty());
}

TEST(ListModifiers, PopFrontFiveElements) {
  std::list<int> list{2, 3, 4, 5};
  s21::list<int> s21_list{1, 2, 3, 4, 5};
  auto it = list.begin();

  s21_list.pop_front();

  ASSERT_EQ(s21_list.size(), 4);

  for (auto& item : s21_list) ASSERT_EQ(item, *(it++));
}

TEST(ListModifiers, SwapEmpty) {
  std::list<int> list{4, 5, 6, 7};
  s21::list<int> s21_list, s21_swap{4, 5, 6, 7};
  auto it = list.begin();

  s21_list.swap(s21_swap);

  ASSERT_TRUE(s21_swap.empty());
  ASSERT_EQ(s21_list.size(), list.size());
  for (auto& item : s21_list) ASSERT_EQ(item, *(it++));
}

TEST(ListModifiers, Swap) {
  std::list<int> list{1, 2, 3}, swap{4, 5, 6, 7};
  s21::list<int> s21_list{1, 2, 3}, s21_swap{4, 5, 6, 7};

  list.swap(swap);
  s21_list.swap(s21_swap);

  auto it = list.begin();
  auto swap_it = swap.begin();

  ASSERT_EQ(s21_list.size(), list.size());
  for (auto& item : s21_list) ASSERT_EQ(item, *(it++));

  ASSERT_EQ(s21_swap.size(), swap.size());
  for (auto& item : s21_swap) ASSERT_EQ(item, *(swap_it++));
}

TEST(ListModifiers, Merge) {
  s21::list<int> list{2, 5}, merge{3, 1, 4};
  s21::list<int> s21_list{2, 5}, s21_merge{3, 1, 4};

  list.merge(merge);
  s21_list.merge(s21_merge);

  auto it = list.begin();
  for (auto& item : s21_list) ASSERT_EQ(item, *(it++));
}

TEST(ListModifiers, Splice) {
  s21::list<int> s21_list{1, 2, 3}, s21_splice{-1, 0}, s21_res{-1, 0, 1, 2, 3};
  auto it = s21_res.begin();

  s21_list.splice(s21_list.cbegin(), s21_splice);

  ASSERT_EQ(s21_list.size(), 5);
  for (auto& item : s21_list) ASSERT_EQ(item, *(it++));
}

TEST(ListModifiers, Reverse) {
  s21::list<int> s21_list{1, 2, 3}, s21_res{3, 2, 1};
  auto it = s21_res.begin();

  s21_list.reverse();

  for (auto& item : s21_list) ASSERT_EQ(item, *(it++));
}

TEST(ListModifiers, Unique) {
  s21::list<int> s21_list{1, 1, 2, 3, 3}, s21_res{1, 2, 3};
  auto it = s21_res.begin();

  s21_list.unique();

  for (auto& item : s21_list) ASSERT_EQ(item, *(it++));
}

TEST(ListModifiers, Sort) {
  s21::list<int> s21_list{2, 1, 5, 4, 3}, s21_sorted{1, 2, 3, 4, 5};
  auto it = s21_sorted.begin();

  s21_list.sort();

  for (auto& item : s21_list) ASSERT_EQ(item, *(it++));
}