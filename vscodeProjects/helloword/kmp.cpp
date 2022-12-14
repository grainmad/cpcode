#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> getlps(string& pat) {
    vector<int>lps(pat.size(), 0);
    int len = 0, j = 1;
    while (j < pat.size()) {
        if (pat[len] == pat[j]) {
            len++;
            lps[j] = len;
            j++;
        } else {
            if (len == 0) {
                lps[j]=0;
                j++;
            } else {
                len = lps[len-1];
            }
        }
    }
    for (int i=0; i<lps.size(); i++) {
        cout << lps[i] << " ";
    } cout << endl;
    return lps;
}

void kmpsearch(string& pat, string& txt) {
    vector<int> lps = getlps(pat);
    int i=0, j=0;
    while (i<txt.size()) {
        if (pat[j] == txt[i]) {
            i++; j++;
        }
        if (j == pat.size()) {
            cout << "find in: " << i-j << endl;
            j = lps[j-1];
        }
        if (pat[j] != txt[i]) {
            if (j!=0) j=lps[j-1];
            else {
                i++;
            }
        }
    }
}

int main() {
    string a = "abcdabcdabcd";
    string b = "bcd";
    kmpsearch(b, a);
    return 0;
}