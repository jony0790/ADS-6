// Copyright 2022 NNTU-CS
#pragma once

struct SYM {
    char ch;
    int prior;
};

template <typename T>
class TPQueue {
 private:
    struct Node {
        T data;
        Node* next;

        Node(const T& value) {
            data = value;
            next = nullptr;
        }
    };

    Node* head;

 public:
    TPQueue() {
        head = nullptr;
    }

    ~TPQueue() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void push(const T& value) {
        Node* newNode = new Node(value);

        // boshiga qo'shish
        if (head == nullptr || value.prior > head->data.prior) {
            newNode->next = head;
            head = newNode;
            return;
        }

        Node* current = head;

        // FIFO uchun >= kerak
        while (current->next != nullptr &&
               current->next->data.prior >= value.prior) {
            current = current->next;
        }

        newNode->next = current->next;
        current->next = newNode;
    }

    T pop() {
        Node* temp = head;
        T value = head->data;

        head = head->next;

        delete temp;

        return value;
    }
};
