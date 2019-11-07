#include <iostream>
#include <string>
#include "function.hpp"
#include "function.cpp"

using namespace std;

int m, n, nr, nc, cr, cc, dr, dc, dd, life, now_life;
// mn matrix. now and charge position. destination position and distance, batterylife, now_batterylife
int **map, **visitedmap, **charge_distance_map;
position* destination_array;
int destination_array_size;

int main()
{
    cin >> m >> n >> life;
    map = createmap(m, n);
    inputmap(); // 0 stands for floor, 1 stands for wall, -1 stands for recharge station.

    charge_distance_map = createmap(m, n, 0);
    BFS(); // using bfs to bulid charge_distance_map (the charge spot distance to every floor element)
    visitedmap = createmap(m, n, 0);
    set_charge_and_wall_true(); // set charge and wall to "true".

    now_life = life;
    cout << "initial : " << cr << cc << endl << "start!" << endl;
    while(find_destination()){ //if it's true, dr and dc should be in the right position.
        run(); // go to the destination and back to the charge station. battery should be charged!
        now_life = life;
    }
    cout << "Finished!" << endl << endl;
    printmatrix(map);
    printmatrix(charge_distance_map);
    print_robot_position();
    return 0;
}