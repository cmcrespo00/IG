#include "auxiliar.h"
#include "objrevolucion.h"
#include "ply_reader.h"

// *****************************************************************************
//
// Clase ObjRevolucion (práctica 2)
//
// *****************************************************************************

// *****************************************************************************
// objeto de revolución obtenido a partir de un perfil (en un PLY)
ObjRevolucion::ObjRevolucion() {}

ObjRevolucion::ObjRevolucion(const std::string & archivo, int num_instancias) {
  // completar ......(práctica 2)
  std::vector<Tupla3f> vertices;
  ply::read_vertices(archivo, vertices);
  crearMalla(vertices, num_instancias);
}

// *****************************************************************************
// objeto de revolución obtenido a partir de un perfil (en un vector de puntos)
ObjRevolucion::ObjRevolucion(std::vector<Tupla3f> archivo, int num_instancias) {
  crearMalla(archivo, num_instancias);
}

void ObjRevolucion::crearMalla(std::vector<Tupla3f> perfil_original, int num_instancias) {
  int N = num_instancias;
  int M = perfil_original.size();

  float angulo;
  Tupla3f ver_aux;
  Tupla3i tri_aux;

  bool poloSUR = false,
       poloNORTE = false;
  Tupla3f polo_sur,
          polo_norte;

  int a, b;

  v.clear();
  f.clear();

  //Comprobar que los vertices esten en orden descendente
  //En caso de no estar, invertir el ordenes
  //(Comparar la coordenada 'y' de el primer y el ultimo vertice del perfil_original)
  if(perfil_original[0][1] < perfil_original[M-1][1]){
    reverse(perfil_original.begin(), perfil_original.end());
  }

  //comprobacion POLOS
  if( (perfil_original[M-1][0] < 0.01 && perfil_original[M-1][0] > -0.01) && (perfil_original[M-1][2] < 0.01 && perfil_original[M-1][2] > -0.01) ){
    poloSUR = true;
    polo_sur = perfil_original[M-1];
    perfil_original.pop_back();
  }

  if( (perfil_original[0][0] < 0.01 && perfil_original[0][0] > -0.01) && (perfil_original[0][2] < 0.01 && perfil_original[0][2] > -0.01) ){
    poloNORTE = true;
    polo_norte = perfil_original[0];
    perfil_original.erase(perfil_original.begin());
  }

  M = perfil_original.size();
  /***************************************************************************/
  for (int i = 0; i <= (N - 1); i++){
    angulo = 2 * M_PI * i / N;
    for (int j = 0; j <= (M - 1); j++){
      ver_aux[0] = sin(angulo)*perfil_original[j][0] + cos(angulo)*perfil_original[j][2];
      ver_aux[1] = perfil_original[j][1];
      ver_aux[2] = -(cos(angulo)*perfil_original[j][0]) + sin(angulo)*perfil_original[j][2];
      v.push_back(ver_aux);
    }
  }

  for(int i = 0; i <= (N - 1); i++){
    for(int j = 0; j <= (M - 2); j++){
      a = M * i + j;
      b = M * ((i + 1) % N) + j;
      f.push_back({a, b, (b + 1)});
      f.push_back({a, (b + 1), (a + 1)});
    }
  }


  //POLOS
    //Polo SUR
  if(poloSUR){
    v.push_back(polo_sur);

    tri_aux[0] = N*M;

    for(int i = 0; i < N; i++){
      tri_aux[1] = M*(i+1)-1;
      tri_aux[2] = M*(((i+1)%N)+1)-1;
      f.push_back(tri_aux);
    }
  }

    //Polo NORTE
  if(poloNORTE){
    v.push_back(polo_norte);

    tri_aux[0] = N*M+1;

    for(int i = 0; i < N; i++){
      tri_aux[1] = M*((i+1)%N);
      tri_aux[2] = M*i;
      f.push_back(tri_aux);
    }
  }

  v.push_back(v[0]);
}
