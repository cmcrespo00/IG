#include "auxiliar.h"
#include "material.h"


Material::Material(Tupla4f mAmbiente, Tupla4f mDifuso, Tupla4f mEspecular, float bril){
  ambiente = mAmbiente;
  difuso = mDifuso;
  especular = mEspecular;
  if(bril <= 128.0 && bril >= 0.0)
    brillo = bril;
}

void Material::aplicar(){
  glMaterialfv( GL_FRONT_AND_BACK, GL_AMBIENT, ambiente );
  glMaterialfv( GL_FRONT_AND_BACK, GL_SPECULAR, especular );
  glMaterialfv( GL_FRONT_AND_BACK, GL_DIFFUSE, difuso );
  glMaterialf( GL_FRONT_AND_BACK, GL_SHININESS, brillo );
}

void Material::setMaterial(Material mat){
  ambiente = mat.ambiente;
  difuso = mat.difuso;
  especular = mat.especular;
  brillo = mat.brillo;
}


void Material::setMaterialC(Tupla3f color, float bri){
  Tupla4f colorRGBA, colorRGBA2, colorRGBA3;
  for (int i = 0; i < 3; i++) {
    colorRGBA[i] = color[i];
    colorRGBA2[i] = color[i] * 0.2;
    colorRGBA3[i] = color[i] * 1.2;
    if(colorRGBA3[i] > 1){
      colorRGBA3[i] = 1;
    }
  }

  colorRGBA[3] = 1.0;
  colorRGBA2[3] = 1.0;
  colorRGBA3[3] = 1.0;

  ambiente = colorRGBA2;
  difuso = colorRGBA;
  especular = colorRGBA3;
  brillo = bri;
}
