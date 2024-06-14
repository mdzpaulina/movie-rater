#include "declaracion.h"
#include <iostream>

using namespace std;

// Constructor de la clase Video
Video::Video(string id, string titulo, string genero, int duracion, double calificacion)
    : id(id), titulo(titulo), genero(genero), duracion(duracion), calificacion(calificacion), numCalificaciones(1) {}

// Método para calificar un video
void Video::calificar(double newCalificacion) {
    if (newCalificacion < 0 || newCalificacion > 5) {
        cout << "Calificación inválida. Debe estar entre 0 y 5." << endl;
        return;
    }
    calificacion = ((calificacion * numCalificaciones) + newCalificacion) / (++numCalificaciones);
}

// Método para mostrar los datos de un video
void Video::MostrarDatos() {
    cout << "ID: " << id << endl;
    cout << "Titulo: " << titulo << endl;
    cout << "Genero: " << genero << endl;
    cout << "Duracion: " << duracion << " minutos" << endl;
    cout << "Calificacion: " << calificacion << endl;
}

// Método para obtener el promedio de calificación de un video
double Video::obtenerPromedioCalificacion() {
    return calificacion;
}

// Constructor de la clase Pelicula
Pelicula::Pelicula(string id, string titulo, string genero, int duracion, double calificacion)
    : Video(id, titulo, genero, duracion, calificacion) {}

// Método para mostrar los datos de una película
void Pelicula::MostrarDatos() {
    Video::MostrarDatos();
}

// Constructor de la clase Episodio
Episodio::Episodio(string id, string titulo, int temporada, int duracion, double calificacion)
    : Video(id, titulo, "", duracion, calificacion), temporada(temporada) {}

// Método para mostrar los datos de un episodio
void Episodio::MostrarDatos() {
    cout << "  Episodio: " << titulo << ", Temporada: " << temporada << ", Duracion: " << duracion << " minutos, Calificacion: " << calificacion << endl;
}

// Método para calificar un episodio
void Episodio::calificar(double newCalificacion) {
    if (newCalificacion < 0 || newCalificacion > 5) {
        cout << "Calificación inválida. Debe estar entre 0 y 5." << endl;
        return;
    }
    calificacion = ((calificacion * numCalificaciones) + newCalificacion) / (++numCalificaciones);
}

// Método para obtener el promedio de calificación de un episodio
double Episodio::obtenerPromedioCalificacion() {
    return calificacion;
}

// Constructor de la clase Serie
Serie::Serie(string id, string titulo, string genero, int duracion, double calificacion, int episodios, vector<Episodio> listaEpisodios)
    : Video(id, titulo, genero, duracion, calificacion), episodios(episodios), listaEpisodios(listaEpisodios) {}

// Método para mostrar los datos de una serie
void Serie::MostrarDatos() {
    Video::MostrarDatos();
    for (auto& episodio : listaEpisodios) {
        episodio.MostrarDatos();
    }
}

// Método para calificar una serie
void Serie::calificar(double newCalificacion) {
    if (newCalificacion < 0 || newCalificacion > 5) {
        cout << "Calificación inválida. Debe estar entre 0 y 5." << endl;
        return;
    }
    calificacion = ((calificacion * numCalificaciones) + newCalificacion) / (++numCalificaciones);
}

// Método para obtener el promedio de calificación de una serie
double Serie::obtenerPromedioCalificacion() {
    double totalCalificacion = 0;
    int totalEpisodios = listaEpisodios.size();
    for (auto& episodio : listaEpisodios) {
        totalCalificacion += episodio.obtenerPromedioCalificacion();
    }
    return totalEpisodios > 0 ? totalCalificacion / totalEpisodios : calificacion;
}

// Método para agregar un video a la plataforma
void Plataforma::AgregarVideo(Video* video) {
    videos.push_back(video);
}

// Método para agregar una película a la plataforma
void Plataforma::AgregarPelicula(Pelicula* pelicula) {
    peliculas.push_back(pelicula);
    AgregarVideo(pelicula);  // Agregar al vector de videos
}

// Método para agregar una serie a la plataforma
void Plataforma::AgregarSerie(Serie* serie) {
    series.push_back(serie);
    AgregarVideo(serie);  // Agregar al vector de videos
}

// Método para mostrar los videos de la plataforma
void Plataforma::MostrarVideos(double calificacion, string genero) {
    cout << "Peliculas:\n";
    for (auto& pelicula : peliculas) {
        if (pelicula->obtenerPromedioCalificacion() >= calificacion && (genero.empty() || pelicula->genero == genero)) {
            pelicula->MostrarDatos();
        }
    }
    cout << "\nSeries:\n";
    for (auto& serie : series) {
        if (serie->obtenerPromedioCalificacion() >= calificacion && (genero.empty() || serie->genero == genero)) {
            serie->MostrarDatos();
        }
    }
}

// Método para mostrar las películas de la plataforma
void Plataforma::MostrarPeliculas(double calificacion, string genero) {
    for (auto& pelicula : peliculas) {
        if (pelicula->obtenerPromedioCalificacion() >= calificacion && (genero.empty() || pelicula->genero == genero)) {
            pelicula->MostrarDatos();
        }
    }
}

// Método para mostrar las series de la plataforma
void Plataforma::MostrarSeries(double calificacion, string genero) {
    for (auto& serie : series) {
        if (serie->obtenerPromedioCalificacion() >= calificacion && (genero.empty() || serie->genero == genero)) {
            serie->MostrarDatos();
        }
    }
}

// Método para mostrar los episodios de una serie
void Plataforma::MostrarEpisodios(string tituloSerie, double calificacion) {
    for (auto& serie : series) {
        if (serie->titulo == tituloSerie) {
            for (auto& episodio : serie->listaEpisodios) {
                if (episodio.obtenerPromedioCalificacion() >= calificacion) {
                    episodio.MostrarDatos();
                }
            }
            return;
        }
    }
    cout << "Serie no encontrada" << endl;
}

// Método para calificar un video
void Plataforma::CalificarVideo(string titulo, double nuevaCalificacion) {
    if (nuevaCalificacion < 0 || nuevaCalificacion > 5) {
        cout << "Calificación inválida. Debe estar entre 0 y 5." << endl;
        return;
    }
    for (auto& video : videos) {
        if (video->titulo == titulo) {
            video->calificar(nuevaCalificacion);
            cout << "El video " << titulo << " ha sido calificado con " << nuevaCalificacion << endl;
            return;
        }
    }
    cout << "Video no encontrado" << endl;
}
