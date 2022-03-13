class Solution {
public:
    stack<pair<int,int>> helps;//first:repeattime;second:[index
    string ans;
    int l;
    string decodeString(string s) {
        l = 0;
        while(l<s.size()){
            ans += helpDecode(s);
            //l++;
        }
        return ans;
    }
    string helpDecode(string s){
        int lnew = 0,rnew = 0,intIndex = 0;
        string retStr;
        int repeatTime = 0;
        while(l<s.size()){
            while(l<s.size()&&s[l]>='0'&&s[l]<='9'){
                repeatTime = repeatTime*10+s[l]-'0';
                l++;
            }
            if(s[l] == '['){
                l++;
                string inStr = helpDecode(s);
                while(repeatTime>0) {
                    retStr+=inStr;
                    repeatTime--;
                }
                continue;
            }
            if(s[l] == ']') 
            {
                l++;
                return retStr;
            }
            retStr += s[l];
            l++;
        }
        return retStr;
    }
};