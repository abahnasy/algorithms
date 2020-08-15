//
// Created by Ahmed Bahnasy on 14.08.20.
//


#include <vector>
#include <iostream>

using namespace std;


bool LEFT_TO_RIGHT = true;
bool RIGHT_TO_LEFT = false;



int fac (int x) {
    if(x <2)
        return x;
    else
        return x * fac(x-1);
}

void print_permutation_naive(int s) {

    vector<int> a(s,0);
    int n = a.size();
    for (int i = 0; i < n; ++i) {
        a[i] = i+1;
    }
    int perm = fac(n);
    int i = 0;

    while(i < perm-1) {
        int idx = n-1;
        while(idx != 0) {
            int t = a[idx];
            a[idx] = a[idx-1];
            a[idx-1] = t;
            for (int c: a)
                cout << c;
            cout << " ";
            idx--;
            i++;
        }
    }

}

int get_mobile_element(vector<int>& a, bool dir[], int n) {
    int mobile = 0;
    for (int i = 0; i < n; ++i) {
        if(dir[a[i]] == RIGHT_TO_LEFT && i != 0) { //check right neighbours, since comparison will be with i-1
            if(a[i] > a[i-1] && a[i] > mobile) {
                mobile = a[i];
            }
        }
        if(dir[a[i]] == LEFT_TO_RIGHT && i!= n-1) {
            if(a[i] > a[i+1] && a[i] > mobile) {
                mobile = a[i];
            }
        }
    }
    if(mobile == -1)
        return 0;
    else
        return mobile;
}

int get_index(vector<int>& a, int n, int element) {
    for (int i = 0; i < n; ++i) {
        if(a[i] == element)
            return i;
    }
}

void update_directions(vector<int>& a, bool dir[], int n, int idx) {
    for(int i =0; i <n; ++i) {
        if(a[i] > a[idx]) {
            if(dir[a[i]] == RIGHT_TO_LEFT)
                dir[a[i]] = LEFT_TO_RIGHT;
            else
                dir[a[i]] = RIGHT_TO_LEFT;
        }
    }
}
void print_one_permutation(vector<int>& a, bool dir[], int n) {

    int mobile = get_mobile_element(a,dir,n);
    int idx = get_index(a,n,mobile);

    if(dir[mobile] == RIGHT_TO_LEFT) {
        int temp  = a[idx-1];
        a[idx-1] = a[idx];
        a[idx] = temp;
        idx--;
        // update directions of larger elements
    } else {
        int temp = a[idx+1];
        a[idx+1] = a[idx];
        a[idx] = temp;
        idx++;
        // update directions of larger elements
    }
    update_directions(a, dir, n, idx);
    for (int i = 0; i < n; ++i) {
        cout << a[i];
    }
    cout << " ";

}
void print_permutation(int n) {
    vector<int> a (n, 0);
    bool dir[n+1];
    //print the first permutation
    for (int i = 0; i < n; ++i) {
        a[i] = i+1;
        dir[a[i]] = RIGHT_TO_LEFT;
        cout << a[i];
    }
    cout << " ";
    for (int i = 1; i < fac(n); ++i) {
        print_one_permutation(a,dir,n);
    }
}

