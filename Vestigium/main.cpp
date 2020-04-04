#include <bits/stdc++.h>

using namespace std;

int main() {
    int t, n, tr = 0, r = 0, c = 0, k = 0;
    cin >> t;
    bitset<100> numr[100];
    bitset<100> numc[100];
    for (int i = 0; i < t; ++i) {
        r = 0;
        c = 0;
        tr =  0;
        cin >> n;
        for (int j = 0; j < n; ++j) {
            for (int l = 0; l < n; ++l) {
                cin >> k;
                if (l == j) tr += k;
                numr[j].flip(k-1);
                numc[l].flip(k-1);

            }


        }
        for (int m = 0; m < n; ++m) {
            if (numr[m].count() < n) r++;
            if (numc[m].count() < n) c++;
            numc[m].reset();
            numr[m].reset();

        }
        cout << "Case #" << i+1 << ": " << tr << " " << r << " " << c << endl;
    }
    return 0;
}

