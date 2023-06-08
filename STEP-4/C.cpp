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
const double eps = 1e-9;

void solve() {
    int n,k;
    cin>>n>>k;
    vector<pair<int,int>>pr;
    for(int i=0;i<n;i++) {
        int a,b;
        cin>>a>>b;
        pr.push_back({a,b});
    }

    auto val = [&](double a,double b,double x) {
        return (a-x*b);
    };

    auto f = [&](double x) {
        vector<double>v;
        for(auto u:pr) {
            v.push_back(val(u.first,u.second,x));
        }
        sort(all(v),[&](auto u,auto v) {
            return u > v;
        });
        double res = 0;
        for(int i=0;i<k;i++) res += v[i];
        return res>=0;
    };

    double l = 0,r=1e12;
    while(r-l>eps) {
        double mid = (l+r)/2;
        if(f(mid)) l = mid;
        else r = mid;
    }

    cout<<fixed<<setprecision(10)<<r<<"\n";
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int testcases=1;
    //cin>>testcases;
    while(testcases--) solve();
    return 0;
}