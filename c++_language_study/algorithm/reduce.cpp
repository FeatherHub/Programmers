#include <execution>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

int main() {
  vector<int> v {1,2};

  cout <<  reduce(v.begin(), v.end()) << endl;
  cout <<  reduce(v.begin(), v.end(), 10) << endl;
  cout <<  reduce(execution::parallel_policy(), v.begin(), v.end(), 10) << endl;
  cout <<  reduce(execution::parallel_policy(), v.begin(), v.end(), 10, [](int a, int b){ 
    cout << a << " " << b << endl;
    return a+b;
  }) << endl;
  cout << "===" << endl;
  cout <<  reduce(v.begin(), v.end(), 1, [](int a, int b){ return a * b;}) << endl;
  
  const auto expo = execution::unsequenced_policy();
  const auto reduce_lambda = [](int acc, int n){
    return acc + n;
  };

  vector<int> v2 {4,5,6,7,8,9};
  cout << reduce(expo, v2.begin(), v2.end(), 0, reduce_lambda) << endl;

  return 0;
}