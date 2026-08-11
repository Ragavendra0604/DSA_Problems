class LRUCache {
private:
    struct Node{
        int key;
        int value;
        Node* prev;
        Node* next;

        Node(int _key, int _value){
            key = _key;
            value = _value;
            prev = nullptr;
            next = nullptr;
        }
    };
    int capacity;
    unordered_map<int, Node*> mp;

    Node* head;
    Node* tail;

    void AddNode(Node* node){
        node -> prev = head;
        node -> next = head -> next;
        head -> next -> prev = node;
        head -> next = node;
    }

    void DeleteNode(Node* node){
        Node* prevNode = node -> prev;
        Node* nextNode = node -> next;

        prevNode -> next = nextNode;
        nextNode -> prev = prevNode;
    }

    void moveToHead(Node* node){
        DeleteNode(node);
        AddNode(node);
    }
public:
    LRUCache(int cap) {
        capacity = cap;
        head = new Node(0, 0);
        tail = new Node(0, 0);

        head -> next = tail;
        tail -> prev = head;
    }
    
    int get(int key) {
        if(mp.find(key) == mp.end()){
            return -1;
        }

        Node* node = mp[key];
        moveToHead(node);
        return node->value;
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end()){
            Node* node = mp[key];
            node -> value = value;
            moveToHead(node);
        }
        else{
            Node* newNode = new Node(key, value);
            mp[key] = newNode;
            AddNode(newNode);

            if(mp.size() > capacity){
                Node* lruNode = tail -> prev;
                mp.erase(lruNode -> key);
                DeleteNode(lruNode);
                delete lruNode;
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */