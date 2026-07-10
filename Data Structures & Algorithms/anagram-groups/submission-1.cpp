class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string , vector<string>>hash;
        for(string s:strs){
            vector<int> freq(26,0);//每处理一个单词都用一个(26,0)的字符表
            for(char ch:s){
                freq[ch-'a']++;
            }
            string key = "";
            for(int i=0;i<26;i++){
                key += "#" + to_string(freq[i]);
                //key就是类似'#1#0#2...#0#0'的形式，如果不加分隔符#会有问题比如[11,1]和[1,11]会混为一谈
            }
            hash[key].push_back(s);
        }
        //进行遍历之后输出
        vector<vector<string>> result;//二维数组
        for(auto pair:hash){//遍历 hash 这个 hashmap 里的每一组 key-value
        //这里pair的类型是<const string, vector<string>>,用auto之后让C++自己判断
            result.push_back(pair.second);//push_back是默认直接放在最后一个位置,insert是放在指定的位置
            //pair.first是key, pair.second直接就是value
        }
        return result;
    }
};