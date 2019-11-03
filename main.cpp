#include <iostream>
#include <string>
#include "function.hpp"
#include "function.cpp"

using namespace std;

int m, n, nr, nc, cr, cc, dr, dc, life, now_life;
// mn matrix. now and charge position. destination position. batterylife, now_batterylife
int **map, **visitedmap, **charge_distance_map;

int main()
{
    cin >> m >> n >> life;
    map = createmap(m, n);
    inputmap(); // 0 stands for floor 1 stands for wall -1 stands for recharge station.

    charge_distance_map = createmap(m, n);
    // TODO: using row1-row2 + column1-column2 to bulid charge_distance_map (the charge spot distance to every floor element)
    visitedmap = createmap(m, n, 0);
/*
    while(find_destination()){
        run();
    }
*/
    printmatrix(map);
    print_robot_position();
    return 0;
}