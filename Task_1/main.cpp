#include <vector>
#include <utility>
#include <ranges>
#include <iterator>

template<class K, class V>
class SearchingTree {
private:
    struct Node {
        std::pair<K, V> data;
        Node *l = nullptr, *r = nullptr;

        ~Node() {
            delete l;
            delete r;
        }
    };

    Node *root = nullptr;

    class iterator {
        friend class SearchingTree;
    private:
        std::vector<const Node *> path;
    public:
        bool operator==(const iterator &other) const;
        iterator &operator++();
        iterator operator++(int);
        iterator &operator--();
        iterator operator--(int);
        const std::pair<K, V> &operator*() const;
        const std::pair<K, V> *operator->() const;
    };
public:
    ~SearchingTree() {
        delete root;
    }

    void insert(const K &key, const V &value);
    void erase(const K &key);
    auto lower_bound(const K &key) const;
    auto find(const K &key) const;
    auto begin() const;
    auto end() const;
    auto range(const K &a, const K &b) const;
};
