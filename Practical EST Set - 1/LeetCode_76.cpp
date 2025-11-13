#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

string minWindow(string s, string t) {
  if (s.length() < t.length()) {
      return "";
  }

  unordered_map<char, int> charCount;
  for (char ch : t) {
      charCount[ch]++;
  }

  int m = t.length();
  int minWindow[2] = {0, INT_MAX};
  int startIndex = 0;

  for (int i = 0; i < s.length(); i++) {
      char ch = s[i];
      if (charCount.find(ch) != charCount.end() && charCount[ch] > 0) {
          m--;
      }
      charCount[ch]--;

      if (m == 0) {
          while (true) {
              char charAtStart = s[startIndex];
              if (charCount.find(charAtStart) != charCount.end() &&
                  charCount[charAtStart] == 0) {
                  break;
              }
              charCount[charAtStart]++;
              startIndex++;
          }

          if (i - startIndex < minWindow[1] - minWindow[0]) {
              minWindow[0] = startIndex;
              minWindow[1] = i;
          }

          charCount[s[startIndex]]++;
          m++;
          startIndex++;
      }
  }

  return minWindow[1] >= s.length()
             ? ""
             : s.substr(minWindow[0], minWindow[1] - minWindow[0] + 1);
}



int main() {
  string s = "ADOBECODEBANC", t = "ABC";
  string ans = minWindow(s, t);
  cout<<ans<<endl;
  return 0;
}
