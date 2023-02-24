#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

char board[10];
char name[30];
int move = 0;

void display_board();
void play();
int win_check();
void game_start();
void winner_declare(char player);
int interrupt_to_opponent_winning();
int get_keysquare(int n1, int n2);
int get_keysquare_for_three(int n1, int n2, int n3);
int get_keysquare_for_four(int n1, int n2, int n3, int n4);
void special_case_for_move_two();
void special_case_for_move_three();
void special_case_for_move_four();
int win_check_mate();

int main()
{
    srand(time(NULL));

    while (1)
    {
        system("cls");
        game_start();

        puts("Do you wanna play again? If you agree Type : Y OR N:  ");
        char ch = _getch();

        ch = toupper(ch);
        if (ch == 'Y')
            continue;
        else
        {
            return 0;
        }
    }

    return 0;
}

void game_start()
{
    for (int i = 1; i <= 9; i++)
    {
        board[i] = ' ';
    }

    printf("\n\n");
    printf("*** Welcome to tic tac toe Game***\n\n");
    display_board(board);
    move = 0;
    play();

    return;
}

void play()
{
    char ch;
    printf("\n\n");
    printf("Enter your Name: ");
    gets(name);

    while (1)
    {
        move++;

        while (1)
        {
            printf("\n\n");
            printf("player %s turn  0: ", name);
            ch = _getch();

            if (board[ch - '0'] == ' ')
            {
                board[ch - '0'] = '0';
                break;
            }
            else
            {
                printf("wrong input\n");
            }
        }

        system("cls");
        display_board();

        if (move >= 3)
        {
            int return_vlaue = win_check();

            if (return_vlaue == 1)
            {
                winner_declare('0');
                break;
            }
            else if (return_vlaue == -1)
            {
                puts("The game is draw\n");
                break;
            }
        }

        printf("\n\n");
        printf("player computer turn  X: ");

        if (move == 1)
        {

            if (ch == '5')
            {
                while (1)
                {
                    int value = (rand() % 9) + 1;
                    if (value == 1 || value == 3 || value == 7 || value == 9)
                    {
                        board[value] = 'X';
                        value = 0;
                        break;
                    }
                }
            }
            else if (ch == '1' || ch == '3' || ch == '7' || ch == '9')
            {
                board[5] = 'X';
            }
            else if (ch == '2' || ch == '4' || ch == '6' || ch == '8')
            {
                board[5] = 'X';
            }
        }
        else if (move == 2)
        {
            if (interrupt_to_opponent_winning() == 0)
            {
                special_case_for_move_two();
            }
        }
        else if (move == 3)
        {
            if (win_check_mate() == 0)
            {
                if (interrupt_to_opponent_winning() == 0)
                {
                    special_case_for_move_three();
                }
            }
        }
        else if (move == 4)
        {
            if (interrupt_to_opponent_winning() == 0)
            {
                special_case_for_move_four();
            }
        }

        system("cls");
        display_board();

        if (move >= 3)
        {
            int return_vlaue = win_check();

            if (return_vlaue == 1)
            {
                winner_declare('X');
                break;
            }
            else if (return_vlaue == -1)
            {
                puts("The game is draw\n");
                break;
            }
        }
    }
}

int win_check_mate()
{
    if (board[1] == '0' && board[3] == 'X' && board[5] == 'X' && board[6] == '0' && board[7] == ' ')
    {
        board[7] = 'X';
        return 1;
    }
    else if (board[1] == '0' && board[7] == 'X' && board[5] == 'X' && board[8] == '0' && board[3] == ' ')
    {
        board[3] = 'X';
        return 1;
    }
    else if (board[1] == '0' && board[2] == 'X' && board[5] == 'X' && board[9] == '0' && board[8] == ' ')
    {
        board[8] = 'X';
        return 1;
    }
    else if (board[1] == '0' && board[6] == 'X' && board[5] == 'X' && board[9] == '0' && board[4] == ' ')
    {
        board[4] = 'X';
        return 1;
    }
    else if (board[1] == '0' && board[8] == 'X' && board[5] == 'X' && board[9] == '0' && board[2] == ' ')
    {
        board[2] = 'X';
        return 1;
    }
    else if (board[1] == '0' && board[4] == 'X' && board[5] == 'X' && board[9] == '0' && board[6] == ' ')
    {
        board[6] = 'X';
        return 1;
    }
    else if (board[3] == '0' && board[1] == 'X' && board[5] == 'X' && board[4] == '0' && board[9] == ' ')
    {
        board[9] = 'X';
        return 1;
    }
    else if (board[3] == '0' && board[9] == 'X' && board[5] == 'X' && board[8] == '0' && board[1] == ' ')
    {
        board[1] = 'X';
        return 1;
    }
    else if (board[3] == '0' && board[2] == 'X' && board[5] == 'X' && board[7] == '0' && board[8] == ' ')
    {
        board[8] = 'X';
        return 1;
    }
    else if (board[3] == '0' && board[6] == 'X' && board[5] == 'X' && board[7] == '0' && board[4] == ' ')
    {
        board[4] = 'X';
        return 1;
    }
    else if (board[3] == '0' && board[8] == 'X' && board[5] == 'X' && board[7] == '0' && board[2] == ' ')
    {
        board[2] = 'X';
        return 1;
    }
    else if (board[3] == '0' && board[4] == 'X' && board[5] == 'X' && board[7] == '0' && board[6] == ' ')
    {
        board[6] = 'X';
        return 1;
    }
    else if (board[2] == '0' && board[3] == 'X' && board[5] == 'X' && board[9] == '0' && board[7] == ' ')
    {
        board[7] = 'X';
        return 1;
    }
    else if (board[4] == '0' && board[7] == 'X' && board[5] == 'X' && board[9] == '0' && board[3] == ' ')
    {
        board[3] = 'X';
        return 1;
    }
    else if (board[1] == '0' && board[2] == 'X' && board[5] == 'X' && board[9] == '0' && board[8] == ' ')
    {
        board[8] = 'X';
        return 1;
    }
    else if (board[1] == '0' && board[6] == 'X' && board[5] == 'X' && board[9] == '0' && board[4] == ' ')
    {
        board[4] = 'X';
        return 1;
    }
    else if (board[1] == '0' && board[8] == 'X' && board[5] == 'X' && board[9] == '0' && board[2] == ' ')
    {
        board[2] = 'X';
        return 1;
    }
    else if (board[1] == '0' && board[4] == 'X' && board[5] == 'X' && board[9] == '0' && board[6] == ' ')
    {
        board[6] = 'X';
        return 1;
    }
    else if (board[2] == '0' && board[1] == 'X' && board[5] == 'X' && board[7] == '0' && board[9] == ' ')
    {
        board[9] = 'X';
        return 1;
    }
    else if (board[6] == '0' && board[9] == 'X' && board[5] == 'X' && board[7] == '0' && board[1] == ' ')
    {
        board[1] = 'X';
        return 1;
    }
    else if (board[3] == '0' && board[2] == 'X' && board[5] == 'X' && board[7] == '0' && board[8] == ' ')
    {
        board[8] = 'X';
        return 1;
    }
    else if (board[3] == '0' && board[6] == 'X' && board[5] == 'X' && board[7] == '0' && board[4] == ' ')
    {
        board[4] = 'X';
        return 1;
    }
    else if (board[3] == '0' && board[8] == 'X' && board[5] == 'X' && board[7] == '0' && board[2] == ' ')
    {
        board[2] = 'X';
        return 1;
    }
    else if (board[3] == '0' && board[4] == 'X' && board[5] == 'X' && board[7] == '0' && board[6] == ' ')
    {
        board[6] = 'X';
        return 1;
    }
    else if (board[3] == '0' && board[6] == 'X' && board[5] == 'X' && board[8] == '0' && board[4] == ' ')
    {
        board[4] = 'X';
        return 1;
    }

    return 0;
}

int interrupt_to_opponent_winning()
{
    if (board[1] == board[2] && board[1] != ' ' && board[3] == ' ')
    {
        board[3] = 'X';
        return 1;
    }
    else if (board[1] == board[3] && board[1] != ' ' && board[2] == ' ')
    {
        board[2] = 'X';
        return 1;
    }
    else if (board[2] == board[3] && board[2] != ' ' && board[1] == ' ')
    {
        board[1] = 'X';
        return 1;
    }
    else if (board[1] == board[4] && board[1] != ' ' && board[7] == ' ')
    {
        board[7] = 'X';
        return 1;
    }
    else if (board[1] == board[7] && board[1] != ' ' && board[4] == ' ')
    {
        board[4] = 'X';
        return 1;
    }
    else if (board[4] == board[7] && board[4] != ' ' && board[1] == ' ')
    {
        board[1] = 'X';
        return 1;
    }
    else if (board[4] == board[5] && board[4] != ' ' && board[6] == ' ')
    {
        board[6] = 'X';
        return 1;
    }
    else if (board[4] == board[6] && board[4] != ' ' && board[5] == ' ')
    {
        board[5] = 'X';
        return 1;
    }
    else if (board[5] == board[6] && board[5] != ' ' && board[4] == ' ')
    {
        board[4] = 'X';
        return 1;
    }
    else if (board[7] == board[8] && board[7] != ' ' && board[9] == ' ')
    {
        board[9] = 'X';
        return 1;
    }
    else if (board[7] == board[9] && board[7] != ' ' && board[8] == ' ')
    {
        board[8] = 'X';
        return 1;
    }
    else if (board[8] == board[9] && board[8] != ' ' && board[7] == ' ')
    {
        board[7] = 'X';
        return 1;
    }
    else if (board[2] == board[5] && board[2] != ' ' && board[8] == ' ')
    {
        board[8] = 'X';
        return 1;
    }
    else if (board[2] == board[8] && board[2] != ' ' && board[5] == ' ')
    {
        board[5] = 'X';
        return 1;
    }
    else if (board[5] == board[8] && board[5] != ' ' && board[2] == ' ')
    {
        board[2] = 'X';
        return 1;
    }
    else if (board[3] == board[6] && board[3] != ' ' && board[9] == ' ')
    {
        board[9] = 'X';
        return 1;
    }
    else if (board[3] == board[9] && board[3] != ' ' && board[6] == ' ')
    {
        board[6] = 'X';
        return 1;
    }
    else if (board[6] == board[9] && board[6] != ' ' && board[3] == ' ')
    {
        board[3] = 'X';
        return 1;
    }
    else if (board[1] == board[5] && board[1] != ' ' && board[9] == ' ')
    {
        board[9] = 'X';
        return 1;
    }
    else if (board[1] == board[9] && board[1] != ' ' && board[5] == ' ')
    {
        board[5] = 'X';
        return 1;
    }
    else if (board[5] == board[9] && board[5] != ' ' && board[1] == ' ')
    {
        board[1] = 'X';
        return 1;
    }
    else if (board[3] == board[5] && board[3] != ' ' && board[7] == ' ')
    {
        board[7] = 'X';
        return 1;
    }
    else if (board[3] == board[7] && board[3] != ' ' && board[5] == ' ')
    {
        board[5] = 'X';
        return 1;
    }
    else if (board[5] == board[7] && board[5] != ' ' && board[3] == ' ')
    {
        board[3] = 'X';
        return 1;
    }

    return 0;
}

void special_case_for_move_two()
{
    if (board[1] == 'X' && board[5] == '0' && board[9] == '0')
    {
        int value = get_keysquare(3, 7);
        board[value] = 'X';
    }
    else if (board[3] == 'X' && board[5] == '0' && board[7] == '0')
    {
        int value = get_keysquare(1, 9);
        board[value] = 'X';
    }
    else if (board[9] == 'X' && board[5] == '0' && board[1] == '0')
    {
        int value = get_keysquare(3, 7);
        board[value] = 'X';
    }
    else if (board[7] == 'X' && board[5] == '0' && board[3] == '0')
    {
        int value = get_keysquare(1, 9);
        board[value] = 'X';
    }
    else if (board[1] == '0' && board[5] == 'X' && board[6] == '0')
    {
        board[3] = 'X';
    }
    else if (board[1] == '0' && board[5] == 'X' && board[8] == '0')
    {
        board[7] = 'X';
    }
    else if (board[3] == '0' && board[5] == 'X' && board[4] == '0')
    {
        board[1] = 'X';
    }
    else if (board[3] == '0' && board[5] == 'X' && board[8] == '0')
    {
        board[9] = 'X';
    }
    else if (board[2] == '0' && board[5] == 'X' && board[9] == '0')
    {
        board[3] = 'X';
    }
    else if (board[4] == '0' && board[5] == 'X' && board[9] == '0')
    {
        board[7] = 'X';
    }
    else if (board[2] == '0' && board[5] == 'X' && board[7] == '0')
    {
        board[1] = 'X';
    }
    else if (board[6] == '0' && board[5] == 'X' && board[7] == '0')
    {
        board[9] = 'X';
    }
    else if (board[1] == '0' && board[5] == 'X' && board[9] == '0')
    {
        int value = get_keysquare_for_four(2, 4, 6, 8);
        board[value] = 'X';
    }
    else if (board[3] == '0' && board[5] == 'X' && board[7] == '0')
    {
        int value = get_keysquare_for_four(2, 4, 6, 8);
        board[value] = 'X';
    }
    else if (board[2] == '0' && board[5] == 'X' && board[4] == '0')
    {
        int value = get_keysquare_for_three(1, 3, 7);
        board[value] = 'X';
    }
    else if (board[2] == '0' && board[5] == 'X' && board[6] == '0')
    {
        int value = get_keysquare_for_three(1, 3, 9);
        board[value] = 'X';
    }
    else if (board[2] == '0' && board[5] == 'X' && board[7] == '0')
    {
        int value = get_keysquare_for_four(1, 3, 4, 6);
        board[value] = 'X';
    }
    else if (board[2] == '0' && board[5] == 'X' && board[9] == '0')
    {
        int value = get_keysquare_for_four(1, 3, 4, 6);
        board[value] = 'X';
    }
    else if (board[2] == '0' && board[5] == 'X' && board[8] == '0')
    {
        int value = get_keysquare_for_four(1, 3, 7, 9);
        board[value] = 'X';
    }
    else if (board[1] == '0' && board[5] == 'X' && board[8] == '0')
    {
        int value = get_keysquare_for_three(4, 7, 9);
        board[value] = 'X';
    }
    else if (board[3] == '0' && board[5] == 'X' && board[8] == '0')
    {
        int value = get_keysquare_for_three(6, 7, 9);
        board[value] = 'X';
    }
    else if (board[4] == '0' && board[5] == 'X' && board[8] == '0')
    {
        int value = get_keysquare_for_three(1, 7, 9);
        board[value] = 'X';
    }
    else if (board[6] == '0' && board[5] == 'X' && board[8] == '0')
    {
        int value = get_keysquare_for_three(3, 7, 9);
        board[value] = 'X';
    }
    else if (board[1] == '0' && board[5] == 'X' && board[6] == '0')
    {
        int value = get_keysquare_for_three(2, 3, 9);
        board[value] = 'X';
    }
    else if (board[2] == '0' && board[5] == 'X' && board[6] == '0')
    {
        int value = get_keysquare_for_three(1, 3, 9);
        board[value] = 'X';
    }
    else if (board[4] == '0' && board[5] == 'X' && board[6] == '0')
    {
        int value = get_keysquare_for_four(1, 3, 7, 9);
        board[value] = 'X';
    }
    else if (board[6] == '0' && board[5] == 'X' && board[7] == '0')
    {
        int value = get_keysquare_for_four(2, 3, 8, 9);
        board[value] = 'X';
    }
    else if (board[3] == '0' && board[5] == 'X' && board[4] == '0')
    {
        int value = get_keysquare_for_three(1, 3, 7);
        board[value] = 'X';
    }
    else if (board[4] == '0' && board[5] == 'X' && board[9] == '0')
    {
        int value = get_keysquare_for_three(1, 7, 8);
        board[value] = 'X';
    }
    else
    {
        for (int i = 1; i <= 9; i++)
        {
            if (board[i] == ' ')
            {
                board[i] = 'X';
                puts("Didn't match any case");
                break;
            }
        }
    }

    return;
}

void special_case_for_move_three()
{
    for (int i = 1; i <= 9; i++)
    {
        if (board[i] == ' ')
        {
            board[i] = 'X';
            puts("Didn't match any case");
            break;
        }
    }
}

void special_case_for_move_four()
{
    for (int i = 1; i <= 9; i++)
    {
        if (board[i] == ' ')
        {
            board[i] = 'X';
            puts("Didn't match any case");
            break;
        }
    }
}

int get_keysquare_for_three(int n1, int n2, int n3)
{
    while (1)
    {
        int value = (rand() % 9) + 1;
        if (value == n1 || value == n2 || value == n3)
        {
            return value;
        }
    }
}

int get_keysquare_for_four(int n1, int n2, int n3, int n4)
{
    while (1)
    {
        int value = (rand() % 9) + 1;

        if (value == n1 || value == n2 || value == n3 || value == n4)
        {
            return value;
        }
    }
}

int get_keysquare(int n1, int n2)
{
    while (1)
    {
        int value = (rand() % 9) + 1;
        if (value == n1 || value == n2)
        {
            return value;
        }
    }
}

void winner_declare(char player)
{
    if (player == '0')
    {
        puts("***Congratulation***\n");
        printf("%s is win\n", name);
    }
    else
    {
        puts("***Congratulation***\n");
        puts("Computer win\n");
    }
}

int win_check()
{
    if (board[1] == board[2] && board[2] == board[3] && board[1] != ' ')
    {
        return 1;
    }
    else if (board[4] == board[5] && board[5] == board[6] && board[4] != ' ')
    {
        return 1;
    }
    else if (board[7] == board[8] && board[8] == board[9] && board[8] != ' ')
    {
        return 1;
    }
    else if (board[1] == board[4] && board[4] == board[7] && board[7] != ' ')
    {
        return 1;
    }
    else if (board[2] == board[5] && board[5] == board[8] && board[5] != ' ')
    {
        return 1;
    }
    else if (board[3] == board[6] && board[6] == board[9] && board[6] != ' ')
    {
        return 1;
    }
    else if (board[1] == board[5] && board[5] == board[9] && board[9] != ' ')
    {
        return 1;
    }
    else if (board[3] == board[5] && board[5] == board[7] && board[7] != ' ')
    {
        return 1;
    }
    else if (move == 5)
    {
        return -1;
    }

    return 0;
}

void display_board()
{
    printf("\n\n");
    printf("        |        |        \n");
    printf("   %c    |   %c    |   %c   \n", board[1], board[2], board[3]);
    printf("        |        |        \n");
    printf("-------------------------- \n");
    printf("        |        |        \n");
    printf("   %c    |   %c    |   %c   \n", board[4], board[5], board[6]);
    printf("        |        |        \n");
    printf("--------------------------\n");
    printf("        |        |        \n");
    printf("   %c    |   %c    |   %c   \n", board[7], board[8], board[9]);
    printf("        |        |        \n");
}
