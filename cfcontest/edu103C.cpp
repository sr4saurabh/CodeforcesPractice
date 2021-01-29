    /*--ILRS-- gonna hit 1600 someday---

    His palms are sweaty,
           knees weak, arms are heavy
    There's vomit on his sweater already,
             mom's spaghetti
    He's nervous,
             but on the surface he looks calm and ready
    To drop bombs,
             but he keeps on forgettin'
    What he wrote down,
             the whole crowd goes so loud
    He opens his mouth,
             but the words won't come out
    He's chokin',
             how, everybody's jokin' now
    The clocks run out,
             times up, over, blaow
    Snap back to reality,
             ope there goes gravity
    Ope, there goes Rabbit,
             he choked

    He's so mad,
             but he won't give up that easy? No
    He won't have it,
             he knows his whole back's to these ropes
    It don't matter,
             he's dope, he knows that, but he's broke
    He's so stagnant,
             he knows, when he goes back to this mobile home, that's when it's
    Back to the lab again
             yo, this whole rhapsody
    Better go capture this moment and hope it don't pass him

    You better lose yourself in the music, the moment
    You own it, you better never let it go
    You only get one shot, do not miss your chance to blow
    This opportunity comes once in a lifetime 

    */
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

    void solve()
    {
        int n;
        cin>>n;

        ll arr[n+1],brr[n+1],crr[n+1];
        for(int i = 1; i <= n; i++)
            cin>>arr[i];
        for(int i = 1; i <= n; i++)
            cin>>brr[i];
        for(int i = 1; i <= n; i++)
            cin>>crr[i];
        
        ll dp[n+1] , dpend[n+1];
        ll ans = 0;
        dp[1] = 0; dpend[1] = 0;
        dp[2] = max(brr[2] , crr[2]) - min(brr[2] , crr[2]) + 2;
        dpend[2] = dp[2] + arr[2] - 1;
        ans = dpend[2];
        if(arr[2] == 1 && brr[2] == crr[2])
            ans = 0 , dp[2] = 0 , dpend[2] = 0;
        


        for(int i = 3; i <= n; i++)
        {
            if(brr[i] == crr[i] && arr[i] == 1)
            {
                dp[i] = 0;
                dpend[i] = 0;
            }
            else
            if(brr[i] > crr[i])
            {
                //crooss is forming
                ll less = crr[i];
                ll more = brr[i];

                dp[i] = max(dp[i-1] + less + 1 + arr[i-1] - more,2 + more - less);
                dpend[i] = arr[i]-1 + dp[i];
            }
            else
            if(brr[i] == crr[i])
            {
                //ended at last
                dp[i] = 2;
                dpend[i] = dp[i] + arr[i] - 1;
            }
            else
            {
                //easily going
                dp[i] = max(dp[i-1] + brr[i] + arr[i-1] - crr[i] + 1,2 + crr[i] - brr[i]);
                dpend[i] = dp[i] + arr[i] - 1;
            }

            ans = max(ans , dpend[i]);
        }
        cout<<ans<<'\n';
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

    	//Never let somebody tell you - you are weak! You are as strong as anyone be,
           // u just need consistency and will power to change!

           int t;
           cin>>t;
           while(t--)
            solve();
           

              






    return 0;
    } 