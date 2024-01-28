#include "auxiliar.h"
#include "malla.h"
#include "material.h"

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

  if(colorMalla[0] == -1 || colorMalla[1] == -1 || colorMalla[2] == -1){
    colorMalla = color;
  }

  if(iluminacion){
    setMaterialC();
    material.aplicar();

    //Aplicar Normales
    if (id_vbo_nv == 0)
      id_vbo_nv = CrearVBO(GL_ARRAY_BUFFER, nv.size()*3*sizeof(float), nv.data());

    // activar buffer: VBO de normales
    glBindBuffer ( GL_ARRAY_BUFFER , id_vbo_nv );
    // usar como buffer de normales el actualmente activo
    glNormalPointer(GL_FLOAT, 0, 0);
    // habilitar el uso de tabla de normales
    glEnableClientState(GL_NORMAL_ARRAY);
  } else {
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
  }

  /**********************************Texturas**********************************/
  if(textura != nullptr){
    textura->activar();

    //Aplicar Texturas
    if (id_vbo_ct == 0)
      id_vbo_ct = CrearVBO(GL_ARRAY_BUFFER, ct.size()*2*sizeof(float), ct.data());

    // activar buffer: VBO de texturas
    glBindBuffer ( GL_ARRAY_BUFFER , id_vbo_ct );
    // usar como buffer de texturas el actualmente activo
    glTexCoordPointer ( 2 , GL_FLOAT , 0 , 0 );
    // habilitar el uso de tabla de texturas
    glEnableClientState(GL_TEXTURE_COORD_ARRAY);
  } else {
    glDisable(GL_TEXTURE_2D);     //Deshabilitar texturas
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
  colorMalla = color;
  Tupla3f color_lineas;
  Tupla3f color_puntos;

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

void Malla3D::calcularNormales(){
  /****************************************************************************/
  //Variables para calcular las normales de las caras
  std::vector<Tupla3f> nc;
  Tupla3f vertice_p,
          vertice_q,
          vertice_r;

  Tupla3f mc,
          vector_nc,
          vector_a,
          vector_b;

  //Variables para calcular las normales de los vertices
  std::vector<Tupla3f> mv;

  /****************************************************************************/
  //Crear normales de las caras
  nc.clear();

  for(int i = 0; i < f.size(); i++){
    vertice_p = v[(f[i][0])];
    vertice_q = v[(f[i][1])];
    vertice_r = v[(f[i][2])];

    for(int j = 0; j < 3; j++){
      vector_a[j] = vertice_q[j] - vertice_p[j];
      vector_b[j] = vertice_r[j] - vertice_p[j];
    }

    mc = vector_a.cross(vector_b);                      //Producto vectorial
    if (mc[0] != 0 || mc[1] != 0 || mc[2] != 0)
      vector_nc = mc.normalized();                      //Normalizar vector

    nc.push_back(vector_nc);
  }

  //Crear normales de los vertices
  nv.clear();
  nv.resize(v.size());
  mv.clear();
  mv.resize(v.size());
  int identif_vertice, _a, identif_vertice_b, identif_vertice_c;

  for (int i = 0; i < f.size(); i++) {
    for (int j = 0; j < 3; j++){
      identif_vertice = f[i][j];
      for (int k = 0; k < 3; k++)
        mv[identif_vertice][k] += nc[i][k];
    }
  }

    //Normalizar resultado
  for (int i = 0; i < nv.size(); i++){
    if (mv[i][0] != 0 || mv[i][1] != 0 || mv[i][2] != 0)
      nv[i] = mv[i].normalized();
  }
}

//Función para asignar un material a la malla
void Malla3D::setMaterial(Material m){
  material.setMaterial(m);
}

//FUnción para asignar un material a partir de su color a un malla
void Malla3D::setMaterialC(){
  material.setMaterialC(colorMalla);
}

//Función para asignar un material a la malla
void Malla3D::setTextura(Textura *t){
  textura = t;
}
//Función para asignar un material a la malla
void Malla3D::multiplicarCoordenadasTextura(float multiplo){
  for (int i = 0; i < ct.size(); i++) {
    ct[i][0] *= multiplo;
    ct[i][1] *= multiplo;
  }
}

void Malla3D::ponerAmarillo(){
  colorOriginal = colorMalla;
  setColor(amarillo);
}

void Malla3D::reestablecerColor(){
  setColor(colorOriginal);
}

void Malla3D::seleccionable(){
  glScalef(1.01, 1.01, 1.01);
  /**************************************************************************/
  int tam = 3;
  std::vector<Tupla3f> c_seleccionable;
  glLineWidth(1);
  glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

  if (id_vbo_ver == 0)
    id_vbo_ver = CrearVBO(GL_ARRAY_BUFFER, v.size()*3*sizeof(float), v.data());
  if (id_vbo_tri == 0)
    id_vbo_tri = CrearVBO(GL_ELEMENT_ARRAY_BUFFER, f.size()*3*sizeof(int), f.data());

  if(id_vbo_col_seleccionable == 0.0){
    c_seleccionable.resize(tam);
    for(int i = 0; i < tam; i++)
      c_seleccionable[i] = amarilloClaro;

    id_vbo_col_seleccionable = CrearVBO(GL_ARRAY_BUFFER, c.size()*3*sizeof(float), c_seleccionable.data());
  }

  if ( id_vbo_col_seleccionable != 0 ) {
    // habilitar uso de array de colores
    glEnableClientState ( GL_COLOR_ARRAY );
    // especifícar cual es el VBO que vamos a usar
    glBindBuffer ( GL_ARRAY_BUFFER , id_vbo_col_seleccionable );
    // Usar el buffer activo para el color
    glColorPointer ( 3 , GL_FLOAT , 0 , 0 );
  }

  /*****************************************************************/
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

  glLineWidth(1);
  glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
}
