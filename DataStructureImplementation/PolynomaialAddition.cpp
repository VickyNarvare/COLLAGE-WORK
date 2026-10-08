// BEGIN

//     // node structure
//     define node
//         coefficient
//         exponent
//         next
//     end define

//     // create a new node
//     procedure create_node(coefficient, exponent)

//         create new_node

//         new_node.coefficient ← coefficient
//         new_node.exponent ← exponent
//         new_node.next ← null

//         return new_node

//     end procedure

//     // add a term to polynomial
//     procedure add_term(head, coefficient, exponent)

//         new_node ← create_node(coefficient, exponent)

//         if head = null then
//             head ← new_node
//             return head
//         end if

//         temp ← head

//         while temp.next ≠ null
//             temp ← temp.next
//         end while

//         temp.next ← new_node

//         return head

//     end procedure

//     // create a polynomial
//     procedure create_polynomial()

//         set head ← null

//         read number_of_terms

//         for i ← 1 to number_of_terms

//             read coefficient
//             read exponent

//             head ← add_term(head, coefficient, exponent)

//         end for

//         return head

//     end procedure

//     // add two polynomials
//     procedure add_polynomial(poly1, poly2)

//         set result ← null

//         while poly1 ≠ null and poly2 ≠ null

//             if poly1.exponent = poly2.exponent then

//                 sum ← poly1.coefficient + poly2.coefficient

//                 if sum ≠ 0 then
//                     result ← add_term(
//                         result,
//                         sum,
//                         poly1.exponent
//                     )
//                 end if

//                 poly1 ← poly1.next
//                 poly2 ← poly2.next

//             else if poly1.exponent > poly2.exponent then

//                 result ← add_term(
//                     result,
//                     poly1.coefficient,
//                     poly1.exponent
//                 )

//                 poly1 ← poly1.next

//             else

//                 result ← add_term(
//                     result,
//                     poly2.coefficient,
//                     poly2.exponent
//                 )

//                 poly2 ← poly2.next

//             end if

//         end while

//         // copy remaining terms of first polynomial
//         while poly1 ≠ null

//             result ← add_term(
//                 result,
//                 poly1.coefficient,
//                 poly1.exponent
//             )

//             poly1 ← poly1.next

//         end while

//         // copy remaining terms of second polynomial
//         while poly2 ≠ null

//             result ← add_term(
//                 result,
//                 poly2.coefficient,
//                 poly2.exponent
//             )

//             poly2 ← poly2.next

//         end while

//         return result

//     end procedure

//     // display polynomial
//     procedure display(poly)

//         if poly = null then
//             print "polynomial is empty"
//             return
//         end if

//         temp ← poly

//         while temp ≠ null

//             print temp.coefficient, "x^", temp.exponent

//             temp ← temp.next

//         end while

//     end procedure

// end
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

  cout << "enter number of terms: ";
  cin >> terms;
  cout << "enter coefficient and exponent from highest to lowest:\n";

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
      addTerm(result, polynomial1->coefficient + polynomial2->coefficient,
              polynomial1->exponent);
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
// ===================== sample output =====================
// Polynomial 1
// enter number of terms: 3
// enter coefficient and exponent from highest to lowest:
// 5 3
// 4 2
// 2 0
// Polynomial 2
// enter number of terms: 2
// enter coefficient and exponent from highest to lowest:
// 3 2
// 6 1
// Polynomial 1: 5x^3 + 4x^2 + 2x^0
// Polynomial 2: 3x^2 + 6x^1
// Sum: 5x^3 + 7x^2 + 6x^1 + 2x^0
