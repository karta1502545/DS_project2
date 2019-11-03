#include <iostream>
#include "function.hpp"

using namespace std;

void printmatrix(int** map)
{
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cout << map[i][j] << " ";
        }
        cout << endl;
    }    
}

int ** createmap(int m, int n)
{
    int **map = new int* [m];
    for(int i=0; i<m; i++){
        map[i] = new int[n];
    }
    return map;
}

void inputmap() //int**& map
{
    string c;
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
           cin >> c;
           if(c == "1") map[i][j] = 1;
           if(c == "0") map[i][j] = 0;
           if(c == "R"){
               map[i][j] = -1;
               cr = i;
               cc = j;
               nr = i;
               nc = i;
           }
        }
    }
}

void print_robot_position()
{
    cout << nr << " " << nc << endl;
}

int** createmap(int m, int n, int reset_value)
{
    int **map = new int* [m];
    for(int i=0; i<m; i++){
        map[i] = new int[n];
    }
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            map[i][j] = reset_value;
        }
    }
    return map;
}

bool find_destination() //const int** charge_distance_map, const int** visitedmap
{
    // if it can find a destination, return true, if not, return false.
    // using the map, charge position and battery life to find out the farest spot as the destination.
    // think of an efficient way to find the destination.
    return false;
}

void run()
{
    // run to dc, dr, and go back to cc, cr.
    // revise visitedmap using map
}