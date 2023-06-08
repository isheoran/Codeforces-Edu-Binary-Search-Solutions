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
    vector<int>a(n);
    input(a);

    auto f = [&](int x) {
        int cnt = 1,cur=0;
        for(int i=1;i<n;i++) {
            if(cur+a[i]-a[i-1]>=x) {
                cnt++;
                cur = 0;
            }
            else {
                cur += a[i]-a[i-1];
            }
        }
        return cnt>=k;
    };

    int l=0,r=mod;
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