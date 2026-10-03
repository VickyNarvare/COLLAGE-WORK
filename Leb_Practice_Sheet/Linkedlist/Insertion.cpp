#include <iostream>
using namespace std;
class NODE {
 public:
  int data;
  NODE* next;
  // Initialize a node with a value and no next node.
  NODE(int value) {
    data = value;
    next = NULL;
  }
};
int itrate() {

};
int main() {
  NODE* n1 = new NODE(12);
  NODE* n2 = new NODE(23);
  NODE* head = n1;

  // Insert n2 at the beginning by linking it to the current head.
  n2->next = head;
  head = n2;

  // Print the data stored in both nodes.
  cout << n1->data << " " << n2->data;
}
