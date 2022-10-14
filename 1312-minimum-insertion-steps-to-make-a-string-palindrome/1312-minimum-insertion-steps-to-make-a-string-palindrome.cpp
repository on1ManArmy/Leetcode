class Solution {
public:
    int t[1001][1001];
    int lcs(string& x, string& y, int n, int m){
        
        // base condition
        if(n == 0 || m == 0){
            return 0;
        }
        
        if(t[n][m] != -1){
            return t[n][m];
        }
        
        if(x[n-1] == y[m-1]){
            t[n][m] = 1 + lcs(x, y, n-1, m-1);
        }
        else{
            t[n][m] = max(lcs(x, y, n-1, m), lcs(x, y, n, m-1));
        }
        
        return t[n][m];
        
    }
    
    int lps(string text1, string text2) {
        int n = text1.length();
        int m = text2.length();
        memset(t, -1, sizeof(t));
        
        return lcs(text1, text2, n, m);
    }
    
    int minInsertions(string s) {
        string t = s;
        reverse(t.begin(), t.end());
        
        return s.size() - lps(s, t);
    }
};