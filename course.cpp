//TC: O(V+E)
//SC: O(V+E)
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> map;
        vector<int> indegree(numCourses, 0);
        //build hashmap here

        
        for(auto v: prerequisites)
        {
            int pre=v[1];
            int course=v[0];
            map[pre].push_back(course);
            indegree[course]+=1;
        }
        queue<int> q;
        for(int i=0;i<indegree.size();i++)
        {
            if(indegree[i]==0)
                q.push(i);
        } 

        while(!q.empty())
        {
            int curr=q.front();
            q.pop();
            for(auto n: map[curr])
            {
                indegree[n]--;
               if(indegree[n]==0)
                    q.push(n);
        
            }
        }

        for(int i=0;i<indegree.size();i++)
        {
            if(indegree[i]!=0)
                return false;
        }
return true;
    }
};