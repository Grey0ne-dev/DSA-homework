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


int main() {
	
	forward_list <int> * spawnedList = createAndFill(10);
	print(*spawnedList);

}
