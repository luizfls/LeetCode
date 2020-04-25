struct KeyValue
{
    KeyValue(int pKey, int pValue)
        : key(pKey)
        , value(pValue)
    {}

    int key;
    int value;
};

class LRUCache {
public:
    LRUCache(int capacity)
        : _capacity(capacity)
    {}

    int get(int key) {
        // key exists
        if(auto it = _references.find(key); it != _references.end())
        {
            // sets key as most recently used, if it's not already
            if(it->second != std::prev(_list.end()))
            {
                auto [key, value] = *it->second;
                _list.erase(it->second);
                _list.emplace_back(key, value);
                _references[key] = std::prev(_list.end());
            }

            return it->second->value;
        }

        // key doesn't exist
        return -1;
    }

    void put(int key, int value) {
        auto it = _references.find(key);

        // key already exists and is most recently used; updates value
        if(it != _references.end() && it->second == std::prev(_list.end()))
            it->second->value = value;
        else
        {
            // key already exists and is NOT most recently used; removes from list
            if(it != _references.end())
                _list.erase(it->second);
            // cache is full; removes least recently used
            else if(_list.size() == _capacity)
            {
                _references.erase(_list.front().key);
                _list.pop_front();
            }

            // adds key as most recently used
            _list.emplace_back(key, value);
            _references[key] = std::prev(_list.end());
        }
    }
private:
    int _capacity;
    std::list<KeyValue> _list;
    std::unordered_map<int, std::list<KeyValue>::iterator> _references;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
