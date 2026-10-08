// BEGIN
//     set size ← 50
//     declare stack[size]
//     set top ← -1
//
//     // precedence of operators
//     procedure precedence(op)
//         if op = '^' then return 3
//         if op = '*' or op = '/' then return 2
//         if op = '+' or op = '-' then return 1
//         return 0
//     end procedure
//
//     // convert infix to postfix
//     procedure convert(infix)
//         set j ← 0
//
//         for i ← 0 to length(infix) - 1
//             ch ← infix[i]
//
//             if ch is operand (letter or digit) then
//                 postfix[j] ← ch
//                 j ← j + 1
//
//             else if ch = '(' then
//                 push(ch)
//
//             else if ch = ')' then
//                 while top ≠ -1 and stack[top] ≠ '('
//                     postfix[j] ← pop()
//                     j ← j + 1
//                 end while
//                 pop()                      // remove '('
//
//             else                           // operator
//                 while top ≠ -1 and precedence(stack[top]) ≥ precedence(ch)
//                     postfix[j] ← pop()
//                     j ← j + 1
//                 end while
//                 push(ch)
//             end if
//         end for
//
//         while top ≠ -1
//             postfix[j] ← pop()
//             j ← j + 1
//         end while
//
//         postfix[j] ← '\0'
//     end procedure
// end
#include <iostream>
using namespace std;

char stack[50];
int top = -1;

void push(char c) { stack[++top] = c; }
char pop() { return stack[top--]; }

int precedence(char op)
{
  if (op == '^')
    return 3;
  if (op == '*' || op == '/')
    return 2;
  if (op == '+' || op == '-')
    return 1;
  return 0;
}

int main()
{
  char infix[50], postfix[50];
  int j = 0;

  cout << "enter infix expression: ";
  cin >> infix;

  for (int i = 0; infix[i] != '\0'; i++)
  {
    char ch = infix[i];

    if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9'))
      postfix[j++] = ch;
    else if (ch == '(')
      push(ch);
    else if (ch == ')')
    {
      while (top != -1 && stack[top] != '(')
        postfix[j++] = pop();
      pop();
    }
    else
    {
      // '^' is right-associative, so it only pops strictly higher precedence
      while (top != -1 && (precedence(stack[top]) > precedence(ch) ||
                           (precedence(stack[top]) == precedence(ch) && ch != '^')))
        postfix[j++] = pop();
      push(ch);
    }
  }

  while (top != -1)
    postfix[j++] = pop();
  postfix[j] = '\0';

  cout << "postfix: " << postfix << "\n";
  return 0;
}

// ===================== output =====================
// enter infix expression: A+B*C
// postfix: ABC*+
//
// enter infix expression: (A+B)*C-D/E
// postfix: AB+C*DE/-
//
// enter infix expression: A^B^C
// postfix: ABC^^
