//  sum of all the elements of an array.
#include <iostream>
using namespace std;
int main() {
  int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int sum = 0;
  for (int x : arr) {
    sum += x;
  }
  cout << sum;
}
