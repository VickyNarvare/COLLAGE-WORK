// Reverse The Number
#include <iostream>
using namespace std;
int main() {
  int number;
  int reverse = 0;
  cout << "Enter the number: ";  // 12345
  cin >> number;
  while (number != 0) {
    int digit = number % 10;
    reverse = reverse * 10 + digit;
    number = number / 10;
  }
  cout << "Result : " << reverse;
}
