#include <bits/stdc++.h>
#include <vector>
using namespace std;

bool isSafe(int row, int col, const vector<vector<int>> &board, int n) {
    // Check vertical up
    for (int i = 0; i < row; i++) {
        if (board[i][col] == 1) return false;
    }

    // Check upper-left diagonal
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1) return false;
    }

    // Check upper-right diagonal
    for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
        if (board[i][j] == 1) return false;
    }

    return true;
}
void printBoard(vector<vector<int>> &board, int solutionCount) {
    cout<<"solution no : "<<solutionCount+1<<endl;
    for (const auto &row : board) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
}

void solve(int row, vector<vector<int>> &board, int n, int &solutionCount) {
    if (row == n) {
        printBoard(board, solutionCount);
        solutionCount++;
        return;
    }
    

    for (int col = 0; col < n; col++) {
        if (isSafe(row, col, board, n)) {
            board[row][col] = 1; // Place queen
            solve(row + 1, board, n,solutionCount);
            board[row][col] = 0; // Backtrack
        }
    }

    return;
}



int main() {
  int n;
  cout << "Enter board size: ";
  cin >> n;

  vector<vector<int>> board(n, vector<int>(n, 0));
  int solutionCount = 0;

  solve(0, board, n, solutionCount);

  if (solutionCount == 0) {
      cout << "No solution exists.\n";
  } else {
      cout << "Total solutions found: " << solutionCount << endl;
  }

  return 0;
}
