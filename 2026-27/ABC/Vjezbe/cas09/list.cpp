#include <iostream>

using namespace std;

struct Node {
    int value;
    Node* next;
};

// Dodaje element na pocetak liste
// head - pokazivac na prvi element liste
// x - vrijednost novog elementa
Node* add_front_n(Node* head, int x) {
    Node* new_element = new Node{x, head};
    return new_element;
}

void add_front(Node*& head, int x) {
    Node* new_element = new Node{x, head};
    head = new_element;
}

void print_list(Node* head) {
    Node* curr = head;

    while(curr != nullptr) {
        cout << curr->value << " ";
        curr = curr->next;
    }

    cout << endl;
}

void delete_list(Node* head) {
    Node* curr = head;

    while(curr != nullptr) {
        Node* next = curr->next;
        delete curr;
        curr = next;
    }
}

void add_back(Node*& head, int x) {
    Node* new_node = new Node{x, nullptr};

    if(head == nullptr) {
        head = new_node;
    } else {
        Node* curr = head;
        while(curr->next != nullptr) curr = curr->next;
        curr->next = new_node;
    }
}

int main() {
    Node* head = nullptr;
    add_back(head, 3);
    add_back(head, 4);
    add_back(head, 5);

    print_list(head);

    delete_list(head);

    return 0;
}