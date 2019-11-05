#include <iostream>
#include "function.hpp"

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
    // revise visitedmap using map.
}


void BFS()
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
    position *arr = new position [1000000];
    arr[0].r = cr;
    arr[0].c = cc;
    arr[0].d = 0;
    charge_distance_map[cr][cc] = 0;
    visited[cr][cc] = true;
    while(first != last){ //TODO: output the distance to charge_distance_map.
        nr = arr[first].r;
        nc = arr[first].c;
        dis = arr[first].d;
        first++;
        // no need to see if it's wall, wall is set "visited = true"
        if( !visited[nr][nc-1] && (nc-1>=0) ){ // left : not out of bound and not visited
            visited[nr][nc-1] = true;
            arr[last].r = nr;
            arr[last].c = nc-1;
            arr[last].d = dis + 1;
            charge_distance_map[nr][nc-1] = dis + 1;
            last++;
        }
        if( !visited[nr][nc+1] && (nc+1<n) ){ // right : not out of bound and not visited
            visited[nr][nc+1] = true;
            arr[last].r = nr;
            arr[last].c = nc+1;
            arr[last].d = dis + 1;
            charge_distance_map[nr][nc+1] = dis + 1;
            last++;
        }
        if( !visited[nr-1][nc] && (nr-1>=0) ){ // up : not out of bound and not visited
            visited[nr-1][nc] = true;
            arr[last].r = nr-1;
            arr[last].c = nc;
            arr[last].d = dis + 1;
            charge_distance_map[nr-1][nc] = dis + 1;
            last++;
        }
        if( !visited[nr+1][nc] && (nr+1<m) ){ // down : not out of bound and not visited
            visited[nr+1][nc] = true;
            arr[last].r = nr+1;
            arr[last].c = nc;
            arr[last].d = dis + 1;
            charge_distance_map[nr+1][nc] = dis + 1;
            last++;
        }
    }

    // reassign now to charge position
    nr = cr;
    nc = cc;
    delete [] arr;
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