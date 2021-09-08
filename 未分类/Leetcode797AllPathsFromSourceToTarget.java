import java.util.ArrayList;
import java.util.List;

public class Leetcode797AllPathsFromSourceToTarget {
    private List<List<Integer>> res = new ArrayList<>();
    private int[][] graph;
    private int n;
    private int[] visited;

    public List<List<Integer>> allPathsSourceTarget(int[][] graph) {
        this.graph = graph;
        n = graph.length;
        visited = new int[n];
        List<Integer> path = new ArrayList<>();
        path.add(0);
        visited[0] = 1;
        dfs(0, n - 1, path);
        return res;
    }

    private void dfs(int start, int end, List<Integer> path) {
        if (start == end) {
            res.add(new ArrayList<>(path));
            return;
        }
        for (int i = 0; i < graph[start].length; ++i) {
            if (visited[graph[start][i]] == 0) {
                visited[graph[start][i]] = 1;
                path.add(graph[start][i]);
                dfs(graph[start][i], end, path);
                path.remove(path.get(path.size() - 1));
                visited[graph[start][i]] = 0;
            }
        }
    }
}
