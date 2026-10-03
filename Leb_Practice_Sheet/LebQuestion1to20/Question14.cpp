// GCD & HCF
#include <iostream>
using namespace std;

int main() {
  int a, b;
  cout << "Enter two numbers: ";
  cin >> a >> b;

  int x = a, y = b;

  while (y != 0) {
    int temp = x % y;
    x = y;
    y = temp;
  }

  cout << "GCD/HCF of " << a << " and " << b << " is: " << x << endl;
  return 0;
}
