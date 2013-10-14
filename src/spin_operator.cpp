#include <iostream>
#include <Eigen/Core>
#include <Eigen/Eigenvalues>
#define BODY_N 1 // Bodies Number - 1
#define BODY_D 4 //= 2^(BODY_N + 1)

typedef Eigen::Matrix<float, BODY_D, BODY_D> SystemMatrix;

bool getNthSpinState(int vector, int n){
  return vector >> n & 1;
}

SystemMatrix SpinNthZOperator(int n){
  SystemMatrix s = SystemMatrix::Identity();

  for(int i = 0; i < BODY_D; ++i){
    if(getNthSpinState(i, n)){
      s(i, i) =  1;
    }else{
      s(i, i) = -1;
    }
  }

  return s;
}

SystemMatrix SpinNthUpOperator(int n){
  SystemMatrix s = SystemMatrix::Zero();

  for(int i = 0; i < BODY_D; ++i){
    if(!getNthSpinState(i, n)){
      s(i + 1 + n, i) = 1;
    }
  }

  return s;
}

SystemMatrix SpinNthDownOperator(int n){
  SystemMatrix s = SystemMatrix::Zero();

  for(int i = 0; i < BODY_D; ++i){
    if(getNthSpinState(i, n)){
      s(i - 1 - n, i) = 1;
    }
  }

  return s;
}

int main(){
  SystemMatrix H = SystemMatrix::Zero();

  for(int i = 0; i < BODY_N; ++i){
    H += SpinNthZOperator(i) * SpinNthZOperator(i + 1);
    H += ( SpinNthUpOperator(i) * SpinNthDownOperator(i + 1) +
           SpinNthDownOperator(i) * SpinNthUpOperator(i + 1) ) / 2;
  }

  std::cout << H << std::endl;

  return 0;
}
