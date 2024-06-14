#ifndef DECLARACION_H
#define DECLARACION_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Video {
public:
    string id;
    string titulo;
    string genero;
    int duracion;
    double calificacion;
    int numCalificaciones;

    Video(string id, string titulo, string genero, int duracion, double calificacion);

    void calificar(double newCalificacion);
    virtual void MostrarDatos();
    double obtenerPromedioCalificacion();
};

class Pelicula : public Video {
public:
    Pelicula(string id, string titulo, string genero, int duracion, double calificacion);
    void MostrarDatos() override;
};

class Episodio {
public:
    string id;
    string titulo;
    int temporada;
    int duracion;
    double calificacion;
    int numCalificaciones;

    Episodio(string id, string titulo, int temporada, int duracion, double calificacion);
    void MostrarDatos();
    void calificar(double newCalificacion);
    double obtenerPromedioCalificacion();
};

class Serie : public Video {
public:
    int episodios;
    vector<Episodio> listaEpisodios;

    Serie(string id, string titulo, string genero, int duracion, double calificacion, int episodios, vector<Episodio> listaEpisodios);
    void MostrarDatos() override;
    void calificar(double newCalificacion) override;
    double obtenerPromedioCalificacion() override;
};

class Plataforma {
public:
    vector<Video*> videos;
    vector<Pelicula> peliculas;
    vector<Serie> series;

    void AgregarVideo(Video* video);
    void AgregarPelicula(Pelicula pelicula);
    void AgregarSerie(Serie serie);
    void MostrarVideos(double calificacion = 0, string genero = "");
    void MostrarPeliculas(double calificacion = 0, string genero = "");
    void MostrarSeries(double calificacion = 0, string genero = "");
    void MostrarEpisodios(string tituloSerie, double calificacion = 0);
    void CalificarVideo(string titulo, double nuevaCalificacion);
};

#endif // DECLARACION_H
