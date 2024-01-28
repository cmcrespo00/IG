#include "auxiliar.h"
#include "malla.h"
#include "lazo.h"

Lazo::Lazo(Tupla3f c){
  esfera = new Esfera(20, 20, 1);
  semiEsfera = new SemiEsfera(20, 20, 1);
  cono = new Cono(20, 20, 1, 1);

  color = c;
  for (int i = 0; i < 3; i++)
    colorOscuro[i] = 0.6 * c[i];
}

void Lazo::draw(bool ilu){
  glPushMatrix();
    glRotatef(320, 0, 0, 1);
    drawParteLazo(ilu);

    glPushMatrix();
      glRotatef(180, 0, 1, 0);
      drawParteLazo(ilu);
    glPopMatrix();

    glPushMatrix();
      glScalef(0.75, 0.75, 0.75);
      esfera->draw(ilu, colorOscuro);
    glPopMatrix();
  glPopMatrix();
}

void Lazo::drawParteLazo(bool ilu){
  glPushMatrix();
    glTranslatef(3, 0, 0);
    glRotatef(90, 0, 0, 1);

    glPushMatrix();
      glScalef(2, 1, 1);
      glRotatef(180, 0, 0, 1);
      semiEsfera->draw(ilu, color);
    glPopMatrix();

    glPushMatrix();
      glScalef(2, 3, 1);
      cono->draw(ilu, color);
    glPopMatrix();
  glPopMatrix();
}
