#function to check if the vertex v can be
# added at index 'pos'
def isSafe(v,graph,path,pos):
 #Check if this vertex is an adjacent vertex of the 
 # previously added vertex
    if (graph[path[pos-1]][v] == 0):
        return False
      
# Check if the vertex has already been included.  
    for i in range(pos):
        if (path[i]==v):
            return False
            
    return True



# A recursive function to solve hamiltonian cycle 
#  problem
def hamPath(graph, path, pos):
    if (pos = N):
# if there is an edge from the last included vertex 
# to the first node
        if (graph[path[pos-1]][path[0]] == 1):
            return True
        else:
  
            return False
# Try different vertices as a next candidate in 
# Hamiltonian Cycle.
    for v in range(1,V):
        if (isSafe(v,graph,path,pos):
            path[pos] = v
            if (hamPath(graph,path,pos+1) == True): 
                return True
                
            path[pos] = -1
        
    return False



#This function solves the Hamiltonian Cycle problem
#  using Backtracking.

def BookProb(graph, N)
    path = N*[-1]
     
    path[0] = 0
    if (hamPath(graph,path,1) == False):
        print "No solution"
        return False
     
    for i in range(N):    
         print(path[i])
         print(" ")
         
    return True
     
      