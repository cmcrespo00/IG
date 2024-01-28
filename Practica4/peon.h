// #############################################################################
//
// Informática Gráfica (Grado Informática)
//
// Archivo: Peon.h
//
// #############################################################################

#ifndef PEON_H_INCLUDED
#define PEON_H_INCLUDED

#include "auxiliar.h"

// *****************************************************************************
//
// clase derivada de ObjRevolucion
//
// *****************************************************************************
class Peon : public ObjRevolucion{
  public:
    Peon (const int num_vert_perfil, const int num_instancias_perf, const float tamano);
};

#endif
