class Solution {
    public void solveSudoku(char[][] board) {
        helper(board);
    }

    boolean helper(char[][] board){
        int n=board.length;
        int m=board[0].length;

        for (int i=0;i<n;i++){
            for (int j=0;j<m;j++){
                if (board[i][j]=='.'){

                    for (char ch='1';ch<='9';ch++){
                        if (isPossible(board,i,j,ch)){
                         board[i][j]=ch;

                        if (helper(board)) return true;
                        else board[i][j]='.';
                        }
                    }
                       return false;
                }
            }
        }
        return true;
    }

    boolean isPossible(char[][] board,int row,int col,char ch){
        for (int i=0;i<9;i++){
            if (board[row][i]==ch) return false;
            if (board[i][col]==ch) return false;
            if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == ch) return false;
        }

        return true;
    }
}