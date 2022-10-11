class Solution {
public:
    int hardestWorker(int n, vector<vector<int>>& logs) {
        int maxi = 0;
        int ans = INT_MAX;
        
        
        // Case 1: Finding the longest time
        for(int i=0;i<logs.size();i++){
            int temp = 0;
            
            if(i==0){
                temp = logs[i][1];
            }
            else{
                temp = logs[i][1] - logs[i-1][1];
            }
            
            maxi = max(maxi, temp);
        }
        
        // case 2: finding the minimum id, if any
        for(int i=0;i<logs.size();i++){
            int temp = 0;
            
            if(i==0){
                temp = logs[i][1];
            }
            else{
                temp = logs[i][1] - logs[i-1][1];
            }
            
            if(temp == maxi){
                ans = min(ans, logs[i][0]);
            }
        }
        
        
        return ans;
    }
};