class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<pair<double,int>>pq;

        int n=classes.size();

        for (int i=0;i<n;i++){
            helper(classes,pq,i);
        }

        while(extraStudents--){
            auto it=pq.top();
            pq.pop();

            int i=it.second;
            
            classes[i][0]++;
            classes[i][1]++;

            helper(classes,pq,i);

        }

        double ans=0;


       for (auto cls:classes){
           int x=cls[0];
           int y=cls[1];

           ans+=(double)x/y;
       }

        return ans/n;
    }

    void helper(vector<vector<int>>& classes, priority_queue<pair<double,int>>&pq,int i){
        double cur=(double)classes[i][0]/classes[i][1];
        double next=(double)(classes[i][0]+1)/(classes[i][1]+1);
        double inc=next-cur;
        pq.push({inc,i});
    }

};