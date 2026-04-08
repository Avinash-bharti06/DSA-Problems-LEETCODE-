class MyQueue {
public:
    stack<int> s1;
    stack<int> s2;

    MyQueue() {}

    // push
    void push(int x) {
        s1.push(x);   
    }

    // pop
    int pop() {
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        int x = s2.top();
        s2.pop();
        return x;
    }

    // peek
    int peek() {
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        return s2.top();
    }

    // empty
    bool empty() {
        return s1.empty() && s2.empty();
    }
};