class Solution:
    def reverse(self, x: int) -> int:
        res = [c for c in reversed([c for c in str(abs(x))])]
        z = ''
        for c in res:
            z = z + c
        z = int(z)
        if x < 0:
            z *= -1

        if z < -2147483648 or z > 2147483647:
            return 0
        return z
