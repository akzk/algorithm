/*
    lintcode 22, 平面列表
*/

#include <vector>
using namespace std;

// This is the interface that allows for creating nested lists.
// You should not implement it, or speculate about its implementation
class NestedInteger {
  public:
    // Return true if this NestedInteger holds a single integer,
    // rather than a nested list.
    bool isInteger() const;

    // Return the single integer that this NestedInteger holds,
    // if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const;

    // Return the nested list that this NestedInteger holds,
    // if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger> &getList() const;
};

class Solution {
public:
    // @param nestedList a list of NestedInteger
    // @return a list of integer
    vector<int> flatten(vector<NestedInteger> &nestedList) {
        // Write your code here
        vector<int> result;
        flattenHelper(result, nestedList);
        return result;
    }

    void flattenHelper(vector<int> &a, vector<NestedInteger> &b)
    {
        for (auto &item: b)
        {
            if (item.isInteger())
                a.push_back(item.getInteger());
            else {
                vector<NestedInteger> tmp = item.getList();
                flattenHelper(a, tmp);
            }
        }
    }
};