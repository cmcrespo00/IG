#include "auxiliar.h"
#include "malla.h"
#include "suelo.h"

Suelo::Suelo() {
  // inicializar la tabla de vértices
  v.clear();
  v.resize(4);
    //Vértices de la capa Superior
  v[0] = {-lado/2,   profundidad/2,  0};
  v[1] = {lado/2,   profundidad/2,  0};
  v[2] = {-lado/2,   -profundidad/2,  0};
  v[3] = {lado/2,   -profundidad/2,  0};

  // inicializar la tabla de caras o triángulos:
  f.clear();
  f.resize(2);

    //Cara Frontal
  f[0] = {2,0,1};
  f[1] = {1,3,2};

  calcularNormales();

  ct.resize(v.size());
  ct[0] = { 0, 0 };
  ct[1] = { 0, 1 };
  ct[2] = { 1, 0 };
  ct[3] = { 1, 1 };
}
