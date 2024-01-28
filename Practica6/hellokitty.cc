#include "auxiliar.h"
#include "malla.h"
#include "hellokitty.h"


HelloKitty::HelloKitty(){
  cabeza = new Cabeza();
  cuerpo = new Cuerpo();

  desplazamiento = 0.0;
  giroAndar = 0.0;
  b = 0;
  aumentoBase = 1;
  aumentoBrazoBase = 6;
  aumentoPiernaBase = 4;
  aumento = 1;
  aumentoBrazo = 6;
  aumentoPierna = 4;
  velocidad = 1.0;
  brazoMax = 30.0;
  brazoMin = -30.0;
  piernaMax = 20.0;
  piernaMin = -20.0;
  brazoIzq = 0.0;
  piernaIzq = 0.0;
  brazoDer = 0.0;
  piernaDer = 0.0;
}

void HelloKitty::draw(bool ilu){
  glPushMatrix();
    glTranslatef(desplazamiento, 0, 0);
    glRotatef(giroAndar, 0, 1, 0);

    glPushMatrix();
      glTranslatef(0, 12, 0);
      cabeza->draw(ilu);
    glPopMatrix();

    glPushMatrix();
      cuerpo->draw(ilu);
    glPopMatrix();
  glPopMatrix();
}

void HelloKitty::moverBrazoDerecho(int coordenada, float incremento){
  cuerpo->moverBrazoDerecho(coordenada, incremento);
}

void HelloKitty::moverBrazoIzquierdo(int coordenada, float incremento){
  cuerpo->moverBrazoIzquierdo(coordenada, -1 * incremento);
}

void HelloKitty::moverPiernaDerecho(float incremento){
  cuerpo->moverPiernaDerecho(-1 * incremento);
}

void HelloKitty::moverPiernaIzquierdo(float incremento){
  cuerpo->moverPiernaIzquierdo(-1 * incremento);
}

void HelloKitty::moverCabeza(int movimiento, float incremento){
  cabeza->moverCabeza(movimiento, incremento);
}

void HelloKitty::moverOjo(float incremento){
  cabeza->moverOjo(incremento);
}

void HelloKitty::andar(float incremento){
  if(incremento < 0.0)
    giroAndar = 270.0;
  if(incremento > 0.0)
    giroAndar = 90.0;

  desplazamiento += incremento;
  if(desplazamiento > 50.0)
    desplazamiento = 50.0;
  if(desplazamiento < -50.0)
    desplazamiento = -50.0;

  moverExtremidades(6*incremento, 4*incremento);
}

void HelloKitty::andarEnElSitio(float incremento){
  moverExtremidades(6*incremento, 4*incremento);
}

void HelloKitty::andarAuto(){
  desplazamiento += aumento;
  if(desplazamiento > 50.0){
    giroAndar = 270.0;
    desplazamiento = 50.0;
    aumento = -1 * abs(aumento);
  }
  if(desplazamiento < -50.0){
    giroAndar = 90.0;
    desplazamiento = -50.0;
    aumento = abs(aumento);
  }

  moverExtremidades(aumentoBrazo, aumentoPierna);
}

void HelloKitty::andarAutoEnElSitio(){
  andarEnElSitio(aumento);
}

void HelloKitty::negarAuto(){
  cabeza->moverCabezaAuto(0);
}

void HelloKitty::afirmarAuto(){
  cabeza->moverCabezaAuto(1);
}

void HelloKitty::moverExtremidades(float incrementoBrazo, float incrementoPierna){
  if(incrementoBrazo < 0)
    incrementoBrazo = abs(incrementoBrazo);
  if(incrementoPierna < 0)
    incrementoPierna = abs(incrementoPierna);

  if(incrementoPierna > piernaMax)
    incrementoPierna = piernaMax;
  if(incrementoBrazo > brazoMax)
    incrementoBrazo = brazoMax;

  if(b == 0){
    brazoIzq += incrementoBrazo;
    piernaIzq += incrementoPierna;

    moverExtremidades_(brazoDer, brazoIzq, piernaDer, piernaIzq);
    if(brazoIzq >= brazoMax || piernaIzq >= piernaMax)
      b = 1;
  } else if(b == 1){
    brazoDer -= incrementoBrazo;
    piernaDer -= incrementoPierna;

    moverExtremidades_(brazoDer, brazoIzq, piernaDer, piernaIzq);
    if(brazoDer <= brazoMin || piernaDer <= piernaMin)
      b = 2;
  } else if(b == 2){
    brazoIzq -= incrementoBrazo;
    piernaIzq -= incrementoPierna;

    moverExtremidades_(brazoDer, brazoIzq, piernaDer, piernaIzq);
    if(brazoIzq >= 0 || piernaIzq >= 0)
      b = 3;
  } else if(b == 3){
    brazoDer += incrementoBrazo;
    piernaDer += incrementoPierna;

    moverExtremidades_(brazoDer, brazoIzq, piernaDer, piernaIzq);
    if(brazoDer <= 0 || piernaDer <= 0)
      b = 4;
  } else if(b == 4){
    brazoDer += incrementoBrazo;
    piernaDer += incrementoPierna;

    moverExtremidades_(brazoDer, brazoIzq, piernaDer, piernaIzq);
    if(brazoDer >= brazoMax || piernaDer >= piernaMax)
      b = 5;
  } else if(b == 5){
    brazoIzq -= incrementoBrazo;
    piernaIzq -= incrementoPierna;

    moverExtremidades_(brazoDer, brazoIzq, piernaDer, piernaIzq);
    if(brazoIzq <= brazoMin || piernaIzq <= piernaMin)
      b = 6;
  } else if(b == 6){
    brazoDer -= incrementoBrazo;
    piernaDer -= incrementoPierna;

    moverExtremidades_(brazoDer, brazoIzq, piernaDer, piernaIzq);
    if(brazoDer <= 0 || piernaDer <= 0)
      b = 7;
  } else if(b == 7){
    brazoIzq += incrementoBrazo;
    piernaIzq += incrementoPierna;

    moverExtremidades_(brazoDer, brazoIzq, piernaDer, piernaIzq);
    if(brazoIzq >= 0 || piernaIzq >= 0)
      b = 8;
  } else if(b == 8){
    brazoDer += incrementoBrazo;
    piernaDer += incrementoPierna;

    moverExtremidades_(brazoDer, brazoIzq, piernaDer, piernaIzq);
    if(brazoDer >= brazoMax || piernaDer >= piernaMax)
      b = 9;
  } else if(b == 9){
    brazoIzq -= incrementoBrazo;
    piernaIzq -= incrementoPierna;

    moverExtremidades_(brazoDer, brazoIzq, piernaDer, piernaIzq);
    if(brazoIzq <= brazoMin || piernaIzq <= piernaMin)
      b = 10;
  } else if(b == 10){
    brazoDer -= incrementoBrazo;
    piernaDer -= incrementoPierna;

    moverExtremidades_(brazoDer, brazoIzq, piernaDer, piernaIzq);
    if(brazoDer >= 0 || piernaDer >= 0)
      b = 11;
  } else if(b == 11){
    brazoIzq += incrementoBrazo;
    piernaIzq += incrementoPierna;

    moverExtremidades_(brazoDer, brazoIzq, piernaDer, piernaIzq);
    if(brazoIzq <= 0 || piernaIzq <= 0)
      b = 12;
  } else if(b == 12){
    brazoIzq += incrementoBrazo;
    piernaIzq += incrementoPierna;

    moverExtremidades_(brazoDer, brazoIzq, piernaDer, piernaIzq);
    if(brazoIzq >= brazoMax || piernaIzq >= piernaMax)
      b = 13;
  } else if(b == 13){
    brazoDer -= incrementoBrazo;
    piernaDer -= incrementoPierna;

    moverExtremidades_(brazoDer, brazoIzq, piernaDer, piernaIzq);
    if(brazoDer <= brazoMin || piernaDer <= piernaMin)
      b = 14;
  } else if(b == 14){
    brazoIzq -= incrementoBrazo;
    piernaIzq -= incrementoPierna;

    moverExtremidades_(brazoDer, brazoIzq, piernaDer, piernaIzq);
    if(brazoIzq <= 0 || piernaIzq <= 0)
      b = 15;
  } else if(b == 15){
    brazoDer += incrementoBrazo;
    piernaDer += incrementoPierna;

    moverExtremidades_(brazoDer, brazoIzq, piernaDer, piernaIzq);
    if(brazoDer >= 0 || piernaDer >= 0)
      b = 0;
  }
}

void HelloKitty::moverExtremidades_(float brazoD, float brazoI, float piernaD, float piernaI){
  moverBrazoIzquierdo(1, brazoI);
  moverBrazoDerecho(1, brazoD);
  moverPiernaIzquierdo(piernaI);
  moverPiernaDerecho(piernaD);
}

void HelloKitty::girar(){
  giroAndar = 0.0;
}

void HelloKitty::aumentarVelocidad(){
  velocidad += 0.1;
  calcularAumento();
}

void HelloKitty::disminuirVelocidad(){
  velocidad -= 0.1;
  if(velocidad < 0)
    velocidad = 0;
  calcularAumento();
}

void HelloKitty::calcularAumento(){
  if(aumento < 0)
    aumento = -1 * aumentoBase * velocidad;
  else
    aumento = aumentoBase * velocidad;

  if(aumentoBrazo < 0)
    aumentoBrazo = -1 * aumentoBrazoBase * velocidad;
  else
    aumentoBrazo = aumentoBrazoBase * velocidad;

  if(aumento < 0)
    aumentoPierna = -1 * aumentoPiernaBase * velocidad;
  else
    aumentoPierna = aumentoPiernaBase * velocidad;
    
  cabeza->calcularVelocidad(velocidad);
}
