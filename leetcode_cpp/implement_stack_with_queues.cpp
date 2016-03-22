//https://leetcode.com/problems/implement-stack-using-queues/

class Stack {
public:
  // Push element x onto stack.
  std::deque<int> queueA;
  std::deque<int> queueB;
  void push(int x) {
    while(!queueA.empty()) {
      queueB.push_back(queueA.front());
      queueA.pop_front();
    }
    queueA.push_back(x);
    while(!queueB.empty()) {
      queueA.push_back(queueB.front());
      queueB.pop_front();
    }
  }

  // Removes the element on top of the stack.
  void pop() {
    queueA.pop_front();
  }
  // Get the top element.
  int top() {
    return queueA.front();
  }
  // Return whether the stack is empty.
  bool empty() {
    return queueA.empty();
  }
};
