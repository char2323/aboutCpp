#pragma once
#include <algorithm>
#include <cstddef>
#include <functional>
#include <iostream>

template <typename K, typename V> class AVLMap {
private:
  struct AVLNode {
    K key;
    V value;
    int height;
    AVLNode *left;
    AVLNode *right;
    AVLNode(const K &k, const V &v)
        : key(k), value(v), height(1), left(nullptr), right(nullptr) {};
  };

  AVLNode *root;
  std::size_t map_size;

  int getHeight(AVLNode *node) {
    if (!node)
      return 0;
    return node->height;
  }

  int getBalance(AVLNode *node) {
    if (!node)
      return 0;
    return getHeight(node->left) - getHeight(node->right);
  }

  void updateHeight(AVLNode *node) {
    if (node) {
      node->height =
          1 + std::max(getHeight(node->left), getHeight(node->right));
    }
  }

  AVLNode *rightRotate(AVLNode *y) {
    auto x = y->left;
    auto T2 = x->right;
    x->right = y;
    y->left = T2;
    updateHeight(y);
    updateHeight(x);
    return x;
  }

  AVLNode *leftRotate(AVLNode *x) {
    auto y = x->right;
    auto T2 = y->left;
    y->left = x;
    x->right = T2;
    updateHeight(x);
    updateHeight(y);
    return y;
  }

  AVLNode *insertNode(AVLNode *node, const K &key, const V &value) {
    if (!node) {
      map_size++;
      return new AVLNode(key, value);
    } else if (key < node->key) {
      node->left = insertNode(node->left, key, value);
    } else if (key > node->key) {
      node->right = insertNode(node->right, key, value);
    } else {
      node->value = value;
      return node;
    }

    updateHeight(node);

    int balance = getBalance(node);

    if (balance > 1 && key < node->left->key) {
      // case LL,need to rightRotate
      return rightRotate(node);
    }
    if (balance < -1 && key > node->right->key) {
      // case RR,need to leftRotate
      return leftRotate(node);
    }
    if (balance > 1 && key > node->left->key) {
      // case LR,need to leftRotate+rightRotate
      node->left = leftRotate(node->left);
      return rightRotate(node);
    }
    if (balance < -1 && key < node->right->key) {
      // case RL,need to rightRotate+leftRotate
      node->right = rightRotate(node->right);
      return leftRotate(node);
    }

    return node;
  }

  AVLNode *minValueNode(AVLNode *node) {
    AVLNode *current = node;
    while (current && current->left) {
      current = current->left;
    }
    return current;
  }

  AVLNode *deleteNode(AVLNode *node, const K &key) {
    if (!node)
      return nullptr;
    if (key < node->key)
      node->left = deleteNode(node->left, key);
    else if (key > node->key)
      node->right = deleteNode(node->right, key);
    else {
      if (!node->left || !node->right) {
        // only have one subnode or have no subnode
        auto temp = node->left ? node->left : node->right;
        delete node;
        map_size--;
        return temp;
      } else {
        AVLNode *temp = minValueNode(node->right);
        node->key = temp->key;
        node->value = temp->value;
        node->right = deleteNode(node->right, temp->key);
      }
    }

    if (!node)
      return nullptr;

    updateHeight(node);

    int balance = getBalance(node);

    if (balance > 1 && getBalance(node->left) >= 0) {
      // case LL
      return rightRotate(node);
    }

    if (balance > 1 && getBalance(node->left) < 0) {
      // case LR
      node->left = leftRotate(node->left);
      return rightRotate(node);
    }

    if (balance < -1 && getBalance(node->right) <= 0) {
      // case RR
      return leftRotate(node);
    }

    if (balance < -1 && getBalance(node->right) > 0) {
      // case RL
      node->right = rightRotate(node->right);
      return leftRotate(node);
    }

    return node;
  }

  void inOrderTraversalHelper(AVLNode *node) const {
    if (node) {
      inOrderTraversalHelper(node->left);
      std::cout << "Key: " << node->key << ", Value: " << node->value
                << std::endl;
      inOrderTraversalHelper(node->right);
    }
  }

  const AVLNode *findNode(AVLNode *node, const K &key) const {
    if (!node || node->key == key)
      return node;
    if (key < node->key)
      return findNode(node->left, key);
    else
      return findNode(node->right, key);
  }

  AVLNode *findNode(AVLNode *node, const K &key) {
    if (!node || node->key == key)
      return node;
    if (key < node->key)
      return findNode(node->left, key);
    else
      return findNode(node->right, key);
  }

  void clear(AVLNode *node) {
    if (node) {
      clear(node->left);
      clear(node->right);
      delete node;
    }
  }

public:
  AVLMap() : root(nullptr), map_size(0) {}
  ~AVLMap() { clear(root); }
  // ~AVLMap() {
  //   std::function<void(AVLNode *)> clear = [&](AVLNode *node) {
  //     if (node) {
  //       clear(node->left);
  //       clear(node->right);
  //       delete node;
  //     }
  //   };
  //   clear(root);
  // }

  AVLMap(const AVLMap &) = delete;
  AVLMap &operator=(const AVLMap &) = delete;

  void insert(const K &key, const V &value) {
    root = insertNode(root, key, value);
  }

  void erase(const K &key) { root = deleteNode(root, key); }

  const V *find(const K &key) const {
    const AVLNode *node = findNode(root, key);
    if (node) {
      return &node->value;
    }
    return nullptr;
  }

  V &operator[](const K &key) {
    AVLNode *node = findNode(root, key);
    if (node) {
      return node->value;
    } else {
      insert(key, V{});
      node = findNode(root, key);
      return node->value;
    }
  }

  size_t size() const { return map_size; }

  bool empty() const { return map_size == 0; }

  void in_order_traversal() const {
    inOrderTraversalHelper(root);
    std::cout << "--- End of Traversal ---" << std::endl;
  }
};
