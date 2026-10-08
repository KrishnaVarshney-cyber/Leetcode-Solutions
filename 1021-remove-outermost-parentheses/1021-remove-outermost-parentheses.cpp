class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans="";
        stack<char> st;
        int i=0;
        string word="";
        while(i<s.size()){
            word+=s[i];
            if(s[i]=='('){
                st.push(s[i]);
            }
            else{
                st.pop();
            }
            if(st.size()==0){
                ans+=word.substr(1,word.size()-2);
                word="";
            }
            i++;
        }
        return ans;
    }
};