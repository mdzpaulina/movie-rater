#include "declaracion.h"
#include <iostream>

using namespace std;

void mostrarMenu() {
    cout << "\nMenu de Opciones:\n";
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
    plataforma.AgregarPelicula(new Pelicula("001", "John Wick 4", "Accion", 170, 1));
    plataforma.AgregarPelicula(new Pelicula("002", "La La Land", "Drama", 129, 1));
    plataforma.AgregarPelicula(new Pelicula("003", "Fight Club", "Drama", 139, 1));

    // Agregar Series
    plataforma.AgregarSerie(new Serie("0001", "Hora De Aventura", "Aventura", 0, 1, 3, {
        Episodio("E001", "Fionna and Cake", 1, 22, 1),
        Episodio("E002", "Incendium", 1, 22, 1),
        Episodio("E003", "The Lich", 1, 22, 1)
    }));
    plataforma.AgregarSerie(new Serie("0002", "Gravity Falls", "Misterio", 0, 1, 3, {
        Episodio("E001", "Fight Fighters", 1, 23, 1),
        Episodio("E002", "Not What He Seems", 1, 23, 1),
        Episodio("E003", "A Tale of Two Stans", 1, 23, 1)
    }));
    plataforma.AgregarSerie(new Serie("0003", "Stranger Things", "Ciencia Ficcion", 0, 1, 3, {
        Episodio("E001", "The Vanishing of Will Byers", 1, 47, 1),
        Episodio("E002", "The Weirdo on Maple Street", 1, 55, 1),
        Episodio("E003", "Holly Jolly", 1, 51, 1)
    }));

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
                plataforma.AgregarPelicula(new Pelicula(id, titulo, genero, duracion, calificacion));
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
                plataforma.AgregarSerie(new Serie(id, titulo, genero, 0, 0, numEpisodios, episodios));
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
            cout << "Saliendo\n";
            break;

        default:
            cout << "Opción no válida. Intente de nuevo.\n";
            break;
        }
    } while (opcion != 0);

    return 0;
}
