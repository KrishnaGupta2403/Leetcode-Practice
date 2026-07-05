class Solution {
public:
    struct TrieNode {
        bool end;
        unordered_map<char, TrieNode*> child;

        TrieNode() {
            end = false;
        }
    };

    TrieNode* getNode() {
        return new TrieNode();
    }

    void insert(TrieNode* root, string &word) {
        TrieNode* curr = root;

        for (char ch : word) {
            if (curr->child.find(ch) == curr->child.end())
                curr->child[ch] = getNode();

            curr = curr->child[ch];
        }

        curr->end = true;
    }

    bool dfs(TrieNode* root, int i, int j,
             vector<vector<char>>& board,
             int row, int col) {

        if (i < 0 || i >= row || j < 0 || j >= col || board[i][j] == '#')
            return false;

        char ch = board[i][j];

        if (root->child.find(ch) == root->child.end())
            return false;

        root = root->child[ch];

        if (root->end)
            return true;

        board[i][j] = '#';

        bool found =
            dfs(root, i - 1, j, board, row, col) ||
            dfs(root, i + 1, j, board, row, col) ||
            dfs(root, i, j - 1, board, row, col) ||
            dfs(root, i, j + 1, board, row, col);

        board[i][j] = ch;

        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {

        int row = board.size();
        int col = board[0].size();

        TrieNode* root = getNode();

        insert(root, word);

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {

                if (root->child.find(board[i][j]) != root->child.end()) {

                    if (dfs(root, i, j, board, row, col))
                        return true;
                }
            }
        }

        return false;
    }
};