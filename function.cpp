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

void inputmap(int**& map)
{
    string c;
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
           cin >> c;
           if(c == "1") map[i][j] = 1;
           if(c == "0") map[i][j] = 0;
           if(c == "R"){
               map[i][j] = -1;
               pr = i;
               pc = j;
           }
        }
    }
}

void print_robot_position()
{
    cout << pr << " " << pc << endl;
}