//     // Step 1: Initialize Array
//     SET SIZE ← 10
//     DECLARE ARRAY[SIZE]
//     SET LENGTH ← 0

//     // Step 2: INSERT Operation
//     PROCEDURE INSERT(ITEM, POS)
//         IF LENGTH = SIZE THEN
//             PRINT "Array is Full"
//             RETURN
//         END IF

//         IF POS < 1 OR POS > LENGTH + 1 THEN
//             PRINT "Invalid position"
//             RETURN
//         END IF

//         FOR I ← LENGTH DOWNTO POS
//             ARRAY[I] ← ARRAY[I - 1]
//         END FOR

//         ARRAY[POS - 1] ← ITEM
//         LENGTH ← LENGTH + 1

//     END PROCEDURE

//     // Step 3: DELETE Operation
//     PROCEDURE DELETE(POS)

//         IF POS < 1 OR POS > LENGTH THEN
//             PRINT "Invalid position"
//             RETURN
//         END IF

//         ITEM ← ARRAY[POS - 1]

//         FOR I ← POS - 1 TO LENGTH - 2
//             ARRAY[I] ← ARRAY[I + 1]
//         END FOR

//         LENGTH ← LENGTH - 1

//         PRINT "Deleted Item:", ITEM

//     END PROCEDURE

//     // Step 4: SEARCH Operation
//     PROCEDURE SEARCH(ITEM)

//         SET FOUND ← FALSE

//         FOR I ← 0 TO LENGTH - 1
//             IF ARRAY[I] = ITEM THEN
//                 PRINT "Element found at position:", I + 1
//                 SET FOUND ← TRUE
//                 BREAK
//             END IF
//         END FOR

//         IF FOUND = FALSE THEN
//             PRINT "Element not found"
//         END IF

//     END PROCEDURE

//     // Step 5: UPDATE Operation
//     PROCEDURE UPDATE(POS, ITEM)

//         IF POS < 1 OR POS > LENGTH THEN
//             PRINT "Invalid position"
//             RETURN
//         END IF

//         ARRAY[POS - 1] ← ITEM

//         PRINT "Element updated successfully"

//     END PROCEDURE

//     // Step 6: DISPLAY Operation
//     PROCEDURE DISPLAY()

//         IF LENGTH = 0 THEN
//             PRINT "Array is empty"
//             RETURN
//         END IF

//         PRINT "Array Elements:"

//         FOR I ← 0 TO LENGTH - 1
//             PRINT ARRAY[I]
//         END FOR

#include <iostream>
using namespace std;

#define SIZE 5

int array[SIZE];
int length = 0;

void insertElement(int position, int value)
{
  if (length == SIZE)
  {
    cout << "Array is full\n";
    return;
  }
  if (position < 1 || position > length + 1)
  {
    cout << "Invalid position\n";
    return;
  }

  for (int i = length; i >= position; i--)
  {
    array[i] = array[i - 1];
  }
  array[position - 1] = value;
  length++;
  cout << value << " inserted into array\n";
}

void deleteElement(int position)
{
  if (position < 1 || position > length)
  {
    cout << "Invalid position\n";
    return;
  }

  int value = array[position - 1];
  for (int i = position - 1; i < length - 1; i++)
  {
    array[i] = array[i + 1];
  }
  length--;
  cout << value << " deleted from array\n";
}

void searchElement(int value)
{
  for (int i = 0; i < length; i++)
  {
    if (array[i] == value)
    {
      cout << value << " found at position " << i + 1 << endl;
      return;
    }
  }
  cout << "Element not found\n";
}

void updateElement(int position, int value)
{
  if (position < 1 || position > length)
  {
    cout << "Invalid position\n";
    return;
  }

  array[position - 1] = value;
  cout << "Element at position " << position << " updated\n";
}

void display()
{
  if (length == 0)
  {
    cout << "Array is empty\n";
    return;
  }

  cout << "Array: ";
  for (int i = 0; i < length; i++)
  {
    cout << array[i] << " ";
  }
  cout << endl;
}

int main()
{
  int choice, position, value;

  while (true)
  {
    cout << "\n1. Insert\n";
    cout << "2. Delete\n";
    cout << "3. Search\n";
    cout << "4. Update\n";
    cout << "5. Display\n";
    cout << "6. Exit\n";
    cout << "Enter choice: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
      cout << "Enter position (1-" << length + 1 << "): ";
      cin >> position;
      cout << "Enter value: ";
      cin >> value;
      insertElement(position, value);
      break;

    case 2:
      cout << "Enter position (1-" << length << "): ";
      cin >> position;
      deleteElement(position);
      break;

    case 3:
      cout << "Enter value to search: ";
      cin >> value;
      searchElement(value);
      break;

    case 4:
      cout << "Enter position (1-" << length << "): ";
      cin >> position;
      cout << "Enter new value: ";
      cin >> value;
      updateElement(position, value);
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
