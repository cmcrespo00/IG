// #############################################################################
//
// Informática Gráfica (Grado Informática)
//
// Archivo: hellokitty.h
//
// #############################################################################

#ifndef HELLOKITTY_H_INCLUDED
#define HELLOKITTY_H_INCLUDED

#include "auxiliar.h"
#include "objrevolucion.h"
#include "malla.h"
#include "cuerpo.h"
#include "cabeza.h"

// *****************************************************************************
//
// clases derivadas de Malla3D (definen constructores específicos)
//
// *****************************************************************************

class HelloKitty : public Malla3D {
  private:
    Cuerpo * cuerpo = nullptr ; // es importante inicializarlo a 'nullptr'
    Cabeza * cabeza = nullptr ; // es importante inicializarlo a 'nullptr'

    float aumento,
          aumentoBase,
          velocidad,
          desplazamiento,
          giroAndar,

    /************************************************************/
          aumentoBrazo,      aumentoPierna,
          aumentoBrazoBase,  aumentoPiernaBase,
          brazoMax,          piernaMax,
          brazoMin,          piernaMin,
          brazoDer,          piernaDer,
          brazoIzq,          piernaIzq;
    int b;

    void moverExtremidades(float incrementoBrazo, float incrementoPierna);
    void moverExtremidades_(float brazoD, float brazoI, float piernaD, float piernaI);
    void calcularAumento();
  public:
    HelloKitty();
    void draw(bool ilu = false);

    void moverBrazoDerecho(int coordenada, float incremento);
    void moverBrazoIzquierdo(int coordenada, float incremento);
    void moverPiernaDerecho(float incremento);
    void moverPiernaIzquierdo(float incremento);
    void moverCabeza(int movimiento, float incremento);
    void moverOjo(float incremento);

    void andar(float incremento);
    void andarAuto();

    void aumentarVelocidad();
    void disminuirVelocidad();

    void girar();

    void andarEnElSitio(float incremento);
    void andarAutoEnElSitio();
    void negarAuto();
    void afirmarAuto();
} ;

#endif
