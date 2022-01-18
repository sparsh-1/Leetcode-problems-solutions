// https://leetcode.com/problems/defanging-an-ip-address/
class Solution {
public:
    string defangIPaddr(string address) {
        string temp;
        for (int i = 0; i < address.size(); i++) {
            if (address[i] == '.') {
                temp += '[';
                temp += '.';
                temp += ']';
            }
            else
                temp += address[i];
        }
        return temp;
    }
};