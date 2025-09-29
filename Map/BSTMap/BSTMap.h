#pragma once
#include <iostream>
#include <stack>
#include <utility>

// 二叉搜索树 (BST) 实现的 Map 映射类
template <typename K, typename V> class BSTMap {
private:
  // 节点结构体，存储键值对
  struct Node {
    K key;       // 键
    V value;     // 值
    Node *left;  // 左子树
    Node *right; // 右子树
    Node(const K &k, const V &v)
        : key(k), value(v), left(nullptr), right(nullptr) {}
  };

  Node *root; // 根节点指针

  // 插入节点（递归实现）
  Node *insert(Node *node, const K &key, const V &value) {
    if (!node)
      return new Node(key, value);
    if (key < node->key)
      node->left = insert(node->left, key, value);
    else if (key > node->key)
      node->right = insert(node->right, key, value);
    else
      node->value = value; // 键已存在，覆盖值
    return node;
  }

  // 查找节点（递归实现）
  Node *find(Node *node, const K &key) const {
    if (!node)
      return nullptr;
    if (key < node->key)
      return find(node->left, key);
    else if (key > node->key)
      return find(node->right, key);
    else
      return node;
  }

  // 删除节点（递归实现）
  Node *erase(Node *node, const K &key) {
    if (!node)
      return nullptr;
    if (key < node->key) {
      node->left = erase(node->left, key);
    } else if (key > node->key) {
      node->right = erase(node->right, key);
    } else {
      if (!node->left) {
        Node *rightChild = node->right;
        delete node;
        return rightChild;
      } else if (!node->right) {
        Node *leftChild = node->left;
        delete node;
        return leftChild;
      } else {
        Node *minNode = node->right;
        while (minNode->left)
          minNode = minNode->left;
        node->key = minNode->key;
        node->value = minNode->value;
        node->right = erase(node->right, minNode->key);
      }
    }
    return node;
  }

  // 递归释放树
  void clear(Node *node) {
    if (!node)
      return;
    clear(node->left);
    clear(node->right);
    delete node;
  }

public:
  BSTMap() : root(nullptr) {}
  ~BSTMap() { clear(root); }

  void insert(const K &key, const V &value) { root = insert(root, key, value); }

  bool contains(const K &key) const { return find(root, key) != nullptr; }

  V &operator[](const K &key) {
    Node *node = find(root, key);
    if (!node) {
      root = insert(root, key, V());
      node = find(root, key);
    }
    return node->value;
  }

  void erase(const K &key) { root = erase(root, key); }

  // ======================
  // 迭代器定义（中序遍历）
  // ======================
  class iterator {
  private:
    std::stack<Node *> stk;

    void pushLeft(Node *node) {
      while (node) {
        stk.push(node);
        node = node->left;
      }
    }

  public:
    iterator(Node *root = nullptr) { pushLeft(root); }

    bool operator==(const iterator &other) const { return stk == other.stk; }
    bool operator!=(const iterator &other) const { return !(*this == other); }

    // 返回 pair 的引用 (key const, value 可改)
    std::pair<const K &, V &> operator*() const {
      Node *node = stk.top();
      return {node->key, node->value};
    }

    std::pair<const K &, V &> *operator->() const {
      Node *node = stk.top();
      // 返回一个静态存储的对象，避免悬空指针
      static std::pair<const K &, V &> temp(node->key, node->value);
      temp.first = node->key;
      temp.second = node->value;
      return &temp;
    }

    iterator &operator++() {
      Node *node = stk.top();
      stk.pop();
      if (node->right)
        pushLeft(node->right);
      return *this;
    }
  };

  class const_iterator {
  private:
    std::stack<const Node *> stk;

    void pushLeft(const Node *node) {
      while (node) {
        stk.push(node);
        node = node->left;
      }
    }

  public:
    const_iterator(const Node *root = nullptr) { pushLeft(root); }

    bool operator==(const const_iterator &other) const {
      return stk == other.stk;
    }
    bool operator!=(const const_iterator &other) const {
      return !(*this == other);
    }

    // 返回只读 pair
    std::pair<const K &, const V &> operator*() const {
      const Node *node = stk.top();
      return {node->key, node->value};
    }

    const std::pair<const K &, const V &> *operator->() const {
      const Node *node = stk.top();
      static std::pair<const K &, const V &> temp(node->key, node->value);
      temp.first = node->key;
      temp.second = node->value;
      return &temp;
    }

    const_iterator &operator++() {
      const Node *node = stk.top();
      stk.pop();
      if (node->right)
        pushLeft(node->right);
      return *this;
    }
  };

  iterator begin() { return iterator(root); }
  iterator end() { return iterator(nullptr); }

  const_iterator begin() const { return const_iterator(root); }
  const_iterator end() const { return const_iterator(nullptr); }
};
