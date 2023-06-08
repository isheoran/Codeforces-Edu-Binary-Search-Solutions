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
    int n,m,d;
    cin>>n>>m>>d;
    vector<vector<pair<int,int>>>adj(n+1);
    vector<int>parent;
    while(m--) {
        int a,b,c;
        cin>>a>>b>>c;
        adj[a].push_back({b,c});
    }

    auto f = [&](int x) {
        parent.assign(n+1,-1);
        vector<int>num(n+1,inf);
        num[1] = 0;
        for(int i=1;i<=n;i++) {
            for(auto u:adj[i]) {
                if(u.second<=x and num[u.first]>num[i]+1) {
                    num[u.first] = num[i] + 1;
                    parent[u.first] = i;
                }
            }
        }
        return num[n]<=d;
    };

    int l = 0,r=mod;
    while(r-l>1) {
        int mid = (l+r)/2;
        if(f(mid)) r = mid;
        else l = mid+1;
    }
    if(!f(r)) {
        cout<<"-1\n";
        return;
    }
    if(!f(l)) f(r);

    vector<int>ans = {n};
    while(parent[n]!=-1) {
        ans.push_back(parent[n]);
        n = parent[n];
    }
    cout<<sz(ans)-1<<"\n";
    reverse(all(ans));
    print(ans);
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int testcases=1;
    //cin>>testcases;
    while(testcases--) solve();
    return 0;
}