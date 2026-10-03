// first 10 prime number
#include <iostream>
using namespace std;
int main() {
  int count = 0;
  int number = 2;
  while (count != 10) {
    bool isPrime = true;
    for (int i = 2; i * i <= number; i++) {
      if (number % i == 0) {
        isPrime = false;
        break;
      }
    }
    if (isPrime) {
      cout << number << endl;
      count++;
    }
    number++;
  }
}
