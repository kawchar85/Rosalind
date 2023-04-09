/**
 Link: https://rosalind.info/problems/lcsm/
 Idea: Binary search on ans(length of LCS)
 */

#include <bits/stdc++.h>
using namespace std;

bool hasCommonSubstring(vector<string> &strings, int length) {
    unordered_set<string> substrings;
    for (int i = 0; i <= strings[0].size() - length; i++) {
        substrings.insert(strings[0].substr(i, length));
    }
    for (int i = 1; i < strings.size(); i++) {
        bool found = 0;
        for (int j = 0; j <= strings[i].size() - length; j++) {
            if (substrings.count(strings[i].substr(j, length))) {
                found = 1;
                break;
            }
        }
        if (!found) {
            return 0;
        }
    }
    return 1;
}

string findLongestCommonSubstring(vector<string> &strings) {
    int minLength = strings[0].size();
    for (int i = 1; i < strings.size(); i++) {
        minLength = min(minLength, (int)strings[i].size());
    }

    //binary search
    int l = 0, r = minLength, mid, length = 0;
    while (l <= r) {
        mid = (l + r) / 2;
        if (hasCommonSubstring(strings, mid)) {
            length = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    //find ans

    //gp_hash_table will be faster
    unordered_set<string> substrings;
    for (int i = 0; i <= strings[0].size() - length; i++) {
        substrings.insert(strings[0].substr(i, length));
    }

    for (int i = 1; i < strings.size(); i++) {
        unordered_set<string> temp;
        for (int j = 0; j <= strings[i].length() - length; j++) {
            if (substrings.count(strings[i].substr(j, length))) {
                temp.insert(strings[i].substr(j, length));
            }
        }
        substrings = temp;
    }
    return *substrings.begin();
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
    
    cout << findLongestCommonSubstring(strings) << endl;
    return 0;
}
