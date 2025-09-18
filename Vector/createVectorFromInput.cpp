#include <iostream>
#include <vector>
#include <stdexcept>


std::vector<int> createVectorFromInput() {

	std::vector<int> res;
	while(1) {

		int i;
		std::cin >> i;
		if(i != 0) {
			res.push_back(i);
		}
		else {
			break;
		}
	}
	return res;
}

int main () {

    std::vector<int> vec = createVectorFromInput();
    for(int i : vec) {
        std::cout << i << ' ';
    }
    
	return 0;
}