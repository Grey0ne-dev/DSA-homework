#include <bits/stdc++.h>
using namespace std;

    void createAndFillDeque(int N) {
        deque<int> mydeque;
        for(int i = 1; i < N; ++i){
            (!(i&1))? mydeque.push_front(i) : mydeque.push_back(i);
        }
        for(int x : mydeque) {
            cout << x << ' ';
        }
        cout << '\n';
    }

int main() {
	
    createAndFillDeque(15);
}
