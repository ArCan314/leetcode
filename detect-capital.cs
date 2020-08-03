public class Solution
{
    public bool DetectCapitalUse(string word)
    {
        bool IsFirstCapital = char.IsUpper(word[0]);
        int CapitalCount = 0;
        foreach (var c in word)
            CapitalCount += char.IsUpper(c) ? 1 : 0;
        return CapitalCount == 0 || (CapitalCount == 1 && IsFirstCapital) || CapitalCount == word.Length;
    }
}