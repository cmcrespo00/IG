#include "auxiliar.h"
#include "malla.h"

GLuint CrearVBO ( GLuint tipo_vbo , GLuint tam , GLvoid * puntero_ram ) {
  GLuint id_vbo;                                               // resultado: identificador de VBO
  glGenBuffers( 1, & id_vbo );                                 // crear nuevo VBO, obtener identificador
  glBindBuffer( tipo_vbo, id_vbo );                            // activar el VBO usando su identificador
  glBufferData( tipo_vbo, tam, puntero_ram, GL_STATIC_DRAW );  // esta instrucción hace la transferencia de datos desde RAM hacia GPU
  glBindBuffer( tipo_vbo, 0);                                  // desactivación del VBO (activar 0)
  return id_vbo ;                                              // devolver el identificador resultado
}

// *****************************************************************************
//
// IG_D Clase Malla3D
//
// *****************************************************************************
// -----------------------------------------------------------------------------
// Función de visualización de la malla,
void Malla3D::draw(bool iluminacion, Tupla3f color) {
  // (la primera vez, se deben crear los VBOs y guardar sus identificadores en el objeto)
  // completar (práctica 1)
  // .....
  if (id_vbo_ver == 0)
    id_vbo_ver = CrearVBO(GL_ARRAY_BUFFER, v.size()*3*sizeof(float), v.data());
  if (id_vbo_tri == 0)
    id_vbo_tri = CrearVBO(GL_ELEMENT_ARRAY_BUFFER, f.size()*3*sizeof(int), f.data());

  colorMalla = color;

  if (id_vbo_col == 0 || id_vbo_col_lineas == 0 || id_vbo_col_puntos == 0)
    setColor(colorMalla);

  GLint comprobacion[2] = {0,0};
  glGetIntegerv(GL_POLYGON_MODE, comprobacion); //Dibujando en solido -> 6914
                                                //Dibujando en lineas -> 6913
                                                //Dibujando en puntos -> 6912

  if ( id_vbo_col != 0 && id_vbo_col_lineas != 0 && id_vbo_col_puntos != 0) {
    // habilitar uso de array de colores
    glEnableClientState ( GL_COLOR_ARRAY );
    // especifícar cual es el VBO que vamos a usar
    switch (comprobacion[0]) {
      case 6914:
        glBindBuffer ( GL_ARRAY_BUFFER , id_vbo_col );
        break;
      case 6913:
        glBindBuffer ( GL_ARRAY_BUFFER , id_vbo_col_lineas );
        break;
      case 6912:
        glBindBuffer ( GL_ARRAY_BUFFER , id_vbo_col_puntos );
        break;
    }

    // Usar el buffer activo para el color
    glColorPointer ( 3 , GL_FLOAT , 0 , 0 );
  }

  /****************************************************************************/
  // activar buffer: VBO de vértices
  glBindBuffer ( GL_ARRAY_BUFFER , id_vbo_ver );
  // usar como buffer de vertices el actualmente activo
  glVertexPointer ( 3 , GL_FLOAT , 0 , 0 );
  // desactivar buffer: VBO de vértices.
  glBindBuffer ( GL_ARRAY_BUFFER , 0 );
  // habilitar el uso de tabla de vértices
  glEnableClientState ( GL_VERTEX_ARRAY );
  // activar buffer: VBO de triángulos
  glBindBuffer ( GL_ELEMENT_ARRAY_BUFFER , id_vbo_tri );
  // dibujar con el buffer de índices activo
  glDrawElements ( GL_TRIANGLES , 3 * f.size () , GL_UNSIGNED_INT , 0 ) ;
  // desactivar buffer: VBO de triángulos
  glBindBuffer ( GL_ELEMENT_ARRAY_BUFFER , 0 );
  // desactivar uso de array de vértices
  glDisableClientState ( GL_VERTEX_ARRAY );
}

//Función para modificar los colores de la malla
void Malla3D::setColor(Tupla3f color){
  Tupla3f color_lineas;
  Tupla3f color_puntos;

  colorMalla = color;

  int tam = v.size();

  if(colorMalla[0] == 0.0 && colorMalla[1] == 0.0 && colorMalla[2] == 0.0){
    for(int i = 0; i < 3; i++){
      color_lineas[i] = 0.25;
      color_puntos[i] = 0.5;
    }
  }else{
    for(int i = 0; i < 3; i++){
      color_lineas[i] = colorMalla[i] / 1.5;
      color_puntos[i] = colorMalla[i] / 2;
    }
  }

  c.resize(tam);
  c_lineas.resize(tam);
  c_puntos.resize(tam);
    for(int i = 0; i < tam; i++){
      c[i] = colorMalla;
      c_lineas[i] = color_lineas;
      c_puntos[i] = color_puntos;
    }

  id_vbo_col = CrearVBO(GL_ARRAY_BUFFER, c.size()*3*sizeof(float), c.data());
  id_vbo_col_lineas = CrearVBO(GL_ARRAY_BUFFER, c_lineas.size()*3*sizeof(float), c_lineas.data());
  id_vbo_col_puntos = CrearVBO(GL_ARRAY_BUFFER, c_puntos.size()*3*sizeof(float), c_puntos.data());
}
