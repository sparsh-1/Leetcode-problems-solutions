// https://leetcode.com/problems/unique-number-of-occurrences/
// What I have done here is that I have used a hash map to first store the frequency of different elements
// then I have used that frequency and inserted them into set whicle checking whether it is already present in set or not
// If I found some frequency already present in the set then I will return false otherwise true;
// Time Complexity - O(nlgn), Space Complexity - O(n)
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int, int> occur;
        for (int i = 0; i < arr.size(); i++)
            occur[arr[i]]++;
        set<int> uniq;
        for (auto i: occur) {
            if (uniq.find(i.second) != uniq.end())
                return false;
            uniq.insert(i.second);
        }
        return true;
    }
};

// We can also use unordered set and unordered map to reduce time complexity to O(n).

// Now another approach is that the number can range between -1000 to 1000 only and the array size is only 1000.
// So we can store count of each element in an array adding 1000 to index value and then using counting sort on that array 
// to store frequency of that count, if we get any count to be greater than 1 then answer is false.