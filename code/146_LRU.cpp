class LRUCache {
    struct biDirecList{
        biDirecList* pre;
        biDirecList* next;
        int key, value;
        biDirecList():key(0),value(0),pre(nullptr),next(nullptr){}
        biDirecList(int _key, int _value):key(_key),value(_value),pre(nullptr),next(nullptr){}
    };
public:
    biDirecList* head;
    biDirecList* tail;
    unordered_map<int,biDirecList*> cache;
    int _len;
    int  _capacity;
    LRUCache(int capacity) {
        head = new biDirecList();
        tail = new biDirecList();
        head->next = tail;
        tail->pre = head;
        _len = 0;
        _capacity = capacity; 
    }
    
    int get(int key) {
        if(!cache.count(key)) {
            return -1;
        } else {
            biDirecList* node = cache[key];
            moveToHead(node);
            return node->value;
        }       
    }
    
    void put(int key, int value) {
        if(cache.count(key))
        {
            cache[key]->value = value;
            moveToHead(cache[key]);
        } else{
            if(++_len>_capacity){
                biDirecList* node = new biDirecList(key,value);
                biDirecList* nodeEnd = tail->pre;
                cache.erase(nodeEnd->key);
                removeTail();
                delete nodeEnd;
                addHead(node);
                cache[node->key] = node;
            }else{
                biDirecList* node = new biDirecList(key,value);
                addHead(node);
                cache[node->key] = node;
            }
        }
    }
    void addHead(biDirecList* node){
        biDirecList* tmp = head->next;
        head->next = node;
        node->next = tmp;
        tmp->pre = node;
        node->pre = head;
    }

    void removeTail(){
        biDirecList* nodetail = tail->pre;
        biDirecList* nodeNewTail = nodetail->pre;
        nodeNewTail->next = tail;
        tail->pre = nodeNewTail;
    }

    void removeNode(biDirecList* node){
        biDirecList* preNode = node->pre;
        biDirecList* nextNode = node->next;
        preNode->next = nextNode;
        nextNode->pre = preNode;
    }

    void moveToHead(biDirecList* node){
        removeNode(node);
        addHead(node);
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */