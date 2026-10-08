//     // node structure
//     define node
//         data
//         next
//     end define

//     set head ← null

//     // create a new node
//     procedure create_node(item)

//         create new_node
//         new_node.data ← item
//         new_node.next ← null

//         return new_node

//     end procedure

//     // insert at beginning
//     procedure insert_beginning(item)

//         new_node ← create_node(item)

//         new_node.next ← head
//         head ← new_node

//         print "node inserted successfully"

//     end procedure

//     // insert at end
//     procedure insert_end(item)

//         new_node ← create_node(item)

//         if head = null then
//             head ← new_node
//             print "node inserted successfully"
//             return
//         end if

//         temp ← head

//         while temp.next ≠ null
//             temp ← temp.next
//         end while

//         temp.next ← new_node

//         print "node inserted successfully"

//     end procedure

//     // delete from beginning
//     procedure delete_beginning()

//         if head = null then
//             print "list is empty"
//             return
//         end if

//         temp ← head
//         head ← head.next

//         delete temp

//         print "node deleted successfully"

//     end procedure

//     // delete from end
//     procedure delete_end()

//         if head = null then
//             print "list is empty"
//             return
//         end if

//         if head.next = null then
//             delete head
//             head ← null
//             print "node deleted successfully"
//             return
//         end if

//         temp ← head

//         while temp.next.next ≠ null
//             temp ← temp.next
//         end while

//         delete temp.next
//         temp.next ← null

//         print "node deleted successfully"

//     end procedure

//     // display linked list
//     procedure display()

//         if head = null then
//             print "list is empty"
//             return
//         end if

//         temp ← head

//         while temp ≠ null
//             print temp.data
//             temp ← temp.next
//         end while

//     end procedure

//     // main menu
//     repeat

//         print "1. insert at beginning"
//         print "2. insert at end"
//         print "3. delete from beginning"
//         print "4. delete from end"
//         print "5. display"
//         print "6. exit"

//         read choice

//         if choice = 1 then
//             read item
//             call insert_beginning(item)

//         else if choice = 2 then
//             read item
//             call insert_end(item)

//         else if choice = 3 then
//             call delete_beginning()

//         else if choice = 4 then
//             call delete_end()

//         else if choice = 5 then
//             call display()

//         else if choice = 6 then
//             print "program terminated"

//         else
//             print "invalid choice"

//         end if

//     until choice = 6

// end
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
    cout << "list is empty\n";
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
    cout << "list is empty\n";
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
    cout << "list is empty\n";
    return;
  }

  Node *temp = head;
  cout << "linked list: ";
  while (temp != nullptr)
  {
    cout << temp->data << " -> ";
    temp = temp->next;
  }
  cout << "null\n";
}

int main()
{
  int choice, value;

  while (true)
  {
    cout << "\n1. insert at beginning\n";
    cout << "2. insert at end\n";
    cout << "3. delete from beginning\n";
    cout << "4. delete from end\n";
    cout << "5. display\n";
    cout << "6. exit\n";
    cout << "enter choice: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
      cout << "enter value: ";
      cin >> value;
      insertAtBeginning(value);
      break;

    case 2:
      cout << "enter value: ";
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
      cout << "invalid choice\n";
    }
  }

  return 0;
}

// ===================== sample output =====================
// 1. insert at beginning
// 2. insert at end
// 3. delete from beginning
// 4. delete from end
// 5. display
// 6. exit
// enter choice: 1
// enter value: 20
// 20 inserted at beginning
//
// enter choice: 1
// enter value: 10
// 10 inserted at beginning
//
// enter choice: 2
// enter value: 30
// 30 inserted at end
//
// enter choice: 5
// linked list: 10 -> 20 -> 30 -> null
//
// enter choice: 3
// 10 deleted from beginning
//
// enter choice: 4
// 30 deleted from end
//
// enter choice: 5
// linked list: 20 -> null
//
// enter choice: 4
// 20 deleted from end
//
// enter choice: 5
// list is empty
//
// enter choice: 6
