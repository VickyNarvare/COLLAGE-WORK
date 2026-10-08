// BEGIN
//     set size ← 50
//     declare stack[size]
//     set top ← -1
//
//     procedure evaluate(postfix)
//         for i ← 0 to length(postfix) - 1
//             ch ← postfix[i]
//
//             if ch is digit then
//                 push(ch - '0')
//
//             else                           // operator
//                 b ← pop()
//                 a ← pop()
//
//                 if ch = '+' then push(a + b)
//                 if ch = '-' then push(a - b)
//                 if ch = '*' then push(a * b)
//                 if ch = '/' then push(a / b)
//                 if ch = '^' then push(a ^ b)
//             end if
//         end for
//
//         return pop()                       // final result
//     end procedure
// end
#include <iostream>
using namespace std;

int stack[50];
int top = -1;

void push(int v) { stack[++top] = v; }
int pop() { return stack[top--]; }

int power(int a, int b)
{
  int r = 1;
  for (int i = 0; i < b; i++)
    r *= a;
  return r;
}

int main()
{
  char postfix[50];

  cout << "enter postfix expression: ";
  cin >> postfix;

  for (int i = 0; postfix[i] != '\0'; i++)
  {
    char ch = postfix[i];

    if (ch >= '0' && ch <= '9')
      push(ch - '0');
    else
    {
      int b = pop();
      int a = pop();

      if (ch == '+')
        push(a + b);
      else if (ch == '-')
        push(a - b);
      else if (ch == '*')
        push(a * b);
      else if (ch == '/')
        push(a / b);
      else if (ch == '^')
        push(power(a, b));
    }
  }

  cout << "result: " << pop() << "\n";
  return 0;
}

// ===================== output =====================
// enter postfix expression: 234*+
// result: 14
//
// enter postfix expression: 23+4*
// result: 20
//
// enter postfix expression: 82/3-
// result: 1
