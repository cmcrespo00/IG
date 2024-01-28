#include "auxiliar.h"
#include "malla.h"
#include "brazo.h"

Brazo::Brazo(Tupla3f c){
  color = c;
  semiEsfera = new SemiEsfera(20, 20, 1);
  cilindro = new Cilindro(20, 20, 1, 1);
  conoTruncado = new ConoTruncado(20, 20, 1, 1, 1.5);

  giroBrazoZ = 60.0;
  giroBrazoX = 0.0;
}

void Brazo::draw(bool ilu){
  glPushMatrix();
    glRotatef(giroBrazoZ, 0, 0, 1);
    glRotatef(giroBrazoX, 1, 0, 0);
    glTranslatef(0, -4, 0);

    conoTruncado->draw(ilu, color);

    glPushMatrix();
      glScalef(1.5, 2, 1);
      glRotatef(180, 0, 0, 1);
      semiEsfera->draw(ilu, color);
    glPopMatrix();

    glPushMatrix();
      glTranslatef(0, 1, 0);
      glScalef(1, 3, 1);
      cilindro->draw(ilu, color);
    glPopMatrix();

    glPushMatrix();
      glTranslatef(1.25, 0, 0);
      glScalef(0.75, 0.5, 0.5);
      glRotatef(270, 0, 0, 1);
      semiEsfera->draw(ilu, color);
    glPopMatrix();
  glPopMatrix();
}

void Brazo::moverBrazo(int coordenada, float incremento){
  if (coordenada == 1){
    giroBrazoX += incremento;
    if(giroBrazoX > 45.0)
      giroBrazoX = 45.0;
    if(giroBrazoX < -45.0)
      giroBrazoX = -45.0;
  } else if (coordenada == 3){
    giroBrazoZ += incremento;
    if(giroBrazoZ > 135.0)
      giroBrazoZ = 135.0;
    if(giroBrazoZ < 50.0)
      giroBrazoZ = 50.0;
  }
}
