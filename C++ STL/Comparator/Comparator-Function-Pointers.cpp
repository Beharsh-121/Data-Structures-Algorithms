//Using function pointer
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool myComparator(pair<int,int> p1, pair<int,int> p2){
  if(p1.first == p2.first){ 
    return p1.second > p2.second;
  }
  return p1.first > p2.first;
}

void print(vector<pair<int,int>> &vec){
  for(auto &it: vec) cout << it.first << "," << it.second << ":"; 
}

int main(){
  vector<pair<int, int>> vec = {{3, 2}, {2, 5}, {2, 6}};

  sort(vec.begin(), vec.end(), myComparator);
  print(vec);

  return 0;
}