class Solution {
public:
vector<string>res;
    vector<string> generateParenthesis(int n) {
        helper(0,n,"");
        return res;
    }

    void helper(int ind,int n,string par){
        if (ind>=2*n){
            if (isValid(par)){
                res.push_back(par);
            }
            return;
        }

        helper(ind+1,n,par+'(');
        helper(ind+1,n,par+')');
        return;
    }

    bool isValid(string &s){
         stack<char> st;

    for (char ch : s) {
        if (ch == '(') {
            st.push(ch);
        }
        else if (ch == ')') {
            if (st.empty()) return false;

            char top = st.top();
            st.pop();

            if ((ch == ')' && top != '('))
                return false;
        }
    }
    return st.empty();
    }
};