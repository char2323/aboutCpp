#pragma once
#include <iostream>
#include <stack>
#include <utility>

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

  Node *insert(Node *node, const K &key, const V &value) {
    if (!node)
      return new Node(key, value);
    if (key < node->key)
      node->left = insert(node->left, key, value);
    else if (key > node->key)
      node->right = insert(node->right, key, value);
    else
      node->value = value;
    return node;
  }

public:
  BSTMap() : root(nullptr) {}
  ~BSTMap() { clear(root); }

  void insert(const K &key, const V &value) { root = insert(root, key, value); }
};
