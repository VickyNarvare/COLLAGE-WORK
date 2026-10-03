// Pattern
// 1
// 1 2
// 1 2 3
// 1 2 3 4
// 1 2 3 4 5

#include <iostream>
using namespace std;
int main() {
  int number;
  cout << "Enter A Number : ";
  cin >> number;
  for (int i = 1; i <= number; i++) {
    for (int j = 1; j <= i; j++) {
      cout << j << " ";
    }
    cout << endl;
  }
}
