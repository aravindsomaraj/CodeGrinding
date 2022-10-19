class Solution {
public:
    int minDistance(string word1, string word2) {
        
        int m = word1.size();
        int n = word2.size();
        
        vector<vector<int>> dp (m+1,vector<int> (n+1,0));
        
        for(int i=1; i<=m; i++)
        {
            dp[i][0] = i;
        }
        for(int j=1; j<=n; j++)
        {
            dp[0][j] = j;
        }
        for(int i=1; i<=m; i++)
        {
            for(int j=1; j<=n; j++)
            {
                if(word1[i-1] == word2[j-1])
                    dp[i][j] = dp[i-1][j-1];
                else
                    /*

                    If word1[i - 1] != word2[j - 1], we need to consider three cases.

                    Replace word1[i - 1] by word2[j - 1] (dp[i][j] = dp[i - 1][j - 1] + 1);
                    If word1[0..i - 1) = word2[0..j) then delete word1[i - 1] (dp[i][j] = dp[i - 1][j] + 1);
                    If word1[0..i) + word2[j - 1] = word2[0..j) then insert word2[j - 1] to word1[0..i) (dp[i][j] = dp[i][j - 1] + 1).
                    

                    So when word1[i - 1] != word2[j - 1], dp[i][j] will just be the minimum of the above three cases.
                    
                    */

                    dp[i][j] = min({dp[i-1][j-1],dp[i][j-1],dp[i-1][j]}) + 1;
            }
        }
        
        return dp[m][n];
        
        
    }
};