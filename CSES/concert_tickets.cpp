#include <iostream>
#include <set>

void process(int ticketcount, int customers) {
	std::multiset<int> tickets;

	for (int i = 0; i < ticketcount; i++) {
		int t;
		std::cin >> t;
		tickets.insert(t);
	}

	for (int i = 0; i < customers; i++) {
		int q;
		std::cin >> q;

		if (tickets.empty()) {
			std::cout << -1 << "\n";
			continue;
		}

		auto it = tickets.upper_bound(q);

		if (it == tickets.begin()) {
			std::cout << -1 << "\n";
		} else {
			--it;
			std::cout << *it << "\n";
			tickets.erase(it);
		}
	}
}

int main() {
	int n, m;
	std::cin >> n >> m;
	process(n, m);
}
