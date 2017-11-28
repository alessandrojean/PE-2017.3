#ifndef GEOMETRIA
#define GEOMETRIA

struct s_ponto {
  double x, y;
};

typedef struct s_ponto ponto;
typedef struct s_ponto vetor;

struct s_segmento {
  ponto p, q;
};

typedef struct s_segmento segmento;

struct s_triangulo {
  ponto p, q, r;
};

typedef struct s_triangulo triangulo;

//  Calcula a norma do vetor p
double norma(vetor p) {
    return sqrt(p.x * p.x + p.y * p.y);
}

//  Calcula o produto interno <u,v>
double produto_interno(vetor u, vetor v) {
    return u.x * v.x + u.y * v.y;
}

//  Calcula o vetor u - v
vetor subtrai(vetor u, vetor v) {
    u.x -= v.x;
    u.y -= v.y;

    return u;
}

/*  Calcula o vetor resultante da rotação do vetor v
    de um ângulo de 90 graus no sentido anti-horário. */
vetor roda90(vetor v) {
    vetor q = {-v.y, v.x};
    
    return q;
}

//  Calcula a distância entre os pontos p e q.
double distancia(ponto p, ponto q) {
    return sqrt(pow(q.x - p.x, 2) + pow(q.y - p.y, 2));
}

/*  Retorna 1 se o coseno do ângulo entre os vetores u e v é 
    positivo e retorna -1 se for negativo e 0 se for nulo. 
    Se u ou v for o vetor nulo, devolve 0. */
int sinal_do_coseno(vetor u, vetor v) {
    double pi = produto_interno(u, v);

    return (pi == 0.0) ? 0 : (pi > 0) ? 1 : -1;
}

/*  Retorna 1 se p, q e r estão em sentido horário e -1 se for
    anti-horário. Se os pontos forem colineares devolva 0. 
    Se dois desses pontos são iguais, devolve 0. */
int sentido(ponto p, ponto q, ponto r) {
    vetor v = {q.x - p.x, q.y - p.y};
    vetor u = {r.x - q.x, r.y - q.y};

    vetor vr = roda90(v);

    return - sinal_do_coseno(vr, u);
}

/*  Retorna 1 se os interiores dos segmentos se intersectam em
    um único ponto e retorna 0 caso contrário. */
int cruza(segmento s, segmento t) {
    int s1 = sentido(s.p, s.q, t.p);
    int s2 = sentido(s.p, s.q, t.q);
    int s3 = sentido(t.p, t.q, s.p);
    int s4 = sentido(t.p, t.q, s.q);

    return s1 != s2 && s3 != s4;
}

/*  Retorna 1 se o ponto p está no interior do triângulo t
    e retorna 0 caso contrário. */
int dentro(ponto p, triangulo t) {
    int s1 = sentido(t.p, p, t.q);
    int s2 = sentido(t.q, p, t.r);
    int s3 = sentido(t.r, p, t.p);

    return s1 == s2 && s2 == s3;
}

// Opcional:

/* Devolve o ponto em que s e t se intersectam caso cruza(s, t) 
   devolva 1 (ou seja, caso s e t se intersectem em um 
   único ponto no interior dos dois segmentos) e devolve 
   o ponto {0, 0} caso contrário. */
ponto cruzamento(segmento s, segmento t);

/* Calcula o ponto que é a projeção de p na reta que 
   contém o segmento s. */
ponto projeta(ponto p, segmento s) {
    vetor u = {s.q.x - s.p.x, s.q.y - s.p.y};
    vetor v = {p.x - s.p.x, p.y - s.p.y};

    double pi_uv = produto_interno(u, v);
    double pi_uu = produto_interno(u, u);

    ponto r;
    r.x = pi_uv / pi_uu * u.x;
    r.y = pi_uv / pi_uu * u.y;

    return r;
}

/*  Devolve 1 se o interior dos triângulos a e b se 
    intersectam e devolve 0 caso contrário. */
int intersecta(triangulo a, triangulo b);

#endif
