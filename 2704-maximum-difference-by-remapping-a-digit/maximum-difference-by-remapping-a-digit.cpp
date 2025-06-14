class Solution {
public:
    int minMaxDifference(int num) {
        char maxReplace=' ';
        char minReplace=' ';
        string maxi="";
        string mini="";

        string temp=to_string(num);

        for (auto c:temp){
            if (c!='9' && maxReplace==' ') maxReplace=c;
            if (c!='0' && minReplace==' ') minReplace=c;
        }

        for (auto c:temp){
            if (c==maxReplace) maxi.push_back('9');
            else maxi.push_back(c);

            if (c==minReplace) mini.push_back('0');
            else mini.push_back(c);
        }

        return stoi(maxi)-stoi(mini);
    }
};