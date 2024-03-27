#include "console.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
#define BOARD_SIZE 10
#define MOVE_DELAY 15
int snakeX = BOARD_SIZE / 2;
int snakeY = BOARD_SIZE / 2;
int dx = 0;
int dy = 0;
int score = 0;
int appleX, appleY;
bool snakeBody[BOARD_SIZE][BOARD_SIZE] = {false};
bool gameOver = false;
void initSnake() {
    snakeX = BOARD_SIZE / 2;
    snakeY = BOARD_SIZE / 2;
    dx = 0;
    dy = 0;
    snakeBody[snakeX][snakeY] = true;
}
void spawnApple() {
    srand(time(NULL));
    do {
        appleX = rand() % BOARD_SIZE;
        appleY = rand() % BOARD_SIZE;
    } while (snakeBody[appleX][appleY]); 
}
void checkGameOver() {
    if (snakeX < 0 || snakeX >= BOARD_SIZE || snakeY < 0 || snakeY >= BOARD_SIZE) {
        gameOver = true; 
    } else if (snakeBody[snakeX][snakeY]) {
        gameOver = true; 
    }
}
void updateGame() {
    snakeX += dx;
    snakeY += dy;
    if (snakeX == appleX && snakeY == appleY) {
        score += 10;
        snakeBody[appleX][appleY] = true;
        spawnApple();
    }
    for (int i = 0; i < BOARD_SIZE; ++i) {
        for (int j = 0; j < BOARD_SIZE; ++j) {
            if (!snakeBody[i][j]) continue;
            console::draw(i, j, "бс");
        }
    }
    console::draw(snakeX, snakeY, "бс");
    checkGameOver();
    if (gameOver) {
        console::draw(BOARD_SIZE / 2 - 5, BOARD_SIZE / 2, "Game Over");
        console::draw(BOARD_SIZE / 2 - 8, BOARD_SIZE / 2 + 1, "Press Enter to restart");
        console::wait();
        while (!console::key(console::K_ENTER)) {
            console::wait();
        }
        gameOver = false;
        score = 0;
        initSnake();
        spawnApple();
    }
}
void handleInput() {
    if (console::key(console::K_LEFT) && dx == 0) {
        dx = -1; dy = 0;
    }
    if (console::key(console::K_RIGHT) && dx == 0) {
        dx = 1; dy = 0;
    }
    if (console::key(console::K_UP) && dy == 0) {
        dx = 0; dy = -1; 
    }
    if (console::key(console::K_DOWN) && dy == 0) {
        dx = 0; dy = 1; 
    }
}

int main() {
    console::init();
    initSnake();
    spawnApple();

    while (true) {
        handleInput();
        updateGame();
        console::wait();
    }

    return 0;
}