// x to the power y
#include <iostream>
using namespace std;
int main() {
  int number, power;
  cout << "Enter a Number: ";
  cin >> number;
  cout << "Enter a power: ";
  cin >> power;
  int Answer = 1;
  for (int i = 0; i < power; i++) {
    Answer *= number;
  }
  cout << Answer;
}
