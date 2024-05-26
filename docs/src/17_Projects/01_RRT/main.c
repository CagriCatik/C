#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define GRID_SIZE 20
#define MAX_NODES 1000
#define GOAL_RADIUS 2

typedef struct {
    int x, y;
} Point;

typedef struct Node {
    Point pos;
    struct Node* parent;
} Node;

Node nodes[MAX_NODES];
int node_count = 0;

int grid[GRID_SIZE][GRID_SIZE] = {0};

Point start = {0, 0};
Point goal = {19, 19};

void initialize_grid() {
    // Add obstacles to the grid
    for (int i = 5; i < 15; i++) {
        grid[i][10] = 1; // Obstacle
    }
}

int is_valid(int x, int y) {
    return x >= 0 && x < GRID_SIZE && y >= 0 && y < GRID_SIZE && grid[x][y] == 0;
}

double distance(Point a, Point b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

Node* nearest_node(Point p) {
    Node* nearest = &nodes[0];
    double min_dist = distance(p, nearest->pos);
    
    for (int i = 1; i < node_count; i++) {
        double dist = distance(p, nodes[i].pos);
        if (dist < min_dist) {
            min_dist = dist;
            nearest = &nodes[i];
        }
    }
    return nearest;
}

Point random_point() {
    Point p;
    p.x = rand() % GRID_SIZE;
    p.y = rand() % GRID_SIZE;
    return p;
}

Point steer(Point from, Point to) {
    Point new_point;
    double theta = atan2(to.y - from.y, to.x - from.x);
    new_point.x = from.x + (int)(cos(theta) * 2);
    new_point.y = from.y + (int)(sin(theta) * 2);
    
    if (is_valid(new_point.x, new_point.y)) {
        return new_point;
    } else {
        return from;
    }
}

void add_node(Node* parent, Point pos) {
    nodes[node_count].pos = pos;
    nodes[node_count].parent = parent;
    node_count++;
}

void build_rrt() {
    add_node(NULL, start);
    
    while (node_count < MAX_NODES) {
        Point rand_point = random_point();
        Node* nearest = nearest_node(rand_point);
        Point new_point = steer(nearest->pos, rand_point);
        
        if (distance(new_point, nearest->pos) > 1 && is_valid(new_point.x, new_point.y)) {
            add_node(nearest, new_point);
            
            if (distance(new_point, goal) < GOAL_RADIUS) {
                add_node(&nodes[node_count - 1], goal);
                break;
            }
        }
    }
}

void print_path(Node* node) {
    if (node == NULL) return;
    print_path(node->parent);
    printf("(%d, %d) -> ", node->pos.x, node->pos.y);
}

void visualize_grid() {
    for (int y = 0; y < GRID_SIZE; y++) {
        for (int x = 0; x < GRID_SIZE; x++) {
            if (grid[x][y] == 1) {
                printf("# ");
            } else {
                int is_path = 0;
                for (int i = 0; i < node_count; i++) {
                    if (nodes[i].pos.x == x && nodes[i].pos.y == y) {
                        is_path = 1;
                        break;
                    }
                }
                if (is_path) {
                    printf("* ");
                } else {
                    printf(". ");
                }
            }
        }
        printf("\n");
    }
}

int main() {
    srand(time(0));
    initialize_grid();
    build_rrt();
    visualize_grid();
    
    printf("Path:\n");
    print_path(&nodes[node_count - 1]);
    printf("Goal\n");
    
    return 0;
}
