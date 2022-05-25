#include <iostream>
#include <vector>

using namespace std;

void insertion_sort(vector<int> &arr);
void print_vec(const vector<int> &arr);
void insertion_sort_optimzie(vector<int> &arr);

int main () {
    vector<int> a{31, 41, 59, 26, 41, 58};

    print_vec(a);
    insertion_sort(a);
    print_vec(a);
    insertion_sort_optimzie(a);
    print_vec(a);

    return 0;
}


void insertion_sort(vector<int> &arr) {
    for (int i = 0; i < arr.size(); i++) {
        for (int j = i + 1; j < arr.size(); j++) {
            if (arr[j] > arr[i]) {
                swap(arr[i], arr[j]);
            }
        }
    }
}

void insertion_sort_optimzie(vector<int> &arr) {
    for (int i = 0; i < arr.size(); i++) {
        int biggest = i;
        for (int j = i + 1; j < arr.size(); j++) {
            if (arr[j] < arr[biggest]) {
                biggest = j;
            }
        }
        swap(arr[i], arr[biggest]);
    }
}

void print_vec(const vector<int> &arr) {
    for (auto c: arr) {
        cout << c << " ";
    }
    cout << endl;
}