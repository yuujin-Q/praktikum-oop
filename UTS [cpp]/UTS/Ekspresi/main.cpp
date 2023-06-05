#include <iostream>
#include "Calculator.hpp"
using namespace std;

int main() {
  string token;
  cin >> token;

  Calculator cc;
  cout << "HASIL=" << cc.Evaluate(token) << endl;
  return 0;
}