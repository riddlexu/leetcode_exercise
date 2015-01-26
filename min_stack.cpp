//https://oj.leetcode.com/problems/min-stack/

class MinStack {
 private:
  std::list<int> dataStack;
  std::list<int> minStack;
 public:
  void push(int x) {
    dataStack.push_front(x);
    if (x < minStack.front()){
      minStack.push_front(x);
    }
  }

  void pop() {
    int ele = dataStack.front();
    dataStack.pop_front();
    if ((ele == minStack.front()) && ((dataStack.size() == 0) || (dataStack.front() != ele))){
      minStack.pop_front();
    }
  }

  int top() {
    return dataStack.front();   
  }

  int getMin() {
    return minStack.front();  
  }
};
