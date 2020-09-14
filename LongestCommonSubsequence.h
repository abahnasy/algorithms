//
// Created by Ahmed Bahnasy on 16.08.20.
//

#ifndef ALGORITHMS_LONGESTCOMMONSUBSEQUENCE_H
#define ALGORITHMS_LONGESTCOMMONSUBSEQUENCE_H

#include <vector>
#include <string>
#include <stack>
#include <iostream>

using namespace std;

typedef vector<int> vi ;
typedef vector<vector<int>> vii ;

// Longest common subsequence using BD approach

int length_lcs(const string s1, const string s2) {
    int len_s1 = s1.length();
    int len_s2 = s2.length();
    vii dp (len_s1+1, vi(len_s2+1, 0));
    for (int i = 1; i <= len_s1 ; ++i) {
        for (int j = 1; j <= len_s2; ++j) {
            if(s1[i-1] == s2[j-1]) {
                dp[i][j] = 1 + dp[i-1][j-1];
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    return dp[len_s1][len_s2];
}

// WARNING: NEED TO BE TESTED !!
void retrieve_lcs(vii& db, const string& s1, const string& s2) {
    stack <char> stk;
    int i = s1.size(); int j = s2.size();
    while (i > 0) {
        while (j > 0) {
            if (db[i][j] == db[i-1][j]) {
                i--;
            } else if (db[i][j] == db[i][j-1]) {
                j--;
            } else {
                stk.push(s1[i]);
                i--;j--;
            }
        }
    }
    while(!stk.empty()) {
        cout << stk.top();
        stk.pop();
    }

}

#endif //ALGORITHMS_LONGESTCOMMONSUBSEQUENCE_H
