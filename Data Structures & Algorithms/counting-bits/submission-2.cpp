class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> count(n+1);//分配n+1个空间
        count[0] = 0;
        for(int i=1;i<=n;i++){
            int last_num = i&1;
            count[i] = count[i>>1] + last_num;
        }
    return count;
    }
};
//当然 也可以说 奇数比上一个偶数多1个1 
//if (i & 1)      res[i] = res[i-1] + 1;
//else            res[i] = res[i/2];      