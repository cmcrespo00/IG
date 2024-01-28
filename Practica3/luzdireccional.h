// #############################################################################
//
// Informática Gráfica (Grado Informática)
//
// Archivo: luzdireccional.h
//
// #############################################################################

#ifndef LUZDIRECCIONAL_H_INCLUDED
#define LUZDIRECCIONAL_H_INCLUDED

#include "auxiliar.h"

// *****************************************************************************
//
// clases derivadas de Luz (definen constructores específicos)
//
// *****************************************************************************

// *****************************************************************************

class LuzDireccional : public Luz {
protected:
  float alpha;
  float beta;

  void calcularCoordenadasCartesianas();
public:
  //Inicializar la fuente de luz
  LuzDireccional(const Tupla2f & orientacion);
  LuzDireccional(const Tupla2f & orientacion, GLenum idLuzOpenGL, Tupla4f colorAmb, Tupla4f colorEsp, Tupla4f colorDif);

  //Cambiar ángulo:
  void variarAnguloAlpha(float incremento);
  void variarAnguloBeta(float incremento);

  void animarLuzDireccionalColor(float incremento);
};

#endif
