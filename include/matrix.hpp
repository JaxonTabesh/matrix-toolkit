#ifndef MATRIX_TOOLKIT_MATRIX_HPP
#define MATRIX_TOOLKIT_MATRIX_HPP

#include <iostream>
#include <sstream>
#include <vector>

template <typename T>
class Matrix {
  template <typename>
  friend class Matrix;

 private:
  std::vector<std::vector<T>> values;
  size_t rows, cols;

 public:
  Matrix(size_t rows, size_t cols)
      : rows(rows),
        cols(cols),
        values(values =
                   std::vector<std::vector<T>>(rows, std::vector<T>(cols, 0))) {
  }
  Matrix(size_t rows, size_t cols, T defNum)
      : rows(rows),
        cols(cols),
        values(
            std::vector<std::vector<T>>(rows, std::vector<T>(cols, defNum))) {}
  template <typename U>
  Matrix(const Matrix<U>& other)
      : rows(other.getRows()),
        cols(other.getCols()),
        values(std::vector<std::vector<T>>(rows, std::vector<T>(cols, 0))) {
    for (size_t i = 0; i < rows; i++) {
      for (size_t j = 0; j < cols; j++) {
        values[i][j] = static_cast<T>(other.get(i, j));
      }
    }
  }

  size_t getRows() const { return rows; }

  size_t getCols() const { return cols; }

  T get(size_t i, size_t j) const {
    if (i >= rows || j >= cols) {
      throw std::invalid_argument("Your indexes are out of bounds.");
    }
    return values[i][j];
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

  void print() const { std::cout << toString(); }

  // operator+ promotes the type
  template <typename U>
  Matrix<decltype(std::declval<T>() + std::declval<U>())> operator+(
      const Matrix<U>& other) const {
    if (rows != other.rows || cols != other.cols) {
      throw std::invalid_argument("Matrix dimensions must match for addition");
    }
    using R = decltype(std::declval<T>() + std::declval<U>());
    Matrix<R> res(rows, cols);
    for (size_t i = 0; i < rows; i++) {
      for (size_t j = 0; j < cols; j++) {
        res.values[i][j] = values[i][j] + other.values[i][j];
      }
    }
    return res;
  }

  // operator- promotes the type
  template <typename U>
  Matrix<decltype(std::declval<T>() + std::declval<U>())> operator-(
      const Matrix<U>& other) const {
    if (rows != other.rows || cols != other.cols) {
      throw std::invalid_argument(
          "Matrix dimensions must match for subtraction");
    }
    using R = decltype(std::declval<T>() + std::declval<U>());
    Matrix<R> res(rows, cols);
    for (size_t i = 0; i < rows; i++) {
      for (size_t j = 0; j < cols; j++) {
        res.values[i][j] = values[i][j] - other.values[i][j];
      }
    }
    return res;
  }

  // operator* promotes the type
  template <typename U>
  Matrix<decltype(std::declval<T>() * std::declval<U>())> operator*(
      const U scalar) const {
    using R = decltype(std::declval<T>() * std::declval<U>());
    Matrix<R> res(rows, cols);
    for (size_t i = 0; i < rows; i++) {
      for (size_t j = 0; j < cols; j++) {
        res.values[i][j] = values[i][j] * scalar;
      }
    }
    return res;
  }

  // operator* promotes the type
  template <typename U>
  friend Matrix<decltype(std::declval<U>() * std::declval<T>())> operator*(
      const U scalar, const Matrix<T>& mat) {
    using R = decltype(std::declval<U>() * std::declval<T>());
    Matrix<R> res(mat.rows, mat.cols);
    for (size_t i = 0; i < mat.rows; i++) {
      for (size_t j = 0; j < mat.cols; j++) {
        res.values[i][j] = mat.values[i][j] * scalar;
      }
    }
    return res;
  }

  // Strict types only
  Matrix<T>& operator+=(const Matrix<T>& other) {
    if (rows != other.rows || cols != other.cols) {
      throw std::invalid_argument("Matrix dimensions must match for addition");
    }
    for (size_t i = 0; i < rows; i++) {
      for (size_t j = 0; j < cols; j++) {
        values[i][j] += other.values[i][j];
      }
    }
    return *this;
  }

  // Strict types only
  Matrix<T>& operator-=(const Matrix<T>& other) {
    if (rows != other.rows || cols != other.cols) {
      throw std::invalid_argument(
          "Matrix dimensions must match for subtraction");
    }
    for (size_t i = 0; i < rows; i++) {
      for (size_t j = 0; j < cols; j++) {
        values[i][j] -= other.values[i][j];
      }
    }
    return *this;
  }
};

#endif