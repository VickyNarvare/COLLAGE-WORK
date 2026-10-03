// PSEUDOCODE: SINGLY LINKED LIST
//
// Create a node:
//     Store the value in data.
//     Set next to NULL.
//
// Insert at beginning:
//     Create a new node.
//     Connect it to the current head.
//     Make the new node the head.
//
// Insert at end:
//     Create a new node.
//     If the list is empty, make it head.
//     Otherwise, move to the last node.
//     Connect the new node after the last node.
//
// Delete from beginning:
//     If the list is empty, show an empty message.
//     Otherwise, move head to the next node.
//     Delete the old head node.
//
// Delete from end:
//     If the list is empty, show an empty message.
//     If there is one node, delete it and set head to NULL.
//     Otherwise, move to the second-last node.
//     Delete the last node and set next to NULL.
//
// Display:
//     Start from head.
//     Print every node and move using next.
//     Stop when the node is NULL.
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
  NODE *next;

  NODE(int value)
  {
    data = value;
    next = NULL;
  }
};

NODE *head = NULL;

void insertAtBeginning(int value)
{
  NODE *newNode = new NODE(value);
  newNode->next = head;
  head = newNode;
  cout << value << " inserted at beginning\n";
}

void insertAtEnd(int value)
{
  NODE *newNode = new NODE(value);

  if (head == NULL)
  {
    head = newNode;
  }
  else
  {
    NODE *temp = head;
    while (temp->next != NULL)
    {
      temp = temp->next;
    }
    temp->next = newNode;
  }

  cout << value << " inserted at end\n";
}

void deleteFromBeginning()
{
  if (head == NULL)
  {
    cout << "List is empty\n";
    return;
  }

  NODE *temp = head;
  head = head->next;
  cout << temp->data << " deleted from beginning\n";
  delete temp;
}

void deleteFromEnd()
{
  if (head == NULL)
  {
    cout << "List is empty\n";
    return;
  }

  if (head->next == NULL)
  {
    cout << head->data << " deleted from end\n";
    delete head;
    head = NULL;
    return;
  }

  NODE *temp = head;
  while (temp->next->next != NULL)
  {
    temp = temp->next;
  }

  cout << temp->next->data << " deleted from end\n";
  delete temp->next;
  temp->next = NULL;
}

void display()
{
  if (head == NULL)
  {
    cout << "List is empty\n";
    return;
  }

  NODE *temp = head;
  cout << "LinkedList: ";
  while (temp != NULL)
  {
    cout << temp->data << " -> ";
    temp = temp->next;
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
    cout << "5. Display\n";
    cout << "6. Exit\n";
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
      display();
      break;

    case 6:
      return 0;

    default:
      cout << "Invalid choice\n";
    }
  }
}
