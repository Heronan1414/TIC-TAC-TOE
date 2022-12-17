//header files
#include <stdio.h>
#include <conio.h> // toupper tolower
#include <windows.h> //gotoxy
#include <ctype.h>
#include <time.h> // for srand
#include <stdlib.h>
#include <process.h>
// definition for colors
#define RED "\x1b[31m"
#define GREEN "\x1b[32m"
#define YELLOW "\x1b[33m"
#define BLUE "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN "\x1b[36m"
#define WHITE "\x1b[37m"
#define NORMAL "\x1b[m"
#define BLK "\e[0;30m"
//bold txt
#define BHBLK "\e[1;90m"
#define BHRED "\e[1;91m"
#define BHGRN "\e[1;92m"
#define BHYEL "\e[1;93m"
#define BHBLU "\e[1;94m"
#define BHMAG "\e[1;95m"
#define BHCYN "\e[1;96m"
#define BHWHT "\e[1;97m"
//Reset
#define reset "\e[0m"
#define CRESET "\e[0m"
#define COLOR_RESET "\e[0m"

//global variables
char board[4][4]; //two dimensional array name board for 4x4 board

const char PLAYER = 'X';
const char COMPUTER = 'O';

const char PLAYER1 = 'X';
const char PLAYER2 = 'O';

char square[10] = { 'o', '1', '2', '3', '4', '5', '6', '7', '8', '9' };

void gotoxy(int x, int y)
{
    COORD b;
    b.X = x; // vertical axis (column)
    b.Y = y; // horizontal axis.(rows or lines)

    SetConsoleCursorPosition(
        GetStdHandle(STD_OUTPUT_HANDLE), b);
}

int main() // main function
{
   loading();
   mainMenu();
}

int loading()
    {
    int r,q;
    gotoxy(50,14);
    printf("    loading...");

    gotoxy(40,15);
    for(r=1; r<=60; r++) // outer forloop for how many times to print those characters in screen
    {
         for(q=0; q<=10000000; q++); // inner forloop is to delay to print the characters in screen
         if(r==5)
         printf("\t %c", 84); // T
         else if(r==10)
         printf("%c", 73); // I
         else if(r==15)
         printf("%c \t", 67); // C
         else if(r==20)
         printf("%c", 84); // T
         else if(r==25)
         printf("%c", 65); // A
         else if(r==30)
         printf("%c \t", 67); // C
         else if(r==35)
         printf("%c", 84); // T
         else if(r==40)
         printf("%c", 79); // O
         else if(r==45)
         printf("%c", 69); // E
    }
    gotoxy(48,16);
    for(r=1; r<=20; r++)
    {
        for(q=0; q<=10000000; q++); // to print the character slowly
            printf("%c", 219);
    }
   return 0;
   }

int mainMenu()
{

   int ch, j;
   int r,q;
   system("cls"); //clear screen
   gotoxy(48,4); //coordinates function
   printf(BHWHT"=========TIC TAC TOE========="COLOR_RESET);
   gotoxy(48,5);
   printf(YELLOW"\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n"); //solid lines for border
   gotoxy(48,6);
   printf(BHYEL"\t  MAIN MENU"COLOR_RESET);
   gotoxy(48,7);
   printf(YELLOW"\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n");
   gotoxy(48,8);
   printf(NORMAL"      press 1:     3x3");
   gotoxy(48,9);
   printf("      press 2:     4x4 \n");
   gotoxy(48,10);
   printf("      press 3: Pyramid \n");
   gotoxy(48,11);
   printf("      press 4:    Quit");
   gotoxy(48,12);
   printf(YELLOW"\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n");
   gotoxy(48,13);
   printf(NORMAL"Enter Number (1-4): ");


   while ((ch = getchar())!= '5') //getchar reads single character input
   {
      //Ignore whitespace
      if(ch == '\n')
         continue;
      else
      {
         switch (ch)
         {
         case '1': //3x3
         gotoxy(48,14);
         printf(YELLOW"\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n");
         gotoxy(48,15);
         printf(NORMAL"Multiplayer(1): ");
         gotoxy(48,16);
         printf("Singleplayer(2): ");
         gotoxy(48,17);
         printf(YELLOW"=============================");
         gotoxy(48,18);
         printf(NORMAL"Enter player mode: ");
         scanf("%d", &j);
            if(j == 1)
            {
            gotoxy(48,24);
            threeXthreeMultiPlayer();
            break;
            }
            else if(j ==2 )
            {
            gotoxy(48,24);
            threeXthreeSingleplayer();
            break;
            }
            else
            {
            gotoxy(48,21);
            printf(RED"Invalid Input press ENTER");
            getch();
            mainMenu();
            break;
            }
         break;

         case '2': //4x4


         gotoxy(48,14);
         printf(YELLOW"\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n");

         gotoxy(48,15);
         printf(NORMAL"Multiplayer(1): ");
         gotoxy(48,16);
         printf("Singleplayer(2): ");
         gotoxy(48,17);
         printf(YELLOW"=============================");
         gotoxy(48,18);
         printf(NORMAL"Enter player mode: ");
         scanf("%d", &j);
            if( j == 1 )
            {
            gotoxy(50,34);
            fourXfourMulti();
            break;
            }
            else if( j == 2 )
            {
            gotoxy(48,34);
            fourXfour();
            break;
            }
            else
            {
            gotoxy(48,21);
            printf(RED"Invalid Input press ENTER");
            getch();
            mainMenu();
            break;
            }
         break;

         case '3':

         gotoxy(48,14);
         printf(YELLOW"\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n");

         gotoxy(48,15);
         printf(NORMAL"Multiplayer(1): ");
         gotoxy(48,16);
         printf("Singleplayer(2): ");
         gotoxy(48,17);
         printf(YELLOW"=============================");
         gotoxy(48,18);
         printf(NORMAL"Enter player mode: ");
         scanf("%d", &j);
            if(j ==1 )
            {
            gotoxy(48,34);
            multiPlayerPyramid();
            break;
            }
            else if(j ==2 )
            {
            gotoxy(48,34);
            singleplayerPyramid();
            break;
            }
            else
            {
            gotoxy(48,21);
            printf(RED"Invalid choice, press ENTER");
            getch();
            mainMenu();
            break;
            }
         break;

         case '4':
         gotoxy(48,15);
         printf(GREEN"Thank you for playing!\n\n");
         exit(0);
         break;



         default:
         gotoxy(48,15);
            printf(RED"Invalid choice, press ENTER\n");
            getch();
            mainMenu();
            break;
         }
   }
   }


}

// 3X3 SINGLE PLAYER
int threeXthreeSingleplayer() //function for the game 3x3 singleplayer mode
{

   char winner = ' ';
   resetBoard3s();

      while(winner == ' ' && checkFreeSpaces3s() != 0)
      {
         threeXthree3s();

         playerMove3s();
         winner = checkWinner3s();
         if(winner != ' ' || checkFreeSpaces3s() == 0)
         {
            break;
         }

         computerMove3s();
         winner = checkWinner3s();
         if(winner != ' ' || checkFreeSpaces3s() == 0)
         {
            break;
         }
      }

      threeXthree3s();
      printWinner(winner);
      response3x3();
   return 0;
}

void response3x3()
{
    char response;
    printf(NORMAL"\nWould you like to play again? (Y/N): ");
    scanf("%c");
    scanf("%c", &response);
    response = toupper(response);

    if (response == 'Y')
        threeXthreeSingleplayer ();
    else if(response == 'N')
        mainMenu();
    else
        {
        printf (RED"INVALID");
        response3x3 ();
        system ("cls");
        }
}

void playerMove3s() // movement of player in 3x3 singleplayer
{
   int x;
   int y;
   char range[3][3]={'1','2','3'};
   do
   {

      printf(BHBLU"Enter row #(1-3): "COLOR_RESET);
      scanf("%d", &x);
      x--; //decrement for index


      printf(BHGRN"Enter column #(1-3): "COLOR_RESET);
      scanf("%d", &y);


      y--;

      if(board[x][y] != ' ')
      {
        printf(RED"\nInvalid move!\n");


      }
      else if (board[x][y] = PLAYER)
      {
         break;
      }

   } while (board[x][y] != ' ');

}
void computerMove3s() //computer move for 3x3 singleplayer
{
   //creates a seed based on current time
   srand(time(0)); //random number generator
   int x;
   int y;

   if(checkFreeSpaces() > 0)
   {
      do
      {
         x = rand() % 3;
         y = rand() % 3;
      } while (board[x][y] != ' ');

      board[x][y] = COMPUTER;
   }
   else
   {
      printWinner(' ');
   }
}
void resetBoard3s() //resets board of 3x3 singleplayer
{
   for(int i = 0; i < 3; i++)
   {
      for(int j = 0; j < 3; j++)
      {
         board[i][j] = ' ';
      }
   }
}
int checkFreeSpaces3s() //checks available space for 3x3 Singleplayer
{
   int freeSpaces = 9;

   for(int i = 0; i < 3; i++)
   {
      for(int j = 0; j < 3; j++)
      {
         if(board[i][j] != ' ')
         {
            freeSpaces--;
         }
      }
   }
   return freeSpaces;
}
int checkWinner3s() //checks the winner for 3x3 singleplayer
{
   //check rows
   for(int i = 0; i < 3; i++)
   {
      if(board[i][0] == board[i][1] && board[i][0] == board[i][2])
      {
         return board[i][0];
      }
   }
   //check columns
   for(int i = 0; i < 3; i++)
   {
      if(board[0][i] == board[1][i] && board[0][i] == board[2][i])
      {
         return board[0][i];
      }
   }
   //check diagonals
   if(board[0][0] == board[1][1] && board[0][0] == board[2][2])
   {
      return board[0][0];
   }
   if(board[0][2] == board[1][1] && board[0][2] == board[2][0])
   {
      return board[0][2];
   }

   return ' ';
}
// 3X3 MULTI PLAYER
int threeXthreeMultiPlayer() //3x3 multiplayer
{
    int player = 1, i, choice;

    char mark;
    do
    {
        threeXthree();
        player = (player % 2) ? 1 : 2;



        switch (player){
        case 1:
        {
            printf(BHBLU"   Player %d, enter a number:  ", player);
            scanf("%d", &choice);
            break;
        }
        case 2:
        {
            printf(BHGRN"   Player %d, enter a number:  "COLOR_RESET, player);
            scanf("%d", &choice);
        }
        }
        mark = (player == 1) ? 'X' : 'O';

        if (choice == 1 && square[1] == '1')
            square[1] = mark;

        else if (choice == 2 && square[2] == '2')
            square[2] = mark;

        else if (choice == 3 && square[3] == '3')
            square[3] = mark;

        else if (choice == 4 && square[4] == '4')
            square[4] = mark;

        else if (choice == 5 && square[5] == '5')
            square[5] = mark;

        else if (choice == 6 && square[6] == '6')
            square[6] = mark;

        else if (choice == 7 && square[7] == '7')
            square[7] = mark;

        else if (choice == 8 && square[8] == '8')
            square[8] = mark;

        else if (choice == 9 && square[9] == '9')
            square[9] = mark;

        else
      {
            printf(RED"   Invalid move ");
            player--;
            getch();
      }
      i = checkwin3();

      player++;
   }while (i ==  - 1);

    threeXthree();

    if (i == 1)
    {
        gotoxy(48,24);
        printf(YELLOW"\t==>\aPlayer %d win ", --player);
        playAgain3M();

    }
    else
    {
        gotoxy(48,24);
        printf(GREEN"\t==>\aGame draw");
        playAgain3M();
    }
    getch();

    return 0;
}
void playAgain3M() // function if user wants to play again or return main menu
{

    int x;
    square[1]= '1';
    square[2]= '2';
    square[3]= '3';
    square[4]= '4';
    square[5]= '5';
    square[6]= '6';
    square[7]= '7';
    square[8]= '8';
    square[9]= '9';

    gotoxy(48,25);
    printf(NORMAL"\tPlay Again (1)");
    gotoxy(48,26);
    printf(NORMAL"\tBack to Main Menu (2) ");
    scanf("%d",&x);

    if (x==1)
        threeXthreeMultiPlayer();
    else if (x==2)
        mainMenu();
    else {
        printf(RED"INVALID");
        playAgain3M();
        system("cls");
    }
}
int checkwin3() //checks the winner for 3x3 multiplayer
{
    if (square[1] == square[2] && square[2] == square[3])
        return 1;

    else if (square[4] == square[5] && square[5] == square[6])
        return 1;

    else if (square[7] == square[8] && square[8] == square[9])
        return 1;

    else if (square[1] == square[4] && square[4] == square[7])
        return 1;

    else if (square[2] == square[5] && square[5] == square[8])
        return 1;

    else if (square[3] == square[6] && square[6] == square[9])
        return 1;

    else if (square[1] == square[5] && square[5] == square[9])
        return 1;

    else if (square[3] == square[5] && square[5] == square[7])
        return 1;

    else if (square[1] != '1' && square[2] != '2' && square[3] != '3' &&
        square[4] != '4' && square[5] != '5' && square[6] != '6' && square[7]
        != '7' && square[8] != '8' && square[9] != '9')

        return 0;
    else
        return  - 1;
}
// 4X4 SINGLE PLAYER
int fourXfour() //single player 4x4
{
    char winner = ' '; //set sinner to empty space, if player wins that an X

    resetBoard(); // first reset borad set in empty space

    while(winner == ' ' && checkFreeSpaces() != 0)// third
    {
        printBoard(); // second

        playerMove(); // fourt
        winner = checkWinnerfour(); // fifth
        if(winner != ' ' || checkFreeSpaces() == 0)// sixth to check if the game is over
            {
                break; // done for the player
            }

        computerMove();
        winner = checkWinnerfour();
        if(winner != ' ' || checkFreeSpaces() == 0)
            {
                break; // done
            }
    }

        printBoard();
        printWinner(winner);
        response4X4 ();

    return 0;
}
void resetBoard() //function to reset the 4x4 singleplayer
{
   for(int i = 0; i < 4; i++) // outer loop is for rows
   {
      for(int j = 0; j < 4; j++) // inner for loop is for column
      {
         board[i][j] = ' '; // set to empty space
      }
   }
}
int checkFreeSpaces() //function to check the available spaces in the 4x4 multiplayer board
{
   int freeSpaces = 16;

   for(int i = 0; i < 4; i++)
   {
      for(int j = 0; j < 4; j++)
      {
         if(board[i][j] != ' ') // check the 2d array board does not occupied
         {
            freeSpaces--; // then
         }
      }
   }
   return freeSpaces; // if return 0 that means no places can player to move
}
void playerMove() // function for the move of player 1 in single player 4x4
{
   int x;
   int y;

   do
   {

      printf(BHBLU"\t\t\t\t\tEnter row #(1-4): "); // user cannot determine/read zero rows so decrement by 1
      scanf("%d", &x);
      x--;
      printf("\t\t\t\t\tEnter column #(1-4): " COLOR_RESET); // user cannot determine zero column so decrement by 1
      scanf("%d", &y);
      y--;

      if(board[x][y] != ' ')
      {

         printf(RED"\t\t\t\t\tInvalid move!\n");
         Beep(500, 400);
         Beep(500, 400);
      }
      else
      {
         board[x][y] = PLAYER; // set player character
         break;
      }
   } while (board[x][y] != ' '); // if currently occupied then we will ask again to ender some coordinates

}
void computerMove() //function for computer move 4x4
{
   //creates a seed based on current time
   srand(time(0));
   int x;
   int y;

   if(checkFreeSpaces() > 0) // check if theres free spaces
   {
      do
      {
         x = rand() % 4; // set rand number btwn 0&3
         y = rand() % 4;
      } while (board[x][y] != ' '); // if theres free spaces it will generate random numbers then escape from while loop

      board[x][y] = COMPUTER; // if there space set to computer character
   }
   else
   {
      printWinner(' ');// means no winner its a draw
   }
}
int checkWinnerfour() // function to check winner for 4x4 singleplayer
{
   //check rows
   for(int i = 0; i < 4; i++)
   {
      if(board[i][0] == board[i][1] && board[i][0] == board[i][2] && board[i][0] == board [i][3])
      {
         return board[i][0]; // so we will return any of this board
      }
   }
   //check columns
   for(int i = 0; i < 4; i++)
   {
      if(board[0][i] == board[1][i] && board[0][i] == board[2][i] && board[0][i] == board [3][i])
      {
         return board[0][i];
      }
   }
   //check diagonals
   if(board[0][0] == board[1][1] && board[1][1] == board[2][2]  && board[2][2] == board[3][3])
   {
      return board[0][0];
   }
   if(board[0][3] == board[1][2] && board[1][2] == board[2][1] && board[2][1] == board[3][0])
   {
      return board[0][3];
   }

   return ' '; // if theres no winner, then return empty charac, means no winner
}
void printWinner(char winner) //function to print winner for 4x4 singleplayer
{
   if(winner == PLAYER)
   {
      printf("YOU WIN!");
   }
   else if(winner == COMPUTER)
   {
      printf("YOU LOSE!");
   }
   else{
      printf("IT'S A TIE!");
   }
}
void response4X4 () // function for user response "play again or return to menu" for single player
{
    char response;
    printf(NORMAL"\nWould you like to play again? (Y/N): ");
    scanf("%c"); // clear the buffer
    scanf("%c", &response);
    response = toupper(response);

    if (response == 'Y')
        fourXfour ();
    else if(response == 'N')
        mainMenu();
    else
        {
        printf (RED"INVALID");
        response4X4 ();
        system ("cls"); // to clear the screen
        }
}

// 4X4 MULTI PLAYER
int fourXfourMulti() //function for 4x4 multiplayer
{
    char winner = ' ';

        resetBoard();

        while(winner == ' ' && checkFreeSpaces() != 0)
            {
                printBoard4x4M();
                player1Move();
                winner = checkWinner4x4multi();
                if(winner != ' ' || checkFreeSpaces() == 0)
                    {
                        break;
                    }
                printBoard4x4M();
                player2Move();
                winner = checkWinner4x4multi();
                if(winner != ' ' || checkFreeSpaces() == 0)
                    {
                        break;
                    }
            }
      printBoard4x4M();
      printWinnerMulti(winner);
      response4X4Multi();

   return 0;
}
void player1Move() // for four x four player 1 move
{
    int x;
    int y;
    do
    {
      printf(NORMAL"\n");
      printf(BHGRN"\t\t\t\t\t[Player 1] Enter row #(1-4): "); // user cannot determine/read zero rows so decrement by 1
      scanf("%d", &x);
      x--;
      printf("\t\t\t\t\t[Player 1] Enter column #(1-4): "COLOR_RESET); // user cannot determine zero column so decrement by 1
      scanf("%d", &y);
      y--;

      if(board[x][y] != ' ')
      {
         printf(RED"\t\t\t\t\tInvalid move!\n");
      }
      else
      {
         board[x][y] = PLAYER1;
         break;
      }
    } while (board[x][y] != ' ');

}
void player2Move() // for 4x4 Multiplayer player 2 move
{
    int x;
    int y;
    do
    {
      printf(BHBLU"\t\t\t\t\t[Player 2] Enter row #(1-4): "); // user cannot determine/read zero rows so decrement by 1
      scanf("%d", &x);
      x--;
      printf(BHBLU"\t\t\t\t\t[Player 2] Enter column #(1-4): "COLOR_RESET); // user cannot determine zero column so decrement by 1
      scanf("%d", &y);
      y--;

      if(board[x][y] != ' ')
      {
         printf(RED"\t\t\t\t\tInvalid move!\n");
      }
      else
      {
         board[x][y] = PLAYER2;
         break;
      }
    } while (board[x][y] != ' ');

}
int checkWinner4x4multi() //checks winner for 4x4 multiplayer
{
   //check rows
   for(int i = 0; i < 4; i++)
   {
      if(board[i][0] == board[i][1] && board[i][0] == board[i][2] && board[i][0] == board [i][3])
      {
         return board[i][0];
      }
   }
   //check columns
   for(int i = 0; i < 4; i++)
   {
      if(board[0][i] == board[1][i] && board[0][i] == board[2][i] && board[0][i] == board [3][i])
      {
         return board[0][i];
      }
   }
   //check diagonals
   if(board[0][0] == board[1][1] && board[1][1] == board[2][2]  && board[2][2] == board[3][3])
   {
      return board[0][0];
   }
   if(board[0][3] == board[1][2] && board[1][2] == board[2][1] && board[2][1] == board[3][0])
   {
      return board[0][3];
   }

   return ' ';
}
void printWinnerMulti (char winner) //print winner for 4x4 multiplayer
{
   if(winner == PLAYER1)
   {
      printf("PLAYER1 WIN!");
   }
   else if(winner == PLAYER2)
   {
      printf("PLAYER2 WIN!");
   }
   else{
      printf("IT'S A TIE!");
   }
}
void response4X4Multi () // function for user response "play again or return to menu"
{
    char response;
    printf(NORMAL"\nWould you like to play again? (Y/N): ");
    scanf("%c");
    scanf("%c", &response);
    response = toupper(response);
    if (response == 'Y')
        fourXfourMulti ();
    else if(response == 'N')
        mainMenu();
    else {
        printf (RED"INVALID");
        response4X4 ();
        system ("cls");
    }
}
// PYRAMID MULTI PLAYER
int multiPlayerPyramid() //function for the game mode Pyramid multiplayer
{
    int player = 1, i, choice;

    char mark;
    do
    {
        pyramid();

        player = (player % 2) ? 1 : 2;

        switch (player){
        case 1:
        {
            printf(BHBLU"   Player %d, enter a number:  ", player);
            scanf("%d", &choice);
            break;
        }
        case 2:
        {
            printf(BHGRN"   Player %d, enter a number:  "COLOR_RESET, player);
            scanf("%d", &choice);
            break;
        }
        }
        mark = (player == 1) ? 'X' : 'O';

        if (choice == 1 && square[1] == '1')
            square[1] = mark;

        else if (choice == 2 && square[2] == '2')
            square[2] = mark;

        else if (choice == 3 && square[3] == '3')
            square[3] = mark;

        else if (choice == 4 && square[4] == '4')
            square[4] = mark;

        else if (choice == 5 && square[5] == '5')
            square[5] = mark;

        else if (choice == 6 && square[6] == '6')
            square[6] = mark;

        else if (choice == 7 && square[7] == '7')
            square[7] = mark;

        else if (choice == 8 && square[8] == '8')
            square[8] = mark;

        else if (choice == 9 && square[9] == '9')
            square[9] = mark;

        else
        {
            printf(RED"\t\t\t\t\t\t Invalid move ");

            player--;
            getch();
        }
        i = checkwin();

        player++;
    }while (i ==  - 1);

    pyramid();

    if (i == 1){
        printf(GREEN"\t\t\t\t\t\t==>\aPlayer %d win ", --player);
        playAgainPM();}
    else{
        printf(NORMAL"\t\t\t\t\t\t==>\aGame draw");
        playAgainPM();}

    getch();

    return 0;
}

void playAgainPM() // function if user wants to play again or return main menu
{

    int x;
    square[1]= '1';
    square[2]= '2';
    square[3]= '3';
    square[4]= '4';
    square[5]= '5';
    square[6]= '6';
    square[7]= '7';
    square[8]= '8';
    square[9]= '9';

    printf(NORMAL"\n\t\t\t\t\t\tPlay Again (1) \n");
    printf(NORMAL"\t\t\t\t\t\tBack to Main Menu (2) \n");
    printf("\t\t\t\t\t\tEnter Number: ");
    scanf("%d",&x);

    if (x==1)
        multiPlayerPyramid();
    else if (x==2)
        mainMenu();
    else {
        printf("INVALID");
        playAgainPM();
        system("cls");
    }
}
int checkwin() //checks the winner for Pyramid multiplayer
{
    if (square[1] == square[2] && square[2] == square[5])
        return 1;

    else if (square[1] == square[3] && square[3] == square[7])
        return 1;

    else if (square[1] == square[4] && square[4] == square[9])
        return 1;

    else if (square[2] == square[3] && square[3] == square[4])
        return 1;

    else if (square[5] == square[6] && square[6] == square[7])
        return 1;

    else if (square[6] == square[7] && square[7] == square[8])
        return 1;

    else if (square[7] == square[8] && square[8] == square[9])
        return 1;

    else if (square[1] != '1' && square[2] != '2' && square[3] != '3' &&
        square[4] != '4' && square[5] != '5' && square[6] != '6' && square[7]
        != '7' && square[8] != '8' && square[9] != '9')

        return 0;
    else
        return  - 1;
}
// PYRAMID SINGLE PLAYER
int singleplayerPyramid()
{
    int i, choice;

    char mark;
    do
    {
        pyramidSingle();
        printf(BHBLU" \t\t\t\t\t\t Player 1, enter a number: "COLOR_RESET);
        scanf("%d", &choice);

        mark ='X';

        if (choice == 1 && square[1] == '1')
            square[1] = mark;

        else if (choice == 2 && square[2] == '2')
            square[2] = mark;

        else if (choice == 3 && square[3] == '3')
            square[3] = mark;

        else if (choice == 4 && square[4] == '4')
            square[4] = mark;

        else if (choice == 5 && square[5] == '5')
            square[5] = mark;

        else if (choice == 6 && square[6] == '6')
            square[6] = mark;

        else if (choice == 7 && square[7] == '7')
            square[7] = mark;

        else if (choice == 8 && square[8] == '8')
            square[8] = mark;

        else if (choice == 9 && square[9] == '9')
            square[9] = mark;

        else
        {
            printf(RED"\t\t\t\t\t\t Invalid move ");
            getch();
            singleplayerPyramid();
        }

    computerMovePS();
    i = checkwinPS();
    }

    while (i ==  - 1);
    pyramidSingle();

    if (i == 1){
        if (square[1] == square[2] && square[2] == square[5] && square[5] == 'X'){
            printf(GREEN"\t\t\t\t\t\t==>\aYou Win ");
            playAgainPS();
            return 0;}

        else if (square[1] == square[3] && square[3] == square[7] && square[7] == 'X'){
            printf(GREEN"\t\t\t\t\t\t==>\aYou Win ");
            playAgainPS();
            return 0;}

        else if (square[1] == square[4] && square[4] == square[9] && square[9] == 'X'){
            printf(GREEN"\t\t\t\t\t\t==>\aYou Win ");
            playAgainPS();
            return 0;}

        else if (square[2] == square[3] && square[3] == square[4] && square[4] == 'X'){
            printf(GREEN"\t\t\t\t\t\t==>\aYou Win ");
            playAgainPS();
            return 0;}

        else if (square[5] == square[6] && square[6] == square[7] && square[7] == 'X'){
            printf(GREEN"\t\t\t\t\t\t==>\aYou Win ");
            playAgainPS();
            return 0;}

        else if (square[6] == square[7] && square[7] == square[8] && square[8] == 'X'){
            printf(GREEN"\t\t\t\t\t\t==>\aYou Win ");
            playAgainPS();
            return 0;}

        else if (square[7] == square[8] && square[8] == square[9] && square[9] == 'X'){
            printf(GREEN"\t\t\t\t\t\t==>\aYou Win ");
            playAgainPS();
            return 0;}

        else
            printf(RED"\t\t\t\t\t\t==>\aYou Lose ");
            playAgainPS();
            return 0;}

    else{
        printf(NORMAL"\t\t\t\t\t\t==>\aGame draw");
        playAgainPS();
    }
    getch();

    return 0;
}
void playAgainPS()
{

    int x;
    square[1]= '1';
    square[2]= '2';
    square[3]= '3';
    square[4]= '4';
    square[5]= '5';
    square[6]= '6';
    square[7]= '7';
    square[8]= '8';
    square[9]= '9';

    printf(NORMAL"\n\t\t\t\t\t\tPlay Again (1) \n");
    printf("\t\t\t\t\t\tBack to Main Menu (2) \n");
    printf("\t\t\t\t\t\tEnter Number: ");
    scanf("%d",&x);

    if (x==1)
        singleplayerPyramid();
    else if (x==2)
        mainMenu();
    else {
        printf("INVALID");
        playAgainPS();
        system("cls");
    }
}
int checkFreeSpacesPS()
{
    int freeSpaces = 9;
        for (int i = 1; i < 10; i++)
            if (square[i] != 'O' && square[i] != 'X')
                freeSpaces--;
                return freeSpaces;

}
int checkwinPS()
{
    if (square[1] == square[2] && square[2] == square[5])
        return 1;

    else if (square[1] == square[3] && square[3] == square[7])
        return 1;

    else if (square[1] == square[4] && square[4] == square[9])
        return 1;

    else if (square[2] == square[3] && square[3] == square[4])
        return 1;

    else if (square[5] == square[6] && square[6] == square[7])
        return 1;

    else if (square[6] == square[7] && square[7] == square[8])
        return 1;

    else if (square[7] == square[8] && square[8] == square[9])
        return 1;

    else if (square[1] != '1' && square[2] != '2' && square[3] != '3' &&
        square[4] != '4' && square[5] != '5' && square[6] != '6' && square[7]
        != '7' && square[8] != '8' && square[9] != '9')

        return 0;
    else
        return  - 1;
}
void computerMovePS()
{

        int x;
        if (checkFreeSpacesPS() > 0){
                do
                {
                    srand(time(0));

                    x = (rand()% 9)+1;
                }
                while (square[x] == 'O' || square[x] == 'X');
                square[x] = 'O';

        }

    return square[x];
}
//BOARD STYLES
void pyramid() //pyramid multiplayer
{

    system("cls");
    printf(YELLOW"\n\n                                                 \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n");
    printf(BHGRN"\t\t\t\t\t\t\t\tTic Tac Toe"COLOR_RESET    );
    printf(YELLOW"\n                                                 \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n\n");
    printf(GREEN"\t\t\t\t\t\t\t Player 1 (X)  -  Player 2 (O)\n\n");


    printf(YELLOW"                                                 \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n");
    printf(GREEN"\t\t\t\t\t\t\t            _____\n");
    printf("\t\t\t\t\t\t\t           |     |\n");
    printf("\t\t\t\t\t\t\t           |  %c  |\n", square[1]);

    printf("\t\t\t\t\t\t\t      _____|_____|_____\n");
    printf("\t\t\t\t\t\t\t     |     |     |     |\n");

    printf("\t\t\t\t\t\t\t     |  %c  |  %c  |  %c  |\n", square[2], square[3], square[4]);

    printf("\t\t\t\t\t\t\t_____|_____|_____|_____|_____\n");
    printf("\t\t\t\t\t\t       |     |     |     |     |     |\n");

    printf("\t\t\t\t\t\t       |  %c  |  %c  |  %c  |  %c  |  %c  |\n", square[5], square[6], square[7], square[8], square[9]);
    printf("\t\t\t\t\t\t       |_____|_____|_____|_____|_____|\n\n");

    printf(YELLOW"                                                 \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n\n\n");

}
void pyramidSingle() //pyramid singleplayer
{

    system("cls");
    printf(YELLOW"\n\n                                                 \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n");
    printf(BHGRN"\t\t\t\t\t\t\t\tTic Tac Toe"COLOR_RESET);
    printf(YELLOW"\n                                                 \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n\n");
    printf(GREEN"\t\t\t\t\t\t\t Player 1 (X)  -  Computer (O)\n\n");


    printf(YELLOW"                                                 \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n");
    printf(GREEN"\t\t\t\t\t\t\t            _____\n");
    printf("\t\t\t\t\t\t\t           |     |\n");
    printf("\t\t\t\t\t\t\t           |  %c  |\n", square[1]);

    printf("\t\t\t\t\t\t\t      _____|_____|_____\n");
    printf("\t\t\t\t\t\t\t     |     |     |     |\n");

    printf("\t\t\t\t\t\t\t     |  %c  |  %c  |  %c  |\n", square[2], square[3], square[4]);

    printf("\t\t\t\t\t\t\t_____|_____|_____|_____|_____\n");
    printf("\t\t\t\t\t\t       |     |     |     |     |     |\n");

    printf("\t\t\t\t\t\t       |  %c  |  %c  |  %c  |  %c  |  %c  |\n", square[5], square[6], square[7], square[8], square[9]);
    printf("\t\t\t\t\t\t       |_____|_____|_____|_____|_____|\n\n");

    printf(YELLOW"                                                 \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n\n\n");

}
void threeXthree3s() //3x3 singleplayer
{
    system("cls");
    printf(GREEN"\n\n                                                    \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n");
    printf(YELLOW"\t\t\t\t\t\t            Tic Tac Toe 3X3");
    printf(GREEN"\n                                                    \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n\n");
    printf(NORMAL"\t\t\t\t\t\t       Enter first row # then \n");
    printf("\t\t\t\t\t\t       column # for your move!  \n");

    printf(GREEN"                                                    \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n");
    printf(NORMAL"\t\t\t\t\t\t    Player 1 (X)  -  Computer (O) \n");
    printf(GREEN"\t\t\t\t\t\t    -----------------------------\n");
    printf(YELLOW"\t\t\t\t\t\t    |col #  1     2     3      |  \n");
    printf(GREEN"                                                    \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n");
    printf(YELLOW"\t\t\t\t\t\t\t  |     |     |     |\n");
    printf("\t\t\t\t\t\t    row 1 |  %c  |  %c  |  %c  |\n", board[0][0], board[0][1], board[0][2]);

    printf("\t\t\t\t\t\t\t  |_____|_____|_____|\n");
    printf("\t\t\t\t\t\t\t  |     |     |     |\n");


    printf("\t\t\t\t\t\t    row 2 |  %c  |  %c  |  %c  |\n", board[1][0], board[1][1], board[1][2]);

    printf("\t\t\t\t\t\t\t  |_____|_____|_____|\n");
    printf("\t\t\t\t\t\t\t  |     |     |     |\n");

    printf("\t\t\t\t\t\t    row 3 |  %c  |  %c  |  %c  |\n", board[2][0], board[2][1], board[2][2]);

    printf("\t\t\t\t\t\t\t  |     |     |     |\n");
    printf(GREEN"                                                    \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n\n");
}
void threeXthree() //3x3 multiplayer
{
    system("cls");
    printf(GREEN"\n\n                                                    \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n");
    printf(YELLOW"\t\t\t\t\t\t\t   Tic Tac Toe 3X3");
    printf(GREEN"\n                                                    \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n\n");

    printf(NORMAL"\t\t\t\t\t\t    Player 1 (X)  -  Player 2 (O)\n\n");
    printf(GREEN"\t\t\t\t\t\t    -----------------------------\n");
    printf(YELLOW"\t\t\t\t\t\t    |col #    1     2     3     |  \n");
    printf(GREEN"                                                    \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n");
    printf(YELLOW"\t\t\t\t\t\t\t   |     |     |     |\n");

    printf("\t\t\t\t\t\t     row 1 |  %c  |  %c  |  %c  |\n", square[1], square[2], square[3]);

    printf("\t\t\t\t\t\t\t   |_____|_____|_____|\n");
    printf("\t\t\t\t\t\t\t   |     |     |     |\n");


    printf("\t\t\t\t\t\t     row 2 |  %c  |  %c  |  %c  |\n", square[4], square[5], square[6]);

    printf("\t\t\t\t\t\t\t   |_____|_____|_____|\n");
    printf("\t\t\t\t\t\t\t   |     |     |     |\n");

    printf("\t\t\t\t\t\t     row 3 |  %c  |  %c  |  %c  |\n", square[7], square[8], square[9]);

    printf("\t\t\t\t\t\t\t   |     |     |     |\n");
    printf(GREEN"                                                    \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n\n");
}

void printBoard() //4x4 singleplayer
{
   system("cls");
   printf("\n\n");
   printf(CYAN"                                        \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n");
   printf("\t\t\t\t\t|        TIC TAC TOE 4x4        |\n");
   printf(CYAN"                                        \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n");
   printf("\n");
   printf(NORMAL"\t\t\t\t\tEnter first the row number \n");
   printf("\t\t\t\t\tthen column number for your move!  \n");
   printf("\n");
   printf(CYAN"                                        \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n");
   printf(YELLOW"\t\t\t\t\tPlayer 1 (X)  -  Player 2 (O)\n");
   printf(CYAN"                                        \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n");
   printf(YELLOW"      \t\t\t\t\tcolumn#    | 1 | 2 | 3 | 4 |  \n");
   printf(CYAN"                                        \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n");
   printf (YELLOW"     \t\t\t\t\trow| 1 |");
   printf(GREEN"   | %c | %c | %c | %c |", board[0][0], board[0][1], board[0][2], board[0][3] ); // row 0 - column 0 |
   printf (YELLOW"     \n\t\t\t\t\t   +---+");
   printf(GREEN"   +---|---|---|---+\n");
   printf (YELLOW"     \t\t\t\t\t   | 2 |");
   printf(GREEN"   | %c | %c | %c | %c |", board[1][0], board[1][1], board[1][2], board[1][3]);
   printf (YELLOW"     \n\t\t\t\t\t   +---+");
   printf(GREEN"   +---|---|---|---+\n");
   printf (YELLOW"     \t\t\t\t\t   | 3 |");
   printf(GREEN"   | %c | %c | %c | %c |", board[2][0], board[2][1], board[2][2], board[2][3]);
   printf (YELLOW"     \n\t\t\t\t\t   +---+");
   printf(GREEN"   +---|---|---|---+\n");
   printf (YELLOW"     \t\t\t\t\t   | 4 |");
   printf(GREEN"   | %c | %c | %c | %c |", board[3][0], board[3][1], board[3][2], board[3][3]);
   printf (YELLOW"     \n\t\t\t\t\t-----------");
   printf(GREEN"----------------------\n");
   printf("\n");
}

void printBoard4x4M() //4x4 multiplayer
{
   system("cls");
   printf("\n\n");
   printf(CYAN"                                        \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n");
   printf("\t\t\t\t\t|        TIC TAC TOE 4x4        |\n");
   printf(CYAN"                                        \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n");
   printf("\n");
   printf(NORMAL"\t\t\t\t\tEnter first the row number \n");
   printf("\t\t\t\t\tthen column number for your move!  \n");
   printf("\n");
   printf(CYAN"                                        \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n");
   printf(YELLOW"\t\t\t\t\tPlayer 1 (X)  -  Player 2 (O)\n");
   printf(CYAN"                                        \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n");

   printf( YELLOW"      \t\t\t\t\tcolumn#    | 1 | 2 | 3 | 4 |  \n");
   printf(CYAN"                                        \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n");
   printf (YELLOW"     \t\t\t\t\trow| 1 |");
   printf(GREEN"   | %c | %c | %c | %c |", board[0][0], board[0][1], board[0][2], board[0][3] ); // row 0 - column 0 |
   printf (YELLOW"     \n\t\t\t\t\t   +---+");
   printf(GREEN"   +---|---|---|---+\n");
   printf (YELLOW"     \t\t\t\t\t   | 2 |");
   printf(GREEN"   | %c | %c | %c | %c |", board[1][0], board[1][1], board[1][2], board[1][3]);
   printf (YELLOW"     \n\t\t\t\t\t   +---+");
   printf(GREEN"   +---|---|---|---+\n");
   printf (YELLOW"     \t\t\t\t\t   | 3 |");
   printf(GREEN"   | %c | %c | %c | %c |", board[2][0], board[2][1], board[2][2], board[2][3]);
   printf (YELLOW"     \n\t\t\t\t\t   +---+");
   printf(GREEN"   +---|---|---|---+\n");
   printf (YELLOW"     \t\t\t\t\t   | 4 |");
   printf(GREEN"   | %c | %c | %c | %c |", board[3][0], board[3][1], board[3][2], board[3][3]);
   printf (YELLOW"     \n\t\t\t\t\t-----------");
   printf(GREEN"----------------------\n");
   printf("\n");
}

