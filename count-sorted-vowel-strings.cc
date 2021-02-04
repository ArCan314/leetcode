#include <vector>
#include <array>

class Solution
{
public:
    static constexpr int kE = 0, kI = 1, kO = 2, kU = 3;

    int countVowelStrings(int n)
    {
        return countVowelStringsLUT(n);
    }

    int countVowelStringsDP(int n)
    {
        int dp[51][4] = {};
        for (auto &cnt : dp[1])
            cnt = 1;

        for (int i = 2; i <= n; i++)
        {
            dp[i][kE] = 1 + dp[i - 1][kE];
            dp[i][kI] = 1 + dp[i - 1][kE] + dp[i - 1][kI];
            dp[i][kO] = 1 + dp[i - 1][kE] + dp[i - 1][kI] + dp[i - 1][kO];
            dp[i][kU] = 1 + dp[i - 1][kE] + dp[i - 1][kI] + dp[i - 1][kO] + dp[i - 1][kU];
        }

        int sum = 0;
        for (int i = 0; i < 4; i++)
            sum += dp[n][i];

        return sum + 1;
    }

    int countVowelStringsOpt(int n)
    {
        int dp[4] = {1, 1, 1, 1};

        for (int i = 2; i <= n; i++)
        {
            int a, b, c, d;
            a = dp[0] + 1;
            b = dp[0] + dp[1] + 1;
            c = dp[0] + dp[1] + dp[2] + 1;
            d = dp[0] + dp[1] + dp[2] + dp[3] + 1;

            dp[0] = a;
            dp[1] = b;
            dp[2] = c;
            dp[3] = d;
        }

        return dp[0] + dp[1] + dp[2] + dp[3] + 1;
    }

    int countVowelStringsLUT(int n)
    {
        constexpr static int lut[] = {5, 15, 35, 70, 126, 210, 330, 495, 715, 1001, 1365, 1820, 2380, 3060, 3876, 4845, 5985, 7315, 8855, 10626, 12650, 14950, 17550, 20475, 23751, 27405, 31465, 35960, 40920, 46376, 52360, 58905, 66045, 73815, 82251, 91390, 101270, 111930, 123410, 135751, 148995, 163185, 178365, 194580, 211876, 230300, 249900, 270725, 292825, 316251};
        return lut[n - 1];
    }
};