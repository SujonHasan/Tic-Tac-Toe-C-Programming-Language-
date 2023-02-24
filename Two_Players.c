#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

char board[9];
char name1[30], name2[30];
int win_c_count = 0;

void display_board();
void play();
void win_check(char input);

int main()
{
    for (int i = 0; i < 9; i++)
    {
        board[i] = ' ';
    }

    printf("\n\n");
    printf("*** Welcome to tic tac toe Game***\n\n");
    display_board(board);
    win_c_count = 0;
    play();

    return 0;
}

void play()
{
    char ch;
    printf("\n\n");
    printf("Enter Player 1 Name: ");
    gets(name1);

    printf("Enter Player 2 Name: ");
    gets(name2);

    while (1)
    {
        while (1)
        {
            printf("\n\n");
            printf("player %s turn  0: ", name1);
            ch = _getch();

            if (board[ch - '1'] == ' ')
            {
                board[ch - '1'] = '0';
                break;
            }
            else
            {
                printf("wrong input\n");
            }
        }

        system("cls");
        display_board();

        win_check('0');

        while (1)
        {
            printf("\n\n");
            printf("player %s turn  X: ", name2);
            ch = _getch();

            if (board[ch - '1'] == ' ')
            {
                board[ch - '1'] = 'X';
                break;
            }
            else
            {
                printf("wrong input\n");
            }
        }

        system("cls");
        display_board();

        win_check('X');
    }
}

void win_check(char input)
{
    if (input == '0')
    {
        win_c_count++;

        if (board[0] == board[1] && board[1] == board[2] && board[0] != ' ')   
        {
                printf("***congratulation***\n");
                printf("win is %s", name1);

                printf("\n\n\nEnter continue...");
                _getch();
                system("cls");
                main();
        }
        if (board[3] == board[4] && board[4] == board[5] && board[3] != ' ')
        {
                printf("***congratulation***\n");
                printf("win is %s", name1);

                printf("\n\n\nEnter continue...");
                _getch();
                system("cls");
                main();
        }
        if (board[6] == board[7] && board[7] == board[8] && board[6] != ' ')
        {
            
                printf("***congratulation***\n");
                printf("win is %s", name1);

                printf("\n\n\nEnter continue...");
                _getch();
                system("cls");
                main();
        }
        if (board[0] == board[3] && board[3] == board[6] && board[0] != ' ')
        {
           
                printf("***congratulation***\n");
                printf("win is %s", name1);

                printf("\n\n\nEnter continue...");
                _getch();
                system("cls");
                main();
        }
        if (board[1] == board[4] && board[4] == board[7] && board[1] != ' ')
        {
                printf("***congratulation***\n");
                printf("win is %s", name1);

                printf("\n\n\nEnter continue...");
                _getch();
                system("cls");
                main();
        }
        if (board[2] == board[5] && board[5] == board[8] && board[5] != ' ')
        {
                printf("***congratulation***\n");
                printf("win is %s", name1);

                printf("\n\n\nEnter continue...");
                _getch();
                system("cls");
                main();
        }
        if (board[0] == board[4] && board[4] == board[8] && board[8] != ' ')
        {
                printf("***congratulation***\n");
                printf("win is %s", name1);

                printf("\n\n\nEnter continue...");
                _getch();
                system("cls");
                main();
        }
        if (board[2] == board[4] && board[4] == board[6] && board[2] != ' ')
        {
                printf("***congratulation***\n");
                printf("win is %s", name1);

                printf("\n\n\nEnter continue...");
                _getch();
                system("cls");
                main();
        }

        else if (win_c_count == 5)
        {
            printf("This game is draw..");
            printf("\n\nEnter Continue\n\n");
            _getch();
            system("cls");
            //display_board();
            main();
        }
    }
    else
    {
        if (board[0] == board[1] && board[1] == board[2])
        {
            if (board[0] != ' ' && board[1] != ' ' && board[2] != ' ')
            {
                printf("***congratulation***\n");
                printf("win is %s", name2);

                printf("\n\n\nEnter continue...");
                _getch();
                system("cls");
                main();
            }
        }
        if (board[3] == board[4] && board[4] == board[5])
        {
            if (board[3] != ' ' && board[4] != ' ' && board[5] != ' ')
            {
                printf("***congratulation***\n");
                printf("win is %s", name2);

                printf("\n\n\nEnter continue...");
                _getch();
                system("cls");
                main();
            }
        }
        if (board[6] == board[7] && board[7] == board[8])
        {
            if (board[6] != ' ' && board[7] != ' ' && board[8] != ' ')
            {
                printf("***congratulation***\n");
                printf("win is %s", name2);

                printf("\n\n\nEnter continue...");
                _getch();
                system("cls");
                main();
            }
        }
        if (board[0] == board[3] && board[3] == board[6])
        {
            if (board[0] != ' ' && board[3] != ' ' && board[6] != ' ')
            {
                printf("***congratulation***\n");
                printf("win is %s", name2);

                printf("\n\n\nEnter continue...");
                _getch();
                system("cls");
                main();
            }
        }
        if (board[1] == board[4] && board[4] == board[7])
        {
            if (board[1] != ' ' && board[4] != ' ' && board[7] != ' ')
            {
                printf("***congratulation***\n");
                printf("win is %s", name2);

                printf("\n\n\nEnter continue...");
                _getch();
                system("cls");
                main();
            }
        }
        if (board[2] == board[5] && board[5] == board[8])
        {
            if (board[2] != ' ' && board[5] != ' ' && board[8] != ' ')
            {
                printf("***congratulation***\n");
                printf("win is %s", name2);

                printf("\n\n\nEnter continue...");
                _getch();
                system("cls");
                main();
            }
        }
        if (board[0] == board[4] && board[4] == board[8])
        {
            if (board[0] != ' ' && board[4] != ' ' && board[8] != ' ')
            {
                printf("***congratulation***\n");
                printf("win is %s", name2);

                printf("\n\n\nEnter continue...");
                _getch();
                system("cls");
                main();
            }
        }
        if (board[2] == board[4] && board[4] == board[6])
        {
            if (board[2] != ' ' && board[4] != ' ' && board[6] != ' ')
            {
                printf("***congratulation***\n");
                printf("win is %s", name2);

                printf("\n\n\nEnter continue...");
                _getch();
                system("cls");
                main();
            }
        }
        
        }
}
void display_board()
{
    printf("\n\n");
    printf("        |        |        \n");
    printf("   %c    |   %c    |   %c   \n", board[0], board[1], board[2]);
    printf("        |        |        \n");
    printf("-------------------------- \n");
    printf("        |        |        \n");
    printf("   %c    |   %c    |   %c   \n", board[3], board[4], board[5]);
    printf("        |        |        \n");
    printf("--------------------------\n");
    printf("        |        |        \n");
    printf("   %c    |   %c    |   %c   \n", board[6], board[7], board[8]);
    printf("        |        |        \n");
}
