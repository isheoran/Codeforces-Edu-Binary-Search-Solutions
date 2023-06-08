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
    cin>>n>>k;
    vector<int>a(n);
    input(a);

    auto b_search = [&](int x) {
        int l = 0,r=n-1;
        while(r-l>1) {
            int mid = (l+r)/2;
            if(a[mid]>x) r = mid-1;
            else l = mid;
        }
        if(a[r]<=x) return r+1;
        if(a[l]<=x) return l+1;
        return 0LL;
    };

    while(k--) {
        int x;
        cin>>x;
        cout<<b_search(x)<<"\n";
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