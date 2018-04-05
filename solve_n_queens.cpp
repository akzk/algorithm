/*
    lintcode 33, n皇后问题
    递归
*/
#include <vector>
using namespace std;

class Solution {
public:
    /*
     * @param n: The number of queens
     * @return: All distinct solutions
     */
    vector<vector<string>> solveNQueens(int n) {
        // write your code here
        vector<string> board(n, string(n, '.'));
        vector<vector<string>> res;
        solveNQueensHelper(board, res, n, 0);
        return res;
    }

    void solveNQueensHelper(vector<string> &board, vector<vector<string>> &res, int n, int i)
    {
        if (i == n) {
            res.push_back(board);
            return;
        }
        for (int j=0; j<n; j++)
        {
            if (isok(board, n, i, j)) {
                board[i][j] = 'Q';
                solveNQueensHelper(board, res, n, i+1);
                board[i][j] = '.';
            }
        }
    }

    bool isok(vector<string> &board, int n, int i, int j)
    {
        for (int t=0; t<i; t++)
            if (board[t][j] == 'Q') return false;
        for (int t=1; t<=min(i,j); t++)
            if (board[i-t][j-t] == 'Q') return false;
        for (int t=1; t<=min(i,n-j); t++)
            if (board[i-t][j+t] == 'Q') return false;
        return true;
    }
};