# Tower_of_Hanoi_AI

This project is able to solve any Tower of Hanoi problem with 3 pillars and any amount of disks.

Artificial Intelligence can be divided into two steps: Representation and Search.

For any problem you need to represent it. In this case my Initial State(IS) is all the disks stacked on the left side, and my Solution State(SS) is all the disks stacked on the right side. And my operands to go from one state to another consists of being able to move any disk from any pillar to an empty pillar or to a pillar that has a bigger disk on it.

After you represent a problem you can search it using any searching algorithm. They all have their pros and cons but in this case I am using breadth-first-search(BFS), although arguably this is not the best one. To search the problem you start at the initial state, then all the successors of the initial state, which you get through the operands explained above, are connected to that state. This creates a graph where you can perform your searching algorithm on until you find the solution state. You want to keep track of the paths in order to know what steps to take from the IS to the SS.

Here is the pseudo code using BFS:

    Check if the initial state is the solution state and if it is solution is trivial return anything (e.g. throw an exception)
    
    Create an OPEN queue with the initial node = (IS)
  
    OUTCOME=False
   
    While OPEN list is not empty or OUTCOME is false
    
        Remove the first node from OPEN list, N
       
        If N has successors then Generate the successors of N

        For every successor
                
                Check if successor/state has already been visited if it has continue
                
                Visit successor/state
                
                Create pointers from the successors/state to N
              
                If a successor is a goal node then OUTCOME=True
               
                    
                
                Else add successors at end of OPEN list
               
    If OUTCOME = True then return the path from IS to successor
   
    Else there is no solution return anything (e.g. throw an exception)



## Getting Started

To run this program and test it you can simply clone this repository and compile all cpp files and run the executable.

g++ src/*.cpp -o program && ./program

make sure you are in the cloned directory as the above command is a relative path.

## Moving Forward

Moving forward I want to create an interface where with any IS and any SS and any operands it can find a solution to the problem meaning the path form the IS to the SS using any searching algorithm you would like.

The link to that future github repo will be pasted here when it is available: 


### Prerequisites

g++ is the only prerequisite. You can also use gcc.


### And code

You can modify the Constructor of the HanoiTower object to have any initial state you would like.

You can modify the getSolutionState method of the HanoiTower object to have any solution state you would like.

You can modify the getSuccessors method of the HanoiTower object to have any "valid moves"/successors/operands you would like.


## Contributing

Please submit any PRs you want


## License

This project is licensed under GNU

## Additional Resources

For more information on how this AI technique works and guarantees and optimal solution visit:
https://www.cs.us.es/~fsancho/Blog/posts/BFS_Solver_NetLogo.md.html
