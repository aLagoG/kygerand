/*
        Temas:
                Convex hull
                Distancia minima entre N puntos
                Distancia maxima entre N puntos

        Cosas a recordar:
                CW = Clockwise
                CCW = Counter Clockwise

        Recomendaria leer las funciones en el siguiente orden:
                1.- solveBrute (para ver el problema original)
                2.- minDist (Como obtener la distancia minima en NlogN)
                3.- maxDist (Como obtener la distancia maxima en NlogN)
                4.- convexHull (Como obtener la convex hull de un poligono)

        Notas adicionales: Use vectores para las implementaciones porque no
   queria modificar el arreglo original, en un concurso se vale lo que sea, no
   se limiten a vectores y recuerden que arreglos son mas rapidos que vectores.
*/
#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <utility>
#include <vector>

#define INF 1000000000000000000LL
#define FOR(i, a, b) for (int i = int(a); i < int(b); i++)
#define FORC(cont, it) \
    for (decltype((cont).begin()) it = (cont).begin(); it != (cont).end(); it++)
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<double, double> pdd;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

// Notar que maxN puede valer 10^5, solo es 1k para probar que funcionan los
// algoritmos
#define maxN 1000
#define PI 3.14159265358979

struct Point {
    double x, y;
    bool operator<(const Point &r) const {
        return x < r.x || x == r.x && y < r.y;
    }
};

int N;
Point p[maxN];

double dist(Point &l, Point &r) {
    return sqrt((l.x - r.x) * (l.x - r.x) + (l.y - r.y) * (l.y - r.y));
}

// Encuentra la minima y maxima distancia entre N puntos O(N^2)
pdd solveBrute() {
    pdd ret = pdd{INF, 0};
    FOR(i, 0, N) {
        FOR(j, i + 1, N) {
            double d = dist(p[i], p[j]);
            ret.first = min(ret.first, d);
            ret.second = max(ret.second, d);
        }
    }
    return ret;
}

// Regresa la distancia minima usando divide and conquer
// Se le envian los puntos sorteados por x y los regresa sorteados por y
// Sabemos que la distancia minima va a ser la minima entre la respuesta de
// left, la respuesta de right y juntarlos. Ahora usamos la misma idea de
// mergesort para mergear los puntos, esta vez ordenandolos por y, pero hacemos
// un paso intermedio. Para este paso intermedio llamenos minDist a la distancia
// minima de left y right. Sabemos que originalmente los teniamos ordenados en
// x, asi que sabemos que los puntos de l tendran una x <= a todos los puntos de
// r. Si agarramos la x mas grande en l (llamemosla mx) podemos descartar todos
// los puntos con una x menor o igual a mx-minDist De igual manera podemos
// descartar todos los puntos de r con una x mayor o igual a mx+minDist Pero
// notamos algo, entre los puntos validos solo vamos a tener maximo 6 puntos al
// mismo tiempo. Esto se debe a que si la distancia entre la minima y y la
// maxima y de los puntos validos es mayor a minDist, podemos sacar la minima y.
// Segunda cosa que notamos, como solo metemos puntos con distancia menor o
// igual a minDist de mx y sabemos que todos los puntos de l estan a minimo una
// distancia minDist (lo mismo para r) El pero caso seria asi: Supongamos que
// minDist=2 y mx cruza por la columna 3 012345 (columnas)
//  . . .
//
//  . . .
// Otra manera de pensarlo es cual es la mayor cantidad de puntos que caben tal
// que todos tienen una distancia entre ellos de al menos minDist, pero no mayor
// a minDist en Y y no mayor a 2*minDist en X Estas premisas siempre se cumplen
// porque si encontramos una nueva minDist la actualizamos. La respuesta a ese
// problema es 6, por ende requerimos de 6*N itearciones para mergear, y por ser
// divide and conquer O(N*logN)
double minDDC(vector<Point> &v) {
    if (v.size() == 1) return INF;
    vector<Point> l, r;
    int half = v.size() / 2, mx = v[half - 1].x;
    FOR(i, 0, half) l.push_back(v[i]);
    FOR(i, half, v.size()) r.push_back(v[i]);
    double minDist = min(minDDC(l), minDDC(r));
    int lc = 0, rc = 0, cc = 0, vl = 0;
    vector<Point> valids;
    while (lc < l.size() || rc < r.size()) {
        Point t;
        if (rc >= r.size() || lc < l.size() && l[lc].y < r[rc].y)
            t = l[lc++];
        else
            t = r[rc++];
        v[cc++] = t;
        if (fabs(t.x - mx) <= minDist) {
            FOR(i, vl, valids.size()) {
                double d = dist(valids[i], t);
                if (d < minDist) {
                    minDist = d;
                }
            }
            valids.push_back(t);
            while (t.y - valids[vl].y > minDist) vl++;
        }
    }
    return minDist;
}

// Obtiene la minima distancia entre 2 puntos usando la tecnica de divide and
// conquer O(NlogN)
double minDist() {
    vector<Point> s(N);
    FOR(i, 0, N) s[i] = p[i];
    sort(s.begin(), s.end());
    double ret = minDDC(s);
    return ret;
}

// Regres el doble del area del triangulo abc (nota que si abc es CCW es
// positiva y CW es negativa, si no es un triangulo, sino estan en la misma
// recta los 3 puntos regresa 0) Gauss shoelace
double areaTriangulo(Point &a, Point &b, Point &c) {
    return a.x * b.y - a.y * b.x + b.x * c.y - b.y * c.x + c.x * a.y -
           c.y * a.x;
}

// Regresa el convex hull en CCW dados N puntos (nota que el primer y ultimo
// punto de la hull es el mismo punto, aparece 2 veces) Primero sortea los
// puntos en X y luego itera sobre todos usando la idea de stack, primero forma
// la mitad de abajo y luego la de arriba Notas de la construccion del hull:
//  1) Siempre suponemos que vamos a meter a la stack el punto en el cual vamos.
//	2) Antes de meter un punto a la stack hay que ver que pasa si lo
//metemos, solo hay 2 opciones: 		1.- El poligono seria convexo en dicho caso lo
//metemos a la stack 		2.- El poligono seria concavo (error, hay que sacar el
//ultimo punto que metimos a la stack) y volvemos a checar
//  3) Para determinar si el nuevo poligono sera concavo o convexo agarramos los
//  ultimos 2 puntos de la stack y el nuevo a meter
//      Obtenemos el area de dicho triangulo y si el area es positiva el
//      poligono es convexo, sino concavo.
//		Esto es cierto porque estamos construyendo la hull en CCW order y
//por definicion 3 puntos consecutivos cualesquiera de un poligono convexo en
//CCW tienen que estar en CCW.
vector<Point> convexHull() {
    vector<Point> hull(N + 1), sorted(N);
    FOR(i, 0, N) sorted[i] = p[i];
    sort(sorted.begin(), sorted.end());
    // Construimos la lower hull
    // Suponemos que tenemos al menos 3 puntos y forzamos a que el punto con la
    // x mas peque�a (y en empate con y mas peque�a) sea parte de la hull, ya
    // que siempre es cierto
    hull[0] = sorted[0];
    int hc = 1;
    FOR(i, 1, N) {
        while (hc > 1 &&
               areaTriangulo(hull[hc - 2], hull[hc - 1], sorted[i]) <= 0)
            hc--;
        hull[hc++] = sorted[i];
    }
    // Construimos el upper hull
    // Nos saltamos todos los puntos con la x mas grande, ya que al terminar el
    // lower hull estamos garantizados que tenemos el punto con la x mas grande
    // (y en empate la y mas grande) dentro de la hull Al igual que al constuir
    // la mitad de abajo, aqui forzamos al que sigue del mas grande a estar en
    // la hull, De esta manera lo que hacemos es pretender que empezamos en otra
    // stack desde 0, pero sin pedir memoria para 2 stacks
    int st = N - 2;
    while (sorted[st].x == sorted[N - 1].x) st--;
    hull[hc++] = sorted[st--];
    for (int i = st; i >= 0; i--) {
        while (hc > 1 &&
               areaTriangulo(hull[hc - 2], hull[hc - 1], sorted[i]) <= 0)
            hc--;
        hull[hc++] = sorted[i];
    }
    hull.resize(hc);
    return hull;
}

// Regresa el angulo (la inclinacion de la pendiente, pero infinitamente mejor
// que pendientes porque maneja cualquier valor) Nota: En caso de que el angulo
// que se obtiene sea menor que el angulo previo, significa que terminamos un
// ciclo sobre el poligono En dicho caso incrementamos en 2*PI hasta que sea
// mayor al previo, para poder aplicar una logica sencilla en el double pointer
// (ya que los angulos son ciclicos y en este caso para facilitarnos la vida no
// queremos eso)
double angConsecutivePoints(const vector<Point> &hull, int i, double prev) {
    double ang = atan2(hull[(i + 1) % hull.size()].y - hull[i].y,
                       hull[(i + 1) % hull.size()].x - hull[i].x);
    while (ang < prev) ang += 2 * PI;
    return ang;
}

// Usamos la tecnica de rotating calipers con double pointers
// Primero imaginemonos un circulo en vez de un poligono.
// El punto mas lejano a un punto en la circumferencia del circulo esta del lado
// opuesto Ahora si agarramos una linea tangente a dicho circulo y que se
// intersecte con ese punto, En el punto opuesto existe una recta tangente con
// la misma pendiente. Para este caso no nos interesan pendientes, asi que
// usaremos angulos, diremos que la que intersecta con el punto original tiene
// angulo A La que intersecta con el punto opuesto tiene angulo A+PI (en
// radianes) Ahora regresemos al poligono, y elegimos un vertice V Pasa lo mismo
// que con el circulo, excepto que ya no hay un unico angulo, sino ahora hay
// infinitos angulos El rango de los angulos para un punto esta dado por [L,R]
// Donde L es el angulo del segmento que une a V y el vertice previo en el
// poligono R es el angulo del segmento entre V y el siguiente vertice cen el
// poligono. Notemos que dado un rango [L,R] puede haber entre 1 y N puntos
// opuestos por los cuales pasa una recta con algun angulo entre L+PI y R+PI Sin
// embargo notemos que entre puntos consecutivos la R de uno se vuelve la L del
// otro (en el vertice V+1 el rango seria [R,R2] Entonces podemos usar double
// pointers ya que siempre vamos creciendo y una vez que pasamos un angulo no
// necesitamos regresarnos, ergo O(N) Ahora bien a la implementacion: Si vamos
// en el punto i obtenemos el angulo del segmento que une a i e i+1 (llamemoslo
// ang) y lo comparamos con el de la r y r+1 (llamemoslo angr) Si el angulo
// entre r y r+1 es menor a ang+PI, significa que r es una potencial respuesta
// (punto opuesto), checamos la distancia y nos saltamos a r+1
double maxDist() {
    // Ya que la respuesta esta en los puntos que se encuentran sobre la convex
    // hull
    vector<Point> hull = convexHull();
    int r = 1;
    double prev = -2 * PI, prevR = -2 * PI, ret = 0;
    FOR(i, 0, hull.size()) {
        double ang = angConsecutivePoints(hull, i, prev), angr;
        while (ang + PI > (angr = angConsecutivePoints(hull, r, prevR))) {
            ret = max(ret, dist(hull[i], hull[r]));
            prevR = angr;
            r = (r + 1) % hull.size();
        }
        prev = ang;
        ret = max(ret, dist(hull[i], hull[r]));
    }
    return ret;
}

pdd solveFast() {
    return pdd{minDist(), maxDist()};
}

int main() {
    // Algo asi es la idea de como se hace un generador de casos prueba para ver
    // si una solucion esta bien Suponiendo que el solucionador de bruteforce es
    // correcto :P
    FOR(i, 0, 1000) {
        N = rand() % maxN + 2;
        FOR(i, 0, N) {
            p[i].x = rand();
            p[i].y = rand();
        }
        if (solveBrute() != solveFast()) {
            // En teoria esto nunca deberia entrar porque las respuestas son
            // iguales
            cout << "ERROR" << endl;
        }
    }
    return 0;
}
