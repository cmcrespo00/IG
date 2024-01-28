// #############################################################################
//
// Informática Gráfica (Grado Informática)
//
// Archivo: semiesfera.h
//
// #############################################################################

#ifndef SEMIESFERA_H_INCLUDED
#define SEMIESFERA_H_INCLUDED

#include "auxiliar.h"

// *****************************************************************************
//
// clase derivada de ObjRevolucion
//
// *****************************************************************************
class SemiEsfera : public ObjRevolucion{
  public:
    SemiEsfera (const int num_vert_perfil, const int num_instancias_perf, const float radio);
};

#endif
