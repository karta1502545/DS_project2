#ifndef FUNCTION_H_INCLUED
#define FUNCTION_H_INCLUED
class position;

extern std::ifstream infile;
extern std::ofstream outfile;

extern int m, n, nr, nc, cr, cc, dr, dc, dd, life, now_life;
extern int **map, **visitedmap, **charge_distance_map;
extern position *destination_array, *route_arr;
extern int destination_array_size;
// mn matrix. now and charge position. destination position. batterylife, now_batterylife

void printmatrix(int** map);
int** createmap(int m, int n);
int** createmap(int m, int n, int reset_value);
void inputmap(); // int**& map
void print_robot_position();
void set_charge_and_wall_true();

bool find_destination(); // wall is set to -1 in visitedmap. // const int** charge_distance_map, const int ** visitedmap
void run(); //int ** visitedmap, int ** map
void route_to_destination();
void route_back_to_charge();
void BFS();
void delete_memory_allocation();

#endif // FUNCTION_H_INCLUED