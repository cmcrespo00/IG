// #############################################################################
//
// Informática Gráfica (Grado Informática)
//
// Archivo: conotruncado.h
//
// #############################################################################
#ifndef CONOTRUNCADO_H_INCLUDED
#define CONOTRUNCADO_H_INCLUDED

#include "auxiliar.h"

// *****************************************************************************
//
// clase derivada de ObjRevolucion
//
// *****************************************************************************
class ConoTruncado : public ObjRevolucion{
  public:
    ConoTruncado(const int num_vert_perfil, const int num_instancias_perf, const float altura, const float radio_menor, const float radio_mayor);
};

#endif
