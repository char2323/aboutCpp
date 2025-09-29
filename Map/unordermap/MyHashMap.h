#pragma once

#include <cstddef>
#include <functional>
#include <iostream>
#include <iterator>
#include <type_traits>
#include <utility>
#include <vector>

template <typename K, typename V, typename Hasher = std::hash<K>>
class UnorderedMap {
private:
  struct HashNode {
    std::pair<const K, V> data;
    HashNode *next;
    HashNode(const std::pair<K, V> &p) : data(p), next(nullptr) {}
  };

  std::vector<HashNode *> buckets_;
  size_t size_; // 当前存储的元素个数
  size_t bucket_count_;
  float max_load_factor_;
  Hasher hasher_;

  size_t get_bucket_index(const K &key) const {
    return hasher_(key) % bucket_count_;
  }

  void rehash(size_t new_backet_count) {
    std::vector<HashNode *> new_buckets(new_backet_count, nullptr);
    for (size_t i = 0; i < bucket_count_; ++i) {
      HashNode *current = buckets_[i];
      while (current) {
        HashNode *next_node = current->next;
        size_t new_index = hasher_(current->data.first) % new_backet_count;
        current->next = new_buckets[new_index];
        new_buckets[new_index] = current;
        current = next_node;
      }
    }
    buckets_ = std::move(new_buckets);
    bucket_count_ = new_backet_count;
  }

public:
  class iterator {
  private:
    UnorderedMap *map_ptr_;
    HashNode *current_node_;
    size_t bucket_index_;

  public:
    using iterator_category = std::forward_iterator_tag;
    using value_type = std::pair<const K, V>;
    using difference_type = std::ptrdiff_t;
    using pointer = value_type *;
    using reference = value_type &;

    iterator(UnorderedMap *map, HashNode *node, size_t index)
        : map_ptr_(map), current_node_(node), bucket_index_(index) {}

    reference operator*() const { return current_node_->data; }

    pointer operator->() const { return &(current_node_->data); }

    iterator &operator++() {
      if (current_node_->next)
        current_node_ = current_node_->next;
      else {
        bucket_index_++;
        while (bucket_index_ < map_ptr_->bucket_count_ &&
               map_ptr_->buckets_[bucket_index_] == nullptr) {
          bucket_index_++;
        }

        if (bucket_index_ < map_ptr_->bucket_count_) {
          current_node_ = map_ptr_->buckets_[bucket_index_];
        } else {
          current_node_ = nullptr;
        }
      }
      return *this;
    }

    iterator operator++(int) {
      iterator old = *this;
      ++(*this);
      return old;
    }

    bool operator==(const iterator &other) const {
      return current_node_ == other.current_node_;
    }

    bool operator!=(const iterator &other) const { return !(*this == other); }
  };

  UnorderedMap(size_t initial_bucket_count = 10)
      : size_(0), bucket_count_(initial_bucket_count), max_load_factor_(0.75f) {
    if (bucket_count_ == 0)
      bucket_count_ = 1;
    buckets_.resize(bucket_count_, nullptr);
  }

  ~UnorderedMap() { clear(); }

  iterator begin() {
    if (size_ == 0)
      return end();
    size_t first_bucket = 0;
    while (first_bucket < bucket_count_ && !buckets_[first_bucket]) {
      first_bucket++;
    }
    return iterator(this, buckets_[first_bucket], first_bucket);
  }

  iterator end() { return iterator(this, nullptr, bucket_count_); }

  size_t size() const { return size_; }

  bool empty() const { return size_ == 0; }

  void clear() {
    for (size_t i = 0; i < bucket_count_; ++i) {
      HashNode *current = buckets_[i];
      while (current) {
        HashNode *to_delete = current;
        current = current->next;
        delete to_delete;
      }
      buckets_[i] = nullptr;
    }
    size_ = 0;
  }

  bool insert(const K &key, const V &value) {
    if ((float)(size_ + 1) / bucket_count_ > max_load_factor_) {
      rehash(bucket_count_ * 2);
    }
    auto it = find(key);
    if (it != end()) {
      it->second = value;
      return false;
    }

    size_t index = get_bucket_index(key);
    HashNode *new_node = new HashNode({key, value});
    new_node->next = buckets_[index];
    buckets_[index] = new_node;
    size_++;
    return true;
  }

  iterator find(const K &key) {
    size_t index = get_bucket_index(key);
    HashNode *current = buckets_[index];
    while (current) {
      if (current->data.first == key)
        return iterator(this, current, index);
      current = current->next;
    }
    return end();
  }

  bool erase(const K &key) {
    size_t index = get_bucket_index(key);
    HashNode *current = buckets_[index];
    HashNode *prev = nullptr;
    while (current) {
      if (current->data.first == key) {
        if (!prev)
          buckets_[index] = current->next;
        else {
          prev->next = current->next;
        }
        delete current;
        size_--;
        return true;
      }
      prev = current;
      current = current->next;
    }
    return false;
  }

  V &operator[](const K &key) {
    iterator it = find(key);
    if (it != end()) {
      return it->second;
    } else {
      insert(key, V{});
      return find(key)->second;
    }
  }
};
