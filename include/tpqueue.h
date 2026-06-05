// Copyright 2026

#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

struct SYM {
    char ch;
    int prior;
};

template <class T>
class TPQueue {
 private:
    struct Node {
        T data;
        Node* next;

        explicit Node(const T& value)
            : data(value), next(nullptr) {
        }
    };

    Node* head;

 public:
    TPQueue()
        : head(nullptr) {
    }

    ~TPQueue() {
        while (head != nullptr) {
            Node* tmp = head;
            head = head->next;
            delete tmp;
        }
    }

    void push(const T& value) {
        Node* node = new Node(value);

        if (head == nullptr ||
            value.prior > head->data.prior) {
            node->next = head;
            head = node;
            return;
        }

        Node* cur = head;

        while (cur->next != nullptr &&
               cur->next->data.prior >= value.prior) {
            cur = cur->next;
        }

        node->next = cur->next;
        cur->next = node;
    }

    T pop() {
        Node* tmp = head;
        T value = head->data;

        head = head->next;
        delete tmp;

        return value;
    }
};

#endif  // INCLUDE_TPQUEUE_H_
