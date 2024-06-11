//Using function objects
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct myComparator { //can use class here as well with uncommenting public access specifier
  // public: 
    bool operator () (int a, int b) {
        return a > b;
    }
};


void print(vector<int> &vec){
  for(auto &num: vec) cout << num << " ";
}

int main(){
  vector<int> vec = {1, 2, 4, 3, 5, 9, 7, 6};

  sort(vec.begin(), vec.end(), myComparator());
  print(vec);

  return 0;
}