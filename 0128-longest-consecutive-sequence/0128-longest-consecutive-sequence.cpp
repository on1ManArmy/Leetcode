class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> hs;
        
        /// put it into the set
        for(int it: nums){
            hs.insert(it);
        }
        
        int len = 0;
        /// Now, check for consecutivity
        for(auto it: nums){
            if(!hs.count(it-1)){
                int currNum = it;
                int currLen = 1;
                
                while(hs.count(currNum+1)){
                    currNum += 1;
                    currLen += 1;
                }
                
                /// update maximum length
                len = max(len, currLen);
            }
        }
        
        return len;
    }
};