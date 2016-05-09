import java.util.Arrays;
import java.util.Map;
import java.util.List;
import static java.util.Comparator.reverseOrder;
import static java.util.Map.Entry.comparingByValue;
import static java.util.stream.Collectors.counting;
import static java.util.stream.Collectors.groupingBy;
import static java.util.stream.Collectors.toList;

public class TopKFrequent {
  public static void main(String[] args) {
    System.out.println(topKFrequent(new int[]{1, 1, 1, 1, 2, 2, 2, 3, 3, 4}, 3));
  }

  public static List<Integer> topKFrequent(int[] nums, int k) {
    return Arrays
      .stream(nums)
      .boxed()
      .collect(groupingBy(x -> x, counting()))
      .entrySet()
      .stream()
      .sorted(comparingByValue(reverseOrder()))
      .limit(k)
      .map(Map.Entry::getKey)
      .collect(toList());
  }
}
