#ifndef MATRIX_TOOLKIT_MATRIX_HPP
#define MATRIX_TOOLKIT_MATRIX_HPP

#include <iostream>
#include <vector>

template <typename T>
class Matrix {
 private:
  std::vector<std::vector<T>> matrix;
  size_t rows, cols;

 public:
  Matrix(size_t rows, size_t cols, const std::vector<std::vector<T>>& matrix)
      : rows(rows), cols(cols), matrix(matrix) {}
  Matrix(size_t rows, size_t cols) : rows(rows), cols(cols) {
    matrix.resize(rows);
    for (auto& row : matrix) {
      row.assign(cols, 0);
    }
  }

  void printArray() const {
    for (const auto& row : matrix) {
      for (const auto& val : row) {
        std::cout << val << " ";
      }
      std::cout << '\n';
    }
  }
};

#endif