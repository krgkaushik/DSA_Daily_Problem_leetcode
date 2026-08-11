class Solution {
public:

    vector<vector<int>>ans;
    vector<int>path;

    void dfs( int src , vector<vector<int>>&graph , vector<int>&vis ){
        path.push_back(src);
        vis[src] = true;

        if( src == graph.size() - 1 ){
            ans.push_back(path);
        } 

        for( int v : graph[src] ){
            if(!vis[v]){
                dfs( v , graph , vis );
            }
        } 

        vis[src] = false;
        path.pop_back();



    }


    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
      vector<int>vis(graph.size() ,  false );
      dfs( 0 , graph , vis );
      return ans;

        
    }
};