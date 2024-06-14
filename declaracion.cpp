#include "declaracion.h"
#include <iostream>
using namespace std;

//Constructor de la clase Video
Video::Video(string id, string titulo, string genero, int duracion, double calificacion) {
    id=id;
    titulo=titulo;
    genero=genero;
    int duracion=duracion;
    calificacion=calificacion;
}

//Metodo para calificar un video
void Video::calificar(double NewCalificacion) {
    calificacion=NewCalificacion;
}

//Metodo para mostrar los datos de un video
void Video::MostrarDatos() {
    cout << "ID: " << id << endl;
    cout << "Titulo: " << titulo << endl;
    cout << "Genero: " << genero << endl;
    cout << "Duracion: " << duracion << endl;
    cout << "Calificacion: " << calificacion << endl;
}

//Constructor de la clase Pelicula
Pelicula::Pelicula(string id, string titulo, string genero, int duracion, double calificacion) : Video(id, titulo, genero, duracion, calificacion) {
}

//Constructor de la clase Serie
Serie::Serie(string id, string titulo, string genero, int duracion, double calificacion, int episodios) : Video(id, titulo, genero, duracion, calificacion) {
    episodios = episodios;
}


//Se repite el metodo MostrarDatos de la clase Video pero para la clase Serie y Pelicula

//Metodo para mostrar los datos de una pelicula
void Pelicula::MostrarDatos() {
    cout<<"ID: "<<id<<endl;
    cout<<"Titulo: "<<titulo<<endl;
    cout<<"Genero: "<<genero<<endl;
    cout<<"Duracion: "<<duracion<<endl;
    cout<<"Calificacion: "<<calificacion<<endl;
}

//Metodo para mostrar los datos de una serie
void Serie::MostrarDatos() {
    cout<<"ID: "<<id<<endl;
    cout<<"Titulo: "<<titulo<<endl;
    cout<<"Genero: "<<genero<<endl;
    cout<<"Calificacion: "<<calificacion<<endl;
    cout<<"Episodios: "<<episodios<<endl;
}

//Metodo para agregar un video a la plataforma
void Plataforma::AgregarVideo(Video* video) {
    videos.push_back(video);
}

//Metodo para mostrar los videos de la plataforma
void Plataforma::MostrarVideos(double calificacion, string genero) {
    for (int i = 0; i < videos.size(); i++) {
        if (videos[i]->calificacion >= calificacion && videos[i]->genero == genero) {
            videos[i]->MostrarDatos();
        }
    }
}

//Metodo para mostrar las peliculas de la plataforma
void Plataforma::MostrarPeliculas(double calificacion, string genero) {
    for (int i = 0; i < videos.size(); i++) {
        if (videos[i]->calificacion >= calificacion && videos[i]->genero == genero) {
            videos[i]->MostrarDatos();
        }
    }
}

//Metodo para mostrar las series de la plataforma

//Lo que se pide es que se muestren las series que tengan una calificacion mayor o igual a la calificacion dada y que sean del genero dado 
void Plataforma::MostrarSeries(double calificacion, string genero) {
    for (int i = 0; i < videos.size(); i++) {
        if (videos[i]->calificacion >= calificacion && videos[i]->genero == genero) {
            videos[i]->MostrarDatos();
        }
    }
}

