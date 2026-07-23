class Solution {
private:
    bool check(vector<int>& piles, int val, int h){
        long long sum=0;// piles[i]最大可能超过整型范围
        for(int i=0;i<piles.size();i++){
            sum+=(piles[i]+val-1)/val;//向上取整
        }
        if(sum<=h){
            return true;
        }else{
            return false;
        }
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left=1;
        int right=0;
        for(int p : piles){
            right = max(p,right);
        }
        int record=right;
        while(left<=right){
            int mid = right+(left-right)/2;
            if(check(piles,mid,h)==true){
                record = mid;
                right = mid - 1;
            }else{
                left = mid + 1;
            }
        }
    return record;
    }
};
