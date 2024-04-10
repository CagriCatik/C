#include <stdio.h>
#include <stdlib.h>
#include "rrt.h"

int main() {
    srand(time(NULL));

    Point start = {10, 10};
    Point goal = {90, 90};

    Node* goal_node = generate_rrt(start, goal);
    if (goal_node != NULL) {
        print_path(goal_node);
    } else {
        printf("Goal not reached within max iterations\n");
    }

    return 0;
}
