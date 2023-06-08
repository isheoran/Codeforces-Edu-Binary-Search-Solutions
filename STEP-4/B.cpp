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
const double eps = 1e-5;

void solve() {
    int n,m;
    cin>>n>>m;
    vector<vector<pair<int,int>>>adj(n+1);
    vector<int>parent;
    while(m--) {
        int a,b,c;
        cin>>a>>b>>c;
        adj[a].push_back({b,c});
    }

    auto f = [&](double avg) {
        parent.assign(n+1,-1);
        vector<double>d(n+1,inf);
        d[1] = 0;
        for(int i=1;i<=n;i++) {
            for(auto u:adj[i]) {
                if(d[u.first]>d[i]+u.second-avg) {
                    d[u.first] = d[i] + u.second - avg;
                    parent[u.first] = i;
                }
            }
        }
        return d[n]<=0;
    };

    double l = 0,r=102;
    while(r-l>eps) {
        double mid = (l+r)/2;
        if(f(mid)) r = mid;
        else l = mid;
    }

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