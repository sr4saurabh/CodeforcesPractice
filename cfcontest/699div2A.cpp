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

       int t = 1;
       cin>>t;

       while(t--)
       {
            int px , py;
            cin>>px>>py;

            string st;
            cin>>st;

            int u = 0 , d = 0, l = 0 ,r = 0;
            int cx = 0 , cy = 0;
            for(char k : st){
                if(k == 'L')
                    l++ , cx--;
                else if(k == 'R')
                    r++,cx++;
                else
                    if(k == 'D')
                    d++,cy--;
                else
                    u++,cy++;
            }

            if(cx == px && cy == py)
            {
                cout<<"YES\n";
                continue;
            }
            int b = 0;
            if(cx >= px && r >= cx - px && cy >= py && u >= cy - py)
                b = 1;
            if(cx <= px && l >= px - cx && cy >= py && u >= cy - py)
                b = 1;
            if(cx >= px && r >= cx - px && cy <= py && d >= py - cy)
                b = 1;
            if(cx <= px && l >= px - cx && cy <= py && d >= py - cy)
                b = 1;
          

            if(b == 1)
                cout<<"YES\n";
            else
                cout<<"NO\n";
       }

       

          






return 0;
} 