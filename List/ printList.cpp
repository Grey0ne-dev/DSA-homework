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


int main() {
    
    
    ListNode<int>* head = new ListNode<int>(1);
    head->next = new ListNode<int>(2);
    head->next->next = new ListNode<int>(3);
    
    print(head);
}