/*--ILRS-- sr4saurabh  */
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
vector<int> primes;
ll modInverse(ll a,ll m){ll m0=m;ll y=0,x=1;if(m == 1)return 0;while(a> 1){ll q=a/m;ll t=m;m=a%m,a=t;t=y;y=x-q*y;x=t;}if(x<0)x+=m0;return x;}
ll powmod(ll a,ll m)
{if(m==0)return 1;if(m==1)return a%mod;if(m%2==0){ll b=powmod(a,m/2);b=(b*b)%mod;return b;}
ll bb=powmod(a,m/2);bb=((bb*bb)%mod*a)%mod;return bb;}
ll factmod(ll n){ll v=1;for(int i=1;i<=n;i++){v=(v*i)%mod;}return v;}
void seive(){int pr[200001];for(int i=0;i<=200000;i++)pr[i]=1;for(int i=2;i*i<=200000;i++){if(pr[i]==1)
{for(int p=i*i;p<=200000;p+=i)pr[p]=0;}}for(int i=2;i<200000;i++)if(pr[i]==1)primes.pb(i);}

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
            int n , k ;
            cin>>n>>k;

            ll arr[n+1];
            map<ll,ll> mp;
            for(int i = 1; i <= n; i++){
                cin>>arr[i];
                mp[arr[i]]++;
            }

            sort(arr+1,arr+n+1);

            if(n == k)
            {
                cout<<1<<'\n';
                continue;
            }

            //---------------less than k

            if(arr[n-k] != arr[n-k+1])
            {
                cout<<1<<'\n';
                continue;
            }
            else
            {
                ll count = 0;
                for(int j = n - k + 1; j <= n; j++)
                    if(arr[j] == arr[n-k+1])
                        count++;
                    else
                        break;

                ll tot = mp[arr[n-k+1]];

                //find totCcount;
                ll num = factmod(tot);
                ll den1 = factmod(count);
                ll den2 = factmod(tot - count);
                ll den = (den1*den2)%mod;
                den = modInverse(den,mod);
                ll ans = (num * den)%mod;
                cout<<ans<<'\n';
                
            }

       }
          














return 0;
}
