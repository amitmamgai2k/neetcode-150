class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int>mpp;
        if(s.size()!=t.size())return false;
        for(auto it:s){
            mpp[it]++;
        }
        for(int i = 0;i<t.size();i++){
            if(mpp.find(t[i])==mpp.end())return false;
            mpp[t[i]]--;
            if(mpp[t[i]]==0)mpp.erase(t[i]);


        }
        if(mpp.size()==0)return true;
        return false;
    }
};
