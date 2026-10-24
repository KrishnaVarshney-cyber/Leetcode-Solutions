class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> st;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                st.push(s[i]);
            }
            if(s[i]==')'){
                if(st.empty() || st.top()==')'){
                    st.push(s[i]);
                }
                else{
                    st.pop();
                }
            }
        }
        return st.size();
    }
};