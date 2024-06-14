#ifndef declaracion_h
#define declaracion_h

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

    virtual void calificar(double newCalificacion);
    virtual void MostrarDatos();
    virtual double obtenerPromedioCalificacion();
};

class Pelicula : public Video {
public:
    Pelicula(string id, string titulo, string genero, int duracion, double calificacion);
    void MostrarDatos() override;
};

class Episodio : public Video {
public:
    int temporada;

    Episodio(string id, string titulo, int temporada, int duracion, double calificacion);

    void MostrarDatos() override;
    void calificar(double newCalificacion) override;
    double obtenerPromedioCalificacion() override;
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
    vector<Pelicula*> peliculas;
    vector<Serie*> series;

    void AgregarVideo(Video* video);
    void AgregarPelicula(Pelicula* pelicula);
    void AgregarSerie(Serie* serie);
    void MostrarVideos(double calificacion, string genero);
    void MostrarPeliculas(double calificacion, string genero);
    void MostrarSeries(double calificacion, string genero);
    void MostrarEpisodios(string tituloSerie, double calificacion);
    void CalificarVideo(string titulo, double nuevaCalificacion);
};

#endif
