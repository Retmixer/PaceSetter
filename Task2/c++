Бинарная куча (Min-Heap)
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int main() {
    vector<int> data = {8, 3, 5, 1, 6, 2, 4, 7};
    make_heap(data.begin(), data.end(), greater<int>());
    data.push_back(0);
    push_heap(data.begin(), data.end(), greater<int>());
    pop_heap(data.begin(), data.end(), greater<int>());
    int min_val = data.back();
    data.pop_back();
    cout << min_val;
    return 0;
}

Хеш-таблица
#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    unordered_map<string, string> ht;
    ht["Alice"] = "January";
    cout << ht["Alice"] << endl;
    ht.erase("Alice");
    return 0;
}

Биномиальная куча
#include <iostream>
using namespace std;

struct Node {
    int key;
    int degree;
    Node* parent;
    Node* child;
    Node* sibling;
    
    Node(int k) : key(k), degree(0), parent(nullptr), child(nullptr), sibling(nullptr) {}
};

class BinomialHeap {
    Node* head;
    
    Node* merge(Node* h1, Node* h2) {
        if (!h1) return h2;
        if (!h2) return h1;
        
        Node* head = nullptr;
        Node* a = h1;
Node* b = h2;
        
        if (a->degree <= b->degree) {
            head = a;
            a = a->sibling;
        } else {
            head = b;
            b = b->sibling;
        }
        
        Node* current = head;
        while (a && b) {
            if (a->degree <= b->degree) {
                current->sibling = a;
                a = a->sibling;
            } else {
                current->sibling = b;
                b = b->sibling;
            }
            current = current->sibling;
        }
        
        current->sibling = a ? a : b;
        return head;
    }
    
    void link(Node* y, Node* z) {
        y->parent = z;
        y->sibling = z->child;
        z->child = y;
        z->degree++;
    }
    
    void unionHeaps(Node* newHead) {
        if (!newHead) return;
        
        Node* prev = nullptr;
        Node* x = newHead;
        Node* next = x->sibling;
        
        while (next) {
            if (x->degree != next->degree || (next->sibling && next->sibling->degree == x->degree)) {
                prev = x;
                x = next;
            } else if (x->key <= next->key) {
                x->sibling = next->sibling;
                link(next, x);
            } else {
                if (!prev) {
                    newHead = next;
                } else {
                    prev->sibling = next;
                }
                link(x, next);
                x = next;
            }
            next = x->sibling;
        }
        head = newHead;
    }
    
public:
    BinomialHeap() : head(nullptr) {}
    
    void insert(int key) {
        BinomialHeap tempHeap;
        tempHeap.head = new Node(key);
        unionHeaps(merge(head, tempHeap.head));
    }
    
    int getMin() {
        if (!head) return -1;
        
        Node* minNode = head;
        Node* current = head->sibling;
        
        while (current) {
            if (current->key < minNode->key) {
                minNode = current;
            }
            current = current->sibling;
        }
        return minNode->key;
    }
    
    int extractMin() {
        if (!head) return -1;
        
        Node* minNode = head;
        Node* prevMin = nullptr;
        Node* prev = nullptr;
        Node* current = head;
        
        while (current) {
            if (current->key < minNode->key) {
                minNode = current;
                prevMin = prev;
            }
            prev = current;
            current = current->sibling;
        }
        
        if (prevMin) {
            prevMin->sibling = minNode->sibling;
        } else {
            head = minNode->sibling;
        }
        
        BinomialHeap childHeap;
        Node* child = minNode->child;
        while (child) {
            Node* next = child->sibling;
            child->sibling = childHeap.head;
            child->parent = nullptr;
            childHeap.head = child;
            child = next;
        }
        
        unionHeaps(merge(head, childHeap.head));
        int minKey = minNode->key;
        delete minNode;
        return minKey;
    }
};

int main() {
    BinomialHeap bh;
    bh.insert(10);
    bh.insert(5);
    bh.insert(20);
    cout << bh.getMin() << endl;
    cout << bh.extractMin() << endl;
    cout << bh.getMin() << endl;
    return 0;
}
