/*
    lintcode 532, 剑指offer 51, 逆序对
*/

#include <vector>
using namespace std;

class Solution {
public:
    /*
     * @param A: an array
     * @return: total of reverse pairs
     */
    long long reversePairs(vector<int> &A) {
        // write your code here
        long long res = 0;
        if (A.size()==0) return res;
        vector<int> tmp(A.size(), 0);
        reversePairsHelper(A, 0, A.size()-1, res, tmp);
        return res;
    }

    void reversePairsHelper(vector<int> &A, int i, int j, long long &res, vector<int> &tmp) {
        if (i==j) return;

        int length = j-i+1;
        int left_end = (i+j)/2;
        int right_start = left_end+1;
        reversePairsHelper(A, i, left_end, res, tmp);
        reversePairsHelper(A, right_start, j, res, tmp);
        
        int a = i, b = right_start;
        for (int k=0; k<length; k++)
        {
            if (a>left_end) tmp[k] = A[b++];
            else if (b>j) tmp[k] = A[a++];
            else {
                if (A[a] > A[b]) {
                    res += (left_end-a+1);
                    tmp[k] = A[b++];
                } else {
                    tmp[k] = A[a++];
                }
            }
        }
        for (int k=0; k<length; k++) A[i++] = tmp[k];
    }
};