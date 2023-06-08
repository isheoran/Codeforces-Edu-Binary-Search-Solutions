#include <bits/stdc++.h>
using namespace std;
#define enl '\n'
#define int long long
#define sz(s) (int)s.size()
#define all(v) (v).begin(),(v).end()
#define input(vec) for (auto &el : vec) cin >> el;
#define print(vec) for (auto &el : vec) cout << el << " "; cout << "\n";

const long long mod = 1e9+7;
const long long inf = 1e18;

void solve() {
    int w,h,n;
    cin>>w>>h>>n;

    auto f = [&](int x) {
        int row = x/h;
        int col = x/w;
        if(!row or !col) return false;
        if(row > inf/col) return true;
        return row*col >= n;
    };

    int l = 0,r = inf;
    while(r-l>0) {
        int mid  = (l+r)/2;
        if(f(mid)) r = mid;
        else l = mid+1;
    }
    cout<<l<<enl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int testcases = 1;
    //cin>>testcases;
    while(testcases--) solve();
    return 0;
}