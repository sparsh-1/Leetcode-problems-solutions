// https://leetcode.com/problems/broken-calculator/
// With a mathematical property we know that if we only decrease/increase a number by 1 and divide it by 2 consecutively, we 
// will eventually reach 1. This is what i have used here, if startValue >= targetValue, we cand do nothing except increasing the 
// target value by 1.
// Else we have a goal to make the target equal to startValue, for it I have divided it by 2 if it is again greaater than startValue
// else I know that dividing it by two and then increasing the target will give us the answer. In case of odd target we will simply increase it by 1
// As we know that division will reduce many operations at once in comparison to + and -.
// Time Complexity - O(log(target)), Space Complexity - O(1)
class Solution {
public:
    int brokenCalc(int startValue, int target) {
        if (target <= startValue)
            return startValue - target;
        int cnt = 0;
        while (true) {
            if (target % 2 == 0 && target / 2 == startValue)
                return cnt + 1;
            else if (target % 2 == 0 && target / 2 > startValue) {
                target /= 2;
                cnt++;
            }
            else if (target % 2 == 0) {
                if ((target + 2) / 2 <= startValue)
                    return startValue - (target / 2) + cnt + 1;
            }
            else
                target++, cnt++;
        }
        return cnt;
    }
};