#include <stdio.h>
#include <algorithm>
#include <cmath>

using namespace std;

typedef struct {
    int x;
    int y;
} point;
double pi = 2 * acos(0.0);

inline long long dist2(point a, point b) {
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) {
        printf("Case #%d: ", i);
        point pa, pb, pc;
        scanf("%d %d", &pa.x, &pa.y);
        scanf("%d %d", &pb.x, &pb.y);
        scanf("%d %d", &pc.x, &pc.y);
        long long la, lb, lc;
        lc = dist2(pa, pb);
        lb = dist2(pa, pc);
        la = dist2(pc, pb);
        double a, b, c, dmax;
        c = sqrt(lc);
        b = sqrt(lb);
        a = sqrt(la);
        // printf("%llu %llu %llu %lf %lf %lf\n",la,lb,lc,a,b,c);
        int w;
        if (a > b && a > c) {
            dmax = a;
            w = 1;
        } else if (b > a && b > c) {
            dmax = b;
            w = 2;
        } else {
            dmax = c;
            w = 3;
        }
        // printf("%lf\n",dmax);
        double amax, a2, a3;
        switch (w) {
            case 1:
                amax = acos(((b * b + c * c) - a * a) / (2.0 * b * c));
                a2 = asin(sin(amax) / a * b);
                break;
            case 2:
                amax = acos(((a * a + c * c) - b * b) / (2.0 * a * c));
                a2 = asin(sin(amax) / b * a);
                break;
            case 3:
                amax = acos(((b * b + a * a) - c * c) / (2.0 * b * a));
                a2 = asin(sin(amax) / c * a);
                break;
        }
        a3 = pi - (amax + a2);
        printf("%lf %lf %lf \n", amax, a2, a3);
        if (isnan(amax) || abs(amax - pi) < pi / 5) {
            printf("not a triangle\n");
            continue;
        }
        if (la == lb || lb == lc || lc == la) {
            printf("isosceles ");
        } else if (la != lb && lb != lc && la != lc) {
            printf("scalene ");
        }
        if (amax - pi / 2 > 0.00001) {
            printf("obtuse ");
        } else if (abs(amax - pi / 2) < 0.00001) {
            printf("right ");
        } else {
            printf("acute ");
        }
        printf("triangle\n");
    }
}