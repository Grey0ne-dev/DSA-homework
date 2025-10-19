#include <bits/stdc++.h>
using namespace std;

int timeRequiredToBuy(vector<int> tickets, int K) {
    int res = 0;
    queue<pair<int,int>> tics;

    for(int i = 0; i < tickets.size(); i++) tics.push({i, tickets[i]});

    while(2) {
        auto cur = tics.front(); 
        tics.pop();
        if(cur.second > 0) {
            cur.second--;
            res++;
        }
        if(cur.second > 0) {
            tics.push(cur);
        }

        if(cur.first == K && cur.second == 0) break;
    }

    return res;
}



int main() {
	std::vector<int> tickets1 = {2, 3, 2};
    std::cout << timeRequiredToBuy(tickets1, 2) << '\n';  // 6
}