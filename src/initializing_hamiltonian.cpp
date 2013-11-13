#include <iostream>
#include <Eigen/Core>
#include <Eigen/Eigenvalues>
#define BODY_N   4
#define STATE_N 16

typedef Eigen::Matrix<float, STATE_N, STATE_N> Matrix;

bool isNthSpinUp(int state, int n){
  return (state >> n & 1) == 1;
}

bool isNthSpinDown(int state, int n){
  return (state >> n & 1) == 0;
}

int replaceUpDownToDownUp(int state, int n){
  return state - (0b1 << (n + 1)) + (0b1 << n);
}

int replaceDownUpToUpDown(int state, int n){
  return state + (0b1 << (n + 1)) - (0b1 << n);
}

int main(){
  Matrix hamiltonian = Matrix::Zero();

  // Each matrix rows
  for (int i = 0; i < STATE_N; ++i){
    // Each body
    for (int j = 0; j < BODY_N - 1; ++j){
      if (isNthSpinDown(i, j + 1) && isNthSpinDown(i, j)){
        // down down
        hamiltonian(i, i) += 0.25;
      }else if(isNthSpinDown(i, j + 1) && isNthSpinUp(i, j)){
        // down up
        int l = replaceDownUpToUpDown(i, j);
        hamiltonian(i, l) += 0.5;
        hamiltonian(i, i) -= 0.25;
      }else if(isNthSpinUp(i, j + 1) && isNthSpinDown(i, j)){
        // up down
        int l = replaceUpDownToDownUp(i, j);
        hamiltonian(i, l) += 0.5;
        hamiltonian(i, i) -= 0.25;
      }else if(isNthSpinUp(i, j + 1) && isNthSpinUp(i, j)){
        // up up
        hamiltonian(i, i) += 0.25;
      }
    }
  }

  std::cout << hamiltonian << std::endl;

  return 0;
}
