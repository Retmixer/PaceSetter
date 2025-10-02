Бинарная куча (Min-Heap)
import heapq

data = [8, 3, 5, 1, 6, 2, 4, 7]
heapq.heapify(data)
heapq.heappush(data, 0)
min_val = heapq.heappop(data)
print(min_val)

Хеш-таблица
class HashTable:
    def init(self, size):
        self.size = size
        self.table = [None] * size

    def _hash(self, key):
        return hash(key) % self.size

    def set(self, key, value):
        idx = self._hash(key)
        self.table[idx] = (key, value)

    def get(self, key):
        idx = self._hash(key)
        if self.table[idx] and self.table[idx][0] == key:
            return self.table[idx][1]
        raise KeyError(key)

    def remove(self, key):
        idx = self._hash(key)
        if self.table[idx] and self.table[idx][0] == key:
            self.table[idx] = None
        else:
            raise KeyError(key)

Куча Фибоначчи (упрастил реализацию на Python)
class FibonacciHeap:
    class Node:
        def init(self, key):
            self.key = key
            self.degree = 0
            self.mark = False
            self.parent = None
            self.child = None
            self.left = self
            self.right = self

    def init(self):
        self.min_node = None
        self.count = 0

    def insert(self, key):
        node = self.Node(key)
        if self.min_node is None:
            self.min_node = node
        else:
            self._add_to_root_list(node)
            if key < self.min_node.key:
                self.min_node = node
        self.count += 1

    def _add_to_root_list(self, node):
        node.left = self.min_node
        node.right = self.min_node.right
        self.min_node.right.left = node
        self.min_node.right = node

    def get_min(self):
        return self.min_node.key if self.min_node else None

fib_heap = FibonacciHeap()
fib_heap.insert(10)
fib_heap.insert(5)
print(fib_heap.get_min())

ht = HashTable(10)
ht.set("Alice", "January")
print(ht.get("Alice"))

Биномиальная куча
class BinomialHeap:
    class Node:
        def __init__(self, key):
            self.key = key
            self.degree = 0
            self.parent = None
            self.child = None
            self.sibling = None

    def __init__(self):
        self.head = None

    def merge(self, h2):
        if not self.head:
            return h2.head
        if not h2.head:
            return self.head
        
        head = None
        a = self.head
        b = h2.head
        
        if a.degree <= b.degree:
            head = a
            a = a.sibling
        else:
            head = b
            b = b.sibling
        
        current = head
        while a and b:
            if a.degree <= b.degree:
                current.sibling = a
                a = a.sibling
            else:
                current.sibling = b
                b = b.sibling
            current = current.sibling
        
        current.sibling = a if a else b
        return head

    def union(self, h2):
        new_head = self.merge(h2)
        if not new_head:
            self.head = None
            return
        
        prev = None
        x = new_head
        next = x.sibling
        
        while next:
            if x.degree != next.degree or (next.sibling and next.sibling.degree == x.degree):
                prev = x
                x = next
            elif x.key <= next.key:
                x.sibling = next.sibling
                self.link(next, x)
            else:
                if not prev:
                    new_head = next
                else:
                    prev.sibling = next
                self.link(x, next)
                x = next
            next = x.sibling
        
        self.head = new_head

    def link(self, y, z):
        y.parent = z
        y.sibling = z.child
        z.child = y
        z.degree += 1

    def insert(self, key):
        new_heap = BinomialHeap()
        new_heap.head = self.Node(key)
        self.union(new_heap)

    def get_min(self):
        if not self.head:
            return None
        
        min_node = self.head
        current = self.head.sibling
        
        while current:
            if current.key < min_node.key:
                min_node = current
            current = current.sibling
        return min_node.key

    def extract_min(self):
        if not self.head:
            return None
        
        min_node = self.head
        prev_min = None
        prev = None
        current = self.head
        
        while current:
            if current.key < min_node.key:
                min_node = current
                prev_min = prev
            prev = current
            current = current.sibling
        
        if prev_min:
            prev_min.sibling = min_node.sibling
        else:
            self.head = min_node.sibling
        
        new_heap = BinomialHeap()
        child = min_node.child
        while child:
            next_child = child.sibling
            child.sibling = new_heap.head
            child.parent = None
            new_heap.head = child
            child = next_child
        
        self.union(new_heap)
        return min_node.key

bh = BinomialHeap()
bh.insert(10)
bh.insert(5)
bh.insert(20)
print(bh.get_min())
print(bh.extract_min())
print(bh.get_min())
