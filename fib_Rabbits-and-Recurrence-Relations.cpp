/**
 Link: https://rosalind.info/problems/fib/
 Idea: 
 */

#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    //input
    int n, k;
    cin >> n >> k;
    
    vector<ll> rabbits(n+1);
    rabbits[1] = rabbits[2] = 1;

    for(int i = 3; i <= n; i++) {
        rabbits[i] = rabbits[i-1] + k * rabbits[i-2];
    } 

    cout << rabbits[n] << "\n";
    return 0;
}
