//https://oj.leetcode.com/problems/min-stack/

class MinStack {
 private:
  stack<int> dataStack;
  stack<int> minStack;
 public:
  void push(int x) {
    dataStack.push(x);
    if (minStack.empty() || (x <= minStack.top())){
      minStack.push(x);
    }
  }

  void pop() {
    int ele = dataStack.top();
    dataStack.pop();
    if (ele == minStack.top()){
      minStack.pop();
    }
  }

  int top() {
    return dataStack.top();   
  }

  int getMin() {
    return minStack.top();  
  }
};
