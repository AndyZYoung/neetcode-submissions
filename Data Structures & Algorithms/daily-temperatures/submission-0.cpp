class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        stack<int> temp;
        vector<int> wait(n,0);
        for(int i=0;i<n;i++){
            while(temp.size()!=0 && temperatures[i]>temperatures[temp.top()]){
                int prevDay = temp.top();
                temp.pop();
                wait[prevDay] = i -prevDay;
            }
            temp.push(i);
        }
    return wait;
    }
};