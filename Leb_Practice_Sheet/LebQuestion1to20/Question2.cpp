// Factorial
#include <iostream>
using namespace std;
int main() {
  int number;
  int factorial = 1;
  cout << "Enter Number : ";
  cin >> number;
  for (int i = 1; i <= number; i++) {
    factorial = factorial * i;
  }
  cout << "Factorial is " << factorial;
}

// Improve or ho sakta hai or karna hai...
