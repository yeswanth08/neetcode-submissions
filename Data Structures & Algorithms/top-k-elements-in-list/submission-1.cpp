class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> res;
        map<int,int> mp;
        for (auto it: nums){
            mp[it]++;
        }
        auto comp = [](const pair<int,int>& a,const pair<int,int>& b){return a.second>b.second;};
        // greater int to sort map in desc by keys
        // for values only way it to get them by vector & sort function
        vector<pair<int,int>> copymp(mp.begin(),mp.end());
        sort(copymp.begin(),copymp.end(),comp);
        for (int i=0; i<k; ++i){
            res.push_back(copymp[i].first);
        }
        return res;
    }   
};
