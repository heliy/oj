# Definition for an interval.
# class Interval:
#     def __init__(self, s=0, e=0):
#         self.start = s
#         self.end = e

class Solution:
    # @param {Interval[]} intervals
    # @return {Interval[]}
    def merge(self, intervals):
        def key(i):
            return i.start
        if not len(intervals):
            return []
        intervals.sort(key=key)
        res = [intervals[0]]
        for i in range(1, len(intervals)):
            if res[-1].end >= intervals[i].start:
                if intervals[i].end > res[-1].end:
                    res[-1].end = intervals[i].end
            else:
                res.append(intervals[i])
        return res
