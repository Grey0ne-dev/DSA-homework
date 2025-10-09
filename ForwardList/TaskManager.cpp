#include <bits/stdc++.h>
using namespace std;

class TaskManager {
    vector <forward_list<string>> taskList;
    public:
    TaskManager(size_t maxPriority = 10) : taskList(maxPriority + 1) {}
    void addTask(size_t priority, const string& name) {
        if (taskList.empty()) return;
        size_t index = (priority >= taskList.size()) ? taskList.size() - 1 : priority;
        taskList.at(index).push_front(name);
    }

    void getNextTask() {
        for (int i = 0; i < taskList.size() ; i++ ) {
            if(!taskList.at(i).empty()) {
                taskList.at(i).pop_front();
                break;
            }
        }
    }
    void removeTask(int priority, string name) {
        if (priority < 0 || priority >= taskList.size()) {
            return;
        }
        
        auto& list = taskList[priority];
        auto prev = list.before_begin();
        auto curr = list.begin();
        
        while (curr != list.end()) {
            if (*curr == name) {
                list.erase_after(prev);
                return;
            } else {
                prev = curr;
                curr++;
            }
        }
    }
    void print() {
        int n = taskList.size();
        for (int i = 0; i < n ; ++i ) {
            for (string s : taskList.at(i)) {
                std::cout << '[' << i << ']' << s << '\n';
            }
        }
    }
};

int main() {
	TaskManager tm(5);
    
    tm.addTask(1, "Write code");
    tm.addTask(2, "Debug");
    tm.addTask(1, "Test");
    tm.addTask(0, "Urgent task");
    
    cout << "All tasks:" << endl;
    tm.print();
    
    cout << "\nNext task to process:" << endl;
    tm.getNextTask();
    
    cout << "\nRemaining tasks:" << endl;
    tm.print();
    
    cout << "\nRemoving 'Debug' from priority 2:" << endl;
    tm.removeTask(2, "Debug");
    tm.print();
    
    return 0;

}
