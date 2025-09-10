class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        unordered_set<int>sadUsers;

        for (auto fri:friendships){
            int u=fri[0]-1;
            int v=fri[1]-1;
            unordered_set<int>lang(languages[u].begin(),languages[u].end());
            bool flag=false;
            for (auto l:languages[v]){
                if (lang.count(l)){
                    flag=true;
                    break;
                }
            }
            if (!flag) {sadUsers.insert(u); sadUsers.insert(v);}

        }

        int maxKnown=0;

        vector<int>freq(n+1,0);

        for (auto user:sadUsers){
            for (auto l:languages[user]){
                freq[l]++;
                maxKnown=max(maxKnown,freq[l]);
            }
        }
        return sadUsers.size()-maxKnown;
    }
};