// BEGIN
//     // ---------- array implementation (linear queue) ----------
//     set size ← 5
//     declare queue[size]
//     set front ← 0, rear ← -1
//
//     procedure arrEnqueue(item)
//         if rear = size - 1 then
//             print "queue overflow"
//             return
//         end if
//         rear ← rear + 1
//         queue[rear] ← item
//     end procedure
//
//     procedure arrDequeue()
//         if front > rear then
//             print "queue underflow"
//             return
//         end if
//         print "dequeued:", queue[front]
//         front ← front + 1
//     end procedure
//
//     procedure arrDisplay()
//         if front > rear then
//             print "queue is empty"
//             return
//         end if
//         for i ← front to rear
//             print queue[i]
//         end for
//     end procedure
//
//     // ---------- linked list implementation ----------
//     define node
//         data
//         next
//     end define
//     set llFront ← NULL, llRear ← NULL
//
//     procedure llEnqueue(item)
//         create newNode (item, NULL)
//         if llRear = NULL then
//             llFront ← newNode
//             llRear ← newNode
//         else
//             llRear.next ← newNode
//             llRear ← newNode
//         end if
//     end procedure
//
//     procedure llDequeue()
//         if llFront = NULL then
//             print "queue underflow"
//             return
//         end if
//         temp ← llFront
//         print "dequeued:", temp.data
//         llFront ← llFront.next
//         if llFront = NULL then
//             llRear ← NULL
//         end if
//         delete temp
//     end procedure
//
//     procedure llDisplay()
//         if llFront = NULL then
//             print "queue is empty"
//             return
//         end if
//         temp ← llFront
//         while temp ≠ NULL
//             print temp.data
//             temp ← temp.next
//         end while
//     end procedure
//
//     // main: choose implementation, then enqueue / dequeue / display / back
// end
#include <iostream>
using namespace std;

// ---------- array implementation ----------
#define SIZE 5

int queueArr[SIZE];
int front = 0, rear = -1;

void arrEnqueue(int value)
{
  if (rear == SIZE - 1)
  {
    cout << "queue overflow\n";
    return;
  }
  queueArr[++rear] = value;
  cout << value << " enqueued\n";
}

void arrDequeue()
{
  if (front > rear)
  {
    cout << "queue underflow\n";
    return;
  }
  cout << queueArr[front++] << " dequeued\n";
}

void arrDisplay()
{
  if (front > rear)
  {
    cout << "queue is empty\n";
    return;
  }
  cout << "queue: ";
  for (int i = front; i <= rear; i++)
    cout << queueArr[i] << " ";
  cout << endl;
}

// ---------- linked list implementation ----------
struct Node
{
  int data;
  Node *next;
};

Node *llFront = NULL;
Node *llRear = NULL;

void llEnqueue(int value)
{
  Node *n = new Node;
  n->data = value;
  n->next = NULL;

  if (llRear == NULL)
    llFront = llRear = n;
  else
  {
    llRear->next = n;
    llRear = n;
  }
  cout << value << " enqueued\n";
}

void llDequeue()
{
  if (llFront == NULL)
  {
    cout << "queue underflow\n";
    return;
  }
  Node *temp = llFront;
  cout << temp->data << " dequeued\n";
  llFront = llFront->next;
  if (llFront == NULL)
    llRear = NULL;
  delete temp;
}

void llDisplay()
{
  if (llFront == NULL)
  {
    cout << "queue is empty\n";
    return;
  }
  cout << "queue: ";
  for (Node *t = llFront; t != NULL; t = t->next)
    cout << t->data << " ";
  cout << endl;
}

// ---------- shared menu ----------
void queueMenu(bool useArray)
{
  int choice, value;
  while (true)
  {
    cout << "\n1. enqueue\n2. dequeue\n3. display\n4. back\nenter choice: ";
    cin >> choice;

    if (choice == 1)
    {
      cout << "enter value: ";
      cin >> value;
      if (useArray)
        arrEnqueue(value);
      else
        llEnqueue(value);
    }
    else if (choice == 2)
    {
      if (useArray)
        arrDequeue();
      else
        llDequeue();
    }
    else if (choice == 3)
    {
      if (useArray)
        arrDisplay();
      else
        llDisplay();
    }
    else if (choice == 4)
      return;
    else
      cout << "invalid choice\n";
  }
}

int main()
{
  int impl;
  while (true)
  {
    cout << "\n1. array\n2. linked list\n3. exit\nenter choice: ";
    cin >> impl;

    if (impl == 1)
      queueMenu(true);
    else if (impl == 2)
      queueMenu(false);
    else if (impl == 3)
    {
      while (llFront != NULL)
      {
        Node *temp = llFront;
        llFront = llFront->next;
        delete temp;
      }
      return 0;
    }
    else
      cout << "invalid choice\n";
  }
}

// ===================== output =====================
// 1. array
// 2. linked list
// 3. exit
// enter choice: 1
//
// 1. enqueue  2. dequeue  3. display  4. back
// enter choice: 1
// enter value: 10
// 10 enqueued
// enter choice: 1
// enter value: 20
// 20 enqueued
// enter choice: 3
// queue: 10 20
// enter choice: 2
// 10 dequeued
// enter choice: 3
// queue: 20
// enter choice: 4
//
// enter choice: 2
// 1. enqueue  2. dequeue  3. display  4. back
// enter choice: 1
// enter value: 5
// 5 enqueued
// enter choice: 1
// enter value: 6
// 6 enqueued
// enter choice: 3
// queue: 5 6
// enter choice: 2
// 5 dequeued
// enter choice: 2
// 6 dequeued
// enter choice: 2
// queue underflow
// enter choice: 4
//
// enter choice: 3
