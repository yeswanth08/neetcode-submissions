class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int r=board.size(),c=board[0].size();
        for (int i=0; i<r; ++i){
            for (int j=0; j<c; ++j){
                char ele = board[i][j];
                if (ele=='.') continue;
                // row
                for (int k=0; k<c; ++k){
                    if (k!=j){
                        if (board[i][k]==ele){
                            return false;
                        }
                    }
                }
                // col
                for (int l=0; l<r; ++l){
                    if (l!=i){
                        if (board[l][j]==ele){
                            return false;
                        }
                    }
                }
                // grid
                // 0.0 0.1 0.2 | 1.0 1.1 1.2 | 2.0 2.1 2.2 | 
                // 0.3 0.5 | 1.3 1.5 | 2.3 2.5
                // locate grid
                int gr=0, gc=0;
                if (i<=2 && j<=2){
                    gr=0;
                    gc=0;
                }
                else if (i<=2 && j<=5){
                    gr=0;
                    gc=3;
                }
                else if (i<=2 && j<=8){
                    gr=0;
                    gc=6;
                }
                else if (i<=5 && j<=2){
                    gr=3;
                    gc=0;
                }
                else if (i<=5 && j<=5){
                    gr=3;
                    gc=3;
                }
                else if (i<=5 && j<=8){
                    gr=3;
                    gc=6;
                }
                else if (i<=8 && j<=2){
                    gr=6;
                    gc=0;
                }
                else if (i<=8 && j<=5){
                    gr=6;
                    gc=3;
                }
                else if (i<=8 && j<=8){
                    gr=6;
                    gc=6;
                }

                // grid;
                for (int m=gr; m<gr+3; ++m){
                    for (int n=gc; n<gc+3; ++n){
                        if ((m!=i && n!=j)&&board[m][n]==ele){
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    }
};
