#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Point {
    double x; 
    double y;
};

struct Polygon {
    size_t num_vertices;
    struct Point* points;
};

double distance(struct Point c, struct Point d) {
    return sqrt((c.x-d.x)*(c.x-d.x) + (c.y-d.y)*(c.y-d.y));
}

double area(struct Polygon *p) {
    double area = 0;
    for(int i = 0; i < p->num_vertices; i++) {
        area += fabs(((p->points[i].x + p->points[i+1].x)*(p->points[i+1].y-p->points[i].y)));
    }

    return area/2;
}

double perimeter(struct Polygon *p) {
    double perim = 0;
    for(int i = 0; i < p->num_vertices; i++) {

        if(i == p->num_vertices) {
            perim += distance(p->points[i], p->points[0]);
        }

        else {
            perim += distance(p->points[i], p->points[i+1]);
        }
    }

    return perim;
}

//reads in the points and makes a polygon 
struct Polygon *read_polygon(size_t point_count) {
    struct Polygon *shape = (struct Polygon*)calloc(1, sizeof(struct Polygon));
    shape->points = (struct Point*)calloc(point_count, sizeof(struct Point));
    shape->num_vertices = point_count;
    return shape;
}

int main (int argc, char *argv[]) {
    int points_number = 0;
    printf("How many points are on your polygon? ");
    scanf("%d", &points_number);
    
    struct Polygon *p = read_polygon(points_number);
    int x = 0;
    int y = 0;
    for(int i = 0; i < points_number; i++) {
        printf("Enter your %d out of %d point:", i+1, points_number);
        scanf("%d %d", &x, &y);
        p->points[i].x = x;
        p->points[i].y = y;

    }

    printf("Here is the area %.3lf\n", area(p));
    printf("Here is the perimeter %.3lf\n", perimeter(p));

  
    free(p->points);
    free(p);
   
    
}

