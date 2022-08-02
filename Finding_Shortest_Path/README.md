There are many ways to find the shortest path a node to any vertices in a graph.



One of the most popular algorithms to solve the shortest path problem is to use Dijkstra's Algorithm.

Dijkstra's algorithm is a greedy algorithm and it looks for the shortest current path.



![DIJ5](https://user-images.githubusercontent.com/108073642/182383997-42009efc-003c-482a-b1b3-4d1e9fa17d44.jpg)
https://stackabuse.com/courses/graphs-in-python-theory-and-implementation/lessons/dijkstras-algorithm/



Dijkstra's algorithm is based on the assumption that any subpath of the shortest path between vertice is also the shortest path from the starting node.



Dijkstra’s algorithm works with a relaxation where an approximation of the accurate distance is steadily displaced by more suitable values until the shortest distance is achieved.




Result of Dijstra's Algorithm


Also, you cannot use Dijkstra's algorithm where there are negative weights or connections between nodes and vertices.



The procedure for Dijkstra's algorithm is following:

1. Make all the values of nodes unvisited or INF numbers.

2. Choose starting node and put a current distance as 0.

3. For the current node, find unvisited neighbor nodes.

4. Compare distances by adding the current distance of the current node to the weight of the edge and keep the smallest value or the connection.

5. Consider all of the unvisited neighbors of the current node

6. If it reaches the destination node then stop and return the array or list that stores the shortest path information. 






There are two storage ways to implement Dijkstra's algorithm.

The first is using a 2D array to store the shortest paths or you can use a heap and priority queue.



I implemented Dijkstra's algorithm using a queue.

void BFS(int iWantedNode) {
priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > qSaveCount;
iResultSaveArray[iWantedNode] = 0;
qSaveCount.push({ 0, iWantedNode});


while (!qSaveCount.empty()) {

    int iCurrentNode = qSaveCount.top().second;
    int iCurrentWeight = qSaveCount.top().first;
    qSaveCount.pop();
    if (iResultSaveArray[iCurrentNode] < iCurrentWeight) {
	    continue;
    }    

    for (int i = 0; i < iStoreConnectionArray[iCurrentNode].size(); i++) {

	    int iNextNode = iStoreConnectionArray[iCurrentNode][i].first;
	    int iNextWeight = iStoreConnectionArray[iCurrentNode][i].second;

	    if (iResultSaveArray[iNextNode] > iNextWeight + iCurrentWeight) {
		    iResultSaveArray[iNextNode] = iNextWeight + iCurrentWeight;
		    qSaveCount.push(make_pair(iResultSaveArray[iNextNode],iNextNode));
	    }
    }

}







# In Dijkstra's algorithm, the shortest distance between two vertices might not include all the vertices of the graph.









************************************************************************************************



References :

https://www.geeksforgeeks.org/dijkstras-shortest-path-algorithm-greedy-algo-7/

https://www.analyticssteps.com/blogs/dijkstras-algorithm-shortest-path-algorithm



My GitHub : https://github.com/AdvancedUno/AlgorithmProblems

