class LRUCache {
public:
    class node {
        public:
        node* next;
        node* prev;
        int key;
        int value;

        node(int key,int value)
        {
            this->key = key;
            this->value = value;
        }
    };

    node* head = new node(-1,-1);
    node* tail = new node(-1,-1);

    int cap;
    unordered_map<int,node*> mp;

    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }

    void insert(node* temp)
    {
        node* headnext = head->next;
        temp->next= headnext;
        headnext->prev = temp;
        temp->prev = head;
        head->next = temp;
    }

    void remove(node* temp)
    {
        node* tempnext = temp->next;
        node* tempprev = temp->prev;
        tempnext->prev = temp->prev;
        tempprev->next = tempnext;
        tempnext->prev = tempprev;
    }
    
    int get(int key) {
        if(mp.find(key)==mp.end()) return -1;
        node *curr = mp[key];
        int val = curr->value;
        mp.erase(key);
        remove(curr);
        insert(curr);
        mp[key] = head->next;
        return val;        
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end())
        {
            node *curr = mp[key];
            mp.erase(key);
            remove(curr);
        }
        if(cap==mp.size())
        {
            node* cur = mp[tail->prev->key];
            mp.erase(tail->prev->key);
            remove(cur);
        }
        insert(new node(key,value));
        mp[key] = head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
