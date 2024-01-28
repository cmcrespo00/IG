#include "auxiliar.h"
#include "textura.h"

Textura::Textura(std::string archivo){
  unsigned char *pixel;

  //Declarar puntero a imagen (pimg)
  jpg::Imagen *pimg = NULL;

  //Cargar la imagen (una sola vez!)
  pimg = new jpg::Imagen(archivo);

  //usar con:
  width = pimg->tamX();           //num.columnas (unsigned)
  height = pimg->tamY();          //num.filas (unsigned)

  //data = pimg->leerPixels();    //puntero texels (unsigned char*)
  for(int i = 0; i < height; i++) {
    for(int j = 0; j < width; j++) {
      pixel=pimg->leerPixel(j, (height-1-i));
      data.push_back(*(pixel));
      data.push_back(*(pixel+1));
      data.push_back(*(pixel+2));
    }
  }
}

void Textura::activar(){
  glEnable ( GL_TEXTURE_2D ) ;

  if(textura_id == 0){
    glGenTextures ( 1 , &textura_id );              //Generar Identificador único
    glBindTexture ( GL_TEXTURE_2D , textura_id ); // activa textura con id 'textura_id'
    gluBuild2DMipmaps ( GL_TEXTURE_2D, GL_RGB, width, height, GL_RGB, GL_UNSIGNED_BYTE, data.data() );
  }

  glBindTexture ( GL_TEXTURE_2D , textura_id ); // activa textura con id 'textura_id'

  /*glLightModeli( GL_LIGHT_MODEL_COLOR_CONTROL, GL_SINGLE_COLOR);
  glLightModeli(GL_LIGHT_MODEL_COLOR_CONTROL, GL_SEPARATE_SPECULAR_COLOR);*/

  glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR );
  glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR );

  glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT );

}
