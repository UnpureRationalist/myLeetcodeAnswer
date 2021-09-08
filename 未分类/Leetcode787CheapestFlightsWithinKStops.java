import java.util.Arrays;

public class Leetcode787CheapestFlightsWithinKStops {
    private int ans = Integer.MAX_VALUE;
    private int[][] flights;
    private int[] visited;
    private int n;
    private int k;

    public int findCheapestPrice(int n, int[][] flights, int src, int dst, int k) {
        this.n = n;
        this.flights = new int[n][n];
        for (int i = 0; i < flights.length; ++i) {
            this.flights[flights[i][0]][flights[i][1]] = flights[i][2];
        }
        visited = new int[n];
        this.k = k + 1;
        visited[src] = 1;
        dfs(src, dst, 0, 0);
        return ans == Integer.MAX_VALUE ? -1 : ans;
    }

    private void dfs(int start, int end, int steps, int cost) {
        if (steps > k || cost > ans)
            return;
        if (start == end) {
            ans = Math.min(ans, cost);
            return;
        }

        for (int i = 0; i < n; ++i) {
            if (flights[start][i] != 0 && visited[i] == 0) {
                visited[i] = 1;
                dfs(i, end, steps + 1, cost + flights[start][i]);
                visited[i] = 0;
            }
        }
    }
}

class Solution {
    public int findCheapestPrice(int n, int[][] flights, int src, int dst, int k) {
        final int INF = 10000 * 101 + 1;
        int[][] f = new int[k + 2][n];
        for (int i = 0; i < k + 2; ++i) {
            Arrays.fill(f[i], INF);
        }
        f[0][src] = 0;
        for (int t = 1; t <= k + 1; ++t) {
            for (int[] flight : flights) {
                int j = flight[0], i = flight[1], cost = flight[2];
                f[t][i] = Math.min(f[t][i], f[t - 1][j] + cost);
            }
        }
        int ans = INF;
        for (int t = 1; t <= k + 1; ++t) {
            ans = Math.min(ans, f[t][dst]);
        }
        return ans == INF ? -1 : ans;
    }
}