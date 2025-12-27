### 📦 What is STL in C++?

**STL (Standard Template Library)** is a powerful library in C++ that provides **ready-made, optimized data structures and algorithms**.
It helps you write **less code**, **faster**, and **more efficient programs**.

👉 STL is based on **templates**, so it works with **any data type**.

---

## 🔑 Main Components of STL

STL has **4 major components**:

---

## 1️⃣ Containers (Data Structures)

Containers store data.

### 🔹 Sequence Containers

| Container | Use                       |
| --------- | ------------------------- |
| `vector`  | Dynamic array (most used) |
| `deque`   | Double-ended queue        |
| `list`    | Doubly linked list        |
| `array`   | Fixed-size array          |

Example:

```cpp
vector<int> v = {1, 2, 3};
v.push_back(4);
```

---

### 🔹 Associative Containers (Sorted)

| Container  | Use                          |
| ---------- | ---------------------------- |
| `set`      | Unique elements (sorted)     |
| `multiset` | Duplicate elements allowed   |
| `map`      | Key–value pair (unique keys) |
| `multimap` | Duplicate keys allowed       |

Example:

```cpp
map<string, int> mp;
mp["apple"] = 3;
```

---

### 🔹 Unordered Containers (Hash-based)

| Container       | Use                    |
| --------------- | ---------------------- |
| `unordered_set` | Fast lookup (O(1))     |
| `unordered_map` | Fast key–value storage |

Example:

```cpp
unordered_map<int, int> freq;
freq[5]++;
```

---

### 🔹 Container Adapters

| Adapter          | Use          |
| ---------------- | ------------ |
| `stack`          | LIFO         |
| `queue`          | FIFO         |
| `priority_queue` | Max/Min heap |

Example:

```cpp
priority_queue<int> pq;
pq.push(10);
```

---

## 2️⃣ Algorithms

Predefined functions for operations like searching, sorting, etc.

| Algorithm         | Purpose               |
| ----------------- | --------------------- |
| `sort()`          | Sort elements         |
| `binary_search()` | Search in sorted data |
| `find()`          | Find element          |
| `count()`         | Count occurrences     |
| `max_element()`   | Max value             |

Example:

```cpp
sort(v.begin(), v.end());
```

---

## 3️⃣ Iterators

Iterators are like **pointers** used to traverse containers.

```cpp
for(auto it = v.begin(); it != v.end(); it++){
    cout << *it << " ";
}
```

---

## 4️⃣ Functors (Function Objects)

Objects that behave like functions.

Example:

```cpp
sort(v.begin(), v.end(), greater<int>());
```

---

# ⭐ Important Data Structures in C++ (Must Know)

### 🔥 Most Important for DSA & Interviews

### 1️⃣ Array

* Fixed size
* Fast access: O(1)

---

### 2️⃣ Vector

* Dynamic array
* Most used STL DS

---

### 3️⃣ Stack

* LIFO
* Used in recursion, undo/redo

---

### 4️⃣ Queue

* FIFO
* Used in BFS

---

### 5️⃣ Linked List

* Dynamic memory
* Easy insertion/deletion

---

### 6️⃣ Set / Map

* Sorted data
* Uses **Red-Black Tree**

---

### 7️⃣ Unordered Map

* Fastest lookup
* Uses **Hash Table**

---

### 8️⃣ Priority Queue (Heap)

* Used in **Dijkstra**, **Top K problems**

---

### 9️⃣ Graph (Non-STL)

* BFS, DFS, shortest path

---

### 🔟 Tree (Non-STL)

* Binary Tree, BST, Segment Tree

---

## 🧠 When to Use What?

| Need               | Use              |
| ------------------ | ---------------- |
| Fast random access | `vector`         |
| Unique sorted data | `set`            |
| Key-value pairs    | `map`            |
| Fast lookup        | `unordered_map`  |
| Min/Max element    | `priority_queue` |