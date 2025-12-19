from typing import *
class Solution:
    def insert(self, intervals: List[List[int]], newInterval: List[int]) -> List[List[int]]:
        starts:list[int] = []
        ends:list[int] = []
        ans = []
        n = len(intervals)
        for i in intervals :
            starts.append(i[0])
            ends.append(i[1])
            
        i:int = 0
        j:int = 0
        
        while i < n :
            if newInterval[0] <= ends[i]:
                if newInterval[1] >= starts[j]:
                    ans.append([min(starts[j] , ends[j]) , max(starts[i] , ends[i])])
            else :
                ans.append([starts[i] , ends[j]])
                    
                
         