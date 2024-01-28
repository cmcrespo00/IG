#include "auxiliar.h"     // includes de OpenGL/glut/glew, windows, y librería std de C++
#include "escena.h"
#include "malla.h" // objetos: Cubo y otros....
#include "luz.h"

//**************************************************************************
// constructor de la escena (no puede usar ordenes de OpenGL)
//**************************************************************************
Escena::Escena() {
  Front_plane       = 50.0;
  Back_plane        = 2000.0;
  Observer_distance = 4*Front_plane;
  Observer_angle_x  = 0.0 ;
  Observer_angle_y  = 0.0 ;
  ejes.changeAxisSize( 5000 );
  // crear los objetos de la escena....
  // .......completar: ...
  // .....
  cubo = new Cubo(30);
  piramide = new PiramidePentagonal(30, 15);
  cono = new Cono(20, 20, 30, 15);
  cilindro = new Cilindro(20, 20, 30, 15);
  esfera = new Esfera(20, 50, 15);
  peonN = new ObjRevolucion(archivo_peon, 20);
  peonB = new ObjRevolucion(archivo_peon, 20);

  //Inicializar luces
  luzPos = new LuzPosicional({100.0,50.0,0.0}, GL_LIGHT0, negro4, blanco4, blanco4);
  luzDir = new LuzDireccional({9.0,180.0}, GL_LIGHT1, negro4, negro4, blanco4);
}

//**************************************************************************
// inicialización de la escena (se ejecuta cuando ya se ha creado la ventana, por
// tanto sí puede ejecutar ordenes de OpenGL)
// Principalmemnte, inicializa OpenGL y la transf. de vista y proyección
//**************************************************************************
void Escena::inicializar( int UI_window_width, int UI_window_height ) {
  //glClearColor( 1.0, 1.0, 1.0, 1.0 );// se indica cual sera el color para limpiar la ventana	(r,v,a,al)
  glClearColor( 0.5, 0.5, 0.5, 0.5 );// se indica cual sera el color para limpiar la ventana	(r,v,a,al)

	glEnable( GL_DEPTH_TEST );	// se habilita el z-bufer

  /*--------------------------HABILITAR GL_CULL_FACE--------------------------*/
  glEnable(GL_CULL_FACE);
  /*------------------------HABILITAR EL GL_NORMALIZE-------------------------*/
  glEnable(GL_NORMALIZE);

	Width  = UI_window_width/10;
	Height = UI_window_height/10;

  change_projection( float(UI_window_width)/float(UI_window_height) );
	glViewport( 0, 0, UI_window_width, UI_window_height );
}

// **************************************************************************
//
// función de dibujo de la escena: limpia ventana, fija cámara, dibuja ejes,
// y dibuja los objetos
//
// **************************************************************************
void Escena::dibujar() {
  glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT ); // Limpiar la pantalla
  change_observer();

  glLineWidth(1);
  glPointSize(1);
  glShadeModel(GL_FLAT);
  glDisable(GL_LIGHTING);
  ejes.draw();

  // COMPLETAR
  //   Dibujar los diferentes elementos de la escena
  // Habrá que tener en esta primera práctica una variable que indique qué objeto se ha de visualizar
  // y hacer

  if (menuVisualizacionActivo[3]){
    glEnable(GL_LIGHTING);

    if(lucesEscena[0])
      luzPos->activar();
    else
      glDisable(GL_LIGHT0);

    if(lucesEscena[1])
      luzDir->activar();
    else
      glDisable(GL_LIGHT1);

    glShadeModel(GL_SMOOTH);
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    dibujarObjetos();

  } else {
    glDisable(GL_LIGHTING);
    if (menuVisualizacionActivo[0]){
      glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
      //dibujarObjetoSelec();
      dibujarObjetos();
    }
    if (menuVisualizacionActivo[1]){
      glLineWidth(3);
      glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
      //dibujarObjetoSelec();
      dibujarObjetos();
    }
    if (menuVisualizacionActivo[2]){
      glPointSize(5);
      glPolygonMode(GL_FRONT_AND_BACK, GL_POINT);
      //dibujarObjetoSelec();
      dibujarObjetos();
    }
  }
}

// **************************************************************************
//
// función que dibuja los objetos
//
// **************************************************************************
void Escena::dibujarObjetos() {
  if (modoMenuObjeto == CUBO){
    cubo->draw(menuVisualizacionActivo[3]);
  } else if (modoMenuObjeto == PIRAMIDE){
    piramide->draw(menuVisualizacionActivo[3], celeste);
  } else if (modoMenuObjeto == OBJETOS){
    glPushMatrix();
      glTranslatef(20, 0, 20);
      glScalef(5, 5, 5);
      peonN->draw(menuVisualizacionActivo[3], negro);
    glPopMatrix();

    glPushMatrix();
      glTranslatef(50, 0, 20);
      glScalef(5, 5, 5);
      peonB->draw(menuVisualizacionActivo[3], blanco);
    glPopMatrix();

    glPushMatrix();
      glTranslatef(-100, 0, -25);
      cubo->draw(menuVisualizacionActivo[3]);
    glPopMatrix();

    glPushMatrix();
      glTranslatef(-50, 0, 0);
      piramide->draw(menuVisualizacionActivo[3], celeste);
    glPopMatrix();

    glPushMatrix();
      glTranslatef(-100, 0, 50);
      cono->draw(menuVisualizacionActivo[3], rojo);
    glPopMatrix();

    glPushMatrix();
      glTranslatef(100, 0, 50);
      cilindro->draw(menuVisualizacionActivo[3], verde);
    glPopMatrix();

    glPushMatrix();
      glTranslatef(100, 15, -25);
      esfera->draw(menuVisualizacionActivo[3], rosa);
    glPopMatrix();
  }
}

// **************************************************************************
//
// función que dibuja el objeto seleccionado
//
// **************************************************************************
void Escena::dibujarObjetoSeleccionado() {
  if (modoMenuObjeto == CUBO)
    cubo->draw(menuVisualizacionActivo[3]);
  if (modoMenuObjeto == PIRAMIDE)
    piramide->draw(menuVisualizacionActivo[3], celeste);
}

//**************************************************************************
//
// función que se invoca cuando se pulsa una tecla
// Devuelve true si se ha pulsado la tecla para terminar el programa (Q),
// devuelve false en otro caso.
//
//**************************************************************************
bool Escena::teclaPulsada( unsigned char tecla, int x, int y ) {
  using namespace std ;
  cout << "Tecla pulsada: '" << tecla << "'" << endl;
  bool salir=false;

  switch (modoMenu) {
    case NADA:
      switch( toupper(tecla) ) {
        case 'Q' :
          salir=true ;
          break ;
        case 'O' :
          // ESTAMOS EN MODO SELECCION DE OBJETO
          modoMenu=SELOBJETO;
          modoMenuObjeto=OBJETOS;
          break ;
        case 'V' :
          // ESTAMOS EN MODO SELECCION DE MODO DE VISUALIZACION
          modoMenu=SELVISUALIZACION;
          break ;
      }
      break;

    /*----------------------------------------------------------------------------*/
    case SELOBJETO:
      switch( toupper(tecla) ) {
        case 'Q' :
          modoMenu=NADA;
          break ;
        case 'C' :
          // SE SELECCIONA PARA VISUALIZAR EL CUBO
          if(modoMenuObjeto == CUBO)
            modoMenuObjeto = NOOBJETO;
          else
            modoMenuObjeto = CUBO;
          break ;
        case 'P' :
          // SE SELECCIONA PARA VISUALIZAR LA PIRAMIDE
          if(modoMenuObjeto == PIRAMIDE)
            modoMenuObjeto=NOOBJETO;
          else
            modoMenuObjeto=PIRAMIDE;
          break ;
        case 'J' :
          // SE SELECCIONA PARA VISUALIZAR EL CUBO
          if(modoMenuObjeto == OBJETOS)
            modoMenuObjeto = NOOBJETO;
          else
            modoMenuObjeto = OBJETOS;
          break ;
      }
      break;

    /*----------------------------------------------------------------------------*/
    case SELVISUALIZACION:
      switch( toupper(tecla) ) {
        case 'Q':
          modoMenu=NADA;
          break;
        case 'P':
          if(menuVisualizacionActivo[2])
            menuVisualizacionActivo[2] = false;
          else
            menuVisualizacionActivo[2] = true;
          break;

        case 'L':
          if(menuVisualizacionActivo[1])
            menuVisualizacionActivo[1] = false;
          else
            menuVisualizacionActivo[1] = true;
          break;

        case 'S':
          if(menuVisualizacionActivo[0])
            menuVisualizacionActivo[0] = false;
          else
            menuVisualizacionActivo[0] = true;
          break;

        case 'I':
          if(menuVisualizacionActivo[3])
            menuVisualizacionActivo[3] = false;
          else
            menuVisualizacionActivo[3] = true;
          break;
      }

      if(menuVisualizacionActivo[3]){
        switch( toupper(tecla) ) {
          case '0':
            if(lucesEscena[0])
              lucesEscena[0] = false;
            else
              lucesEscena[0] = true;
            break;
          case '1':
            if(lucesEscena[1])
              lucesEscena[1] = false;
            else
              lucesEscena[1] = true;
            break;

          case 'A':
            modoMenuAngulo = ALFA;
            break;
          case 'B':
            modoMenuAngulo = BETA;
            break;
          case '>':
            if(modoMenuAngulo == ALFA)
              luzDir->variarAnguloAlpha(incremento);
            else if(modoMenuAngulo == BETA)
              luzDir->variarAnguloBeta(incremento);
            break;
          case '<':
            if(modoMenuAngulo == ALFA)
              luzDir->variarAnguloAlpha(-1 * incremento);
            else if(modoMenuAngulo == BETA)
              luzDir->variarAnguloBeta(-1 * incremento);
            break;
        }
      }
      break;
  }

  return salir;
}

//**************************************************************************
void Escena::teclaEspecial( int Tecla1, int x, int y ) {
  switch ( Tecla1 ) {
    case GLUT_KEY_LEFT:
      Observer_angle_y-- ;
      break;
    case GLUT_KEY_RIGHT:
      Observer_angle_y++ ;
      break;
    case GLUT_KEY_UP:
      Observer_angle_x-- ;
      break;
    case GLUT_KEY_DOWN:
      Observer_angle_x++ ;
      break;
    case GLUT_KEY_PAGE_UP:
      Observer_distance *=1.2 ;
      break;
    case GLUT_KEY_PAGE_DOWN:
      Observer_distance /= 1.2 ;
      break;
  }

  //std::cout << Observer_distance << std::endl;
}

//**************************************************************************
// Funcion para definir la transformación de proyeccion
//
// ratio_xy : relacción de aspecto del viewport ( == ancho(X) / alto(Y) )
//
//***************************************************************************
void Escena::change_projection( const float ratio_xy ) {
  glMatrixMode( GL_PROJECTION );
  glLoadIdentity();
  const float wx = float(Height)*ratio_xy ;
  glFrustum( -wx, wx, -Height, Height, Front_plane, Back_plane );
}

//**************************************************************************
// Funcion que se invoca cuando cambia el tamaño de la ventana
//***************************************************************************
void Escena::redimensionar( int newWidth, int newHeight ) {
  Width  = newWidth/10;
  Height = newHeight/10;
  change_projection( float(newHeight)/float(newWidth) );
  glViewport( 0, 0, newWidth, newHeight );
}

//**************************************************************************
// Funcion para definir la transformación de vista (posicionar la camara)
//***************************************************************************
void Escena::change_observer() {
  // posicion del observador
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glTranslatef( 0.0, 0.0, -Observer_distance );
  glRotatef( Observer_angle_y, 0.0 ,1.0, 0.0 );
  glRotatef( Observer_angle_x, 1.0, 0.0, 0.0 );
}
