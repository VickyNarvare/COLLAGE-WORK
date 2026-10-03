// PSEUDOCODE: DOUBLY LINKED LIST
//
// Create a node:
//     Store the value in data.
//     Set previous and next to NULL.
//
// Insert at beginning:
//     Create a new node.
//     If the list is empty, make it head and tail.
//     Otherwise, connect it before head and update head.
//
// Insert at end:
//     Create a new node.
//     If the list is empty, make it head and tail.
//     Otherwise, connect it after tail and update tail.
//
// Delete from beginning:
//     If the list is empty, show an empty message.
//     Otherwise, move head to the next node.
//     Set the new head previous pointer to NULL.
//     Delete the old head node.
//
// Delete from end:
//     If the list is empty, show an empty message.
//     Otherwise, move tail to the previous node.
//     Set the new tail next pointer to NULL.
//     Delete the old tail node.
//
// Display forward:
//     Start from head and move using next.
//     Print every node until NULL.
//
// Display backward:
//     Start from tail and move using previous.
//     Print every node until NULL.
//
// Main:
//     Show the menu repeatedly.
//     Run the operation selected by the user.
//     Stop when the user selects Exit.

#include <iostream>
using namespace std;

class NODE
{
public:
  int data;
  NODE *previous;
  NODE *next;
  NODE(int value)
  {
    data = value;
    previous = NULL;
    next = NULL;
  }
};

NODE *head = NULL;
NODE *tail = NULL;

// Insert a node at the beginning of the list.
void insertAtBeginning(int value)
{
  NODE *newNode = new NODE(value);

  if (head == NULL)
  {
    head = newNode;
    tail = newNode;
  }
  else
  {
    newNode->next = head;
    head->previous = newNode;
    head = newNode;
  }
}

// Insert a node at the end of the list.
void insertAtEnd(int value)
{
  NODE *newNode = new NODE(value);

  if (tail == NULL)
  {
    head = newNode;
    tail = newNode;
  }
  else
  {
    newNode->previous = tail;
    tail->next = newNode;
    tail = newNode;
  }
}

// Delete the first node of the list.
void deleteFromBeginning()
{
  if (head == NULL)
  {
    cout << "List is empty\n";
    return;
  }

  NODE *temp = head;

  if (head == tail)
  {
    head = NULL;
    tail = NULL;
  }
  else
  {
    head = head->next;
    head->previous = NULL;
  }

  delete temp;
}

// Delete the last node of the list.
void deleteFromEnd()
{
  if (tail == NULL)
  {
    cout << "List is empty\n";
    return;
  }
  NODE *temp = tail;
  if (head == tail)
  {
    head = NULL;
    tail = NULL;
  }
  else
  {
    tail = tail->previous;
    tail->next = NULL;
  }
  delete temp;
}

// Display the list from head to tail.
void displayForward()
{
  if (head == NULL)
  {
    cout << "List is empty\n";
    return;
  }
  NODE *temp = head;
  cout << "Forward: ";
  while (temp != NULL)
  {
    cout << temp->data << " <-> ";
    temp = temp->next;
  }
  cout << "NULL\n";
}

// Display the list from tail to head.
void displayBackward()
{
  if (tail == NULL)
  {
    cout << "List is empty\n";
    return;
  }
  NODE *temp = tail;
  cout << "Backward: ";
  while (temp != NULL)
  {
    cout << temp->data << " <-> ";
    temp = temp->previous;
  }
  cout << "NULL\n";
}
int main()
{
  int choice, value;
  while (true)
  {
    cout << "\n1. Insert at beginning\n";
    cout << "2. Insert at end\n";
    cout << "3. Delete from beginning\n";
    cout << "4. Delete from end\n";
    cout << "5. Display forward\n";
    cout << "6. Display backward\n";
    cout << "7. Exit\n";
    cout << "Enter choice: ";
    cin >> choice;
    switch (choice)
    {
    case 1:
      cout << "Enter value: ";
      cin >> value;
      insertAtBeginning(value);
      break;

    case 2:
      cout << "Enter value: ";
      cin >> value;
      insertAtEnd(value);
      break;

    case 3:
      deleteFromBeginning();
      break;

    case 4:
      deleteFromEnd();
      break;

    case 5:
      displayForward();
      break;

    case 6:
      displayBackward();
      break;

    case 7:
      while (head != NULL)
      {
        NODE *temp = head;
        head = head->next;
        delete temp;
      }
      return 0;

    default:
      cout << "Invalid choice\n";
    }
  }
}
