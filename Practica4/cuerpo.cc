#include "auxiliar.h"
#include "malla.h"
#include "cuerpo.h"

Cuerpo::Cuerpo(){
  brazoDer = new Brazo(colorCuerpo);
  brazoIzq = new Brazo(colorCuerpo);
  piernaDer = new Pierna(colorCuerpo);
  piernaIzq = new Pierna(colorCuerpo);
  conoTruncado = new ConoTruncado(20, 20, 7, 3, 6);
  semiEsfera = new SemiEsfera(20, 20, 1);
}

void Cuerpo::draw(bool ilu){
  glPushMatrix();
    drawTronco(ilu);

    glPushMatrix();
      glTranslatef(-2, 0, 0);
      piernaDer->draw(ilu);
    glPopMatrix();

    glPushMatrix();
      glTranslatef(2, 0, 0);
      piernaIzq->draw(ilu);
    glPopMatrix();

    glPushMatrix();
      glTranslatef(-3.5, 4, 0);
      glRotatef(180, 0, 1, 0);
      brazoDer->draw(ilu);
    glPopMatrix();

    glPushMatrix();
      glTranslatef(3.5, 4, 0);
      brazoIzq->draw(ilu);
    glPopMatrix();
  glPopMatrix();
}

void Cuerpo::drawTronco(bool ilu){
  glPushMatrix();
    conoTruncado->draw(ilu, colorVestido);

    glPushMatrix();
      glScalef(6, 3, 6);
      glRotatef(180, 0, 0, 1);
      semiEsfera->draw(ilu, colorCuerpo);
    glPopMatrix();
  glPopMatrix();
}

void Cuerpo::moverBrazoDerecho(int coordenada, float incrementoGiro){
  brazoDer->moverBrazo(coordenada, incrementoGiro);
}

void Cuerpo::moverBrazoIzquierdo(int coordenada, float incrementoGiro){
  if(coordenada == 1)
    brazoIzq->moverBrazo(coordenada, incrementoGiro);
  if(coordenada == 3)
    brazoIzq->moverBrazo(coordenada, (-1 * incrementoGiro));
}

void Cuerpo::moverPiernaDerecho(float incrementoGiro){
  piernaDer->moverPierna(incrementoGiro);
}

void Cuerpo::moverPiernaIzquierdo(float incrementoGiro){
  piernaIzq->moverPierna(incrementoGiro);
}
