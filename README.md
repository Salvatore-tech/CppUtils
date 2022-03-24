# CppUtils
C++ utility used in the projects:
- https://github.com/Salvatore-tech/HashGraph
- https://github.com/Salvatore-tech/WaterPipes    


**graphnode:** static lib, implements a generic node of the graph of type T and the operations of adding/finding/removing edges.  
**iograph:** static lib, read an input text file containing the graph structure, validates it and returns a buffer implemented as a map.  
**hashing_strategy:** offers two different hashing strategies for an hash table, the linear probing and the double hashing.
**graph-generator:** executable to generate a graph and write to a .txt file. It accepts two args plus one optional from cmd:  
N (number of nodes) E (number of edges) P (percentage of nodes directly connected to the source).  
Ex.  
IN ./graph-generator 1000 10000 10  
OUT Insert the maximum value to generate:  
IN 5000  

=> A graph of 1000 nodes and 5000 edges has been generated with 10% of nodes directly connected to the source. 


