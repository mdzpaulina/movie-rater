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

    virtual void MostrarDatos() const;
    virtual double obtenerPromedioCalificacion() const;

    // Sobrecarga del operador += para calificar el video
    virtual Video& operator+=(double newCalificacion);
};

class Pelicula : public Video {
public:
    Pelicula(string id, string titulo, string genero, int duracion, double calificacion);
    void MostrarDatos() const override;
};

class Episodio : public Video {
public:
    int temporada;

    Episodio(string id, string titulo, int temporada, int duracion, double calificacion);

    void MostrarDatos() const override;
    double obtenerPromedioCalificacion() const override;

    // Sobrecarga del operador += para calificar el episodio
    Episodio& operator+=(double newCalificacion) override;
};

class Serie : public Video {
public:
    int episodios;
    vector<Episodio> listaEpisodios;

    Serie(string id, string titulo, string genero, int duracion, double calificacion, int episodios, vector<Episodio> listaEpisodios);

    void MostrarDatos() const override;
    double obtenerPromedioCalificacion() const override;

    // Sobrecarga del operador += para calificar la serie
    Serie& operator+=(double newCalificacion) override;
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
