#include "auxiliar.h"
#include "malla.h"
#include "cabeza.h"


Cabeza::Cabeza(){
  esfera = new Esfera(20, 20, 1);
  esferaOjo = new Esfera(20, 20, 1);
  esferaNariz = new Esfera(20, 20, 1);
  oreja = new Oreja(20, 20, 1);
  lazo = new Lazo(colorLazo);

  giroNegar = 0;
  giroAfirmar = 0;
  alturaOjo = -1;
  posicionOjoD = -4;
  posicionOjoI = 4;
  n = false;
  aumento = 1;
  aumentoBase = 1;
}

void Cabeza::draw(bool ilu){
  glPushMatrix();
    glRotatef(giroNegar, 0, 1, 0);
    glRotatef(giroAfirmar, 1, 0, 0);
    glPushMatrix();
      glScalef(8, 6, 4);
      esfera->draw(ilu, colorCara);
    glPopMatrix();

    glPushMatrix();
      glTranslatef(5, 3, 3);
      lazo->draw(ilu);
    glPopMatrix();

    glPushMatrix();
      glTranslatef(posicionOjoD, alturaOjo, 3.5);
      drawOjo(ilu);
    glPopMatrix();

    glPushMatrix();
      glTranslatef(posicionOjoI, alturaOjo, 3.5);
      drawOjo(ilu);
    glPopMatrix();

    glPushMatrix();
      glTranslatef(0, -4, 3);
      drawNariz(ilu);
    glPopMatrix();

    glPushMatrix();
      glTranslatef(-4.5, 4, 0);
      glRotatef(40, 0, 0, 1);
      glScalef(3, 3, 2);
      oreja->draw(ilu, colorOreja);
    glPopMatrix();

    glPushMatrix();
      glTranslatef(4.5, 4, 0);
      glRotatef(320, 0, 0, 1);
      glScalef(3, 3, 2);
      oreja->draw(ilu, colorOreja);
    glPopMatrix();
  glPopMatrix();
}

void Cabeza::drawOjo(bool ilu){
  glPushMatrix();
    glScalef(0.5, 1, 0.5);
    esferaOjo->draw(ilu, colorOjo);
  glPopMatrix();
}

void Cabeza::drawNariz(bool ilu){
  glPushMatrix();
    glScalef(1, 0.5, 0.5);
    esferaNariz->draw(ilu, colorNariz);
  glPopMatrix();
}

void Cabeza::moverOjo(float incremento){
  alturaOjo += incremento;
  if(alturaOjo > -1)
    alturaOjo = -1;
  if(alturaOjo < -1.75)
    alturaOjo = -1.75;
  posicionOjoI += incremento;
  if(posicionOjoI > 4)
    posicionOjoI = 4;
  if(posicionOjoI < 3.25)
    posicionOjoI = 3.25;

  posicionOjoD = -1 * posicionOjoI;
}


/**
 * Movimiento == 0 --> Movimiento de negación
 * Movimiento == 1 --> Movimiento de afirmación
*/
void Cabeza::moverCabeza(int movimiento, float incremento){
  if (movimiento == 0){
    giroNegar += incremento;
    if(giroNegar > 25.0)
      giroNegar = 25.0;
    if(giroNegar < -25.0)
      giroNegar = -25.0;

    //MOVER OJOS AL NEGAR
    if(giroNegar >= 25 || giroNegar <= -25)
      n = false;
    else if(giroNegar == 0)
      n = true;
    if (n)
      moverOjo(abs(incremento) / (5/0.15));
    else
      moverOjo(-1 * (abs(incremento)) / (5/0.15));
  } else if (movimiento == 1){
    giroAfirmar += incremento;
    if(giroAfirmar > 15.0)
      giroAfirmar = 15.0;
    if(giroAfirmar < -15.0)
      giroAfirmar = -15.0;
  }
}

void Cabeza::moverCabezaAuto(int movimiento){
  if (movimiento == 0){
    if(giroNegar >= 25.0)
      aumento *= -1;
    if(giroNegar <= -25.0)
      aumento *= -1;

  } else if (movimiento == 1){
    if(giroAfirmar >= 15.0)
      aumento *= -1;
    if(giroAfirmar <= -15.0)
      aumento *= -1;
  }

  moverCabeza(movimiento, aumento);
}

void Cabeza::calcularVelocidad(float velocidad){
  if(aumento < 0)
    aumento = -1 * aumentoBase * velocidad;
  else
    aumento = aumentoBase * velocidad;
}
