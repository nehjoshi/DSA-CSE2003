#include <iostream>
using namespace std;

void solveProblem(int n, int from, int to, int intermidate){
    if (n==0){
        return;
    }
    solveProblem(n-1, from, intermidate, to);
    cout << "Moving disk " << n << " from rod " << from << " to rod " << to <<endl;
    solveProblem(n-1, intermidate, to, from);
}

int main(){
    solveProblem(2, 1, 3, 2);
    return 0;
}