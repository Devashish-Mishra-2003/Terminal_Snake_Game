# 🐍 Terminal Snake Game in C++

This is a simple Snake game implemented entirely in **C++**, designed to run in the terminal using minimal dependencies. It's a great beginner-level project that demonstrates fundamental programming concepts like loops, input handling, logic building, and basic data structures.

---

## 🎮 Gameplay

- Control the snake using **W (up), A (left), S (down), D (right)**.
- Eat the `*` (food) to grow the snake and increase your score.
- Avoid colliding with the wall or your own body — doing so ends the game.
- Press `X` at any time to exit the game manually.

---

## 💡 Implementation Highlights

This game is implemented using:

- **`<iostream>`** for input/output operations.
- **`<conio.h>`** for real-time key detection with `_kbhit()` and `_getch()`.
- **`<windows.h>`** for `Sleep()` and screen clearing (`system("cls")`).
- **`<vector>`** for tracking the snake's body as coordinate pairs.
- **Simple game loop** managing `Draw()`, `Input()`, and `Logic()` functions.

The code is written in a **clean and readable** manner, making it ideal for educational purposes or quick tinkering.

---

## 📁 How It Works

- The game grid is 20x20.
- The snake starts at the center and remains still until the player gives input.
- Food is randomly placed on the grid.
- The snake grows in length each time it eats food.
- Collision with the wall or self results in game over.

---

## 🛠️ To Run

Make sure you're on a **Windows environment** due to use of `<conio.h>` and `<windows.h>`.

1. Compile the code using a C++ compiler (like `g++`):

   ```bash
   g++ -o snake snake.cpp
2. Run the game:

    ./snake

Preview :

######################
#                    #
#                    #
#         O          #
#                    #
#        *           #
#                    #
######################
Score: 10
