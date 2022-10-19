#include <bits/stdc++.h>
using namespace std;

void Solve(vector<char> s, int n, int i, int& c)
{
    if(i>=n)
        return;
    c++;
    for(int j=i+2; j<n; j++)
    {
        s[j]='1';
        for(char &i:s)
            cout << i;
        cout << "\n";
        Solve(s,n,j,c);
        s[j]='0';
    }

}
int main()
{

    int n;
    cin >> n;
    int count=0;
    vector<char> s (n,'0');
    for(int i=0;i<n;i++)
    {
        s[i]='0';
    }
    
    Solve(s,n,-2,count);
    cout << count << endl;
    return 0;
}