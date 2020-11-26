#include <iostream>
#include <cstring>
using namespace std;



// PROBLEMA 1)
const int N_MAX = 201;
char phrase[N_MAX], ans[N_MAX];
void rev(char* phrase) {
    size_t szStr = strlen(phrase);

    for (size_t i = 0; i < szStr / 2; ++i) {
        char aux = phrase[i];
        phrase[i] = phrase[(szStr - 1) - i];
        phrase[(szStr - 1) - i] = aux;
    }
}
int main() {
    cin.getline(phrase, N_MAX);
    size_t strSz = strlen(phrase);

    int k = 0;
    for (size_t i = 0; i < strSz; ++i) {
        if (phrase[i] >= 'a' && phrase[i] <='z' || phrase[i] >= 'A' && phrase[i] <= 'Z') {
            ans[k++] = phrase[i];
        }
    }
    cout << ans;

    for (int i = 0; i < k; ++i) {
        ans[i] = tolower(ans[i]);
    }

    char aux[N_MAX];
    strcpy(aux, ans);

    rev(aux);
    if (!strcmp(ans, aux)) {
        cout << " DA\n";
    } else {
        cout << " NU\n";
    }
    return 0;
}


// PROBLEMA 2)
char* cuv[N_MAX / 2 + 1];
int main() {
    cin.getline(phrase, N_MAX);

    bool found = false;
    char* pch = strtok(phrase, " ");
    int k = 0;

    while (pch != NULL && !found) {
        size_t szStr = strlen(pch);
        for (size_t i = 0; i < szStr; ++i) {
            pch[i] = tolower(pch[i]);
        }

        for (int i = 0; i < k; i++) {
            if (!strcmp(pch, cuv[i]))
                found = true;
        }

        cuv[k++] = pch;
        pch = strtok(NULL, " ");
    }

    cout << (found ? "NU" : "DA");
    return 0;
}


// PROBLEMA 3)
void revToUpper(char* str, size_t sz) {
    for (size_t i = 0; i < sz / 2; ++i) {
        char aux = toupper(str[i]);
        str[i] = toupper(str[(sz - 1) - i]);
        str[(sz - 1) - i] = aux;
    }

    str[sz / 2] = toupper(str[sz / 2]);
}
int main() {
    cin.getline(phrase, N_MAX);

    char* pch = strtok(phrase, " ");
    char voc[] = "aeiou";

    while (pch != NULL) {
        if (strchr(voc, tolower(pch[0]))) {
            size_t szStr = strlen(pch);
            
            strcpy(ans, pch);
            revToUpper(ans, szStr);

            cout << ans << " ";
        }

        pch = strtok(NULL, " ");
    }

    return 0;
}


// PROBLEMA 4
const int N_MAX = 21;
int main()
{
    char a[N_MAX], b[N_MAX];
    cin.getline(a, N_MAX - 1);
    cin.getline(b, N_MAX - 1);

    // VAR CU POINTERI
    bool found = false;
    size_t szA = strlen(a);

    for (size_t i = 0; i < szA; i++) {
        if (strstr(b, a + i) == b) {
            cout << a + i << ' ';
            found = true;
        }
    }

    if (!found)
        cout << "nu exista";

    // VAR FARA POINTERI
    bool found = false;
    int szA = strlen(a), k = 0;

    // O(szA * szAux)
    char aux[N_MAX];
    for (int i = szA - 1; i >= 0; i--) {
        aux[k++] = a[i];

        bool status = true;
        int szAux = strlen(aux);
        for (int i = 0; i < szAux; i++) {
            if (aux[(szAux - 1) - i] != b[i]) {
                status = false;
                break;
            }
        }

        if (status) {
            for (int j = szAux - 1; j >= 0; j--) {
                cout << aux[j];
            }
            cout << " ";
            found = true;
        }
    }

    if (!found)
        cout << "nu exista";
    return 0;
}

// PROBLEMA 5
const int N_MAX = 21;
int main() {
    char cuv[3][N_MAX];
    char ans[3 * N_MAX];

    for (int i = 0; i < 3; ++i) {
        cin >> cuv[i];
    }

    int k = 0;
    for (int i = 0; i < 3; ++i) {
        size_t strSz = strlen(cuv[i]);

        strSz += (strSz % 2) ? 1 : 0;
        for (int j = 0; j < strSz / 2; ++j) {
            ans[k++] = cuv[i][j];
        }
    }

    cout << ans;
    return 0;
}
