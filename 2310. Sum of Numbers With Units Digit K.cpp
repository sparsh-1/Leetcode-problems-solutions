// https://leetcode.com/problems/sum-of-numbers-with-units-digit-k/
// Time Complexity - O() Space Complexity - O()
class Solution {
public:
    vector<int> oc_ans;
    int minimumNumbers(int num, int k) {
        if (num == 0)
            return 0;
        if (k % 2 == 0 && num % 2 != k % 2)
            return -1;
        vector<int> arr;
        for (int i = k; i < num + 1; i += 10) {
            if (i == 0)
                continue;
            arr.push_back(i);
        }
        oc_ans.resize(num + 1, 0);
        for (int i = 0; i < arr.size(); i++) {
            for (int j = arr[i]; j < num + 1; j += arr[i])
                oc_ans[j] = j / arr[i];
        }
        for (int i = 0; i < num + 1; i++) {
            if (oc_ans[i]) {
                for (int j = i + 1; j < num + 1; j++) {
                    if (oc_ans[j])
                        if (i + j < num + 1 && oc_ans[i + j] == 0)
                            oc_ans[i + j] = oc_ans[i] + oc_ans[j];
                        else if (i + j < num + 1)
                            oc_ans[i + j] = min(oc_ans[i + j], oc_ans[i] + oc_ans[j]);
                }
            }
        }
        if (oc_ans[num] == 0)
            return -1;
        else
            return oc_ans[num];
        return 0;
    }
};