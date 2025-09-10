#include <iostream>
using namespace std;


class Logger {
    string space;
    public:
    Logger(int n) {
        for(int i = 0; i < n ; i++ ) {
            space += ' ';
        }
    }
        
    void l0g(){
        cout << '\n';   
    }
    template <typename T, typename... Rest >
    void l0g(T first, Rest... rest) {
        cout << space << first << '\n'; 
        l0g(rest...);
    }
};


int main() {
	Logger logger(19);
	logger.l0g("Gentoo", "Lover");

}
