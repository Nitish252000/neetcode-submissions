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
            order.pop_front();
            cache.erase(lru);
        }
        order.push_back(key);
        cache[key]=value;
    }
};
