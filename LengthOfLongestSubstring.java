import java.util.HashSet;

public class LengthOfLongestSubstring {
  public static int lengthOfLongestSubstring(String s) {
    if (s.length() == 0) return 0;
    if (s.length() == 1) return 1;

    int max = 0;
    int count = 0;
    HashSet<Character> occur = new HashSet();

    for (int i = 0; i < s.length(); i++) {
      Character current = s.charAt(i);
      if (occur.contains(current)) {
        occur = new HashSet();
        if (count > max) max = count;
        i -= count;
        count = 0;
      } else {
        count++;
        occur.add(current);
      }
    }
    if (count > max) max = count;
    return max;
  }
}
