class Solution {
public:

    bool dfs(int course,
             vector<vector<int>>& prerequisites,
             vector<int>& vis,
             vector<int>& rec) {

        vis[course] = true;
        rec[course] = true;

        for (int i = 0; i < prerequisites.size(); i++) {

            if (prerequisites[i][0] == course) {

                int nextCourse = prerequisites[i][1];

                if (!vis[nextCourse]) {
                    if (!dfs(nextCourse, prerequisites, vis, rec)) {
                        return false;
                    }
                }
                else if (rec[nextCourse]) {
                    return false;
                }
            }
        }

        rec[course] = false;
        return true;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        vector<int> vis(numCourses, false);
        vector<int> rec(numCourses, false);

        for (int i = 0; i < numCourses; i++) {

            if (!vis[i]) {
                if (!dfs(i, prerequisites, vis, rec)) {
                    return false;
                }
            }
        }

        return true;
    }
};