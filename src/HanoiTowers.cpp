#include "../include/HanoiTowers.hpp"
#include <iostream>
#include <queue>
#include <limits>
#include <algorithm>

HanoiTowers::HanoiTowers(int n)
{
    this->number_of_disks = n;
    for (int i = n; i > 0; i--)
    {
        tower1.push_back(i);
    }
}

std::vector<Move> HanoiTowers::solve() const
{
    // This will solve the problem using BFS. We will search the graph to find the optimal solution.
    std::cout << "Finding Solution\n";
    std::vector<Move> solution;                           // This will keep track of the states to go from initial state to solution state
    HanoiTowers solutionState = this->getSolutionState(); // This will be the solution to our problem
    std::vector<HanoiTowers> viseted;
    // Check if the initial state is the solution state and if it is return solution
    if (solutionState == *this)
    {
        std::cout << "Solution Found!\n";
        return solution;
    }
    viseted.push_back(*this);

    // Create an OPEN queue with the initial node, I, (initial-state)
    std::queue<HanoiTowers> bsf_queue;
    bsf_queue.push(*this);

    // 2 OUTCOME=False
    bool outcome = false; // This rappresents weather or not we found a solution

    // 3 Repeat until OPEN list is empty or OUTCOME is true
    while (!(bsf_queue.empty() || outcome))
    {
        // Remove the first node from OPEN list, N
        HanoiTowers N = bsf_queue.front();
        bsf_queue.pop();

        // If N has successors then Generate the successors of N
        std::vector<HanoiTowers> successors = N.getSuccessors();
        if (!successors.empty())
        {
            for (auto successor : successors)
            {
                // Check if state has already been visited if it has continue
                if (std::find(viseted.begin(), viseted.end(), successor) != viseted.end())
                {
                    continue;
                }

                // Visit node
                viseted.push_back(successor);

                // Create pointers from the successors to N

                // If a successor is a goal node then OUTCOME=True
                if (successor == solutionState)
                {
                    std::cout << "Solution Found!\n" << successor << std::endl;
                    outcome = true;
                }
                // Else add successors at end of OPEN list
                else
                {
                    bsf_queue.push(successor);
                }
            }
        }
    }

    // 4 If OUTCOME Then Solution = path from I to N through the pointers
    if (outcome)
    {
        return solution;
    }
    // Else Solution = False
    else
    {
        // This will never happen as this problem is alwasy solvable.
        std::cout << "Solution Not Found!\n";
        return (std::vector<Move>){};
    }
}

void HanoiTowers::print() const
{
    std::cout << *this << std::endl;
}

HanoiTowers HanoiTowers::getSolutionState() const
{
    HanoiTowers solutionState(this->number_of_disks); // Instantiate a new HanoiTower object to rappresent solution state
    solutionState.tower3 = solutionState.tower1;
    solutionState.tower1.clear();
    return solutionState;
}

bool HanoiTowers::operator==(const HanoiTowers &other) const
{
    return this->tower1 == other.tower1 && this->tower2 == other.tower2 && this->tower3 == other.tower3;
}

std::ostream &operator<<(std::ostream &os, const HanoiTowers &ht)
{
    // determaning the pillar with the most disks
    int BiggestSize = ht.tower1.size() > ht.tower2.size() ? ht.tower1.size() : ht.tower2.size();
    BiggestSize = BiggestSize > ht.tower3.size() ? BiggestSize : ht.tower3.size();

    for (int i = BiggestSize - 1; i >= 0; i--)
    {
        if (i < ht.tower1.size())
        {
            os << ht.tower1[i];
        }
        else
        {
            os << " ";
        }

        os << " ";

        if (i < ht.tower2.size())
        {
            os << ht.tower2[i];
        }
        else
        {
            os << " ";
        }

        os << " ";

        if (i < ht.tower3.size())
        {
            os << ht.tower3[i];
        }
        else
        {
            os << " ";
        }

        os << std::endl;
    }
    os << "- - -\n";

    return os;
}

void HanoiTowers::moveDisk(int from, int to)
{
    // function to move the disk from one tower to another. The function checks if the move is valid.
    if ((from != 0 && from != 1 && from != 2) || (to != 0 && to != 1 && to != 2))
    {
        std::cout << "Invalid tower number\n";
        return;
    }

    // The switch statement looks really ugly but it bassically moves the disk from one tower to another checking if the move is valid
    switch (from)
    {
    case 0:
        if (to == 1)
        {
            if (tower1.size() == 0)
            {
                std::cout << "Invalid move\n";
                return;
            }
            tower2.push_back(tower1.back());
            tower1.pop_back();
        }
        else if (to == 2)
        {
            if (tower1.size() == 0)
            {
                std::cout << "Invalid move\n";
                return;
            }
            tower3.push_back(tower1.back());
            tower1.pop_back();
        }
        break;

    case 1:
        if (to == 0)
        {
            if (tower2.size() == 0)
            {
                std::cout << "Invalid move\n";
                return;
            }
            tower1.push_back(tower2.back());
            tower2.pop_back();
        }
        else if (to == 2)
        {
            if (tower2.size() == 0)
            {
                std::cout << "Invalid move\n";
                return;
            }
            tower3.push_back(tower2.back());
            tower2.pop_back();
        }
        break;

    case 2:
        if (to == 0)
        {
            if (tower3.size() == 0)
            {
                std::cout << "Invalid move\n";
                return;
            }
            tower1.push_back(tower3.back());
            tower3.pop_back();
        }
        else if (to == 1)
        {
            if (tower3.size() == 0)
            {
                std::cout << "Invalid move\n";
                return;
            }
            tower2.push_back(tower3.back());
            tower3.pop_back();
        }
        break;

    default:
        break;
    }
}

std::vector<HanoiTowers> HanoiTowers::getSuccessors() const
{
    // To get the successors of any HanoiTowers object we define the valid moves you can make.
    std::vector<HanoiTowers> successors; // This will be a vector of all successors of the calling HanoiTowers object

    const int MAX = std::numeric_limits<int>::max();

    int top_of_tower1 = this->tower1.empty() ? MAX : this->tower1.back();
    int top_of_tower2 = this->tower2.empty() ? MAX : this->tower2.back();
    int top_of_tower3 = this->tower3.empty() ? MAX : this->tower3.back();

    if (top_of_tower1 < top_of_tower2)
    {
        HanoiTowers newSuccessor = *this; // default copy constructor
        newSuccessor.moveDisk(0, 1);      // first pillar to second pillar
        successors.push_back(newSuccessor);
    }
    if (top_of_tower1 < top_of_tower3)
    {
        HanoiTowers newSuccessor = *this; // default copy constructor
        newSuccessor.moveDisk(0, 2);      // first pillar to third pillar
        successors.push_back(newSuccessor);
    }
    if (top_of_tower2 < top_of_tower1)
    {
        HanoiTowers newSuccessor = *this; // default copy constructor
        newSuccessor.moveDisk(1, 0);      // second pillar to first pillar
        successors.push_back(newSuccessor);
    }
    if (top_of_tower2 < top_of_tower3)
    {
        HanoiTowers newSuccessor = *this; // default copy constructor
        newSuccessor.moveDisk(1, 2);      // second pillar to third pillar
        successors.push_back(newSuccessor);
    }
    if (top_of_tower3 < top_of_tower1)
    {
        HanoiTowers newSuccessor = *this; // default copy constructor
        newSuccessor.moveDisk(2, 0);      // third pillar to first pillar
        successors.push_back(newSuccessor);
    }
    if (top_of_tower3 < top_of_tower2)
    {
        HanoiTowers newSuccessor = *this; // default copy constructor
        newSuccessor.moveDisk(2, 1);      // third pillar to second pillar
        successors.push_back(newSuccessor);
    }

    return successors;
}

void HanoiTowers::execute_moves(std::vector<Move> moves)
{
    std::cout << "Executing Moves...\n";
    for (auto move : moves)
    {
        this->moveDisk(move.from, move.to);
    }
}
