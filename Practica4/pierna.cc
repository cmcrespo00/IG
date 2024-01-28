#include "auxiliar.h"
#include "malla.h"
#include "pierna.h"

Pierna::Pierna(Tupla3f c){
  color = c;
  semiEsfera = new SemiEsfera(20, 20, 1);
  cilindro = new Cilindro(20, 20, 1, 1);
  conoTruncado = new ConoTruncado(20, 20, 2, 1, 1.5) ;

  giroPierna = 0.0;
}

void Pierna::draw(bool ilu){
  glPushMatrix();
    glRotatef(giroPierna, 1, 0, 0);
    glTranslatef(0,-5,0);
    conoTruncado->draw(ilu, color);

    glPushMatrix();
      glScalef(1.5, 1, 1.5);
      glRotatef(180, 0, 0, 1);
      semiEsfera->draw(ilu, color);
    glPopMatrix();

    glPushMatrix();
      glTranslatef(0, 2, 0);
      glScalef(1, 3, 1);
      cilindro->draw(ilu, color);
    glPopMatrix();
  glPopMatrix();
}

void Pierna::moverPierna(float incremento){
  giroPierna += incremento;
  if(giroPierna > 30.0)
    giroPierna = 30.0;
  if(giroPierna < -50.0)
    giroPierna = -50.0;
}
