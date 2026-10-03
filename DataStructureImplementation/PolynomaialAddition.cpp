// PSEUDOCODE: POLYNOMIAL ADDITION USING LINKED LIST
//
// Create a node:
//     Store coefficient and exponent.
//     Set next to NULL.
//
// Add a term:
//     Create a new node.
//     If the list is empty, make it head.
//     Otherwise, move to the last node and attach the new node.
//
// Create a polynomial:
//     Read the number of terms.
//     Read terms from highest exponent to lowest exponent.
//     Add every term to the linked list.
//
// Add two polynomials:
//     Compare the exponents of both lists.
//     If equal, add the coefficients and move both nodes.
//     Copy the term with the greater exponent.
//     Copy the remaining terms.
//
// Display:
//     Start from head and print every term until NULL.

#include <iostream>
using namespace std;

class NODE
{
public:
  int coefficient;
  int exponent;
  NODE *next;

  NODE(int coefficientValue, int exponentValue)
  {
    coefficient = coefficientValue;
    exponent = exponentValue;
    next = NULL;
  }
};

void addTerm(NODE *&head, int coefficient, int exponent)
{
  if (coefficient == 0)
  {
    return;
  }

  NODE *newNode = new NODE(coefficient, exponent);

  if (head == NULL)
  {
    head = newNode;
    return;
  }

  NODE *temp = head;
  while (temp->next != NULL)
  {
    temp = temp->next;
  }
  temp->next = newNode;
}

NODE *createPolynomial()
{
  NODE *head = NULL;
  int terms, coefficient, exponent;

  cout << "Enter number of terms: ";
  cin >> terms;
  cout << "Enter coefficient and exponent from highest to lowest:\n";

  for (int i = 0; i < terms; i++)
  {
    cin >> coefficient >> exponent;
    addTerm(head, coefficient, exponent);
  }

  return head;
}

NODE *addPolynomials(NODE *polynomial1, NODE *polynomial2)
{
  NODE *result = NULL;

  while (polynomial1 != NULL || polynomial2 != NULL)
  {
    if (polynomial1 == NULL)
    {
      addTerm(result, polynomial2->coefficient, polynomial2->exponent);
      polynomial2 = polynomial2->next;
    }
    else if (polynomial2 == NULL)
    {
      addTerm(result, polynomial1->coefficient, polynomial1->exponent);
      polynomial1 = polynomial1->next;
    }
    else if (polynomial1->exponent == polynomial2->exponent)
    {
      addTerm(result, polynomial1->coefficient + polynomial2->coefficient, polynomial1->exponent);
      polynomial1 = polynomial1->next;
      polynomial2 = polynomial2->next;
    }
    else if (polynomial1->exponent > polynomial2->exponent)
    {
      addTerm(result, polynomial1->coefficient, polynomial1->exponent);
      polynomial1 = polynomial1->next;
    }
    else
    {
      addTerm(result, polynomial2->coefficient, polynomial2->exponent);
      polynomial2 = polynomial2->next;
    }
  }

  return result;
}

void display(NODE *head)
{
  if (head == NULL)
  {
    cout << "0\n";
    return;
  }

  NODE *temp = head;
  while (temp != NULL)
  {
    cout << temp->coefficient << "x^" << temp->exponent;
    if (temp->next != NULL)
    {
      cout << " + ";
    }
    temp = temp->next;
  }
  cout << "\n";
}

void deletePolynomial(NODE *&head)
{
  while (head != NULL)
  {
    NODE *temp = head;
    head = head->next;
    delete temp;
  }
}

int main()
{
  cout << "Polynomial 1\n";
  NODE *polynomial1 = createPolynomial();

  cout << "Polynomial 2\n";
  NODE *polynomial2 = createPolynomial();

  NODE *sumPolynomial = addPolynomials(polynomial1, polynomial2);

  cout << "Polynomial 1: ";
  display(polynomial1);
  cout << "Polynomial 2: ";
  display(polynomial2);
  cout << "Sum: ";
  display(sumPolynomial);

  deletePolynomial(polynomial1);
  deletePolynomial(polynomial2);
  deletePolynomial(sumPolynomial);

  return 0;
}
