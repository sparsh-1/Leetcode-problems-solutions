// https://leetcode.com/problems/largest-rectangle-in-histogram/
// Stack implementation
// What basically I have used is next smaller element and previous smaller element
// for a particular index. The maximum area will be between the next smaller and the previous smaller 
// index only.
// Time Complexity - O(n), Space Complexity - O(n) [We can even reduce more space by utilising same stack and vector]
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> nextSmaller, prevSmaller;
        vector<int> ns(heights.size(), heights.size()), ps(heights.size(), 0);
        nextSmaller.push(heights.size());
        prevSmaller.push(0);
        int ans = 0;
        for (int i = 1; i < heights.size(); i++) {
            while (!prevSmaller.empty() && heights[i] <= heights[prevSmaller.top()])
                prevSmaller.pop();
            if (!prevSmaller.empty())
                ps[i] = prevSmaller.top() + 1;
            else
                ps[i] = 0;
            prevSmaller.push(i);
        }
        for (int i = heights.size() - 2; i >= 0; i--) {
            while (!nextSmaller.empty() && heights[i] <= heights[nextSmaller.top() - 1]) {
                nextSmaller.pop();
            }
            if (!nextSmaller.empty()) {
                ns[i] = nextSmaller.top() - 1;
            }
            else {
                ns[i] = heights.size();
            }
            nextSmaller.push(i + 1);
        }
        for (int i = 0; i < heights.size(); i++) {
            ans = max(ans, (ns[i] - ps[i]) * heights[i]);
        }
        return ans;
    }
};

// Simple to understand solution with all cases same, just a bit change in logic
class Solution {
public:
    int largestRectangleArea(vector<int>& histogram) {
        int n = histogram.size();
        stack <int> a, ai;
    vector <int> left;
    left.push_back(1);
    a.push(histogram[0]);
    ai.push(1);
    for (int i = 1; i < n; i++) {
        if (histogram[i] > a.top()) {
            a.push(histogram[i]);
            if (ai.size() > 0) 
                left.push_back(i + 1 - ai.top());
            else
                left.push_back(i + 1);
            ai.push(i + 1);
        }
        else {
            while (a.size() > 0 && histogram[i] <= a.top()) {
                a.pop();
                ai.pop();
            }
            a.push(histogram[i]);
            if (ai.size() > 0) 
                left.push_back(i + 1 - ai.top());
            else
                left.push_back(i + 1);
            ai.push(i + 1);
        }
    }
    vector <int> right;
    stack <int> b, bi;
    right.push_back(1);
    b.push(histogram[n - 1]);
    bi.push(1);
    for (int i = n - 2; i >= 0; i--) {
        if (histogram[i] > b.top()) {
            b.push(histogram[i]);
            if (bi.size() > 0)
                right.push_back(n - i - bi.top());
            else
                right.push_back(n - i);
            bi.push(n - i);
        }
        else {
            while (b.size() > 0 && b.top() >= histogram[i]) {
                b.pop();
                bi.pop();
            }
            b.push(histogram[i]);
            if (bi.size() > 0)
                right.push_back(n - i - bi.top());
            else 
                right.push_back(n - i);
            bi.push(n - i);
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (histogram[i] * (left[i] + right[n - i - 1] - 1) > ans)
            ans = histogram[i] * (left[i] + right[n - i - 1] - 1);
    }
    return ans;
        
    }
};