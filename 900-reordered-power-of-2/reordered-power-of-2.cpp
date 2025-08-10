class Solution {
public:
    bool reorderedPowerOf2(int n) {
        string str_num=to_string(n);
        sort(str_num.begin(),str_num.end());
        for (int i=0;i<32;i++){
            string temp=to_string(1<<i);
            sort(temp.begin(),temp.end());
            if (temp==str_num) return true;
        }
        return false;
    }
};