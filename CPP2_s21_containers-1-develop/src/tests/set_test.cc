#include <gtest/gtest.h>

#include <set>

#include "../headers/s21_set.h"

TEST(set_test, constructor1) {
  s21::set<int> s1{4, 73, -101, 62, 77, 158, 909, -12, 3, 88, 43, 18};
  std::set<int> s2{4, 73, -101, 62, 77, 158, 909, -12, 3, 88, 43, 18};
  s21::set<int>::iterator it1 = s1.begin();
  std::set<int>::iterator it2 = s2.begin();
  EXPECT_EQ(s1.size(), s2.size());
  for (; it2 != s2.end(); ++it1, ++it2) EXPECT_EQ(*it1, *it2);
}

TEST(set_test, constructor2) {
  s21::set<int> s1;
  std::set<int> s2;
  EXPECT_EQ(s1.size(), s2.size());
}

TEST(set_test, constructor3) {
  const s21::set<int> s1{4};
  const std::set<int> s2{4};
  s21::set<int>::const_iterator it1 = s1.begin();
  std::set<int>::const_iterator it2 = s2.begin();
  EXPECT_EQ(s1.size(), s2.size());
  for (; it2 != s2.end(); ++it1, ++it2) EXPECT_EQ(*it1, *it2);
}

TEST(set_test, constructor4) {
  s21::set<int> s1{4, 73, -101, 62, 77, 158, 909, -12, 3, 88, 43, 18};
  std::set<int> s2{4, 73, -101, 62, 77, 158, 909, -12, 3, 88, 43, 18};
  s21::set<int> s11 = s1;
  std::set<int> s22 = s2;
  s21::set<int>::iterator it1 = s11.begin();
  for (std::set<int>::iterator it2 = s22.begin(); it2 != s22.end();
       ++it1, ++it2)
    EXPECT_EQ(*it1, *it2);
  EXPECT_EQ(s1.size(), s2.size());
  EXPECT_EQ(s11.size(), s22.size());
}

TEST(set_test, constructor5) {
  s21::set<int> s1{4, 73, -101, 62, 77, 158, 909, -12, 3, 88, 43, 18};
  std::set<int> s2{4, 73, -101, 62, 77, 158, 909, -12, 3, 88, 43, 18};
  s21::set<int> s11 = std::move(s1);
  std::set<int> s22 = std::move(s2);
  s21::set<int>::iterator it1 = s11.begin();
  for (std::set<int>::iterator it2 = s22.begin(); it2 != s22.end();
       ++it1, ++it2)
    EXPECT_EQ(*it1, *it2);
  EXPECT_EQ(s1.size(), s2.size());
  EXPECT_EQ(s11.size(), s22.size());
}

TEST(set_test, move_operator1) {
  s21::set<int> s1{4, 73, -101, 62, 77, 158, 909, -12, 3, 88, 43, 18};
  std::set<int> s2{4, 73, -101, 62, 77, 158, 909, -12, 3, 88, 43, 18};
  s21::set<int> s11;
  std::set<int> s22;
  s11 = std::move(s1);
  s22 = std::move(s2);
  s21::set<int>::iterator it1 = s11.begin();
  for (std::set<int>::iterator it2 = s22.begin(); it2 != s22.end();
       ++it1, ++it2)
    EXPECT_EQ(*it1, *it2);
  EXPECT_EQ(s1.size(), s2.size());
  EXPECT_EQ(s11.size(), s22.size());
}

TEST(set_test, begin1) {
  s21::set<int> s1{4, 73, -101, 62, 77, 158, 909, -12, 3, 88, 43, 18};
  std::set<int> s2{4, 73, -101, 62, 77, 158, 909, -12, 3, 88, 43, 18};
  s21::set<int>::iterator it1 = s1.begin();
  std::set<int>::iterator it2 = s2.begin();
  EXPECT_EQ(*it1, *it2);
}

TEST(set_test, end1) {
  s21::set<int> s1{4, 73, -101, 62, 77, 158, 909, -12, 3, 88, 43, 18};
  std::set<int> s2{4, 73, -101, 62, 77, 158, 909, -12, 3, 88, 43, 18};
  s21::set<int>::iterator it1 = s1.end();
  std::set<int>::iterator it2 = s2.end();
  --it1, --it2;
  EXPECT_EQ(*it2, *it1);
}

TEST(set_test, end2) {
  s21::set<int> s1{4, 73, -101, 62, 77, 158, 909, -12, 3, 88, 43, 18};
  s21::set<int>::iterator it1 = s1.end();
  EXPECT_THROW(*it1, std::invalid_argument);
}

TEST(set_test, iterator1) {
  s21::set<int>::iterator it;
  EXPECT_THROW(*it, std::invalid_argument);
}

TEST(set_test, iterator2) {
  s21::set<int> s1{4, 73, -101, 62, 77, 158, 909, -12, 3, 88, 43, 18};
  std::set<int> s2{4, 73, -101, 62, 77, 158, 909, -12, 3, 88, 43, 18};
  s21::set<int>::iterator it1 = s1.end();
  std::set<int>::iterator it2 = s2.end();
  --it1, --it2;
  for (; it2 != s2.begin(); --it1, --it2) EXPECT_EQ(*it1, *it2);
}

TEST(set_test, iterator3) {
  s21::set<int> s1{4, 73, -101, 62, 77, 158, 909, -12, 3, 88, 43, 18};
  s21::set<int>::iterator it1 = s1.end();
  s21::set<int>::iterator it2 = s1.end();
  --(--it1), --(--it2);
  EXPECT_TRUE(it1 == it2);
}

TEST(set_test, iterator4) {
  s21::set<int> s1{4, 73, -101, 62, 77, 158, 909, -12, 3, 88, 43, 18};
  s21::set<int>::iterator it1 = s1.begin();
  s21::set<int>::iterator it2 = s1.begin();
  ++(++it1), ++(++(++it2));
  EXPECT_TRUE(it1 != it2);
}

TEST(set_test, iterator5) {
  s21::set<int> s1{4, 73, -101, 62, 77, 158, 909, -12, 3, 88, 43, 18};
  s21::set<int>::iterator it1 = s1.begin();
  s21::set<int>::iterator it2 = s1.begin();
  ++it1, ++(++(++it2));
  EXPECT_FALSE(it1 == it2);
}

TEST(set_test, iterator6) {
  s21::set<int> s1{4, 73, -101, 62, 77, 158, 909, -12, 3, 88, 43, 18};
  s21::set<int>::iterator it1 = s1.begin();
  s21::set<int>::iterator it2 = s1.begin();
  ++(++(++it1)), ++(++(++it2));
  EXPECT_FALSE(it1 != it2);
}

TEST(set_test, iterator7) {
  s21::set<int> s1{4, 73, -101, 62, 77, 158, 909, -12, 3, 88, 43, 18};
  s21::set<int>::iterator it1 = s1.begin();
  EXPECT_THROW(--it1, std::invalid_argument);
}

TEST(set_test, iterator8) {
  s21::set<int> s1{4, 73, -101, 62, 77, 158, 909, -12, 3, 88, 43, 18};
  s21::set<int>::iterator it1 = s1.end();
  EXPECT_THROW(++it1, std::invalid_argument);
}

TEST(set_test, iterator9) {
  s21::set<int>::iterator it;
  EXPECT_THROW(++it, std::invalid_argument);
}

TEST(set_test, iterator10) {
  s21::set<int>::iterator it;
  EXPECT_THROW(--it, std::invalid_argument);
}

TEST(set_test, iterator11) {
  s21::set<std::pair<int, int>> s1{{1, 7}};
  std::set<std::pair<int, int>> s2{{1, 7}};
  s21::set<std::pair<int, int>>::iterator it1 = s1.begin();
  std::set<std::pair<int, int>>::iterator it2 = s2.begin();
  EXPECT_EQ(it1->first, it2->first);
}

TEST(set_test, empty1) {
  s21::set<int> s1{4, 73, -101, 62, 77, 158, 909, -12, 3, 88, 43, 18};
  std::set<int> s2{4, 73, -101, 62, 77, 158, 909, -12, 3, 88, 43, 18};
  EXPECT_EQ(s1.empty(), s2.empty());
}

TEST(set_test, empty2) {
  s21::set<int> s1;
  std::set<int> s2;
  EXPECT_EQ(s1.empty(), s2.empty());
}

TEST(set_test, size1) {
  s21::set<int> s1;
  std::set<int> s2;
  s1.insert(1);
  s2.insert(1);
  EXPECT_EQ(s1.size(), s2.size());
}

TEST(set_test, size2) {
  s21::set<int> s1{4, 73, -101, 62, 77, 158, 909, -12, 3, 88, 43, 18};
  std::set<int> s2{4, 73, -101, 62, 77, 158, 909, -12, 3, 88, 43, 18};
  EXPECT_EQ(s1.size(), s2.size());
}

TEST(set_test, size3) {
  s21::set<int> s1;
  std::set<int> s2;
  EXPECT_EQ(s1.size(), s2.size());
}

TEST(set_test, max_size1) {
  s21::set<int> s1;
  std::set<int> s2;
  EXPECT_EQ(s1.max_size(), s2.max_size());
}

TEST(set_test, clear1) {
  s21::set<double> s1{4, 73, -101, 62.5, 77.2, 158, 909, -12, 3, 88, 43, 18};
  std::set<double> s2{4, 73, -101, 62.5, 77.2, 158, 909, -12, 3, 88, 43, 18};
  s1.clear();
  s2.clear();
  EXPECT_EQ(s1.size(), s2.size());
  EXPECT_EQ(s1.empty(), s2.empty());
}

TEST(set_test, clear2) {
  s21::set<double> s1;
  std::set<double> s2;
  s1.clear();
  s2.clear();
  EXPECT_EQ(s1.size(), s2.size());
  EXPECT_EQ(s1.empty(), s2.empty());
}

TEST(set_test, clear3) {
  s21::set<double> s1{4, 73, -101, 62.5, 77.2, 158, 909, -12, 3, 88, 43, 18};
  std::set<double> s2{4, 73, -101, 62.5, 77.2, 158, 909, -12, 3, 88, 43, 18};
  s1.clear();
  s2.clear();
  EXPECT_EQ(s1.size(), s2.size());
  EXPECT_EQ(s1.empty(), s2.empty());
  s1.clear();
  s2.clear();
  EXPECT_EQ(s1.size(), s2.size());
  EXPECT_EQ(s1.empty(), s2.empty());
}

TEST(set_test, insert1) {
  s21::set<double> s1{4, 73, -101, 62.5, 77.2, 158, 909, -12, 3, 88, 43, 18};
  std::set<double> s2{4, 73, -101, 62.5, 77.2, 158, 909, -12, 3, 88, 43, 18};
  EXPECT_EQ(s1.size(), s2.size());
  EXPECT_EQ(s1.insert(3.0).second, s2.insert(3.0).second);
  EXPECT_EQ(s1.size(), s2.size());
  EXPECT_EQ(*(s1.insert(3.0).first), *(s2.insert(3.0).first));
  EXPECT_EQ(s1.size(), s2.size());
}

TEST(set_test, insert2) {
  s21::set<double> s1{4, 73, -101, 62.5, 77.2, 158, 909, -12, 3, 88, 43, 18};
  std::set<double> s2{4, 73, -101, 62.5, 77.2, 158, 909, -12, 3, 88, 43, 18};
  EXPECT_EQ(s1.size(), s2.size());
  EXPECT_EQ(s1.insert(9.0).second, s2.insert(9.0).second);
  EXPECT_EQ(s1.size(), s2.size());
  EXPECT_EQ(*(s1.insert(9.0).first), *(s2.insert(9.0).first));
  EXPECT_EQ(s1.size(), s2.size());
}

TEST(set_test, insert3) {
  s21::set<double> s1{4, 73, -101, 62.5, 77.2, 158, 909, -12, 3, 88, 43, 18};
  std::set<double> s2{4, 73, -101, 62.5, 77.2, 158, 909, -12, 3, 88, 43, 18};
  EXPECT_EQ(s1.size(), s2.size());
  EXPECT_EQ(s1.insert(943).second, s2.insert(943).second);
  EXPECT_EQ(s1.size(), s2.size());
  EXPECT_EQ(*(s1.insert(943).first), *(s2.insert(943).first));
  EXPECT_EQ(s1.size(), s2.size());
}

TEST(set_test, erase1) {
  s21::set<double> s1{4, 73, -101, 62, 77, 158, 909, -12, 3, 88, 43, 18};
  std::set<double> s2{4, 73, -101, 62, 77, 158, 909, -12, 3, 88, 43, 18};
  EXPECT_EQ(s1.size(), s2.size());
  s21::set<double>::iterator it1 = s1.begin();
  std::set<double>::iterator it2 = s2.begin();
  s1.erase(it1);
  s2.erase(it2);
  EXPECT_EQ(s1.size(), s2.size());
  it1 = s1.end();
  EXPECT_THROW(s1.erase(it1), std::invalid_argument);
}

TEST(set_test, erase2) {
  s21::set<double> s1{4, 73, -101, 62, 77, 158, 909, -12, 3, 88, 43, 18};
  std::set<double> s2{4, 73, -101, 62, 77, 158, 909, -12, 3, 88, 43, 18};
  s21::set<double>::iterator it1 = s1.begin();
  std::set<double>::iterator it2 = s2.begin();
  s1.erase(it1);
  s2.erase(it2);
  it1 = s1.begin();
  it2 = s2.begin();
  EXPECT_EQ(s1.size(), s2.size());
  EXPECT_EQ(*it1, *it2);
}

TEST(set_test, erase3) {
  s21::set<double> s1{4, 73, -101, 62, 77, 158, 909, -12, 3, 88, 43, 18};
  std::set<double> s2{4, 73, -101, 62, 77, 158, 909, -12, 3, 88, 43, 18};
  s21::set<double>::iterator it1 = s1.end();
  std::set<double>::iterator it2 = s2.end();
  s1.erase(--it1);
  s2.erase(--it2);
  EXPECT_EQ(s1.size(), s2.size());
  it1 = s1.begin();
  it2 = s2.begin();
  for (; it2 != s2.end(); ++it1, ++it2) EXPECT_EQ(*it1, *it2);
}

TEST(set_test, erase4) {
  s21::set<double> s1{4};
  std::set<double> s2{4};
  s1.erase(s1.begin());
  s2.erase(s2.begin());
  EXPECT_EQ(s1.empty(), s2.empty());
}

TEST(set_test, erase5) {
  s21::set<double> s1{4};
  s21::set<double>::iterator it1 = s1.begin();
  s1.erase(it1);
  EXPECT_ANY_THROW(*it1);
}

TEST(set_test, swap1) {
  s21::set<int> s1{4, 73, -101, 62, 77, 158, 909, -12, 3, 88, 43, 18};
  std::set<int> s2{4, 73, -101, 62, 77, 158, 909, -12, 3, 88, 43, 18};
  s21::set<int> s11;
  std::set<int> s22;
  s1.swap(s11);
  s2.swap(s22);
  EXPECT_EQ(s1.size(), s2.size());
  EXPECT_EQ(s11.size(), s22.size());
  auto it1 = s11.begin();
  for (auto it2 = s22.begin(); it2 != s22.end(); ++it1, ++it2)
    EXPECT_EQ(*it1, *it2);
}

TEST(set_test, swap2) {
  s21::set<int> s1{4, 73, -101, 62, 77, 158, 909, -12, 3, 88, 43, 18};
  std::set<int> s2{4, 73, -101, 62, 77, 158, 909, -12, 3, 88, 43, 18};
  s21::set<int> s11{671, 5894, 720, 8096, 99};
  std::set<int> s22{671, 5894, 720, 8096, 99};
  s1.swap(s11);
  s2.swap(s22);
  EXPECT_EQ(s1.size(), s2.size());
  EXPECT_EQ(s11.size(), s22.size());
  auto it1 = s11.begin();
  for (auto it2 = s22.begin(); it2 != s22.end(); ++it1, ++it2)
    EXPECT_EQ(*it1, *it2);
}

TEST(set_test, swap3) {
  s21::set<int> s1;
  std::set<int> s2;
  s21::set<int> s11;
  std::set<int> s22;
  s1.swap(s11);
  s2.swap(s22);
  EXPECT_EQ(s1.size(), s2.size());
  EXPECT_EQ(s11.size(), s22.size());
  auto it1 = s11.begin();
  for (auto it2 = s22.begin(); it2 != s22.end(); ++it1, ++it2)
    EXPECT_EQ(*it1, *it2);
}

TEST(set_test, merge1) {
  s21::set<int> s1{4, 73, -101, 62, 77, 158, 909, -12, 3, 88, 43, 18};
  std::set<int> s2{4, 73, -101, 62, 77, 158, 909, -12, 3, 88, 43, 18};
  s21::set<int> s11{671, 5894, 720, 80396, 99};
  std::set<int> s22{671, 5894, 720, 80396, 99};
  s1.merge(s11);
  s2.merge(s22);
  EXPECT_EQ(s1.size(), s2.size());
  EXPECT_EQ(s11.size(), s22.size());
  auto it1 = s1.begin();
  for (auto it2 = s2.begin(); it2 != s2.end(); ++it1, ++it2)
    EXPECT_EQ(*it1, *it2);
}

TEST(set_test, merge2) {
  s21::set<int> s1{4, 73, -101, 62, 77, 158, 909, -12, 3, 88, 43, 18};
  std::set<int> s2{4, 73, -101, 62, 77, 158, 909, -12, 3, 88, 43, 18};
  s21::set<int> s11{4, 73, -101, 62, 77, 158, 909, -12, 3, 88, 43, 18};
  std::set<int> s22{4, 73, -101, 62, 77, 158, 909, -12, 3, 88, 43, 18};
  s1.merge(s11);
  s2.merge(s22);
  EXPECT_EQ(s1.size(), s2.size());
  EXPECT_EQ(s11.size(), s22.size());
  auto it1 = s1.begin();
  for (auto it2 = s2.begin(); it2 != s2.end(); ++it1, ++it2)
    EXPECT_EQ(*it1, *it2);
}

TEST(set_test, merge3) {
  s21::set<int> s1{4, 73, -101, 62, 77, 158, 909, -12, 3, 88, 43, 18};
  std::set<int> s2{4, 73, -101, 62, 77, 158, 909, -12, 3, 88, 43, 18};
  s21::set<int> s11{4, 73, -101, 62, 77, 158, 909, -12,
                    3, 88, 43,   18, 5,  35,  832};
  std::set<int> s22{4, 73, -101, 62, 77, 158, 909, -12,
                    3, 88, 43,   18, 5,  35,  832};
  s1.merge(s11);
  s2.merge(s22);
  EXPECT_EQ(s1.size(), s2.size());
  EXPECT_EQ(s11.size(), s22.size());
  auto it1 = s1.begin();
  for (auto it2 = s2.begin(); it2 != s2.end(); ++it1, ++it2)
    EXPECT_EQ(*it1, *it2);
}

TEST(set_test, merge4) {
  s21::set<int> s1{77, 4, 127, -12, 456, 4, 5, 4, 34, 4, 77, 2, 0, 2, 127};
  std::set<int> s2{77, 4, 127, -12, 456, 4, 5, 4, 34, 4, 77, 2, 0, 2, 127};
  s21::set<int> s11{3, -121, 45, 3, 4, 7, 4, 22, -14, 92, 3, 321};
  std::set<int> s22{3, -121, 45, 3, 4, 7, 4, 22, -14, 92, 3, 321};
  s1.merge(s11);
  s2.merge(s22);
  s21::set<int>::iterator it1 = s1.begin();
  for (std::set<int>::iterator it2 = s2.begin(); it2 != s2.end(); ++it1, ++it2)
    EXPECT_EQ(*it1, *it2);
}

TEST(set_test, merge5) {
  s21::set<int> s1{4, 73, -101, 62, 77, 158, 909, -12, 3, 88, 43, 18};
  std::set<int> s2{4, 73, -101, 62, 77, 158, 909, -12, 3, 88, 43, 18};
  s21::set<int> s11{7, 4, 20, -9, 3, 5, -6};
  std::set<int> s22{7, 4, 20, -9, 3, 5, -6};
  s1.merge(s11);
  s2.merge(s22);
  EXPECT_EQ(s1.size(), s2.size());
  EXPECT_EQ(s11.size(), s22.size());
  auto it1 = s1.begin();
  for (auto it2 = s2.begin(); it2 != s2.end(); ++it1, ++it2)
    EXPECT_EQ(*it1, *it2);
}

TEST(set_test, merge6) {
  s21::set<int> s1{4, 73, -101, 62, 77, 158, 909, -12, 3, 88, 43, 18};
  std::set<int> s2{4, 73, -101, 62, 77, 158, 909, -12, 3, 88, 43, 18};
  s1.merge(s1);
  s2.merge(s2);
  EXPECT_EQ(s1.size(), s2.size());
  auto it1 = s1.begin();
  for (auto it2 = s2.begin(); it2 != s2.end(); ++it1, ++it2)
    EXPECT_EQ(*it1, *it2);
}

TEST(set_test, find1) {
  s21::set<int> s1{4, 73, -101, 62, 77, 158, 909, -12, 3, 88, 43, 18};
  std::set<int> s2{4, 73, -101, 62, 77, 158, 909, -12, 3, 88, 43, 18};
  EXPECT_EQ(*(s1.find(3)), *(s2.find(3)));
}

TEST(set_test, contains1) {
  s21::set<int> s1{4, 73, -101, 62, 77, 158, 909, -12, 3, 88, 43, 18};
  EXPECT_EQ(s1.contains(73), true);
}

TEST(set_test, contains2) {
  s21::set<int> s1{4, 73, -101, 62, 77, 158, 909, -12, 3, 88, 43, 18};
  EXPECT_EQ(s1.contains(7), false);
}

TEST(set_test, emplace) {
  s21::set<char> s1{'g', 'f'};
  std::set<char> s2{'g', 'f'};
  s1.emplace('7');
  s1.emplace('L');
  s1.emplace(';');
  s1.emplace('5');
  s1.emplace('e');
  s2.emplace('7');
  s2.emplace('L');
  s2.emplace(';');
  s2.emplace('5');
  s2.emplace('e');
  s21::set<char>::iterator it1 = s1.begin();
  std::set<char>::iterator it2 = s2.begin();
  EXPECT_EQ(s1.size(), s2.size());
  for (; it2 != s2.end(); ++it1, ++it2) EXPECT_EQ(*it1, *it2);
}