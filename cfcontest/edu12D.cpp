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
int pr[2000001];
ll modInverse(ll a,ll m){ll m0=m;ll y=0,x=1;if(m == 1)return 0;while(a> 1){ll q=a/m;ll t=m;m=a%m,a=t;t=y;y=x-q*y;x=t;}if(x<0)x+=m0;return x;}
ll powmod(ll a,ll m)
{if(m==0)return 1;if(m==1)return a%mod;if(m%2==0){ll b=powmod(a,m/2);b=(b*b)%mod;return b;}
ll bb=powmod(a,m/2);bb=((bb*bb)%mod*a)%mod;return bb;}
ll factmod(ll n){ll v=1;for(int i=1;i<=n;i++){v=(v*i)%mod;}return v;}
void seive(){for(int i=0;i<=2000000;i++)pr[i]=1;for(int i=2;i*i<=2000000;i++){if(pr[i]==1)
{for(int p=i*i;p<=2000000;p+=i)pr[p]=0;}}for(int i=2;i<2000000;i++)if(pr[i]==1)primes.pb(i);}
 int mpp[2000001]={0};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    #ifndef ONLINE_JUDGE
       freopen ("INPUT.txt" , "r" , stdin);
       freopen ("OUTPUT.txt", "w" , stdout);
    #endif

       seive();
    
       
       int n;cin>>n;
      
       int arr[n+1];
       arr[0] = 0;
       for(int i = 1; i <= n; i++){
        cin>>arr[i];
        mpp[arr[i]]++;
       
    }
    if(mpp[1] && mpp[2])
    {
        cout<<mpp[1]+1<<'\n';
        cout<<2<<' ';
        for(int i = 0; i < mpp[1]; i++)
            cout<<1<<' ';
        return 0;
    }
    if(mpp[1])
    {
        for(int i = 1; i < primes.size(); i++)
        {
            if(mpp[primes[i]-1])
            {
                cout<<mpp[1]+1<<'\n';
                for(int i = 0; i < mpp[1]; i++)
                    cout<<1<<' ';
                    cout<<primes[i]-1;
                    return 0;
            }
        }
    }
    if(mpp[1] > 1)
    {
        cout<<mpp[1]<<'\n';
        for(int i = 0; i < mpp[1]; i++)
                    cout<<1<<' ';
                return 0;

    }


        int a1 = -1 , a2 = -1 , ma = 0;
        for(int i = 1; i <= n; i++)
        {
            for(int j = i+1; j <= n; j++)
            {
                int val = arr[i] + arr[j];
                int l = 0 , r = primes.size()-1;
                bool b = false;
                while(l <= r)
                {
                    int m = (l + r)/2;
                    if(primes[m] == val)
                    {
                        b = true;
                        break;
                    }
                    else
                    if(primes[m] > val)
                        r = m - 1;
                    else
                        l = m + 1;

                }

                if(b){
                    cout<<2<<'\n';
                    cout<<arr[i]<<' '<<arr[j];
                    return 0;
                }
            }
        }


        cout<<1<<'\n';
        cout<<arr[1];


















return 0;
}
