class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        int i=1;

        while(true){
            string num=to_string(i);
            if (num.find('0')!=string::npos){
                i++;
                continue;
            }
            string req=to_string(n-i);
            if (req.find('0')==string::npos){
                return {stoi(req),i};
            }
            i++;
        }
        return {-1,-1};
    }
};