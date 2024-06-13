//Declaración de clases header

#ifndef video_h
#define video_h

#include <iostream>
using namespace std;
#include <string>

class Video {
    //Atributos
    public:
    string id;
    string titulo;
    string genero;
    double calificacion;

    //Constructor de la clase
    Video(string id, string titulo, string genero, double calificacion);

    //Aquí iran las funciones generales
    void calificar(double NewCalificacion)
    
};

#endif 