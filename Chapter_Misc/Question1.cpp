/*********************************************************************************
 * Kyle Helmick
 * January, 2018
 * Question 1:
 *    Implement an algorithm to determine if a string has all unique characters.
 *    What if you cannot use additional data structures?
 *********************************************************************************/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class minHeap {
  private:
    vector<int> container;

    int getParent(int i) {
      return (i - 1) / 2;
    }

    int getLeft(int i) {
      return (2 * i) + 1;
    }

    int getRight(int i) {
      return (2 * i) + 2;
    }

    void heapifydown(int i) {
      int left = getLeft(i);
      int right = getRight(i);

      int smallest = i;

      if((left < container.size()) && (container[left] < container[smallest])) {
        smallest = left;
      }
      if((right < container.size()) && (container[right] < container[smallest])) {
        smallest = right;
      }

      if(smallest != i) {
        int temp = container[i];
        container[i] = container[smallest];
        container[smallest] = temp;
        
        heapifydown(smallest);
      }
    }

    void heapifyup(int i) {
      // basically saying if i > 0
      if(i && container[getParent(i)] > container[i]) {
        int temp = container[i];
        container[i] = container[getParent(i)];
        container[getParent(i)] = temp;

        heapifyup(getParent(i));
      }
    }

  public:
    int size() {
      return container.size();
    }

    bool empty() {
      return (0 == container.size());
    }

    void push(int val) {
      container.push_back(val);
      int index = container.size()-1;
      heapifyup(index);
    }

    int pop() {
      if(empty()) {
        cout << "The heap is empty!" << endl;
        return -1;
      }
      int ret = container[0];
      container[0] = container.back();
      container.pop_back();
      heapifydown(0);
      return ret;
    }

    int peek() {
      return container[0];
    }
};

int main()
{
	minHeap mh;
	
	// Note - Priority is decided by element's value
	
	mh.push(3);
	mh.push(2);
	mh.push(15);
	
	cout << "Size is " << mh.size() << endl;	
	
	cout << mh.peek() << " ";
	mh.pop();

	cout << mh.peek() << " ";
	mh.pop();

	mh.push(5);
	mh.push(4);
	mh.push(45);

	cout << endl << "Size is " << mh.size() << endl;
	
	cout << mh.peek() << " ";
	mh.pop();

	cout << mh.peek() << " ";
	mh.pop();

	cout << mh.peek() << " ";
	mh.pop();

	cout << mh.peek() << " ";
	mh.pop();

	cout << endl << std::boolalpha << mh.empty() << endl;
	
	mh.peek();	// top operation on an empty heap
	mh.pop();	// pop operation on an empty heap

	return 0;
}
