#include <iostream>
#include <set>
#include <vector>

std::vector<int> vectorize(int n) {
	using namespace std;
    vector<int> cubes(n);
    for (int i = 0; i < n; i++) {
        cin >> cubes[i];
    }
	return cubes;
}

int getTowersCount(std::vector<int> cubes) {
    using namespace std;
	multiset<int> tops;
    for (int cube : cubes) {
      
        auto it = tops.upper_bound(cube);
        
        if (it != tops.end()) {
           
            tops.erase(it);
        }
        tops.insert(cube);
    }
    
    return tops.size();
}

void solve() {
	int n;
	std::cin >> n;
	std::vector<int> cubes = vectorize(n);
	std::cout << getTowersCount(cubes) << std::endl;	
}


int main () {
	solve();
}

