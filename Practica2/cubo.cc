#include "auxiliar.h"
#include "malla.h"
#include "cubo.h"

Cubo::Cubo(float lado) {
  // inicializar la tabla de vértices
  v.clear();
  v.resize(8);

    //Vértices de la Base
  v[0] = {-lado/2,  0,  lado/2};     //(-lado/2, -lado/2, lado/2)
  v[1] = {lado/2,   0,  lado/2};     //(lado/2, -lado/2, lado/2)
  v[2] = {lado/2,   0,  -lado/2};    //(lado/2, -lado/2, -lado/2)
  v[3] = {-lado/2,  0,  -lado/2};    //(-lado/2, -lado/2, -lado/2)

    //Vértices de la capa Superior
  v[4] = {-lado/2,  lado,   lado/2};     //(-lado/2, lado/2, lado/2)
  v[5] = {lado/2,   lado,   lado/2};     //(lado/2, lado/2, lado/2)
  v[6] = {lado/2,   lado,   -lado/2};    //(lado/2, lado/2, -lado/2)
  v[7] = {-lado/2,  lado,   -lado/2};    //(-lado/2, lado/2, -lado/2)

  // inicializar la tabla de caras o triángulos:
  // (es importante en cada cara ordenar los vértices en sentido contrario
  //  de las agujas del reloj, cuando esa cara se observa desde el exterior del cubo)
  f.clear();
  f.resize(12);

    //Cara Frontal
  f[0] = {0,1,4};      //Triángulo 0, 1 y 4
  f[1] = {1,5,4};      //Triángulo 1, 5 y 4

    //Cara Derecha
  f[2] = {1,2,5};      //Triángulo 1, 2 y 5
  f[3] = {2,6,5};      //Triángulo 2, 6 y 5

    //Cara Trasera
  f[4] = {2,3,6};      //Triángulo 2, 3 y 6
  f[5] = {3,7,6};      //Triángulo 3, 7 y 6

    //Cara Izquierda
  f[6] = {3,0,7};      //Triángulo 3, 0 y 7
  f[7] = {0,4,7};      //Triángulo 0, 4 y 7

    //Cara Base
  f[8] = {3,2,0};      //Triángulo 3, 2 y 0
  f[9] = {2,1,0};      //Triángulo 2, 1 y 0

    //Cara Superior
  f[10] = {4,5,7};      //Triángulo 4, 5 y 7
  f[11] = {5,6,7};      //Triángulo 5, 6 y 7
}
