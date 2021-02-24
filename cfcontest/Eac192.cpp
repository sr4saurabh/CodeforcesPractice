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
int n,m,s,d;
vector<pair<ll,pll>> adj[100004];
ll dist[100010];
//--------------------------------------------
void dijkstra()
{
  ll source = s;
  int visd[100040]={0};
  multiset<pll> s;
  s.insert({0ll,source});
  for(int i = 1; i <= n ;i++)
  {
    if(i==source)
      dist[source] = 0;
    else
      dist[i] = 1e18;
  }
  while(!s.empty())
  {
    pll p = *s.begin();
    s.erase(s.begin());

    ll x = p.se; ll w = p.fi;
    if(visd[x])
      continue;
    visd[x] = true;

    for(pair<ll,pll> u : adj[x])
    {
      ll edge = u.fi;
      ll weight = u.se.fi;
      ll ti = u.se.se;
      ll temp_dist;
      if(dist[x] % ti == 0)
        temp_dist = dist[x];
    else
        temp_dist = (dist[x]/ti + 1)*ti;

      if(temp_dist+weight < dist[edge])
      {
        dist[edge] = temp_dist+weight;
        s.insert(mp(dist[edge],edge));
      }

    }
  } //returns dist[] array with distance of vertex from source if reachable.

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

      
       cin>>n>>m>>s>>d;
       
       for(int i = 0; i < m; i++)
       {
            ll a , b, c , d;
            cin>>a>>b>>c>>d;
            adj[a].pb({b,{c,d}});
            adj[b].pb({a,{c,d}});
       }

       dijkstra();

       if(dist[d] == 1e18)
        cout<<-1<<'\n';
    else
        cout<<dist[d];
          






return 0;
} 