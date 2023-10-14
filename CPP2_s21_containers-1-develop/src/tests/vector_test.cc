#include <gtest/gtest.h>

#include <vector>

#include "../headers/s21_vector.h"

TEST(VectorTest, constructor_default) {
  s21::vector<int> vectors210;
  std::vector<int> vectorstd0;
  s21::vector<char> vectors211;
  std::vector<char> vectorstd1;
  s21::vector<std::string> vectors212;
  std::vector<std::string> vectorstd2;
  s21::vector<double> vectors213;
  std::vector<double> vectorstd3;
  EXPECT_EQ(vectorstd0.size(), vectors210.size());
  EXPECT_EQ(vectorstd0.capacity(), vectors210.capacity());
  EXPECT_EQ(vectorstd1.size(), vectors211.size());
  EXPECT_EQ(vectorstd1.capacity(), vectors211.capacity());
  EXPECT_EQ(vectorstd2.size(), vectors212.size());
  EXPECT_EQ(vectorstd2.capacity(), vectors212.capacity());
  EXPECT_EQ(vectorstd3.size(), vectors213.size());
  EXPECT_EQ(vectorstd3.capacity(), vectors213.capacity());
}

TEST(VectorTest, constructor_parametrized) {
  s21::vector<int> vectors21(5);
  std::vector<int> vectorstd(5);
  EXPECT_EQ(vectorstd.size(), vectors21.size());
}

TEST(VectorTest, constructor_initializer_list) {
  s21::vector<int> vectors21{1, 2, 3, 4, 5};
  std::vector<int> vectorstd{1, 2, 3, 4, 5};
  EXPECT_EQ(vectorstd.at(0), vectors21.at(0));
  EXPECT_EQ(vectorstd.at(1), vectors21.at(1));
  EXPECT_EQ(vectorstd.at(2), vectors21.at(2));
  EXPECT_EQ(vectorstd.at(3), vectors21.at(3));
  EXPECT_EQ(vectorstd.at(4), vectors21.at(4));
}

TEST(VectorTest, constructor_copy) {
  s21::vector<int> vectors21{1, 2, 3, 4, 5};
  s21::vector<int> cvectors21(vectors21);
  std::vector<int> vectorstd{1, 2, 3, 4, 5};
  std::vector<int> cvectorstd(vectorstd);
  EXPECT_EQ(cvectors21.at(0), cvectorstd.at(0));
  EXPECT_EQ(cvectors21.at(1), cvectorstd.at(1));
  EXPECT_EQ(cvectors21.at(2), cvectorstd.at(2));
  EXPECT_EQ(cvectors21.at(3), cvectorstd.at(3));
  EXPECT_EQ(cvectors21.at(4), cvectorstd.at(4));
}

TEST(VectorTest, constructor_move) {
  s21::vector<int> vectors21{1, 2, 3, 4, 5};
  s21::vector<int> mvectors21(std::move(vectors21));
  std::vector<int> vectorstd{1, 2, 3, 4, 5};
  std::vector<int> mvectorstd(std::move(vectorstd));
  EXPECT_EQ(mvectors21.at(0), mvectorstd.at(0));
  EXPECT_EQ(mvectors21.at(1), mvectorstd.at(1));
  EXPECT_EQ(mvectors21.at(2), mvectorstd.at(2));
  EXPECT_EQ(mvectors21.at(3), mvectorstd.at(3));
  EXPECT_EQ(mvectors21.at(4), mvectorstd.at(4));
}

TEST(VectorTest, constructor_operator) {
  s21::vector<int> vectors21 = {1, 2, 3, 4, 5};
  s21::vector<int> mvectors21;
  mvectors21 = std::move(vectors21);
  EXPECT_EQ(mvectors21.at(0), 1);
  EXPECT_EQ(mvectors21.at(1), 2);
  EXPECT_EQ(mvectors21.at(2), 3);
  EXPECT_EQ(mvectors21.at(3), 4);
  EXPECT_EQ(mvectors21.at(4), 5);
}

TEST(VectorTest, at_function) {
  s21::vector<int> vectors21{1, 2, 3, 4, 5};
  std::vector<int> vectorstd{1, 2, 3, 4, 5};
  EXPECT_EQ(vectors21.at(0), vectorstd.at(0));
  EXPECT_EQ(vectors21.at(1), vectorstd.at(1));
  EXPECT_EQ(vectors21.at(2), vectorstd.at(2));
  EXPECT_EQ(vectors21.at(3), vectorstd.at(3));
  EXPECT_EQ(vectors21.at(4), vectorstd.at(4));
}

TEST(VectorTest, at_throw) {
  s21::vector<int> vectors21;
  std::vector<int> vectorstd;
  EXPECT_ANY_THROW(vectors21.at(1));
  EXPECT_ANY_THROW(vectorstd.at(1));
}

TEST(VectorTest, square_brackets_operator) {
  s21::vector<int> vectors21{1, 2, 3, 4, 5};
  std::vector<int> vectorstd{1, 2, 3, 4, 5};
  EXPECT_EQ(vectors21[0], vectorstd[0]);
  EXPECT_EQ(vectors21[1], vectorstd[1]);
  EXPECT_EQ(vectors21[2], vectorstd[2]);
  EXPECT_EQ(vectors21[3], vectorstd[3]);
  EXPECT_EQ(vectors21[4], vectorstd[4]);
}

TEST(VectorTest, front_function) {
  s21::vector<int> vectors21{1, 2, 3, 4, 5};
  std::vector<int> vectorstd{1, 2, 3, 4, 5};
  EXPECT_EQ(vectors21.front(), vectorstd.front());
}

TEST(VectorTest, back_function) {
  s21::vector<int> vectors21{1, 2, 3, 4, 5};
  std::vector<int> vectorstd{1, 2, 3, 4, 5};
  EXPECT_EQ(vectors21.back(), vectorstd.back());
}

TEST(VectorTest, data_function) {
  s21::vector<int> vectors21{1, 2, 3, 4, 5};
  std::vector<int> vectorstd{1, 2, 3, 4, 5};
  EXPECT_EQ(*vectors21.data(), *vectorstd.data());
}

TEST(VectorTest, empty_function) {
  s21::vector<int> vectors21;
  std::vector<int> vectorstd;
  EXPECT_EQ(vectors21.empty(), vectorstd.empty());
}

TEST(VectorTest, size_function) {
  s21::vector<int> vectors21{1, 2, 3, 4, 5};
  std::vector<int> vectorstd{1, 2, 3, 4, 5};
  EXPECT_EQ(vectors21.size(), vectorstd.size());
}

TEST(VectorTest, max_size_function) {
  s21::vector<int> vectors21{1, 2, 3, 4, 5};
  std::vector<int> vectorstd{1, 2, 3, 4, 5};
  EXPECT_EQ(vectors21.max_size(), vectorstd.max_size());
}

TEST(VectorTest, reserve_function_0) {
  s21::vector<int> vectors21;
  std::vector<int> vectorstd;
  vectors21.reserve(5);
  vectorstd.reserve(5);
  EXPECT_EQ(vectors21.capacity(), vectorstd.capacity());
}

TEST(VectorTest, reserve_function_1) {
  s21::vector<int> vectors21(5);
  std::vector<int> vectorstd(5);
  vectors21.reserve(1);
  vectorstd.reserve(1);
  EXPECT_EQ(vectors21.capacity(), vectorstd.capacity());
}

TEST(VectorTest, reserve_function_2) {
  s21::vector<int> vectors21{1, 2, 3, 4, 5};
  std::vector<int> vectorstd{1, 2, 3, 4, 5};
  vectors21.reserve(2);
  vectorstd.reserve(2);
  EXPECT_EQ(vectors21.capacity(), vectorstd.capacity());
}

// TEST(VectorTest, reserve_throw) {
//   s21::vector<int> vectors21;
//   std::vector<int> vectorstd;
//   EXPECT_ANY_THROW(vectors21.reserve(2305843009213693952));
//   EXPECT_ANY_THROW(vectorstd.reserve(2305843009213693952));
// }

TEST(VectorTest, capacity_function) {
  s21::vector<int> vectors21{1, 2, 3, 4, 5};
  std::vector<int> vectorstd{1, 2, 3, 4, 5};
  EXPECT_EQ(vectors21.capacity(), vectorstd.capacity());
}

TEST(VectorTest, shrink_to_fit_function) {
  s21::vector<int> vectors21;
  std::vector<int> vectorstd;
  vectors21.reserve(10);
  vectorstd.reserve(10);
  vectors21.shrink_to_fit();
  vectorstd.shrink_to_fit();
  EXPECT_EQ(vectors21.capacity(), vectorstd.capacity());
}

TEST(VectorTest, clear_function) {
  s21::vector<int> vectors21;
  std::vector<int> vectorstd;
  vectors21.clear();
  vectorstd.clear();
  EXPECT_EQ(vectors21.size(), vectorstd.size());
}

TEST(VectorTest, iterator_0) {
  s21::vector<int> vectors21{1, 2, 3, 4, 5};
  std::vector<int> vectorstd{1, 2, 3, 4, 5};
  s21::vector<int>::iterator i = vectors21.begin();
  std::vector<int>::iterator j = vectorstd.begin();
  EXPECT_EQ(vectors21.at(0), *i);
  EXPECT_EQ(vectorstd.at(0), *j);
}

TEST(VectorTest, iterator_1) {
  s21::vector<int> vectors21{1, 2, 3, 4, 5};
  std::vector<int> vectorstd{1, 2, 3, 4, 5};
  s21::vector<int>::iterator i = vectors21.begin();
  std::vector<int>::iterator j = vectorstd.begin();
  i++;
  j++;
  EXPECT_EQ(vectors21.at(1), *i);
  EXPECT_EQ(vectorstd.at(1), *j);
}

TEST(VectorTest, insert_function) {
  s21::vector<int> vectors21{1, 2, 3};
  std::vector<int> vectorstd{1, 2, 3};
  vectors21.insert(vectors21.begin() + 1, 5);
  vectorstd.insert(vectorstd.begin() + 1, 5);
  EXPECT_EQ(vectors21.at(0), vectorstd.at(0));
  EXPECT_EQ(vectors21.at(1), vectorstd.at(1));
  EXPECT_EQ(vectors21.at(2), vectorstd.at(2));
  EXPECT_EQ(vectors21.at(3), vectorstd.at(3));
}

TEST(VectorTest, insert_throw) {
  s21::vector<int> vectors21{1, 2, 3};
  EXPECT_ANY_THROW(vectors21.insert(vectors21.begin() + 5, 5));
}

TEST(VectorTest, erase_function) {
  s21::vector<int> vectors21{1, 2, 3};
  std::vector<int> vectorstd{1, 2, 3};
  vectors21.erase(vectors21.begin() + 1);
  vectorstd.erase(vectorstd.begin() + 1);
  EXPECT_EQ(vectors21.at(0), vectorstd.at(0));
  EXPECT_EQ(vectors21.at(1), vectorstd.at(1));
}

TEST(VectorTest, erase_throw) {
  s21::vector<int> vectors21{1, 2, 3};
  EXPECT_ANY_THROW(vectors21.erase(vectors21.begin() + 5));
}

TEST(VectorTest, push_back_function) {
  s21::vector<int> vectors21;
  std::vector<int> vectorstd;
  vectors21.push_back(1);
  vectors21.push_back(2);
  vectorstd.push_back(1);
  vectorstd.push_back(2);
  EXPECT_EQ(vectors21.at(0), vectorstd.at(0));
  EXPECT_EQ(vectors21.at(1), vectorstd.at(1));
}

TEST(VectorTest, pop_back_function) {
  s21::vector<int> vectors21{1, 2};
  std::vector<int> vectorstd{1, 2};
  vectors21.pop_back();
  vectors21.pop_back();
  vectorstd.pop_back();
  vectorstd.pop_back();
  EXPECT_EQ(vectors21.size(), 0);
  EXPECT_EQ(vectors21.capacity(), 2);
}

TEST(VectorTest, swap_function) {
  s21::vector<int> vectors21{1, 2, 3, 4, 5};
  s21::vector<int> svectors21;
  std::vector<int> vectorstd{1, 2, 3, 4, 5};
  std::vector<int> svectorstd;
  svectors21.swap(vectors21);
  svectorstd.swap(vectorstd);
  EXPECT_EQ(vectors21.size(), vectorstd.size());
  EXPECT_EQ(vectors21.capacity(), vectorstd.capacity());
  EXPECT_EQ(svectors21.size(), svectorstd.size());
  EXPECT_EQ(svectors21.capacity(), svectorstd.capacity());
}

TEST(VectorTest, iterator_operator_minus_minus) {
  s21::vector<int> vectors21{1, 2, 3, 4, 5};
  std::vector<int> vectorstd{1, 2, 3, 4, 5};
  EXPECT_EQ(vectors21.at(2)--, vectorstd.at(2)--);
}
TEST(VectorTest, iterator_operator_plus_plus) {
  s21::vector<int> vectors21{1, 2, 3, 4, 5};
  std::vector<int> vectorstd{1, 2, 3, 4, 5};
  EXPECT_EQ(vectors21.at(1)++, vectorstd.at(1)++);
}
TEST(VectorTest, iterator_operator_plus) {
  s21::vector<int> vectors21{1, 2, 3, 4, 5};
  std::vector<int> vectorstd{1, 2, 3, 4, 5};
  EXPECT_EQ(vectors21.at(0) + vectors21.at(1),
            vectorstd.at(0) + vectorstd.at(1));
}
TEST(VectorTest, iterator_operator_minus) {
  s21::vector<int> vectors21{1, 2, 3, 4, 5};
  std::vector<int> vectorstd{1, 2, 3, 4, 5};
  EXPECT_EQ(vectors21.at(2) - vectors21.at(1),
            vectorstd.at(2) - vectorstd.at(1));
}
TEST(VectorTest, iterator_operator_eq) {
  s21::vector<int> vectors21{1, 2, 3, 4, 5};
  std::vector<int> vectorstd{1, 2, 3, 4, 5};
  EXPECT_EQ(vectors21.at(4) == vectorstd.at(4), 1);
}
TEST(VectorTest, iterator_operator_not_eq) {
  s21::vector<int> vectors21{1, 2, 3, 4, 5};
  std::vector<int> vectorstd{1, 2, 3, 4, 5};
  EXPECT_EQ(vectors21.at(3) != vectorstd.at(4), 1);
}
