#ifndef HANOI_TOWERS_HPP
#define HANOI_TOWERS_HPP

#include <ostream>
#include <vector>

// this struct is just to keep track of some moves. All we need to define a rule is the pillar you want to move the disk from and to.
struct Move
{
    int from; // pillar you are moving the disk from
    int to;   // pillar you are moving the disk to
};

class HanoiTowers
{
private:
    std::vector<int> tower1;
    std::vector<int> tower2;
    std::vector<int> tower3;
    int number_of_disks;

public:
    HanoiTowers(int n);
    // Precondition: None
    // Postcondition: It will retrun a vector of Moves that rappresent each move you should make to solve the problem. Meaning going from initial state to solution state.
    std::vector<Move> solve() const;
    void execute_moves(std::vector<Move>); 
    void print() const;
    void moveDisk(int from, int to);
    HanoiTowers getSolutionState() const;
    std::vector<HanoiTowers> getSuccessors() const;
    bool operator==(const HanoiTowers& other) const;
    friend std::ostream &operator<<(std::ostream &os, const HanoiTowers &ht);  // output stream and hanoi towers is what the things stand for
};

#endif // HANOI_TOWERS_HPP
