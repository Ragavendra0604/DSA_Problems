class LFUCache {
private:
    struct Node{
        int key;
        int value;
        int freq;
        Node* next;
        Node* prev;
        Node(int _key, int _value){
            key = _key;
            value = _value;
            freq = 1;
            next = nullptr;
            prev = nullptr;
        }
    };

    struct DoublyLinkedList{
        Node* head;
        Node* tail;
        int size;

        DoublyLinkedList(){
            head = new Node(0, 0);
            tail = new Node(0, 0);

            head -> next = tail;
            tail -> prev = head;
            size = 0;
        }

        void AddFront(Node* node){
            node -> prev = head;
            node -> next = head -> next;
            head -> next -> prev = node;
            head -> next = node;
            size++;
        }

        void removeNode(Node* node){
            Node* prevNode = node -> prev;
            Node* nextNode = node -> next;

            nextNode -> prev = prevNode;
            prevNode -> next = nextNode;
            size--;
        }
    };
    int capacity;
    int minFreq;

    unordered_map<int, Node*> keyNode;
    unordered_map<int, DoublyLinkedList*> freqMap;

    void updateFreq(Node* node){
        int oldFreq = node -> freq;

        freqMap[oldFreq] -> removeNode(node);

        if(oldFreq == minFreq && freqMap[oldFreq] -> size == 0){
            minFreq++;
        }

        node -> freq++;

        if(freqMap.find(node -> freq) == freqMap.end()){
            freqMap[node->freq] = new DoublyLinkedList();
        }

            freqMap[node->freq] -> AddFront(node);
    }
public:
    LFUCache(int cap) {
        capacity = cap;
        minFreq = 0;
    }
    
    int get(int key) {
        if(keyNode.find(key) == keyNode.end()){
            return -1;
        }

        Node* node = keyNode[key];
        updateFreq(node);
        return node -> value;
    }
    
    void put(int key, int value) {
        if(capacity == 0) return;

        if(keyNode.find(key) != keyNode.end()){
            Node* node = keyNode[key];
            node -> value = value;
            updateFreq(node);
        }
        else{
            if(keyNode.size() == capacity){
                DoublyLinkedList* minFreqList = freqMap[minFreq];

                Node* lruNode = minFreqList -> tail -> prev;
                keyNode.erase(lruNode -> key);
                minFreqList -> removeNode(lruNode);
                delete lruNode;
            }

            Node* newNode = new Node(key, value);
            keyNode[key] = newNode;

            minFreq = 1;
            if(freqMap.find(1) == freqMap.end()){
                freqMap[1] = new DoublyLinkedList();
            }
            freqMap[1] -> AddFront(newNode);
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */