#include <bits/stdc++.h>
using namespace std;


string hotPotato(vector<string> players, int K) {
    queue<string> pl;
    for(auto player : players) pl.push(player);
    K %= players.size();
    while(pl.size() > 1) {
        for(int i = 0; i < K; ++i ) {
            pl.push(pl.front());
            pl.pop();
        }
        pl.pop();
    }
    return pl.front();
}


int main() {
	std::vector<std::string> players = {"Alice", "Bob", "Charlie", "David"};
    std::cout << hotPotato(players, 7) << '\n';  // победитель

}
