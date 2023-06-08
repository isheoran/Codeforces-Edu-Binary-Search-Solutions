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
    int m,n,t,z,y;
    cin>>m>>n;
    vector<tuple<int,int,int>>tup;
    for(int i=0;i<n;i++) {
        cin>>t>>z>>y;
        tup.push_back({t,z,y});
    }

    auto f = [&](int x) {
        int cnt = 0;
        for(auto u:tup) {
            tie(t,z,y) = u;
            cnt += z*(x/(z*t+y));
            if((x%(z*t+y))>z*t) cnt += z;
            else cnt += (x%(z*t+y))/t;
        }
        return cnt >= m;
    };

    int l = 0,r=1e8;
    while(r-l>1) {
        int mid = (l+r)/2;
        if(f(mid)) r = mid;
        else l = mid+1;
    }
    if(f(l)) r = l;

    cout<<r<<"\n";
    for(auto u:tup) {
        tie(t,z,y) = u;
        int cnt = 0;
        cnt += z*(r/(z*t+y));
        if(r%(z*t+y)>z*t) cnt += z;
        else cnt += (r%(z*t+y))/t;
        if(cnt>m) {
            cout<<m<<" ";
            m = 0;
            continue;
        }
        cout<<cnt<<" ";
        m -= cnt;
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