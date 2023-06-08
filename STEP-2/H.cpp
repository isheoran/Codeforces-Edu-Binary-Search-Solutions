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
    string S;
    cin>>S;
    vector<int>v(7);
    input(v);
    int b=0,s=0,c=0;
    for(auto u:S) {
        if(u=='B') b++;
        else if(u=='S') s++;
        else c++;
    }

    auto f = [&](int x) {
        int price = (b*x-v[0]<0 ? 0:b*x-v[0])*v[3]+(s*x-v[1]<0 ? 0:s*x-v[1])*v[4]+(c*x-v[2]<0 ? 0:c*x-v[2])*v[5];
        return price<=v[6];
    };

    int l = 0,r=1e13;
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