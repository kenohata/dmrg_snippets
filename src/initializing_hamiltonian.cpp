#include <iostream>
#include <Eigen/Core>
#include <Eigen/Eigenvalues>
#define SYSTEM_BODY_N  2
#define SYSTEM_STATE_N 4

bool isNthSpinUp(int state, int n);
bool isNthSpinDown(int state, int n);
float nthSpinZOperator(int state, int n);
int replaceUpDownToDownUp(int state, int n);
int replaceDownUpToUpDown(int state, int n);

int main(){
  Eigen::MatrixXd hamiltonian = Eigen::MatrixXd::Zero(SYSTEM_STATE_N, SYSTEM_STATE_N);

  for (int i = 0; i < SYSTEM_STATE_N; ++i){
    for (int j = 0; j < SYSTEM_BODY_N - 1; ++j){
      hamiltonian(i, i) += nthSpinZOperator(i, j + 1) * nthSpinZOperator(i, j);

      if(isNthSpinDown(i, j + 1) && isNthSpinUp(i, j)){
        // down up
        int l = replaceDownUpToUpDown(i, j);
        hamiltonian(i, l) += 0.5;
      }else if(isNthSpinUp(i, j + 1) && isNthSpinDown(i, j)){
        // up down
        int l = replaceUpDownToDownUp(i, j);
        hamiltonian(i, l) += 0.5;
      }
    }
  }

  std::cout << hamiltonian << std::endl;

  return 0;
}

bool isNthSpinUp(int state, int n){
  return (state >> n & 1) == 1;
}

bool isNthSpinDown(int state, int n){
  return (state >> n & 1) == 0;
}

float nthSpinZOperator(int state, int n){
  if(isNthSpinUp(state, n)){
    return 0.5;
  }else{
    return - 0.5;
  }
}

int replaceUpDownToDownUp(int state, int n){
  return state - (1 << (n + 1)) + (1 << n);
}

int replaceDownUpToUpDown(int state, int n){
  return state + (1 << (n + 1)) - (1 << n);
}
