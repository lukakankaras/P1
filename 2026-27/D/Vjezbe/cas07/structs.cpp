#include <iostream>

using namespace std;

struct Node {
    int value;
    Node* next;
};

Node* add_front_n(Node* head, int v) {
    Node* new_element = new Node{v, head};
    return new_element;
}

void add_front(Node*& head, int v) {
    Node* new_element = new Node{v, head};
    head = new_element;
}

void add_back(Node*& head, int v) {
    if(head == nullptr) {
        add_front(head, v);
    } else {
        Node* new_element = new Node{v, nullptr};

        Node* curr = head;
        while(curr->next != nullptr) {
            curr = curr->next;
        }

        curr->next = new_element;
    }
}

void print_list(Node* head) {
    Node* curr = head;

    while(curr != nullptr) {
        cout << curr->value << " ";
        curr = curr->next;
    }

    cout << endl;
}

void delete_list(Node*& head) {
    Node* curr = head;

    while(curr != nullptr) {
        Node* next = curr->next;
        delete curr;
        curr = next;
    }

    head = nullptr;
}

void insert_at(Node*& head, int index, int value) {
    if(head == nullptr || index <= 0) {
        add_front(head, value);
    } else {
        Node* curr = head;
        for(int i = 0; i < index - 1 && curr->next != nullptr; i++) {
            curr = curr->next;
        }

        Node* new_element = new Node{value, curr->next};
        curr->next = new_element;
    }
}

void delete_at(Node*& head, int index) {
    if(head == nullptr) return;
    if(index <= 0) {
        Node* del_element = head;
        head = head->next;
        delete del_element;
    } else {
        Node* curr = head;
        for(int i = 0; i < index - 1 && curr != nullptr; i++) {
            curr = curr->next;
        }

        // Preveliki indeks
        if(curr == nullptr) return;

        Node* del_element = curr->next;
        curr->next = curr->next->next;
        delete del_element;
    }
}

int main() {
    Node* head = nullptr;
    add_back(head, 1);
    add_back(head, 2);
    add_back(head, 3);

    print_list(head);

    delete_at(head, 5);

    print_list(head);

    delete_list(head);

    return 0;
}