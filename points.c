#include <stdio.h>
#include <math.h>
#include <stdbool.h>

typedef struct {
    double x; 
    double y; 
} point;

typedef struct {
    point a; 
    point b; 

} line;

double dist(point a, point b) {
    return sqrt((b.y - a.y)*(b.y - a.y) + (b.x - a.x)*(b.x - a.x));
}

double length(line x) {
    return dist(x.a, x.b);
}

double slope(line z) {
    return (z.b.y - z.a.y) / (z.b.x - z.a.x);
}

bool point_on_line (line c, point p) {

    //find the intercept by subtracting the slope*x coordinate of point from the y
   double line_intercept = c.a.y - (slope(c)*(c.a.x));

    if ((p.x*slope(c)) + line_intercept == p.y) {
        return 1;
    }

    else {
        return 0;
    }
    
}

int main(int argc, char *argv[]) {
/*
    point p = {3, 0};
    point q = {0, 4};
    printf("%lf", dist(p, q));

    */

   point a = {0, 0};
   point b = {1, 1}; 
   point c = {2, 2};
   line l = {a, b}; 

   printf("%d\n", point_on_line(l, c));

}