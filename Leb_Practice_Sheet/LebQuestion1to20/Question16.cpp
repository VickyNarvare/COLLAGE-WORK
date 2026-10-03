#include <iostream>
using namespace std;

int main() {
  int r, c;

  cout << "Enter rows and columns: ";
  cin >> r >> c;

  int matrix[r][c];

  cout << "Enter matrix elements:\n";
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      cin >> matrix[i][j];
    }
  }

  cout << "Transpose:\n";
  for (int j = 0; j < c; j++) {
    for (int i = 0; i < r; i++) {
      cout << matrix[i][j] << " ";
    }
    cout << endl;
  }

  return 0;
}
