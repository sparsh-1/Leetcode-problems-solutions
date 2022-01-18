// https://leetcode.com/problems/can-place-flowers/
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int i = 0;
        while (i < flowerbed.size()) {
            int zlen = 0, st = i;
            while (i < flowerbed.size() && !flowerbed[i])
                zlen++, i++;
            if (st == 0 && i == flowerbed.size())
                n -= ++zlen / 2;
            else if (st == 0 && zlen)
                n -= zlen / 2;
            else if (i == flowerbed.size())
                n -= zlen / 2;
            else if (zlen)
                n -= --zlen / 2;
            if (n <= 0)
                return true;
            i++;
        }
        return false;
    }
};