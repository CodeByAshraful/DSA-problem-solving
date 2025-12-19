/*
Platform   : Phitron
Problem    : Single Source Shortest Distance using BFS
Difficulty : Easy
Topic      : Graph, BFS
*/
#include<bits/stdc++.h>
using namespace std;
vector<int>adj_list[1005]; // let 1005 array size
bool vis[1005]; //for tracking duplicate nodes 
int level[1005]; //for counting the level of nodes

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

    int src,dest; //src->source node; dest->destination;
    cin>>src>>dest; 
    bfs(src); //function call

    cout<<level[dest]<<endl;

    return 0;
}
/*
sample input 1 : 
7 8
0 1
1 3
3 2
1 4
3 5
2 5
5 6
4 6
0
4
sample output 1 : 
2
 
sample input 2 : 
8 9
0 1
1 3
3 2
1 4
3 5
2 5
5 6
4 6
7 8
0
8 

sample output 2 : 
-1 --> it means no connected path with source node.

*/