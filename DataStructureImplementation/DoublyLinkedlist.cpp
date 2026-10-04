//     // node structure
//     define node
//         data
//         previous
//         next
//     end define

//     set head ← null
//     set tail ← null

//     // create a new node
//     procedure create_node(item)

//         create new_node
//         new_node.data ← item
//         new_node.previous ← null
//         new_node.next ← null

//         return new_node

//     end procedure

//     // insert at beginning
//     procedure insert_beginning(item)

//         new_node ← create_node(item)

//         if head = null then
//             head ← new_node
//             tail ← new_node
//         else
//             new_node.next ← head
//             head.previous ← new_node
//             head ← new_node
//         end if

//     end procedure

//     // insert at end
//     procedure insert_end(item)

//         new_node ← create_node(item)

//         if tail = null then
//             head ← new_node
//             tail ← new_node
//         else
//             new_node.previous ← tail
//             tail.next ← new_node
//             tail ← new_node
//         end if

//     end procedure

//     // delete from beginning
//     procedure delete_beginning()

//         if head = null then
//             print "list is empty"
//             return
//         end if

//         temp ← head

//         if head = tail then
//             head ← null
//             tail ← null
//         else
//             head ← head.next
//             head.previous ← null
//         end if

//         delete temp

//     end procedure

//     // delete from end
//     procedure delete_end()

//         if tail = null then
//             print "list is empty"
//             return
//         end if

//         temp ← tail

//         if head = tail then
//             head ← null
//             tail ← null
//         else
//             tail ← tail.previous
//             tail.next ← null
//         end if

//         delete temp

//     end procedure

//     // display forward
//     procedure display_forward()

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

//     // display backward
//     procedure display_backward()

//         if tail = null then
//             print "list is empty"
//             return
//         end if

//         temp ← tail

//         while temp ≠ null
//             print temp.data
//             temp ← temp.previous
//         end while

//     end procedure

// end
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

// insert a node at the beginning of the list.
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

// insert a node at the end of the list.
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

// delete the first node of the list.
void deleteFromBeginning()
{
  if (head == NULL)
  {
    cout << "list is empty\n";
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

// delete the last node of the list.
void deleteFromEnd()
{
  if (tail == NULL)
  {
    cout << "list is empty\n";
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

// display the list from head to tail.
void displayForward()
{
  if (head == NULL)
  {
    cout << "list is empty\n";
    return;
  }
  NODE *temp = head;
  cout << "forward: ";
  while (temp != NULL)
  {
    cout << temp->data << " <-> ";
    temp = temp->next;
  }
  cout << "null\n";
}

// display the list from tail to head.
void displayBackward()
{
  if (tail == NULL)
  {
    cout << "list is empty\n";
    return;
  }
  NODE *temp = tail;
  cout << "backward: ";
  while (temp != NULL)
  {
    cout << temp->data << " <-> ";
    temp = temp->previous;
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
    cout << "5. display forward\n";
    cout << "6. display backward\n";
    cout << "7. exit\n";
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
      cout << "invalid choice\n";
    }
  }
}
