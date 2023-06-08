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
    int n,d;
    cin>>n>>d;
    vector<int>a(n);
    input(a);

    auto f = [&](double x) {
        vector<double>sm(n+1);
        for(int i=1;i<=n;i++) {
            sm[i] = sm[i-1] + a[i-1] - x;
        }
        double pre = sm[0];
        int idx = 0;
        for(int i=d;i<=n;i++) {
            if(sm[i]>=pre) return make_pair(i,idx+1LL);
            if(sm[i-d+1] < pre) {
                pre = sm[i-d+1];
                idx = i-d+1;
            }
        }
        return make_pair(0LL,0LL);
    };

    double l = 0,r=100;
    int cnt=0;
    while(r-l>eps) {
        double mid = (l+r)/2;
        if(f(mid).first) l = mid;
        else r = mid;
        cnt++;
    }

    cout<<f(l).second<<" "<<f(l).first<<"\n";
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int testcases=1;
    //cin>>testcases;
    while(testcases--) solve();
    return 0;
}