#include "matrix.hpp"

int main() {
  Matrix<int> m(2, 2, 1);

  Matrix<int> n(2, 2, 5);

  auto result = Matrix<int>::multiplication(m, n);

  std::cout << m.toString() << " X " << std::endl
            << n.toString() << " = " << std::endl
            << result.toString();

  return 0;
}