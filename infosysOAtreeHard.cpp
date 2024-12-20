
#include <bits/stdc++.h>
using namespace std;
int recNodes(int node , vector<int>adj[],int depth,int &sum,vector<int>&numNodes,vector<int>&depNodes){
    int cnt=1;
    sum+=depth;
    depNodes[node]=depth;
    for(int sideNode:adj[node]){
        cnt+=recNodes(sideNode,adj,depth+1,sum,numNodes,depNodes);
    }
    return numNodes[node]=cnt;
}
void dfs(int prev,vector<int>&numNodes,int &sum,int node,vector<int>&depNodes,int depth,map<int,int>parent){
    if(depNodes[node]>=depth){
        sum-=(numNodes[node]-numNodes[prev]-1)*(depNodes[node]-depth);
        if(parent[node]!=node){
            dfs(node,numNodes,sum,parent[node],depNodes,depth+1,parent);
        }
    }
}
int get_ans(int n,int m,vector<vector<int>>edges){
    map<int,int>parents;
    vector<int>adj[n];
    for(auto it:edges){
        parents[it[1]-1]=it[0]-1;
        adj[it[0]-1].push_back(it[1]-1);
    }
    int totalSum=0;
    vector<int>numNodes(n,0),depNodes(n,0);
    recNodes(0,adj,0,totalSum,numNodes,depNodes);
    int minSum=totalSum;
    for(int i=1;i<n;i++){
        int xNodeSum=totalSum-(numNodes[i]*(depNodes[i]-1));
        dfs(i,numNodes,xNodeSum,parents[i],depNodes,2,parents);
        minSum=min(minSum,xNodeSum);
    }
    return minSum;
}
int main()
{
    int n,m;
    cin>>n;
    m=n-1;
    vector<vector<int>>edges;
    for(int i=0;i<n-1;i++){
        int a,b;
        cin>>a>>b;
        edges.push_back({a,b});
    }
    cout<<get_ans(n,m,edges);

    return 0;
}