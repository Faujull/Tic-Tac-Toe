/*
███████╗░█████╗░██╗░░░██╗░░░░░██╗██╗░░░██╗██╗░░░░░
██╔════╝██╔══██╗██║░░░██║░░░░░██║██║░░░██║██║░░░░░
█████╗░░███████║██║░░░██║░░░░░██║██║░░░██║██║░░░░░
██╔══╝░░██╔══██║██║░░░██║██╗░░██║██║░░░██║██║░░░░░
██║░░░░░██║░░██║╚██████╔╝╚█████╔╝╚██████╔╝███████╗
╚═╝░░░░░╚═╝░░╚═╝░╚═════╝░░╚════╝░░╚═════╝░╚══════╝
*/
#include <bits/stdc++.h>
using namespace std;

char board[3][3];
string playerX, playerY;

// Initialize the board with 1-9
void initialBoard()
{
    char start = '1';
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            board[i][j] = start++;
        }
    }
}

// Display the board
void displayBoard()
{
    cout << "\n";
    for(int i = 0; i < 3; i++)
    {
        cout << " ";
        for(int j = 0; j < 3; j++)
        {
            cout << board[i][j];
            if(j < 2)
            {
                cout << " | ";
            }
        }
        cout << endl;
        if(i < 2)
        {
            cout << "---|---|---\n";
        }
    }
    cout << endl;
}

// Check if current player has won
bool checkWin(char player)
{
    for(int i = 0; i < 3; i++)
    {
        if((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
           (board[0][i] == player && board[1][i] == player && board[2][i] == player))
            return true;
    }

    // Diagonals
    if((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
       (board[0][2] == player && board[1][1] == player && board[2][0] == player))
        return true;

    return false;
}

// Check for draw
bool isDraw()
{
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            if(board[i][j] != 'X' && board[i][j] != 'O')
                return false;
        }
    }
    return true;
}

// Handle player move
void playerMove(string name, char symbol)
{
    int move;
    while (true)
    {
        cout << name << " (" << symbol << "), enter your move (1-9): ";
        cin >> move;
        if (move < 1 || move > 9)
        {
            cout << "Invalid input. Try again.\n";
            continue;
        }

        int row = (move - 1) / 3;
        int col = (move - 1) % 3;

        if(board[row][col] != 'X' && board[row][col] != 'O')
        {
            board[row][col] = symbol;
            break;
        }
        else
        {
            cout << "Cell already taken. Try again.\n";
        }
    }
}

// Two player game loop
void twoPlayerGame()
{
    initialBoard();
    displayBoard();

    char currentSymbol = 'X';
    string currentPlayer = playerX;

    while (true)
    {
        playerMove(currentPlayer, currentSymbol);
        displayBoard();

        if (checkWin(currentSymbol))
        {
            cout << currentPlayer << " wins! \n";
            break;
        }

        if (isDraw())
        {
            cout << "It's a draw! \n";
            break;
        }

        // Switch player
        if (currentSymbol == 'X')
        {
            currentSymbol = 'O';
            currentPlayer = playerY;
        }
        else
        {
            currentSymbol = 'X';
            currentPlayer = playerX;
        }
    }
}

// Main function
int main()
{
    cout << "=== Tic Tac Toe ===\n";
    cout << "Enter name for Player X: ";
    getline(cin, playerX);
    cout << "Enter name for Player O: ";
    getline(cin, playerY);
    twoPlayerGame();

    cout << "Thanks for playing, " << playerX << " and " << playerY << "! \n";
    return 0;
}
