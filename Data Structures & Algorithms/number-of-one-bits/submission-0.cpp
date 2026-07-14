class Solution {
public:
    int hammingWeight(uint32_t n) {
        int sum = 0;
        for(int i=0;i<32;i++){
            if(n & 1){//与是都为1才返回1,而 n & 1 1的前31位都是0，32位是1，所以相当于只看最后一位
                sum += 1;
            }
            n = n >> 1;
        }
    return sum;
    }
};
//AND 与   &  两个都是1 结果才是1 否则是0
//OR  或   |  只要有一个是 1，结果就是 1
//XOR 异或 ^  不一样才是 1，一样就是 0
//NOT 非   ~  0 变 1，1 变 0
//  左移   << 所有位往左推，右边补 0  n<<1相当于n*2
//  右移   >> 所有位往右推，左边补 0  n>>1相当于n/2