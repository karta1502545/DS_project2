#include <iostream>
#include <string>
#include "function.hpp"
#include "function.cpp"

using namespace std;

int m, n, pr, pc; // p is now position

int main()
{
    cin >> m >> n;
    int ** map = createmap(m, n);
    inputmap(map); // 0 stands for floor 1 stands for wall -1 stands for recharge station.
    int ** now_distance_map = createmap(m, n);
    int ** visitedmap = createmap(m, n);

    

    printmatrix(map);
    print_robot_position();

    return 0;
}