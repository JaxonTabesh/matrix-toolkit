#ifndef MATRIX_TOOLKIT_MATRIX_HPP
#define MATRIX_TOOLKIT_MATRIX_HPP

#include <iostream>
#include <sstream>
#include <vector>

template <typename T>
class Matrix {
 private:
  std::vector<std::vector<T>> values;
  size_t rows, cols;

 public:
  Matrix(size_t rows, size_t cols, const std::vector<std::vector<T>>& matrix)
      : rows(rows), cols(cols), values(matrix) {}
  Matrix(size_t rows, size_t cols) : rows(rows), cols(cols) {
    values = std::vector<std::vector<T>>(rows, std::vector<T>(cols, 0));
  }

  std::string toString() const {
    std::ostringstream oss;
    for (const auto& row : values) {
      for (const auto& col : row) {
        oss << col << " ";
      }
      oss << "\n";
    }
    return oss.str();
  }

  void print() const { std::cout << this->toString(); }

  // operator+ promotes the type
  template <typename U>
  Matrix<decltype(std::declval<T>() + std::declval<U>())> operator+(
      const Matrix<U>& other) const {
    if (this->rows != other.rows || this->cols != other.cols) {
      throw std::invalid_argument("Matrix dimensions must match for addition");
    }
    using R = decltype(std::declval<T>() + std::declval<U>());
    Matrix<R> res(this->rows, this->cols);
    for (size_t i = 0; i < this->rows; i++) {
      for (size_t j = 0; j < this->cols; j++) {
        res.values[i][j] = this->values[i][j] + other.values[i][j];
      }
    }
    return res;
  }

  // operator- promotes the type
  template <typename U>
  Matrix<decltype(std::declval<T>() + std::declval<U>())> operator-(
      const Matrix<U>& other) const {
    if (this->rows != other.rows || this->cols != other.cols) {
      throw std::invalid_argument(
          "Matrix dimensions must match for subtraction");
    }
    using R = decltype(std::declval<T>() + std::declval<U>());
    Matrix<R> res(this->rows, this->cols);
    for (size_t i = 0; i < this->rows; i++) {
      for (size_t j = 0; j < this->cols; j++) {
        res.values[i][j] = this->values[i][j] - other.values[i][j];
      }
    }
    return res;
  }

  // Strict types only
  Matrix<T>& operator+=(const Matrix<T>& other) {
    if (this->rows != other.rows || this->cols != other.cols) {
      throw std::invalid_argument("Matrix dimensions must match for addition");
    }
    for (size_t i = 0; i < this->rows; i++) {
      for (size_t j = 0; j < this->cols; j++) {
        this->values[i][j] += other.values[i][j];
      }
    }
    return *this;
  }

  // Strict types only
  Matrix<T>& operator-=(const Matrix<T>& other) {
    if (this->rows != other.rows || this->cols != other.cols) {
      throw std::invalid_argument(
          "Matrix dimensions must match for subtraction");
    }
    for (size_t i = 0; i < this->rows; i++) {
      for (size_t j = 0; j < this->cols; j++) {
        this->values[i][j] -= other.values[i][j];
      }
    }
    return *this;
  }
};

#endif