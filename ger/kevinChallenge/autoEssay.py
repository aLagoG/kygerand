from random import randint

phrases = [
    [
        "Una crítica a",
        "Una reflexión sobre",
        "Un acercamiento a",
        "Una asimilación de",
        "Una alegoría de",
        "Un redescubrimiento de"
    ],
    [
        "los lugares",
        "los espacios",
        "los vínculos",
        "los contrastes",
        "los lenguajes",
        "los valores"
    ],
   [
       "comunes",
       "fronterizos",
       "limítrofes",
       "encontrados",
       "deteriorados",
       "ultraperiféricos"
   ],
   [
       "del comunismo",
       "del costumbrismo",
       "de la experiencia",
       "de la cultura",
       "de la sociedad",
       "de la individualidad"
   ],
   [
       "postmodern",
       "colectiv",
       "deshumanizador",
       "dominante",
       "establecid",
       "hipersensorial"
   ]
]

def construct(probs):
    answ = []

    for i in range(len(probs)):
        print(i)
        answ.append( phrases[i][probs[i]] )

    if probs[-1] not in [3, 5]:
        answ[-1] += "a" if "de la" in answ[-2] else "o"

    return " ".join(answ)

def random_construct():
    return construct([randint(0, 5) for i in range(5)])

def all_iters():
    return [ construct([i, j, k, l, m]) for i in range(6) for j in range(6) for k in range(6) for l in range(6) for m in range(6) ]
