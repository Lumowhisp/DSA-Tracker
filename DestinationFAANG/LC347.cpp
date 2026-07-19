class Solution {
    public:
        vector<int> topKFrequent(vector<int>& nums, int k) {
            unordered_map<int,int>mp;
            for(int it:nums){
              mp[it]++;
            }
            vector<pair<int,int>>vec(mp.begin(),mp.end());
            sort(vec.begin(),vec.end(),
            [](auto &a,auto &b){
              return a.second>b.second;
            });
            vector<int>ans;
            for(int i=0;i<k;i++){
              ans.push_back(vec[i].first);
            }
            return ans;
        }
    };