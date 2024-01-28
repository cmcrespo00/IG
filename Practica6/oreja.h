// #############################################################################
//
// Informática Gráfica (Grado Informática)
//
// Archivo: oreja.h
//
// #############################################################################
#ifndef OREJA_H_INCLUDED
#define OREJA_H_INCLUDED

#include "auxiliar.h"

// *****************************************************************************
//
// clase derivada de ObjRevolucion
//
// *****************************************************************************
class Oreja : public ObjRevolucion{
  public:
    Oreja(const int num_vert_perfil, const int num_instancias_perf, const float radio);
};

#endif
