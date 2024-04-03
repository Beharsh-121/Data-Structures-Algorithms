int m, n;
    vector<vector<int>> directions{ {1, 0},
                     {0, -1},                     {0, 1},
                                    {-1, 0}
    };
    bool find(int i, int j, string word, vector<vector<char>>& board, int idx){
        if(idx == word.length()) return true;
        if(i < 0 || j < 0|| i >= m || j >= n || board[i][j] == '$') return false;
        if(board[i][j] != word[idx]) return false;

        char temp = board[i][j];
        board[i][j] = '$';
        for(int k = 0; k < 4; k++){
             int new_i = i + directions[k][0];
             int new_j = j + directions[k][1];
             if(find(new_i, new_j, word, board, idx+1)) return true;
        }
        board[i][j] = temp;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size(), n = board[0].size();

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == word[0] and find(i, j, word, board, 0)) return true;
            }
        }
        return false;
    }