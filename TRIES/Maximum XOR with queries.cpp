class Trienode {
    public:
     Trienode* bits[2];

     Trienode(){
        bits[0] = NULL;
        bits[1] = NULL;
     }
};
class Trie {
    private:
     Trienode* root;

    public:
     Trie()
     {
        root = new Trienode();
     }
     void insert(int num)
     {
        Trienode* node = root;
        for(int i=31;i>=0;i--)
        {
            int bit = num>>i & 1;
            if(node->bits[bit]==NULL)
            {
                node->bits[bit] = new Trienode();
            }
            node = node->bits[bit];
        }
     }
     int maxx(int num)
     {
        Trienode* node = root;
        int ans = 0;
        for(int i=31;i>=0;i--)
        {
            int bit = num>>i & 1;
            if(node->bits[!bit])
            {
                ans = ans | (1<<i);
                node = node->bits[!bit];
            }
            else
            {
                node = node->bits[bit];
            }
        }
        return ans;
     }
};
class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> ans(queries.size(),0);
        sort(nums.begin(),nums.end());
        vector<pair<int,pair<int,int>>> q;
        for(int i=0;i<queries.size();i++)
        {
            q.push_back({queries[i][1],{queries[i][0],i}});
        }
        sort(q.begin(),q.end());
        int n = nums.size(); 
        Trie trie; 
        int i=0;
   
    for(auto &it : q) {
        while(i < n && nums[i] <= it.first) {
            trie.insert(nums[i]); 
            i++; 
        }
        if(i != 0) 
            ans[it.second.second] = trie.maxx(it.second.first); 
        else 
            ans[it.second.second] = -1; 
    }
    return ans; 
    }
};
