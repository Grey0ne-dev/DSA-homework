#include <bits/stdc++.h>
using namespace std;


forward_list <int> * createAndFill(int N) {
    forward_list<int> * mylist= new forward_list <int>;
    for(int i = 1; i <= N ; ++i ) {
        mylist->push_front(i);
    }
    return mylist;
}

void print(forward_list <int> & arg1) {
    for(int x : arg1) {
        cout << x << ' ';
    }
    cout << endl;
}

void insert_after_position(forward_list<int> &list, size_t position, int value) {
    auto it = list.begin();
    advance(it, position);
    list.insert_after(it, value);
}

bool deleteByValue(forward_list<int> & list, int value){
    auto prev = list.before_begin();
    auto curr = list.begin();

    while (curr != list.end()) {
        if (*curr == value) {
            curr = list.erase_after(prev);
            return true;
        } else {
            prev = curr;
            curr++;
        }
    }
    return false;
}

forward_list<int> & merge(forward_list<int> &first, forward_list<int> &second) {
    first.merge(second);
    return first;
}


void moveElementToFront(forward_list<int> & list, int value) {
    int i = 0;
    while(deleteByValue(list, value)) {
        i++;
    }
    while(i) {
        list.push_front(value);
        i--;
    }
}

bool isEven(int x) {
    return !(x&1);
}

template <typename F>
void deleteif(std::forward_list<int>& list, F foo) {
    auto prev = list.before_begin();
    auto curr = list.begin();

    while (curr != list.end()) { // inadu em mechy kanchum vor update anem
        if (foo(*curr)) {
            curr = list.erase_after(prev);
        } else {
            ++prev;
            ++curr;
        }
    }
}

void insertionSort(forward_list<int>& list) {
    if (list.empty() || list.begin() == list.end()) return;

    forward_list<int> sorted;
    for (int x : list) {
        auto prev = sorted.before_begin();
        auto it = sorted.begin();

        while (it != sorted.end() && *it < x) {
            ++prev;
            ++it;
        }
        sorted.insert_after(prev, x);
    }
    list = move(sorted);
}


int main() {
	
	forward_list <int> * spawnedList1 = createAndFill(10);
	deleteif(*spawnedList1, isEven);
	insertionSort(*spawnedList1);
	print(*spawnedList1);
    delete spawnedList1;
}