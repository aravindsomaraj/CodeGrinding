class Solution {
public:
    
    void Solve(int i, vector<vector<int>>& a,vector<int>& arr, vector<int>& temp, int target)
    {
        if(target==0)               //condition satisfied, set of vectors is pushed
        {
            a.push_back(temp);
            return;
        }
        
        if(target<0)
            return;
        
        if(i==arr.size())
            return;
        
        Solve(i+1,a,arr,temp,target);   
        
        temp.push_back(arr[i]);             //pushing selected candidate to temp vector
        
        Solve(i,a,arr,temp,target-arr[i]);  //repeating the same candidate 
        temp.pop_back();                    //backtracking
        
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        vector<vector<int>> a;
        
        vector<int> temp;
        
        Solve(0,a,candidates,temp,target);
        
        return a;
        
        
        
    }
};