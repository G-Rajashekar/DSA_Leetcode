class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {

        unordered_map<string,bool>mp;
        int i=1;

        while(true){
            string num=to_string(i);
            if (num.find('0')!=string::npos){
                i++;
                continue;
            }
            int req=n-i;
            if (mp.find(to_string(req))!=mp.end() || req==i){
                return {req,i};
            }
             mp[num]=true;
            i++;
        }
        return {-1,-1};
    }
};