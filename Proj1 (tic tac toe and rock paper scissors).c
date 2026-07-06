#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char board[3][3];
char currentPlayer = 'X';

void initializeBoard() {
 for (int i = 0; i < 3; i++) {
 for (int j = 0; j < 3; j++) {
 board[i][j] = ' ';
 }
 }
}

void displayBoard() {
 printf("\n");
 printf(" %c | %c | %c\n", board[0][0], board[0][1], board[0][2]);
 printf("---|---|---\n");
 printf(" %c | %c | %c\n", board[1][0], board[1][1], board[1][2]);
 printf("---|---|---\n");
 printf(" %c | %c | %c\n", board[2][0], board[2][1], board[2][2]);
 printf("\n");
}

int checkWin() {
 // Check rows
 for (int i = 0; i < 3; i++) {
 if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ') {
 return 1;
 }
 }
 
 // Check columns
 for (int j = 0; j < 3; j++) {
 if (board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[0][j] != ' ') {
 return 1;
 }
 }
 
 // Check diagonals
 if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') {
 return 1;
 }
 
 if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ') {
 return 1;
 }
 
 return 0;
}

int checkDraw() {
 for (int i = 0; i < 3; i++) {
 for (int j = 0; j < 3; j++) {
 if (board[i][j] == ' ') {
 return 0;
 }
 }
 }
 return 1;
}

void switchPlayer() {
 currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}

void getPlayerMove() {
 int row, col;
 printf("\nPlayer %c, enter your move (row column): ", currentPlayer);
 scanf("%d %d", &row, &col);
 
 // Validate input
 if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ') {
 board[row][col] = currentPlayer;
 } else {
 printf("Invalid move! Try again.\n");
 getPlayerMove();
 }
}

int main() {
 int choice;
 char playAgain;
 
 printf("Welcome to Tic-Tac-Toe!\n");
 
 do {
 initializeBoard();
 displayBoard();
 
 printf("Press 1 to start playing or 0 to exit: ");
 scanf("%d", &choice);
 
 if (choice == 1) {
 while (!checkWin() && !checkDraw()) {
 getPlayerMove();
 displayBoard();
 switchPlayer();
 }
 
 if (checkWin()) {
 printf("\nPlayer %c wins!\n", currentPlayer == 'X' ? 'O' : 'X');
 } else {
 printf("\nIt's a draw!\n");
 }
 }
 
 printf("Play again? (Y/N): ");
 scanf(" %c", &playAgain);
 
 } while (playAgain == 'Y' || playAgain == 'y');
 
 printf("Thanks for playing!\n");
 return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

char getComputerChoice() {
 int choice = rand() % 3;
 switch (choice) {
 case 0: return 'R';
 case 1: return 'P';
 case 2: return 'S';
 default: return 'R';
 }
}

char getUserChoice() {
 char choice;
 do {
 printf("\nEnter your choice (R for Rock, P for Paper, S for Scissors): ");
 scanf(" %c", &choice);
 choice = toupper(choice);
 } while (choice != 'R' && choice != 'P' && choice != 'S');
 return choice;
}

void determineWinner(char user, char computer) {
 printf("\nYou chose: %c\n", user);
 printf("Computer chose: %c\n", computer);
 
 if (user == computer) {
 printf("It's a tie!\n");
 } else if ((user == 'R' && computer == 'S') ||
 (user == 'P' && computer == 'R') ||
 (user == 'S' && computer == 'P')) {
 printf("You win!\n");
 } else {
 printf("Computer wins!\n");
 }
}

int main() {
 int choice;
 char playAgain;
 
 // Seed random number generator
 srand(time(NULL));
 
 printf("Welcome to Rock-Paper-Scissors!\n");
 
 do {
 char userChoice = getUserChoice();
 char computerChoice = getComputerChoice();
 determineWinner(userChoice, computerChoice);
 
 printf("\nPlay again? (Y/N): ");
 scanf(" %c", &playAgain);
 
 } while (playAgain == 'Y' || playAgain == 'y');
 
 printf("Thanks for playing!\n");
 return 0;
}
