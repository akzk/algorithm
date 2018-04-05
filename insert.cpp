/*
    lintcode 30, 插入区间
    遍历区间集，有交集则item融入newInterval；
    无交集时，若未插入过newInterval且item.start大于newInterval.end，插入newInterval，最后插入item
*/
#include <vector>
using namespace std;

// Definition of Interval:
class Interval {
public:
    int start, end;
    Interval(int start, int end) {
        this->start = start;
        this->end = end;
    }
}

class Solution {
public:
    /*
     * @param intervals: Sorted interval list.
     * @param newInterval: new interval.
     * @return: A new interval list.
     */
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        // write your code here
        vector<Interval> result;
        bool merged = false;
        for (auto &item: intervals)
        {
            if (item.start > newInterval.end || item.end < newInterval.start) { // 没有交集
                if (!merged && newInterval.end < item.start) { // item刚好大于newInterval时
                    result.push_back(newInterval);
                    merged = true;
                }
                result.push_back(item);
            } else { // 有交集
                newInterval.start = min(newInterval.start, item.start);
                newInterval.end = max(newInterval.end, item.end);
            }
        }
        if (!merged) result.push_back(newInterval);
        return result;
    }
};