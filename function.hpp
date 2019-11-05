#ifndef FUNCTION_H_INCLUED
#define FUNCTION_H_INCLUED

extern int m, n, nr, nc, cr, cc, dr, dc, life, now_life;
extern int **map, **visitedmap, **charge_distance_map;
// mn matrix. now and charge position. destination position. batterylife, now_batterylife

class position;

void printmatrix(int** map);
int** createmap(int m, int n);
int** createmap(int m, int n, int reset_value);
void inputmap(); // int**& map
void print_robot_position();

bool find_destination(); // wall is set to -1 in visitedmap. // const int** charge_distance_map, const int ** visitedmap
void run(); //int ** visitedmap, int ** map
void BFS();

#endif // FUNCTION_H_INCLUED