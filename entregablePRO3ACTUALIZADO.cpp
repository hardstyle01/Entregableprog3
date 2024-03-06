#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <windows.h>
using namespace std;

const size_t TAM = 10;
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); //se está utilizando para manipular los colores de la consola, probablemente para dar formato o resaltar cierta información al usuario durante la ejecución del programa.

// Definicion de la clase Libro
class Libro {
private:
	int nISBN;
	string sTitulo;
	string sAutor;
	int nPublicacion;
	string sIdioma;
	double dPrecio;
	int nCalificacion;
public:
	//constructor por defecto
	Libro() {
		this->nISBN = 0;
		this->sTitulo = "";
		this->sAutor = "";
		this->nPublicacion = 0;
		this->sIdioma = "";
		this->dPrecio = 0.0;
		this->nCalificacion = 0;
	}
	// Constructor por atributos
	Libro(int isbn, string titulo, string autor, int publicacion, string idioma, double precio, int calificacionn) {
		this->nISBN = isbn;
		this->sTitulo = titulo;
		this->sAutor = autor;
		this->nPublicacion = publicacion;
		this->sIdioma = idioma;
		this->dPrecio = precio;
		this->nCalificacion = calificacionn;
	}
	// Metodos de obtencion de los atributos
	int get_ISBN() const { return nISBN; }
	string get_Titulo() const { return sTitulo; }
	string get_Autor() const { return sAutor; }
	int get_Publicacion() const { return nPublicacion; }
	string get_idioma() const { return sIdioma; }
	double get_Precio() const { return dPrecio; }
	int get_calificacion() const { return nCalificacion; }
	// Metodos de modificacion de los atributos
	void set_ISBN(int isbn) { nISBN = isbn; }
	void set_Titulo(const string& titulo) { sTitulo = titulo; }
	void set_Autor(const string& autor) { sAutor = autor; }
	void set_Publicacion(int publicacion) { nPublicacion = publicacion; }
	void set_idioma(const string& idioma) { sIdioma = idioma; }
	void set_Precio(double precio) { dPrecio = precio; }
	void set_Paginas(int paginas) { nCalificacion = paginas; }
};
// Definicion de la clase Persona
class Persona {
private:
	int nID;
	string sNombre;
	string sApellido;
	string scorreo;
public:
	// Constructor por defecto
	Persona() {
		this->nID = 0;
		this->sNombre = "sin nombre";
		this->sApellido = "sin apellido";
		this->scorreo = "sin correo";
	}
	// Constructor por parametros
	Persona(int id, string nombre, string apellido, string correo) {
		this->nID = id;
		this->sNombre = nombre;
		this->sApellido = apellido;
		this->scorreo = correo;
	}
	// Metodos de obtencion de los atributos
	int get_ID() const { return nID; }
	string get_Nombre() const { return sNombre; }
	string get_Apellido() const { return sApellido; }
	string get_correo() const { return scorreo; }
	// Metodos de modificacion de los atributos
	void set_ID(int id) { nID = id;}
	void set_Nombre(const string& nombre) { sNombre = nombre; }
	void set_Apellido(const string& apellido) { sApellido = apellido; }
	void set_correo(const string& correo) { scorreo = correo; }
};
// Definicion de la clase Usuario
class Usuario : public Persona {
private:
	int nCI;
public:
	// Constructor por defecto
	Usuario() {
		this->nCI = 0;
	}
	//constructor por parametros
	Usuario(int id, string nombre, string apellido, string correo, int cedula): Persona(id, nombre, apellido, correo){
		this->nCI=cedula;
	}
	// Metodos de obtencion de los atributos
	int get_cedula() const { return nCI; }
	// Metodos de modificacion de los atributos
	void set_cedula(int cedula) { nCI = cedula; }
};
// Definicion de la clase Bibliotecario
class Bibliotecario : public Persona {
private:
	double dSueldo;
public:
	// Constructor por defecto
	Bibliotecario() {
		this->dSueldo = 0.0;
	}
	//constructor por parametros
	Bibliotecario(int id, string nombre, string apellido, string correo, double sueldo): Persona(id, nombre, apellido, correo){
		this->dSueldo=sueldo;
	}
	// Metodos de obtencion de los atributos
	double get_Sueldo() const { return dSueldo; }
	// Metodos de modificacion de los atributos
	void set_sueldo(double sueldo) { dSueldo = sueldo; }
};
// Definición de la clase GestorLibros
class GestorLibros {
private:
	Libro libros[TAM];
	int TAMActual;
public:
	GestorLibros() : TAMActual(0) {}
	bool tituloRepetido(const string& titulo, int cantidad) const {
		for (int i = 0; i < cantidad; i++) {
			if (titulo == libros[i].get_Titulo()) {
				return true; // Si el titulo esta repetido
			}
		}
		return false; // Si el titulo no esta repetido
	}
	void llenado() {
		string listaTitulo[] = {"Programacion", "Estructuras de Datos", "Desarrollo Web", "Sistemas Operativos", "Software Agil", "Redes", "Matemáticas Discretas", "Inteligencia Artificial", "Bases de Datos", "Robótica"};
		string listaAutor[] = {"Fyodor Dostoevsky", "Leo Tolstoy", "Jane Austen", "Haruki Murakami", "Virginia Woolf", "Ernest Hemingway", "Agatha Christie", "Albert Camus", "Toni Morrison", "Margaret Atwood"};
		string listaidioma[] = {"Español", "Ingles", "Aleman", "Catalan", "Frances", "Italiano", "Guarani", "Portugues", "Mandarin", "Japones"};
		srand(time(nullptr)); // Inicializar la semilla del generador de números aleatorios
		TAMActual = 0; // Reiniciar el contador para llenado desde el principio
		for (int i = 0; i < TAM; i++) {
			string tituloAleatorio;
			do {
				int indiceTitulo = rand() % 10; //generacion de numero randomico de 0 a 9
				tituloAleatorio = listaTitulo[indiceTitulo];
			} while (tituloRepetido(tituloAleatorio, TAMActual)); // Verificar si el titulo esta repetido
			int isbnAleatorio = i + 1;
			int indiceAutor = rand() % 10;
			int indiceidioma = rand() % 10;
			int publicacionAleatoria = rand() % 25 + 1999; // Años entre 1999 y 2024
			double precioAleatorio = rand() % 100 + 10; // Precios entre 10 y 109
			int calificacionAleatoria = rand() % 10 + 1; // Números aleatorios entre 1 y 10
			string AutorAleatorio = listaAutor[indiceAutor];
			string idiomaAleatorio = listaidioma[indiceidioma];
			libros[i] = Libro(isbnAleatorio, tituloAleatorio,AutorAleatorio , publicacionAleatoria,idiomaAleatorio , precioAleatorio, calificacionAleatoria);
			TAMActual++;
		}
	}
	void mostrar() const {
		if (TAMActual == 0) { // Verifica si no hay libros llenados
			SetConsoleTextAttribute(hConsole, FOREGROUND_RED );
			cout << "Datos no llenados." << endl;
			return;
		}
		//imprimir datos de los libros
		
		cout << setw(2) << right << "ISBN" << setw(10) << "TITULO" << setw(24) << "AUTOR" << setw(24) << "AÑO" << setw(13) << "IDIOMA" << setw(15) << "PRECIO" << setw(17) << "Calificacion" << endl;
		SetConsoleTextAttribute(hConsole, BACKGROUND_GREEN );
		for (int i = 0; i < TAMActual; i++) {
			cout << left << setw(8) << libros[i].get_ISBN() << setw(25) << libros[i].get_Titulo() << setw(25) << libros[i].get_Autor() << setw(11) << libros[i].get_Publicacion() << setw(15) << libros[i].get_idioma() << setw(3) << libros[i].get_Precio()<< setw(10)<< "$" << setw(2) << libros[i].get_calificacion()<<"/10" << std::endl;
		}
	}
	// Función para mostrar los datos de los libros en forma de bloque
	void mostrar(string bloque) const {
		if (TAMActual == 0) { // Verifica si no hay libros llenados
			SetConsoleTextAttribute(hConsole, FOREGROUND_RED );
			cout << "Datos no llenados." << endl; // Mostrar mensaje si no hay datos
			return;
		}
		SetConsoleTextAttribute(hConsole, BACKGROUND_GREEN );
		cout << "Datos de libros en bloques: " << endl;
		for (int i = 0; i < TAMActual; i++) {
			
			cout << "ISBN: " << libros[i].get_ISBN() << endl;
			cout << "Titulo: " << libros[i].get_Titulo() << endl; 
			cout << "Autor: " << libros[i].get_Autor() << endl;
			cout << "Año: " << libros[i].get_Publicacion() << endl; 
			cout << "idioma: " << libros[i].get_idioma() << endl; 
			cout << "Precio: " << libros[i].get_Precio() <<" $"<< endl;
			cout << "Calificacion: " << libros[i].get_calificacion() << "/10"<< endl << endl;
		}
		
	}
	// Funcion para convertir una cadena a minusculas
	string convertir(const string& cadena) const {
		string resultado = cadena;
		for (char& c : resultado) {
			c = tolower(c);
		}
		return resultado;
	}
	// Funcion recursiva para buscadou libros por titulo
	void buscadou(int indice, int fin, const string& busqueda) const {
		bool libroEncontrado = false; // Bandera para verificar si se encontró al menos un libro
		
		if (indice < fin) { //condicion base
			// Convertir a minúsculas los atributos del libro y la cadena de búsqueda
			string tituloMinuscula = convertir(libros[indice].get_Titulo());
			string autorMinuscula = convertir(libros[indice].get_Autor());
			string idiomaMinuscula = convertir(libros[indice].get_idioma());
			string precioStr = to_string(libros[indice].get_Precio());
			string busquedaMinuscula = convertir(busqueda);
			
			if (indice == 0) { //mostrar el encabezado de la tabla
				
				cout << setw(2) << right << "ISBN" << setw(10) << "TITULO" << setw(24) << "AUTOR" << setw(24) << "AÑO" << setw(13) << "IDIOMA" << setw(15) << "PRECIO" << setw(17) << "Calificacion" << endl;
			}
			
			// Verificar si la búsqueda coincide con el título, autor, idioma o precio
			if (tituloMinuscula.find(busquedaMinuscula) != string::npos || autorMinuscula.find(busquedaMinuscula) != string::npos || idiomaMinuscula.find(busquedaMinuscula) != string::npos || precioStr.find(busquedaMinuscula) != string::npos) {
				SetConsoleTextAttribute(hConsole, BACKGROUND_GREEN );
				//imprimir los datos de los libros que coincidan con la búsqueda
				cout << left << setw(8) << libros[indice].get_ISBN() << setw(25) << libros[indice].get_Titulo() << setw(25) << libros[indice].get_Autor() << setw(11) << libros[indice].get_Publicacion() << setw(15) << libros[indice].get_idioma() << setw(3) << libros[indice].get_Precio()<< setw(10)<< "$" << setw(2) << libros[indice].get_calificacion()<<"/10" << std::endl;
				libroEncontrado = true; // Se encontró al menos un libro
			}
			
			buscadou(indice + 1, fin, busqueda); // Llamada recursiva con el siguiente libro
		}
		
		// Si no se encontró ningún libro en toda la búsqueda y estamos en el último registro, emitir un mensaje
		if (!libroEncontrado && indice == fin - 1) {
			cout << "Libro no encontrado" << endl;
		}
	}
	
};
// Definicion de la clase GestorUsuarios
class GestorUsuarios {
private:
	Usuario usuarios[TAM];
	int TAMActual;
public:
	GestorUsuarios() : TAMActual(0) {}
	void llenado() { // Funcion para llenado el arreglo de usuarios con datos aleatorios
		string listaNombres[] = {"Ever", "Carmen", "Diego", "Isabel", "Eliana", "Naty", "Roberto", "Lucia", "Daniel", "Paula"};
		string listaApellidos[] = {"Zabala", "Villa", "Fernandez", "Narvaez", "Cifuentes", "Hernando", "Aguirre", "Urrutia", "Pusy", "Gomez"};
		srand(time(nullptr)); // Inicializar la semilla del generador de números aleatorios
		TAMActual = 0; // Reiniciar el contador para llenado desde el principio
		for (int i = 0; i < TAM; ++i) {
			int indiceNombre = rand() % 10; //generacion de numero randomico de 0 al 9
			int indiceApellido = rand() % 10; //generacion de numero randomico de 0 al 9
			int idAleatorio = i + 1;
			int cedulaAleatorio = (rand() % 9 + 1) * 10000000 + rand() % 10000000;
			//asignar nombre y apellido de los arrays de acuerdo al indice generado randomicamente
			string nombreAleatorio = listaNombres[indiceNombre];
			string apellidoAleatorio = listaApellidos[indiceApellido];
			string correoAleatorio = nombreAleatorio + apellidoAleatorio + "@upds.com.bo";
			usuarios[i] = Usuario(idAleatorio, nombreAleatorio, apellidoAleatorio, correoAleatorio, cedulaAleatorio);
			TAMActual++; // Incrementar el contador de usuarios
		}
	}
	void mostrar() const {  // Funcion para mostrar los datos de los usuarios en forma de tabla
		if (TAMActual == 0) { // Verificar si no hay usuarios para mostrar
			SetConsoleTextAttribute(hConsole, FOREGROUND_RED );
			cout << "Datos no llenados." << endl; // Mostrar mensaje si no hay datos
			return;
		}
		
		cout << setw(5) << right << "USER ID" << setw(14) << "NOMBRE" << setw(17) << "APELLIDO" << setw(12) << "CORREO" << setw(32) << "CEDULA" << endl;
		SetConsoleTextAttribute(hConsole, BACKGROUND_GREEN );
		for (int i = 0; i < TAMActual; ++i) { //imprimir datos de los usuarios
			cout << left << setw(15) << usuarios[i].get_ID() << setw(15) << usuarios[i].get_Nombre() << setw(15) << usuarios[i].get_Apellido() << setw(30) << usuarios[i].get_correo() << setw(15) << usuarios[i].get_cedula() << endl;
		}
	}
	// Función para mostrar los datos de los usuarios en forma de bloques
	void mostrar(string bloque) const {
		if (TAMActual == 0) { // Verificar si no hay usuarios para mostrar
			SetConsoleTextAttribute(hConsole, FOREGROUND_RED );
			cout << "Datos no llenados." << endl; // Mostrar mensaje si no hay datos
			return;
		}
		SetConsoleTextAttribute(hConsole, BACKGROUND_GREEN );
		cout << "Datos de Usuarios en Bloques:" << endl;
		for (int i = 0; i < TAMActual; ++i) { //imprimir datos de los usuarios
			//cout << "Usuario " << i+1 << ":" << endl;
			cout << "USER ID: " << usuarios[i].get_ID() << endl;
			cout << "NOMBRE: " << usuarios[i].get_Nombre() << endl;
			cout << "APELLIDO: " << usuarios[i].get_Apellido() << endl;
			cout << "CORREO: " << usuarios[i].get_correo() << endl;
			cout << "CEDULA: " << usuarios[i].get_cedula() << endl << endl;
		}
	}
	// Funcion para convertir una cadena a minusculas
	string convertir(const string& cadena) const { 
		string resultado = cadena;
		for (char& c : resultado) {
			c = tolower(c);
		}
		return resultado;
	}
	// Funcion recursiva para buscadou usuarios por nombre, apellido o nombre completo
	void buscadou(int inicio, int fin, const string& busqueda) const {
		bool usuarioEncontrado = false; // Bandera para verificar si se encontró al menos un usuario
		
		if (inicio < fin) {  //condicion base
			// Convertir a minúsculas los atributos del usuario y la cadena de búsqueda
			string nombreMinuscula = convertir(usuarios[inicio].get_Nombre()); //convertir las cadenas a minúsculas
			string apellidoMinuscula = convertir(usuarios[inicio].get_Apellido());
			string correoMinuscula = convertir(usuarios[inicio].get_correo());
			string cedulaStr = to_string(usuarios[inicio].get_cedula());
			string busquedaMinuscula = convertir(busqueda);
			
			if (inicio == 0) { //mostrar el encabezado de la tabla
				
				cout << setw(5) << right << "USER ID" << setw(14) << "NOMBRE" << setw(17) << "APELLIDO" << setw(12) << "CORREO" << setw(32) << "CEDULA" << endl;
			}
			
			// Verifica si la búsqueda coincide con el nombre, apellido o nombre completo
			if (nombreMinuscula.find(busquedaMinuscula) != string::npos || apellidoMinuscula.find(busquedaMinuscula) != string::npos || (nombreMinuscula + " " + apellidoMinuscula).find(busquedaMinuscula) != string::npos || correoMinuscula.find(busquedaMinuscula) != string::npos || cedulaStr.find(busquedaMinuscula) != string::npos){
				SetConsoleTextAttribute(hConsole, BACKGROUND_GREEN );
				// Imprimir los datos del usuario que coincidan con la búsqueda
				cout << left << setw(15) << usuarios[inicio].get_ID() << setw(15) << usuarios[inicio].get_Nombre() << setw(15) << usuarios[inicio].get_Apellido() << setw(30) << usuarios[inicio].get_correo() << setw(15) << usuarios[inicio].get_cedula() << endl;
				usuarioEncontrado = true; // Se encontró al menos un usuario
			}
			
			buscadou(inicio + 1, fin, busqueda); //llamada recursiva con el siguiente usuario
		}
		
		// Si no se encontró ningún usuario en toda la búsqueda y estamos en el último registro, emitir un mensaje
		if (!usuarioEncontrado && inicio == fin - 1) {
			cout << "Usuario no encontrado" << endl;
		}
	}
	
	
};
	
// Definicion de la clase GestorBibliotecarios
class GestorBibliotecarios {
private:
	Bibliotecario bibliotecarios[TAM];
	int TAMActual;
public:
	GestorBibliotecarios() : TAMActual(0) {}
	void llenado() { // Función para llenado el arreglo de bibliotecarios con datos aleatorios
		string listaNombres[] = {"Ezequiel", "Marisol", "Rocío", "Maxi", "Valy", "Leandro", "Azul", "Damián", "Ariadna", "Ciro"};
		string listaApellidos[] = {"Mandia", "Brambila", "Valle", "Benas", "Hung", "Luna", "Cortez", "Castilla", "Lobre", "Albizu"};
		srand(time(nullptr)); // Inicializar la semilla del generador de números aleatorios
		TAMActual = 0; // Reiniciar el contador para llenado desde el principio
		for (int i = 0; i < TAM; ++i) {
			int indiceNombre = rand() % 10; //generar numero randomico del 0 al 9
			int indiceApellido = rand() % 10;
			int idAleatorio = i + 1;
			double sueldoAleatorio = rand() % 1501 + 2000; // sueldo entre 1500 y 3500
			bibliotecarios[i] = Bibliotecario(idAleatorio, listaNombres[indiceNombre], listaApellidos[indiceApellido], listaNombres[indiceNombre] + listaApellidos[indiceApellido] + "@gmail.com", sueldoAleatorio);
			TAMActual++;
		}
	}
	void mostrar() const {  // Funcion para mostrar los datos de los bibliotecarios en forma de tabla
		if (TAMActual == 0) { // Verificar si no hay bibliotecarios para mostrar
			SetConsoleTextAttribute(hConsole, FOREGROUND_RED );
			cout << "Datos no llenados." << endl; // Mostrar mensaje si no hay datos
			return;
		}
		//imprimir datos de los bibliotecarios
		SetConsoleTextAttribute(hConsole, BACKGROUND_GREEN );
		cout << setw(5) << right << "Empleado ID" << setw(10) << "Nombre" << setw(17) << "Apellido" << setw(12) << "Correo" << setw(32) << "Sueldo" << endl;
		for (int i = 0; i < TAMActual; ++i) {
			cout << left << setw(15) << bibliotecarios[i].get_ID() << setw(15) << bibliotecarios[i].get_Nombre() << setw(15) << bibliotecarios[i].get_Apellido() << setw(30) << bibliotecarios[i].get_correo() << bibliotecarios[i].get_Sueldo() << " BOB" << endl;
		}
	}
	// Función para mostrar los datos de los bibliotecarios en forma de bloques
	void mostrar(string bloque) const {
		if (TAMActual == 0) {  // Verificar si no hay bibliotecarios para mostrar
			SetConsoleTextAttribute(hConsole, FOREGROUND_RED );
			cout << "Datos no llenados." << endl; // Mostrar mensaje si no hay datos
			return;
		}
		SetConsoleTextAttribute(hConsole, BACKGROUND_GREEN );
		cout << "Datos de Bibliotecarios en Bloques:" << endl;
		for (int i = 0; i < TAMActual; ++i) { //imprimir datos de los bibliotecarios
			//cout << "Bibliotecario " << i+1 << ":" << endl;
			cout << "Empleado ID: " << bibliotecarios[i].get_ID() << endl;
			cout << "Nombre: " << bibliotecarios[i].get_Nombre() << endl;
			cout << "Apellido: " << bibliotecarios[i].get_Apellido() << endl;
			cout << "Correo: " << bibliotecarios[i].get_correo() << endl;
			cout << "Sueldo: " << bibliotecarios[i].get_Sueldo() << " BOB" << endl << endl;
		}
	}
	string convertir(const string& cadena) const { // Funcion para convertir una cadena a minusculas
		string resultado = cadena;
		for (char& c : resultado) {
			c = tolower(c);
		}
		return resultado;
	}
	// Funcion recursiva para buscadou bibliotecarios por nombre, apellido o nombre completo
	void buscadou(int inicio, int fin, const string& busqueda) const {
		bool bibliotecarioEncontrado = false; // Bandera para verificar si se encontró al menos un bibliotecario
		
		if (inicio < fin) { //condicion base
			// Convertir a minúsculas los atributos del bibliotecario y la cadena de búsqueda
			string nombreMinuscula = convertir(bibliotecarios[inicio].get_Nombre());
			string apellidoMinuscula = convertir(bibliotecarios[inicio].get_Apellido());
			string correoMinuscula = convertir(bibliotecarios[inicio].get_correo());
			string sueldoStr= to_string(bibliotecarios[inicio].get_Sueldo());
			string busquedaMinuscula = convertir(busqueda);
			
			if (inicio == 0) { //mostrar el encabezado de la tabla
				SetConsoleTextAttribute(hConsole, BACKGROUND_GREEN );
				cout << setw(5) << right << "Empleado ID" << setw(10) << "Nombre" << setw(17) << "Apellido" << setw(12) << "Correo" << setw(32) << "Sueldo" << endl;
			}
			
			// Verifica si la búsqueda coincide con el nombre, apellido o nombre completo
			if (nombreMinuscula.find(busquedaMinuscula) != string::npos || apellidoMinuscula.find(busquedaMinuscula) != string::npos || (nombreMinuscula + " " + apellidoMinuscula).find(busquedaMinuscula) != string::npos || correoMinuscula.find(busquedaMinuscula) != string::npos || sueldoStr.find(busquedaMinuscula) != string::npos) {
				// Imprimir los datos del bibliotecario que coincidan con la búsqueda
				cout << left << setw(15) << bibliotecarios[inicio].get_ID() << setw(15) << bibliotecarios[inicio].get_Nombre() << setw(15) << bibliotecarios[inicio].get_Apellido() << setw(30) << bibliotecarios[inicio].get_correo() << bibliotecarios[inicio].get_Sueldo() << " BOB" << endl;
				bibliotecarioEncontrado = true; // Se encontró al menos un bibliotecario
			}
			
			buscadou(inicio + 1, fin, busqueda); //llamada recursiva con el siguiente bibliotecario
		}
		
		// Si no se encontró ningún bibliotecario en toda la búsqueda y estamos en el último registro, emitir un mensaje
		if (!bibliotecarioEncontrado && inicio == fin - 1) {
			cout << "Bibliotecario no encontrado" << endl;
		}
	}
	
};
// Menu para mostrar los listados
void menuListados(GestorLibros& gestorL, GestorUsuarios& gestorU, GestorBibliotecarios& gestorB) {
	char opcionListados;
	do {
		SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE );
		cout << "\nSubmenu de Listados:" << endl;
		cout << "A) Listado de Libros" << endl;
		cout << "B) Listado de Usuarios" << endl;
		cout << "C) Listado de Bibliotecarios" << endl;
		cout << "X) Volver al Menu Principal" << endl;
		cout << "INGRESE SU OPCION: ";
		SetConsoleTextAttribute(hConsole, FOREGROUND_RED );
		cin >> opcionListados;
		switch (opcionListados) {
		case 'a' : case 'A':
		{
			char respuesta;
			SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE );
			cout << "Desea ver los datos en forma de tabla? (s/n): ";
			SetConsoleTextAttribute(hConsole, FOREGROUND_RED );
			cin >> respuesta;
			if (respuesta == 's' || respuesta == 'S'){
				gestorL.mostrar();
			} else {
				gestorL.mostrar("bloque");
			}
		}  
		break;
		case 'b' : case 'B':
		{
			char respuesta;
			SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE );
			cout << "Desea ver los datos en forma de tabla? (s/n): ";
			SetConsoleTextAttribute(hConsole, FOREGROUND_RED );
			cin >> respuesta;
			if (respuesta == 's' || respuesta == 'S') {
				gestorU.mostrar();
			} else {
				gestorU.mostrar("Bloque");
			}
		}
		break;
		case 'c' : case 'C':
		{
			char respuesta;
			SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE );
			cout << "Desea ver los datos en forma de tabla? (s/n): ";
			SetConsoleTextAttribute(hConsole, FOREGROUND_RED );
			cin >> respuesta;
			if (respuesta == 's' || respuesta == 'S') {
				gestorB.mostrar();
			} else {
				gestorB.mostrar("Bloque");
			}
		}
		break;
		case 'x' : case 'X':
			SetConsoleTextAttribute(hConsole, FOREGROUND_RED );
			cout << "Volviendo al Menu Principal..." << endl;
			break;
		default:
			SetConsoleTextAttribute(hConsole, FOREGROUND_RED );
			cout << "Opcion invalida. Intente de nuevo." << endl;
		}
	} while (opcionListados != 'X' == 'x');
}
// Menu para realizar busquedas
void menuBusqueda(GestorLibros& gestorL, GestorUsuarios& gestorU, GestorBibliotecarios& gestorB) {
	char opcionBusqueda;
	do {
		SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE );
		cout << "\nSubmenu de Busqueda:" << endl;
		cout << "A) Busqueda de Libro" << endl;
		cout << "B) Busqueda de Usuario" << endl;
		cout << "C) Busqueda de Bibliotecario" << endl;
		cout << "X) Volver al Menu Principal" << endl;
		cout << "Ingrese la opcion: ";
		SetConsoleTextAttribute(hConsole, FOREGROUND_RED );
		cin >> opcionBusqueda;
		switch (opcionBusqueda) {
		case 'a' : case 'A' :
		{
			string sBusquedaLi;
			SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE );
			cout << "Ingrese el titulo del libro que desea buscadou: ";
			SetConsoleTextAttribute(hConsole, FOREGROUND_RED );
			cin.ignore(); // Limpiar el buffer de entrada
			getline(cin, sBusquedaLi); // Leer la cadena de búsqueda
			SetConsoleTextAttribute(hConsole, BACKGROUND_GREEN );
			cout << "\nResultados de la busqueda:" << endl;
			gestorL.buscadou(0, TAM, sBusquedaLi); // Realizar la busqueda de libros
		}
		break;
		case 'b' : case 'B':
		{
			string sBusquedaU;
			SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE );
			cout << "Ingrese el nombre, apellido o nombre completo: ";
			SetConsoleTextAttribute(hConsole, FOREGROUND_RED );
			cin.ignore(); // Limpiar el buffer de entrada
			getline(cin, sBusquedaU); // Leer la cadena de búsqueda
			SetConsoleTextAttribute(hConsole, BACKGROUND_GREEN );
			cout << "\nResultados de la busqueda:" << endl;
			gestorU.buscadou(0, TAM, sBusquedaU); // Realizar la busqueda de usuarios
		}
		break;
		case 'c' : case 'C':
		{
			string sBusquedaB;
			SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE );
			cout << "Ingrese el nombre, apellido o nombre completo: ";
			SetConsoleTextAttribute(hConsole, FOREGROUND_RED );
			cin.ignore(); // Limpiar el buffer de entrada
			getline(cin, sBusquedaB); // Leer la cadena de búsqueda
			SetConsoleTextAttribute(hConsole, BACKGROUND_GREEN );
			cout << "\nResultados de la busqueda:" << endl;
			gestorB.buscadou(0, TAM, sBusquedaB); // Realizar la busqueda de usuarios
		}
		break;
		case 'x' : case 'X':
			SetConsoleTextAttribute(hConsole, FOREGROUND_RED );
			cout << "Volviendo al Menu Principal..." << endl;
			break;
		default:
			SetConsoleTextAttribute(hConsole, FOREGROUND_RED );
			cout << "Opcion invalida. Intente de nuevo." << endl;
		}
	} while (opcionBusqueda != 'X'== 'x');
}
// Menu principal
void menuPrincipal(GestorLibros& gestorL, GestorUsuarios& gestorU, GestorBibliotecarios& gestorB) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	int opcionPrincipal;
	do {
		SetConsoleTextAttribute(hConsole, BACKGROUND_GREEN | FOREGROUND_RED);
		cout << "\nMENU PRINCIPAL" << endl;
		SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE );
		cout << "1. llenado Datos" << endl;
		cout << "2. Listados" << endl;
		cout << "3. Busqueda" << endl;
		cout << "0. Salir" << endl;
		SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE );
		cout << "Ingrese la opcion: ";
		SetConsoleTextAttribute(hConsole, FOREGROUND_RED );
		cin >> opcionPrincipal;
		cin.ignore(); //Limpiar el buffer de entrada
		switch (opcionPrincipal) {
		case 1 :
			gestorL.llenado();
			gestorU.llenado();
			gestorB.llenado();
			SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN );
			cout << "Datos llenados exitosamente." << endl;
			break;
		case 2:
			menuListados(gestorL, gestorU, gestorB);
			break;
		case 3:
			menuBusqueda(gestorL, gestorU, gestorB);
			break;
		case 0:
			SetConsoleTextAttribute(hConsole, FOREGROUND_RED );
			cout << "Saliendo del programa..." << endl;
			break;
		default:
			SetConsoleTextAttribute(hConsole, FOREGROUND_RED );
			cout << "Opcion invalida. Intente de nuevo." << endl;
		}
	} while (opcionPrincipal != 0);
}
int main() {
	
	srand(time(nullptr));
	// Crear instancias de los gestores de libros, usuarios y bibliotecarios
	GestorLibros gestorL;
	GestorUsuarios gestorU;
	GestorBibliotecarios gestorB;
	// Llamar a la función del menú principal, pasando los gestores como argumentos
	menuPrincipal(gestorL, gestorU, gestorB);
	
	
	return 0;
}
