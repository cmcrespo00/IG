#include "auxiliar.h"
#include "objrevolucion.h"
#include "peon.h"

Peon::Peon(const int num_vert_perfil, const int num_instancias_perf, const float tamano){
  std::vector<Tupla3f> perfil_original;
  float x, y;
  int tam = num_vert_perfil - 6;

  float radio = tamano/3,
        altura = tamano,
        radio_peq = tamano/4.5;

  float angulo = M_PI / tam;

  perfil_original.clear();

  for(int i = 0; i < tam; i++){
    x = radio_peq * sin(angulo * i);
    y = altura - (radio_peq * cos(angulo * i)) - tamano/15;

    perfil_original.push_back({ x, y, 0});
  }

  perfil_original.push_back({radio/2, 9*altura/12, 0});
  perfil_original.push_back({3*radio/4, 17*altura/24, 0});
  perfil_original.push_back({radio/2, 2*altura/3, 0});
  perfil_original.push_back({radio/2, altura/3, 0});
  perfil_original.push_back({radio, 0, 0});
  perfil_original.push_back({0, 0, 0});

  crearMalla(perfil_original, num_instancias_perf);
}
