#include <iostream>
using namespace std;
#define MAX 100   // maximum size of stack

class Stack {
    int arr[MAX];
    int top;

public:
    Stack() { 
        top = -1; 
    }

    void push(int x) {
        if (top == MAX - 1) {
            cout << "Stack Overflow\n";
            return;
        }
        arr[++top] = x;
    }

    int pop() {
        if (empty()) {
            cout << "Stack Underflow\n";
            return -1;
        }
        return arr[top--];
    }

    int peek() {
        if (empty()) {
            cout << "Stack is Empty\n";
            return -1;
        }
        return arr[top];
    }

    bool empty() {
         return top == -1;
    }

    int size() { 
        return top + 1; 
    }
};

int main() {
    Stack st;
    st.push(10);
    st.push(20);
    st.push(30);
    cout<<"Stack :"<<"10 20 30"<<endl;
    cout << "Top: " << st.peek() << "\n";   // 30
    cout << "Size: " << st.size() << "\n";  // 3

    cout << "Popped: " << st.pop() << "\n"; // 30
    cout << "Top: " << st.peek() << "\n";   // 20

    return 0;
}
