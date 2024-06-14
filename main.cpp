
#include "declaracion.h"
#include <iostream>
using namespace std;

int main(){
    //Se crean los objetos tanto para las peliculas como para las serie 
    plataforma.AgregarVideo(new Pelicula("001", "John_Wick_4", "Accion", 170, 0));
    plataforma.AgregarVideo(new Pelicula("002", "La_La_Land", "Drama", 129, 0));
    plataforma.AgregarVideo(new Pelicula("003", "Fight_Club", "Drama", 139, 0));
    
    plataforma.AgregarVideo(new Serie("0001", "Hora_De_Aventura", "Aventura", 0, {Episodio("001", "Fionna_and_Cake", 22, 1, 0), Episodio("002", "Incendium", 22, 1, 0), Episodio("003", "The_Lich", 22, 1, 0)}));
    plataforma.AgregarVideo(new Serie("0002", "Gravity_Falls", "Misterio", 0, {Episodio("001", "Fight_Fighters", 23, 1, 0), Episodio("002", "Not_What_He_Seems", 23, 1, 0), Episodio("003", "A_Tale_of_Two_Stans", 23, 1, 0)}));
    plataforma.AgregarVideo(new Serie("0003", "Stranger_Things", "Ciencia_Ficcion", 0, {Episodio("001", "The_Vanishing_of_Will_Byers", 47, 1, 0), Episodio("002", "The_Weirdo_on_Maple_Street", 55, 1, 0), Episodio("003", "Holly_Jolly", 51, 1, 0)}));

    //menu de la plataforma
    int opcion;
    do{
        menu();
        cin>>opcion;
        switch(opcion){
            case 1:
                plataforma.MostrarVideos();
                break;
            case 2:
                plataforma.CalificarVideo();
                break;
            case 3:
                plataforma.MostrarCalificacion();
                break;
            case 4:
                plataforma.MostrarGenero();
                break;
            case 5:
                plataforma.MostrarDuracion();
                break;
            case 6:
                plataforma.MostrarEpisodios();
                break;
            case 7:
                plataforma.MostrarTemporada();
                break;
            case 8:
                cout<<"Saliendo de la plataforma"<<endl;
                break;
            default:
                cout<<"Opcion no valida"<<endl;
                break;
        }
    }

}