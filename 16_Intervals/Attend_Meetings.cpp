#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Interval {
public:
    int start, end;
    Interval(int start, int end) {
        this->start = start;
        this->end = end;
    }
};

class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const auto& x, const auto& y){
            return x.start < y.start;
        });

        for(int i = 1; i < intervals.size(); i++){
            if(intervals[i].start < intervals[i - 1].end){
                return false;
            }
        }

        return true;
    }
};