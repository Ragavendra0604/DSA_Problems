public class Solution {
    public int NumberOfSpecialChars(string word) {
        var lowerSet = new HashSet<char>(word.Where(char.IsLower));
        var upperSet = new HashSet<char>(word.Where(char.IsUpper));

        return lowerSet.Count(ch => upperSet.Contains(char.ToUpper(ch)));
    }
}