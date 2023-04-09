/**
 Link: https://rosalind.info/problems/sign/
 Idea: Backtracking
 */

#include <bits/stdc++.h>
using namespace std;

vector< vector<int> > all_seq;
int n;

bool find(int k, vector<int> v) {
    for(auto x : v) {
        if(abs(x) == k) return 1;
    }
    return 0;
}

void gen(vector<int> seq) {
    
    if(seq.size() == n ) {
        all_seq.push_back(seq);
        return;
    }

    for(int i = 1; i <= n; i++) {
        if(!find(i, seq)) {
            seq.push_back(-i);
            gen(seq);
            seq.pop_back();

            seq.push_back(i);
            gen(seq);
            seq.pop_back();
        }
    }
}
int main() {
    //input
    cin >> n;
    
    vector<int> seq;
    gen(seq);

    cout << all_seq.size() << "\n";
    for(auto v : all_seq) {
        for(auto x : v) {
            cout << x << " ";
        } cout << endl;
    }
    return 0;
}
