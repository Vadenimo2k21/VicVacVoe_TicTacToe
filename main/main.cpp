#include <iostream>
#include <stdlib.h>
#include <time.h>

char field[10];

void singleplayer();
void multiplayer();
void help();
bool checkFull();
bool checkWin(char);
char keyInput(bool x);

void consoleClear() { // Diese Funktion beendet den angezeigten Inhalt des Programms. Dies wird für später benötigt, um das Spiel zu beenden.

    system("cls");

}

void fieldReset() { // Diese Funktion soll das Spielfeld nach Beendigung eines Spiels zurücksetzen.

    for (int i = 0; i < 10; i++) {
        field[i] = ' ';
    }

}

void menu() {
   
    while (true) { 
        fieldReset(); // Nach dem Spiel landen wir im Hauptmenü, dementsprechend wird mit dieser Endlosschleife das Spielfeld zurückgesetzt. fieldReset(); ginge auch nach dem Spiel, aber es wurde ins Hauptmenü gepackt.
        char inputmenu;
        
        std::cout << "\n\n";
        std::cout << "GAME MENU:\n\n";
        std::cout << "1: Singleplayer\n";
        std::cout << "2: Local Multiplayer\n";
        std::cout << "3: Help\n";
        std::cout << "4: Quit\n\n";
        std::cout << "Input: ";
        
        std::cin >> inputmenu;
        
        if (inputmenu == '1')singleplayer();
        else if (inputmenu == '2')multiplayer();
        else if (inputmenu == '3')help();
        else if (inputmenu == '4' || inputmenu == 'q' || inputmenu == 'Q')return;
        else { consoleClear(); std::cout << "Input invalid.\nPlease try again.\n"; }
    }
}

void fieldDraw() { // Mit dieser Funktion wird das Spielfeld gezeichnet. Diese Funktion wird benötigt, um das Spielfeld anzeigen zu lassen.
    consoleClear();
    std::cout << "\n\n\n";
    std::cout << "        " << field[1] << " |  " << field[2] << "  | " << field[3] << std::endl;
    std::cout << "      --- | --- | ---       " << std::endl;
    std::cout << "        " << field[4] << " |  " << field[5] << "  | " << field[6] << std::endl;
    std::cout << "      --- | --- | ---       " << std::endl;
    std::cout << "        " << field[7] << " |  " << field[8] << "  | " << field[9] << std::endl;
    std::cout << std::endl;
}

void singleplayer() {
    consoleClear();
}

void multiplayer() {
    consoleClear();
    char input = ' ';
    bool player1Turn = true;
    while (true)
    {
        fieldDraw();
        if (checkWin('X'))
        {
            std::cout << "\nPlayer 1 has won. Congratulations!\n\n";
            return;
        }
        else if (checkWin('O'))
        {
            std::cout << "\n Player 2 has won. Congratulations!\n\n";
            return;
        }
        if (checkFull())
        {
            std::cout << "Tie.\n\n";
        }
        input = keyInput(player1Turn);
        if (input == 'q' || input == 'Q')return;
        player1Turn = !player1Turn;
    }
}

void help() {
    
    consoleClear();
    std::cout << "HELP MENU:\n\nSingleplayer:\n\nIn this mode, you will play a game against a computer player.\nYou, as the player, are using X. The computer is using O.\n\n\nLocal Multiplayer:\n\nIn this mode, two players can play on one computer by pressing in each turn on the computer keyboard. Player 1 is using X. Player 2 is using O.\n\n\nControls:\n\nTo choose a field, you must choose a number between 1 and 9.\nThe first field is on top left, the second in the middle of the top, and the third is on the top right.\nThe fourth field is in the middle on the left, the fifth in the middle, and the sixth in the middle on the right.\nThe seventh field is on the bottom left, the eight in the middle of the bottom, and the ninth is on the bottom right. \n\n";
    return;

}

char keyInput(bool x)
{
    while (true)
    {
        std::cout << "\n\nInput: ";
        char input = ' ';
        std::cin >> input;
        int inputNumber = input - '0';
        if (inputNumber > 9 || inputNumber < 1)
        {
            if (input == 'q' || input == 'Q')
                return input;
            else
                std::cout << "Input invalid.\nPlease try again.\n";
        }
        else if (field[inputNumber] != ' ')
        {
            std::cout << "\nThis field is already used.";
        }
        else
        {
            if (x)
                field[inputNumber] = 'X';
            else
                field[inputNumber] = 'O';
            return input;
        }
    }
}

bool checkWin(char sign) {
    if (field[1] == sign && field[2] == sign && field[3] == sign || field[1] == sign && field[4] == sign && field[7] == sign || field[1] == sign && field[5] == sign && field[9] == sign || field[2] == sign && field[5] == sign && field[8] == sign || field[3] == sign && field[6] == sign && field[9] == sign || field[3] == sign && field[5] == sign && field[7] == sign || field[4] == sign && field[5] == sign && field[6] == sign || field[7] == sign && field[8] == sign && field[9] == sign)return true;
    return false; // Keine Siegesbedingung.
}

bool checkFull() {
    for (int i = 1; i < 10, i++;) {
        if (field[i] == ' ')return false; // Freies Feld.
    }
    return true; // Volles Feld.
}

int main()
{
    std::cout << "Welcome to VicVacVoe.\nA TicTacToe game programmed by Vadenimo in the programming language C++.\nSpecial Thanks to Pilzschaf for his tutorials on YouTube, and to kevleybauz for answering C++ questions.";
    menu();
    return 0;
}
