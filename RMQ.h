//
// Created by Ahmed Bahnasy on 14.08.20.
//

#ifndef ALGORITHMS_RMQ_H
#define ALGORITHMS_RMQ_H

#include <vector>
#include <iostream>

using namespace std;

const int MAXN = 5;

// This trivial algorithm is quite slow and uses O(N2) memory, so it won’t work for large cases.
void process_range_min_query(int M[MAXN][MAXN], int A[MAXN]) {
    for (int i = 0; i < MAXN; ++i) {
        M[i][i] = i;
    }
    // symmetric matrix
    for (int i = 0; i < MAXN; ++i) {
        for (int j = i+1; j < MAXN; ++j) {
            if(A[M[i][j-1]] < A[j])
                M[i][j] = M[i][j-1];
            else
                M[i][j] = j;
            M[j][i] = M[i][j]; //symmetric matrix
        }
    }

}



#endif //ALGORITHMS_RMQ_H
