import java.util.HashSet;

public class SingleNumber3 {
  public static int[] singleNumber(int[] nums) {
    HashSet<Integer> hs = new HashSet<>();
    for (int n : nums) {
      if (hs.contains(n)) hs.remove(n);
      else hs.add(n);
    }
    Object[] unique = hs.toArray();
    return new int[]{ (int)unique[0], (int)unique[1] };
  }
}
