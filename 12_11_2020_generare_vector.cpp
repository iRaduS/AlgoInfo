#include <iostream>
using namespace std;

const int N_MAX = 1000;
int n, v[N_MAX];

int main() {
    cin >> n;

    int mid =  (n + 1) / 2;
    if (n % 2 == 0) {
        mid++;
    }

    v[mid] = n;
    int st = mid - 1, dr = mid + 1,

    k = (n % 2) ? n - 1 : n - 2;
    while(dr <= n) {
        v[dr] = k;
        dr++;

        k -= 2;
    }

    k = (n % 2) ? n - 2 : n - 1;
    while(st >= 0) {
        v[st] = k;
        st--;

        k -= 2;
    }

    for (int i = 1; i <= n; i++) {
        cout << v[i] << ' ';
    }
    return 0;
}
