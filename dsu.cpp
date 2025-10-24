 
 class DSU { //tells whether u and v belong to same component in constant time O(1)--//
  public:
   vector<int> rank,parent,size;
    DSU(int n) {
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
         if(rank[ulp] == rank[vlp]) rank[ulp]++;
         parent[vlp] = ulp;
    }
    
     void findUnionBySize(int u,int v) {  //it stores the size as rank gets distorted while path compression
         int ulp=findUlp(u);
         int vlp=findUlp(v);

         if(ulp==vlp) return;
         if(size[ulp] < size[vlp]) swap(ulp, vlp);
         
         parent[vlp] = ulp;
         size[ulp] += size[vlp];
    } 
 };
  
 
