//COMSC-210-5068, Lab 17, Yang Liu
#include <iostream>
#include <cstdlib>
using namespace std;

const int SIZE = 7;  

struct Node {
    float value;
    Node *next;
};

void output(Node *);
Node* addNodeToFront(Node *head, int val);  
Node* addNodeToTail(Node *head, int val);   
Node* insertNodeAfterPosition(Node *head, int position, int val);  
Node* deleteNodeAtPosition(Node *head, int position);  
void deleteEntireList(Node *&head);   


int main() {
    Node *head = nullptr;
    int count = 0;

    for (int i = 0; i < SIZE; i++) {
        int tmp_val = rand() % 100;
        head = addNodeToFront(head, tmp_val);
    }
    cout << "Initial linked list: " << endl;
    output(head);

    //Test addNodeToTail 
    head = addNodeToTail(head, 666); 
    cout << "Adding 666 to the TAIL: " << endl;
    output(head); 

    // deleting a node
    cout << "Which node to delete? " << endl;
    output(head);
    int entry;
    cout << "Choice --> ";
    cin >> entry;

    // traverse that many times and delete that node
    Node *current = head;
    Node *prev = nullptr;  // start prev as nullptr to detect head deletion

    for (int i = 0; i < (entry - 1); i++) {
        prev = current;
        current = current->next;
    }

    // at this point, delete current and reroute pointers
    if (current) {
        if (prev == nullptr) {
            // deleting the head node
            head = current->next;
        } else {
            prev->next = current->next;
        }
        delete current;
        current = nullptr;
    }
    output(head);

    // insert a node
    cout << "After which node to insert 10000? " << endl;
    count = 1;
    current = head;
    while (current) {
        cout << "[" << count++ << "] " << current->value << endl;
        current = current->next;
    }
    cout << "Choice --> ";
    cin >> entry;

    current = head;
    prev = nullptr;  // reset prev to nullptr for same reason

    for (int i = 0; i < entry; i++) {
        prev = current;
        current = current->next;
    }

    // at this point, insert a node between prev and current
    Node *newnode = new Node;
    newnode->value = 10000;
    newnode->next = current;

    if (prev == nullptr) {
        // inserting before the head
        head = newnode;
    } else {
        prev->next = newnode;
    }
    output(head);

    // deleting the linked list
    current = head;
    while (current) {
        head = current->next;
        delete current;
        current = head;
    }
    head = nullptr;
    output(head);

    return 0;
}

void output(Node *hd) {
    if (!hd) {
        cout << "Empty list.\n";
        return;
    }
    int count = 1;
    Node *current = hd;
    while (current) {
        cout << "[" << count++ << "] " << current->value << endl;
        current = current->next;
    }
    cout << endl;
}

Node* addNodeToFront(Node *head, int val) {
    Node *newNode = new Node;
    newNode->value = val;
    newNode->next = head;
    return newNode;
}

Node* addNodeToTail(Node *head, int val) {
    Node *newNode = new Node;
    newNode->value = val;
    newNode->next = nullptr;
    if (!head) {
        return newNode;
    }
    Node *current = head;
    while (current->next != nullptr) {
        current = current->next;
    }
    current->next = newNode;
    return head;
}