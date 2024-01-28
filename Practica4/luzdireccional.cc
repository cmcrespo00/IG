#include "auxiliar.h"
#include "luz.h"
#include "luzdireccional.h"

LuzDireccional::LuzDireccional(const Tupla2f & orientacion){
  alpha = orientacion[0];
  beta = orientacion[1];

  calcularCoordenadasCartesianas();
}

LuzDireccional::LuzDireccional(const Tupla2f & orientacion, GLenum idLuzOpenGL, Tupla4f colorAmb, Tupla4f colorEsp, Tupla4f colorDif){
  alpha = orientacion[0];
  beta = orientacion[1];

  calcularCoordenadasCartesianas();

  id = idLuzOpenGL;

  colorAmbiente = colorAmb;
  colorEspecular = colorEsp;
  colorDifuso = colorDif;
}

void LuzDireccional::variarAnguloAlpha(float incremento){
  alpha += incremento;
  calcularCoordenadasCartesianas();
}

void LuzDireccional::variarAnguloBeta(float incremento){
  beta += incremento;
  calcularCoordenadasCartesianas();
}

//Pasar de coordenadas esfericas a coordenadas cartesianas
void LuzDireccional::calcularCoordenadasCartesianas(){
  float a = alpha * (2*M_PI/360),
        b = beta * (2*M_PI/360);
  posicion[0] = sin(a) * cos(b);
  posicion[1] = sin(a) * sin(b);
  posicion[2] = cos(a);
  posicion[3] = 0.0;
}

void LuzDireccional::animarLuzDireccionalColor(float incremento){
  for (int i = 0; i < 3; i++) {
    colorDifuso[i] += incremento;
    if(colorDifuso[i] < 0)
      colorDifuso[i] = 0;

    if(colorDifuso[i] > 1)
      colorDifuso[i] = 1;
  }
}
