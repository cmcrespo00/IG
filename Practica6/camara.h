// #############################################################################
//
// Informática Gráfica (Grado Informática)
//
// Archivo: camara.h
//
// #############################################################################

#ifndef CAMARA_H_INCLUDED
#define CAMARA_H_INCLUDED

#include "auxiliar.h"

// *****************************************************************************
//
// clases Camara
//
// *****************************************************************************

// *****************************************************************************

class Camara {
  private:
    Tupla3f eye,
            at,
            up;
    int tipo;   //0-->ORTOGONAL
                //1-->PERSPECTIVA
    float left,          right,
          top,           bottom,
          near,          far;

  public:
    Camara(Tupla3f e, Tupla3f a, Tupla3f u, int ti,
            float l, float r, float to, float b, float n, float f);

    void rotarXExaminar(float angle);
    void rotarYExaminar(float angle);
    void rotarZExaminar(float angle);

    void rotarXFirstPerson(float angle);
    void rotarYFirstPerson(float angle);
    void rotarZFirstPerson(float angle);

    void mover(float x, float y, float z);

    void zoom(float factor);
    void setObserver();
    void setProyeccion();

    void setAt(Tupla3f a);
};

#endif
