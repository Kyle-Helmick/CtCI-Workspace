/*********************************************************************************
 * Kyle Helmick
 * January, 2018
 * Question 3:
 *    Implement an algorithm to delete a node in the middle (i.e., any node but the
 *      first and last node, not necessarily the exact middle) of a singly linked list,
 *      given only access to that node.
 *********************************************************************************/
#include <iostream>

using namespace std;

struct node {
  int val;
  node *next;
};

void printList(node* head) {
  node* current = head;
  while(current->next != NULL) {
    cout << current->val << " -> ";
    current = current->next;
  }
  cout << current->val << endl;
}

void deleteMiddleNode(node*);

int main(int argc, char* argv[]) {
  node* head = new node;
  head->next = NULL;
  head->val = 0;

  node* current = head;

  for(int i = 1; i < 12; i++) {
    node* insert = new node;
    insert->next = NULL;
    insert->val = i;
    current->next = insert;
    current = current->next;
  }

  printList(head);

  node* deleteme = head->next->next->next->next->next->next;
  
  cout << "Node to delete is: " << deleteme->val << endl;

  deleteMiddleNode(deleteme);

  current = head;

  printList(head);

}

void deleteMiddleNode(node* start) {
    node* current = start;
    while(current->next->next != NULL) {
      current->val = current->next->val;
      current = current->next;
    }
    current->val = current->next->val;
    current->next = NULL;
}