public class Solution {
    public int NumberOfSpecialChars(string word) {
        HashSet<char> lowerSet = new HashSet<char>();
        HashSet<char> upperSet = new HashSet<char>();

        foreach(char ch in word){
            if(char.IsLower(ch)){
                lowerSet.Add(ch);
            }
            else{
                upperSet.Add(ch);
            }
        }

        int specialCount = 0;
        foreach(char ch in lowerSet){
            if(upperSet.Contains(char.ToUpper(ch))){
                specialCount++;
            }
        }

        return specialCount;
    }
}