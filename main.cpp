#include <iostream>
#include <fstream>
#include <string>
#include <time.h>
#include "function.hpp"
#include "function.cpp"

ifstream infile("floor.data");//以輸入方式開啟檔案
ofstream outfile("temp.path");
ifstream temp_infile;
ofstream finalfile("final.path");//以輸出方式開啟檔案
//ofstream mapfile("testcase.txt");//以輸出方式開啟檔案

using namespace std;

int m, n, nr, nc, cr, cc, dr, dc, dd, life, now_life, num_of_steps = 0;
// mn matrix. now and charge position. destination position and distance, batterylife, now_batterylife
int **map, **visitedmap, **charge_distance_map;
position *destination_array, *route_arr;
int destination_array_size;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    infile >> m >> n >> life;
    map = createmap(m, n);
    inputmap();// 0 stands for floor, 1 stands for wall, -1 stands for recharge station.

    charge_distance_map = createmap(m, n, 0);
    BFS(); // using bfs to bulid charge_distance_map (the charge spot distance to every floor element)
    visitedmap = createmap(m, n, 0);
    set_charge_and_wall_true(); // set charge and wall to "true".

    now_life = life;
    printmatrix(charge_distance_map);
    //cout << "initial : " << cr << cc << endl << "start!" << endl;
    route_arr = new position [m*n];
    outfile << cr << " " << cc << '\n';
    while(find_destination()){ //if it's true, dr and dc should be in the right position.
        run(); // go to the destination and back to the charge station. battery should be charged!
        now_life = life;
    }
    outfile.close();
    temp_infile.open("temp.path");
    output_result();
    //cout << "Finished!" << endl << endl;
    //printmatrix(map);
    //print_robot_position();
    delete_memory_allocation();
    temp_infile.close();
    remove("temp.path");
    return 0;
}
/* calculate time
#include <time.h>
clock_t start, end;
start = clock();
std::cout << "time consume: " << (double)(clock() - start) / CLOCKS_PER_SEC << endl;
*/
/* make a size of 1000*1000 testcase map
for(int i=0; i<1000; i++){
    mapfile << "1";
}
mapfile << endl;
for(int i=0; i<998; i++){
    mapfile << "1";
    for(int j=0; j<998; j++){
        mapfile << "0";
    }
    mapfile << "1" << endl;
}
for(int i=0; i<1000; i++){
    if(i!=1)
        mapfile << "1";
    else{
        mapfile << "R";
    }
    
}
mapfile << endl;
*/