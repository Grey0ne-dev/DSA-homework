#include <iostream>

template <typename T>
struct ListNode {
    T data;
    ListNode* next;
    
    explicit ListNode(T val, ListNode* next = nullptr) : data(val), next(next) {}
};

template <typename T>
void print(ListNode<T>* head) {
    if(!head) {
        std::cout << "nullptr\n";
        return;
    }
    std::cout << head->data << " -> ";
    print(head->next);
}

template <typename T>
void clear(ListNode<T>* head) {
    if(!head) {
        return;
    }
    clear(head->next);
    delete head;
}

template <typename T>
void deleteNext(ListNode<T>* head) {
    if (!head || !head->next) return;
    ListNode<T>* tmp = head->next;
    head->next = head->next->next;
    delete tmp;
}

template <typename T>
bool findNode(ListNode<T>* head, T val) {
    if(!head) {
        return false;
    }
    return (head->data == val) || findNode(head->next, val);
}

template <typename T>
void deleteByValue(ListNode<T>*& head, T value) {
    if (!head) return;
    
    if (head->data == value) {
        ListNode<T>* temp = head;
        head = head->next;
        delete temp;
        return;
    }
    
    ListNode<T>* current = head;
    while (current->next && current->next->data != value) {
        current = current->next;
    }
    
    if (current->next && current->next->data == value) {
        deleteNext(current);
    }
}


template <typename T>
ListNode<T>* createList(T last) {
    return new ListNode<T>(last);
}


template <typename T, typename... Args>
ListNode<T>* createList(T first, Args... rest) {
    return new ListNode<T>(first, createList(rest...));
}

int main() {
    
    ListNode<int>* head1 = createList(1, 2, 3);
    ListNode<double>* head2 = createList(1.1, 2.2, 3.3);
    print(head1);
    print(head2);
    
    
    clear(head1);
    clear(head2);
    
    return 0;
}