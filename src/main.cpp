#include "matrix.hpp"

int main() {
  Matrix<int> m(2, 2);
  m.print();
  Matrix<int> n(2, 2, 5);
  n.print();
  n = n * 5;
  n.print();
  Matrix<int> i = (n * (1.0 / 5.0));
  i.print();
  n = 5 * n;
  n.print();

  Matrix<int> o(2, 2);
  Matrix<double> p(2, 2);
  return 0;
}