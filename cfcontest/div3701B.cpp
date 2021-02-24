
#include <bits/stdc++.h>
using namespace std; 
typedef long long int ll;
#define pb push_back 
#define popb pop_back
#define mp make_pair
#define ve vector
#define vii vector < int >
#define vll vector < ll > 
#define pii pair < int , int >
#define pll pair < ll , ll >
#define vpl vector < pll >
#define fi first
#define sz size 
#define len length 
#define se second 
//const ll mod=998244353;
const ll mod = 1000000000+7;
const ll N=10000000+6;
#define M_PI           3.14159265358979323846
//--------------------------------------------



//--------------------------------------------
int bs_lower_bound(vii &f, int x) {
    int l = 0;
    int n = f.size();
    int h = f.size(); // Not n - 1
    while (l < h) {
        int mid =  l + (h - l) / 2;
        if (x <= f[mid]) {
            h = mid;
        } else {
            l = mid + 1;
        }
    }
    return l;
}




//============================================
int main() {
    ios::sync_with_stdio(false);
     cin.tie(0);
     cout.tie(0);
    #ifndef ONLINE_JUDGE
       freopen ("INPUT.txt" , "r" , stdin);
       freopen ("OUTPUT.txt", "w" , stdout);
    #endif

   


        int t;
        cin>>t;
        while(t--)
        {   
            int n;
            cin>>n;
            map<int,int> mp;
            for(int i = 0;i < n; i++)
            {
                int v;
                cin>>v;
                mp[v]++;
            }

            vii f;
            f.pb(0);
            for(auto it : mp)
                f.push_back(it.se);

            sort(f.begin(),f.end());

            int nn = f.size();
            vii pref(nn+1,0);

            for(int i = 1 ; i <  nn; i++)
                pref[i] = pref[i-1] + f[i];
           // for(int i = 1; i < nn; i++)
              //  cout<<pref[i]<<' ';
           // cout<<'\n';
            ll mi = 1e18;
            for(int i = 1; i < nn; i++)
            {
                ll in = bs_lower_bound(f,f[i]);
                ll val = pref[in-1];

                ll ahsum = pref[nn-1] - pref[i];
                ll sbe = f[i]*(nn-i -1);
                //cout<<ahsum<<" "<<sbe<<'\n';
                val = val + ahsum - sbe;

                mi = min(val,mi);
            }

            cout<<mi<<'\n';

            
        }

          






return 0;
} 