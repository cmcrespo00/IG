// #############################################################################
//
// Informática Gráfica (Grado Informática)
//
// Archivo: cuerpo.h
//
// #############################################################################

#ifndef CUERPO_H_INCLUDED
#define CUERPO_H_INCLUDED

#include "auxiliar.h"
#include "objrevolucion.h"
#include "malla.h"
#include "semiesfera.h"
#include "conotruncado.h"
#include "brazo.h"
#include "pierna.h"

// *****************************************************************************
//
// clases derivadas de Malla3D (definen constructores específicos)
//
// *****************************************************************************

class Cuerpo : public Malla3D {
  private:
    Tupla3f colorVestido = {1, 0, 0.5},
            colorCuerpo = {1, 1, 1};

    SemiEsfera * semiEsfera = nullptr ; // es importante inicializarlo a 'nullptr'
    ConoTruncado * conoTruncado = nullptr ; // es importante inicializarlo a 'nullptr'
    Brazo * brazoDer = nullptr ; // es importante inicializarlo a 'nullptr'
    Brazo * brazoIzq = nullptr ; // es importante inicializarlo a 'nullptr'
    Pierna * piernaDer = nullptr ; // es importante inicializarlo a 'nullptr'
    Pierna * piernaIzq = nullptr ; // es importante inicializarlo a 'nullptr'

    void drawTronco(bool ilu);
  public:
    Cuerpo();
    void draw(bool ilu);
    void moverBrazoDerecho(int coordenada, float incrementoGiro);
    void moverBrazoIzquierdo(int coordenada, float incrementoGiro);
    void moverPiernaDerecho(float incrementoGiro);
    void moverPiernaIzquierdo(float incrementoGiro);
} ;

#endif
