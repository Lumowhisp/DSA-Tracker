#include <bits/stdc++.h>
using namespace std;

int main() {
    #ifndef ONLINE_JUDGE
    if (freopen("testcase.txt", "r", stdin) == nullptr) {
        cerr << "File not found!\n";
        return 1;
    }
    cout << "File opened successfully\n";
    #endif

    string s, p;
    int tc = 1;
    while (cin >> s >> p) {
        int expectedCount;
        cin >> expectedCount;
        vector<int> expected(expectedCount);
        for (int k = 0; k < expectedCount; k++) {
            cin >> expected[k];
        }
        // Your solution here
        if (p.size() > s.size()) {
            continue;
        }
        vector<int> ans;
        unordered_map<char, int> mp;
        for (auto it : p) {
            mp[it]++;
        }
        int count = mp.size();
        int i = 0;
        int j = 0;
        while (j < p.size()) {
            if (mp.find(s[j]) != mp.end()) {
                mp[s[j]]--;
                if (mp[s[j]] == 0) {
                    count--;
                }
            }
            // window Hit
            if (j == p.size() - 1) {
                if (count == 0) {
                    ans.push_back(i);
                }
                if (mp.find(s[i]) != mp.end()) {
                    if (mp[s[i]] == 0) {
                        count++;
                    }
                    mp[s[i]]++;
                }
                i++;
            }
            j++;
        }
        // continue window throughout the string s
        while (j < s.size()) {
            if (mp.find(s[j]) != mp.end()) {
                mp[s[j]]--;
                if (mp[s[j]] == 0) {
                    count--;
                }
            }
            j++;
            if (count == 0) {
                ans.push_back(i);
            }
            if (mp.find(s[i]) != mp.end()) {
                if (mp[s[i]] == 0) {
                    count++;
                }
                mp[s[i]]++;
            }
            i++;
        }
        bool ok = (ans == expected);
        cout << "Test " << tc++ << ": " << (ok ? "PASS" : "FAIL") << '\n';
        if (!ok) {
            cout << "Expected: ";
            for (int x : expected) cout << x << ' ';
            cout << "\nGot:      ";
            for (int x : ans) cout << x << ' ';
            cout << "\n";
        }
    }
    return 0;
}
