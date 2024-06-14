//Declaración de clases header

#ifndef declaracion_h
#define declaracion_h

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

    void calificar(double NewCalificacion);
    virtual void MostrarDatos();
};


class Pelicula : public Video {
    //Atributos
    public:

    //Constructor de la clase
    //Hereda los atributos de la clase Video 
    Pelicula(string id, string titulo, string genero, double calificacion);

    void MostrarDatos() override();
};


class Serie : public Video {
    //Atributos
    public:
    int episodios;

    //Constructor de la clase 
    //Hereda los atributos de la clase Video 
    Serie(string id, string titulo, string genero, double calificacion, int episodios);

    void MostrarDatos() override();
};

class Plataforma {
    //Atributos
    public:
    vector<Video*> videos;

    //Metodos para filtrar los videos
    void AgregarVideo(Video* video);
    void MostrarVideos(double calificacion, string enero);
    void MostrarPeliculas(double calificacion, string genero);
    void MostrarSeries(double calificacion, string genero);  //Sus episodios
};

#endif 



