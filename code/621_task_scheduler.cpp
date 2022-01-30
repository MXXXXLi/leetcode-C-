class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int>arr(26,0);
        for (char c : tasks) {
            arr[c - 'A']++;
            //cout<<arr[c - 'A']<<endl;
        }
        int maxNum = 0;
        for (int i = 0; i < 26; i++) {
            maxNum = max(maxNum, arr[i]);
        }
        int ret = (maxNum - 1) * (n + 1);
        //cout<<ret<<endl;
        for (int i = 0; i < 26; i++) {
            if (arr[i] == maxNum) {
                ret++;
            }
        }
        return max(ret, (int)tasks.size());
    }
};