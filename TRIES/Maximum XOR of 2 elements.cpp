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
    int findMaximumXOR(vector<int>& nums) {
        Trie trie;
        for(int i=0;i<nums.size();i++)
        {
            trie.insert(nums[i]);
        }
        int maxi = 0;
        for(int i=0;i<nums.size();i++)
        {
            maxi = max(maxi , trie.maxx(nums[i]));
        }
        return maxi;
    }
};
