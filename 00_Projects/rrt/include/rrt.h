#ifndef RRT_H
#define RRT_H

#include "structures.h"

#define WIDTH 100
#define HEIGHT 100
#define STEP_SIZE 5
#define NUM_NODES 1000
#define GOAL_RADIUS 5
#define EPSILON 1.0

Node* generate_rrt(Point start, Point goal);
void print_path(Node* goal_node);

#endif /* RRT_H */
