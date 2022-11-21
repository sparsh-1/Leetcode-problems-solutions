// https://leetcode.com/problems/my-calendar-i/
// I have added the elements as they are coming and am also checking is start lies in between sofe interval or end lies
// in between some interval or start lies outside some interval and end lies between that interval
// if any condition above satisfies I return false otherwise true
// Time Complexity - O(n^2) Space Complexity - O(n)
class MyCalendar {
public:
    vector<vector<int>> booking;
    MyCalendar() {
        booking = booking;
    }
    
    bool book(int start, int end) {
        if (booking.size() == 0) {
            booking.push_back({start, end});
            return true;
        }
        for (int i = 0; i < booking.size(); i++) {
            if ((end > booking[i][0] && end <= booking[i][1]) || (start >= booking[i][0] && start < booking[i][1]) || (start < booking[i][0] && end > booking[i][0]))
                return false;
        }
        booking.push_back({start, end});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */


