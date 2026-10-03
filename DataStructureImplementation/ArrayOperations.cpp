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

#define SIZE 5

int arr[SIZE];
int len = 0;

void insertEl(int pos, int val){
  if (len == SIZE)
  {
    cout << "Array is full\n";
    return;
  }
  if (pos < 1 || pos > len + 1)
  {
    cout << "Invalid position\n";
    return;
  }

  for (int i = len; i >= pos; i--)
  {
    arr[i] = arr[i - 1];
  }
  arr[pos - 1] = val;
  len++;
  cout << val << " inserted into array\n";
}

void deleteEl(int pos)
{
  if (pos < 1 || pos > len)
  {
    cout << "Invalid position\n";
    return;
  }

  int val = arr[pos - 1];
  for (int i = pos - 1; i < len - 1; i++)
  {
    arr[i] = arr[i + 1];
  }
  len--;
  cout << val << " deleted from array\n";
}

void searchEl(int val)
{
  for (int i = 0; i < len; i++)
  {
    if (arr[i] == val)
    {
      cout << val << " found at position " << i + 1 << endl;
      return;
    }
  }
  cout << "Element not found\n";
}

void updateEl(int pos, int val)
{
  if (pos < 1 || pos > len)
  {
    cout << "Invalid position\n";
    return;
  }

  arr[pos - 1] = val;
  cout << "Element at position " << pos << " updated\n";
}

void show()
{
  if (len == 0)
  {
    cout << "Array is empty\n";
    return;
  }

  cout << "Array: ";
  for (int i = 0; i < len; i++)
  {
    cout << arr[i] << " ";
  }
  cout << endl;
}

int main()
{
  int ch, pos, val;

  while (true)
  {
    cout << "\n1. Insert\n";
    cout << "2. Delete\n";
    cout << "3. Search\n";
    cout << "4. Update\n";
    cout << "5. Display\n";
    cout << "6. Exit\n";
    cout << "Enter choice: ";
    cin >> ch;

    switch (ch)
    {
    case 1:
      cout << "Enter position (1-" << len + 1 << "): ";
      cin >> pos;
      cout << "Enter value: ";
      cin >> val;
      insertEl(pos, val);
      break;

    case 2:
      cout << "Enter position (1-" << len << "): ";
      cin >> pos;
      deleteEl(pos);
      break;

    case 3:
      cout << "Enter value to search: ";
      cin >> val;
      searchEl(val);
      break;

    case 4:
      cout << "Enter position (1-" << len << "): ";
      cin >> pos;
      cout << "Enter new value: ";
      cin >> val;
      updateEl(pos, val);
      break;

    case 5:
      show();
      break;

    case 6:
      return 0;

    default:
      cout << "Invalid choice\n";
    }
  }
}
