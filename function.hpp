#ifndef FUNCTION_H_INCLUED
#define FUNCTION_H_INCLUED
class position;

extern int m, n, nr, nc, cr, cc, dr, dc, life, now_life;
extern int **map, **visitedmap, **charge_distance_map;
extern position* destination_array;
extern int destination_array_size;
// mn matrix. now and charge position. destination position. batterylife, now_batterylife

void printmatrix(int** map);
int** createmap(int m, int n);
int** createmap(int m, int n, int reset_value);
void inputmap(); // int**& map
void print_robot_position();
void set_charge_and_wall_true();

void create_destination_array();
bool find_destination(); // wall is set to -1 in visitedmap. // const int** charge_distance_map, const int ** visitedmap
bool sort_destination_cmp();
void run(); //int ** visitedmap, int ** map
void BFS();

#endif // FUNCTION_H_INCLUED