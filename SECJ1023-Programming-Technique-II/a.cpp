// ============================================================================
// MEGALIB.CPP
// A large, self-contained C++ demonstration program containing:
//   - A custom string class
//   - A dynamic array template
//   - Singly and doubly linked lists
//   - Stack and queue (array based)
//   - Binary search tree
//   - Self-balancing AVL tree
//   - Hash table with chaining
//   - Graph with BFS, DFS, and Dijkstra's algorithm
//   - A full suite of sorting algorithms
//   - Binary and linear search
//   - A matrix class with arithmetic operations
//   - A complex number class
//   - A fraction class with automatic reduction
//   - An infix expression evaluator (shunting-yard algorithm)
//   - A polymorphic shape hierarchy
//   - A polymorphic employee/payroll hierarchy
//   - A main() that exercises every module
// ============================================================================

#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <unordered_map>
#include <map>
#include <algorithm>
#include <cmath>
#include <stdexcept>
#include <memory>
#include <functional>
#include <sstream>
#include <list>
#include <limits>

using namespace std;

namespace mylib {

// ============================================================================
// SECTION 1: CUSTOM STRING CLASS
// ============================================================================
class MyString {
private:
    char* data;
    size_t len;

    static size_t rawLength(const char* s) {
        size_t count = 0;
        while (s[count] != '\0') count++;
        return count;
    }

    void allocate(const char* src, size_t length) {
        len = length;
        data = new char[len + 1];
        for (size_t i = 0; i < len; ++i) data[i] = src[i];
        data[len] = '\0';
    }

public:
    MyString() : data(nullptr), len(0) {
        data = new char[1];
        data[0] = '\0';
    }

    MyString(const char* str) {
        allocate(str, rawLength(str));
    }

    MyString(const MyString& other) {
        allocate(other.data, other.len);
    }

    MyString& operator=(const MyString& other) {
        if (this != &other) {
            delete[] data;
            allocate(other.data, other.len);
        }
        return *this;
    }

    ~MyString() {
        delete[] data;
    }

    size_t length() const { return len; }
    const char* c_str() const { return data; }
    bool empty() const { return len == 0; }

    MyString operator+(const MyString& other) const {
        char* newData = new char[len + other.len + 1];
        for (size_t i = 0; i < len; ++i) newData[i] = data[i];
        for (size_t i = 0; i < other.len; ++i) newData[len + i] = other.data[i];
        newData[len + other.len] = '\0';
        MyString result(newData);
        delete[] newData;
        return result;
    }

    bool operator==(const MyString& other) const {
        if (len != other.len) return false;
        for (size_t i = 0; i < len; ++i)
            if (data[i] != other.data[i]) return false;
        return true;
    }

    bool operator<(const MyString& other) const {
        size_t m = min(len, other.len);
        for (size_t i = 0; i < m; ++i) {
            if (data[i] != other.data[i]) return data[i] < other.data[i];
        }
        return len < other.len;
    }

    char& operator[](size_t index) {
        if (index >= len) throw out_of_range("MyString: index out of range");
        return data[index];
    }

    MyString reverse() const {
        char* newData = new char[len + 1];
        for (size_t i = 0; i < len; ++i) newData[i] = data[len - 1 - i];
        newData[len] = '\0';
        MyString result(newData);
        delete[] newData;
        return result;
    }

    MyString toUpper() const {
        char* newData = new char[len + 1];
        for (size_t i = 0; i < len; ++i) {
            char c = data[i];
            newData[i] = (c >= 'a' && c <= 'z') ? char(c - 32) : c;
        }
        newData[len] = '\0';
        MyString result(newData);
        delete[] newData;
        return result;
    }

    MyString toLower() const {
        char* newData = new char[len + 1];
        for (size_t i = 0; i < len; ++i) {
            char c = data[i];
            newData[i] = (c >= 'A' && c <= 'Z') ? char(c + 32) : c;
        }
        newData[len] = '\0';
        MyString result(newData);
        delete[] newData;
        return result;
    }

    bool isPalindrome() const {
        for (size_t i = 0; i < len / 2; ++i) {
            if (data[i] != data[len - 1 - i]) return false;
        }
        return true;
    }

    friend ostream& operator<<(ostream& os, const MyString& s) {
        os << s.data;
        return os;
    }
};

// ============================================================================
// SECTION 2: DYNAMIC ARRAY TEMPLATE
// ============================================================================
template <typename T>
class DynamicArray {
private:
    T* arr;
    size_t capacity;
    size_t count;

    void resize(size_t newCapacity) {
        T* newArr = new T[newCapacity];
        for (size_t i = 0; i < count; ++i) newArr[i] = arr[i];
        delete[] arr;
        arr = newArr;
        capacity = newCapacity;
    }

public:
    DynamicArray() : arr(nullptr), capacity(4), count(0) {
        arr = new T[capacity];
    }

    DynamicArray(const DynamicArray& other) : capacity(other.capacity), count(other.count) {
        arr = new T[capacity];
        for (size_t i = 0; i < count; ++i) arr[i] = other.arr[i];
    }

    DynamicArray& operator=(const DynamicArray& other) {
        if (this != &other) {
            delete[] arr;
            capacity = other.capacity;
            count = other.count;
            arr = new T[capacity];
            for (size_t i = 0; i < count; ++i) arr[i] = other.arr[i];
        }
        return *this;
    }

    ~DynamicArray() {
        delete[] arr;
    }

    void push_back(const T& value) {
        if (count == capacity) resize(capacity * 2);
        arr[count++] = value;
    }

    void pop_back() {
        if (count > 0) count--;
    }

    T& operator[](size_t index) {
        if (index >= count) throw out_of_range("DynamicArray: index out of range");
        return arr[index];
    }

    const T& operator[](size_t index) const {
        if (index >= count) throw out_of_range("DynamicArray: index out of range");
        return arr[index];
    }

    size_t size() const { return count; }
    bool empty() const { return count == 0; }
    void clear() { count = 0; }

    T* begin() { return arr; }
    T* end() { return arr + count; }
    const T* begin() const { return arr; }
    const T* end() const { return arr + count; }
};

// ============================================================================
// SECTION 3: SINGLY LINKED LIST
// ============================================================================
template <typename T>
class SinglyLinkedList {
private:
    struct Node {
        T value;
        Node* next;
        Node(const T& v) : value(v), next(nullptr) {}
    };

    Node* head;
    Node* tail;
    size_t count;

public:
    SinglyLinkedList() : head(nullptr), tail(nullptr), count(0) {}

    ~SinglyLinkedList() {
        clear();
    }

    void clear() {
        Node* current = head;
        while (current) {
            Node* next = current->next;
            delete current;
            current = next;
        }
        head = tail = nullptr;
        count = 0;
    }

    void pushBack(const T& value) {
        Node* node = new Node(value);
        if (!head) {
            head = tail = node;
        } else {
            tail->next = node;
            tail = node;
        }
        count++;
    }

    void pushFront(const T& value) {
        Node* node = new Node(value);
        node->next = head;
        head = node;
        if (!tail) tail = node;
        count++;
    }

    bool removeValue(const T& value) {
        Node* current = head;
        Node* prev = nullptr;
        while (current) {
            if (current->value == value) {
                if (prev) prev->next = current->next;
                else head = current->next;
                if (current == tail) tail = prev;
                delete current;
                count--;
                return true;
            }
            prev = current;
            current = current->next;
        }
        return false;
    }

    SinglyLinkedList<T> reversed() const {
        SinglyLinkedList<T> result;
        Node* current = head;
        while (current) {
            result.pushFront(current->value);
            current = current->next;
        }
        return result;
    }

    size_t size() const { return count; }
    bool empty() const { return count == 0; }

    void print() const {
        Node* current = head;
        cout << "[";
        while (current) {
            cout << current->value;
            if (current->next) cout << " -> ";
            current = current->next;
        }
        cout << "]";
    }
};

// ============================================================================
// SECTION 4: DOUBLY LINKED LIST
// ============================================================================
template <typename T>
class DoublyLinkedList {
private:
    struct Node {
        T value;
        Node* next;
        Node* prev;
        Node(const T& v) : value(v), next(nullptr), prev(nullptr) {}
    };

    Node* head;
    Node* tail;
    size_t count;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr), count(0) {}

    ~DoublyLinkedList() {
        Node* current = head;
        while (current) {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }

    void pushBack(const T& value) {
        Node* node = new Node(value);
        if (!tail) {
            head = tail = node;
        } else {
            node->prev = tail;
            tail->next = node;
            tail = node;
        }
        count++;
    }

    void pushFront(const T& value) {
        Node* node = new Node(value);
        if (!head) {
            head = tail = node;
        } else {
            node->next = head;
            head->prev = node;
            head = node;
        }
        count++;
    }

    bool popBack() {
        if (!tail) return false;
        Node* old = tail;
        tail = tail->prev;
        if (tail) tail->next = nullptr;
        else head = nullptr;
        delete old;
        count--;
        return true;
    }

    size_t size() const { return count; }

    void printForward() const {
        Node* current = head;
        cout << "[";
        while (current) {
            cout << current->value;
            if (current->next) cout << ", ";
            current = current->next;
        }
        cout << "]";
    }

    void printBackward() const {
        Node* current = tail;
        cout << "[";
        while (current) {
            cout << current->value;
            if (current->prev) cout << ", ";
            current = current->prev;
        }
        cout << "]";
    }
};

// ============================================================================
// SECTION 5: STACK AND QUEUE (ARRAY BASED)
// ============================================================================
template <typename T>
class MyStack {
private:
    DynamicArray<T> data;

public:
    void push(const T& value) { data.push_back(value); }

    void pop() {
        if (data.empty()) throw runtime_error("MyStack: pop from empty stack");
        data.pop_back();
    }

    T& top() {
        if (data.empty()) throw runtime_error("MyStack: top of empty stack");
        return data[data.size() - 1];
    }

    bool empty() const { return data.empty(); }
    size_t size() const { return data.size(); }
};

template <typename T>
class MyQueue {
private:
    list<T> data;

public:
    void enqueue(const T& value) { data.push_back(value); }

    void dequeue() {
        if (data.empty()) throw runtime_error("MyQueue: dequeue from empty queue");
        data.pop_front();
    }

    T& front() {
        if (data.empty()) throw runtime_error("MyQueue: front of empty queue");
        return data.front();
    }

    bool empty() const { return data.empty(); }
    size_t size() const { return data.size(); }
};

// ============================================================================
// SECTION 6: BINARY SEARCH TREE
// ============================================================================
template <typename T>
class BinarySearchTree {
private:
    struct Node {
        T value;
        Node* left;
        Node* right;
        Node(const T& v) : value(v), left(nullptr), right(nullptr) {}
    };

    Node* root;
    size_t count;

    Node* insertHelper(Node* node, const T& value) {
        if (!node) {
            count++;
            return new Node(value);
        }
        if (value < node->value) node->left = insertHelper(node->left, value);
        else if (node->value < value) node->right = insertHelper(node->right, value);
        return node;
    }

    bool containsHelper(Node* node, const T& value) const {
        if (!node) return false;
        if (value < node->value) return containsHelper(node->left, value);
        if (node->value < value) return containsHelper(node->right, value);
        return true;
    }

    void inorderHelper(Node* node, DynamicArray<T>& out) const {
        if (!node) return;
        inorderHelper(node->left, out);
        out.push_back(node->value);
        inorderHelper(node->right, out);
    }

    int heightHelper(Node* node) const {
        if (!node) return -1;
        return 1 + max(heightHelper(node->left), heightHelper(node->right));
    }

    void destroy(Node* node) {
        if (!node) return;
        destroy(node->left);
        destroy(node->right);
        delete node;
    }

public:
    BinarySearchTree() : root(nullptr), count(0) {}
    ~BinarySearchTree() { destroy(root); }

    void insert(const T& value) { root = insertHelper(root, value); }
    bool contains(const T& value) const { return containsHelper(root, value); }
    int height() const { return heightHelper(root); }
    size_t size() const { return count; }

    DynamicArray<T> inorder() const {
        DynamicArray<T> out;
        inorderHelper(root, out);
        return out;
    }
};

// ============================================================================
// SECTION 7: SELF-BALANCING AVL TREE
// ============================================================================
template <typename T>
class AVLTree {
private:
    struct Node {
        T value;
        Node* left;
        Node* right;
        int height;
        Node(const T& v) : value(v), left(nullptr), right(nullptr), height(0) {}
    };

    Node* root;

    int heightOf(Node* n) const { return n ? n->height : -1; }

    int balanceFactor(Node* n) const {
        return n ? heightOf(n->left) - heightOf(n->right) : 0;
    }

    void updateHeight(Node* n) {
        n->height = 1 + max(heightOf(n->left), heightOf(n->right));
    }

    Node* rotateRight(Node* y) {
        Node* x = y->left;
        Node* t2 = x->right;
        x->right = y;
        y->left = t2;
        updateHeight(y);
        updateHeight(x);
        return x;
    }

    Node* rotateLeft(Node* x) {
        Node* y = x->right;
        Node* t2 = y->left;
        y->left = x;
        x->right = t2;
        updateHeight(x);
        updateHeight(y);
        return y;
    }

    Node* rebalance(Node* node) {
        updateHeight(node);
        int bf = balanceFactor(node);
        if (bf > 1) {
            if (balanceFactor(node->left) < 0) node->left = rotateLeft(node->left);
            return rotateRight(node);
        }
        if (bf < -1) {
            if (balanceFactor(node->right) > 0) node->right = rotateRight(node->right);
            return rotateLeft(node);
        }
        return node;
    }

    Node* insertHelper(Node* node, const T& value) {
        if (!node) return new Node(value);
        if (value < node->value) node->left = insertHelper(node->left, value);
        else if (node->value < value) node->right = insertHelper(node->right, value);
        else return node;
        return rebalance(node);
    }

    void inorderHelper(Node* node, DynamicArray<T>& out) const {
        if (!node) return;
        inorderHelper(node->left, out);
        out.push_back(node->value);
        inorderHelper(node->right, out);
    }

    void destroy(Node* node) {
        if (!node) return;
        destroy(node->left);
        destroy(node->right);
        delete node;
    }

public:
    AVLTree() : root(nullptr) {}
    ~AVLTree() { destroy(root); }

    void insert(const T& value) { root = insertHelper(root, value); }
    int height() const { return heightOf(root); }

    DynamicArray<T> inorder() const {
        DynamicArray<T> out;
        inorderHelper(root, out);
        return out;
    }
};

// ============================================================================
// SECTION 8: HASH TABLE WITH CHAINING
// ============================================================================
template <typename K, typename V>
class HashTable {
private:
    struct Entry {
        K key;
        V value;
        Entry(const K& k, const V& v) : key(k), value(v) {}
    };

    vector<list<Entry>> buckets;
    size_t bucketCount;
    size_t itemCount;

    size_t hashKey(const K& key) const {
        hash<K> hasher;
        return hasher(key) % bucketCount;
    }

    void rehash() {
        size_t newBucketCount = bucketCount * 2;
        vector<list<Entry>> newBuckets(newBucketCount);
        for (auto& bucket : buckets) {
            for (auto& entry : bucket) {
                hash<K> hasher;
                size_t idx = hasher(entry.key) % newBucketCount;
                newBuckets[idx].push_back(entry);
            }
        }
        buckets = move(newBuckets);
        bucketCount = newBucketCount;
    }

public:
    HashTable(size_t initialBuckets = 16) : bucketCount(initialBuckets), itemCount(0) {
        buckets.resize(bucketCount);
    }

    void insert(const K& key, const V& value) {
        if (itemCount >= bucketCount * 3 / 4) rehash();
        size_t idx = hashKey(key);
        for (auto& entry : buckets[idx]) {
            if (entry.key == key) {
                entry.value = value;
                return;
            }
        }
        buckets[idx].emplace_back(key, value);
        itemCount++;
    }

    bool get(const K& key, V& outValue) const {
        size_t idx = hashKey(key);
        for (const auto& entry : buckets[idx]) {
            if (entry.key == key) {
                outValue = entry.value;
                return true;
            }
        }
        return false;
    }

    bool remove(const K& key) {
        size_t idx = hashKey(key);
        auto& bucket = buckets[idx];
        for (auto it = bucket.begin(); it != bucket.end(); ++it) {
            if (it->key == key) {
                bucket.erase(it);
                itemCount--;
                return true;
            }
        }
        return false;
    }

    size_t size() const { return itemCount; }
    size_t bucketsUsed() const { return bucketCount; }
};

// ============================================================================
// SECTION 9: GRAPH WITH BFS, DFS, DIJKSTRA
// ============================================================================
class Graph {
private:
    int numVertices;
    vector<vector<pair<int, int>>> adjacency; // (neighbor, weight)

public:
    explicit Graph(int n) : numVertices(n), adjacency(n) {}

    void addEdge(int u, int v, int weight = 1, bool directed = false) {
        adjacency[u].push_back({v, weight});
        if (!directed) adjacency[v].push_back({u, weight});
    }

    vector<int> bfs(int start) const {
        vector<bool> visited(numVertices, false);
        vector<int> order;
        queue<int> q;
        visited[start] = true;
        q.push(start);
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            order.push_back(u);
            for (auto& edge : adjacency[u]) {
                int v = edge.first;
                if (!visited[v]) {
                    visited[v] = true;
                    q.push(v);
                }
            }
        }
        return order;
    }

    void dfsHelper(int u, vector<bool>& visited, vector<int>& order) const {
        visited[u] = true;
        order.push_back(u);
        for (auto& edge : adjacency[u]) {
            int v = edge.first;
            if (!visited[v]) dfsHelper(v, visited, order);
        }
    }

    vector<int> dfs(int start) const {
        vector<bool> visited(numVertices, false);
        vector<int> order;
        dfsHelper(start, visited, order);
        return order;
    }

    vector<int> dijkstra(int start) const {
        const int INF = numeric_limits<int>::max();
        vector<int> dist(numVertices, INF);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        dist[start] = 0;
        pq.push({0, start});
        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();
            if (d > dist[u]) continue;
            for (auto& edge : adjacency[u]) {
                int v = edge.first;
                int w = edge.second;
                if (dist[u] != INF && dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    pq.push({dist[v], v});
                }
            }
        }
        return dist;
    }
};

// ============================================================================
// SECTION 10: SORTING ALGORITHMS
// ============================================================================
namespace sorting {

    template <typename T>
    void bubbleSort(vector<T>& arr) {
        size_t n = arr.size();
        for (size_t i = 0; i < n; ++i) {
            bool swapped = false;
            for (size_t j = 0; j + 1 < n - i; ++j) {
                if (arr[j + 1] < arr[j]) {
                    swap(arr[j], arr[j + 1]);
                    swapped = true;
                }
            }
            if (!swapped) break;
        }
    }

    template <typename T>
    void insertionSort(vector<T>& arr) {
        for (size_t i = 1; i < arr.size(); ++i) {
            T key = arr[i];
            int j = static_cast<int>(i) - 1;
            while (j >= 0 && arr[j] > key) {
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j + 1] = key;
        }
    }

    template <typename T>
    void selectionSort(vector<T>& arr) {
        size_t n = arr.size();
        for (size_t i = 0; i < n; ++i) {
            size_t minIdx = i;
            for (size_t j = i + 1; j < n; ++j) {
                if (arr[j] < arr[minIdx]) minIdx = j;
            }
            swap(arr[i], arr[minIdx]);
        }
    }

    template <typename T>
    void merge(vector<T>& arr, size_t left, size_t mid, size_t right) {
        vector<T> leftPart(arr.begin() + left, arr.begin() + mid + 1);
        vector<T> rightPart(arr.begin() + mid + 1, arr.begin() + right + 1);
        size_t i = 0, j = 0, k = left;
        while (i < leftPart.size() && j < rightPart.size()) {
            arr[k++] = (leftPart[i] <= rightPart[j]) ? leftPart[i++] : rightPart[j++];
        }
        while (i < leftPart.size()) arr[k++] = leftPart[i++];
        while (j < rightPart.size()) arr[k++] = rightPart[j++];
    }

    template <typename T>
    void mergeSortHelper(vector<T>& arr, size_t left, size_t right) {
        if (left >= right) return;
        size_t mid = left + (right - left) / 2;
        mergeSortHelper(arr, left, mid);
        mergeSortHelper(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }

    template <typename T>
    void mergeSort(vector<T>& arr) {
        if (!arr.empty()) mergeSortHelper(arr, 0, arr.size() - 1);
    }

    template <typename T>
    size_t partition(vector<T>& arr, size_t low, size_t high) {
        T pivot = arr[high];
        size_t i = low;
        for (size_t j = low; j < high; ++j) {
            if (arr[j] < pivot) {
                swap(arr[i], arr[j]);
                i++;
            }
        }
        swap(arr[i], arr[high]);
        return i;
    }

    template <typename T>
    void quickSortHelper(vector<T>& arr, size_t low, size_t high) {
        if (low >= high) return;
        size_t p = partition(arr, low, high);
        if (p > 0) quickSortHelper(arr, low, p - 1);
        quickSortHelper(arr, p + 1, high);
    }

    template <typename T>
    void quickSort(vector<T>& arr) {
        if (!arr.empty()) quickSortHelper(arr, 0, arr.size() - 1);
    }

    template <typename T>
    void heapify(vector<T>& arr, size_t n, size_t i) {
        size_t largest = i;
        size_t left = 2 * i + 1;
        size_t right = 2 * i + 2;
        if (left < n && arr[left] > arr[largest]) largest = left;
        if (right < n && arr[right] > arr[largest]) largest = right;
        if (largest != i) {
            swap(arr[i], arr[largest]);
            heapify(arr, n, largest);
        }
    }

    template <typename T>
    void heapSort(vector<T>& arr) {
        size_t n = arr.size();
        for (size_t i = n / 2; i-- > 0;) heapify(arr, n, i);
        for (size_t i = n - 1; i > 0; --i) {
            swap(arr[0], arr[i]);
            heapify(arr, i, 0);
        }
    }

} // namespace sorting

// ============================================================================
// SECTION 11: SEARCHING ALGORITHMS
// ============================================================================
namespace searching {

    template <typename T>
    int linearSearch(const vector<T>& arr, const T& target) {
        for (size_t i = 0; i < arr.size(); ++i) {
            if (arr[i] == target) return static_cast<int>(i);
        }
        return -1;
    }

    template <typename T>
    int binarySearch(const vector<T>& sortedArr, const T& target) {
        int low = 0, high = static_cast<int>(sortedArr.size()) - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (sortedArr[mid] == target) return mid;
            if (sortedArr[mid] < target) low = mid + 1;
            else high = mid - 1;
        }
        return -1;
    }

} // namespace searching

// ============================================================================
// SECTION 12: MATRIX CLASS
// ============================================================================
class Matrix {
private:
    size_t rows, cols;
    vector<vector<double>> data;

public:
    Matrix(size_t r, size_t c, double fill = 0.0) : rows(r), cols(c) {
        data.assign(rows, vector<double>(cols, fill));
    }

    double& at(size_t r, size_t c) { return data[r][c]; }
    double at(size_t r, size_t c) const { return data[r][c]; }
    size_t numRows() const { return rows; }
    size_t numCols() const { return cols; }

    static Matrix identity(size_t n) {
        Matrix m(n, n);
        for (size_t i = 0; i < n; ++i) m.at(i, i) = 1.0;
        return m;
    }

    Matrix operator+(const Matrix& other) const {
        if (rows != other.rows || cols != other.cols)
            throw invalid_argument("Matrix dimensions must match for addition");
        Matrix result(rows, cols);
        for (size_t i = 0; i < rows; ++i)
            for (size_t j = 0; j < cols; ++j)
                result.at(i, j) = data[i][j] + other.at(i, j);
        return result;
    }

    Matrix operator-(const Matrix& other) const {
        if (rows != other.rows || cols != other.cols)
            throw invalid_argument("Matrix dimensions must match for subtraction");
        Matrix result(rows, cols);
        for (size_t i = 0; i < rows; ++i)
            for (size_t j = 0; j < cols; ++j)
                result.at(i, j) = data[i][j] - other.at(i, j);
        return result;
    }

    Matrix operator*(const Matrix& other) const {
        if (cols != other.rows)
            throw invalid_argument("Matrix dimensions incompatible for multiplication");
        Matrix result(rows, other.cols);
        for (size_t i = 0; i < rows; ++i) {
            for (size_t j = 0; j < other.cols; ++j) {
                double sum = 0.0;
                for (size_t k = 0; k < cols; ++k) sum += data[i][k] * other.at(k, j);
                result.at(i, j) = sum;
            }
        }
        return result;
    }

    Matrix transpose() const {
        Matrix result(cols, rows);
        for (size_t i = 0; i < rows; ++i)
            for (size_t j = 0; j < cols; ++j)
                result.at(j, i) = data[i][j];
        return result;
    }

    void print() const {
        for (size_t i = 0; i < rows; ++i) {
            cout << "[ ";
            for (size_t j = 0; j < cols; ++j) cout << data[i][j] << " ";
            cout << "]\n";
        }
    }
};

// ============================================================================
// SECTION 13: COMPLEX NUMBER CLASS
// ============================================================================
class Complex {
private:
    double re, im;

public:
    Complex(double r = 0.0, double i = 0.0) : re(r), im(i) {}

    Complex operator+(const Complex& o) const { return Complex(re + o.re, im + o.im); }
    Complex operator-(const Complex& o) const { return Complex(re - o.re, im - o.im); }

    Complex operator*(const Complex& o) const {
        return Complex(re * o.re - im * o.im, re * o.im + im * o.re);
    }

    double magnitude() const { return sqrt(re * re + im * im); }

    friend ostream& operator<<(ostream& os, const Complex& c) {
        os << c.re;
        if (c.im >= 0) os << " + " << c.im << "i";
        else os << " - " << -c.im << "i";
        return os;
    }
};

// ============================================================================
// SECTION 14: FRACTION CLASS
// ============================================================================
class Fraction {
private:
    long long num, den;

    static long long gcd(long long a, long long b) {
        a = llabs(a);
        b = llabs(b);
        while (b != 0) {
            long long t = b;
            b = a % b;
            a = t;
        }
        return a == 0 ? 1 : a;
    }

    void reduce() {
        if (den < 0) { num = -num; den = -den; }
        long long g = gcd(num, den);
        num /= g;
        den /= g;
    }

public:
    Fraction(long long n = 0, long long d = 1) : num(n), den(d) {
        if (d == 0) throw invalid_argument("Fraction: denominator cannot be zero");
        reduce();
    }

    Fraction operator+(const Fraction& o) const {
        return Fraction(num * o.den + o.num * den, den * o.den);
    }

    Fraction operator-(const Fraction& o) const {
        return Fraction(num * o.den - o.num * den, den * o.den);
    }

    Fraction operator*(const Fraction& o) const {
        return Fraction(num * o.num, den * o.den);
    }

    Fraction operator/(const Fraction& o) const {
        return Fraction(num * o.den, den * o.num);
    }

    friend ostream& operator<<(ostream& os, const Fraction& f) {
        os << f.num << "/" << f.den;
        return os;
    }
};

// ============================================================================
// SECTION 15: INFIX EXPRESSION EVALUATOR (SHUNTING YARD)
// ============================================================================
class ExpressionEvaluator {
private:
    static int precedence(char op) {
        if (op == '+' || op == '-') return 1;
        if (op == '*' || op == '/') return 2;
        return 0;
    }

    static double applyOp(double a, double b, char op) {
        switch (op) {
            case '+': return a + b;
            case '-': return a - b;
            case '*': return a * b;
            case '/':
                if (b == 0) throw runtime_error("Division by zero");
                return a / b;
            default: throw runtime_error("Unknown operator");
        }
    }

public:
    static double evaluate(const string& expr) {
        stack<double> values;
        stack<char> ops;
        size_t i = 0;
        while (i < expr.size()) {
            char c = expr[i];
            if (isspace(c)) { i++; continue; }
            if (isdigit(c) || c == '.') {
                string num;
                while (i < expr.size() && (isdigit(expr[i]) || expr[i] == '.')) num += expr[i++];
                values.push(stod(num));
                continue;
            }
            if (c == '(') {
                ops.push(c);
            } else if (c == ')') {
                while (!ops.empty() && ops.top() != '(') {
                    double b = values.top(); values.pop();
                    double a = values.top(); values.pop();
                    char op = ops.top(); ops.pop();
                    values.push(applyOp(a, b, op));
                }
                if (!ops.empty()) ops.pop(); // remove '('
            } else if (c == '+' || c == '-' || c == '*' || c == '/') {
                while (!ops.empty() && precedence(ops.top()) >= precedence(c)) {
                    double b = values.top(); values.pop();
                    double a = values.top(); values.pop();
                    char op = ops.top(); ops.pop();
                    values.push(applyOp(a, b, op));
                }
                ops.push(c);
            }
            i++;
        }
        while (!ops.empty()) {
            double b = values.top(); values.pop();
            double a = values.top(); values.pop();
            char op = ops.top(); ops.pop();
            values.push(applyOp(a, b, op));
        }
        return values.empty() ? 0.0 : values.top();
    }
};

// ============================================================================
// SECTION 16: POLYMORPHIC SHAPE HIERARCHY
// ============================================================================
class Shape {
public:
    virtual double area() const = 0;
    virtual double perimeter() const = 0;
    virtual string name() const = 0;
    virtual ~Shape() = default;
};

class Circle : public Shape {
private:
    double radius;

public:
    explicit Circle(double r) : radius(r) {}
   // double area() const override { return M_PI * radius * radius; }
    //double perimeter() const override { return 2 * M_PI * radius; }
    string name() const override { return "Circle"; }
};

class Rectangle : public Shape {
private:
    double width, heightVal;

public:
    Rectangle(double w, double h) : width(w), heightVal(h) {}
    double area() const override { return width * heightVal; }
    double perimeter() const override { return 2 * (width + heightVal); }
    string name() const override { return "Rectangle"; }
};

class Triangle : public Shape {
private:
    double a, b, c;

public:
    Triangle(double sideA, double sideB, double sideC) : a(sideA), b(sideB), c(sideC) {}

    double area() const override {
        double s = (a + b + c) / 2.0;
        return sqrt(s * (s - a) * (s - b) * (s - c));
    }

    double perimeter() const override { return a + b + c; }
    string name() const override { return "Triangle"; }
};

void describeShapes(const vector<unique_ptr<Shape>>& shapes) {
    for (const auto& s : shapes) {
        cout << s->name() << ": area=" << s->area()
             << ", perimeter=" << s->perimeter() << "\n";
    }
}

// ============================================================================
// SECTION 17: POLYMORPHIC EMPLOYEE / PAYROLL HIERARCHY
// ============================================================================
class Employee {
protected:
    string employeeName;
    double baseSalary;

public:
    Employee(string n, double salary) : employeeName(move(n)), baseSalary(salary) {}
    virtual double computeSalary() const { return baseSalary; }
    virtual string role() const { return "Employee"; }
    virtual ~Employee() = default;

    void describe() const {
        cout << role() << " " << employeeName << " earns " << computeSalary() << "\n";
    }
};

class Developer : public Employee {
private:
    int linesOfCodeBonus;

public:
    Developer(string n, double salary, int bonusPerThousandLines)
        : Employee(move(n), salary), linesOfCodeBonus(bonusPerThousandLines) {}

    double computeSalary() const override { return baseSalary + linesOfCodeBonus; }
    string role() const override { return "Developer"; }
};

class Manager : public Employee {
private:
    double teamBonus;

public:
    Manager(string n, double salary, double bonus)
        : Employee(move(n), salary), teamBonus(bonus) {}

    double computeSalary() const override { return baseSalary + teamBonus; }
    string role() const override { return "Manager"; }
};

class Executive : public Employee {
private:
    double stockOptions;

public:
    Executive(string n, double salary, double stocks)
        : Employee(move(n), salary), stockOptions(stocks) {}

    double computeSalary() const override { return baseSalary + stockOptions * 1.5; }
    string role() const override { return "Executive"; }
};

} // namespace mylib

// ============================================================================
// SECTION 18: MAIN — EXERCISES EVERY MODULE ABOVE
// ============================================================================
using namespace mylib;

void section(const string& title) {
    cout << "\n========================================\n";
    cout << title << "\n";
    cout << "========================================\n";
}

int main() {
    cout << "MEGALIB DEMONSTRATION PROGRAM\n";

    // --- MyString ---
    section("Custom String Class");
    MyString s1("Hello, ");
    MyString s2("World!");
    MyString s3 = s1 + s2;
    cout << "Concatenated: " << s3 << "\n";
    cout << "Uppercase: " << s3.toUpper() << "\n";
    cout << "Reversed: " << s3.reverse() << "\n";
    MyString palin("racecar");
    cout << palin << " is palindrome? " << (palin.isPalindrome() ? "yes" : "no") << "\n";

    // --- DynamicArray ---
    section("Dynamic Array");
    DynamicArray<int> dynArr;
    for (int i = 1; i <= 10; ++i) dynArr.push_back(i * i);
    cout << "Squares: ";
    for (size_t i = 0; i < dynArr.size(); ++i) cout << dynArr[i] << " ";
    cout << "\n";

    // --- Singly Linked List ---
    section("Singly Linked List");
    SinglyLinkedList<int> sll;
    for (int i = 1; i <= 5; ++i) sll.pushBack(i);
    cout << "List: ";
    sll.print();
    cout << "\nReversed: ";
    SinglyLinkedList<int> sllRev = sll.reversed();
    sllRev.print();
    cout << "\n";

    // --- Doubly Linked List ---
    section("Doubly Linked List");
    DoublyLinkedList<string> dll;
    dll.pushBack("alpha");
    dll.pushBack("beta");
    dll.pushBack("gamma");
    dll.pushFront("zero");
    cout << "Forward: ";
    dll.printForward();
    cout << "\nBackward: ";
    dll.printBackward();
    cout << "\n";

    // --- Stack and Queue ---
    section("Stack and Queue");
    MyStack<int> stack1;
    for (int i = 1; i <= 5; ++i) stack1.push(i);
    cout << "Stack popped order: ";
    while (!stack1.empty()) {
        cout << stack1.top() << " ";
        stack1.pop();
    }
    cout << "\n";

    MyQueue<int> queue1;
    for (int i = 1; i <= 5; ++i) queue1.enqueue(i);
    cout << "Queue dequeued order: ";
    while (!queue1.empty()) {
        cout << queue1.front() << " ";
        queue1.dequeue();
    }
    cout << "\n";

    // --- Binary Search Tree ---
    section("Binary Search Tree");
    BinarySearchTree<int> bst;
    for (int v : {50, 30, 70, 20, 40, 60, 80, 10}) bst.insert(v);
    cout << "Inorder traversal: ";
    DynamicArray<int> bstOrder = bst.inorder();
    for (size_t i = 0; i < bstOrder.size(); ++i) cout << bstOrder[i] << " ";
    cout << "\nHeight: " << bst.height() << ", contains 60? " << bst.contains(60) << "\n";

    // --- AVL Tree ---
    section("Self-Balancing AVL Tree");
    AVLTree<int> avl;
    for (int v : {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}) avl.insert(v);
    cout << "Inorder traversal: ";
    DynamicArray<int> avlOrder = avl.inorder();
    for (size_t i = 0; i < avlOrder.size(); ++i) cout << avlOrder[i] << " ";
    cout << "\nHeight (balanced, should be small): " << avl.height() << "\n";

    // --- Hash Table ---
    section("Hash Table With Chaining");
    HashTable<string, int> ht;
    ht.insert("apples", 10);
    ht.insert("bananas", 25);
    ht.insert("cherries", 99);
    int val;
    if (ht.get("bananas", val)) cout << "bananas -> " << val << "\n";
    ht.remove("apples");
    cout << "apples present after removal? " << ht.get("apples", val) << "\n";
    cout << "Total items: " << ht.size() << "\n";

    // --- Graph ---
    section("Graph: BFS, DFS, Dijkstra");
    Graph g(6);
    g.addEdge(0, 1, 4);
    g.addEdge(0, 2, 1);
    g.addEdge(2, 1, 2);
    g.addEdge(1, 3, 1);
    g.addEdge(2, 3, 5);
    g.addEdge(3, 4, 3);
    g.addEdge(4, 5, 2);

    vector<int> bfsOrder = g.bfs(0);
    cout << "BFS from 0: ";
    for (int v : bfsOrder) cout << v << " ";
    cout << "\n";

    vector<int> dfsOrder = g.dfs(0);
    cout << "DFS from 0: ";
    for (int v : dfsOrder) cout << v << " ";
    cout << "\n";

    vector<int> distances = g.dijkstra(0);
    cout << "Shortest distances from 0: ";
    for (int d : distances) cout << d << " ";
    cout << "\n";

    // --- Sorting Algorithms ---
    section("Sorting Algorithms");
    vector<int> base = {9, 3, 7, 1, 8, 2, 5, 6, 4, 0};

    vector<int> bubbleArr = base;
    sorting::bubbleSort(bubbleArr);
    cout << "Bubble sort:    ";
    for (int v : bubbleArr) cout << v << " ";
    cout << "\n";

    vector<int> insertArr = base;
    sorting::insertionSort(insertArr);
    cout << "Insertion sort: ";
    for (int v : insertArr) cout << v << " ";
    cout << "\n";

    vector<int> selectArr = base;
    sorting::selectionSort(selectArr);
    cout << "Selection sort: ";
    for (int v : selectArr) cout << v << " ";
    cout << "\n";

    vector<int> mergeArr = base;
    sorting::mergeSort(mergeArr);
    cout << "Merge sort:     ";
    for (int v : mergeArr) cout << v << " ";
    cout << "\n";

    vector<int> quickArr = base;
    sorting::quickSort(quickArr);
    cout << "Quick sort:     ";
    for (int v : quickArr) cout << v << " ";
    cout << "\n";

    vector<int> heapArr = base;
    sorting::heapSort(heapArr);
    cout << "Heap sort:      ";
    for (int v : heapArr) cout << v << " ";
    cout << "\n";

    // --- Searching ---
    section("Searching Algorithms");
    int target = 7;
    cout << "Linear search for " << target << " in unsorted base: index "
         << searching::linearSearch(base, target) << "\n";
    cout << "Binary search for " << target << " in sorted array: index "
         << searching::binarySearch(mergeArr, target) << "\n";

    // --- Matrix ---
    section("Matrix Operations");
    Matrix m1(2, 2);
    m1.at(0, 0) = 1; m1.at(0, 1) = 2;
    m1.at(1, 0) = 3; m1.at(1, 1) = 4;

    Matrix m2(2, 2);
    m2.at(0, 0) = 5; m2.at(0, 1) = 6;
    m2.at(1, 0) = 7; m2.at(1, 1) = 8;

    cout << "Matrix A:\n"; m1.print();
    cout << "Matrix B:\n"; m2.print();
    cout << "A + B:\n"; (m1 + m2).print();
    cout << "A * B:\n"; (m1 * m2).print();
    cout << "Transpose of A:\n"; m1.transpose().print();
    cout << "3x3 Identity:\n"; Matrix::identity(3).print();

    // --- Complex Numbers ---
    section("Complex Numbers");
    Complex c1(3, 4);
    Complex c2(1, -2);
    cout << "c1 = " << c1 << ", c2 = " << c2 << "\n";
    cout << "c1 + c2 = " << (c1 + c2) << "\n";
    cout << "c1 * c2 = " << (c1 * c2) << "\n";
    cout << "|c1| = " << c1.magnitude() << "\n";

    // --- Fractions ---
    section("Fractions");
    Fraction f1(1, 3);
    Fraction f2(1, 6);
    cout << "f1 = " << f1 << ", f2 = " << f2 << "\n";
    cout << "f1 + f2 = " << (f1 + f2) << "\n";
    cout << "f1 * f2 = " << (f1 * f2) << "\n";
    cout << "f1 / f2 = " << (f1 / f2) << "\n";

    // --- Expression Evaluator ---
    section("Infix Expression Evaluator");
    vector<string> expressions = {
        "3 + 4 * 2",
        "(1 + 2) * (3 + 4)",
        "10 / 2 - 3",
        "2 * (3 + (4 - 1) * 2)"
    };
    for (const auto& expr : expressions) {
        cout << expr << " = " << ExpressionEvaluator::evaluate(expr) << "\n";
    }

    // --- Shape Hierarchy ---
    section("Polymorphic Shapes");
    vector<unique_ptr<Shape>> shapes;
    shapes.push_back(make_unique<Circle>(3.0));
    shapes.push_back(make_unique<Rectangle>(4.0, 5.0));
    shapes.push_back(make_unique<Triangle>(3.0, 4.0, 5.0));
    describeShapes(shapes);

    // --- Employee Hierarchy ---
    section("Polymorphic Employees");
    vector<unique_ptr<Employee>> staff;
    staff.push_back(make_unique<Developer>("Alice", 70000, 5000));
    staff.push_back(make_unique<Manager>("Bob", 90000, 10000));
    staff.push_back(make_unique<Executive>("Carol", 150000, 20000));
    for (const auto& e : staff) e->describe();

    cout << "\nAll modules executed successfully.\n";
    return 0;
}