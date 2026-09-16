class Solution {
public:
    bool dfs( int src , vector<vector<int>>&graph , vector<int>&color , vector<bool>&vis ){
    
        vis[src] = true;

        for( int i = 0 ; i<graph[src].size(); i++ ){
            if( !vis[graph[src][i]] ){
                vis[graph[src][i]] = true;
                color[graph[src][i]] = !color[src];
                if(!dfs( graph[src][i] , graph , color , vis )){
                    return false;
                }
            }
            else if( color[graph[src][i]] == color[src]){
                  return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {


        int n = graph.size();
        vector<int>color( n , -1 );
        vector<bool>vis(n , false );
        for (int i = 0; i < n; i++) {
           if (!vis[i]) {
                color[i] = 0;
         
        if (!dfs(i, graph, color, vis)) {
            return false;
        }
    }
}

return true;
   
        
        
    }
};