// Swap Two numbers
#include <iostream>
using namespace std;

void swipUsingPointer(int* First_Number,
                      int* Second_Number) {  // Using dereference operator
  int temp = *First_Number;
  *First_Number = *Second_Number;
  *Second_Number = temp;
}

void swipUsingAlias(int& First_Number, int& Second_Number) {  // Using alias
  int temp = First_Number;
  First_Number = Second_Number;
  Second_Number = temp;
}

int main() {
  int First_Number, Second_Number;

  cout << "Enter First Number: ";
  cin >> First_Number;
  cout << "Enter Second Number: ";
  cin >> Second_Number;

  cout << "Before Swapping -> First Number " << First_Number
       << ", Second Number " << Second_Number << endl;

  swipUsingPointer(&First_Number, &Second_Number);
  // swipUsingAlias(First_Number, Second_Number);

  cout << "After Swapping -> First Number " << First_Number
       << ", Second Number " << Second_Number << endl;

  return 0;
}
