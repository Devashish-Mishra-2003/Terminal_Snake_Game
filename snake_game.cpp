#include <iostream>
#include <conio.h>      
#include <windows.h>    
#include <vector>
#include <ctime>
using namespace std;

const int width = 20;
const int height = 20;
bool gameOver;
int x, y, foodX, foodY, score;
int dx, dy;
vector<pair<int, int>> snake;

enum Direction { STOP = 0, LEFT, RIGHT, UP, DOWN };
Direction dir;

void Setup() {
    gameOver = false;
    dir = STOP;
    x = width / 2;
    y = height / 2;
    snake.clear();
    snake.push_back({x, y});
    foodX = rand() % width;
    foodY = rand() % height;
    score = 0;
}

void Draw() {
    system("cls"); 

    for (int i = 0; i < width + 2; i++) cout << "#";
    cout << endl;

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (j == 0) cout << "#";

            bool printed = false;
            if (i == y && j == x) {
                cout << "O"; 
                printed = true;
            } else if (i == foodY && j == foodX) {
                cout << "*"; 
                printed = true;
            } else {
                for (int k = 1; k < snake.size(); k++) {
                    if (snake[k].first == j && snake[k].second == i) {
                        cout << "o"; 
                        printed = true;
                        break;
                    }
                }
            }

            if (!printed) cout << " ";
            if (j == width - 1) cout << "#";
        }
        cout << endl;
    }

    for (int i = 0; i < width + 2; i++) cout << "#";
    cout << endl;
    cout << "Score: " << score << endl;
}

void Input() {
    if (_kbhit()) {
        switch (_getch()) {
            case 'a': dir = LEFT; break;
            case 'd': dir = RIGHT; break;
            case 'w': dir = UP; break;
            case 's': dir = DOWN; break;
            case 'x': gameOver = true; break;
        }
    }
}

void Logic() {
    if (dir == STOP) return;

    for (int i = snake.size() - 1; i > 0; i--) {
        snake[i] = snake[i - 1];
    }

    switch (dir) {
        case LEFT: x--; break;
        case RIGHT: x++; break;
        case UP: y--; break;
        case DOWN: y++; break;
    }

    snake[0] = {x, y};

    if (x >= width || x < 0 || y >= height || y < 0)
        gameOver = true;

    for (int i = 1; i < snake.size(); i++) {
        if (snake[i].first == x && snake[i].second == y)
            gameOver = true;
    }

    if (x == foodX && y == foodY) {
        snake.push_back({-1, -1}); 
        score += 10;
        foodX = rand() % width;
        foodY = rand() % height;
    }
}

int main() {
    srand(time(0));
    Setup();
    cout << "Press any direction key (W/A/S/D) to start..." << endl;
    while (dir == STOP) {
    Input(); // wait for valid direction
    }
    while (!gameOver) {
        Draw();
        Input();
        Logic();
        Sleep(100); 
    }

    cout << "Game Over! Final Score: " << score << endl;
    system("pause");
    return 0;
}