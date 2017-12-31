/*********************************************************************************
 * Kyle Helmick
 * December, 2017
 * Question 1:
 *    Write code to remove duplicates from an unsorted linked list.
 *********************************************************************************/
#include <iostream>

using namespace std;

struct node {
  int val;
  node *next;
  node *previous;
};

node* removeDups(node*);

int main(int argc, char* argv[]) {

  node* head = new node;
  head->val = 0;
  head->next = NULL;
  head->previous = NULL;

  node* current = head;

  for(int i = 1; i < 12; i++) {
    if(i%3 == 0) {
      node* insert = new node;
      insert->val = 14;
      insert->previous = current;
      current->next = insert;
      insert->next = NULL;
    } else {
      node* insert = new node;
      insert->val = i;
      insert->previous = current;
      current->next = insert;
      insert->next = NULL;
    }
    current = current->next;
  }

  current = head;
  while(current->next != NULL) {
    cout << current->val << " -> ";
    current = current->next;
  }
  cout << current->val << endl;

  removeDups(head);
  current = head;
  while(current->next != NULL) {
    cout << current->val << " -> ";
    current = current->next;
  }
  cout << current->val << endl;

  return 0;
}

node* removeDups(node* head) {
  // Initialization, we need a node to keep track of where we are in the main list,
  //    where we possibly are in the hashlist, and a hashtable to hold linked lists
  node* current = head;
  node* currenthash = NULL;
  node* hashtable[29];

  // We need to set all indices of the hashlist to NULL before we start
  for(int i = 0; i < 29; i++) {
    hashtable[i] = NULL;
  }

  while(current != NULL) {
    // If theres no node in the hash list just start a list
    if(hashtable[current->val%29] == NULL){

      node* insert = new node;
      insert->val = current->val;
      insert->next = NULL;
      insert->previous = NULL;

      hashtable[current->val%29] = insert;

    // If there is a node we have to go through the list, make sure our current 
    //    node from the main list is not in the hashlist. If it is remove the
    //    node from the main list and if not, add it to the hash list
    } else {

      currenthash = hashtable[current->val%29];
      bool nodefound = false;

      while(currenthash != NULL) {
        // If the value is found in the hash list, remove the node from the main list
        if(current->val == currenthash->val) {
          current->previous->next = current->next;
          current = current->previous;
          nodefound = true;
        }
        // If we have nade it to the end of the list, break before currenthash is set to NULL
        //    or just move on to the next node
        if(currenthash->next != NULL) {
          currenthash = currenthash->next;
        } else {
          break;
        }
      }

      // If we never found the node in the list then we need to add it to the hash list
      if(!nodefound) {
        node* insert = new node;
        insert->val = current->val;
        insert->next = NULL;
        insert->previous = currenthash;
        currenthash->next = insert;
      }
    }
    current = current->next;
  }
}