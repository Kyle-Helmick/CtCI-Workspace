/*********************************************************************************
 * Kyle Helmick
 * January, 2018
 * Question 2:
 *    Implement an algorithm to find the kth to last element of a singly linked list.
 *********************************************************************************/
#include <iostream>

using namespace std;

struct node {
  int val;
  node *next;
};

int kthToLast(int, node*);

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

  current = head;

  while(current->next != NULL) {
    cout << current->val << " -> ";
    current = current->next;
  }
  cout << current->val << endl;

  cout << "3rd to last is: " << kthToLast(3, head) << endl;
  cout << "1st to last is: " << kthToLast(1, head) << endl;
  cout << "0th to last is: " << kthToLast(0, head) << endl;
  cout << "12th to last is: " << kthToLast(12, head) << endl;
  cout << "-1st to last is: " << kthToLast(-1, head) << endl;
  cout << "20th to last is: " << kthToLast(20, head) << endl;

  return 0;
}

int kthToLast(int kth, node* head) {
  if(kth < 0) {
    return -1;
  }

  node* leader = head;
  node* follower = head;

  for(int i = 0; i < kth; i++) {
    if(leader == NULL) {
      return -1;
    }
    leader = leader->next;
  }

  while(leader != NULL) {
    leader = leader->next;
    follower = follower->next;
  }

  if(follower == NULL) {
    return -1;
  }

  return follower->val;
}