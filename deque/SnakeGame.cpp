#include <iostream>
#include <deque>
#include <vector>
#include <chrono>
#include <thread>
#include <cstdlib>
#include <ctime>
#include <limits>
#include <queue>
using namespace std;

class Game {
private:
    int WIDTH = 50;
    int HEIGHT = 20;
    vector<vector<char>> map;
    deque<pair<int, int>> snake;
    pair<int, int> apple;
    char lastDir;
    bool gameOver;
    int score;
    queue<char> inputBuffer;
    
    void initializeMap() {
        map.resize(HEIGHT, vector<char>(WIDTH, '.'));
        for (int i = 0; i < HEIGHT; i++)
            for (int j = 0; j < WIDTH; j++)
                if (i == 0 || i == HEIGHT - 1 || j == 0 || j == WIDTH - 1)
                    map[i][j] = '#';
    }
    
    void initializeSnake() {
        snake.clear();
        int startX = WIDTH / 2, startY = HEIGHT / 2;
        snake.push_back({startY, startX});
        snake.push_back({startY, startX - 1});
        snake.push_back({startY, startX - 2});
        snake.push_back({startY, startX - 3});
    }
    
    void spawnApple() {
        int x, y;
        bool valid = false;
        while (!valid) {
            x = rand() % (WIDTH - 2) + 1;
            y = rand() % (HEIGHT - 2) + 1;
            valid = true;
            for (auto &p : snake)
                if (p.first == y && p.second == x)
                    valid = false;
        }
        apple = {y, x};
    }
    
    void updateMap() {
        for (int i = 1; i < HEIGHT - 1; i++)
            for (int j = 1; j < WIDTH - 1; j++)
                map[i][j] = '.';
        for (size_t i = 0; i < snake.size(); i++) {
            int y = snake[i].first, x = snake[i].second;
            map[y][x] = (i == 0) ? '@' : '&';
        }
        map[apple.first][apple.second] = '$';
    }
    
    void display() {
        #ifdef _WIN32
            system("cls");
        #else
            system("clear");
        #endif
        cout << "Snake Game - Score: " << score << endl;
        cout << "Use WASD to move, Q to quit" << endl;
        cout << "Input Buffer: " << inputBuffer.size() << endl << endl;
        for (int i = 0; i < HEIGHT; i++) {
            for (int j = 0; j < WIDTH; j++)
                cout << map[i][j];
            cout << endl;
        }
    }
    
    bool isValidMove(char newDir) {
        return !((lastDir == 'w' && newDir == 's') ||
                 (lastDir == 's' && newDir == 'w') ||
                 (lastDir == 'a' && newDir == 'd') ||
                 (lastDir == 'd' && newDir == 'a'));
    }

    void processInput() {
        if (cin.rdbuf()->in_avail() > 0) {
            string input;
            getline(cin, input);
            for (char c : input) {
                c = tolower(c);
                if (c == 'q') { gameOver = true; return; }
                if ((c == 'w' || c == 'a' || c == 's' || c == 'd') && isValidMove(c))
                    if (inputBuffer.size() < 10) inputBuffer.push(c);
            }
        }
    }
    
    char getNextInput() {
        if (!inputBuffer.empty()) {
            char next = inputBuffer.front();
            inputBuffer.pop();
            return next;
        }
        return lastDir;
    }

public:
    Game() : lastDir('d'), gameOver(false), score(0) {
        srand(time(0));
        initializeMap();
        initializeSnake();
        spawnApple();
        updateMap();
    }
    
    void makeMove(char dir) {
        if (gameOver) return;
        lastDir = dir;
        int y = snake.front().first, x = snake.front().second;
        if (dir == 'w') y--; else if (dir == 's') y++; else if (dir == 'a') x--; else if (dir == 'd') x++;
        if (x <= 0 || x >= WIDTH - 1 || y <= 0 || y >= HEIGHT - 1) { gameOver = true; return; }
        for (auto &s : snake)
            if (s.first == y && s.second == x) { gameOver = true; return; }
        snake.push_front({y, x});
        if (y == apple.first && x == apple.second) { score += 10; spawnApple(); }
        else snake.pop_back();
        updateMap();
    }
    
    void run() {
        int frame = 0;
        cin.tie(nullptr);
        ios_base::sync_with_stdio(false);
        while (!gameOver) {
            processInput();
            makeMove(getNextInput());
            display();
            if (frame++ >= 40) { spawnApple(); frame = 0; }
            this_thread::sleep_for(chrono::milliseconds(200));
        }
        display();
        cout << "\nGame Over! Final Score: " << score << endl;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin.get();
    }
};

int main() {
    Game game;
    game.run();
    return 0;
}

