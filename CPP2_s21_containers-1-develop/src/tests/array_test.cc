#include <gtest/gtest.h>

#include <array>

#include "../s21_containers.h"

TEST(ArrayTest, constructor_default) {
  s21::array<int, 0> arrays210;
  std::array<int, 0> arraystd0;
  s21::array<char, 0> arrays211;
  std::array<char, 0> arraystd1;
  s21::array<std::string, 0> arrays212;
  std::array<std::string, 0> arraystd2;
  s21::array<double, 0> arrays213;
  std::array<double, 0> arraystd3;
  EXPECT_EQ(arraystd0.size(), arrays210.size());
  EXPECT_EQ(arraystd1.size(), arrays211.size());
  EXPECT_EQ(arraystd2.size(), arrays212.size());
  EXPECT_EQ(arraystd3.size(), arrays213.size());
}

TEST(ArrayTest, constructor_initializer_list) {
  s21::array<int, 5> arrays21{1, 2, 3, 4, 5};
  std::array<int, 5> arraystd{1, 2, 3, 4, 5};
  EXPECT_EQ(arraystd.at(0), arrays21.at(0));
  EXPECT_EQ(arraystd.at(1), arrays21.at(1));
  EXPECT_EQ(arraystd.at(2), arrays21.at(2));
  EXPECT_EQ(arraystd.at(3), arrays21.at(3));
  EXPECT_EQ(arraystd.at(4), arrays21.at(4));
}

TEST(ArrayTest, constructor_copy) {
  s21::array<int, 5> arrays21{1, 2, 3, 4, 5};
  s21::array<int, 5> carrays21(arrays21);
  std::array<int, 5> arraystd{1, 2, 3, 4, 5};
  std::array<int, 5> carraystd(arraystd);
  EXPECT_EQ(carrays21.at(0), carraystd.at(0));
  EXPECT_EQ(carrays21.at(1), carraystd.at(1));
  EXPECT_EQ(carrays21.at(2), carraystd.at(2));
  EXPECT_EQ(carrays21.at(3), carraystd.at(3));
  EXPECT_EQ(carrays21.at(4), carraystd.at(4));
}

TEST(ArrayTest, constructor_move) {
  s21::array<int, 5> arrays21{1, 2, 3, 4, 5};
  s21::array<int, 5> marrays21(std::move(arrays21));
  std::array<int, 5> arraystd{1, 2, 3, 4, 5};
  std::array<int, 5> marraystd(std::move(arraystd));
  EXPECT_EQ(marrays21.at(0), marraystd.at(0));
  EXPECT_EQ(marrays21.at(1), marraystd.at(1));
  EXPECT_EQ(marrays21.at(2), marraystd.at(2));
  EXPECT_EQ(marrays21.at(3), marraystd.at(3));
  EXPECT_EQ(marrays21.at(4), marraystd.at(4));
}

TEST(ArrayTest, constructor_operator) {
  s21::array<int, 5> arrays21 = {1, 2, 3, 4, 5};
  s21::array<int, 5> marrays21;
  marrays21 = std::move(arrays21);
  EXPECT_EQ(marrays21.at(0), 1);
  EXPECT_EQ(marrays21.at(1), 2);
  EXPECT_EQ(marrays21.at(2), 3);
  EXPECT_EQ(marrays21.at(3), 4);
  EXPECT_EQ(marrays21.at(4), 5);
}

TEST(ArrayTest, at_function) {
  s21::array<int, 5> arrays21{1, 2, 3, 4, 5};
  std::array<int, 5> arraystd{1, 2, 3, 4, 5};
  EXPECT_EQ(arrays21.at(0), arraystd.at(0));
  EXPECT_EQ(arrays21.at(1), arraystd.at(1));
  EXPECT_EQ(arrays21.at(2), arraystd.at(2));
  EXPECT_EQ(arrays21.at(3), arraystd.at(3));
  EXPECT_EQ(arrays21.at(4), arraystd.at(4));
}

TEST(ArrayTest, at_throw) {
  s21::array<int, 0> arrays21;
  std::array<int, 0> arraystd;
  EXPECT_ANY_THROW(arrays21.at(1));
  EXPECT_ANY_THROW(arraystd.at(1));
}

TEST(ArrayTest, square_brackets_operator) {
  s21::array<int, 5> arrays21{1, 2, 3, 4, 5};
  std::array<int, 5> arraystd{1, 2, 3, 4, 5};
  EXPECT_EQ(arrays21[0], arraystd[0]);
  EXPECT_EQ(arrays21[1], arraystd[1]);
  EXPECT_EQ(arrays21[2], arraystd[2]);
  EXPECT_EQ(arrays21[3], arraystd[3]);
  EXPECT_EQ(arrays21[4], arraystd[4]);
}

TEST(ArrayTest, front_function) {
  s21::array<int, 5> arrays21{1, 2, 3, 4, 5};
  std::array<int, 5> arraystd{1, 2, 3, 4, 5};
  EXPECT_EQ(arrays21.front(), arraystd.front());
}

TEST(ArrayTest, back_function) {
  s21::array<int, 5> arrays21{1, 2, 3, 4, 5};
  std::array<int, 5> arraystd{1, 2, 3, 4, 5};
  EXPECT_EQ(arrays21.back(), arraystd.back());
}

TEST(ArrayTest, data_function) {
  s21::array<int, 5> arrays21{1, 2, 3, 4, 5};
  std::array<int, 5> arraystd{1, 2, 3, 4, 5};
  EXPECT_EQ(*arrays21.data(), *arraystd.data());
}

TEST(ArrayTest, empty_function) {
  s21::array<int, 0> arrays21;
  std::array<int, 0> arraystd;
  EXPECT_EQ(arrays21.empty(), arraystd.empty());
}

TEST(ArrayTest, size_function) {
  s21::array<int, 5> arrays21{1, 2, 3, 4, 5};
  std::array<int, 5> arraystd{1, 2, 3, 4, 5};
  EXPECT_EQ(arrays21.size(), arraystd.size());
}

TEST(ArrayTest, max_size_function) {
  s21::array<int, 5> arrays21{1, 2, 3, 4, 5};
  std::array<int, 5> arraystd{1, 2, 3, 4, 5};
  EXPECT_EQ(arrays21.max_size(), arraystd.max_size());
}

TEST(ArrayTest, iterator_0) {
  s21::array<int, 5> arrays21{1, 2, 3, 4, 5};
  std::array<int, 5> arraystd{1, 2, 3, 4, 5};
  s21::array<int, 5>::iterator i = arrays21.begin();
  std::array<int, 5>::iterator j = arraystd.begin();
  EXPECT_EQ(arrays21.at(0), *i);
  EXPECT_EQ(arraystd.at(0), *j);
}

TEST(ArrayTest, iterator_1) {
  s21::array<int, 5> arrays21{1, 2, 3, 4, 5};
  std::array<int, 5> arraystd{1, 2, 3, 4, 5};
  s21::array<int, 5>::iterator i = arrays21.begin();
  std::array<int, 5>::iterator j = arraystd.begin();
  i++;
  j++;
  EXPECT_EQ(arrays21.at(1), *i);
  EXPECT_EQ(arraystd.at(1), *j);
}

TEST(ArrayTest, iterator_operator_minus_minus) {
  s21::array<int, 5> arrays21{1, 2, 3, 4, 5};
  std::array<int, 5> arraystd{1, 2, 3, 4, 5};
  EXPECT_EQ(arrays21.at(2)--, arraystd.at(2)--);
}
TEST(ArrayTest, iterator_operator_plus_plus) {
  s21::array<int, 5> arrays21{1, 2, 3, 4, 5};
  std::array<int, 5> arraystd{1, 2, 3, 4, 5};
  EXPECT_EQ(arrays21.at(1)++, arraystd.at(1)++);
}
TEST(ArrayTest, iterator_operator_plus) {
  s21::array<int, 5> arrays21{1, 2, 3, 4, 5};
  std::array<int, 5> arraystd{1, 2, 3, 4, 5};
  EXPECT_EQ(arrays21.at(0) + arrays21.at(1), arraystd.at(0) + arraystd.at(1));
}
TEST(ArrayTest, iterator_operator_minus) {
  s21::array<int, 5> arrays21{1, 2, 3, 4, 5};
  std::array<int, 5> arraystd{1, 2, 3, 4, 5};
  EXPECT_EQ(arrays21.at(2) - arrays21.at(1), arraystd.at(2) - arraystd.at(1));
}
TEST(ArrayTest, iterator_operator_eq) {
  s21::array<int, 5> arrays21{1, 2, 3, 4, 5};
  std::array<int, 5> arraystd{1, 2, 3, 4, 5};
  EXPECT_EQ(arrays21.at(4) == arraystd.at(4), 1);
}
TEST(ArrayTest, iterator_operator_not_eq) {
  s21::array<int, 5> arrays21{1, 2, 3, 4, 5};
  std::array<int, 5> arraystd{1, 2, 3, 4, 5};
  EXPECT_EQ(arrays21.at(3) != arraystd.at(4), 1);
}
