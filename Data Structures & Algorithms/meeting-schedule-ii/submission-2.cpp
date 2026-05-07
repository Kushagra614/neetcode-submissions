class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        if(intervals.empty()) return 0;

        int n = intervals.size();

        priority_queue<int, vector<int>, greater<int>> pq;

        sort(intervals.begin(), intervals.end(), [](const Interval& a, const Interval& b){
            return a.start < b.start;
        });

        pq.push(intervals[0].end);

        for(int i = 1; i < n; i++)
        {
            if(pq.top() <= intervals[i].start)
            {
                pq.pop();
            }
            pq.push(intervals[i].end);
            
        }

        return pq.size();
    }
};