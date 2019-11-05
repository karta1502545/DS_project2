#include <iostream>
#include "function.hpp"
#include <algorithm>

using namespace std;

class position{ //用來建造queue的
    public:
        int c;
        int r;
        int d;
        position(): r(-1), c(-1){};
        position(int x, int y): r(x), c(y){};
};

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
    char c;
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
           cin >> c;
           if(c == '1') map[i][j] = 1;
           if(c == '0') map[i][j] = 0;
           if(c == 'R'){
               map[i][j] = -1;
               cr = i;
               cc = j;
               nr = i;
               nc = j;
           }
        }
    }
}

void print_robot_position()
{
    cout << nr << " " << nc << endl;
}

void set_charge_and_wall_true()
{
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(map[i][j] != 0)
                visitedmap[i][j] = true;
        }
    }
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
bool sort_destination_cmp(position a, position b)
{
    return a.d >= b.d;
}
bool find_destination() //const int** charge_distance_map, const int** visitedmap
{
    // if it can find a destination, return true, if not, return false.
    // using the map, charge position and battery life to find out the farest spot as the destination.
    // think of an efficient way to find the destination.

    return false;
}

void create_destination_array()
{
    // it's complete. TODO:sort it. using std? using sort_destination_cmp
    
}

void run()
{
    // run to dc, dr, and go back to cc, cr.
    // revise visitedmap using map.
}


void BFS() // also create an unsorted destination_array
{
    bool visited [m][n];
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(map[i][j] == 0)
                visited[i][j] = false;
            else
                visited[i][j] = true;
        }
    } // construct a visited board, wall and recharge place are set "true" 

    int first = 0, last = 1, dis = 0;
    destination_array = new position [1000000];
    destination_array[0].r = cr;
    destination_array[0].c = cc;
    destination_array[0].d = 0;
    charge_distance_map[cr][cc] = 0;
    visited[cr][cc] = true;
    while(first != last){ //TODO: output the distance to charge_distance_map.
        nr = destination_array[first].r;
        nc = destination_array[first].c;
        dis = destination_array[first].d;
        first++;
        // no need to see if it's wall, wall is set "visited = true"
        if( !visited[nr][nc-1] && (nc-1>=0) ){ // left : not out of bound and not visited
            visited[nr][nc-1] = true;
            destination_array[last].r = nr;
            destination_array[last].c = nc-1;
            destination_array[last].d = dis + 1;
            charge_distance_map[nr][nc-1] = dis + 1;
            last++;
        }
        if( !visited[nr][nc+1] && (nc+1<n) ){ // right : not out of bound and not visited
            visited[nr][nc+1] = true;
            destination_array[last].r = nr;
            destination_array[last].c = nc+1;
            destination_array[last].d = dis + 1;
            charge_distance_map[nr][nc+1] = dis + 1;
            last++;
        }
        if( !visited[nr-1][nc] && (nr-1>=0) ){ // up : not out of bound and not visited
            visited[nr-1][nc] = true;
            destination_array[last].r = nr-1;
            destination_array[last].c = nc;
            destination_array[last].d = dis + 1;
            charge_distance_map[nr-1][nc] = dis + 1;
            last++;
        }
        if( !visited[nr+1][nc] && (nr+1<m) ){ // down : not out of bound and not visited
            visited[nr+1][nc] = true;
            destination_array[last].r = nr+1;
            destination_array[last].c = nc;
            destination_array[last].d = dis + 1;
            charge_distance_map[nr+1][nc] = dis + 1;
            last++;
        }
    }

    // reassign now to charge position
    nr = cr;
    nc = cc;
    
    // delete the charge position
    destination_array[0].c = destination_array[last-1].c;
    destination_array[0].r = destination_array[last-1].r;
    destination_array[0].d = destination_array[last-1].d;
    destination_array_size = last-1;
    // 0 ~ last-2 -> size = last-1
}
/*
7 10 30
1111111111
1000100001
1000100001
1000100001
1011111101
1000000001
1111R11111
*/