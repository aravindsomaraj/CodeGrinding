#include<bits/stdc++.h>
using namespace std;
int SolveFast(vector<vector<int>> dp, int i)
{
    int ma=0;
    // int l=ma;
    for(int j=0; j<dp[0].size(); j++)
    {
        if(dp[i][j]==1)
        {
            ma=max(ma,1+SolveFast(dp,j));
        }
    }
    return ma;
}
int Solve(vector<vector<int>>& box)
{
    int m = box.size();
    int n = box[0].size();
    
    vector<vector<int>> dp (m, vector<int> (m,0));
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(box[i][0] < box[j][0] && box[i][1] < box[j][1])
            {
                dp[i][j] = 1;
            }
        }
    }
    int ma=0;
    for(int i=0; i<m; i++)
    {
        ma=max(ma,1+SolveFast(dp,i));
    }
    return ma;
}

int main()
{
    int n;
    cout << "Number of Boxes: ";
    cin >> n;
    vector<vector<int>> box (n, vector<int> (2,0));
    for(int i=0; i<n; i++)
    {
        cin >> box[i][0] >> box[i][1];
    }

    int num = Solve(box);

    cout << "Possible Ways: " << num << endl;
}