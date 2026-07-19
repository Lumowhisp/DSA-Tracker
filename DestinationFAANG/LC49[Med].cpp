//Optimal Approach
//SC : O(n*logk)
//SC : O(n*k)

class Solution {
    public:
        vector<vector<string>> groupAnagrams(vector<string>& strs) {
            unordered_map<string,vector<string>>mp;
            for(string s:strs){
              string key=s;
              sort(key.begin(),key.end());
              mp[key].push_back(s);
            }
            vector<vector<string>>ans;
            for(auto &it:mp){
              ans.push_back(it.second);
            }
            return ans;
        }
    };



// Approach : Brute (n^2*K)
// class Solution {
//     public:
//         bool isAnagram(string s, string t) {
//           if(s.size()!=t.size()){
//             return false;
//           }
//             unordered_map<char, int> mp;
//             for (char ch : s) {
//                 mp[ch]++;
//             }
//             for (char ch : t) {
//                 mp[ch]--;
//             }
//             for (auto& it : mp) {
//                 if (it.second != 0) {
//                     return false;
//                 }
//             }
//             return true;
//         }
    
//         vector<vector<string>> groupAnagrams(vector<string>& strs) {
//             vector<vector<string>> ans;
//             vector<bool> visited(strs.size(), false);
//             for (int i = 0; i < strs.size(); i++) {
//                 if (!visited[i]) {
//                     vector<string> store;
//                     for (int j = i; j < strs.size(); j++) {
//                         if (isAnagram(strs[i], strs[j])) {
//                             visited[j] = true;
//                             store.push_back(strs[j]);
//                         }
//                     }
//                     ans.push_back(store);
//                 }
//             }
//             return ans;
//         }
//     };