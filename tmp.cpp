#include <string>
#include <iostream>
#include <map>
#include <string.h>
using namespace std;

int main() {
    string s = "aaabb";
    string t = "bab";
    
    int m[256];
    memset(m, 0, 256);
    for (auto c: t) m[c] += 1;
    
    int count = 0;
    int szs = s.size();
    int szt = t.size();
    
    if (szs == szt) {
        for (int i=0; i<szs; i++)
            if (s[i]!=t[i]) count += 1;
        cout << count << endl;
        return 0;
    }

    for (int i=szt-1; i<=szs-szt; i++) count += m[s[i]];
    
    int tt = szs-szt;
    for (int i=0; i<tt; i++)
        for (int j=0; j<tt-i; j++)
            if (s[i+j]!=t[j]) count += 1;
    for (int i=szs-1; i>=szs-tt; i--)
        for (int j=0; j<=szs-i; j++)
            if (s[i-j]!=t[szt-j-1]) count += 1;
    
    cout << count << endl;
}