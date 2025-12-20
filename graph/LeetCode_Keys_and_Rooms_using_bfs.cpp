/*
Platform   : LeetCode
Problem    : 841. Keys and Rooms
Difficulty : Medium
Topic      : Graph, BFS
*/
class Solution {
public:
   bool vis[1005];
   void bfs(int src,vector<vector<int>>& rooms)
   {
    queue<int>q;
    q.push(src);
    vis[src]=true;
    while(!q.empty())
    {
    int par=q.front();
    q.pop();
    for(int child : rooms[par] )
    {
        if(!vis[child])
        {
            q.push(child);
            vis[child]=true;
        }
    }
    }
   }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        memset(vis,false,sizeof(vis));
        bfs(0,rooms);
        for(int i=0; i<rooms.size(); i++)
        {
            if(!vis[i])
            {
                return false;
            }
        }
        return true;    
    }
};
/*
Example 1:

Input: rooms = [[1],[2],[3],[]]
Output: true
Explanation: 
We visit room 0 and pick up key 1.
We then visit room 1 and pick up key 2.
We then visit room 2 and pick up key 3.
We then visit room 3.
Since we were able to visit every room, we return true.

Example 2:

Input: rooms = [[1,3],[3,0,1],[2],[0]]
Output: false
Explanation: We can not enter room number 2 since the only key that unlocks it is in that room.
*/
