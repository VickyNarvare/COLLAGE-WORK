// BEGIN
//     define node
//         row
//         col
//         val
//         next
//     end define
//
//     // insert at end of list (only non-zero values)
//     procedure insert(head, r, c, v)
//         create newNode (r, c, v, null)
//         if head = null then
//             head ← newNode
//         else
//             temp ← head
//             while temp.next ≠ null
//                 temp ← temp.next
//             temp.next ← newNode
//         return head
//     end procedure
//
//     // create from normal matrix
//     procedure create()
//         read rows, cols
//         head ← null
//         for i ← 0 to rows-1
//             for j ← 0 to cols-1
//                 read v
//                 if v ≠ 0 then
//                     head ← insert(head, i, j, v)
//         return head
//     end procedure
//
//     // transpose
//     procedure transpose(a, cols)
//         result ← null
//         for c ← 0 to cols-1
//             temp ← a
//             while temp ≠ null
//                 if temp.col = c then
//                     result ← insert(result, c, temp.row, temp.val)
//                 temp ← temp.next
//         return result
//     end procedure
//
//     // add (both lists sorted by row, then col)
//     procedure add(a, b)
//         result ← null
//         while a ≠ null and b ≠ null
//             if a.row = b.row and a.col = b.col then
//                 sum ← a.val + b.val
//                 if sum ≠ 0 then
//                     result ← insert(result, a.row, a.col, sum)
//                 a ← a.next
//                 b ← b.next
//             else if a.row < b.row or (a.row = b.row and a.col < b.col) then
//                 result ← insert(result, a.row, a.col, a.val)
//                 a ← a.next
//             else
//                 result ← insert(result, b.row, b.col, b.val)
//                 b ← b.next
//         copy remaining nodes of a
//         copy remaining nodes of b
//         return result
//     end procedure
//
//     // display
//     procedure display(head)
//         temp ← head
//         while temp ≠ null
//             print temp.row, temp.col, temp.val
//             temp ← temp.next
//     end procedure
// end
#include <iostream>
using namespace std;

struct Node
{
  int row, col, val;
  Node *next;
};

Node *insert(Node *head, int r, int c, int v)
{
  Node *n = new Node;
  n->row = r;
  n->col = c;
  n->val = v;
  n->next = NULL;

  if (head == NULL)
    return n;

  Node *temp = head;
  while (temp->next != NULL)
    temp = temp->next;
  temp->next = n;
  return head;
}

Node *create(int &rows, int &cols)
{
  Node *head = NULL;
  int v;
  cout << "enter rows and cols: ";
  cin >> rows >> cols;
  cout << "enter matrix:\n";
  for (int i = 0; i < rows; i++)
    for (int j = 0; j < cols; j++)
    {
      cin >> v;
      if (v != 0)
        head = insert(head, i, j, v);
    }
  return head;
}

Node *transpose(Node *a, int cols)
{
  Node *result = NULL;
  for (int c = 0; c < cols; c++)
    for (Node *t = a; t != NULL; t = t->next)
      if (t->col == c)
        result = insert(result, c, t->row, t->val);
  return result;
}

Node *add(Node *a, Node *b)
{
  Node *result = NULL;
  while (a != NULL && b != NULL)
  {
    if (a->row == b->row && a->col == b->col)
    {
      int sum = a->val + b->val;
      if (sum != 0)
        result = insert(result, a->row, a->col, sum);
      a = a->next;
      b = b->next;
    }
    else if (a->row < b->row || (a->row == b->row && a->col < b->col))
    {
      result = insert(result, a->row, a->col, a->val);
      a = a->next;
    }
    else
    {
      result = insert(result, b->row, b->col, b->val);
      b = b->next;
    }
  }
  for (; a != NULL; a = a->next)
    result = insert(result, a->row, a->col, a->val);
  for (; b != NULL; b = b->next)
    result = insert(result, b->row, b->col, b->val);
  return result;
}

void display(Node *head)
{
  if (head == NULL)
  {
    cout << "empty\n";
    return;
  }
  for (Node *t = head; t != NULL; t = t->next)
    cout << t->row << " " << t->col << " " << t->val << "\n";
}

int main()
{
  int r1, c1, r2, c2;
  cout << "Matrix A\n";
  Node *a = create(r1, c1);
  cout << "Matrix B\n";
  Node *b = create(r2, c2);

  cout << "A:\n";
  display(a);
  cout << "transpose of A:\n";
  display(transpose(a, c1));
  cout << "A + B:\n";
  display(add(a, b));
  return 0;
}

// ===================== output =====================
// Matrix A
// enter rows and cols: 3 3
// enter matrix:
// 5 0 0
// 0 0 3
// 0 2 0
// Matrix B
// enter rows and cols: 3 3
// enter matrix:
// 1 0 0
// 0 0 -3
// 0 0 6
// A:
// 0 0 5
// 1 2 3
// 2 1 2
// transpose of A:
// 0 0 5
// 1 2 2
// 2 1 3
// A + B:
// 0 0 6
// 2 1 2
// 2 2 6
