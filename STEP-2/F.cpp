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
    string t,p;
    cin>>t>>p;
    int n=sz(t);
    vector<int>a(n);
    input(a);

    auto f = [&](int x) {
        vector<bool>dlt(n);
        for(int i=0;i<x;i++) {
            dlt[a[i]-1] = true;
        }
        int i = 0;
        for(auto u:p) {
            while(i<n and (dlt[i] or t[i]!=u)) i++;
            if(i==n) return false;
            i++;
        }
        return true;
    };

    int l = 0,r=n;
    while(r-l>1) {
        int mid = (l+r)/2;
        if(f(mid)) l=mid;
        else r=mid-1;
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