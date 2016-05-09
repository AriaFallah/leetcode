import java.util.HashMap;
import java.util.Arrays;

public class TwoSum {
  public static int[] twoSum(int[] nums, int target) {
    HashMap<Integer, Integer> m = new HashMap();
    for (int i = 0; i < nums.length; i++) {
      Integer num = nums[i];

      if (m.get(num) == null) {
        m.put(num, i);
      }

      Integer requiredIndex = m.get(target - num);
      if (requiredIndex != null && requiredIndex != i) {
        return new int[]{ requiredIndex + 1, i + 1 };
      }
    }

    return new int[]{};
  }

  public static void main(String[] args) {
    int[] result = twoSum(new int[]{ 3, 4, 2 }, 6);
    System.out.println(Arrays.toString(result));
  }
}
