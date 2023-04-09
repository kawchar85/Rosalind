/**
 Link: https://rosalind.info/problems/cons/
 Idea: 
 */

#include <bits/stdc++.h>
using namespace std;

int cnt[4][2003];
int id(char ch) {
    if(ch == 'A') return 0;
    if(ch == 'C') return 1;
    if(ch == 'G') return 2;
    return 3;
}

char get(int a, int b, int c, int d) {
    int mx = max({a, b, c, d});
    if(mx == a) return 'A';
    if(mx == b) return 'C';
    if(mx == c) return 'G';
    return 'T';
}

int main() {
    vector<string> strings;
    string line, name, dna;

    //input
    while(getline(cin, line)) {
        if (line.empty()) {
            continue;
        }
        if (line[0] == '>') {
            if (!name.empty()) {
                strings.push_back(dna);
                dna = "";
            }
            name = line.substr(1);
        } else {
            dna += line;
        }
    }
    strings.push_back(dna);
    int n = dna.size();

    for(auto s : strings) {
        for(int i = 0; i < n; i++) {
            cnt[id(s[i])][i]++;
        }
    }
    
    for(int i = 0; i < n; i++) {
        cout << get(cnt[0][i], cnt[1][i], cnt[2][i], cnt[3][i]);
    }

    cout << "\nA:";
    for(int i = 0; i < n; i++) 
        cout << " " << cnt[0][i];

    cout << "\nC:";
    for(int i = 0; i < n; i++) 
        cout << " " << cnt[1][i];

    cout << "\nG:";
    for(int i = 0; i < n; i++) 
        cout << " " << cnt[2][i];

    cout << "\nT:";
    for(int i = 0; i < n; i++) 
        cout << " " << cnt[3][i];

    
    return 0;
}
