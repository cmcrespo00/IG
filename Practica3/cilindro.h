// #############################################################################
//
// Informática Gráfica (Grado Informática)
//
// Archivo: cilindro.h
//
// #############################################################################
#ifndef CILINDRO_H_INCLUDED
#define CILINDRO_H_INCLUDED

#include "auxiliar.h"

// *****************************************************************************
//
// clase derivada de ObjRevolucion
//
// *****************************************************************************
class Cilindro : public ObjRevolucion{
  public:
    Cilindro (const int num_vert_perfil, const int num_instancias_perf, const float altura, const float radio);
};

#endif
