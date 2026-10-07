class Solution {
public:
    string countAndSay(int n) {
        if(n==1) return "1";
        
        string str = countAndSay(n-1);
        string s = "";
        int count = 0;
        for(int i=0; i<str.size()-1; i++){
            if(str[i] == str[i+1]){
                count++;
            }
            else{
                count++;
                string st = to_string(count);
                s += st;
                s += str[i];
                count = 0;
            }
        }
        count++;
        string st = to_string(count);
        s += st;
        s += str[str.size()-1];
        count = 0;

        return s;
    }
};