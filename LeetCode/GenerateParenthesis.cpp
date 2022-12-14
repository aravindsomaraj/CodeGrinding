class Solution {
public:
    void Solve(vector<string>& a, string s, int n, int i)
    {
        if(i==n)    // if all maximum possible '(' are present, then add remaining ')'s.
        {
            while(s.size()!=(2*n))
            {
                s=s+")";
            }
            a.push_back(s);
            return ;
        }
                  
        s = s + "(";
    
        Solve(a,s,n,i+1);
                  
        s.pop_back();       //backtracking
        
        if(2*i == s.size())
            return ;
        s = s + ")";
        
        Solve(a,s,n,i);
            
    }
    vector<string> generateParenthesis(int n) {
        
        vector<string> a;
        Solve(a,"",n,0);
        
        return a;
        
    }
};