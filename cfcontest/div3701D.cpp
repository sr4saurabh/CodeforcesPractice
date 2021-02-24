
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
    cin >> t;
    while(t--)
    {
        int n,m;
        cin >> n >> m;
        vector<ll> a(n+1,0);
        ll sum=0;
        map<ll,ll> mx;
        for(int i=1;i<=n;i++)
        {
            cin >> a[i];
            sum+=a[i];
            if(mx.find(sum)==mx.end()) mx[sum]=i;
        }
        int mn=n;
        for(auto it=mx.rbegin();it!=mx.rend();it++)
        {
            mn=min(mn,(int)it->second);
            it->second=mn;
        }
        ll z=(mx.rbegin()->first);
        while(m--)
        {
            ll x;
            cin >> x;
            if(sum<=0)
            {
                auto it=mx.lower_bound(x);
                if(it!=mx.end()) cout << (it->second)-1 << " ";
                else cout << "-1 ";
            }
            else
            {
                ll k=max(0ll,(x-z+sum-1)/sum);
                cout << k*n+(mx.lower_bound(x-k*sum)->second)-1 << " ";
            }
        }
        cout << "\n";
    }
        
          






return 0;
} 