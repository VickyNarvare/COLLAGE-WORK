//     // Node structure
//     DEFINE NODE
//         DATA
//         NEXT
//     END DEFINE

//     SET HEAD ← NULL

//     // Create a new node
//     PROCEDURE CREATE_NODE(ITEM)

//         CREATE NEW_NODE
//         NEW_NODE.DATA ← ITEM
//         NEW_NODE.NEXT ← NULL

//         RETURN NEW_NODE

//     END PROCEDURE

//     // Insert at Beginning
//     PROCEDURE INSERT_BEGINNING(ITEM)

//         NEW_NODE ← CREATE_NODE(ITEM)

//         NEW_NODE.NEXT ← HEAD
//         HEAD ← NEW_NODE

//         PRINT "Node inserted successfully"

//     END PROCEDURE

//     // Insert at End
//     PROCEDURE INSERT_END(ITEM)

//         NEW_NODE ← CREATE_NODE(ITEM)

//         IF HEAD = NULL THEN
//             HEAD ← NEW_NODE
//             PRINT "Node inserted successfully"
//             RETURN
//         END IF

//         TEMP ← HEAD

//         WHILE TEMP.NEXT ≠ NULL
//             TEMP ← TEMP.NEXT
//         END WHILE

//         TEMP.NEXT ← NEW_NODE

//         PRINT "Node inserted successfully"

//     END PROCEDURE

//     // Delete from Beginning
//     PROCEDURE DELETE_BEGINNING()

//         IF HEAD = NULL THEN
//             PRINT "List is empty"
//             RETURN
//         END IF

//         TEMP ← HEAD
//         HEAD ← HEAD.NEXT

//         DELETE TEMP

//         PRINT "Node deleted successfully"

//     END PROCEDURE

//     // Delete from End
//     PROCEDURE DELETE_END()

//         IF HEAD = NULL THEN
//             PRINT "List is empty"
//             RETURN
//         END IF

//         IF HEAD.NEXT = NULL THEN
//             DELETE HEAD
//             HEAD ← NULL
//             PRINT "Node deleted successfully"
//             RETURN
//         END IF

//         TEMP ← HEAD

//         WHILE TEMP.NEXT.NEXT ≠ NULL
//             TEMP ← TEMP.NEXT
//         END WHILE

//         DELETE TEMP.NEXT
//         TEMP.NEXT ← NULL

//         PRINT "Node deleted successfully"

//     END PROCEDURE

//     // Display Linked List
//     PROCEDURE DISPLAY()

//         IF HEAD = NULL THEN
//             PRINT "List is empty"
//             RETURN
//         END IF

//         TEMP ← HEAD

//         WHILE TEMP ≠ NULL
//             PRINT TEMP.DATA
//             TEMP ← TEMP.NEXT
//         END WHILE

//     END PROCEDURE

//     // Main Menu
//     REPEAT

//         PRINT "1. Insert at Beginning"
//         PRINT "2. Insert at End"
//         PRINT "3. Delete from Beginning"
//         PRINT "4. Delete from End"
//         PRINT "5. Display"
//         PRINT "6. Exit"

//         READ CHOICE

//         IF CHOICE = 1 THEN
//             READ ITEM
//             CALL INSERT_BEGINNING(ITEM)

//         ELSE IF CHOICE = 2 THEN
//             READ ITEM
//             CALL INSERT_END(ITEM)

//         ELSE IF CHOICE = 3 THEN
//             CALL DELETE_BEGINNING()

//         ELSE IF CHOICE = 4 THEN
//             CALL DELETE_END()

//         ELSE IF CHOICE = 5 THEN
//             CALL DISPLAY()

//         ELSE IF CHOICE = 6 THEN
//             PRINT "Program terminated"

//         ELSE
//             PRINT "Invalid choice"

//         END IF

//     UNTIL CHOICE = 6

// END
#include <iostream>
using namespace std;

class Node
{
public:
  int data;
  Node *next;

  Node(int value)
  {
    data = value;
    next = nullptr;
  }
};

Node *head = nullptr;

void insertAtBeginning(int value)
{
  Node *newNode = new Node(value);
  newNode->next = head;
  head = newNode;
  cout << value << " inserted at beginning\n";
}

void insertAtEnd(int value)
{
  Node *newNode = new Node(value);

  if (head == nullptr)
  {
    head = newNode;
  }
  else
  {
    Node *temp = head;
    while (temp->next != nullptr)
    {
      temp = temp->next;
    }
    temp->next = newNode;
  }

  cout << value << " inserted at end\n";
}

void deleteFromBeginning()
{
  if (head == nullptr)
  {
    cout << "List is empty\n";
    return;
  }

  Node *temp = head;
  head = head->next;
  cout << temp->data << " deleted from beginning\n";
  delete temp;
}

void deleteFromEnd()
{
  if (head == nullptr)
  {
    cout << "List is empty\n";
    return;
  }

  if (head->next == nullptr)
  {
    cout << head->data << " deleted from end\n";
    delete head;
    head = nullptr;
    return;
  }

  Node *temp = head;
  while (temp->next->next != nullptr)
  {
    temp = temp->next;
  }

  cout << temp->next->data << " deleted from end\n";
  delete temp->next;
  temp->next = nullptr;
}

void display()
{
  if (head == nullptr)
  {
    cout << "List is empty\n";
    return;
  }

  Node *temp = head;
  cout << "LinkedList: ";
  while (temp != nullptr)
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

  return 0;
}
