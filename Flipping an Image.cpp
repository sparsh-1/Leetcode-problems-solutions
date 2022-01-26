// https://leetcode.com/problems/flipping-an-image/
// I just have used xor firstly in this code and then replaced it by mod operation
// and by the run time I cam to know that xor operation is a costlier
// operation than mod operation.
// Time complexity - O(m * n), Space Complexity - O(1)
class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        for (int i = 0; i < image.size(); i++) {
            for (int j = 0; j < image[i].size() / 2; j++)
                if (image[i][j] == image[i][image[i].size() - j - 1])
                    image[i][j] = image[i][image[i].size() - j - 1] = (image[i][j] + 1) % 2;
            if (image[i].size() % 2)
                image[i][image[i].size() / 2] = (image[i][image[i].size() / 2] + 1) % 2;
        }
        return image;
    }
};