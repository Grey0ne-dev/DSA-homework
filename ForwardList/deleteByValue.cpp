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

void deleteByValue(forward_list<int> & list, int value){
    auto prev = list.before_begin();
    auto curr = list.begin();

    while (curr != list.end()) {
        if (*curr == value) {
            curr = list.erase_after(prev);
            return;
        } else {
            prev = curr;
            curr++;
        }
    }
}


int main() {
	
	forward_list <int> * spawnedList = createAndFill(10);
	insert_after_position(*spawnedList, 2, 8);
	print(*spawnedList);
	deleteByValue(*spawnedList, 8);
	print(*spawnedList);
    delete spawnedList;
}