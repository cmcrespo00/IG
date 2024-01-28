// #############################################################################
//
// Informática Gráfica (Grado Informática)
//
// Archivo: material.h
//
// #############################################################################

#ifndef MATERIAL_H_INCLUDED
#define MATERIAL_H_INCLUDED

#include "auxiliar.h"
// *****************************************************************************

// *****************************************************************************
class Material {
  private:
    Tupla4f ambiente;
    Tupla4f difuso;
    Tupla4f especular;
    float brillo = 0.0; //Valor por defecto, y en caso de que se introduzca un valor erroneo
  public:
    Material(Tupla4f mAmbiente, Tupla4f mDifuso, Tupla4f mEspecular, float bril);
    void aplicar();
    void setMaterial(Material mat);
    void setMaterialC(Tupla3f color, float bri = 1.0);
};

#endif
