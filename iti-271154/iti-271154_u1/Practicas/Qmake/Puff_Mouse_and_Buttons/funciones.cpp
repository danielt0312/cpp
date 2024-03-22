#include <iostream>
#include <filesystem>
#include "funciones.h"

using namespace std;
namespace fs = std::filesystem;


void Funciones::crearCarpeta (string nombre_carpeta) {
    if (!fs::exists(nombre_carpeta)) {
        fs::create_directory(nombre_carpeta);
        cout << "Carpeta creada" << endl;
    } else {
        cout << "carpeta existente" << endl;
    }
}

void Funciones::leerArchivos(string nombreArchivo) { 
    ifstream archivo(nombreArchivo.c_str());
    string linea;
    // Obtener línea de archivo, y almacenar contenido en "linea"
    while (getline(archivo, linea)) {
        // Lo vamos imprimiendo
        cout << "Una línea: ";
        cout << linea << endl;
        
    }
}

void Funciones::guardarDibujos(string nombreArchivo) {
    FILE *arch=fopen(nombreArchivo,"wt");
    
    if (arch==NULL)
        return;
    fputs("Primer linea\n",arch);
    fputs("Segunda linea\n",arch);
    fputs("Tercer linea\n",arch);
    fclose(arch);
    printf("Se creo el archivo de texto con tres lineas de texto.");
    getch();
}
