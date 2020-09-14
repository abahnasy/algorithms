
#include "PatternMatching.h"


int main() {
    string txt =  "ABABDABACDABABCABAB";
    string pattern = "ABABCABAB";
    cout << "naive\n";
    pattern_matching_naive(txt, pattern);
    cout << "kmp\n";
    pattern_matching_kmp(txt, pattern);

    return 0;
}