/*
    lintcode 24, LFU缓存
*/
#include <map>
#include <queue>
using namespace std;

class LFUCache {
private:
    int size;
    map<int, int> data;
    map<int, int> count;
    vector<int> history;
public:
    /*
    * @param capacity: An integer
    */
    LFUCache(int capacity) {
        // do intialization if necessary
        size = capacity;
    }

    /*
     * @param key: An integer
     * @param value: An integer
     * @return: nothing
     */
    void set(int key, int value) {
        // write your code here
        if (data.find(key) == data.end()) { // 不存在
            if (data.size() < size) { // 扩容
                data[key] = value;
                count[key] = 0;
                history.push_back(key);
            } else { // 不扩容，删除，插入
                int index, min=0;
                for (auto it=count.begin(); it!=count.end(); it++)
                {
                    if (min > it->second) {
                        index = it->first;
                        min = it->second;
                    } else if (min == it->second) {
                        for (int i=0; i<history.size(); i++)
                        {
                            if (history[i] == index) return;
                            if (history[i] == it->first) {
                                index = it->first;
                                return;
                            }
                        }
                    }
                }

                data.erase(index);
                count.erase(index);
                for (int i=0; i<history.size(); i++) if (history[i] == index) history.erase(i+history.begin());
                
                data[key] = value;
                count[key] = 0;
                history.push_back(key);
            }
        } else { // 存在，直接覆盖
            data[key] = value;
            count[key] = 0;
            for (int i=0; i<history.size(); i++) if (history[i] == key) history.erase(i+history.begin());
            history.push_back(key);
        }
    }

    /*
     * @param key: An integer
     * @return: An integer
     */
    int get(int key) {
        // write your code here
        if (data.find(key) == data.end()) {
            return -1;
        } else {
            count[key] += 1;
            for (int i=0; i<history.size(); i++) if (history[i] == key) history.erase(i+history.begin());
            history.push_back(key);
            return data[key];
        }
    }
};