// #############################################################################
//
// Informática Gráfica (Grado Informática)
//
// Archivo: lazo.h
//
// #############################################################################

#ifndef LAZO_H_INCLUDED
#define LAZO_H_INCLUDED

#include "malla.h"
#include "objrevolucion.h"
#include "cono.h"
#include "esfera.h"
#include "semiesfera.h"

// *****************************************************************************
//
// clases derivadas de Malla3D (definen constructores específicos)
//
// *****************************************************************************

class Lazo : public Malla3D {
  private:
    Tupla3f color;
    Tupla3f colorOscuro;
    Esfera * esfera = nullptr ; // es importante inicializarlo a 'nullptr'
    SemiEsfera * semiEsfera = nullptr ; // es importante inicializarlo a 'nullptr'
    Cono * cono = nullptr ; // es importante inicializarlo a 'nullptr'

    void drawParteLazo(bool ilu = false);
  public:
    Lazo(Tupla3f c = {1, 0, 0.5});
    void draw(bool ilu = false);
} ;

#endif
