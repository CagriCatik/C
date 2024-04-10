#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "rrt.h"

double distance(Point a, Point b) {
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

Point random_point() {
    Point p;
    p.x = (double)(rand() % WIDTH);
    p.y = (double)(rand() % HEIGHT);
    return p;
}

Point step_from_to(Point from, Point to) {
    double d = distance(from, to);
    if (d <= STEP_SIZE) {
        return to;
    } else {
        Point new_point;
        new_point.x = from.x + (STEP_SIZE / d) * (to.x - from.x);
        new_point.y = from.y + (STEP_SIZE / d) * (to.y - from.y);
        return new_point;
    }
}

Node* get_nearest_node(Point point, Node* nodes[], int num_nodes) {
    double min_distance = __DBL_MAX__;
    Node* nearest_node = NULL;
    for (int i = 0; i < num_nodes; i++) {
        double d = distance(point, nodes[i]->point);
        if (d < min_distance) {
            min_distance = d;
            nearest_node = nodes[i];
        }
    }
    return nearest_node;
}

int is_point_valid(Point point) {
    return point.x >= 0 && point.x < WIDTH && point.y >= 0 && point.y < HEIGHT;
}

Node* generate_rrt(Point start, Point goal) {
    Node* nodes[NUM_NODES];
    Node* root = (Node*)malloc(sizeof(Node));
    root->point = start;
    root->parent = NULL;
    nodes[0] = root;

    for (int i = 1; i < NUM_NODES; i++) {
        Point random_point_ = random_point();
        Node* nearest_node = get_nearest_node(random_point_, nodes, i);
        Point new_point = step_from_to(nearest_node->point, random_point_);
        
        if (!is_point_valid(new_point))
            continue;
        
        Node* new_node = (Node*)malloc(sizeof(Node));
        new_node->point = new_point;
        new_node->parent = nearest_node;
        nodes[i] = new_node;

        if (distance(new_point, goal) <= GOAL_RADIUS) {
            Node* goal_node = (Node*)malloc(sizeof(Node));
            goal_node->point = goal;
            goal_node->parent = new_node;
            return goal_node; // Goal reached
        }
    }
    return NULL; // Goal not reached within max iterations
}

void print_path(Node* goal_node) {
    printf("Path: ");
    Node* current = goal_node;
    while (current != NULL) {
        printf("(%.1f, %.1f) ", current->point.x, current->point.y);
        current = current->parent;
    }
    printf("\n");
}
