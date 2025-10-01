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
void deleteNext(ListNode <T> * head){
    ListNode <T> * tmp = head->next;
    head->next = head->next->next;
    delete tmp;
}

template <typename T>
bool findNode(ListNode <T> * head, T val) {
    if(!head) {
        return false;
    }
    return (head->data == val) || findNode(head->next, val);
}

template <typename T>
void deleteByValue(ListNode <T> * head, T value) {
    bool check = findNode(head, value);
    if(!check) {
        return;
    }
    
    if(head->data == value) {
        head->next = nullptr;
        delete head;
        return;
    }
    while(head->next->data != value) {
        head = head->next;
    }
    deleteNext(head);
}

int main() {
    
    
    ListNode<int>* head = new ListNode<int>(1);
    head->next = new ListNode<int>(2);
    head->next->next = new ListNode<int>(3);
    
    print(head);
    deleteByValue(head,8);
    deleteByValue(head,2);
    print(head);
    
    
    
    clear(head);
}