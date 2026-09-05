class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            unordered_set<char> st;
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    if (st.find(board[i][j]) != st.end()) return false;
                    st.insert(board[i][j]);
                }
            }
        }
        for (int i = 0; i < 9; i++) {
            unordered_set<int> st;
            for (int j = 0; j < 9; j++) {
                if (board[j][i] != '.') {
                    if (st.find(board[j][i]) != st.end()) return false;
                    st.insert(board[j][i]);
                }
            }
        }
        for (int i = 0; i < 9; i++) {
            unordered_set<int> st;
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 3; k++) {
                    int row = i / 3 * 3 + j;
                    int col = i % 3 * 3 + k;
                    if (board[row][col] != '.') {
                        if (st.find(board[row][col]) != st.end()) return false;
                        st.insert(board[row][col]);
                    }
                }
            }
        }
        return true;
    }
};
