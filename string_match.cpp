/*
    字符串匹配，Sunday算法
    资料：
        http://blog.csdn.net/gerl123456/article/details/51189678
        http://blog.csdn.net/l953972252/article/details/51331001
*/

#include <iostream>
using namespace std;

int strmatch(const char* text, const char* pattern);
int sunday(const char* text, const char* pattern);

int strmatch(const char* text, const char* pattern)
{
    return sunday(text, pattern);
}

int sunday(const char* text, const char* pattern)
{
    int i = 0;
    int lenText = strlen(text);
    int lenPatt = strlen(pattern);
    char map[CHAR_MAX];

    // check
    if (lenText < lenPatt) return -1;

    // preprocess
    for (i=0; i<CHAR_MAX; i++) map[i] = lenPatt+1;
    for (i=0; i<lenPatt; i++) map[pattern[i]] = lenPatt-i;

    // matching
    i = 0;
    while (i<=lenText-lenPatt)
    {
        if (strncmp(text+i, pattern, lenPatt) == 0) return i;
        else i += map[text[i+lenPatt]];
    }

    return -1;
}

int main()
{
    cout << strmatch("here is a simple example", "example");
}
