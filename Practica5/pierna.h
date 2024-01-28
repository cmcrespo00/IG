// #############################################################################
//
// Informática Gráfica (Grado Informática)
//
// Archivo: pierna.h
//
// #############################################################################

#ifndef PIERNA_H_INCLUDED
#define PIERNA_H_INCLUDED

#include "auxiliar.h"
#include "objrevolucion.h"
#include "malla.h"
#include "semiesfera.h"
#include "conotruncado.h"
#include "cilindro.h"

// *****************************************************************************
//
// clases derivadas de Malla3D (definen constructores específicos)
//
// *****************************************************************************

class Pierna : public Malla3D {
  private:
    Tupla3f color;
    float giroPierna;

    SemiEsfera * semiEsfera = nullptr ; // es importante inicializarlo a 'nullptr'
    Cilindro * cilindro = nullptr ; // es importante inicializarlo a 'nullptr'
    ConoTruncado * conoTruncado = nullptr ; // es importante inicializarlo a 'nullptr'
  public:
    Pierna(Tupla3f c = {1, 1, 1});
    void draw(bool ilu);

    void moverPierna(float incremento);
} ;

#endif
