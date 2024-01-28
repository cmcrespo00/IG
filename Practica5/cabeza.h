// #############################################################################
//
// Informática Gráfica (Grado Informática)
//
// Archivo: cabeza.h
//
// #############################################################################

#ifndef CABEZA_H_INCLUDED
#define CABEZA_H_INCLUDED

#include "auxiliar.h"
#include "objrevolucion.h"
#include "malla.h"
#include "esfera.h"
#include "oreja.h"
#include "lazo.h"

// *****************************************************************************
//
// clases derivadas de Malla3D (definen constructores específicos)
//
// *****************************************************************************

class Cabeza : public Malla3D {
  private:
    Tupla3f colorLazo = {1, 0, 0.5},
            colorOjo = {0, 0, 0},
            colorNariz = {1, 1, 0},
            colorOreja = {1, 1, 1},
            colorCara = {1, 1, 1};

    float giroNegar,
          giroAfirmar,
          alturaOjo,
          posicionOjoD,
          posicionOjoI,
          aumento,
          aumentoBase;
    bool n;

    Esfera * esfera = nullptr ; // es importante inicializarlo a 'nullptr'
    Esfera * esferaOjo = nullptr ; // es importante inicializarlo a 'nullptr'
    Esfera * esferaNariz = nullptr ; // es importante inicializarlo a 'nullptr'
    Oreja * oreja = nullptr ; // es importante inicializarlo a 'nullptr'
    Lazo * lazo = nullptr ; // es importante inicializarlo a 'nullptr'

    void drawOjo(bool ilu);
    void drawNariz(bool ilu);
  public:
    Cabeza();
    void draw(bool ilu);
    void moverCabeza(int movimiento, float incremento);
    void moverOjo(float incremento);

    void moverCabezaAuto(int movimiento);

    void calcularVelocidad(float velocidad);
} ;

#endif
