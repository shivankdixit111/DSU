  
  
   
 #include <bits/stdc++.h>
using namespace std;
#define vi vector<ll>
#define vs vector<string>
#define mii map<ll,ll>
#define umii unordered_map<ll,ll>
#define pii pair<ll,ll>
#define mod1 998244353
#define mci map<char,ll>
#define vpii vector<pair<ll,ll>>
#define vvii vector<vector<int>>
#define mod 1000000007
#define sei set<ll>
#define ses set<string> 
#define ues unordered_set<string> 
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(),x.end()
#define sall(x) sort(x.begin(),x.end());
#define rall(x) sort(x.rbegin(),x.rend())
#define MAX(x) *max_element(x.begin(),x.end())
#define MIN(x) *min_element(x.begin(),x.end())
#define SUM(X) accumulate(X.begin(),X.end(),0LL)
#define FIND(x,y) binary_search(all(x),y)
#define MEM(x,y) memset(x,y,sizeof(x))
#define binone(x) __builtin_popcountll(x)
#define ll long long int
#define pb push_back
#define Test ll t;cin>>t;while(t--)
#define in insert
#define ff first 
#define ss second 
#define rep(i,a,b) for(int i=a;i<b;i++)
#define repeq(i,a,b) for(int i=a;i<=b;i++)
#define revf(i,a,b) for(int i=b-1;i>=a;i--)
#define mini(a,b,c) min(a,min(b,c))
#define maxi(a,b,c) max(a,max(b,c)) 
#define rev(arr) reverse(arr.begin(),arr.end());
const int N=1e5+7;
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
#define ret return 0
#define endl '\n' //remove for interactives

// ================================== take ip/op like vector,pairs directly!==================================
template<typename typC,typename typD> istream &operator>>(istream &cin,pair<typC,typD> &a) { return cin>>a.first>>a.second; }
template<typename typC> istream &operator>>(istream &cin,vector<typC> &a) { for (auto &x:a) cin>>x; return cin; }
template<typename typC,typename typD> ostream &operator<<(ostream &cout,const pair<typC,typD> &a) { return cout<<a.first<<' '<<a.second; }
template<typename typC,typename typD> ostream &operator<<(ostream &cout,const vector<pair<typC,typD>> &a) { for (auto &x:a) cout<<x<<'\n'; return cout; }
template<typename typC> ostream &operator<<(ostream &cout,const vector<typC> &a) { int n=a.size(); if (!n) return cout; cout<<a[0]; for (int i=1; i<n; i++) cout<<' '<<a[i]; return cout; }
// ===================================END Of the input module ==========================================

  
 
 class DisjointSet { //tells whether u and v belong to same component in constant time O(1)--//
  public:
   vector<int> rank,parent,size;
    DisjointSet(int n) {
       rank.resize(n+1,0);
       parent.resize(n+1);
       size.resize(n+1,1);

       for(int i=0;i<=n;i++) parent[i]=i;
    
    }

    int findUlp(int node) {
        if(node==parent[node]) return node;

        return parent[node]=findUlp(parent[node]);
    }

    void findUnionByRank(int u, int v) {
         int ulp = findUlp(u);
         int vlp = findUlp(v);
         if(ulp == vlp) return;
         //greater rank becomes parent
         if(rank[ulp] < rank[vlp])  swap(ulp, vlp);
         else rank[ulp]++;
         parent[vlp] = ulp;
    }
    
    void findUnionBySize(int u,int v) {  //it stores the size as rank gets distorted while path compression
         int ulp_u=findUlp(u);
         int ulp_v=findUlp(v);

         if(ulp_u==ulp_v) return;

         if( size[ulp_u] > size[ulp_v] ) {
            parent[ulp_v]=ulp_u;
            size[ulp_u]+=size[ulp_v];
         } else {
            parent[ulp_u]=ulp_v;
            size[ulp_v]+=size[ulp_u];
         }
    }
 };
  
   

  int solve() {
   int n;
   cin>>n;

   DisjointSet ds(n+2);

   for(int i=0;i<n;i++) {
      int u,v;
      cin>>u>>v;

      ds.findUnionBySize(u,v);
   }
//    yes;
   ll q;
   cin>>q;

   while(q--) {
     int u,v;
     cin>>u>>v;  //lies in same component or not
     if(ds.findUlp(u)==ds.findUlp(v))  yes;
     else  no;
   }

   

    
    return 0;
  } 
 
  
  
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
 
    //   ll t;
    //   cin>>t;
    //   while(t--)

       solve();  

       ret;
} 
