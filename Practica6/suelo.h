// #############################################################################
//
// Informática Gráfica (Grado Informática)
//
// Archivo: suelo.h
//
// #############################################################################

#ifndef SUELO_H_INCLUDED
#define SUELO_H_INCLUDED

#include "auxiliar.h"
#include "malla.h"
// *****************************************************************************
//
// clases derivadas de Malla3D (definen constructores específicos)
//
// *****************************************************************************

class Suelo : public Malla3D {
  private:
    float lado = 300,
          profundidad = 200;
  public:
    Suelo();
} ;

#endif
