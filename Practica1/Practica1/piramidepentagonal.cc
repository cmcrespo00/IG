#include "auxiliar.h"
#include "malla.h"
#include "piramidepentagonal.h"

PiramidePentagonal::PiramidePentagonal(float h, float r) {
  float ang = (2 * M_PI)/5;
  // inicializar la tabla de vértices
  v.clear();
  v.resize(7);

    //Vertices Base
  v[0] = {0,                           0,   0};                         //Centro de la base
  v[1] = {float(-r * (sin(ang * 4))),  0,   float(-r * (cos(ang * 4)))};
  v[2] = {0,                           0,   -r};                        //Vertice "principal" (desde el que se calcula)
  v[3] = {float(-r * (sin(ang))),      0,   float(-r * (cos(ang)))};
  v[4] = {float(-r * (sin(ang * 2))),  0,   float(-r * (cos(ang * 2)))};
  v[5] = {float(-r * (sin(ang * 3))),  0,   float(-r * (cos(ang * 3)))};

    //Vertice superior
  v[6] = {0, h, 0};

  // inicializar la tabla de caras o triángulos:
  // (es importante en cada cara ordenar los vértices en sentido contrario
  //  de las agujas del reloj, cuando esa cara se observa desde el exterior del cubo)
  f.clear();
  f.resize(10);

    //Cara Base
  f[0] = {0,2,1};      //Triángulo 0, 2 y 1
  f[1] = {0,3,2};      //Triángulo 0, 3 y 2
  f[2] = {0,4,3};      //Triángulo 0, 4 y 3
  f[3] = {0,5,4};      //Triángulo 0, 5 y 4
  f[4] = {0,1,5};      //Triángulo 0, 1 y 5

    //Caras Piramide
  f[5] = {5,1,6};      //Triángulo 5, 1 y 6
  f[6] = {1,2,6};      //Triángulo 1, 2 y 6
  f[7] = {2,3,6};      //Triángulo 2, 3 y 6
  f[8] = {3,4,6};      //Triángulo 3, 4 y 6
  f[9] = {4,5,6};      //Triángulo 4, 5 y 6

  // inicializar la/s tabla/s de colores
  //setColor({0.53,0.8,0.92});
}
