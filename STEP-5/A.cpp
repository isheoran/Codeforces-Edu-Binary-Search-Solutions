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
const int nmm = 3e9;

void solve() {
    int n,k;
    cin>>n>>k;
    k++;
    vector<pair<int,int>>pr;
    for(int i=0;i<n;i++) {
        int l,r;
        cin>>l>>r;
        pr.push_back({l,r});
    }

    auto f = [&](int x) {
        int cnt = 0;
        for(auto u:pr) {
            if(x>=u.first) {
                cnt += min(x,u.second) - u.first + 1;
            }
        }
        return cnt >= k;
    };

    int l = -nmm,r=nmm;
    while(r-l>1) {
        int mid = (l+r)/2;
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