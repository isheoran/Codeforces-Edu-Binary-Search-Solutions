#include <bits/stdc++.h>
using namespace std;
#define int long long
#define mod  (int)(1e9+7)
#define inf  (int)(1e18)
#define sz(s) (int)s.size()
#define all(v) (v).begin(),(v).end()
#define fill(v,p) memset(v,p,sizeof(v))
#define input(vec) for (auto &el : vec) cin >> el;
#define print(vec) for (auto &el : vec) cout << el << " "; cout << "\n";

void solve() {
    int n,k;
    cin>>n;
    vector<int>a(n);
    input(a);
    sort(all(a));

    auto b_search = [&](int l,int r) {
        int ans = upper_bound(all(a),r) - lower_bound(all(a),l);
        return ans;
    };

    cin>>k;
    while(k--) {
        int l,r;
        cin>>l>>r;
        cout<<b_search(l,r)<<" ";
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int testcases=1;
    //cin>>testcases;
    while(testcases--) solve();
    return 0;
}