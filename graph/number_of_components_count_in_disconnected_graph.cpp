/*
Platform   : Phitron
Problem    : count number of components of a graph.
Difficulty : Easy
Topic      : Graph, DFS
*/
#include<bits/stdc++.h>
using namespace std;
vector<int>adj_list[1005];
bool vis[105];
void dfs(int src)
{
    vis[src]=true;
    for(int child : adj_list[src])
    {
        if(!vis[child])
        {
           dfs(child);
        }
    }
      
}
int main()
{
    int n,e;
    cin>>n>>e;
    while(e--)
    {
       int a,b;
       cin>>a>>b;
       adj_list[a].push_back(b);
       adj_list[b].push_back(a);
    }
    memset(vis,false,sizeof(vis));
    int count = 0;
    for(int i=0; i<n; i++)
    {
        if(vis[i]==false)
        {
            dfs(i);
            count++;
        }
    }
    cout<<count<<endl;

    return 0;
}
/*
sample input : 
8 6
1 2
0 5
2 3
6 7
4 5
1 3
sample output : 
3
-------------------o--------------------
A graph component is a group of nodes where every node 
is connected (directly or indirectly) to each other,
 and no connection exists with nodes outside the group.
*/
