// #############################################################################
//
// Informática Gráfica (Grado Informática)
//
// Archivo: brazo.h
//
// #############################################################################

#ifndef BRAZO_H_INCLUDED
#define BRAZO_H_INCLUDED

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

class Brazo : public Malla3D {
  private:
    Tupla3f color;
    float giroBrazoZ;
    float giroBrazoX;

    SemiEsfera * semiEsfera = nullptr ; // es importante inicializarlo a 'nullptr'
    Cilindro * cilindro = nullptr ; // es importante inicializarlo a 'nullptr'
    ConoTruncado * conoTruncado = nullptr ; // es importante inicializarlo a 'nullptr'
  public:
    Brazo(Tupla3f c = {1, 1, 1});
    void draw(bool ilu);

    void moverBrazo(int coordenada, float incremento);
} ;

#endif
