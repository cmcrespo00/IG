// #############################################################################
//
// Informática Gráfica (Grado Informática)
//
// Archivo: cono.h
//
// #############################################################################
#ifndef CONO_H_INCLUDED
#define CONO_H_INCLUDED

#include "auxiliar.h"

// *****************************************************************************
//
// clase derivada de ObjRevolucion
//
// *****************************************************************************
class Cono : public ObjRevolucion{
  public:
    Cono (const int num_vert_perfil, const int num_instancias_perf, const float altura, const float radio);
};

#endif
