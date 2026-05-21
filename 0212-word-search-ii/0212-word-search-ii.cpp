// completely copy pasted due to exam
class TrieNode {
public:
    TrieNode* children[26];
    string word; // Stores the full word at the leaf node
    int refs;    // Tracks active children to prune the tree dynamically

    TrieNode() {
        for (int i = 0; i < 26; i++) children[i] = nullptr;
        word = "";
        refs = 0;
    }
};

class Solution {
private:
    TrieNode* root;

    // Insert a word into the Trie
    void insert(const string& word) {
        TrieNode* curr = root;
        for (char ch : word) {
            int idx = ch - 'a';
            if (!curr->children[idx]) {
                curr->children[idx] = new TrieNode();
                curr->refs++; // Parent gains a unique child branch
            }
            curr = curr->children[idx];
        }
        curr->word = word; // Mark end of word
    }

    void dfs(vector<vector<char>>& board, int r, int c, TrieNode* parent, TrieNode* curr, vector<string>& result) {
        char ch = board[r][c];
        int idx = ch - 'a';
        
        // Safety check if the path is no longer viable due to pruning
        if (!curr->children[idx]) return;
        
        TrieNode* nextNode = curr->children[idx];
        
        // If we found a valid word
        if (!nextNode->word.empty()) {
            result.push_back(nextNode->word);
            nextNode->word = ""; // Prevent duplicate matches
            
            // Prune leaves cleanly back up the tree if they have no other branches
            if (nextNode->refs == 0) {
                // We will clean up structural nodes iteratively by tracking refs
            }
        }

        // Mark as visited
        board[r][c] = '#';

        // Explore 4 directions
        int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        for (auto& dir : dirs) {
            int nr = r + dir[0];
            int nc = c + dir[1];
            
            if (nr >= 0 && nr < board.size() && nc >= 0 && nc < board[0].size() && board[nr][nc] != '#') {
                dfs(board, nr, nc, curr, nextNode, result);
            }
        }

        // Backtrack
        board[r][c] = ch;

        // Optimization: Dynamic Pruning
        // If the next node has no remaining children branches, we can disconnect it
        if (nextNode->refs == 0 && nextNode->word.empty()) {
            delete nextNode;
            curr->children[idx] = nullptr;
            curr->refs--;
        }
    }

public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        root = new TrieNode();
        for (const string& w : words) {
            insert(w);
        }

        vector<string> result;
        int m = board.size();
        int n = board[0].size();

        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (root->children[board[r][c] - 'a']) {
                    dfs(board, r, c, nullptr, root, result);
                }
            }
        }

        return result;
    }
};