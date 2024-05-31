class Trienode {
    public:
    Trienode* links[26];
    bool isend;

    Trienode(){
        for(int i=0;i<26;i++)
        {
            links[i] = NULL;
        }
        isend = false;
    }
};
class Trie {
    private:
    Trienode* root;
public:
    Trie() {
         root = new Trienode();
    }
    
    void insert(string word) {
        Trienode* node = root;
        int cur = 0;

        for(int i=0;i<word.size();i++)
        {
            cur = word[i] - 'a';
            if(node->links[cur]==NULL)
            {
                node->links[cur] = new Trienode();
            }
            node = node->links[cur];
        }
        node->isend = true;
    }
    
    bool search(string word) {
        Trienode* node = root;
        int cur = 0;

        for(int i=0;i<word.size();i++)
        {
            cur = word[i] - 'a';
            if(node->links[cur] == NULL) 
            return false;

            node = node->links[cur];
        }
        return node->isend;
    }
    
    bool startsWith(string prefix) {
        Trienode* node = root;
        int cur = 0;

        for(int i=0;i<prefix.size();i++)
        {
            cur = prefix[i] - 'a';
            if(node->links[cur] == NULL) return false;

            node = node->links[cur];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
