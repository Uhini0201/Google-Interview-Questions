'''
Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).

You may assume that the intervals were initially sorted according to their start times.

Example 1:

Given intervals [1,3],[6,9] insert and merge [2,5] would result in [1,5],[6,9].

Example 2:

Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] would result in [1,2],[3,10],[12,16].

This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].

Make sure the returned intervals are also sorted.
'''

# Code

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
vector<Interval> Solution::insert(vector<Interval> &intervals, Interval newInterval) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    vector<Interval> result;
    if(intervals.size()==0){
        //vector<Interval>ans;
        result.push_back(newInterval);
        return result;
    }
    if(newInterval.start>newInterval.end)
        swap(newInterval.start,newInterval.end);
    Interval ans=newInterval;
    int ind=-1;
    for(int i=0;i<intervals.size();i++){
        if(max(intervals[i].start,newInterval.start)<=min(intervals[i].end,newInterval.end)){
            ans={min(intervals[i].start,newInterval.start),max(intervals[i].end,newInterval.end)};
        }
        else{
            if(ans.end<intervals[i].start){
                result.push_back(ans);
                ind=i;break;
            }
            else{
                result.push_back(intervals[i]);
            }
        }
    }
    if(ind==-1){
        result.push_back(ans);
    }
    else{
        for(int i=ind;i<intervals.size();i++){
            result.push_back(intervals[i]);
        }
    }
    // for(int i=1;i<=intervals.size();i++){
    //     result[i-1]=result[i];
    // }
    return result;
}
