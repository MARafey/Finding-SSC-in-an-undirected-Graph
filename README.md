# Finding largest SSC in an undirected Graph

The given code is an implementation of the Kosaraju's algorithm for finding strongly connected components in a directed graph.

The main function revDFS performs a Depth First Search (DFS) on a reversed graph, starting from a given vertex start. It takes in the following parameters:

* start: the starting vertex
* size: the total number of vertices in the graph
* original: a pointer to the original graph
* already_visited: a boolean array to keep track of which vertices have already been visited
* tempsize: a reference to a variable to keep track of the size of the strongly connected component
The function first marks the starting vertex as visited and increases the size of the strongly connected component by 1. It then traverses through all the vertices adjacent to the starting vertex and performs a recursive DFS on each unvisited adjacent vertex.

The function Depth_first_Search is used to perform a DFS on the original graph. It takes in the following parameters:

* start: the starting vertex
* size: the total number of vertices in the graph
* original: a pointer to the original graph
* already_visited: a boolean array to keep track of which vertices have already been visited
* DFS_getter: a pointer to a stack to store the vertices in the order in which they are visited
The function marks the starting vertex as visited and then traverses through all the vertices adjacent to the starting vertex. For each unvisited adjacent vertex, it performs a recursive DFS and then adds the starting vertex to the stack DFS_getter.

The main function Kosaraju first creates a reversed graph using the reverse_of_graph function. It then performs a DFS on the original graph using the Depth_first_Search function and stores the vertices in the order in which they are visited in the stack DFS_getter. It then performs a DFS on the reversed graph for each vertex in the stack DFS_getter that has not already been visited, and computes the size of each strongly connected component using the revDFS function. Finally, it returns an array components containing the size of each strongly connected component.
