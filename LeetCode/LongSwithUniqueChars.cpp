class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        vector<int> mp (256,0);
        
        // if(s=="")
        //     return 0;
        
        int start=0,maxl=0,maxs=0,l=0;
        
        for(int i=0;i<s.size();i++)
        {
            mp[s[i]]++;                 //updating count in map
            cout << s[i];
            
            if(mp[s[i]]!=1)
            {
                while(mp[s[i]]!=1)     //resetting start to new posn, also decrementing occurences of all prev characters
                {
                    mp[s[start]]--;
                    start++;
                }
            }
            l=i-start+1;                //current length
            if(l>maxl)
            {
                maxl=l;
                maxs=start;
            }
        }
        
        return maxl;
        
    }
    
};