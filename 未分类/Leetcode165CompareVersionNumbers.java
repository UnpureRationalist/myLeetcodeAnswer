public class Leetcode165CompareVersionNumbers {
    private int comp(String subVersion1, String subVersion2) {
        int num1 = Integer.valueOf(subVersion1);
        int num2 = Integer.valueOf(subVersion2);
        return Integer.compare(num1, num2);
    }

    public int compareVersion(String version1, String version2) {
        String[] sub1 = version1.split("[.]");
        String[] sub2 = version2.split("[.]");
        for (String s : sub1) {
            System.out.println(s);
        }
        int len1 = sub1.length;
        int len2 = sub2.length;
        int i = 0;
        while (i < len1 && i < len2) {
            int res = comp(sub1[i], sub2[i]);
            if (res != 0) {
                return res;
            }
            ++i;
        }
        while (i < len1) {
            int res = comp(sub1[i], "0");
            if (res != 0) {
                return res;
            }
            ++i;
        }
        while (i < len2) {
            int res = comp("0", sub2[i]);
            if (res != 0) {
                return res;
            }
            ++i;
        }
        return 0;
    }

    public static void main(String[] args) {
        Leetcode165CompareVersionNumbers obj = new Leetcode165CompareVersionNumbers();
        System.out.println(obj.compareVersion("0.1", "1.1"));
    }
}
