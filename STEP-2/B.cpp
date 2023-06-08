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
const double eps = 1e-7;

void solve() {
    int n,k;
    cin>>n>>k;
    vector<double>a(n);
    input(a);

    auto f = [&](double l) {
        int cnt = 0;
        for(auto u:a) cnt += u/l;
        return cnt >= k;
    };

    double l  =0,r=1e7+1;
    while(r-l>eps) {
        double mid = (l+r)/2;
        if(f(mid)) l = mid;
        else r = mid;
    }

    cout<<fixed<<setprecision(15)<<l<<"\n";
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int testcases=1;
    //cin>>testcases;
    while(testcases--) solve();
    return 0;
}