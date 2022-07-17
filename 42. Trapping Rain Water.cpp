// https://leetcode.com/problems/trapping-rain-water/
// What I have done here is that for each index I have stored the previous greater element and the next greater element
// using stack. Now I know the water in a specific column can only fill up to a maximum height of min of (previous greater height
// or next greater height) - current height of that column.
// Time Complexity - O(n), Space Complexity - O(n)
class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> pge, nge;
        stack<int> png;
        for (int i = 0; i < height.size(); i++) {
            if (png.empty()) {
                png.push(i);
                pge.push_back(-1);
            }
            else if (height[png.top()] > height[i]) {
                pge.push_back(png.top());
            }
            else {
                while (!png.empty() && height[png.top()] <= height[i])
                    png.pop();
                if (png.empty()) {
                    png.push(i);
                    pge.push_back(-1);
                }
                else {
                    pge.push_back(png.top());
                    png.push(i);
                }
            }
        }
        while (!png.empty())
            png.pop();
        for (int i = height.size() - 1; i >= 0; i--) {
            if (png.empty()) {
                png.push(i);
                nge.push_back(-1);
            }
            else if (height[png.top()] > height[i]) {
                nge.push_back(png.top());
            }
            else {
                while (!png.empty() && height[png.top()] <= height[i])
                    png.pop();
                if (png.empty()) {
                    png.push(i);
                    nge.push_back(-1);
                }
                else {
                    nge.push_back(png.top());
                    png.push(i);
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < height.size(); i++) {
            if (pge[i] != -1 && nge[height.size() - i - 1] != -1) {
                ans += min(height[pge[i]], height[nge[height.size() - i - 1]]) - height[i];
            }
        }
        return ans;
    }
};


// I have reduced 3 loops to 2 here.
// Similarly I can also reduce this 2 loops to 1 and also I can diminish the whole pge and nge array
// just by storing the highest element from both end and start thus giving time complexity of O(n) but space 
// complexity of O(1) only.
class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> pge(height.size()), nge(height.size());
        stack<int> png;
        int ans = 0;
        for (int i = 0; i < height.size(); i++) {
            if (png.empty()) {
                png.push(i);
                pge[i] = -1;
            }
            else if (height[png.top()] > height[i]) {
                pge[i] = png.top();
            }
            else {
                while (!png.empty() && height[png.top()] <= height[i])
                    png.pop();
                if (png.empty())
                    pge[i] = -1;
                else
                    pge[i] = png.top();
                png.push(i);
            }
        }
        while (!png.empty())
            png.pop();
        for (int i = height.size() - 1; i >= 0; i--) {
            if (png.empty()) {
                png.push(i);
                nge[i] = -1;
            }
            else if (height[png.top()] > height[i])
                nge[i] = png.top();
            else {
                while (!png.empty() && height[png.top()] <= height[i])
                    png.pop();
                if (png.empty())
                    nge[i] = -1;
                else
                    nge[i] = png.top();
                png.push(i);
            }
            if (pge[i] != -1 && nge[i] != -1)
                ans += min(height[pge[i]], height[nge[i]]) - height[i];
        }
        return ans;
    }
};