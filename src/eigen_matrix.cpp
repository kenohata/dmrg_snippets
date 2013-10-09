#include <iostream>
#include <Eigen/Core>
#define N 8

int main(){
  Eigen::Matrix<int, N, N> m;

  for(int i = 0; i < N; ++i){
    for(int j = 0; j < N; ++j){
      if(i == j){
        m(i, j) = 2;
      }else{
        m(i, j) = 1;
      }
    }
  }

  std::cout << m << std::endl;

  return 0;
}
