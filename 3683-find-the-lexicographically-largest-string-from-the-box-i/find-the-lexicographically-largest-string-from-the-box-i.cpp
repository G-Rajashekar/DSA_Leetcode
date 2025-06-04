class Solution {
public:
    string answerString(string word, int numFriends) {
        if (numFriends==1) return word;
        int maxLength=word.length()-(numFriends-1);
        char maxChar=*max_element(word.begin(),word.end());
        string ans=to_string(maxChar);
        for (int i=0;i<word.length();i++){
               if (word[i]==maxChar){
                   string temp=word.substr(i,maxLength);
                   if (temp>ans)  ans=temp;
               }
        }
        return ans;
    }
};