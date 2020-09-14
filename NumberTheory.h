//
// Created by Ahmed Bahnasy on 16.08.20.
//

#ifndef ALGORITHMS_NUMBERTHEORY_H
#define ALGORITHMS_NUMBERTHEORY_H

#include <vector>
#include <cmath>
using namespace std;

int fast_exponentiation(int n, int exp) {
    if(exp == 0)
        return 1;
    else if (exp == 1)
        return n;
    else {
        int r = fast_exponentiation(n, exp/2);
        if(exp % 2 == 0)
            return r*r;
        else
            return r*n*r;
    }
}


//Sieve of Eratosthenes implementation
// O(nlog(log(n))
vector<int> get_primes_till (int n) {
    vector<int> result;
    vector<bool> prime (n+1, true);
    for (int i = 2; i*i <= n; ++i) {
        if(prime[i] == true) {
            for (int j = i*i; j < n; j+=i)
                prime[j] = false;
        }
    }
    for (int i = 2; i <=n ;++i)
        if(prime[i] == true)
            result.push_back(i);
}

#endif //ALGORITHMS_NUMBERTHEORY_H
