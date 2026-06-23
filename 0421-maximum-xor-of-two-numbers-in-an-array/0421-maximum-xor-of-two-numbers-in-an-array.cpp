class Solution {
    private: 
    class Node{
        public:
        Node* children[2];
        Node(){
            children[1] = NULL;
            children[0] = NULL;
        }
    };
    class Trie{
        Node*  root;
        public:
        Trie(){
            root = new Node();
        }
        void insert(int num){
            Node* temp = root;
            for(int i = 31 ; i >= 0 ; i--){
            int bit = num>>i & 1;
            if(temp->children[bit] == NULL){
                temp->children[bit] = new Node();
            }
            temp = temp->children[bit];
            }
        }

        // now logic for finding maximum XOR of a number with given digit;
        
        int getMax(int x){
            int ans = 0;
            Node* temp = root;
            for(int i = 31 ; i >= 0 ; i--){
                int bit = x>>i & 1;
                if(temp->children[!bit] != NULL){
                    ans = ans | (1<<i);
                    temp = temp->children[ !bit];
                }else{
                    temp = temp->children[bit];
                }
            }
            return ans;
        }
    };
    public:
    int findMaximumXOR(vector<int>& nums) {
        int ans = 0;
        Trie trie;
        for(int i : nums) trie.insert(i);
        for(int i : nums)ans = max(ans ,trie.getMax(i));
        return ans;
    }
};