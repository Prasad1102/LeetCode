// 3306. Count of Substrings Containing Every Vowel and K Consonants II
class Solution {
  public:
   long long countOfSubstrings(string word, int k) {
     return substringsWithAtMost(word, k) - substringsWithAtMost(word, k - 1);
   }
 
  private:
   long substringsWithAtMost(const string& word, int k) {
     if (k == -1)
       return 0;
 
     long res = 0;
     int vowels = 0;
     int uniqueVowels = 0;
     unordered_map<char, int> vowelLastSeen;
 
     for (int l = 0, r = 0; r < word.length(); ++r) {
       if (isVowel(word[r])) {
         ++vowels;
         if (const auto it = vowelLastSeen.find(word[r]);
             it == vowelLastSeen.end() || it->second < l)
           ++uniqueVowels;
         vowelLastSeen[word[r]] = r;
       }
       while (r - l + 1 - vowels > k) {
         if (isVowel(word[l])) {
           --vowels;
           if (vowelLastSeen[word[l]] == l)
             --uniqueVowels;
         }
         ++l;
       }
       if (uniqueVowels == 5)
         res += min({vowelLastSeen['a'], vowelLastSeen['e'], vowelLastSeen['i'],
                     vowelLastSeen['o'], vowelLastSeen['u']}) -
                l + 1;
     }
 
     return res;
   }
 
   bool isVowel(char c) {
     static constexpr string_view kVowels = "aeiou";
     return kVowels.find(c) != string_view::npos;
   }
 };