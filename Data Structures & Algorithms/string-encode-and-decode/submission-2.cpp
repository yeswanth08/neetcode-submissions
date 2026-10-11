class Solution {
public:

    string encode(vector<string>& strs) {
        string temp = "";
        for (auto it: strs){
            temp += it;
            temp += "`";
        }
        return temp;
    }

    vector<string> decode(string s) {
        vector<string> res;
        int i = 0, n = s.size();
        while(i<n){
            int j=i;
            string temp = "";
            while(j<n&&s[j]!='`'){
                temp += s[j];
                 ++j;
            }
            res.push_back(temp);
            i=j+1;
        }
        return res;
    }
};
