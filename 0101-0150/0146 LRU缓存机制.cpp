#include <unordered_map>
#include <list>
#include <iostream>

using namespace std;
// TODO: 换成侵入式双向列表可以提速
class LRUCache {
private:
    int capacity_;
    list<pair<int, int>> cache_;
    unordered_map<int, list<pair<int, int>>::iterator> hash_map_;
public:
    LRUCache(int capacity) : capacity_(capacity) { }

    int get(int key) {
        auto it = hash_map_.find(key);
        if (it == hash_map_.end()) return -1;
        // key 存在，把 (k, v) 换到队头
        pair<int, int> kv = *(it->second);
        cache_.erase(it->second);
        cache_.push_front(kv);
        // 更新 (key, value) 在 cache 中的位置
        hash_map_[key] = cache_.begin();
        return kv.second; // value
    }
    void put(int key, int value) {
        /* 要先判断 key 是否已经存在 */
        auto it = hash_map_.find(key);
        if (it == hash_map_.end()) {
            /* key 不存在，判断 cache 是否已满 */
            if (cache_.size() == capacity_) {
                // cache 已满，删除尾部的键值对腾位置
                // cache 和 map 中的数据都要删除
                hash_map_.erase(cache_.back().first);
                cache_.pop_back();
            }
            // cache 没满，可以直接添加
            cache_.push_front(make_pair(key, value));
            hash_map_[key] = cache_.begin();
        } else {
            /* key 存在，更改 value 并换到队头 */
            cache_.erase(hash_map_[key]);
            cache_.push_front(make_pair(key, value));
            hash_map_[key] = cache_.begin();
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

int main(int argc, char *argv[])
{
    LRUCache cache(2);
    cache.put(1, 1);
    cache.put(2, 2);
    cout << cache.get(1) << "\n"; // 返回 1
    cache.put(3, 3);
    cout << cache.get(2) << "\n"; // 返回 -1 (未找到)
    cache.put(1, 4);
    return 0;
}
