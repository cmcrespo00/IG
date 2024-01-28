#include "auxiliar.h"
#include "objrevolucion.h"
#include "oreja.h"

Oreja::Oreja(const int num_vert_perfil, const int num_instancias_perf, const float radio){
  std::vector<Tupla3f> perfil_original;
  float radio_menor = radio / 3,
        x, y;
  int tam = num_vert_perfil - 2;

  float angulo = (M_PI/2) / (tam+2);

  perfil_original.clear();
  perfil_original.resize(num_vert_perfil);

  for(int i = 0; i < tam; i++){
    x = radio_menor * sin(angulo * i);
    y = radio + (radio_menor * cos(angulo * i));
    perfil_original[i] = { x, y, 0 };
  }

  perfil_original[num_vert_perfil - 2] = { radio, 0, 0 };
  perfil_original[num_vert_perfil - 1] = { 0, 0, 0 };

  crearMalla(perfil_original, num_instancias_perf);
}
