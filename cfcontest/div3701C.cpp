
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
int bs_lower_bound(vll &f, ll x) {
    int l = 1;
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
            int n,m;
            cin>>n>>m;
            int arr[n+1],brr[m+1];
            for(int i = 1; i <= n; i++)
                cin>>arr[i];

            for(int j = 1;j <= m; j++)
                cin>>brr[j];

            ll ma = arr[1];
            ll val = arr[1];
            vll pref(n+1,0);
            pref[1] = val;
            for(int i = 2; i <= n; i++)
            {
                val += arr[i];
                ma = max(ma,val);
                pref[i] = max(pref[i-1],val);
            }
            
            for(int i = 1;i <= m; i++)
            {
                if(brr[i] > ma && val <= 0)
                {
                    cout<<-1<<' ';
                    
                }
                else
                    if(val == 0 && brr[i] <= ma)
                    {
                        ll curr = 0; ll ans = 0;
                        /*for(int j = 1; j <= n; j++)
                        {
                            curr += arr[j];
                            if(curr >= brr[i])
                            {
                                ans+=j-1;
                                break;
                            }
                        }*/
                        ans = bs_lower_bound(pref,brr[i]);
                        cout<<ans-1<<' ';
                    }
                else
                {
                    ll t = 0;
                    ll d = max(0ll, brr[i]-ma);

                    t = d / val; // times it will rotate

                    if(t * val + ma < brr[i])
                        t++;

                    ll remm = brr[i] - t*val;

                    ll curr = 0;
                    ll ans = t * n;
                    /*for(int j = 1; j <= n; j++)
                    {
                        curr += arr[j];
                        if(curr >= remm)
                        {
                            ans+=j-1;
                            break;
                        }
                    }*/
                    ans = ans + bs_lower_bound(pref,remm);
                    cout<<ans-1<<' ';

                }
                
            }
            cout<<'\n';
       }
       

          






return 0;
} 