// Step 1: Initialize Stack
// Create an array STACK[SIZE].
// Set TOP ← -1.

// Step 2: PUSH Operation
// Check if TOP = SIZE - 1.
// If yes, display "Stack Overflow" and stop the operation.
// Otherwise, set TOP ← TOP + 1.
// Read the value ITEM.
// Set STACK[TOP] ← ITEM.
// Stop the PUSH operation.

// Step 3: POP Operation
// Check if TOP = -1.
// If yes, display "Stack Underflow" and stop the operation.
// Otherwise, set ITEM ← STACK[TOP].
// Display/remove ITEM.
// Set TOP ← TOP - 1.
// Stop the POP operation.

// Step 4: DISPLAY Operation
// Check if TOP = -1.
// If yes, display "Stack is Empty" and stop.
// Otherwise, set I ← TOP.
// Repeat while I ≥ 0:
// Display STACK[I].
// Set I ← I - 1.
// Stop the DISPLAY operation.
#include <iostream>
using namespace std;

#define SIZE 5

int stack[SIZE];
int top = -1;

void push(int value)
{
  if (top == SIZE - 1)
  {
    cout << "Stack Overflow\n";
    return;
  }
  top++;
  stack[top] = value;
  cout << value << " pushed into stack\n";
}

void pop()
{
  if (top == -1)
  {
    cout << "Stack Underflow\n";
    return;
  }
  cout << stack[top] << " popped from stack\n";
  top--;
}

void display()
{
  if (top == -1)
  {
    cout << "Stack is empty\n";
    return;
  }
  cout << "Stack: ";
  for (int i = top; i >= 0; i--)
  {
    cout << stack[i] << " ";
  }
  cout << endl;
}

int main()
{
  int choice, value;

  while (true)
  {
    cout << "\n1. Push\n";
    cout << "2. Pop\n";
    cout << "3. Display\n";
    cout << "4. Exit\n";
    cout << "Enter choice: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
      cout << "Enter value: ";
      cin >> value;
      push(value);
      break;

    case 2:
      pop();
      break;

    case 3:
      display();
      break;

    case 4:
      return 0;

    default:
      cout << "Invalid choice\n";
    }
  }
}
