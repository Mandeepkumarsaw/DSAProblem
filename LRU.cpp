#include <bits/stdc++.h>
using namespace std;

class LRUCache {
public:
   
    class Node {
    public:
           int key,val;
           Node* prev;
           Node* next;
  
           Node(int k, int v) {
              key = k;
              val = v;
              prev = next = NULL;
           }        
    };  

    Node* head = new Node(-1,-1);
    Node* tail = new Node(-1,-1);

    unordered_map<int, Node*> m;
    int limit;

    //Helper Function for add & del Nodes
    // 1:--
    void addNode(Node* newNode) {   //O(1)
        Node* oldNext =head->next;

        head->next = newNode;
        oldNext->prev = newNode;

        newNode->next = oldNext;
        newNode->prev = head;
    }
  
    // 2:--                          O(1)
    void delNode(Node* oldNode) {
        Node* oldPrev = oldNode->prev;
        Node* oldNext = oldNode->next;

        oldPrev->next = oldNext;
        oldNext->prev = oldPrev;
    }

    //Main Func
    LRUCache(int capacity) {
        limit = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(m.find(key) == m.end()) {
            return -1;
        }

        Node* ansNode = m[key];
        int ans = ansNode->val;

        //Logic to make dynamic behaviour for Most Recent Node and Least Recent Node
        m.erase(key);   //First erase from map 
        delNode(ansNode);   //then , del that node

        addNode(ansNode);   //After del insert same Node again but with Most Recent Usage
        m[key] = ansNode;   //then insert the correspomding val to map for get in further

        return ans;
    }
    
    
    void put(int key, int val) {       //O(1)
        if(m.find(key) != m.end()) {
            Node* oldNode = m[key];   //m[key] return reference to the value associated with that key.
            delNode(oldNode);
            m.erase(key);

        }

        if(m.size() == limit) {
            //delete LRU data
            m.erase(tail->prev->key);
            delNode(tail->prev);
        }

        Node* newNode = new Node(key, val);
        addNode(newNode);
        m[key] = newNode;
    }
};

int main() {
    LRUCache cache(2); // Capacity = 2

    cache.put(1, 10);
    cache.put(2, 20);
    cout << "Get 1: " << cache.get(1) << endl; // Should return 10

    cache.put(3, 30); // Evicts key 2
    cout << "Get 2: " << cache.get(2) << endl; // Should return -1

    cache.put(4, 40); // Evicts key 1
    cout << "Get 1: " << cache.get(1) << endl; // Should return -1
    cout << "Get 3: " << cache.get(3) << endl; // Should return 30
    cout << "Get 4: " << cache.get(4) << endl; // Should return 40

    return 0;
}

