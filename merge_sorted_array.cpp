/*
    lintcode 4，合并两个排序数组
    归并
*/
#include <iostream>
#include <vector>
using namespace std;

vector<int> mergeSortedArray(vector<int> &A, vector<int> &B) {
    vector<int> res(A.size()+B.size());
    int i = 0;
    int j = 0;
    int k = res.size();

    while (k--) {
        int a = A[i];
        int b = B[j];

        if (a > b) {
            res[k] = a;
            i++;
        } else {
            res[k] = b;
            j++;
        }
    }

    return res;
}

int main() {

}