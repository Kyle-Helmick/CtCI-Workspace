/*********************************************************************************
 * Kyle Helmick
 * January, 2018
 * Question 4:
 *    Write code to partition a linked list around a value x, such that all nodes 
 *      less than x come before all nodes greater than or equal to x. If x is contained
 *      within the list, the values of x only need to be after the elements less than
 *      x. The partition element x can appear anywhere in the "right partition"; it
 *      does not need to appear between the left and right partitions.
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

node* partition(int, node*);

int main(int argc, char* argv[]) {
  node* head = new node;
  head->next = NULL;
  head->val = 0;

  node* current = head;

  for(int i = 11; i > 0; i--) {
    node* insert = new node;
    insert->next = NULL;
    insert->val = i;
    current->next = insert;
    current = current->next;
  }

  cout << "Partition value: 5" << endl;

  printList(head);

  node* new_head = partition(5, head);

  printList(new_head);

  return 0;

}

node* partition(int part, node* main_head) {
  node* main_cur = main_head;
  
  node* part_head = new node;
  part_head->next = NULL;
  part_head->val = main_cur->val;
  node* part_tail = part_head;

  main_cur = main_cur->next;

  while(main_cur != NULL) {

    node* insert = new node;
    insert->val = main_cur->val;
    
    if(main_cur->val < part) {
      insert->next = part_head;
      part_head = insert;
    } else {
      part_tail->next = insert;
      insert->next = NULL;
      part_tail = insert;
    }

    main_cur = main_cur->next;
  }

  return part_head;
}