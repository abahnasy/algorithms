//
// Created by Ahmed Bahnasy on 13.09.20.
//

#ifndef ALGORITHMS_PATTERNMATCHING_H
#define ALGORITHMS_PATTERNMATCHING_H

#include <string>
#include <iostream>

using namespace std;

/* Naive matching algorithm */ /* complexity is O(m*(n-m+1)) */
void pattern_matching_naive(const string txt, const string pattern) {
    for (int i =0; i < txt.size() - pattern.size() +1; ++i) {
        int j;
        for (j = 0; j < pattern.size(); ++j) {
            if(txt.at(j+i) != pattern.at(j)) {
                break;
            }
        }
        if(j == pattern.size()) {
            cout << "matching found ! at " << i << "\n";
//            break; // uncomment break if you want to print all matches
        }
    }

}
void construct_lps(int lps [], const string& pattern, int M) {
    int len = 0;
    lps[0] = 0;
    int i = 1;
    while (i <M) {
        if(pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if(len != 0) {
                len = lps[len - 1];
            } else { //len = 0
                lps[i] =0;
                i++;
            }
        }

    }
}
void pattern_matching_kmp(const string& txt, const string& pattern) {
    int n = txt.size();
    int m = pattern.size();
    int lps[m];
    construct_lps(lps, pattern, m);
    int i=0, j=0; // for txt and pattern
    while (i < n) {
        if (txt[i] == pattern[j]) {
            i++;j++;
        }
        if(j == m) { // matching found at i-j
            cout << "matching found !! at " << i - j << "\n";
            j = lps[j-1]; // reset j
        } else if (i<n && txt[i] != pattern[j]) { // no matching
            if(j != 0) {
                j = lps[j-1];
            } else {
                i++;
            }

        }
    }
}

#endif //ALGORITHMS_PATTERNMATCHING_H
