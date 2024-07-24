#include <vector>
#include <unordered_map>
#include <iostream>

class Solution {
    int ans = 0;
public:
    void dfs(std::unordered_map<int,std::vector<int>>&mp ,std::unordered_map<int,bool>&vis,int m){
        vis[m]=true;
        for(auto i:mp[m]){
            if(i>=0){
                if(!vis[i]){    
                    dfs(mp,vis,i);
                }
            }
            else{
                i=abs(i);
                if(!vis[i]){   
                    ans++; 
                    dfs(mp,vis,i);
                }
            }
        }
    }
    
    int minReorder(int n, std::vector<std::vector<int>>& c) {
        int s=c.size();
        std::unordered_map<int,std::vector<int>>mp;
        std::unordered_map<int, bool>vis;
        for(int i = 0; i < s; i++){
            mp[c[i][1]].push_back(c[i][0]);
            mp[c[i][0]].push_back(-c[i][1]);
        }
        dfs(mp,vis,0);
        if(ans==0)return ans;
        return ans;
    }
};