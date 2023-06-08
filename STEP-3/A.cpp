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
const double eps = 1e-6;

void solve() {
    int n;
    cin>>n;
    vector<pair<int,int>>pr;
    for(int i=0;i<n;i++) {
        int a,b;
        cin>>a>>b;
        pr.push_back({a,b});
    }
    sort(all(pr));

    auto f = [&](double t) {
        double l = pr[0].first + t*pr[0].second;
        for(auto u:pr) {
            if(l>u.first) l = min(l,u.first+u.second*t);
            else if(u.first-u.second*t>l) return false;
        }
        return true;
    };

    double l = 0,r=2e9+10;
    while(r-l>eps) {
        double mid = (l+r)/2;
        if(f(mid)) r=mid;
        else l = mid+eps;
    }
    cout<<fixed<<setprecision(10)<<l<<"\n";
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int testcases=1;
    //cin>>testcases;
    while(testcases--) solve();
    return 0;
}