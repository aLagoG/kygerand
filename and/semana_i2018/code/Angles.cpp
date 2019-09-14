/*
        Temas:
                Funciones trigonometricas basicas
                Circular sweep
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

#define INF 1000000000
#define FOR(i, a, b) for (int i = int(a); i < int(b); i++)
#define FORC(cont, it) \
    for (decltype((cont).begin()) it = (cont).begin(); it != (cont).end(); it++)
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

#define PI 3.14159265358979
#define maxN 100000

struct Point {
    double x, y, ang;
    int id;
    Point operator-=(const Point &r) {
        x -= r.x;
        y -= r.y;
        return *this;
    }
    bool operator<(const Point &r) const {
        return ang < r.ang;
    }
};

int N;
Point p[maxN];

int main() {
    double x = 0.5, y = 0.5;
    // Funciones utiles para problemas de geometria
    // NOTA: TODOS LOS ANGULOS ESTAN EN RADIANES!!!
    // Recomiendo probarlas todas con al menos unos 3-6 valores diferentes para
    // realmente entender que hacen.
    sin(x);  // Seno de x
    cos(x);  // Coseno de x
    tan(x);  // Tangente de x

    // Dado un numero obtener el angulo (por ejemplo el angulo interno de in
    // triangulo)
    asin(x);  // Function inversa de Seno de x (recordar que hay 2 respuestas
              // para cada x) donde x = op/hip
    acos(x);  // Function inversa de Coseno de x (recordar que hay 2 respuestas
              // para cada x) donde x = adj/hip
    atan(x);  // Function inversa de Tangente de x (recordar que hay 2
              // respuestas para cada x) donde x = op/adj
    atan2(y, x);  // Mismo que atan, pero regresa el angulo exacto (solo hay 1
                  // unica respuesta), ya que considera los signos de op y adj

    // Circle sweep idea:
    // Sort all points according to angle from a point P and then iterate
    // through them in order (allows double pointers idea, etc.) 1.- Treat P as
    // origin (do p[i]-P for each point) 2.- Obtain angle from P to p[i] using
    // atan2
    //		1) Remember that a point just to the right of P has angle 0,
    //		2) A point straight up from P has angle PI/2
    //		3) A point directly to the left of P has angle PI
    //		4) A point below P has an angle 3*PI/2 (or -PI/2)
    // 3.- Sort points according to their angle
    // 4.- Iterate through them

    // Ejemplo de problema:
    // Dados 2<=N<=10^5 puntos encontrar los i,j (i!=j) tal que el angulo
    // p[i],P,p[j] sea el mas chico posible. En caso de multiples respuestas
    // imprime la que sea
    while (cin >> N) {
        /*
                Ejemplo de IO:
                4
                0 0
                5 0
                0 5
                -5 0
                0 -5

        */
        Point P;
        cin >> P.x >> P.y;
        FOR(i, 0, N) {
            cin >> p[i].x >> p[i].y;
            p[i] -= P;
            p[i].id = i;
            p[i].ang = atan2(p[i].y, p[i].x);
        }
        sort(p, p + N);
        double resp = INF;
        int r1, r2;
        FOR(i, 0, N) {
            double t = p[(i + 1) % N].ang - p[i].ang;
            // Notar que como estan sorteados p[i+1] siempre sera mayor que
            // p[i], excepto cuando i==N-1, ya que el sig punto es p[0] y es
            // menor
            if (t < 0) t += 2 * PI;
            if (t < resp) {
                resp = t;
                r1 = p[i].id;
                r2 = p[(i + 1) % N].id;
            }
        }
        cout << resp << " " << r1 << " " << r2 << endl;
        // Variaciones de problemas:
        // Variacion 1 (double pointers):
        // Existe un pastel en forma de un cilindro perfecto con N chispas de
        // chocolate, Tu amas las chispas de chocolate, asi que tienes que
        // maximizar la cantidad de chispas de chocolate que tendra tu rebanada.
        // Notas: Solo puedes agarrar 1 rebanda y dicha rebanada tiene que ser
        // formada por 2 cortes rectos del centro del pastel a la orilla.
        // Recibes:
        //	1) N: La cantidad de chispas de chocolate
        //  2) V: El volumen maximo que puede tener tu rebanada de pastel
        //	3) H: La altura del pastel
        //  4) R: El radio del pastel
        //  5) P: Las coordenadas (x,y) del centro del pastel visto desde arriba
        //  5) p[]: Las coordenadas (x,y) de las N chispas de chocolate (Estas
        //  garantizado que todas las chispas estan dentro del pastel).

        // Variacion 2 (double pointer):
        // Dado un Punto P, N puntos en el espacio y su color (rojo o negro) y
        // una recta infinita que tiene que cruzar por P Cual es la mejor manera
        // de posicionar la recta tal que abs(rojos-negros) sea minimizado para
        // cada uno de los 2 lados de la linea. Si la linea es vertical un lado
        // es todo a su izquierda y el otro todo a su derecha

        // Notar que ciertos problemas pueden tener una tolerancia de precision,
        // en dicho caso es necesario considerarla.
    }
    return 0;
}
