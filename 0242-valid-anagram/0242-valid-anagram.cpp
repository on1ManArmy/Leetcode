class Solution {
public:
    bool isAnagram(string s, string t) {
        if(t.size() != s.size()){
            return false;
        }
        
        /// initialize
        unordered_map<char, int> mp;
        
        /// compute
        for(int i=0;i<s.size();i++){
            mp[s[i]-'a']++;
            mp[t[i]-'a']--;
        }
        
        /// check
        for(auto it: mp){
            if(it.second != 0){
                return false;
            }
        }
        return true;
    }
};

// T.C. = O(N)
// S.C. = O(N)