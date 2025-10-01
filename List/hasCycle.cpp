#include <iostream>
#include <cmath>

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
size_t listLength(ListNode<T> * head) {
    if(!head) {
        return 0;
    }
    return 1 + listLength(head -> next);
}

template <typename T>
ListNode<T>* createList(T last) {
    return new ListNode<T>(last);
}


template <typename T, typename... Args>
ListNode<T>* createList(T first, Args... rest) {
    return new ListNode<T>(first, createList(rest...));
}

int calc(ListNode<int> * head, int base, int deg) {
    if(deg == 0) {
        return head->data * pow(base, deg);
    }
    return head->data * pow(base, deg) + calc(head->next, 2, --deg);
}

int toDecimal(ListNode<int> * head) {
    int base = 2;
    int deg = listLength(head) - 1;
    return calc(head, base, deg); 
}

template <typename T>
ListNode<T> * findMiddle(ListNode<T> * head) {
    if(!head->next) {return head;}
    ListNode<T> * slow = head;
    ListNode<T> * fast = head->next;
    while(fast && fast->next) {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

template<typename T>
bool hasCycle(ListNode<T> * head) {
    if(!head->next) {return false;}
    ListNode<T> * slow = head;
    ListNode<T> * fast = head->next;
    while(fast != slow) {
        if(!fast || !fast->next) {return false;}
        fast = fast->next->next;
        slow = slow->next;
    }
    return true;
}

template <typename T>
void addNode(ListNode <T> * head, ListNode<T> * tail) {
    while(head->next) {
        head = head->next;
    }
    head -> next = tail;
}

int main() {
    
    ListNode<int>* head1 = createList(1, 2, 3, 4, 5, 6, 7, 8);
    print(head1);
    std::cout <<  std::boolalpha << hasCycle(head1) << '\n';
    addNode(head1, head1);
    std::cout <<  std::boolalpha << hasCycle(head1) << '\n';
    //clear(head1); gmpaluya vor bacem ;)
    
    return 0;
}