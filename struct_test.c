#include<stdio.h>
#include<stdlib.h>
#include<math.h>


struct Coord{
    double x;
    double y;
};

typedef struct {
    double x, y;
} Coordinate;

double distance(struct Coord p1, struct Coord p2){
    return sqrt(pow(p1.x - p2.x,2) + pow(p1.y - p2.y, 2));
}

double distance2(Coordinate p1, Coordinate p2){
    return sqrt(pow(p1.x - p2.x,2) + pow(p1.y - p2.y, 2));
}

int main() {

    struct Coord p1;
    p1.x = 2; p1.y = 5;
    struct Coord p2 = {4, 10};
// struct Coord p3 = {.x = 5, .y = 9};
    Coordinate q1 = {2, 5};

    double d = distance(p1, p2);
    printf("%.2f", d);

    return 0;
}