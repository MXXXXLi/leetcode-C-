class Trie {
public:
    vector<Trie*> children;
    bool isEnd;
    Trie() :children(26),isEnd(false){
        
    }
    
    void insert(string word) {
        Trie* node = this;
        for(char ch:word){
            int value = ch -'a';
            if(!node->children[value])
                node->children[value] = new Trie();
            node = node->children[value];
        }
        node->isEnd = true;
    }
    
    bool search(string word) {
        Trie* node = this;
        for(char ch:word){
            int value = ch - 'a';
            if(!node->children[value])
                return false;
            node = node->children[value];
        }
        if(node&&node->isEnd)
            return true;
        else
            return false;
    }
    
    bool startsWith(string prefix) {
        Trie* node = this;
        for(char ch:prefix){
            int value = ch - 'a';
            if(!node->children[value])
                return false;
            node = node->children[value];
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