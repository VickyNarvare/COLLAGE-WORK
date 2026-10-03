// Check Palindrome Number
#include <iostream>
using namespace std;
int main() {
  int number;
  int reverse = 0;
  cout << "Enter a Number: ";
  cin >> number;
  int previousNumber = number;
  while (number != 0) {
    int digit = number % 10;
    reverse = reverse * 10 + digit;
    number = number / 10;
  }
  if (reverse == previousNumber) {
    cout << "Number is Palindrome";
  } else {
    cout << "Number is not Palindrome";
  }
}
