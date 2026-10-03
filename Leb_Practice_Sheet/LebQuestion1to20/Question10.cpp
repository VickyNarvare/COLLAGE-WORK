// find the number in a array
#include <iostream>
using namespace std;
int main() {
  int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
  int target = 11;
  bool result = false;
  for (int x : arr) {
    if (x == target) {
      result = true;
      break;
    }
  }
  if (result) {
    cout << "True";
  } else {
    cout << "False";
  }
}
