#include <iostream>
#include <vector>
using namespace std;


void quickSort(vector<int> &a, int l, int r);
void FindIntegerPairs(vector<int> a, int l, int r, int value);
int main() {
    vector<int> a = {1, 2, 2, 1, 1};
    int len = a.size();
    quickSort(a, 0, len - 1);

    //    for (int i = 0; i < len; ++i) {
    //        cout << a[i] << ", ";
    //    }
    //    cout << endl;
    FindIntegerPairs(a, 0, len - 1, 3);
    return 0;
}
void FindIntegerPairs(vector<int> a, int l, int r, int value) {
    while (l < r) {
        if (a[l] + a[r] == value) {
            cout << "pair is " << l << " and " <<r << endl;
            //            cout << "pair is" << a[l];
            l++;
            r--;
        } else if (a[l] + a[r] > value) {
            r--;
        } else {
            l++;
        }
    }
}
void quickSort(vector<int> &a, int l, int r) {
    if (l < r) {
        int i = l, j = r, x = a[l];
        while (i < j) {
            while (i < j && a[j] >= x) {
                j--;
            }
            if (i < j) {
                a[i++] = a[j];
            }
            while (i < j && a[i] < x) {
                i++;
            }
            if (i < j) {
                a[j--] = a[i];
            }
        }
        a[i] = x;
        quickSort(a, l, i - 1);
        quickSort(a, i + 1, r);
    }
}
