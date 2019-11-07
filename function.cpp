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
bool find_destination() //const int** charge_distance_map, const int** visitedmap
{
    static int now_index = destination_array_size; // destination_array[0] is charge space, don't use it.
    int pop_dr, pop_dc, pop_dd;
    bool find = false;
    while(!find && now_index>=1){
        pop_dr = destination_array[now_index].r; //from 1 to destination_array_size
        pop_dc = destination_array[now_index].c;
        pop_dd = destination_array[now_index].d;
        if(!visitedmap[pop_dr][pop_dc]){
            find = true;
            dr = pop_dr;
            dc = pop_dc;
            dd = pop_dd;
        }
        now_index--;
    }
    return find;
}

void run()
{
    // run to dc, dr, and go back to cc, cr.
    // revise visitedmap using map.
    // nr, nc(global var) is unused.
    route_to_destination();
    route_back_to_charge();
}

void route_to_destination()
{
    // run to dc, dr : start from dc, dr, run back to charge place, push them to array and print out in inverse order in the end.
    // revise visitedmap using map.
    int index = 0, now_r = dr, now_c = dc;
    route_arr[index].c = now_c;
    route_arr[index].r = now_r;
    index++;
    visitedmap[now_c][now_r] = true;
    while(now_r != cr || now_c != cc){
        if(charge_distance_map[now_r][now_c-1] < charge_distance_map[now_r][now_c]){ // left, won't appear "out of bound" occasion
            now_r = now_r;
            now_c = now_c - 1;
            route_arr[index].c = now_c; // d (destination) is unused.
            route_arr[index].r = now_r;
            index++;
            visitedmap[now_r][now_c] = true;
        }
        else if(charge_distance_map[now_r][now_c+1] < charge_distance_map[now_r][now_c]){ // right
            now_r = now_r;
            now_c = now_c + 1;
            route_arr[index].c = now_c;
            route_arr[index].r = now_r;
            index++;
            visitedmap[now_r][now_c] = true;
        }
        else if(charge_distance_map[now_r-1][now_c] < charge_distance_map[now_r][now_c]){ // up
            now_r = now_r - 1;
            now_c = now_c;
            route_arr[index].c = now_c;
            route_arr[index].r = now_r;
            index++;
            visitedmap[now_r][now_c] = true;
        }
        else if(charge_distance_map[now_r+1][now_c] < charge_distance_map[now_r][now_c]){ // down
            now_r = now_r + 1;
            now_c = now_c;
            route_arr[index].c = now_c;
            route_arr[index].r = now_r;
            index++;
            visitedmap[now_r][now_c] = true;
        }
    }
    // print out the result
    index--;
    while(index >= 0){
        cout << "row: " <<route_arr[index].r << " column :" << route_arr[index].c << endl;
        index--;
    }
}

void route_back_to_charge()
{
    // run back to charge place.
    // revise visitedmap in the procedure.
    bool find_next = false;
    int now_r = dr, now_c = dc; // start push to array from the next step.
    // print result out when it's been calculated.
    // find the unvisited position first, if not find, then we choose the smaller distance to be next step.
    while(now_r != cr || now_c != cc){
        position* choose_best_step = new position [4];
        for(int i=0; i<4; i++){
            
        }
    }
    cout << "row: " << now_r << " column: " << now_c;
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
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(map[i][j] == 1){
                charge_distance_map[i][j] = 1000000; // in run function, it will be ingored when choosing a proper step. (visited && bigger number)
            }
        }
    }
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
    /*
    // delete the charge position
    destination_array[0].c = destination_array[last-1].c;
    destination_array[0].r = destination_array[last-1].r;
    destination_array[0].d = destination_array[last-1].d;
    */
    last--;
    destination_array_size = last; // destination_array[0] is charge position.
    // 1 ~ last-1 -> size = last-1
}

void delete_memory_allocation()
{
    delete map, visitedmap, charge_distance_map;
    delete destination_array, route_arr;
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