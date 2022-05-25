#include <iostream>
#include <vector>

using namespace std;

void mergesort(vector<int> &v, int p, int r);
void merge(vector<int> &v, int p, int q, int r);
void print_vec(const vector<int> &arr);

int main() {
    vector<int> v{3, 41, 52, 26, 38, 57, 9, 49 };

    mergesort(v, 0, v.size() - 1);
    print_vec(v);

    return 0;
}

void mergesort(vector<int> &v, int p, int r) {\
    int q;
    if (p < r) {
        q = (p + r) / 2;
        mergesort(v, p, q);
        mergesort(v, q + 1, r);
        merge(v, p, q, r);
    }
}

void merge(vector<int> &v, int p, int q, int r) {
    vector<int> L, R;
    for (int i = p; i < q + 1; i++) {
        L.push_back(v[i]);
    }
    print_vec(L);
    for (int i = q + 1; i < r + 1; i++) {
        R.push_back(v[i]);
    }
    print_vec(R);

    int i = 0; int j = 0;
    int k = p;
    while (i < L.size() && j < R.size()) {
        if (L[i] < R[j]) {
            v[k] = L[i];
            ++i;
        } else {
            v[k] = R[j];
            ++j;
        }
        ++k;
    }
    if (j == R.size()) {
        while (k < r + 1) {
            v[k++] = L[i++];
        }
    }
    if (i == L.size()) {
        while (k < r + 1) {
            v[k++] = R[j++];
        }
    }
}

void print_vec(const vector<int> &arr) {
    for (auto c: arr) {
        cout << c << " ";
    }
    cout << endl;
}