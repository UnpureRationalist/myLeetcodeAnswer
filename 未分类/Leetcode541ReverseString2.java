public class Leetcode541ReverseString2 {
    private void reverse(StringBuilder s, int start, int k) {
        int i = start, j = start + k - 1;
        while (i < j) {
            char temp = s.charAt(i);
            s.setCharAt(i, s.charAt(j));
            s.setCharAt(j, temp);
            ++i;
            --j;
        }
    }

    public String reverseStr(String s, int k) {
        StringBuilder stringBuilder = new StringBuilder(s);
        int index = 0;
        int n = s.length();
        int step = k << 1;
        int end = n - (n % step);
        for (; index < end; index += step) {
            reverse(stringBuilder, index, k);
        }
        int leftLength = Math.min(k, n - end);
        reverse(stringBuilder, end, leftLength);
        return stringBuilder.toString();
    }
}