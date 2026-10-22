class LRUCache {
   public:
    unordered_map<int, int> cache;
    list<int> order;
    int capacity;
    LRUCache(int capacity) { this->capacity = capacity; }

    int get(int key) {
        if (cache.find(key) == cache.end()) return -1;
        // Move key to the most recently used position
        order.remove(key);
        order.push_back(key);
        return cache[key];
    }

    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            order.remove(key); // Remove old position
        }
        else if(cache.size()==capacity){
            int lru = order.front();             // Evict least recently used key
            order.pop_front();   // remove least recently used key
            cache.erase(lru);
        }
        order.push_back(key);
        cache[key]=value;
    }
};

// A list is similar to a vector in that it can store multiple elements of the same type and dynamically grow in size.

// However, two major differences between lists and vectors are:

// You can add and remove elements from both the beginning and at the end of a list, while vectors are generally optimized for adding and removing at the end.

// Unlike vectors, a list does not support random access, meaning you cannot directly jump to a specific index, or access elements by index numbers.