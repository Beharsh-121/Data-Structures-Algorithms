//Using Lambda Expression
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void print(vector<int> &vec){
  for(auto &num: vec) cout << num << " ";
}

int main(){
  vector<int> vec = {1, 2, 4, 3, 5, 9, 7, 6};

  auto myLambda = [](int a, int b){
    return a > b;
  };
  
  sort(vec.begin(), vec.end(), myLambda);
  print(vec);

  return 0;
}