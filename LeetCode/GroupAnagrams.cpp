class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>ans;
        int n=strs.size();
        if(n==0){
            return ans;
        }
        map<string,vector<string>>mp;
        for(int i=0;i<n;i++){
            string che=strs[i];
            sort(strs[i].begin(),strs[i].end());
            mp[strs[i]].push_back(che);             //pushing each string into the sorted index position of the string in the map
        }
        for(auto it:mp){
            ans.push_back(it.second);               //pushing into ans, groupwise
        }
        return ans;
    }
};