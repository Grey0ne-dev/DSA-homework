#include <bits/stdc++.h>
using namespace std;

    deque<int>* createAndFillDeque(int N) {
        deque<int> * mydeque = new deque<int>;
        for(int i = 1; i < N; ++i){
            (!(i&1))? mydeque->push_front(i) : mydeque->push_back(i);
        }
        return mydeque;
    }
    
    void print(deque<int> d) {
        for (int x : d) {
            cout << x << ' ';
        }
        cout << '\n';
    }
    
    void removeFromBothEnds(deque<int> & d, int N) {
        for(int i = 0; i < N ; i++) {
            d.pop_back();
            d.pop_front();
        }
    }

int main() {
	
    deque<int> * d = createAndFillDeque(15);
    removeFromBothEnds(*d,4);
    print(*d);
}
