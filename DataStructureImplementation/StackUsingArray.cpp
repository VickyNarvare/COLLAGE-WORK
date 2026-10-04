//     // initialize stack
//     set size ← 10
//     declare stack[size]
//     set top ← -1

//     // push operation
//     procedure push(item)

//         if top = size - 1 then
//             print "stack overflow"
//             return
//         end if

//         top ← top + 1
//         stack[top] ← item

//     end procedure

//     // pop operation
//     procedure pop()

//         if top = -1 then
//             print "stack underflow"
//             return
//         end if

//         item ← stack[top]
//         top ← top - 1

//         print "deleted item:", item

//     end procedure

//     // display operation
//     procedure display()

//         if top = -1 then
//             print "stack is empty"
//             return
//         end if

//         i ← top

//         while i ≥ 0
//             print stack[i]
//             i ← i - 1
//         end while

//     end procedure

// end
#include <iostream>
using namespace std;

#define SIZE 5

int stack[SIZE];
int top = -1;

void push(int value)
{
  if (top == SIZE - 1)
  {
    cout << "stack overflow\n";
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
    cout << "stack underflow\n";
    return;
  }
  cout << stack[top] << " popped from stack\n";
  top--;
}

void display()
{
  if (top == -1)
  {
    cout << "stack is empty\n";
    return;
  }
  cout << "stack: ";
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
    cout << "\n1. push\n";
    cout << "2. pop\n";
    cout << "3. display\n";
    cout << "4. exit\n";
    cout << "enter choice: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
      cout << "enter value: ";
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
      cout << "invalid choice\n";
    }
  }
}
