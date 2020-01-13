#include <unordered_map>
#include <map>
#include <iostream>

using namespace std;

class LFUCache {
private:
    int capacity_;
    using freq_cache_t = multimap<int, pair<int, int>>; // <频次 <关键词 值>>
    using hash_map_t = unordered_map<int, freq_cache_t::iterator>; // <关键词 freq_cache_迭代器>
    freq_cache_t freq_cache_;
    hash_map_t hash_map_;

public:
    LFUCache(int capacity) : capacity_(capacity) { }

    int get(int key) {
        auto it = hash_map_.find(key);
        if (it == hash_map_.end()) return -1;
        auto value = it->second->second.second;
        // 此 key 的频次递增
        freq_inc(key);
        return value;
    }
    void put(int key, int value) {
        auto it = hash_map_.find(key);
        if (it == hash_map_.end()) {
            if (hash_map_.size() == capacity_) {
                auto it = freq_cache_.begin();
                auto k = it->second.first;
                freq_cache_.erase(it);
                hash_map_.erase(k);
            }
            auto freq_it = freq_cache_.insert({0, {key, value}});
            hash_map_.insert({key, freq_it});
        } else {
            // 此 key 的频次递增
            freq_inc(key);
            it->second->second.second = value;
        }
    }
    void freq_inc(int key) {
        auto it = hash_map_.find(key);
        auto freq = it->second->first;      // freq;
        auto kv = it->second->second;
        auto freq_it = freq_cache_.insert({++freq, kv});
        freq_cache_.erase(it->second);
        it->second = freq_it;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

int main(int argc, char *argv[])
{
    // LFUCache cache(0);
    // cache.put(0, 0);
    // cout << cache.get(0);
    LFUCache cache(2);
    cache.put(1, 1);
    cache.put(2, 2);
    cout << cache.get(1) << "\n";
    cache.put(3, 3);
    cout << cache.get(2) << "\n";
    cout << cache.get(3) << "\n";
    cache.put(4, 4);
    cout << cache.get(1) << "\n";
    cout << cache.get(3) << "\n";
    cout << cache.get(4) << "\n";

    return 0;
}
