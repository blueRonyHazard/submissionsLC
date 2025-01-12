// LC Link: https://leetcode.com/problems/minimum-height-trees
// Logic: minimum height trees will be created with nodes that are farther away from leaves. The longest length for the tree will have the answer nodes. 
// if the longest link has odd number of edges -> answer has 2 nodes. even number of edges -> answer has 1 nodes
// Code: bfs with all the leaves nodes, remove the edges and pause when there are <=2 nodes. 
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n == 0)  return {};
        if(n == 1)  return {0};

        vector<int> ans;
        vector<int> degree(n,0);
        vector<vector<int>> graph(n);
        queue<int> leaves;

        // graph creation
        for(auto edge: edges) {
            degree[edge[0]]++; degree[edge[1]]++;
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        
        // initialise the queue
        for(int i=0;i<n;i++) {
            if(degree[i]==1) {
                leaves.push(i);
            }
        }

        while(!leaves.empty()) {
            ans.clear();
            int size = leaves.size();
            
            for(int i=0; i<size; i++) {
                int cur = leaves.front();
                leaves.pop();  
                degree[cur]--;
                ans.push_back(cur);
                for(auto neighbour: graph[cur]) {
                    degree[neighbour]--;
                    if(degree[neighbour] == 1) {
                        leaves.push(neighbour);
                    }
                }
            }
        }
        return ans;
    }
};
