import java.util.Map;
import java.util.List;
import java.util.ArrayList;
import java.util.HashMap;


public class TopKFrequent {
  public static void main(String[] args) {
    System.out.println(topKFrequent(new int[]{1, 1, 1, 1, 2, 2, 2, 3, 3, 4}, 3));
  }

  public static List<Integer> topKFrequent(int[] nums, int k) {
    List<Integer> myList = new ArrayList<>();
    HashMap<Integer, Integer> map = new HashMap<>();

    for (int n : nums) {
      if (!map.containsKey(n)) map.put(n, 1);
      else map.put(n, map.get(n) + 1);
    }

    map.entrySet().stream()
      .sorted(Map.Entry.<Integer, Integer>comparingByValue().reversed())
      .limit(k)
      .forEach((entry) -> myList.add(entry.getKey()));

    return myList;
  }
}
