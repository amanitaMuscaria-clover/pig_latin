#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct point {
    int x; 
    int y;
};

double distance(struct point c, struct point d) {
    return sqrt((c.x-d.x)*(c.x-d.x) + (c.y-d.y)*(c.y-d.y));
}

double perimeter(const struct point points[], size_t count) {
    double perim = 0;
    for(int i = 0; i < count; i++) {

        if(i == count-1) {
            perim += distance(points[i], points[0]);
        }

        else {
            perim += distance(points[i], points[i+1]);
        }
    }

    return perim;
}

double area(const struct point points[], size_t count) {
    double area = 0;
    for(int i = 0; i < count; i++) {
        area += abs(((points[i].x + points[i+1].x)*(points[i+1].y-points[i].y)));
    }

    return area/2;
}

int main(int argc, char *argv[]) {
    struct point a, b, c;
    a.x = 0;
    a.y = 0;

    b.x = 0;
    b.y = 1;

    c.x = 1;
    c.y = 0;

    struct point points[] = {a, b, c};

    printf("%lf\n", area(points, 3));
    
}