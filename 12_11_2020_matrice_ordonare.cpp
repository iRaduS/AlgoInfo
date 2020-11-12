#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("input.txt");

int main() {
    int x, m, n, i = 1, j = 1, v[100*100], k = 0;
    fin >> m >> n;

    while (fin >> x) {
        if (i == 1 || j == 1 || i == m ||  j == n)
            v[k++] = x;

        j++;
        if (j > n) {
            i++;
            j = 1;
        }
    }

    for (int ind = 0; ind < k; ind++) {
        for (int col = ind + 1; col < k; col++) {
            if (v[ind] > v[col])
            {
                int aux = v[ind];
                v[ind] = v[col];
                v[col] = aux;
            }
        }
    }

    for (int ind = 0; ind < k; ind++) {
        cout << v[ind] << ' ';
    }
    return 0;
}
