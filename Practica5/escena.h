#ifndef _ESCENA_H
#define _ESCENA_H

#include "ejes.h"
#include "malla.h"
#include "cubo.h"
#include "piramidepentagonal.h"
#include "objrevolucion.h"
#include "objply.h"
#include "cilindro.h"
#include "cono.h"
#include "conotruncado.h"
#include "esfera.h"
#include "semiesfera.h"
#include "peon.h"
#include "hellokitty.h"
#include "luz.h"
#include "luzposicional.h"
#include "luzdireccional.h"
#include "textura.h"
#include "suelo.h"


typedef enum {NADA, SELOBJETO,SELVISUALIZACION, AUTOMATICO, MANUAL} menu;
typedef enum {NOOBJETO, CUBO, PIRAMIDE, OBJETOS, HELLOKITTY, PELOTA} menuObjeto;
typedef enum {ALFA, BETA} menuAngulo;
class Escena {
  private:
    // ** PARÁMETROS DE LA CÁMARA (PROVISIONAL)
      // variables que definen la posicion de la camara en coordenadas polares
    GLfloat Observer_distance;
    GLfloat Observer_angle_x;
    GLfloat Observer_angle_y;

      // variables que controlan la ventana y la transformacion de perspectiva
    GLfloat Width, Height, Front_plane, Back_plane;

      // Transformación de cámara
    void change_projection( const float ratio_xy );
    void change_observer();

    void clear_window();

    //Inicializar enum
    menu modoMenu = NADA;
    menuObjeto modoMenuObjeto=OBJETOS;
    menuAngulo modoMenuAngulo=ALFA;
                                     //SOLIDO LINEAS PUNTOS ILUMINACION
    bool menuVisualizacionActivo[4] = {true,  false, false, true};
    bool lucesEscena[8] = {true, true, false, false, false, false, false, false};
    bool gradoLibertad[11] = {false, false, false, false, false, false, false, false, false, false, false};
    bool gradoLibertadAuto[4] = {true, false, true, false};
    bool animarLuzP = false;

    // Objetos de la escena
    Ejes ejes;
    Cubo *cubo = nullptr ; // es importante inicializarlo a 'nullptr'
    PiramidePentagonal *piramide = nullptr ; // es importante inicializarlo a 'nullptr'
    Cono *cono = nullptr ; // es importante inicializarlo a 'nullptr'
    ConoTruncado *conoTruncado = nullptr ; // es importante inicializarlo a 'nullptr'
    Cilindro *cilindro = nullptr ; // es importante inicializarlo a 'nullptr'
    Esfera *esfera = nullptr ; // es importante inicializarlo a 'nullptr'
    SemiEsfera *semiEsfera = nullptr ; // es importante inicializarlo a 'nullptr'
    ObjRevolucion *peonB = nullptr ; // es importante inicializarlo a 'nullptr'
    ObjRevolucion *peonN = nullptr ; // es importante inicializarlo a 'nullptr'
    HelloKitty *helloKitty = nullptr ; // es importante inicializarlo a 'nullptr'
    Suelo *cesped = nullptr ; // es importante inicializarlo a 'nullptr'
    Suelo *tierra = nullptr ; // es importante inicializarlo a 'nullptr'
    Esfera *pelota = nullptr ; // es importante inicializarlo a 'nullptr'

    //Texturas
    Textura *textCesped = nullptr;
    Textura *textTierra = nullptr;
    Textura *textPelota = nullptr;

    //Colores
    Tupla3f negro = {0, 0, 0},
            blanco = {1, 1, 1},
            rojo = {1, 0, 0},
            verde = {0, 1, 0},
            azul = {0, 0, 1},
            amarillo = {1, 1, 0},
            moradoClaro = {0.8, 0.66, 0.86},
            celeste = {0.53, 0.8, 0.92},
            rosa = {1, 0, 0.5};

    Tupla4f negro4 = {0.0, 0.0, 0.0, 1.0},
            blanco4 = {1.0, 1.0, 1.0, 1.0},
            rosa4 = {1.0, 0.0, 0.5, 1.0};

    /********************************ArchivosPLY*******************************/
    const std::string archivo_peon = "plys/peon";

    /***********************************Luces**********************************/
    float incremento = 5.0;
    LuzDireccional * luzDir = nullptr;
    LuzPosicional * luzPos = nullptr;

    /*********************************Animación********************************/
    float incrementoGradoMovimiento = 5.0;

    void dibujarObjetos();
    void dibujarObjetoSeleccionado();
    void iluminarObjetos();

  public:
    Escena();
    void inicializar( int UI_window_width, int UI_window_height );
    void redimensionar( int newWidth, int newHeight ) ;

    // Dibujar
    void dibujar();

    //Animar objeto
    void animarModeloJerarquico();
    void animarLuzPuntual();

    // Interacción con la escena
    bool teclaPulsada( unsigned char Tecla1, int x, int y ) ;
    void teclaEspecial( int Tecla1, int x, int y );
};
#endif
