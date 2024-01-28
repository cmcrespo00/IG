// #############################################################################
//
// Informática Gráfica (Grado Informática)
//
// Archivo: luz.h
//
// #############################################################################

#ifndef LUZ_H_INCLUDED
#define LUZ_H_INCLUDED

#include "auxiliar.h"

// *****************************************************************************
//
// clases derivadas de Luz (definen constructores específicos)
//
// *****************************************************************************

// *****************************************************************************

class Luz {
  protected:
    GLenum id;
    Tupla4f colorAmbiente;
    Tupla4f colorDifuso;
    Tupla4f colorEspecular;
    Tupla4f posicion;
  public:
    void activar();
};

#endif
