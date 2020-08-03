from typing import List


class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        d = {x: ind for ind, x in enumerate(nums)}

        for ind, val in enumerate(nums):
            if (target - val == val and d[val] != ind):
                return [ind, d[val]]
            elif (target - val != val and (target - val) in d):
                return [ind, d[target - val]]





        