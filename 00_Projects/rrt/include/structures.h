#ifndef STRUCTURES_H
#define STRUCTURES_H

typedef struct {
    double x;
    double y;
} Point;

typedef struct Node {
    Point point;
    struct Node* parent;
} Node;

#endif /* STRUCTURES_H */
