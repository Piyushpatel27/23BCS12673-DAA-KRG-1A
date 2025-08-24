#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

// Doubly Linked List
class DoublyLinkedList {
    Node* head;
public:
    DoublyLinkedList() { head = nullptr; }

    void insertAtBeginning(int val) {
        Node* temp = new Node{val, head, nullptr};
        if(head) head->prev = temp;
        head = temp;
    }

    void insertAtEnd(int val) {
        Node* temp = new Node{val, nullptr, nullptr};
        if(!head) { head = temp; return; }
        Node* curr = head;
        while(curr->next) curr = curr->next;
        curr->next = temp;
        temp->prev = curr;
    }

    void deleteFromBeginning() {
        if(!head) return;
        Node* temp = head;
        head = head->next;
        if(head) head->prev = nullptr;
        delete temp;
    }

    void deleteFromEnd() {
        if(!head) return;
        if(!head->next) { delete head; head = nullptr; return; }
        Node* curr = head;
        while(curr->next) curr = curr->next;
        curr->prev->next = nullptr;
        delete curr;
    }

    void display() {
        Node* curr = head;
        while(curr) { cout << curr->data << " "; curr = curr->next; }
        cout << endl;
    }
};

// Circular Linked List
class CircularLinkedList {
    Node* tail;
public:
    CircularLinkedList() { tail = nullptr; }

    void insertAtBeginning(int val) {
        Node* temp = new Node{val, nullptr, nullptr};
        if(!tail) { tail = temp; tail->next = tail; return; }
        temp->next = tail->next;
        tail->next = temp;
    }

    void insertAtEnd(int val) {
        Node* temp = new Node{val, nullptr, nullptr};
        if(!tail) { tail = temp; tail->next = tail; return; }
        temp->next = tail->next;
        tail->next = temp;
        tail = temp;
    }

    void deleteFromBeginning() {
        if(!tail) return;
        Node* head = tail->next;
        if(tail == head) { delete tail; tail = nullptr; return; }
        tail->next = head->next;
        delete head;
    }

    void deleteFromEnd() {
        if(!tail) return;
        Node* head = tail->next;
        if(tail == head) { delete tail; tail = nullptr; return; }
        Node* curr = head;
        while(curr->next != tail) curr = curr->next;
        curr->next = tail->next;
        delete tail;
        tail = curr;
    }

    void display() {
        if(!tail) return;
        Node* curr = tail->next;
        do { cout << curr->data << " "; curr = curr->next; } while(curr != tail->next);
        cout << endl;
    }
};

int main() {
    DoublyLinkedList d;
    d.insertAtBeginning(10);
    d.insertAtEnd(20);
    d.insertAtBeginning(5);
    d.insertAtEnd(25);
    d.display();
    d.deleteFromBeginning();
    d.deleteFromEnd();
    d.display();

    CircularLinkedList c;
    c.insertAtBeginning(1);
    c.insertAtEnd(2);
    c.insertAtBeginning(0);
    c.insertAtEnd(3);
    c.display();
    c.deleteFromBeginning();
    c.deleteFromEnd();
    c.display();

    return 0;
}
