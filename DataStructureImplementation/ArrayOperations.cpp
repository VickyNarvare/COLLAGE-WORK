//     // step 1: initialize array
//     set size ← 10
//     declare array[size]
//     set length ← 0

//     // step 2: insert operation
//     procedure insert(item, pos)
//         if length = size then
//             print "array is full"
//             return
//         end if

//         if pos < 1 or pos > length + 1 then
//             print "invalid position"
//             return
//         end if

//         for i ← length downto pos
//             array[i] ← array[i - 1]
//         end for

//         array[pos - 1] ← item
//         length ← length + 1

//     end procedure

//     // step 3: delete operation
//     procedure delete(pos)

//         if pos < 1 or pos > length then
//             print "invalid position"
//             return
//         end if

//         item ← array[pos - 1]

//         for i ← pos - 1 to length - 2
//             array[i] ← array[i + 1]
//         end for

//         length ← length - 1

//         print "deleted item:", item

//     end procedure

//     // step 4: search operation
//     procedure search(item)

//         set found ← false

//         for i ← 0 to length - 1
//             if array[i] = item then
//                 print "element found at position:", i + 1
//                 set found ← true
//                 break
//             end if
//         end for

//         if found = false then
//             print "element not found"
//         end if

//     end procedure

//     // step 5: update operation
//     procedure update(pos, item)

//         if pos < 1 or pos > length then
//             print "invalid position"
//             return
//         end if

//         array[pos - 1] ← item

//         print "element updated successfully"

//     end procedure

//     // step 6: display operation
//     procedure display()

//         if length = 0 then
//             print "array is empty"
//             return
//         end if

//         print "array elements:"

//         for i ← 0 to length - 1
//             print array[i]
//         end for

#include <iostream>
using namespace std;

#define size 5

int array[size];
int length = 0;

void insert_el(int pos, int val) //Insert Operation
{
  if (length == size)
  {
    cout << "array is full\n";
    return;
  }
  if (pos < 1 || pos > length + 1)
  {
    cout << "invalid position\n";
    return;
  }

  for (int i = length; i >= pos; i--)
  {
    array[i] = array[i - 1];
  }
  array[pos - 1] = val;
  length++;
  cout << val << " inserted into array\n";
}

void delete_el(int pos) //Delete Operation
{
  if (pos < 1 || pos > length)
  {
    cout << "invalid position\n";
    return;
  }

  int val = array[pos - 1];
  for (int i = pos - 1; i < length - 1; i++)
  {
    array[i] = array[i + 1];
  }
  length--;
  cout << val << " deleted from array\n";
}

void search_el(int val) //Search Element 
{
  for (int i = 0; i < length; i++)
  {
    if (array[i] == val)
    {
      cout << val << " found at position " << i + 1 << endl;
      return;
    }
  }
  cout << "element not found\n";
}

void update_el(int pos, int val) // Update Eletemet
{
  if (pos < 1 || pos > length)
  {
    cout << "invalid position\n";
    return;
  }

  array[pos - 1] = val;
  cout << "element at position " << pos << " updated\n";
}

void show() //Display Elements
{
  if (length == 0)
  {
    cout << "array is empty\n";
    return;
  }

  cout << "array: ";
  for (int i = 0; i < length; i++)
  {
    cout << array[i] << " ";
  }
  cout << endl;
}

int main()
{
  int ch, pos, val;

  while (true)
  {
    cout << "\n1. insert\n";
    cout << "2. delete\n";
    cout << "3. search\n";
    cout << "4. update\n";
    cout << "5. display\n";
    cout << "6. exit\n";
    cout << "enter choice: ";
    cin >> ch;

    switch (ch)
    {
    case 1:
      cout << "enter position (1-" << length + 1 << "): ";
      cin >> pos;
      cout << "enter value: ";
      cin >> val;
      insert_el(pos, val);
      break;

    case 2:
      cout << "enter position (1-" << length << "): ";
      cin >> pos;
      delete_el(pos);
      break;

    case 3:
      cout << "enter value to search: ";
      cin >> val;
      search_el(val);
      break;

    case 4:
      cout << "enter position (1-" << length << "): ";
      cin >> pos;
      cout << "enter new value: ";
      cin >> val;
      update_el(pos, val);
      break;

    case 5:
      show();
      break;

    case 6:
      return 0;

    default:
      cout << "invalid choice\n";
    }
  }
}
