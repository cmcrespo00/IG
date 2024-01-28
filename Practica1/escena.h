#ifndef _ESCENA_H
#define _ESCENA_H

#include "ejes.h"
#include "malla.h"
#include "cubo.h"
#include "piramidepentagonal.h"

typedef enum {NADA, SELOBJETO,SELVISUALIZACION} menu;
typedef enum {NOOBJETO, CUBO, PIRAMIDE} menuObjeto;
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
    menuObjeto modoMenuObjeto=CUBO;
    menuAngulo modoMenuAngulo=ALFA;
                                     //SOLIDO LINEAS PUNTOS
    bool menuVisualizacionActivo[3] = {true,  false, false};

    // Objetos de la escena
    Ejes ejes;
    Cubo *cubo = nullptr ; // es importante inicializarlo a 'nullptr'
    PiramidePentagonal *piramide = nullptr ; // es importante inicializarlo a 'nullptr'

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

    void dibujarObjetoSeleccionado();
  public:
    Escena();
    void inicializar( int UI_window_width, int UI_window_height );
    void redimensionar( int newWidth, int newHeight ) ;

    // Dibujar
    void dibujar();

    // Interacción con la escena
    bool teclaPulsada( unsigned char Tecla1, int x, int y ) ;
    void teclaEspecial( int Tecla1, int x, int y );
};
#endif
