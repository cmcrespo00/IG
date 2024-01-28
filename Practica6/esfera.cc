#include "auxiliar.h"
#include "objrevolucion.h"
#include "esfera.h"

Esfera::Esfera(const int num_vert_perfil, const int num_instancias_perf, const float radio){
  std::vector<Tupla3f> perfil_original;
  float x, y;
  int tam = num_vert_perfil;

  float angulo = M_PI / (tam-1);

  perfil_original.clear();
  perfil_original.resize(num_vert_perfil);

  for(int i = 0; i < tam; i++){
    x = radio * sin(angulo * i);
    y = radio * cos(angulo * i);
    perfil_original[i] = { x, y, 0};
  }

  crearMalla(perfil_original, num_instancias_perf);
}
