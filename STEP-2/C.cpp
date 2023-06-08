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
const int mx = 1e10;

void solve() {
    int n,x,y;
    cin>>n>>x>>y;
    if(x>y) swap(x,y);

    auto f = [&](int t) {
        t-=x;
        return (n<=(1+t/x+t/y));
    };

    int l = x,r=mx;
    while(r-l>1) {
        int mid =(l+r)/2;
        if(f(mid)) r = mid;
        else l = mid+1;
    }
    if(f(l)) cout<<l<<"\n";
    else cout<<r<<"\n";
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int testcases=1;
    //cin>>testcases;
    while(testcases--) solve();
    return 0;
}