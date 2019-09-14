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

/*
Strings:
- KMP (Knuth-Morris-Pratt)
- Z function
- Manacher
- Hash strings
- Trie
- Longest Common Subsequence (DP)
- Longest Common Substring (usando Hash)
- Suffix Array/ Suffix tree/ Suffix automaton
*/

#define maxSize 1000

int dp[maxSize][maxSize];

// Version recursiva para reconstruir la respuesta del LCS
void reconstruct(int i, int j, const string &a, const string &b, string &ans) {
    if (i < 0 || j < 0) return;
    if (a[i] == b[j]) {
        ans += a[i];
        return reconstruct(i - 1, j - 1, a, b, ans);
    }
    if ((i ? dp[i - 1][j] : 0) > (j ? dp[i][j - 1] : 0))
        return reconstruct(i - 1, j, a, b, ans);
    reconstruct(i, j - 1, a, b, ans);
}

// Longest common subsequence between 2 string A and B
// Usa un dp[i][j], donde i es el caracter en el que vamos de A y j es el
// caracter de B
string LCS(string a, string b) {
    FOR(i, 0, a.length()) {
        FOR(j, 0, b.length()) {
            dp[i][j] = max(i ? dp[i - 1][j] : 0, j ? dp[i][j - 1] : 0);
            if (a[i] == b[j]) dp[i][j] = (i && j ? dp[i - 1][j - 1] : 0) + 1;
        }
    }
    string ans = "";
    int i = a.length(), j = b.length();
    while (i >= 0 && j >= 0) {
        if (a[i] == b[j]) {
            ans += a[i];
            i--, j--;
        } else if ((i ? dp[i - 1][j] : 0) > (j ? dp[i][j - 1] : 0)) {
            i--;
        } else
            j--;
    }
    return ans;
}

#define maxChars 100000

int trie[maxChars][26], tc = 1;

void Trie() {
    // inicializar el trie
    memset(trie, -1, sizeof(trie));
    tc = 1;

    // Meter una palabra al arbol, notar que si queremos guardar algo en los
    // nodos y actualizar hacia arriba, conviene hacerlo recursivo Por ejemplo:
    // Cual es la palabra mas probable de aparecer dado un prefijo, ahi
    // necesitamos actualizar del fondo hacia arriba.
    {
        int t = 0;
        string s;
        FOR(i, 0, s.length()) {
            char c = s[i] - 'a';
            if (trie[t][c] == -1) {
                trie[t][c] = tc++;
            }
            t = trie[t][c];
        }
    }

    /*
    Idea detras de trie:
    Usar un grafo donde las edges son letras [a,z] y el camino tomado desde la
    raiz hasta un nodo implica el prefijo de la palabra
    

    Por ejemplo dado:
    abaco
    abanico
    dado

    El grafo seria
      d->a->d->o
     /
    $->a->b->a->c->o
     \
      n->i->c->o
    */
}

#define maxN 100000

int p[maxN];
string a = "a", b = "a";

int main() {
    cout << LCS("abada", "kedabra") << endl;
    // Buscar si b es un substring de a en naive O((A-B)*B)-> O(N^2)
    int ansBrute = -1;
    FOR(i, 0, a.length() - b.length() + 1) {
        bool v = true;
        FOR(j, 0, b.length()) {
            if (a[i + j] != b[j]) {
                v = false;
                break;
            }
        }
        if (v) {
            ansBrute = i;
            break;
        }
    }
    // KMP (Knuth-Morris-Pratt), te dice si B es un substring de A en tiempo
    // lineal Primero se construye un arreglo de posiciones p para b Para
    // entenderlo primero hay que entender la solucion naive, en caso de que no
    // se matchee nos detenemos La diferencia es que aqui ya iteramos sobre lo
    // anterior, entonces en caso de no matchearse queremos la maxima pp tal que
    // desde todo el intervalo desde b[i-pp+1] hasta b[i] sea exactamente igual
    // al rango desde b[0] hasta b[pp] En caso de que no exista ninguna pp, pp
    // valdra -1 Por ende p[i]-> el indice al cual movernos en caso de que b[i]
    // sea diferente a b[pp] P se veria algo asi para el string ababc a  b  a  b
    // c -1 0  0  1  2 KMP
    int pp = -1, ansKMP = -1;
    p[0] = -1;
    // a = b + "$" + a;
    cin >> a >> b;
    // Notar que hay 2 maneras de hacer esto, una es primero creamos P para b y
    // luego iteramos sobre A usando P Por supuesto que hay que notar que el
    // proceso es el mismo para ambos, asi que podemos simplemente concatener A
    // y B poniendo un caracter de escape de por medio para resetear pp al
    // cambiar entre b y a
    a = b + "$" + a;
    FOR(i, 0, a.length()) {
        while (pp >= 0 && a[pp] != a[i]) pp = p[pp];
        p[i + 1] = ++pp;
        if (pp >= b.length()) {
            // subproblema: Como le hacemos para encontrar TODOS los substrings
            // de A que son iguales a B
            ansKMP = i - b.length() + 1;
            break;
        }
    }

    // Z function
    // Necesitamos un arreglo p, donde p[i]=k contenga la longitud mas larga tal
    // que todo el rango desde desde [i,i+k) sea igual al rango [0,k) en el
    // string a Otra manera de pensarlo es p es el substring mas largo que
    // empieza en i y es un prefijo de a Implementacion navie O(N^2)
    FOR(i, 0, a.length()) {
        p[i] = 0;
        FOR(j, 0, a.length() - i) {
            if (a[i + j] != a[j]) {
                break;
            }
            p[i]++;
        }
    }
    // Tiempo lineal
    // Usamos 2 letras, l y r, ya que las tenemos sabemos que el rango [l,r) es
    // igual al rango [0,r-l), asi que usamos la informacion calculada
    // previamente para obtener los nuevos valores de p r -> posicion mas a la
    // derecha a la cual hemos llegado para algunas posicion l l -> indice que
    // nos produjo dicha r
    int l = 1, r = 1;
    p[0] = a.length();  // Ya que el substring mas largo empezando en posicion 0
                        // es el string entero
    FOR(i, 1, a.length()) {
        int t = min(p[i - l], max(0, r - i));
        while (t + i < a.length() && a[t + i] == a[t]) t++;
        p[i] = t;
        if (i + t > r) {
            l = i;
            r = i + t;
        }
    }
    // Ejemplo de problemas:
    // Encuentra todos los sufijos de un string que tambien sean prefijos
    // (usamos Z function y cada i tal que i+p[i]>=a.length() es parte es la
    // respuesta) Curiosamente Z function tambien se puede usar como alternativa
    // a KMP, haciendo lo mismo concatenamos y ponemos un valor basura entre
    // ellos, todas las p[i] con valor igual a b.length son respuestas (excepto
    // p[0])

    // Identificar todos los palindromos de un string
    // Se puede resolver con un DP en tiempo O(N^2)
    // Decimos se dp[i][j] tiene true si el substring [i,j] es un palindromo
    // Si el substring [i][j] es un palindromo implica que el substring [i+1,
    // j-1] es un palindromo y que s[i]==s[j] dp[i][j] = dp[i + 1][j - 1] &&
    // a[i] == a[j]

    // Manacher, es tiempo lineal, usa la misma idea que z function donde tiene
    // un rango l,r y se sabe que como ya se tienen las respuestas se reusan
    // Primero, para evitar manejar palindromos de longitud par e impar se
    // pretende que todos son de longitud impar, asi que se agregan caracteres
    // de escape entre cada par de caracteres abacabadfdsf ->
    // a$b$a$c$a$b$a$d$f$d$s$f
    //   			   1 3 1 7 1 3 1 1 3 1 1 1
    // Algo asi se veria p**, por supuesto que depende de como lo implementemos
    // los '$' pueden ser parte del valor en p o no
    // **Faltan las respuestas de los $, no las puse para que no se vea muy
    // apretado, pero tambien tienen que ir
    a = "abacabadfdsf";
    string s = "";
    s += a[0];
    // Construimos S
    FOR(i, 1, a.length()) {
        s += "$";
        s += a[i];
    }
    // Algo asi seria calcular p en tiempo O(N^2), sin usar dp
    FOR(i, 0, s.length()) {
        int j = 0;
        while (i + j < s.length() && i - j >= 0 && s[i - j] == s[i + j]) j++;
        p[i] = j;
    }
    // Manacher, variacion de Z function
    l = 0, r = 0;
    FOR(i, 0, s.length()) {
        int j = i - l;
        int t = min(p[l - j], r - i);
        while (i + t < s.length() && i - t >= 0 && s[i + t] == s[i - t]) t++;
        p[i] = t;
        if (i + t > r) {
            l = i;
            r = i + t;
        }
    }
    // Ahora, para el largo verdadero de cada palindromo hay que notar si en la
    // posicion i hay '$' o un caracter normal, es decir si es palindromo
    // longitud par o impar. Subproblemas:
    //	1) Encuentra el palindromo mas largo de un string de tama�o 10^5
    //  2) Encuentra TODOS los palindromos de un string de tama�o 10^5

    // Hash strings
    // Usamos modulos primos
    // 10^9+7
    // 10^9+9
    // Usualmente queremos usar la siguiente ecuacion: x=(a*x+b+v)%p
    // donde x es el hash hasta el momento
    // p es el modulo y sera un numero primo
    // b es un numero cualquiera relativamente chico (preferentemente primo)
    // v es el valor del caracter en la posicion i
    // a es un numero primo menor a p y preferentemente b+v<a
    // Por ejemplo si tenemos un string de longitud 10^5 y queremos hashear
    // todos sus prefijos/sufijos
    // por paradoja del cumplea�os usar 10^9+7 implica que si tenemos mas de
    // 7*10^4 valores hay approx 50% de probabilidades de una colision falsa.
    // Podemos lidiar con esto si la longitud del string es muy chica, por
    // ejemplo 10^3 o si usamos multiples hashes
    ll x = 0, y = 0, MOD1 = 1000000007, MOD2 = 1000000009;
    map<ii, int> m;
    map<string, int> m2;
    FOR(i, 0, s.length()) {
        x = (47 * x + 17 + (s[i] - 'a')) % MOD1;
        y = (71 * y + 19 + (s[i] - 'a')) % MOD2;
        // Para que haya un falso positivo ocupamos que lo sea en tanto en x
        // como en y. Usar 2 hashes implica que las probabilidades se
        // decrementan considerablemente. Para 10^5 strings en vez de que la
        // probabilidad de colision sea mayor a 50% se vuelve muy peque�a, casi
        // 0 Hay que recordar que podemos usar K hashes diferentes, aunque esto
        // vuelve la complejidad de tiempo N*K
        m[ii(x, y)]++;
    }
    // Ejemplos de problemas donde hashear es util:
    // Dados 2 strings encontrar el substring mas largo de B que es parte un
    // substring de A
    return 0;
}
