#include <bits/stdc++.h>
using namespace std;

    class Logger {
        deque<string> messages;
        size_t max;
        public:
        explicit Logger(size_t i) : max(i) {}
        void add(string m) {
            messages.push_front(m);
            if(messages.size() > max) {
                messages.pop_back();
            }
        }
        void print() {
            for(string x : messages) {
                cout << x << ' ';
            }
        }
        
    };

int main() {
	
	Logger l(3);
	l.add("message 1");
	l.add("message 2");
	l.add("message 3");
	l.add("message 4");
	l.add("message 5");
	l.print();
    
}
