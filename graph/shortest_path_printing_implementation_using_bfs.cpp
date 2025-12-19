/*
Platform   : Phitron
Problem    : shortest Path printing implementation
Difficulty : Easy
Topic      : Graph, BFS
*/
#include<bits/stdc++.h>
using namespace std;
vector<int>adj_list[1005]; // let 1005 array size
bool vis[1005]; //for tracking duplicate nodes 
int level[1005]; //for counting the level of nodes
int parent[1005]; //for tracking the parent of childs

void bfs(int src)
{
    queue<int>q;
    q.push(src);
    vis[src]=true;
    level[src]=0;
    while(!q.empty())
    {
        int par = q.front(); //parent node
        q.pop();
        for(int child : adj_list[par])
        {
            if(vis[child]==false)
            {
                q.push(child);
                vis[child]=true;
                level[child]=level[par]+1; //for increasing the level of child
                parent[child]=par; //for selecting parent for childs
            }
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
    memset(level,-1,sizeof(level));
    memset(parent,-1,sizeof(parent));

    int src,dest; //src->source node; dest->destination;
    cin>>src>>dest; 
    bfs(src); //function call
    
    vector<int>path;
    int node = dest;
    while(node!=-1)
    {
        path.push_back(node);
        node=parent[node];
    }
    reverse(path.begin(),path.end());
    for(int x : path)
    {
        cout<<x<<" ";
    }
   


    return 0;
}
/*
here , 0 is source node and 6 is destination.

sample input : 
7 7
0 1
1 3
3 2
1 4
3 5
2 5
5 6
0
6

sample output : 
0 1 3 5 6 

*/