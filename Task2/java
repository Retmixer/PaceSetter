Бинарная куча (Min-Heap)
import java.util.PriorityQueue;

public class Main {
    public static void main(String[] args) {
        PriorityQueue<Integer> heap = new PriorityQueue<>();
        int[] data = {8, 3, 5, 1, 6, 2, 4, 7};
        for (int num : data) heap.offer(num);
        heap.offer(0);
        int minVal = heap.poll();
        System.out.println(minVal);
    }
}

Хеш-таблица
java
import java.util.HashMap;

public class Main {
    public static void main(String[] args) {
        HashMap<String, String> ht = new HashMap<>();
        ht.put("Alice", "January");
        System.out.println(ht.get("Alice"));
        ht.remove("Alice");
    }
}

Биномиальная куча
class BinomialHeap {
    class Node {
        int key;
        int degree;
        Node parent;
        Node child;
        Node sibling;
        
        Node(int k) {
            key = k;
            degree = 0;
            parent = null;
            child = null;
            sibling = null;
        }
    }
    
    private Node head;
    
    private Node merge(Node h1, Node h2) {
        if (h1 == null) return h2;
        if (h2 == null) return h1;
Node head = null;
        Node a = h1;
        Node b = h2;
        
        if (a.degree <= b.degree) {
            head = a;
            a = a.sibling;
        } else {
            head = b;
            b = b.sibling;
        }
        
        Node current = head;
        while (a != null && b != null) {
            if (a.degree <= b.degree) {
                current.sibling = a;
                a = a.sibling;
            } else {
                current.sibling = b;
                b = b.sibling;
            }
            current = current.sibling;
        }
        
        current.sibling = (a != null) ? a : b;
        return head;
    }
    
    private void link(Node y, Node z) {
        y.parent = z;
        y.sibling = z.child;
        z.child = y;
        z.degree++;
    }
    
    private void unionHeaps(Node newHead) {
        if (newHead == null) return;
        
        Node prev = null;
        Node x = newHead;
        Node next = x.sibling;
        
        while (next != null) {
            if (x.degree != next.degree || (next.sibling != null && next.sibling.degree == x.degree)) {
                prev = x;
                x = next;
            } else if (x.key <= next.key) {
                x.sibling = next.sibling;
                link(next, x);
            } else {
                if (prev == null) {
                    newHead = next;
                } else {
                    prev.sibling = next;
                }
                link(x, next);
                x = next;
            }
            next = x.sibling;
        }
        head = newHead;
    }
    
    public void insert(int key) {
        BinomialHeap tempHeap = new BinomialHeap();
        tempHeap.head = new Node(key);
        unionHeaps(merge(head, tempHeap.head));
    }
    
    public int getMin() {
        if (head == null) return -1;
        
        Node minNode = head;
        Node current = head.sibling;
        
        while (current != null) {
            if (current.key < minNode.key) {
                minNode = current;
            }
            current = current.sibling;
        }
        return minNode.key;
    }
    
    public int extractMin() {
        if (head == null) return -1;
        
        Node minNode = head;
        Node prevMin = null;
        Node prev = null;
        Node current = head;
        
        while (current != null) {
            if (current.key < minNode.key) {
                minNode = current;
                prevMin = prev;
            }
            prev = current;
            current = current.sibling;
        }
        
        if (prevMin != null) {
            prevMin.sibling = minNode.sibling;
        } else {
            head = minNode.sibling;
        }
        
        BinomialHeap childHeap = new BinomialHeap();
        Node child = minNode.child;
        while (child != null) {
            Node next = child.sibling;
            child.sibling = childHeap.head;
            child.parent = null;
            childHeap.head = child;
            child = next;
        }
        
        unionHeaps(merge(head, childHeap.head));
        return minNode.key;
    }
    
    public static void main(String[] args) {
        BinomialHeap bh = new BinomialHeap();
        bh.insert(10);
        bh.insert(5);
        bh.insert(20);
        System.out.println(bh.getMin());
        System.out.println(bh.extractMin());
        System.out.println(bh.getMin());
    }
}
