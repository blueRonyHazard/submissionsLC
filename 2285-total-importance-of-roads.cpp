// O(nlogn) + O(n) Sorting + roads traversal
// Let inDegree and sort the indegrees and multiple to road number
class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int> degrees(n,0);
        for(auto road: roads) {
            degrees[road[0]]++;
            degrees[road[1]]++;
        }

        sort(degrees.begin(), degrees.end(), greater<int>());

        long long ans = 0;

        for(int i=0; i<n; i++) {
            ans+=1LL*(n-i)*degrees[i];
        }

        return ans;
    }
};
