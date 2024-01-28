#include "auxiliar.h"
#include "luz.h"
#include "luzposicional.h"

LuzPosicional::LuzPosicional(const Tupla3f & pos){
  posicion[0] = pos[0];
  posicion[1] = pos[1];
  posicion[2] = pos[2];
  posicion[3] = 1.0;
}

LuzPosicional::LuzPosicional(const Tupla3f & pos, GLenum idLuzOpenGL, Tupla4f colorAmb, Tupla4f colorEsp, Tupla4f colorDif){
  posicion[0] = pos[0];
  posicion[1] = pos[1];
  posicion[2] = pos[2];
  posicion[3] = 1.0;

  id = idLuzOpenGL;

  colorAmbiente = colorAmb;
  colorEspecular = colorEsp;
  colorDifuso = colorDif;
}

void LuzPosicional::animarLuzPosicional(){
  float angulo = 2 * M_PI / 360;
  posicion[0] = posicion[0] * cos(angulo) + posicion[2] * sin(angulo);
  posicion[2] = posicion[0] * (-sin(angulo)) + posicion[2] * cos(angulo);
}
