class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> groups;//第一个string就是key(ordered_word),后面这个vector存放原始word
        //如groups["opst"] = ["pots","tops","stop"]
        for(int i=0;i<strs.size();i++){
            string key = strs[i];//先把当前的word赋值给key
            sort(key.begin(),key.end());//把当前的key进行排序，比如tops变成opst
            groups[key].push_back(strs[i]);//push_back放进对应的组内
            //先找到当前key对应的vector<string>,把它放到groups里面alignas
            //以groups["act":"act";"opst":"pots"]然后处理tops 对应的排好序的key还是opst,识别到groups[opst]已经有了
            //就变成了groups["act":"act";"opst":"pots","tops"]
        }
        //进行遍历之后输出
        vector<vector<string>> result;//二维数组
        for(auto pair:groups){//遍历 groups 这个 hashmap 里的每一组 key-value
        //这里pair的类型是<const string, vector<string>>,用auto之后让C++自己判断
            result.push_back(pair.second);//push_back是默认直接放在最后一个位置,insert是放在指定的位置
            //pair.first是key, pair.second直接就是value
        }
        return result;
    }
};