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
    cin>>k>>n;
    vector<int>a(n);
    input(a);

    auto f = [&](int x) {
        int layer = 0,l = 0;
        for(auto u:a) {
            if(u>=x) layer++;
            else {
                if(l+u>=x) {
                    layer++;
                    l = u-x+l;
                }
                else {
                    l += u;
                }
            }
        }
        return layer>=k;
    };
    int l = 0,r = 1e14;
    while(r-l>1) {
        int mid = (l+r)/2;
        if(f(mid)) l = mid;
        else r = mid-1;
    }
    if(f(r)) cout<<r<<"\n";
    else cout<<l<<"\n";
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int testcases=1;
    //cin>>testcases;
    while(testcases--) solve();
    return 0;
}