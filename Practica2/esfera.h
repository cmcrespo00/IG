// #############################################################################
//
// Informática Gráfica (Grado Informática)
//
// Archivo: Esfera.h
//
// #############################################################################

#ifndef ESFERA_H_INCLUDED
#define ESFERA_H_INCLUDED

#include "auxiliar.h"

// *****************************************************************************
//
// clase derivada de ObjRevolucion
//
// *****************************************************************************
class Esfera : public ObjRevolucion{
  public:
    Esfera (const int num_vert_perfil, const int num_instancias_perf, const float radio);
};

#endif
