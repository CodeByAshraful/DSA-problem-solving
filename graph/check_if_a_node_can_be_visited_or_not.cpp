#include<bits/stdc++.h>
using namespace std;
vector<int>adj_list[1005];
bool vis[1005];

void check_vis_node(int src)
 {
    queue<int>q;
    q.push(src);
    vis[src]=true;
    while(!q.empty())
    {
        int par = q.front();
        q.pop();
        for(int child : adj_list[par])
        {
           if(vis[child]==false)
           {
              q.push(child);
              vis[child]=true;
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
    int src,des; // src->source node; des->destination;
    cin>>src>>des;

    check_vis_node(src);
    //checking visted or not
    if(vis[des])
    {
        cout<<"Yes";
    }
    else
    cout<<"No"; 

   return 0;
}