#include "declaracion.h"
#include <iostream>
using namespace std;

//Constructor de la clase Video
Video::Video(string id, string titulo, string genero, double calificacion) {
    //El usars this -> es para hacer referencia a los atributos de la clase y de esta forma no confundirlos con los parametros
    this->id = id;
    this->titulo = titulo;
    this->genero = genero;
    this->calificacion = calificacion;
}

//Metodo para calificar un video
void Video::calificar(double NewCalificacion) {
    this->calificacion = NewCalificacion;
}

//Metodo para mostrar los datos de un video
void Video::MostrarDatos() {
    cout << "ID: " << this->id << endl;
    cout << "Titulo: " << this->titulo << endl;
    cout << "Genero: " << this->genero << endl;
    cout << "Calificacion: " << this->calificacion << endl;
}

//Constructor de la clase Pelicula
Pelicula::Pelicula(string id, string titulo, string genero, double calificacion) : Video(id, titulo, genero, calificacion) {
}

//Constructor de la clase Serie
Serie::Serie(string id, string titulo, string genero, double calificacion, int episodios) : Video(id, titulo, genero, calificacion) {
    this->episodios = episodios;
}


//Se repite el metodo MostrarDatos de la clase Video pero para la clase Serie y Pelicula

//Metodo para mostrar los datos de una pelicula
void Pelicula::MostrarDatos() {
    cout << "ID: " << this->id << endl;
    cout << "Titulo: " << this->titulo << endl;
    cout << "Genero: " << this->genero << endl;
    cout << "Calificacion: " << this->calificacion << endl;
}

//Metodo para mostrar los datos de una serie
void Serie::MostrarDatos() {
    cout << "ID: " << this->id << endl;
    cout << "Titulo: " << this->titulo << endl;
    cout << "Genero: " << this->genero << endl;
    cout << "Calificacion: " << this->calificacion << endl;
    cout << "Episodios: " << this->episodios << endl;
}

//Metodo para agregar un video a la plataforma
void Plataforma::AgregarVideo(Video* video) {
    this->videos.push_back(video);
}

//Metodo para mostrar los videos de la plataforma
