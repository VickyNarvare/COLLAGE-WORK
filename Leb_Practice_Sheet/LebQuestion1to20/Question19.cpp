#include <iostream>
using namespace std;

int main() {
  int r, c, key;
  bool found = false;

  cout << "Enter rows and columns: ";
  cin >> r >> c;

  int matrix[r][c];

  cout << "Enter matrix elements:\n";
  for (int i = 0; i < r; i++)
    for (int j = 0; j < c; j++) cin >> matrix[i][j];

  cout << "Enter element to search: ";
  cin >> key;

  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      if (matrix[i][j] == key) {
        cout << "Element found at row " << i << ", column " << j << endl;
        found = true;
      }
    }
  }

  if (!found) cout << "Element not found.";

  return 0;
}
