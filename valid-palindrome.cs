using System.Text;

public class Solution
{
    static private string PreProcessing(string s)
    {
        StringBuilder builder = new StringBuilder();
        foreach (char c in s)
            if (char.IsLetterOrDigit(c))
                builder.Append(char.ToLower(c));
        return builder.ToString();
    }

    public bool IsPalindrome(string s)
    {
        if (s == null || s.Length == 0)
            return true;
        string Temp = PreProcessing(s);
        int i = 0, j = Temp.Length - 1;
        while (i < j)
        {
            if (Temp[j--] != Temp[i++])
                return false;
        }
        return true;
    }
}