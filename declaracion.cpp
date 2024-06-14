#include "declaracion.h"
#include <iostream>
using namespace std;

//Constructor de la clase Video
Video::Video(string id, string titulo, string genero, double calificacion) {
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
