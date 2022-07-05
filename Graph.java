import java.io.*;
import java.util.*;
import java.util.LinkedList;

// This class represents an undirected graph using adjacency list
class Graph {
    private int V; // No. of vertices
    private LinkedList<Integer> adj[]; // Adjacency List

    // Constructor
    Graph(int v) {
        V = v;
        adj = new LinkedList[v];
        for (int i = 0; i < v; ++i)
            adj[i] = new LinkedList();
    }

    // Function to add an edge into the graph
    void addEdge(int v, int w) {
        adj[v].add(w);
        adj[w].add(v); // Graph is undirected
    }

    // Assigns colors (starting from 0) to all vertices and
    // prints the assignment of colors
    void greedyColoring() {
        int result[] = new int[V];

        // Initialize all vertices as unassigned
        Arrays.fill(result, -1);

        // Assign the first color to first vertex
        result[0] = 0;

        // A temporary array to store the available colors. False
        // value of available[cr] would mean that the color cr is
        // assigned to one of its adjacent vertices
        boolean available[] = new boolean[V];

        // Initially, all colors are available
        Arrays.fill(available, true);

        // Assign colors to remaining V-1 vertices
        for (int u = 1; u < V; u++) {
            // Process all adjacent vertices and flag their colors
            // as unavailable
            Iterator<Integer> it = adj[u].iterator();
            while (it.hasNext()) {
                int i = it.next();
                if (result[i] != -1)
                    available[result[i]] = false;
            }

            // Find the first available color
            int cr;
            for (cr = 0; cr < V; cr++) {
                if (available[cr])
                    break;
            }

            result[u] = cr; // Assign the found color

            // Reset the values back to true for the next iteration
            Arrays.fill(available, true);
        }

        // print the result
        for (int u = 0; u < V; u++)
            System.out.println("Vertex " + u + " --->  Color "
                    + result[u]);
    }

    // Driver method
    public static void main(String args[]) {
        Graph g1 = new Graph(34);
        g1.addEdge(0, 1);
        g1.addEdge(1, 2);
        g1.addEdge(1, 4);
        g1.addEdge(1, 6);
        g1.addEdge(1, 7);
        g1.addEdge(1, 10);
        g1.addEdge(2, 7);
        g1.addEdge(3, 10);
        g1.addEdge(4, 5);
        g1.addEdge(5, 6);
        g1.addEdge(6, 7);
        g1.addEdge(8, 9);
        g1.addEdge(8, 10);
        g1.addEdge(8, 26);
        g1.addEdge(9, 10);
        g1.addEdge(9, 11);
        g1.addEdge(9, 25);
        g1.addEdge(9, 26);
        g1.addEdge(10, 11);
        g1.addEdge(11, 25);
        g1.addEdge(11, 13);
        g1.addEdge(11, 14);
        g1.addEdge(12, 29);
        g1.addEdge(12, 30);
        g1.addEdge(12, 32);
        g1.addEdge(13, 15);
        g1.addEdge(13, 25);
        g1.addEdge(13, 16);
        g1.addEdge(13, 17);
        g1.addEdge(13, 14);
        g1.addEdge(14, 17);
        g1.addEdge(14, 19);
        g1.addEdge(15, 22);
        g1.addEdge(15, 24);
        g1.addEdge(15, 25);
        g1.addEdge(15, 16);
        g1.addEdge(16, 17);
        g1.addEdge(17, 19);
        g1.addEdge(17, 20);
        g1.addEdge(18, 19);
        g1.addEdge(19, 20);
        g1.addEdge(21, 23);
        g1.addEdge(22, 23);
        g1.addEdge(23, 27);
        g1.addEdge(23, 24);
        g1.addEdge(24, 25);
        g1.addEdge(24, 26);
        g1.addEdge(24, 27);
        g1.addEdge(25, 26);
        g1.addEdge(26, 27);
        g1.addEdge(26, 28);
        g1.addEdge(26, 29);
        g1.addEdge(26, 31);
        g1.addEdge(26, 32);
        g1.addEdge(27, 28);
        g1.addEdge(27, 29);
        g1.addEdge(27, 30);
        g1.addEdge(28, 29);
        g1.addEdge(29, 30);
        g1.addEdge(29, 31);
        g1.addEdge(29, 32);
        g1.addEdge(30, 32);
        g1.addEdge(30, 33);
        g1.addEdge(31, 32);
        g1.addEdge(32, 33);
        System.out.println("Coloring of graph 1");
        g1.greedyColoring();
    }
}