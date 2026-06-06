#include <iostream>
using namespace std;

const int MAX = 20;

char board[MAX][MAX];
int totalSolutions = 0;
bool findAll = true;

// Check if it is safe to place the queen at any point/ cell
bool isSafe(int row, int col, int n)
{
  // Check column
  for (int i = 0; i < row; i++)
  {

    if (board[i][col] == 'Q')
      return false;
  }

  // Check left diagonal
  for (int i = row - 1, j = col - 1;
       i >= 0 && j >= 0;
       i--, j--)
  {

    if (board[i][j] == 'Q')
      return false;
  }

  // Check right diagonal
  for (int i = row - 1, j = col + 1;
       i >= 0 && j < n;
       i--, j++)
  {

    if (board[i][j] == 'Q')
      return false;
  }

  return true;
}

// Print board
void printBoard(int n)
{
  cout << "Solution #" << totalSolutions << ":\n\n";

  for (int i = 0; i < n; i++)
  {

    for (int j = 0; j < n; j++)
    {
      cout << board[i][j] << " ";
    }

    cout << endl;
  }

  cout << endl;
}

// Solve function
bool solve(int row, int n)
{
  // Solution found
  if (row == n)
  {

    totalSolutions++;

    printBoard(n);

    // Stop after first solution
    if (!findAll)
      return true;

    return false;
  }

  for (int col = 0; col < n; col++)
  {

    if (isSafe(row, col, n))
    {

      board[row][col] = 'Q';

      // If first solution only
      if (solve(row + 1, n) && !findAll)
        return true;

      // Backtrack
      board[row][col] = '.';
    }
  }

  return false;
}

int main()
{
  int n;
  char choice;

  cout << "Enter value of N: ";
  cin >> n;

  cout << "Find all solutions? (y/n): ";
  cin >> choice;

  if (choice == 'y' || choice == 'Y')
    findAll = true;
  else
    findAll = false;

  // Fill board with dots
  for (int i = 0; i < n; i++)
  {

    for (int j = 0; j < n; j++)
    {
      board[i][j] = '.';
    }
  }

  solve(0, n);

  cout << "Total Solutions: "
       << totalSolutions << endl;

  return 0;
}
