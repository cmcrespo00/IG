// #############################################################################
//
// Informática Gráfica D (Grado Informática)
//
// Archivo: Malla3D.h
// -- declaraciones de clase Malla3D (mallas indexadas) y derivados
//
// #############################################################################

#ifndef MALLA3D_H_INCLUDED
#define MALLA3D_H_INCLUDED

#include "auxiliar.h"

// *****************************************************************************
//
// clase para objetos 3D (mallas indexadas)
//
// *****************************************************************************

class Malla3D {
  public:
    // función que dibuja el objeto en modo diferido (usando VBOs)
    void draw(bool iluminacion = false, Tupla3f color = {0.8,0.66,0.86});
    void setColor(Tupla3f color);

  protected:
    std::vector<Tupla3f> v;  // tabla de coordenadas de vértices (una tupla por vértice, con tres floats)
    std::vector<Tupla3i> f;  // una terna de 3 enteros por cada cara o triángulo
    std::vector<Tupla3f> c,
                         c_lineas,
                         c_puntos;
    // Completar P1: vbo y método asociado
    GLuint id_vbo_tri=0;
    GLuint id_vbo_ver=0;
    GLuint id_vbo_col=0,
           id_vbo_col_lineas=0,
           id_vbo_col_puntos=0;

      //ColorMalla
    Tupla3f colorMalla;
};

#endif
