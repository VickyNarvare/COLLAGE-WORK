//     // ---------- array implementation ----------
//     set size ← 5
//     declare stack[size]
//     set arrTop ← -1
//
//     procedure arrPush(item)
//         if arrTop = size - 1 then
//             print "stack overflow"
//             return
//         end if
//         arrTop ← arrTop + 1
//         stack[arrTop] ← item
//     end procedure
//
//     procedure arrPop()
//         if arrTop = -1 then
//             print "stack underflow"
//             return
//         end if
//         print "popped:", stack[arrTop]
//         arrTop ← arrTop - 1
//     end procedure
//
//     procedure arrDisplay()
//         if arrTop = -1 then
//             print "stack is empty"
//             return
//         end if
//         i ← arrTop
//         while i ≥ 0
//             print stack[i]
//             i ← i - 1
//         end while
//     end procedure
//
//     // ---------- linked list implementation ----------
//     structure Node
//         data
//         next
//     end structure
//     set llTop ← NULL
//
//     procedure llPush(item)
//         create newNode
//         if newNode = NULL then
//             print "stack overflow (heap full)"
//             return
//         end if
//         newNode.data ← item
//         newNode.next ← llTop
//         llTop ← newNode
//     end procedure
//
//     procedure llPop()
//         if llTop = NULL then
//             print "stack underflow"
//             return
//         end if
//         temp ← llTop
//         print "popped:", temp.data
//         llTop ← llTop.next
//         delete temp
//     end procedure
//
//     procedure llDisplay()
//         if llTop = NULL then
//             print "stack is empty"
//             return
//         end if
//         current ← llTop
//         while current ≠ NULL
//             print current.data
//             current ← current.next
//         end while
//     end procedure
#include <iostream>
#include <new>
using namespace std;

// ---------- array implementation ----------
#define SIZE 5

int stackArr[SIZE];
int arrTop = -1;

void arrPush(int value)
{
  if (arrTop == SIZE - 1)
  {
    cout << "stack overflow\n";
    return;
  }
  arrTop++;
  stackArr[arrTop] = value;
  cout << value << " pushed into stack\n";
}

void arrPop()
{
  if (arrTop == -1)
  {
    cout << "stack underflow\n";
    return;
  }
  cout << stackArr[arrTop] << " popped from stack\n";
  arrTop--;
}

void arrDisplay()
{
  if (arrTop == -1)
  {
    cout << "stack is empty\n";
    return;
  }
  cout << "stack: ";
  for (int i = arrTop; i >= 0; i--)
  {
    cout << stackArr[i] << " ";
  }
  cout << endl;
}

// ---------- linked list implementation ----------
struct Node
{
  int data;
  Node *next;
};

Node *llTop = NULL;

void llPush(int value)
{
  Node *newNode = new (nothrow) Node;
  if (newNode == NULL)
  {
    cout << "stack overflow (heap full)\n";
    return;
  }
  newNode->data = value;
  newNode->next = llTop;
  llTop = newNode;
  cout << value << " pushed into stack\n";
}

void llPop()
{
  if (llTop == NULL)
  {
    cout << "stack underflow\n";
    return;
  }
  Node *temp = llTop;
  cout << temp->data << " popped from stack\n";
  llTop = llTop->next;
  delete temp;
}

void llDisplay()
{
  if (llTop == NULL)
  {
    cout << "stack is empty\n";
    return;
  }
  cout << "stack: ";
  Node *current = llTop;
  while (current != NULL)
  {
    cout << current->data << " ";
    current = current->next;
  }
  cout << endl;
}

void llClear()
{
  while (llTop != NULL)
  {
    Node *temp = llTop;
    llTop = llTop->next;
    delete temp;
  }
}

// ---------- operation menu (shared by both) ----------
void stackMenu(bool useArray)
{
  int choice, value;

  while (true)
  {
    cout << "\n--- " << (useArray ? "array" : "linked list") << " stack ---\n";
    cout << "1. push\n";
    cout << "2. pop\n";
    cout << "3. display\n";
    cout << "4. back\n";
    cout << "enter choice: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
      cout << "enter value: ";
      cin >> value;
      if (useArray)
        arrPush(value);
      else
        llPush(value);
      break;

    case 2:
      if (useArray)
        arrPop();
      else
        llPop();
      break;

    case 3:
      if (useArray)
        arrDisplay();
      else
        llDisplay();
      break;

    case 4:
      return;

    default:
      cout << "invalid choice\n";
    }
  }
}

int main()
{
  int impl;

  while (true)
  {
    cout << "\nchoose implementation\n";
    cout << "1. array\n";
    cout << "2. linked list\n";
    cout << "3. exit\n";
    cout << "enter choice: ";
    cin >> impl;

    switch (impl)
    {
    case 1:
      stackMenu(true);
      break;

    case 2:
      stackMenu(false);
      break;

    case 3:
      llClear();
      return 0;

    default:
      cout << "invalid choice\n";
    }
  }
}

// ===================== sample output =====================
//
// choose implementation
// 1. array
// 2. linked list
// 3. exit
// enter choice: 1
//
// --- array stack ---
// 1. push
// 2. pop
// 3. display
// 4. back

// enter choice: 1
// enter value: 10
// 10 pushed into stack
//
//
// [menu]
// enter choice: 3
// stack: 10
//
// [menu]
// enter choice: 2
// 10 popped from stack

// choose implementation
// 1. array
// 2. linked list
// 3. exit
// enter choice: 2
//
// --- linked list stack ---
// 1. push
// 2. pop
// 3. display
// 4. back
// enter choice: 3
// stack is empty                  <-- separate stack, starts empty
//
// [menu]
// enter choice: 1
// enter value: 100
// 100 pushed into stack
//
// [menu]
// enter choice: 1
// enter value: 200
// 200 pushed into stack
//
// [menu]
// enter choice: 3
// stack: 200 100
