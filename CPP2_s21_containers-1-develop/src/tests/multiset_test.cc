#include <gtest/gtest.h>

#include "../headers/s21_multiset.h"

TEST(multiset_test, constructor1) {
  s21::multiset<int> m1;
  std::multiset<int> m2;
  s21::multiset<int>::iterator it1 = m1.begin();
  for (std::multiset<int>::iterator it2 = m2.begin(); it2 != m2.end();
       ++it1, ++it2)
    EXPECT_EQ(*it1, *it2);
  EXPECT_EQ(m1.size(), m2.size());
}

TEST(multiset_test, constructor2) {
  s21::multiset<int> m1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  std::multiset<int> m2 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  s21::multiset<int>::iterator it1 = m1.begin();
  for (std::multiset<int>::iterator it2 = m2.begin(); it2 != m2.end();
       ++it1, ++it2)
    EXPECT_EQ(*it1, *it2);
  EXPECT_EQ(m1.size(), m2.size());
}

TEST(multiset_test, constructor3) {
  s21::multiset<int> m1{77, 4, 127, -12, 456, 4, 5, 4, 34, 4, 77, 2, 0, 2, 127};
  std::multiset<int> m2{77, 4, 127, -12, 456, 4, 5, 4, 34, 4, 77, 2, 0, 2, 127};
  s21::multiset<int>::iterator it1 = m1.begin();
  for (std::multiset<int>::iterator it2 = m2.begin(); it2 != m2.end();
       ++it1, ++it2)
    EXPECT_EQ(*it1, *it2);
  EXPECT_EQ(m1.size(), m2.size());
}

TEST(multiset_test, constructor4) {
  s21::multiset<int> m1{77, 4, 127, -12, 456, 4, 5, 4, 34, 4, 77, 2, 0, 2, 127};
  std::multiset<int> m2{77, 4, 127, -12, 456, 4, 5, 4, 34, 4, 77, 2, 0, 2, 127};
  s21::multiset<int> m11 = m1;
  std::multiset<int> m22 = m2;
  s21::multiset<int>::iterator it1 = m11.begin();
  for (std::multiset<int>::iterator it2 = m22.begin(); it2 != m22.end();
       ++it1, ++it2)
    EXPECT_EQ(*it1, *it2);
  EXPECT_EQ(m11.size(), m22.size());
  it1 = m1.begin();
  for (std::multiset<int>::iterator it2 = m2.begin(); it2 != m2.end();
       ++it1, ++it2)
    EXPECT_EQ(*it1, *it2);
  EXPECT_EQ(m1.size(), m2.size());
}

TEST(multiset_test, constructor5) {
  s21::multiset<int> m1;
  std::multiset<int> m2;
  s21::multiset<int> m11 = m1;
  std::multiset<int> m22 = m2;
  s21::multiset<int>::iterator it1 = m11.begin();
  for (std::multiset<int>::iterator it2 = m22.begin(); it2 != m22.end();
       ++it1, ++it2)
    EXPECT_EQ(*it1, *it2);
  EXPECT_EQ(m11.size(), m22.size());
  it1 = m1.begin();
  for (std::multiset<int>::iterator it2 = m2.begin(); it2 != m2.end();
       ++it1, ++it2)
    EXPECT_EQ(*it1, *it2);
  EXPECT_EQ(m1.size(), m2.size());
}

TEST(multiset_test, constructor6) {
  s21::multiset<int> m1{77, 4, 127, -12, 456, 4, 5, 4, 34, 4, 77, 2, 0, 2, 127};
  std::multiset<int> m2{77, 4, 127, -12, 456, 4, 5, 4, 34, 4, 77, 2, 0, 2, 127};
  s21::multiset<int> m11 = std::move(m1);
  std::multiset<int> m22 = std::move(m2);
  s21::multiset<int>::iterator it1 = m11.begin();
  for (std::multiset<int>::iterator it2 = m22.begin(); it2 != m22.end();
       ++it1, ++it2)
    EXPECT_EQ(*it1, *it2);
  EXPECT_EQ(m11.size(), m22.size());
  it1 = m1.begin();
  for (std::multiset<int>::iterator it2 = m2.begin(); it2 != m2.end();
       ++it1, ++it2)
    EXPECT_EQ(*it1, *it2);
  EXPECT_EQ(m1.size(), m2.size());
}

TEST(multiset_test, constructor7) {
  s21::multiset<int> m1;
  std::multiset<int> m2;
  s21::multiset<int> m11 = std::move(m1);
  std::multiset<int> m22 = std::move(m2);
  s21::multiset<int>::iterator it1 = m11.begin();
  for (std::multiset<int>::iterator it2 = m22.begin(); it2 != m22.end();
       ++it1, ++it2)
    EXPECT_EQ(*it1, *it2);
  EXPECT_EQ(m11.size(), m22.size());
  it1 = m1.begin();
  for (std::multiset<int>::iterator it2 = m2.begin(); it2 != m2.end();
       ++it1, ++it2)
    EXPECT_EQ(*it1, *it2);
  EXPECT_EQ(m1.size(), m2.size());
}

TEST(multiset_test, move_operation1) {
  s21::multiset<int> m1{77, 4, 127, -12, 456, 4, 5, 4, 34, 4, 77, 2, 0, 2, 127};
  std::multiset<int> m2{77, 4, 127, -12, 456, 4, 5, 4, 34, 4, 77, 2, 0, 2, 127};
  s21::multiset<int> m11;
  std::multiset<int> m22;
  m11 = std::move(m1);
  m22 = std::move(m2);
  s21::multiset<int>::iterator it1 = m11.begin();
  for (std::multiset<int>::iterator it2 = m22.begin(); it2 != m22.end();
       ++it1, ++it2)
    EXPECT_EQ(*it1, *it2);
  EXPECT_EQ(m11.size(), m22.size());
  it1 = m1.begin();
  for (std::multiset<int>::iterator it2 = m2.begin(); it2 != m2.end();
       ++it1, ++it2)
    EXPECT_EQ(*it1, *it2);
  EXPECT_EQ(m1.size(), m2.size());
}

TEST(multiset_test, begin1) {
  s21::multiset<int> m1{77, 4, 127, -12, 456, 4, 5, 4, 34, 4, 77, 2, 0, 2, 127};
  std::multiset<int> m2{77, 4, 127, -12, 456, 4, 5, 4, 34, 4, 77, 2, 0, 2, 127};
  s21::multiset<int>::iterator it1 = m1.begin();
  std::multiset<int>::iterator it2 = m2.begin();
  EXPECT_EQ(*it1, *it2);
}

TEST(multiset_test, end1) {
  s21::multiset<int> m1{77, 4, 127, -12, 456, 4, 5, 4, 34, 4, 77, 2, 0, 2, 127};
  std::multiset<int> m2{77, 4, 127, -12, 456, 4, 5, 4, 34, 4, 77, 2, 0, 2, 127};
  s21::multiset<int>::iterator it1 = m1.end();
  std::multiset<int>::iterator it2 = m2.end();
  --it1;
  --it2;
  EXPECT_EQ(*it1, *it2);
}

TEST(multiset_test, empty1) {
  s21::multiset<int> m1;
  std::multiset<int> m2;
  EXPECT_EQ(m1.empty(), m2.empty());
}

TEST(multiset_test, empty2) {
  s21::multiset<int> m1{77, 4, 127, -12, 456, 4, 5, 4, 34, 4, 77, 2, 0, 2, 127};
  std::multiset<int> m2{77, 4, 127, -12, 456, 4, 5, 4, 34, 4, 77, 2, 0, 2, 127};
  EXPECT_EQ(m1.empty(), m2.empty());
}

TEST(multiset_test, empty3) {
  s21::multiset<int> m1{77, 4, 127, -12, 456, 4, 5, 4, 34, 4, 77, 2, 0, 2, 127};
  std::multiset<int> m2{77, 4, 127, -12, 456, 4, 5, 4, 34, 4, 77, 2, 0, 2, 127};
  m1.clear();
  m2.clear();
  EXPECT_EQ(m1.empty(), m2.empty());
}

TEST(multiset_test, size1) {
  s21::multiset<int> m1;
  std::multiset<int> m2;
  EXPECT_EQ(m1.size(), m2.size());
}

TEST(multiset_test, size2) {
  s21::multiset<int> m1{77, 4, 127, -12, 456, 4, 5, 4, 34, 4, 77, 2, 0, 2, 127};
  std::multiset<int> m2{77, 4, 127, -12, 456, 4, 5, 4, 34, 4, 77, 2, 0, 2, 127};
  EXPECT_EQ(m1.size(), m2.size());
}

TEST(multiset_test, size3) {
  s21::multiset<int> m1{77, 4, 127, -12, 456, 4, 5, 4, 34, 4, 77, 2, 0, 2, 127};
  std::multiset<int> m2{77, 4, 127, -12, 456, 4, 5, 4, 34, 4, 77, 2, 0, 2, 127};
  m1.clear();
  m2.clear();
  EXPECT_EQ(m1.size(), m2.size());
}

TEST(multiset_test, max_size1) {
  s21::multiset<int> m1{77, 4, 127, -12, 456, 4, 5, 4, 34, 4, 77, 2, 0, 2, 127};
  std::multiset<int> m2{77, 4, 127, -12, 456, 4, 5, 4, 34, 4, 77, 2, 0, 2, 127};
  EXPECT_EQ(m1.max_size(), m2.max_size());
}

TEST(multiset_test, clear1) {
  s21::multiset<int> m1{77, 4, 127, -12, 456, 4, 5, 4, 34, 4, 77, 2, 0, 2, 127};
  std::multiset<int> m2{77, 4, 127, -12, 456, 4, 5, 4, 34, 4, 77, 2, 0, 2, 127};
  m1.clear();
  m2.clear();
  EXPECT_EQ(m1.empty(), m2.empty());
}

TEST(multiset_test, clear2) {
  s21::multiset<int> m1;
  std::multiset<int> m2;
  m1.clear();
  m2.clear();
  EXPECT_EQ(m1.empty(), m2.empty());
}

TEST(multiset_test, insert1) {
  s21::multiset<int> m1;
  std::multiset<int> m2;
  for (int i = 0; i < 1000; i++) {
    int num = rand();
    EXPECT_EQ(*(m1.insert(num)), *(m2.insert(num)));
  }
  EXPECT_EQ(m1.size(), m2.size());
}

TEST(multiset_test, insert2) {
  s21::multiset<int> m1;
  std::multiset<int> m2;
  for (int i = 0; i < 10; i++) {
    EXPECT_EQ(*(m1.insert(1)), *(m2.insert(1)));
  }
  EXPECT_EQ(m1.size(), m2.size());
}

TEST(multiset_test, insert3) {
  s21::multiset<int> m1{77, 4, 127, -12, 456, 4, 5, 4, 34, 4, 77, 2, 0, 2, 127};
  std::multiset<int> m2{77, 4, 127, -12, 456, 4, 5, 4, 34, 4, 77, 2, 0, 2, 127};
  for (int i = 0; i < 100; i++) {
    int num = rand();
    m1.insert(num);
    m2.insert(num);
  }
  s21::multiset<int>::iterator it1 = m1.begin();
  for (std::multiset<int>::iterator it2 = m2.begin(); it2 != m2.end();
       ++it1, ++it2)
    EXPECT_EQ(*it1, *it2);
  EXPECT_EQ(m1.size(), m2.size());
}

TEST(multiset_test, erase1) {
  s21::multiset<int> m1;
  EXPECT_ANY_THROW(m1.erase(m1.begin()));
}

TEST(multiset_test, erase2) {
  s21::multiset<int> m1{77, 4, 127, -12, 456, 4, 5, 4, 34, 4, 77, 2, 0, 2, 127};
  std::multiset<int> m2{77, 4, 127, -12, 456, 4, 5, 4, 34, 4, 77, 2, 0, 2, 127};
  EXPECT_EQ(m1.size(), m2.size());
  s21::multiset<int>::iterator it1 = m1.begin();
  std::multiset<int>::iterator it2 = m2.begin();
  m1.erase(it1);
  m2.erase(it2);
  it1 = m1.begin();
  it2 = m2.begin();
  for (; it2 != m2.end(); ++it1, ++it2) EXPECT_EQ(*it1, *it2);
  EXPECT_EQ(m1.size(), m2.size());
}

TEST(multiset_test, erase3) {
  s21::multiset<int> m1{77, 4, 127, -12, 456, 4, 5, 4, 34, 4, 77, 2, 0, 2, 127};
  EXPECT_ANY_THROW(m1.erase(m1.end()));
}

TEST(multiset_test, swap1) {
  s21::multiset<int> m1{77, 4, 127, -12, 456, 4, 5, 4, 34, 4, 77, 2, 0, 2, 127};
  std::multiset<int> m2{77, 4, 127, -12, 456, 4, 5, 4, 34, 4, 77, 2, 0, 2, 127};
  s21::multiset<int> m11;
  std::multiset<int> m22;
  m1.swap(m11);
  m2.swap(m22);
  EXPECT_EQ(m1.size(), m2.size());
  EXPECT_EQ(m11.size(), m22.size());
  s21::multiset<int>::iterator it1 = m1.begin();
  s21::multiset<int>::iterator it11 = m11.begin();
  std::multiset<int>::iterator it2 = m2.begin();
  std::multiset<int>::iterator it22 = m22.begin();
  for (; it2 != m2.end(); ++it1, ++it2) EXPECT_EQ(*it1, *it2);
  for (; it22 != m22.end(); ++it11, ++it22) EXPECT_EQ(*it11, *it22);
}

TEST(multiset_test, swap2) {
  s21::multiset<int> m1{77, 4, 127, -12, 456, 4, 5, 4, 34, 4, 77, 2, 0, 2, 127};
  std::multiset<int> m2{77, 4, 127, -12, 456, 4, 5, 4, 34, 4, 77, 2, 0, 2, 127};
  s21::multiset<int> m11{3, -121, 45, 3, 4, 7, 4, 22, -14, 92, 3, 321};
  std::multiset<int> m22{3, -121, 45, 3, 4, 7, 4, 22, -14, 92, 3, 321};
  m1.swap(m11);
  m2.swap(m22);
  EXPECT_EQ(m1.size(), m2.size());
  EXPECT_EQ(m11.size(), m22.size());
  s21::multiset<int>::iterator it1 = m1.begin();
  s21::multiset<int>::iterator it11 = m11.begin();
  std::multiset<int>::iterator it2 = m2.begin();
  std::multiset<int>::iterator it22 = m22.begin();
  for (; it2 != m2.end(); ++it1, ++it2) EXPECT_EQ(*it1, *it2);
  for (; it22 != m22.end(); ++it11, ++it22) EXPECT_EQ(*it11, *it22);
}

TEST(multiset_test, merge1) {
  s21::multiset<int> m1{77, 4, 127, -12, 456, 4, 5, 4, 34, 4, 77, 2, 0, 2, 127};
  std::multiset<int> m2{77, 4, 127, -12, 456, 4, 5, 4, 34, 4, 77, 2, 0, 2, 127};
  s21::multiset<int> m11{3, -121, 45, 3, 4, 7, 4, 22, -14, 92, 3, 321};
  std::multiset<int> m22{3, -121, 45, 3, 4, 7, 4, 22, -14, 92, 3, 321};
  m1.merge(m11);
  m2.merge(m22);
  s21::multiset<int>::iterator it1 = m1.begin();
  for (std::multiset<int>::iterator it2 = m2.begin(); it2 != m2.end();
       ++it1, ++it2)
    EXPECT_EQ(*it1, *it2);
}

TEST(multiset_test, merge2) {
  s21::multiset<int> m1{77, 4, 127, -12, 456, 4, 5, 4, 34, 4, 77, 2, 0, 2, 127};
  std::multiset<int> m2{77, 4, 127, -12, 456, 4, 5, 4, 34, 4, 77, 2, 0, 2, 127};
  s21::multiset<int> m11;
  std::multiset<int> m22;
  m1.merge(m11);
  m2.merge(m22);
  s21::multiset<int>::iterator it1 = m1.begin();
  for (std::multiset<int>::iterator it2 = m2.begin(); it2 != m2.end();
       ++it1, ++it2)
    EXPECT_EQ(*it1, *it2);
}

TEST(multiset_test, count1) {
  s21::multiset<int> m1{77, 4, 127, -12, 456, 4, 5, 4, 34, 4, 77, 2, 0, 2, 127};
  std::multiset<int> m2{77, 4, 127, -12, 456, 4, 5, 4, 34, 4, 77, 2, 0, 2, 127};
  EXPECT_EQ(m1.count(1), m2.count(1));
  EXPECT_EQ(m1.count(2), m2.count(2));
  EXPECT_EQ(m1.count(6), m2.count(6));
}

TEST(multiset_test, count2) {
  s21::multiset<int> m1;
  std::multiset<int> m2;
  EXPECT_EQ(m1.count(1), m2.count(1));
  EXPECT_EQ(m1.count(2), m2.count(2));
  EXPECT_EQ(m1.count(6), m2.count(6));
}

TEST(multiset_test, count3) {
  s21::multiset<int> m1 = {1, 1, 1, 1, 1, 1, 1, 1};
  std::multiset<int> m2 = {1, 1, 1, 1, 1, 1, 1, 1};
  EXPECT_EQ(m1.count(1), m2.count(1));
  EXPECT_EQ(m1.count(2), m2.count(2));
  EXPECT_EQ(m1.count(6), m2.count(6));
}

TEST(multiset_test, find1) {
  s21::multiset<int> m1{77, 4, 127, -12, 456, 4, 5, 4, 34, 4, 77, 2, 0, 2, 127};
  std::multiset<int> m2{77, 4, 127, -12, 456, 4, 5, 4, 34, 4, 77, 2, 0, 2, 127};
  EXPECT_EQ(*(m1.find(127)), *(m2.find(127)));
  EXPECT_EQ(*(m1.find(2)), *(m2.find(2)));
  EXPECT_EQ(*(m1.find(4)), *(m2.find(4)));
}

TEST(multiset_test, find3) {
  s21::multiset<int> m1 = {1, 1, 1, 1, 1, 1, 1, 1};
  std::multiset<int> m2 = {1, 1, 1, 1, 1, 1, 1, 1};
  EXPECT_EQ(*(m1.find(1)), *(m2.find(1)));
}

TEST(multiset_test, contains1) {
  s21::multiset<int> m1{77, 4, 127, -12, 456, 4, 5, 4, 34, 4, 77, 2, 0, 2, 127};
  EXPECT_EQ(m1.contains(127), true);
  EXPECT_EQ(m1.contains(2), true);
  EXPECT_EQ(m1.contains(4), true);
}

TEST(multiset_test, contains2) {
  s21::multiset<int> m1;
  EXPECT_EQ(m1.contains(127), false);
  EXPECT_EQ(m1.contains(2), false);
  EXPECT_EQ(m1.contains(4), false);
}

TEST(multiset_test, contains3) {
  s21::multiset<int> m1 = {1, 1, 1, 1, 1, 1, 1, 1};
  std::multiset<int> m2 = {1, 1, 1, 1, 1, 1, 1, 1};
  EXPECT_EQ(m1.contains(1), true);
  EXPECT_EQ(m1.contains(2), false);
  EXPECT_EQ(m1.contains(4), false);
}

TEST(multiset_test, equal_range1) {
  s21::multiset<int> m1{77, 4, 127, -12, 456, 4, 5, 4, 34, 4, 77, 2, 0, 2, 127};
  std::multiset<int> m2{77, 4, 127, -12, 456, 4, 5, 4, 34, 4, 77, 2, 0, 2, 127};
  std::pair<s21::multiset<int>::iterator, s21::multiset<int>::iterator> pair1 =
      m1.equal_range(9);
  std::pair<std::multiset<int>::iterator, std::multiset<int>::iterator> pair2 =
      m2.equal_range(9);
  EXPECT_EQ(*(pair1.first), *(pair2.first));
  EXPECT_EQ(*(pair1.second), *(pair2.second));
  pair1 = m1.equal_range(1);
  pair2 = m2.equal_range(1);
  EXPECT_EQ(*(pair1.first), *(pair2.first));
  EXPECT_EQ(*(pair1.second), *(pair2.second));
  pair1 = m1.equal_range(2);
  pair2 = m2.equal_range(2);
  EXPECT_EQ(*(pair1.first), *(pair2.first));
  EXPECT_EQ(*(pair1.second), *(pair2.second));
}

TEST(multiset_test, lower_bound1) {
  s21::multiset<int> m1{77, 4, 127, -12, 456, 4, 5, 4, 34, 4, 77, 2, 0, 2, 127};
  std::multiset<int> m2{77, 4, 127, -12, 456, 4, 5, 4, 34, 4, 77, 2, 0, 2, 127};
  s21::multiset<int>::iterator it1 = m1.lower_bound(9);
  std::multiset<int>::iterator it2 = m2.lower_bound(9);
  EXPECT_EQ(*(it1), *(it2));
  it1 = m1.lower_bound(1);
  it2 = m2.lower_bound(1);
  EXPECT_EQ(*(it1), *(it2));
  it1 = m1.lower_bound(2);
  it2 = m2.lower_bound(2);
  EXPECT_EQ(*(it1), *(it2));
}

TEST(multiset_test, upper_bound1) {
  s21::multiset<int> m1{77, 4, 127, -12, 456, 4, 5, 4, 34, 4, 77, 2, 0, 2, 127};
  std::multiset<int> m2{77, 4, 127, -12, 456, 4, 5, 4, 34, 4, 77, 2, 0, 2, 127};
  s21::multiset<int>::iterator it1 = m1.upper_bound(9);
  std::multiset<int>::iterator it2 = m2.upper_bound(9);
  EXPECT_EQ(*(it1), *(it2));
  it1 = m1.upper_bound(1);
  it2 = m2.upper_bound(1);
  EXPECT_EQ(*(it1), *(it2));
  it1 = m1.upper_bound(2);
  it2 = m2.upper_bound(2);
  EXPECT_EQ(*(it1), *(it2));
}

TEST(multiset_test, iterator1) {
  s21::multiset<int> m1{77, 4, 127, -12, 456, 4, 5, 4, 34, 4, 77, 2, 0, 2, 127};
  std::multiset<int> m2{77, 4, 127, -12, 456, 4, 5, 4, 34, 4, 77, 2, 0, 2, 127};
  s21::multiset<int>::iterator it1 = m1.end();
  std::multiset<int>::iterator it2 = m2.end();
  --it1, --it2;
  EXPECT_EQ(*(it1), *(it2));
  for (; it2 != m2.begin(); --it1, --it2) EXPECT_EQ(*it1, *it2);
}

TEST(multiset_test, emplace) {
  s21::multiset<char> m1{'g', 'f', 'e', 'g'};
  std::multiset<char> m2{'g', 'f', 'e', 'g'};
  m1.emplace('7');
  m1.emplace('e');
  m1.emplace('L');
  m1.emplace(';');
  m1.emplace('g');
  m1.emplace('5');
  m1.emplace('e');
  m2.emplace('7');
  m2.emplace('e');
  m2.emplace('L');
  m2.emplace(';');
  m2.emplace('g');
  m2.emplace('5');
  m2.emplace('e');
  s21::multiset<char>::iterator it1 = m1.begin();
  std::multiset<char>::iterator it2 = m2.begin();
  EXPECT_EQ(m1.size(), m2.size());
  for (; it2 != m2.end(); ++it1, ++it2) EXPECT_EQ(*it1, *it2);
}