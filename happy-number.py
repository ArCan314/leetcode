happy_nums = set()
happy_nums.add(1)


class Solution:
    def sqrSum(self, n: int) -> int:
        res = 0
        for c in str(n):
            res += int(c)**2
        return res

    def isHappy(self, n: int) -> bool:
        global happy_nums
        temp = set()

        while True:
            sqr = self.sqrSum(n)
            if sqr in happy_nums:
                happy_nums = happy_nums.union(temp)
                return True
            elif sqr in temp:
                return False
            else:
                temp.add(n)
                n = sqr
