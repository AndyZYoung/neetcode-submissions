class TimeMap {
private:
    unordered_map<string, vector<pair<int, string>>> data;
public:
    TimeMap() {
    }
    
    void set(string key, string value, int timestamp) {
        data[key].push_back({timestamp,value});
    }
    
    string get(string key, int timestamp) {
        if(data.find(key)==data.end()){//这里.find()是查找，.end() 就像"字典最后一页的后面"
        //找到了：返回指向那个位置的"指针"（迭代器）
        //没找到：返回 data.end()（表示"到头了，没找到"）
        //data[key] 会自动创建空列表！find 是"看看有没有"，不动手；data[key] 是"没有就造一个"。
            return "";
        }
        vector<pair<int,string>>& lst = data[key];//引用不复制，直接操作原数据
        int left = 0;
        int right = lst.size()-1;
        int ans = -1;//记录最后一个满足条件的索引
        while(left<=right){
            int mid = left + (right - left)/2;
            if(lst[mid].first<=timestamp){
                ans = mid;
                left = mid+1;
            }else{
                right = mid - 1;
            }
        }
        if(ans == -1) return "";
        return lst[ans].second;
    }
};
