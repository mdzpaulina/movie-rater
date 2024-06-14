#include "declaracion.h"
#include <iostream>

using namespace std;

void mostrarMenu() {
    cout << "Menu de Opciones:\n";
    cout << "1. Agregar video\n";
    cout << "2. Mostrar los videos en general con una cierta calificación o de un cierto género\n";
    cout << "3. Mostrar los episodios de una determinada serie con una calificación determinada\n";
    cout << "4. Mostrar las películas con cierta calificación\n";
    cout << "5. Calificar un video\n";
    cout << "0. Salir\n";
    cout << "Ingrese una opción: ";
}

int main() {
    Plataforma plataforma;
    int opcion;
    string id, titulo, genero, episodioTitulo;
    double calificacion, duracion;
    int numEpisodios, temporada;

    // Agregar Peliculas
    plataforma.AgregarPelicula(Pelicula("001", "John_Wick_4", "Accion", 170, 0));
    plataforma.AgregarPelicula(Pelicula("002", "La_La_Land", "Drama", 129, 0));
    plataforma.AgregarPelicula(Pelicula("003", "Fight_Club", "Drama", 139, 0));

    // Agregar Series
    plataforma.AgregarSerie(Serie("0001", "Hora_De_Aventura", "Aventura", 0, 0, 3, {Episodio("E001", "Fionna_and_Cake", 1, 22, 0), Episodio("E002", "Incendium", 1, 22, 0), Episodio("E003", "The_Lich", 1, 22, 0)}));
    plataforma.AgregarSerie(Serie("0002", "Gravity_Falls", "Misterio", 0, 0, 3, {Episodio("E001", "Fight_Fighters", 1, 23, 0), Episodio("E002", "Not_What_He_Seems", 1, 23, 0), Episodio("E003", "A_Tale_of_Two_Stans", 1, 23, 0)}));
    plataforma.AgregarSerie(Serie("0003", "Stranger_Things", "Ciencia_Ficcion", 0, 0, 3, {Episodio("E001", "The_Vanishing_of_Will_Byers", 1, 47, 0), Episodio("E002", "The_Weirdo_on_Maple_Street", 1, 55, 0), Episodio("E003", "Holly_Jolly", 1, 51, 0)}));

    do {
        mostrarMenu();
        cin >> opcion;

        switch (opcion) {
        case 1:
            // Opción para agregar un video
            cout << "Ingrese el tipo de video (1 para Pelicula, 2 para Serie): ";
            int tipo;
            cin >> tipo;
            if (tipo == 1) {
                cout << "Ingrese el ID: ";
                cin >> id;
                cout << "Ingrese el Titulo: ";
                cin.ignore();
                getline(cin, titulo);
                cout << "Ingrese el Genero: ";
                getline(cin, genero);
                cout << "Ingrese la Duracion: ";
                cin >> duracion;
                cout << "Ingrese la Calificación: ";
                cin >> calificacion;
                plataforma.AgregarPelicula(Pelicula(id, titulo, genero, duracion, calificacion));
            } else if (tipo == 2) {
                cout << "Ingrese el ID de la serie: ";
                cin >> id;
                cout << "Ingrese el Titulo de la serie: ";
                cin.ignore();
                getline(cin, titulo);
                cout << "Ingrese el Genero de la serie: ";
                getline(cin, genero);
                cout << "Ingrese el número de episodios: ";
                cin >> numEpisodios;
                vector<Episodio> episodios;
                for (int i = 0; i < numEpisodios; ++i) {
                    cout << "Ingrese el ID del episodio " << (i + 1) << ": ";
                    cin >> id;
                    cout << "Ingrese el Titulo del episodio " << (i + 1) << ": ";
                    cin.ignore();
                    getline(cin, episodioTitulo);
                    cout << "Ingrese la Duracion del episodio: ";
                    cin >> duracion;
                    cout << "Ingrese la Temporada del episodio: ";
                    cin >> temporada;
                    cout << "Ingrese la Calificación del episodio: ";
                    cin >> calificacion;
                    episodios.push_back(Episodio(id, episodioTitulo, temporada, duracion, calificacion));
                }
                plataforma.AgregarSerie(Serie(id, titulo, genero, 0, 0, numEpisodios, episodios));
            }
            break;

        case 2:
            // Opción para mostrar videos filtrados por calificación y género
            cout << "Ingrese la calificación mínima: ";
            cin >> calificacion;
            cout << "Ingrese el género (deje vacío para ignorar): ";
            cin.ignore();
            getline(cin, genero);
            plataforma.MostrarVideos(calificacion, genero);
            break;

        case 3:
            // Opción para mostrar episodios de una serie filtrados por calificación
            cout << "Ingrese el nombre de la serie: ";
            cin.ignore();
            getline(cin, titulo);
            cout << "Ingrese la calificación mínima: ";
            cin >> calificacion;
            plataforma.MostrarEpisodios(titulo, calificacion);
            break;

        case 4:
            // Opción para mostrar películas filtradas por calificación
            cout << "Ingrese la calificación mínima: ";
            cin >> calificacion;
            cout << "Ingrese el género (deje vacío para ignorar): ";
            cin.ignore();
            getline(cin, genero);
            plataforma.MostrarPeliculas(calificacion, genero);
            break;

        case 5:
            // Opción para calificar un video
            cout << "Ingrese el título del video a calificar: ";
            cin.ignore();
            getline(cin, titulo);
            cout << "Ingrese la nueva calificación: ";
            cin >> calificacion;
            plataforma.CalificarVideo(titulo, calificacion);
            break;

        case 0:
            // Opción para salir
            cout << "Saliendo...\n";
            break;

        default:
            cout << "Opción no válida. Intente de nuevo.\n";
            break;
        }
    } while (opcion != 0);

    return 0;
}
