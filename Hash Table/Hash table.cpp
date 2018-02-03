#include <iostream>
#include <array>
#include <list>

template<typename K, typename V>
class HashTable
{
private:
    static const unsigned short int TABLE_SIZE = 13003;
    std::array<std::list<std::pair<K, V>>, TABLE_SIZE> table;
    unsigned short int (*hashFunc)(const K&);
public:
    HashTable(unsigned short int (*_hashFunc)(const K&)) :
        hashFunc(_hashFunc)
    {}
    void add(const K& key, const V& value)
    {
        unsigned short int ind = hashFunc(key) % TABLE_SIZE;
        std::pair<K, V> element = std::make_pair(key, value);
        for (typename std::list<std::pair<K, V>>::iterator it =
                table[ind].begin();
             it != table[ind].end();
             ++it)
        {
            if ((*it).first == key)
            {
                (*it).second = value;
                return;
            }
        }
        table[ind].push_back(element);
    }
    bool find(const K& key, V& retValue)
    {
        unsigned short int ind = hashFunc(key) % TABLE_SIZE;
        for (typename std::list<std::pair<K, V>>::iterator it =
                table[ind].begin();
             it != table[ind].end();
             ++it)
        {
            if ((*it).first == key)
            {
                retValue = (*it).second;
                return true;
            }
        }
        return false;
    }
};

unsigned short int hashFunc(const unsigned int& key)
{
    return key;
}

int main()
{
    HashTable<unsigned int, int> hTable(hashFunc);
    hTable.add(5, 21);
    int ret;
    bool res = hTable.find(5, ret);
    std::cout << res << ' ' << ret << std::endl;
    res = hTable.find(3, ret);
    std::cout << res << ' ' << ret << std::endl;
    hTable.add(5, 216);
    res = hTable.find(5, ret);
    std::cout << res << ' ' << ret << std::endl;
    hTable.add(7, 234256);
    res = hTable.find(7, ret);
    std::cout << res << ' ' << ret << std::endl;
    hTable.add(2, 200);
    res = hTable.find(2, ret);
    std::cout << res << ' ' << ret << std::endl;
    hTable.add(34, 1);
    res = hTable.find(31, ret);
    std::cout << res << ' ' << ret << std::endl;
    return 0;
}
