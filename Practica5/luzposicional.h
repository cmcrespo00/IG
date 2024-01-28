// #############################################################################
//
// Informática Gráfica (Grado Informática)
//
// Archivo: luzposicional.h
//
// #############################################################################

#ifndef LUZPOSICIONAL_H_INCLUDED
#define LUZPOSICIONAL_H_INCLUDED

#include "auxiliar.h"

// *****************************************************************************
//
// clases derivadas de Luz (definen constructores específicos)
//
// *****************************************************************************

// *****************************************************************************

class LuzPosicional : public Luz {
  public:
    //Inicializar la fuente de luz
    LuzPosicional(const Tupla3f & pos);
    LuzPosicional(const Tupla3f & pos, GLenum idLuzOpenGL, Tupla4f colorAmb, Tupla4f colorEsp, Tupla4f colorDif);

    void animarLuzPosicional();
};

#endif
