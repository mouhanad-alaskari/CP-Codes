#include<bits/stdc++.h>
using namespace std;

const int N = 110000;
typedef long double DB;
const DB EPS = 1e-6;
const DB INF = 1e100;

DB sqr(DB x)
{
    return x * x;
}

struct PT
{
    DB x, y;
    PT (DB x = 0, DB y = 0) : x(x), y(y) {}
    void in()
    {
        double _x, _y;
        scanf("%lf%lf", &_x, &_y);
        x = _x, y = _y;
    }
    PT operator +(const PT &pts) const
    {
        return PT(x + pts.x, y + pts.y);
    }
    PT operator -(const PT &pts) const
    {
        return PT(x - pts.x, y - pts.y);
    }
    PT operator *(const DB &d) const
    {
        return PT(x * d, y * d);
    }
    PT operator /(const DB &d) const
    {
        return PT(x / d, y / d);
    }
};

DB dis2(PT p)
{
    return sqr(p.x) + sqr(p.y);
}
DB dis(PT p)
{
    return sqrt(dis2(p));
}

DB vect(PT p1, PT p2)
{
    return p1.x * p2.y - p1.y * p2.x;
}
DB vect(PT p, PT p1, PT p2)
{
    return vect(p1 - p, p2 - p);
}
DB scal(PT p1, PT p2)
{
    return p1.x * p2.x + p1.y * p2.y;
}
DB scal(PT p, PT p1, PT p2)
{
    return scal(p1 - p, p2 - p);
}

PT projection(PT a, PT b, PT p)
{
    return a + (a - b) * (scal(p - a, a - b) / dis2(a - b));
}

bool onLine(PT p, PT p1, PT p2)
{
    return fabs(vect(p1 - p, p2 - p)) < EPS;
}
bool onSeg(PT p, PT p1, PT p2)
{
    if (!onLine(p, p1, p2)) return 0;
    return (p1.x - p.x) * (p2.x - p.x) < EPS && (p1.y - p.y) * (p2.y - p.y) < EPS;
}

bool common(PT p1, PT p2, PT p3, PT p4)
{
    if (max(p1.x, p2.x) + EPS < min(p3.x, p4.x) || max(p3.x, p4.x) + EPS < min(p1.x, p2.x)) return 0;
    if (max(p1.y, p2.y) + EPS < min(p3.y, p4.y) || max(p3.y, p4.y) + EPS < min(p1.y, p2.y)) return 0;
    return vect(p1, p2, p3) * vect(p1, p2, p4) < EPS && vect(p3, p4, p1) * vect(p3, p4, p2) < EPS;
}

int intersect(PT p1, PT p2, PT p3, PT p4, PT& p)
{
    if( !common(p1,p2,p3,p4) )return 0;
    DB s1 = vect(p1, p2, p3), s2 = vect(p1, p2, p4);
    if (fabs(s1 - s2) < EPS)
    {
        if (fabs(s1) < EPS) return 2;
        return 0;
    }
    p = p3 + (p4 - p3) * s1 / (s1 - s2);
    return 1;
}

int main()
{
    return 0;
}
