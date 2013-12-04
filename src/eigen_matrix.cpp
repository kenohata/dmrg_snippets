#include <iostream>
#include <Eigen/Core>
#include <Eigen/Eigenvalues>
#define N 8

int main(){
  Eigen::Matrix<double, N, N> m;

  for(int i = 0; i < N; ++i){
    for(int j = 0; j < N; ++j){
      if(i == j){
        m(i, j) = 2;
      }else{
        m(i, j) = 1;
      }
    }
  }

  Eigen::EigenSolver< Eigen::Matrix<double, N, N> > es(m);
  Eigen::MatrixXcd d = es.eigenvalues().asDiagonal();
  Eigen::MatrixXcd a = es.eigenvectors();
  Eigen::VectorXcd v = es.eigenvalues();

  return 0;
}
