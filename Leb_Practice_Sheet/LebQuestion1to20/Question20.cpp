#include <iostream>
#include <string>
using namespace std;

struct Student {
  int rollNo;
  string name;
  float percentage;
};

int main() {
  Student s[10];

  for (int i = 0; i < 10; i++) {
    cout << "\nEnter details of student " << i + 1 << ":\n";

    cout << "Roll No: ";
    cin >> s[i].rollNo;

    cout << "Name: ";
    cin >> s[i].name;

    cout << "Percentage: ";
    cin >> s[i].percentage;
  }

  cout << "\n--- Student Information ---\n";

  for (int i = 0; i < 10; i++) {
    cout << "\nRoll No: " << s[i].rollNo;
    cout << "\nName: " << s[i].name;
    cout << "\nPercentage: " << s[i].percentage << "%\n";
  }

  return 0;
}
