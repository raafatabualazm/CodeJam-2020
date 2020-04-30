#include <bits/stdc++.h>

using namespace std;

int main() {
    int x, y, t, n;
    string output = "";
    vector<pair<pair<int, int>, int>> time;
    vector<pair<pair<int, int>, char>> time2;
    map<pair<int, int>, char> mp;
    pair<int, int> c;
    pair<int, int> b;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        b.first = -1;
        b.second = -1;
        cin >> n;
        output = "";
        time.clear();
        time2.clear();
        for (int j = 0; j < n; ++j) {
            cin >> x >> y;
            time.push_back(make_pair(make_pair(x, y), j));
            time2.push_back(make_pair(make_pair(x, y), 'k'));
        }
        sort(time.begin(), time.end());
        c = time[0].first;
        time2[time[0].second].second = 'C';
        for (int k = 1; k < n; ++k) {
            if (time[k].first.first >= c.second)
            {
                c = time[k].first;
                time2[time[k].second].second = 'C';
            } else if (time[k].first.first >= b.second)
            {
                b = time[k].first;
                time2[time[k].second].second = 'J';
            }
            else {
                output = "IMPOSSIBLE";
                break;
            }
        }
        for (int l = 0; l < n; ++l) {
            if (output == "IMPOSSIBLE") break;
            else {
                output +=  time2[l].second;
            }
        }
        cout << "Case #" << i+1 << ": " << output << endl;

    }
    return 0;
}
