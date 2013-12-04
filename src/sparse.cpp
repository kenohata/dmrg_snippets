#include <iostream>
#include <Eigen/Core>
#include <Eigen/Sparse>
#define N 4

int main(){
  Eigen::SparseMatrix<double> m(N, N);

  m.insert(0, 0) = 1;
  m.insert(1, 1) = 1;
  m.insert(2, 2) = 1;
  m.insert(3, 3) = 1;

  std::cout << m << std::endl;
  return 0;
}
