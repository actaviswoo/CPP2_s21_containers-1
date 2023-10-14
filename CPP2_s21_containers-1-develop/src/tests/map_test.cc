#include <gtest/gtest.h>

#include <map>
#include <string>

#include "../headers/s21_map.h"

TEST(map_test, constructor1) {
  s21::map<std::string, int> m1{{"LeBron", 38},
                                {"Messi", 36},
                                {"Bradley Pitt", 59},
                                {"Tom Brady", 45},
                                {"Ryan Gosling", 42}};
  std::map<std::string, int> m2{{"LeBron", 38},
                                {"Messi", 36},
                                {"Bradley Pitt", 59},
                                {"Tom Brady", 45},
                                {"Ryan Gosling", 42}};
  auto it1 = m1.begin();
  for (auto it2 = m2.begin(); it2 != m2.end(); ++it1, ++it2)
    EXPECT_EQ((*it1).second, (*it2).second);
  it1 = m1.begin();
  for (auto it2 = m2.begin(); it2 != m2.end(); ++it1, ++it2)
    EXPECT_EQ((*it1).first, (*it2).first);
  EXPECT_EQ(m1.size(), m2.size());
}

TEST(map_test, constructor2) {
  s21::map<int, int> m1;
  std::map<int, int> m2;
  EXPECT_EQ(m1.size(), m2.size());
  m1.insert({1, 7});
  m2.insert({1, 7});
  EXPECT_EQ(m1.size(), m2.size());
}

TEST(map_test, constructor3) {
  s21::map<std::string, int> m1{{"LeBron", 38},
                                {"Messi", 36},
                                {"Bradley Pitt", 59},
                                {"Tom Brady", 45},
                                {"Ryan Gosling", 42}};
  std::map<std::string, int> m2{{"LeBron", 38},
                                {"Messi", 36},
                                {"Bradley Pitt", 59},
                                {"Tom Brady", 45},
                                {"Ryan Gosling", 42}};
  auto m11 = m1;
  auto m22 = m2;
  auto it1 = m11.begin();
  for (auto it2 = m22.begin(); it2 != m22.end(); ++it2, ++it1)
    EXPECT_EQ((*it1).second, (*it2).second);
  EXPECT_EQ(m1.size(), m2.size());
  EXPECT_EQ(m11.size(), m22.size());
}

TEST(map_test, constructor4) {
  s21::map<std::string, int> m1{{"LeBron", 38},
                                {"Messi", 36},
                                {"Bradley Pitt", 59},
                                {"Tom Brady", 45},
                                {"Ryan Gosling", 42}};
  std::map<std::string, int> m2{{"LeBron", 38},
                                {"Messi", 36},
                                {"Bradley Pitt", 59},
                                {"Tom Brady", 45},
                                {"Ryan Gosling", 42}};
  auto m11 = std::move(m1);
  auto m22 = std::move(m2);
  auto it1 = m11.begin();
  for (auto it2 = m22.begin(); it2 != m22.end(); ++it2, ++it1)
    EXPECT_EQ((*it1).second, (*it2).second);
  EXPECT_EQ(m1.size(), m2.size());
  EXPECT_EQ(m11.size(), m22.size());
}

TEST(map_test, constructor5) {
  s21::map<std::string, int> m1{{"LeBron", 38},
                                {"Messi", 36},
                                {"Bradley Pitt", 59},
                                {"Tom Brady", 45},
                                {"Ryan Gosling", 42}};
  std::map<std::string, int> m2{{"LeBron", 38},
                                {"Messi", 36},
                                {"Bradley Pitt", 59},
                                {"Tom Brady", 45},
                                {"Ryan Gosling", 42}};
  s21::map<std::string, int> m11;
  std::map<std::string, int> m22;
  m11 = std::move(m1);
  m22 = std::move(m2);
  auto it1 = m11.begin();
  for (auto it2 = m22.begin(); it2 != m22.end(); ++it2, ++it1)
    EXPECT_EQ((*it1).second, (*it2).second);
  EXPECT_EQ(m1.size(), m2.size());
  EXPECT_EQ(m11.size(), m22.size());
}

TEST(map_test, at1) {
  s21::map<int, int> m1 = {{1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5}};
  std::map<int, int> m2 = {{1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5}};
  for (size_t i = 1; i < m1.size(); i++) EXPECT_EQ(m1.at(i), m2.at(i));
}

TEST(map_test, at2) {
  s21::map<std::string, int> m1{{"LeBron", 38},
                                {"Messi", 36},
                                {"Bradley Pitt", 59},
                                {"Tom Brady", 45},
                                {"Ryan Gosling", 42}};
  std::map<std::string, int> m2{{"LeBron", 38},
                                {"Messi", 36},
                                {"Bradley Pitt", 59},
                                {"Tom Brady", 45},
                                {"Ryan Gosling", 42}};
  EXPECT_ANY_THROW(m1.at("hm"));
  EXPECT_ANY_THROW(m2.at("hm"));
}

TEST(map_test, at3) {
  s21::map<std::string, int> m1{{"LeBron", 38},
                                {"Messi", 36},
                                {"Bradley Pitt", 59},
                                {"Tom Brady", 45},
                                {"Ryan Gosling", 42}};
  std::map<std::string, int> m2{{"LeBron", 38},
                                {"Messi", 36},
                                {"Bradley Pitt", 59},
                                {"Tom Brady", 45},
                                {"Ryan Gosling", 42}};
  EXPECT_EQ(m1.at("Messi"), m2.at("Messi"));
}

TEST(map_test, operator_ind1) {
  s21::map<int, int> m1{{7, 1}, {2, 2}, {100, 99}, {44, -19}, {1234, 4321}};
  std::map<int, int> m2{{7, 1}, {2, 2}, {100, 99}, {44, -19}, {1234, 4321}};
  EXPECT_EQ(m1[100], m2[100]);
  EXPECT_NO_THROW(m1[-2] = 3);
  EXPECT_NO_THROW(m2[-2] = 3);
  EXPECT_NO_THROW(m1.at(-2) = 5);
  EXPECT_NO_THROW(m2.at(-2) = 5);
  EXPECT_EQ(m1.at(-2), m2.at(-2));
}

TEST(map_test, begin1) {
  s21::map<int, int> m1{{7, 1}, {2, 2}, {100, 99}, {44, -19}, {1234, 4321}};
  std::map<int, int> m2{{7, 1}, {2, 2}, {100, 99}, {44, -19}, {1234, 4321}};
  auto it1 = m1.begin();
  auto it2 = m2.begin();
  EXPECT_EQ((*it1).second, (*it2).second);
}

TEST(map_test, end1) {
  s21::map<int, int> m1{{7, 1}, {2, 2}, {100, 99}, {44, -19}, {1234, 4321}};
  std::map<int, int> m2{{7, 1}, {2, 2}, {100, 99}, {44, -19}, {1234, 4321}};
  auto it1 = m1.end();
  auto it2 = m2.end();
  --it1, --it2;
  EXPECT_EQ((*it2).second, (*it1).second);
}

TEST(map_test, end2) {
  s21::map<int, int> m1{{7, 1}, {2, 2}, {100, 99}, {44, -19}, {1234, 4321}};
  std::map<int, int> m2{{7, 1}, {2, 2}, {100, 99}, {44, -19}, {1234, 4321}};
  auto it1 = m1.end();
  auto it2 = m2.end();
  --it1, --it2;
  EXPECT_EQ((*it2).second, (*it1).second);
}

TEST(map_test, empty1) {
  s21::map<int, int> m1{{7, 1}, {2, 2}, {100, 99}, {44, -19}, {1234, 4321}};
  std::map<int, int> m2{{7, 1}, {2, 2}, {100, 99}, {44, -19}, {1234, 4321}};
  EXPECT_EQ(m1.empty(), m2.empty());
}

TEST(map_test, empty2) {
  s21::map<int, int> m1{{7, 1}, {2, 2}, {100, 99}, {44, -19}, {1234, 4321}};
  std::map<int, int> m2{{7, 1}, {2, 2}, {100, 99}, {44, -19}, {1234, 4321}};
  m1.clear();
  m2.clear();
  EXPECT_EQ(m1.empty(), m2.empty());
}

TEST(map_test, size1) {
  s21::map<int, int> m1;
  std::map<int, int> m2;
  std::pair<int, int> pair = {1, 1};
  m1.insert(pair);
  m2.insert(pair);
  EXPECT_EQ(m1.size(), m2.size());
}

TEST(map_test, size2) {
  s21::map<int, int> m1{{7, 1}, {2, 2}, {100, 99}, {44, -19}, {1234, 4321}};
  std::map<int, int> m2{{7, 1}, {2, 2}, {100, 99}, {44, -19}, {1234, 4321}};
  EXPECT_EQ(m1.size(), m2.size());
}

TEST(map_test, size3) {
  s21::map<int, int> m1{{7, 1}, {2, 2}, {100, 99}, {44, -19}, {1234, 4321}};
  std::map<int, int> m2{{7, 1}, {2, 2}, {100, 99}, {44, -19}, {1234, 4321}};
  m1.clear();
  m2.clear();
  EXPECT_EQ(m1.size(), m2.size());
}

TEST(map_test, max_size1) {
  s21::map<int, int> s1;
  std::map<int, int> s2;
  EXPECT_EQ(s1.max_size(), s2.max_size());
}

TEST(map_test, clear1) {
  s21::map<int, int> m1{{7, 1}, {2, 2}, {100, 99}, {44, -19}, {1234, 4321}};
  std::map<int, int> m2{{7, 1}, {2, 2}, {100, 99}, {44, -19}, {1234, 4321}};
  m1.clear();
  m2.clear();
  EXPECT_EQ(m1.size(), m2.size());
  EXPECT_EQ(m1.empty(), m2.empty());
}

TEST(map_test, clear2) {
  s21::map<int, int> m1;
  std::map<int, int> m2;
  m1.clear();
  m2.clear();
  EXPECT_EQ(m1.size(), m2.size());
  EXPECT_EQ(m1.empty(), m2.empty());
}

TEST(map_test, clear3) {
  s21::map<int, int> m1{{7, 1}, {2, 2}, {100, 99}, {44, -19}, {1234, 4321}};
  std::map<int, int> m2{{7, 1}, {2, 2}, {100, 99}, {44, -19}, {1234, 4321}};
  m1.clear();
  m2.clear();
  EXPECT_EQ(m1.size(), m2.size());
  EXPECT_EQ(m1.empty(), m2.empty());
  m1.clear();
  m2.clear();
  EXPECT_EQ(m1.size(), m2.size());
  EXPECT_EQ(m1.empty(), m2.empty());
}

TEST(map_test, insert1) {
  s21::map<int, int> m1{{7, 1}, {2, 2}, {100, 99}, {44, -19}, {1234, 4321}};
  std::map<int, int> m2{{7, 1}, {2, 2}, {100, 99}, {44, -19}, {1234, 4321}};
  std::pair<int, int> pair = {3, 1};
  EXPECT_EQ(m1.insert(pair).second, m2.insert(pair).second);
  EXPECT_EQ(m1.size(), m2.size());
}

TEST(map_test, insert2) {
  s21::map<int, int> m1;
  std::map<int, int> m2;
  EXPECT_EQ(m1.empty(), m2.empty());
  std::pair<int, int> pair = {3, 1};
  EXPECT_EQ(m1.insert(pair).second, m2.insert(pair).second);
  EXPECT_EQ(m1.empty(), m2.empty());
  EXPECT_EQ(m1.size(), m2.size());
}

TEST(map_test, insert3) {
  s21::map<int, int> m1{{7, 1}, {2, 2}, {100, 99}, {44, -19}, {1234, 4321}};
  std::map<int, int> m2{{7, 1}, {2, 2}, {100, 99}, {44, -19}, {1234, 4321}};
  EXPECT_EQ(m1.empty(), m2.empty());
  std::pair<int, int> pair = {3, 1};
  EXPECT_EQ(m1.insert(3, 1).second, m2.insert(pair).second);
  EXPECT_EQ(m1.empty(), m2.empty());
  EXPECT_EQ(m1.size(), m2.size());
}

TEST(map_test, insert4) {
  s21::map<int, int> m1;
  std::map<int, int> m2;
  EXPECT_EQ(m1.empty(), m2.empty());
  std::pair<int, int> pair = {3, 1};
  EXPECT_EQ(m1.insert(3, 1).second, m2.insert(pair).second);
  EXPECT_EQ(m1.empty(), m2.empty());
  EXPECT_EQ(m1.size(), m2.size());
}

TEST(map_test, insert5) {
  s21::map<int, int> m1{{7, 1}, {2, 2}, {100, 99}, {44, -19}, {1234, 4321}};
  std::map<int, int> m2{{7, 1}, {2, 2}, {100, 99}, {44, -19}, {1234, 4321}};
  EXPECT_EQ(m1.empty(), m2.empty());
  EXPECT_EQ(m1.insert_or_assign(3, 1).second, m2.insert_or_assign(3, 1).second);
  EXPECT_EQ(m1.at(3), m2.at(3));
  EXPECT_EQ(m1.empty(), m2.empty());
  EXPECT_EQ(m1.size(), m2.size());
}

TEST(map_test, insert6) {
  s21::map<int, int> m1{{7, 1}, {2, 2}, {100, 99}, {44, -19}, {1234, 4321}};
  std::map<int, int> m2{{7, 1}, {2, 2}, {100, 99}, {44, -19}, {1234, 4321}};
  EXPECT_EQ(m1.empty(), m2.empty());
  EXPECT_EQ(m1.insert_or_assign(2, 1).second, m2.insert_or_assign(2, 1).second);
  EXPECT_EQ(m1.at(2), m2.at(2));
  EXPECT_EQ(m1.empty(), m2.empty());
  EXPECT_EQ(m1.size(), m2.size());
}

TEST(map_test, erase1) {
  s21::map<int, int> m1{{7, 1}, {2, 2}, {100, 99}, {44, -19}, {1234, 4321}};
  std::map<int, int> m2{{7, 1}, {2, 2}, {100, 99}, {44, -19}, {1234, 4321}};
  EXPECT_EQ(m1.size(), m2.size());
  m1.erase(m1.begin());
  m2.erase(m2.begin());
  EXPECT_EQ(m1.size(), m2.size());
  EXPECT_ANY_THROW(m1.erase(m1.end()));
}

TEST(map_test, erase2) {
  s21::map<int, int> m1{{7, 1}, {2, 2}, {100, 99}, {44, -19}, {1234, 4321}};
  std::map<int, int> m2{{7, 1}, {2, 2}, {100, 99}, {44, -19}, {1234, 4321}};
  m1.erase(m1.begin());
  m2.erase(m2.begin());
  auto it1 = m1.begin();
  auto it2 = m2.begin();
  EXPECT_EQ(m1.size(), m2.size());
  EXPECT_EQ((*it1).second, (*it2).second);
}

TEST(map_test, swap1) {
  s21::map<int, int> m1{{7, 1}, {2, 2}, {100, 99}, {44, -19}, {1234, 4321}};
  std::map<int, int> m2{{7, 1}, {2, 2}, {100, 99}, {44, -19}, {1234, 4321}};
  s21::map<int, int> m11;
  std::map<int, int> m22;
  m1.swap(m11);
  m2.swap(m22);
  EXPECT_EQ(m1.size(), m2.size());
  EXPECT_EQ(m11.size(), m22.size());
  auto it1 = m11.begin();
  for (auto it2 = m22.begin(); it2 != m22.end(); ++it1, ++it2)
    EXPECT_EQ((*it1).second, (*it2).second);
}

TEST(map_test, swap2) {
  s21::map<int, int> m1{{7, 1}, {2, 2}, {100, 99}, {44, -19}, {1234, 4321}};
  std::map<int, int> m2{{7, 1}, {2, 2}, {100, 99}, {44, -19}, {1234, 4321}};
  s21::map<int, int> m11{
      {15, 44}, {265, 2904}, {243508, 24}, {22435, 7}, {7, 45}};
  std::map<int, int> m22{
      {15, 44}, {265, 2904}, {243508, 24}, {22435, 7}, {7, 45}};
  m1.swap(m11);
  m2.swap(m22);
  EXPECT_EQ(m1.size(), m2.size());
  EXPECT_EQ(m11.size(), m22.size());
  auto it1 = m11.begin();
  for (auto it2 = m22.begin(); it2 != m22.end(); ++it1, ++it2)
    EXPECT_EQ((*it1).second, (*it2).second);
}

TEST(map_test, swap3) {
  s21::map<int, int> m1;
  std::map<int, int> m2;
  s21::map<int, int> m11;
  std::map<int, int> m22;
  m1.swap(m11);
  m2.swap(m22);
  EXPECT_EQ(m1.size(), m2.size());
  EXPECT_EQ(m11.size(), m22.size());
  auto it1 = m11.begin();
  for (auto it2 = m22.begin(); it2 != m22.end(); ++it1, ++it2)
    EXPECT_EQ((*it1).second, (*it2).second);
}

TEST(map_test, merge1) {
  s21::map<int, int> m1{{7, 1}, {2, 2}, {100, 99}, {44, -19}, {1234, 4321}};
  std::map<int, int> m2{{7, 1}, {2, 2}, {100, 99}, {44, -19}, {1234, 4321}};
  s21::map<int, int> m11{
      {15, 44}, {265, 2904}, {243508, 24}, {22435, 7}, {7, 45}};
  std::map<int, int> m22{
      {15, 44}, {265, 2904}, {243508, 24}, {22435, 7}, {7, 45}};
  m1.merge(m11);
  m2.merge(m22);
  EXPECT_EQ(m1.size(), m2.size());
  EXPECT_EQ(m11.size(), m22.size());
  auto it1 = m1.begin();
  for (auto it2 = m2.begin(); it2 != m2.end(); ++it1, ++it2)
    EXPECT_EQ((*it1).second, (*it2).second);
}

TEST(map_test, merge2) {
  s21::map<int, int> m1{{7, 1}, {2, 2}, {100, 99}, {44, -19}, {1234, 4321}};
  std::map<int, int> m2{{7, 1}, {2, 2}, {100, 99}, {44, -19}, {1234, 4321}};
  s21::map<int, int> m11{
      {15, 44}, {265, 2904}, {243508, 24}, {22435, 7}, {7, 45}};
  std::map<int, int> m22{
      {15, 44}, {265, 2904}, {243508, 24}, {22435, 7}, {7, 45}};
  m1.merge(m11);
  m2.merge(m22);
  EXPECT_EQ(m1.size(), m2.size());
  EXPECT_EQ(m11.size(), m22.size());
  auto it1 = m1.begin();
  for (auto it2 = m2.begin(); it2 != m2.end(); ++it1, ++it2)
    EXPECT_EQ((*it1).second, (*it2).second);
}

TEST(map_test, merge3) {
  s21::map<int, int> m1{{7, 1}, {2, 2}, {100, 99}, {44, -19}, {1234, 4321}};
  std::map<int, int> m2{{7, 1}, {2, 2}, {100, 99}, {44, -19}, {1234, 4321}};
  s21::map<int, int> m11{{15, 44}, {265, 2904}, {243508, 24}, {22435, 7},
                         {7, 45},  {56, 0},     {4, 0},       {542, 5}};
  std::map<int, int> m22{{15, 44}, {265, 2904}, {243508, 24}, {22435, 7},
                         {7, 45},  {56, 0},     {4, 0},       {542, 5}};
  m1.merge(m11);
  m2.merge(m22);
  EXPECT_EQ(m1.size(), m2.size());
  EXPECT_EQ(m11.size(), m22.size());
  auto it1 = m1.begin();
  for (auto it2 = m2.begin(); it2 != m2.end(); ++it1, ++it2)
    EXPECT_EQ((*it1).second, (*it2).second);
}

TEST(map_test, contains1) {
  s21::map<int, int> m1{{7, 1}, {2, 2}, {100, 99}, {44, -19}, {1234, 4321}};
  EXPECT_EQ(m1.contains(44), true);
}

TEST(map_test, contains2) {
  s21::map<int, int> m1{{7, 1}, {2, 2}, {100, 99}, {44, -19}, {1234, 4321}};
  EXPECT_EQ(m1.contains(0), false);
}

TEST(map_test, emplace) {
  s21::map<std::string, int> m1{{"LeBron", 38}, {"Messi", 36}};
  std::map<std::string, int> m2{{"LeBron", 38}, {"Messi", 36}};
  m1.emplace("Bradley Pitt", 59);
  m1.emplace("LeBron", 38);
  m1.emplace("Ryan Gosling", 42);
  m1.emplace("Messi", 36);
  m1.emplace("Ryan Gosling", 42);
  m2.emplace("Bradley Pitt", 59);
  m2.emplace("LeBron", 38);
  m2.emplace("Ryan Gosling", 42);
  m2.emplace("Messi", 36);
  m2.emplace("Ryan Gosling", 42);
  s21::map<std::string, int>::iterator it1 = m1.begin();
  std::map<std::string, int>::iterator it2 = m2.begin();
  EXPECT_EQ(m1.size(), m2.size());
  for (; it2 != m2.end(); ++it1, ++it2) EXPECT_EQ((*it1).second, (*it2).second);
}
