class Solution {
    class Trie{
        private: 

        class Node{
            public:
            Node* children[2];
            Node(){
                children[1] = NULL;
                children[0] = NULL;
            }
        };
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
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {\
        vector<vector<int>>Q_sorted;
        int Q_size = queries.size();
        for(int i = 0 ; i < Q_size ; i++){
            int a = queries[i][0], b = queries[i][1];
            Q_sorted.push_back({b,a,i});
        }

        sort(Q_sorted.begin() , Q_sorted.end());
        sort(nums.begin() , nums.end());

        vector<int>ans(Q_size , -1);
        int j = 0 , n = nums.size();
        Trie trie;
        for(int i = 0 ; i < Q_size ;i++){
            while(j < n && nums[j] <= Q_sorted[i][0])
                trie.insert(nums[j++]);   
            
            if(j>0) ans[Q_sorted[i][2]] = trie.getMax(Q_sorted[i][1]);
        }

        return ans;
    }
};