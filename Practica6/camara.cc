#include "auxiliar.h"
#include "camara.h"

Camara::Camara(Tupla3f e, Tupla3f a, Tupla3f u, int ti, float l, float r, float to, float b, float n, float f){
  eye = e;
  at = a;
  up = u;
  tipo = ti;
  left = l;
  right = r;
  top  = to;
  bottom = b;
  near = n;
  far = f;
}

void Camara::rotarXExaminar(float angle){
  Tupla3f VPN = eye - at;

  eye[1] = VPN[1]*cosf(angle)-VPN[2]*sinf(angle);
  eye[2] = VPN[1]*sinf(angle)+VPN[2]*cosf(angle);
}

void Camara::rotarYExaminar(float angle){
  Tupla3f VPN = eye - at;

  eye[0] = VPN[0]*cosf(angle)-VPN[2]*sinf(angle);
  eye[2] = VPN[0]*sinf(angle)+VPN[2]*cosf(angle);
}

void Camara::rotarZExaminar(float angle){
  Tupla3f VPN = eye - at;

  eye[0] = VPN[0]*cosf(angle)-VPN[1]*sinf(angle);
  eye[1] = VPN[0]*sinf(angle)+VPN[1]*cosf(angle);
}


void Camara::rotarXFirstPerson(float angle){
  at[0] += angle;
}

void Camara::rotarYFirstPerson(float angle){
  at[1] += angle;
}

void Camara::rotarZFirstPerson(float angle){
  at[2] += angle;
}


void Camara::mover(float x, float y, float z){
  at[0] = x;
  at[1] = y;
  at[2] = z;
}

void Camara::zoom(float factor){
  left *= factor;
  right *= factor;
  top  *= factor;
  bottom *= factor;

  setProyeccion();
}

void Camara::setObserver(){
  gluLookAt (eye[0], eye[1], eye[2], at[0], at[1], at[2], up[0], up[1], up[2]);
}

void Camara::setProyeccion(){
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();

  if(tipo == 0)
    glOrtho(left, right, bottom, top, near, far);
  if(tipo == 1)
    glFrustum(left, right, bottom, top, near, far);
}

void Camara::setAt(Tupla3f a){
  for (int i = 0; i < 3; i++)
    at[i] = a[i];
}
