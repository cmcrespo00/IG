#include "auxiliar.h"
#include "objrevolucion.h"
#include "cono.h"

Cono::Cono(const int num_vert_perfil, const int num_instancias_perf, const float altura, const float radio){
  std::vector<Tupla3f> perfil_original;
  float x, y;
  int tam = num_vert_perfil - 2;

  float radio_x = radio / (tam-1),
        altura_y = altura / (tam-1);

  perfil_original.clear();
  perfil_original.resize(num_vert_perfil);

  perfil_original[0] = {0, altura, 0};

  for(int i = 0; i < tam; i++){
    x = radio_x * i;
    y = altura - (altura_y * i);
    perfil_original[i+1] = {x, y, 0};
  }

  perfil_original[num_vert_perfil - 1] = {0, 0, 0};

  crearMalla(perfil_original, num_instancias_perf);
}
