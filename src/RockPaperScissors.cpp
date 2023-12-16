#include <iostream>
#include <windows.h>

// Prototypes
void printChoice(char choiceChar);
char getPlayerChoice();
char getComputerChoice();
void printWinner(char player, char computer);

// main method
int main(int argc, char const *argv[])
{
    char player, computer;

    player = getPlayerChoice();
    std::cout << "Generating computer's choice...\n";
    Sleep(2000);
    computer = getComputerChoice();

    printWinner(player, computer);

    return 0;
}

// gets the player's input
char getPlayerChoice()
{
    char playerChar;
    do
    {
        std::cout << "\x1B[2J\x1B[H";
        std::cout << "########## Rock-Paper-Scissors ##########\n";
        std::cout << "Enter your choice (r -> Rock | p -> Paper | s -> scissors): ";
        std::cin >> playerChar;

        if (playerChar != 'r' && playerChar != 'p' && playerChar != 's')
        {
            std::cout << "Invalid operation! Try again.\n";
            Sleep(1000);
        }
    } while (playerChar != 'r' && playerChar != 'p' && playerChar != 's');

    std::cout << "You have chosen -> ";
    printChoice(playerChar);
    return playerChar;
}

// gets the computer's input
char getComputerChoice()
{
    srand(time(NULL));
    int computerInt = rand() % 3;

    char computerChar;
    switch (computerInt)
    {
    case 0:
        computerChar = 'r';
        break;
    case 1:
        computerChar = 'p';
        break;
    case 2:
        computerChar = 's';
        break;
    }

    std::cout << "Computer has chosen -> ";
    printChoice(computerChar);
    return computerChar;
}

// prints out the choice
void printChoice(char choiceChar)
{
    std::string choiceString;
    switch (choiceChar)
    {
    case 'r':
        choiceString = "Rock";
        break;
    case 'p':
        choiceString = "Paper";
        break;
    case 's':
        choiceString = "Scissors";
        break;
    }

    std::cout << choiceString + "\n";
}

// tests for the winner
void printWinner(char player, char computer)
{
    if (player == computer)
    {
        std::cout << "DRAW";
    }
    else if ((player == 'r' && computer == 's') || (player == 'p' && computer == 'r') || (player == 's' && computer == 'p'))
    {
        std::cout << "Player wins!";
    }
    else if ((computer == 'r' && player == 's') || (computer == 'p' && player == 'r') || (computer == 's' && player == 'p'))
    {
        std::cout << "Computer wins!";
    }
}