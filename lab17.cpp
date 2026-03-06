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

    int entry;
    cout << "After which node to insert 10000? " << endl;
    int count = 1;
    Node *current = head;
    while (current) {
        cout << "[" << count++ << "] " << current->value << endl;
        current = current->next;
    }
    cout << "Choice --> ";
    cin >> entry;
    head = insertNodeAfterPosition(head, entry, 10000);
    cout << "Linked list after inserting 10000: " << endl;
    output(head);

    // Delete node at specified position
    cout << "Which node to delete?: ";
    int del_pos;
    cin >> del_pos;
    head = deleteNodeAtPosition(head, del_pos);
    cout << "Linked list after deleting node " << del_pos << ": " << endl;
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

Node* insertNodeAfterPosition(Node *head, int position, int val) {
    if (position < 1) {
        cout << "Invalid position!" << endl;
        return head;
    }

    Node *prev = nullptr;
    Node *current = head;
    int i = 0;
    while (current != nullptr && i < position) {
        prev = current;
        current = current->next;
        i++;
    }
    if (i < position) {
        cout << "Position exceeds list length!" << endl;
        return head;
    }
    Node *newnode = new Node;
    newnode->value = val;
    newnode->next = current;
    prev->next = newnode;
    return head;
}

Node* deleteNodeAtPosition(Node *head, int position) {
    if (!head || position < 1) {
        cout << "Empty list or invalid position!" << endl;
        return head;
    }

    Node *toDelete = nullptr;
    // For delete head node
    if (position == 1) {
        toDelete = head;
        head = head->next;
        delete toDelete;
        return head;
    }

    Node *prev = head;
    int i = 1;
    while (prev != nullptr && i < position - 1) {
        prev = prev->next;
        i++;
    }

    if (!prev || !prev->next) {
        cout << "Position exceeds list length!" << endl;
        return head;
    }

    toDelete = prev->next;
    prev->next = toDelete->next;
    delete toDelete;

    return head;
}
