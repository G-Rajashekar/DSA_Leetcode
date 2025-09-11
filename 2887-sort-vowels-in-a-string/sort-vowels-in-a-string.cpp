class Solution {
public:
    string sortVowels(string s) {
        vector<char>vowels;

        for (auto c:s){
            char ch=c;
            if (ch>=65 && ch<=90){
                ch=ch+32;
            }
            if (ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u'){
                vowels.push_back(c);
            }
        }

        sort(vowels.begin(),vowels.end());

        string t="";
        int i=0;

        for (auto c:s){
            char ch=c;
            if (ch>=65 && ch<=90){
                ch=ch+32;
            }
             if (ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u'){
                t.push_back(vowels[i]);
                i++;
            }
            else{
                t.push_back(c);
            }
            
        }
        return t;
    }
};