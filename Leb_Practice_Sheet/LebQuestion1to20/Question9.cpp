// greatest
#include <iostream>
using namespace std;
int main() {
  int firstNumber, secondNumber, thridNumber;
  cout << "Enter First Number";
  cin >> firstNumber;
  cout << "Enter First Number";
  cin >> secondNumber;
  cout << "Enter First Number";
  cin >> thridNumber;
  if (firstNumber > secondNumber || firstNumber > thridNumber) {
    cout << "first Number is grater";
  } else if (secondNumber > thridNumber) {
    cout << "second Number is grater";
  } else {
    cout << "thrid Number is grater";
  }
}
