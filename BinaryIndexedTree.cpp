#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 1e5 + 5;
int BIT[MAXN];  // Binary Indexed Tree array
int A[MAXN];    // Original array
int n;          // Size of array

// Update BIT at index 'i' by adding 'val'
void update(int i, int val) {
    while (i <= n) {
        BIT[i] += val;
        i += i & -i;
    }
}

// Query prefix sum from 1 to i
int query(int i) {
    int sum = 0;
    while (i > 0) {
        sum += BIT[i];
        i -= i & -i;
    }
    return sum;
}

// Query sum from index l to r (inclusive)
int rangeQuery(int l, int r) {
    return query(r) - query(l - 1);
}

// Build BIT from original array A[1..n]
void buildBIT() {
    for (int i = 1; i <= n; ++i) {
        update(i, A[i]);
    }
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> A[i];
    }

    buildBIT();

    cout << "\nPrefix sum from 1 to 5: " << query(5) << endl;
    cout << "Sum from index 3 to 7: " << rangeQuery(3, 7) << endl;

    cout << "\nUpdating index 4 by adding 10\n";
    update(4, 10);

    cout << "New prefix sum from 1 to 5: " << query(5) << endl;
    cout << "New sum from index 3 to 7: " << rangeQuery(3, 7) << endl;

    return 0;
}

