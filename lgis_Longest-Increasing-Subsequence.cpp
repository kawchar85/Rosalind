/**
 Link: https://rosalind.info/problems/lgis/
 Idea: Binary search. For Longest decreasing subsequenc, reverse the input array!! then find LIS
 */

#include <bits/stdc++.h>
using namespace std;

#define N 20004
int n, a[N], B[N], len[N];

int find_lis() {
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        len[i] = lower_bound(B + 1, B + ans + 1, a[i]) - B;  //Incresing...
        ans = max(ans, len[i]);
        B[len[i]] = a[i];
    }
    return ans;
}

void print_lis(int ans, int rev = 0) {
    vector<int> seq;
    for(int i = n; i >= 1; i--) {
        if(len[i] == ans) {
            seq.push_back(a[i]);
            ans--;
        }
    }

    if(rev) {
        for(auto x : seq) cout << x << " "; cout << "\n";
        return;
    }

    int i = (int)seq.size();
    while(i--)
        cout << seq[i] << " \n"[!i];
}

void init() {
    memset(B, -1, sizeof B);
    memset(len, 0, sizeof len);
}

int main() {
    //input
    cin >> n;
    for(int i = 1; i <= n; i++) 
        cin >> a[i];

    //find LIS
    int answer = find_lis();
    // printf("LIS lenght: %d\n", answer);
    print_lis(answer);

    //find LDS
    for(int i = 1; 2*i <= n; i++) {
        swap(a[i], a[n - i]);
    }

    init();
    answer = find_lis();
    print_lis(answer, 1);
    return 0;
}
