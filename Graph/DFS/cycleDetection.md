1. For undirected graph
- maintaining a visited array is enough to find if we get a back edge.
- to get the cycle itself just keep a parent array
-  Following simple loop using the parent array can give the answer.
    ```
    while(start!=end){
			ans.push_back(start);
			start=parent[start];
    }
    ans.push_back(end);
    ans.push_back(start);
    ```
- It's important to exit early as soon as you find a cycle in a graph traversal to avoid potential runtime errors and unnecessary computations.
     1
    / \
    2   3
    If there's a cycle that starts from node 1, goes to node 2, and then returns to 1 through some route, when DFS finishes exploring node 2 and returns to node 1, it will then proceed to node 3. If node 3 is already visited, another cycle is detected. This situation may set cycleStart = 1 and cycleEnd = 3. Since node 1 has no parent (parent[1] is not set), accessing it can cause runtime errors.

    To avoid these issues, it's simpler and safer to exit immediately when a cycle is detected. This avoids the complexity of handling such edge cases and ensures the program runs correctly without unexpected errors.

2. For directed Graph
- Directed graphs need to maintain a inStack array to check if the nodes we are
  exploring are part of current dfs stack .
  As we may have case where a previously visited node may be visited again but without any cycle formation.