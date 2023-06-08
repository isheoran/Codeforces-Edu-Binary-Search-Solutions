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

    auto f = [&](int x) {
        int cnt = 0;
        for(int i=1;i<=n;i++) {
            cnt += min(n,x/i);
        }
        return cnt>=k;
    };

    int l = 0,r=1e12;

    while(r-l>1) {
        int mid = (l+r)/2;
        if(f(mid)) r = mid;
        else l = mid+1;
    }
    if(f(l)) r = l;
    cout<<r<<"\n";
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int testcases=1;
    //cin>>testcases;
    while(testcases--) solve();
    return 0;
}