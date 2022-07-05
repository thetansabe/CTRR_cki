#include<iostream>
#include<vector>
#include<stack>
#include<unordered_map>
using namespace std;
class Graph{
    
    int vertex; // number of vertices
    // adjacency list
    // we are using unordered_map to speed up the deletion of edges
    vector<unordered_map<int,int>> adj;
    
    public:
        
        // constructor to initialize graph
        // set number of vertices to v
        // initialize adjacency map for v nodes
        Graph(int v){
            vertex = v;
            adj = vector<unordered_map<int,int>>(v+1);
        }
        
        // add edge (u, v) to graph
        void addEdge(int u, int v){
            adj[u][v] = 1;
            adj[v][u] = 1;
        }
        
        // remove edge (u, v) from the graph
        void removeEdge(int v,int u){
            adj[v].erase(u);
            adj[u].erase(v);
        }
        
        // function checks if the graph contains a euler path/circuit or not
        // if the graph is valid, then it calls another function printEuler()
        // to print Euler Path or circuit
        void printEulerPathCircuit(){
            
            int odd = 0; // number of vertices with odd degree
            int oddVertex = 0; // it stores vertex with odd degree if it exists
            
            for(int i=1;i<=vertex;++i){
                if(adj[i].size()%2==1){
                    ++odd;
                    oddVertex = i;
                }
            }
            
            if(odd==0){
                // if the number of odd degree vertices is 0
                // the graph contains a Euler Circuit
                // we can use any vertex as the starting vertex
                cout<<"Euler Circuit: ";
                // print euler circuit with '1' as the starting vertex
                printEuler(1);
            }
            else if(odd==2){
                // if the number of odd degree vertices is 0
                // the graph contains a Euler Path
                // starting vertex should be of odd degree
                cout<<"Euler Path: ";
                printEuler(oddVertex);
            }
            else{
                cout<<"Euler Path/Circuit Doesn't Exist"<<endl;
            }
            
        }
        
        // the function to print euler path or circuit
        void printEuler(int v){
            
            stack<int> cpath;    // current path
            stack<int> epath;    // euler path
            
            cpath.push(v);        // euler path starts from v
            
            while(!cpath.empty()){
                int u = cpath.top();
                
                if(adj[u].size()==0){
                    // if all edges from u are visited
                    // pop u and push it to euler path    
                    epath.push(u);
                    cpath.pop();
                }
                else{
                    // if all edges from u are not visited
                    // select any edge (u, v)
                    // push v to current path and remove edge (u, v) from the graph
                    cpath.push(adj[u].begin()->first);
                    removeEdge(u,adj[u].begin()->first);
                }    
            }
            
            while(!epath.empty()){
                cout<<" "<<epath.top()<<" ";
                epath.pop();
            }
            
        }
        
};
int main()
{
    // graph G, containing 6 vertices from 1 to 6.
    Graph G(40);
    
    // adding edges to the graph
    // this graph is same as the graph we used in the above example
    // we are assuming graph is connected and undirected
    G.addEdge(1, 2);
    G.addEdge(1, 4);
    G.addEdge(1, 18);
    G.addEdge(1, 22);
    G.addEdge(2, 3);
    G.addEdge(2, 19);
    G.addEdge(2, 23);
    G.addEdge(3, 4);
    G.addEdge(3, 5);
    G.addEdge(3, 9);
    G.addEdge(4, 10);
    G.addEdge(4, 17);
    G.addEdge(5, 6);
    G.addEdge(5, 8);
    G.addEdge(5, 19);
    G.addEdge(6, 7);
    G.addEdge(6, 20);
    G.addEdge(6, 38);
    G.addEdge(7, 8);
    G.addEdge(7, 16);
    G.addEdge(7, 38);
    G.addEdge(8, 9);
    G.addEdge(8, 15);
    G.addEdge(9, 10);
    G.addEdge(9, 14);
    G.addEdge(9, 14);
    G.addEdge(10, 11);
    G.addEdge(10, 13);
    G.addEdge(11, 12);
    G.addEdge(11, 17);
    G.addEdge(11, 27);
    G.addEdge(12, 13);
    G.addEdge(12, 26);
    G.addEdge(12, 39);
    G.addEdge(13, 14);
    G.addEdge(13, 39);
    G.addEdge(14, 15);
    G.addEdge(14, 39);
    G.addEdge(15, 16);
    G.addEdge(15, 39);
    G.addEdge(16, 38);
    G.addEdge(16, 39);
    G.addEdge(17, 18);
    G.addEdge(17, 28);
    G.addEdge(18, 21);
    G.addEdge(18, 29);
    G.addEdge(19, 20);
    G.addEdge(19, 24);
    G.addEdge(20, 25);
    G.addEdge(20, 38);
    G.addEdge(21, 22);
    G.addEdge(21, 30);
    G.addEdge(21, 32);
    G.addEdge(22, 23);
    G.addEdge(22, 33);
    G.addEdge(23, 24);
    G.addEdge(23, 34);
    G.addEdge(24, 25);
    G.addEdge(24, 35);
    G.addEdge(25, 36);
    G.addEdge(25, 38);
    G.addEdge(26, 27);
    G.addEdge(26, 39);
    G.addEdge(26, 40);
    G.addEdge(27, 28);
    G.addEdge(27, 40);
    G.addEdge(28, 29);
    G.addEdge(28, 40);
    G.addEdge(29, 30);
    G.addEdge(29, 40);
    G.addEdge(30, 31);
    G.addEdge(30, 40);
    G.addEdge(31, 32);
    G.addEdge(31, 37);
    G.addEdge(31, 40);
    G.addEdge(32, 33);
    G.addEdge(32, 37);
    G.addEdge(33, 34);
    G.addEdge(33, 37);
    G.addEdge(34, 35);
    G.addEdge(34, 37);
    G.addEdge(35, 36);
    G.addEdge(35, 37);
    G.addEdge(36, 37);
    G.addEdge(36, 38);

   
    G.printEulerPathCircuit();
}