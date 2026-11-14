class Solution {
public:
    string decodeString(string s) {
        int i = 0;
        return decodeString(s,i);
    }

    string decodeString(string &s, int &i){
        string result = "";

        while(i < s.length() && s[i] !=']'){
            if(isalpha(s[i])){
                result += s[i];
                i++;
            }
            else{
                int num = 0;

                while(i < s.length() && isdigit(s[i])){
                    num = num * 10 + (s[i] - '0');
                    i++;
                }
                i++;

                string inside = decodeString(s, i);

                i++;

                for(int j = 0; j < num; j ++){
                    result += inside;
                }
            }
        }

        return result;
    }
};
