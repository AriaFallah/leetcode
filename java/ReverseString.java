public class ReverseString {
  public static void main(String[] args) {
    System.out.println(reverseString("hello"));
  }

  public static String reverseString(String s) {
    int begin = 0;
    int end = s.length() - 1;
    char[] str = s.toCharArray();
    char temp;

    while (begin < end) {
      temp = str[end];
      str[end--] = str[begin];
      str[begin++] = temp;
    }

    return new String(str);
  }
}
