/**
 Link: https://rosalind.info/problems/fibd/
 Idea: 
    All rabbits will live for m months, and their age will range from 0 to m-1.
    For each month, we need to keep track of the number of rabbits of each age.
    At the start of each month, rabbits of age m-1 will die, and rabbits of age 0 to m-2 will survive to the next month and will age by 1 month.
    Rabbits of age 1 to m-1 will produce new rabbits of age 0.
    
    Repeat this process for n months and count the total number of rabbits that remain at the end.

 */

#include<bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    int n, m;
    cin >> n >> m;

    vector<int> rabbits(m, 0);
    rabbits[0] = 1; //initially, month 1, 1 pair of age 0, 0 pair of 0 to m-1 age

    for(int month = 2; month <= n; month++) {
        int new_born = 0;
        for(int i = 1; i < m; i++) {
            new_born += rabbits[i];
        }
        //update age by 1 month
        for(int i = m - 1; i > 0; i--) {
            rabbits[i] = rabbits[i - 1];
        }
        rabbits[0] = new_born;
    }

    int total = 0;
    for(int age = 0; age < m; age++) {
        total += rabbits[age];
    }

    cout << total << endl;

    return 0;
}
