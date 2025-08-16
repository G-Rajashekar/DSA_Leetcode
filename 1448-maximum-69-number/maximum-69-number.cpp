class Solution {
public:
    int maximum69Number (int num) {
        string temp=to_string(num);
        int n=temp.length();
        int i=0;
        int j=temp.length()-1;

        while(i<n){
            if (temp[i]=='6'){
                 temp[i]='9';
                 break;
            };
            i++;
        }

        return stoi(temp);
    }
};