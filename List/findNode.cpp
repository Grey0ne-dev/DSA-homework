#include <iostream>

template <typename T>
struct ListNode {
    T data;
    ListNode* next;
    
    explicit ListNode(T val) : data(val), next(nullptr) {}
};

template <typename T>
void print (ListNode <T> * head) {
    if(!head) {
        std::cout << "nullptr\n";
        return;
    }
    std::cout << head->data << " -> ";
    print(head->next);
}

template <typename T>
void clear(ListNode <T> * head) {
    if(!head) {
        return;
    }
    clear(head->next);
    delete head;
}

template <typename T>
size_t listLength(ListNode <T> * head) {
    if(!head) {
        return 0;
    }
    return 1 + listLength(head->next);
}

template <typename T>
bool findNode(ListNode <T> * head, T val) {
    if(!head) {
        return false;
    }
    return (head->data == val) || findNode(head->next, val);
}

int main() {
    
    
    ListNode<int>* head = new ListNode<int>(1);
    head->next = new ListNode<int>(2);
    head->next->next = new ListNode<int>(3);
    
    std::cout << std::boolalpha << findNode(head, 4) << '\n';
    std::cout << std::boolalpha << findNode(head, 1) << '\n';
    std::cout << std::boolalpha << findNode(head, 0) << '\n';
    clear(head);
}