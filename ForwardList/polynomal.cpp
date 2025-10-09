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

void insertionSort(forward_list<pair<int,double>>& list) {
    if (list.empty() || list.begin() == list.end()) return;

    forward_list<pair<int,double>> sorted;
    for (const auto& x : list) {
        auto prev = sorted.before_begin();
        auto it = sorted.begin();

        while (it != sorted.end() && it->first < x.first) {
            ++prev;
            ++it;
        }
        sorted.insert_after(prev, x);
    }
    list = move(sorted);
}

class Polynomial {
    forward_list<pair<int,double>> list;

public:
    void addTerm(int degree, double coefficient) {
        if (coefficient == 0) return;
        list.push_front({degree, coefficient});
        insertionSort(list);
    }

    double evaluate(double x) const {
        double sum = 0;
        for (const auto& term : list) {
            sum += term.second * pow(x, term.first);
        }
        return sum;
    }

    Polynomial derivative() const {
        Polynomial result;
        for (const auto& term : list) {
            if (term.first > 0) {
                result.addTerm(term.first - 1, term.first * term.second);
            }
        }
        return result;
    }

    void print() const {
        for (const auto& term : list) {
            cout << term.second << "x^" << term.first << " ";
        }
        cout << "\n";
    }
};



int main() {
	
	Polynomial p;
    p.addTerm(2, 3);
    p.addTerm(0, 5);
    p.addTerm(1, 4);
    p.print();
    cout << "p(2) = " << p.evaluate(2) << "\n";

    Polynomial d = p.derivative();
    d.print();
}