public class Leetcode1646GetGenerateArrayMaxElement {
    public int getMaximumGenerated(int n) {
        if (n == 0)
            return 0;
        int[] array = new int[n + 1];
        array[0] = 0;
        array[1] = 1;
        int maxValue = 1;
        for (int i = 2; i <= n; ++i) {
            array[i] = array[i / 2];
            if (i % 2 == 1) {
                array[i] += array[i / 2 + 1];
            }
            maxValue = Math.max(array[i], maxValue);
        }
        return maxValue;
    }

    public static void main(String[] args) {
        Leetcode1646GetGenerateArrayMaxElement obj = new Leetcode1646GetGenerateArrayMaxElement();
        System.out.println(obj.getMaximumGenerated(100));
    }
}
