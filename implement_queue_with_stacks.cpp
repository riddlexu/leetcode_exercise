//https://leetcode.com/problems/implement-queue-using-stacks/

class Queue {
public:
  // Push element x to the back of queue.
  std::deque<int> stackA;
  std::deque<int> stackB;

  void push(int x) {
    while(!stackB.empty()){
      stackA.push_back(stackB.back());
      stackB.pop_back();
    }
    stackA.push_back(x);
    while(!stackA.empty()){
      stackB.push_back(stackA.back());
      stackA.pop_back();
    }
  }

  // Removes the element from in front of queue.
  void pop(void) {
    stackB.pop_back();
  }

  // Get the front element.
  int peek(void) {
    return stackB.back();
  }

  // Return whether the queue is empty.
  bool empty(void) {
    return stackB.empty();
  }
};
