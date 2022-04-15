#include "../../header.h"

int combs(int m, int n) {
    if (n < 0 or m > n) {
        return 0;
    } else if (m == n or m == 0) {
        return 1;
    } else {
        return combs(m, n - 1) + combs(m - 1, n - 1);
    }
}

int recursion_combs_f1() {

    cout << combs(7, 11);
    return 0;
}