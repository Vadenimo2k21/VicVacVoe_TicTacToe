#include "cpu.h"

bool checkWin(char sign) {
    if (field[1] == sign && field[2] == sign && field[3] == sign ||
        field[1] == sign && field[4] == sign && field[7] == sign ||
        field[1] == sign && field[5] == sign && field[9] == sign ||
        field[2] == sign && field[5] == sign && field[8] == sign ||
        field[3] == sign && field[6] == sign && field[9] == sign ||
        field[3] == sign && field[5] == sign && field[7] == sign ||
        field[4] == sign && field[5] == sign && field[6] == sign ||
        field[7] == sign && field[8] == sign && field[9] == sign)
        return true;
    return false;
}

bool checkFull() {
    for (int i = 1; i < 10; i++) {
        if (field[i] == ' ') return false;
    }
    return true;
}

void CPU(int difficulty) {
    if (checkFull()) return;
    srand(time(nullptr));
    if (difficulty == 1) {
        // Logik für Easy.
        int check = rand() % 3;
        if (check != 1) {
            for (int i = 1; i < 10; i++) {
                if (field[i] == ' ') {
                    field[i] = 'O';
                    if (checkWin('O')) return;
                    else field[i] = ' ';
                }
            }
        }
        if (check != 2) {
            for (int i = 1; i < 10; i++) {
                if (field[i] == ' ') {
                    field[i] = 'X';
                    if (checkWin('X')) {
                        field[i] = 'O';
                        return;
                    }
                    else field[i] = ' ';
                }
            }
        }
        while (true) {
            int i = rand() % 9 + 1;
            if (field[i] == ' ') {
                field[i] = 'O';
                return;
            }
        }
    }
    if (difficulty == 2) {
        // Logik für Medium.
        int check = rand() % 5 + 1;
        if (check != 3) {
            for (int i = 1; i < 10; i++) {
                if (field[i] == ' ') {
                    field[i] = 'O';
                    if (checkWin('O')) return;
                    else field[i] = ' ';
                }
            }
        }
        else if (check != 4) {
            for (int i = 1; i < 10; i++) {
                if (field[i] == ' ') {
                    field[i] = 'X';
                    if (checkWin('X')) {
                        field[i] = 'O';
                        return;
                    }
                    else field[i] = ' ';
                }
            }
        }
        while (true) {
            int i = rand() % 9 + 1;
            if (field[i] == ' ') {
                field[i] = 'O';
                return;
            }
        }
    }
    if (difficulty == 3) {
        // Logik für Hard.
        for (int i = 1; i < 10; i++) {
            if (field[i] == ' ') {
                field[i] = 'O';
                if (checkWin('O')) return;
                else field[i] = ' ';
            }
        }
        for (int i = 1; i < 10; i++) {
            if (field[i] == ' ') {
                field[i] = 'X';
                if (checkWin('X')) {
                    field[i] = 'O';
                    return;
                }
                else field[i] = ' ';
            }
        }
        int middleField = rand() % 4;
        if (field[5] == ' ' && middleField != 1) {
            field[5] = 'O';
            return;
        }
        while (true) {
            srand(time(nullptr));
            int i = rand() % 9 + 1;
            if (field[i] == ' ') {
                field[i] = 'O';
                return;
            }
        }
    }
    else return;
}
