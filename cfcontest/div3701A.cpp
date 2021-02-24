
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

   
      
       

        int  t = 1;
        cin>>t;
        while(t--)
        {
            int n;
            cin>>n;
            
            vpl arr(n);
            for(int i = 0; i < n; i++){
                cin>>arr[i].fi;
                arr[i].se = i;
            }

            sort(arr.begin(),arr.end());

            vll pref(n,0);
            pref[0] = arr[0].first;

            bool win[n];
            //win[n-1] = 1;
            for(int i = 1; i < n; i++)
                pref[i] += pref[i-1] + arr[i].first;

            for(int i = 0; i < n-1; i++)
            {
                if(pref[i] < arr[i+1].first)
                    win[i] = 0;
                else
                    win[i] = 1;
            }
            win[n-1] = 1;
            int ff = -1;
            for(int j = n-1; j >= 1; j--)
            {
                if(win[j] == 0)
                {
                    ff = j;
                    break;
                }
            }
            
            //for(int i : pref)
              //  cout<<i<<' ';
            //cout<<'\n';
            for(int j = ff; j >= 0; j--)
                win[j] = 0;

            int c = 0;
            vii ansr;
            for(int i = 0; i < n; i++)
            {
                if(win[i])
                    ansr.pb(arr[i].se+1);
            }   
            sort(ansr.begin(),ansr.end());
           /* cout<<c<<'\n';
            for(int i  = 0;i < n; i++)
            {
                if(win[i])
                    cout<<i+1<<' ';
            }*/
            cout<<ansr.size()<<'\n';
            for(int i : ansr)
                cout<<i<<' ';
            cout<<'\n';
        }
            
            
        
       

          






return 0;
} 