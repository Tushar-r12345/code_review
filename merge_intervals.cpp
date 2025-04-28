/*

Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping 
intervals, and return an array of the non-overlapping intervals that cover all the intervals 
in the input.

Example 1:

Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlap, merge them into [1,6].
Example 2:

Input: intervals = [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.

*/

class Solution {
    public:
        vector<vector<int>> merge(vector<vector<int>>& intervals) {
            
            vector<vector<int>>mergeInterval;
            if(intervals.size()==0){
                return mergeInterval;
            }
            
            sort(intervals.begin(),intervals.end());
            vector<int>tempInterval=intervals[0];         // eg - let say that it is storing vector of interval size 2
            
            for(auto it:intervals){
                if(it[0]<=tempInterval[1]){
                    tempInterval[1]=max(it[1],tempInterval[1]);
                }
                
                else{
                    mergeInterval.push_back(tempInterval);
                    tempInterval=it;
                }
            }
            mergeInterval.push_back(tempInterval);
            return mergeInterval;
        }
    };