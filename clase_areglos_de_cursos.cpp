#include <iostream>
#include <string>

using namespace std;

class Curso{
	private:
		string Name;
		string Codigo;
		int NroAlumnos;
	public:
		Curso();
		Curso(string nombre, int Nroalumnos);
 		void setNombre(const string nombre);
 		void setCodigo(const string codigo);
		void setNroAlumnos(const int nroAlumnos);
		void printCurso();				
};
Curso::Curso(){
	Name = "o";
	NroAlumnos = 0;
}
Curso::Curso(string nombre, int Nroalumnos){
	Name = nombre;
	NroAlumnos = Nroalumnos;
	
}
void Curso::setNombre(const string nombre){
	Name = nombre;
}
void Curso::setCodigo(const string codigo){
	Codigo = codigo;
}
void Curso::setNroAlumnos(const int nroAlumnos){
	NroAlumnos = nroAlumnos;
}
void Curso::printCurso(){
	cout<<"\nNombre del Curso: "<<Name<<"\nNumero de Alumnos: "<<NroAlumnos<<"\nCodigo: "<<Codigo<<endl;
}
class ArregloDeCursos{
	private:
		Curso *Cursos;
		int tam;
	public:
		ArregloDeCursos(const Curso cursos[], const int tam);
		ArregloDeCursos(const ArregloDeCursos &o);
		~ArregloDeCursos();
		
		void redimensionar(int n); 
		void pushback(const Curso &p);
		void insert(const int posicion, const Curso &p);
		void remove(const int pos);
		const int getSize() const;
		void clear();
		void printArregloDeCursos();
};
ArregloDeCursos::ArregloDeCursos(const Curso cursos[], const int tamanio){
	Cursos = new Curso [tamanio];
    for (int i=0 ; i<tamanio ; i++)
        Cursos[i] = Cursos[i];
    tam = tamanio;
}
ArregloDeCursos::ArregloDeCursos(const ArregloDeCursos &o){
	Cursos = o.Cursos;
    tam = o.tam;
}
ArregloDeCursos::~ArregloDeCursos(){
	delete []Cursos;
}
void ArregloDeCursos::redimensionar(int n){
	 Curso *new_Cursos = new Curso[n];

    if (n>tam) //si la nueva dimension es mayor al tamaño original
    {
        for (int i = 0; i < tam; i++)
            new_Cursos[i] = Cursos[i];
        new_Cursos[n-1]= Curso();
    }
    else //si la nueva dimension es menor al tamaño original
    {
        for (int i = 0; i < n; i++)
            new_Cursos[i] = Cursos[i];
    }
    tam = n;
    delete []Cursos;
    Cursos = new_Cursos;
}
void ArregloDeCursos::pushback(const Curso &p){
	 redimensionar(tam+1);
	 Cursos[tam-1] = p;
}
void ArregloDeCursos::insert(const int posicion, const Curso &p){
	    if (posicion<=tam){
        redimensionar(tam+1);
        for (int i=tam-1 ; i>posicion ;i--)
            Cursos[i]=Cursos[i-1];
        Cursos[posicion] = p;
    }
    else
        cout <<"\nPosicion no valida\n";
}
void ArregloDeCursos::remove(const int pos){
	if (pos<=tam){
        for (int i=pos ; i<tam-1 ;i++)
            Cursos[i]=Cursos[i+1];
        redimensionar(tam-1);
    }
    else
        cout <<"\nPosicion no valida\n";
}
const int ArregloDeCursos::getSize() const{
	return tam;
}
void ArregloDeCursos::clear(){
	delete []Cursos;
    cout<<"Elementos eliminados"<<endl;
}
void ArregloDeCursos::printArregloDeCursos()
{
    for (int i=0 ; i<tam ;i++){
        Cursos[i].printCurso();
        if (i != tam - 1)
            cout<<"\n";
    }
}	
int main(){
	Curso a("Computer_Science2",24);
	a.setCodigo("20190753");
	a.printCurso();
	Curso b("Calculo_en_Varias_Variables",24);
	b.setCodigo("20190742");
	b.printCurso();
	Curso c("Trabajo_Interdiciplinar",24);
	c.setCodigo("20190754");
	c.printCurso();
	Curso d("Ingles",24);
	d.setCodigo("201907455");
	d.printCurso();
	
	int tam = 2;
    Curso Array [tam] = {a, b};

    ArregloDeCursos A(Array , tam);
    cout << "Original"<<endl;
    A.printArregloDeCursos();

    cout<<endl<< "Add"<<endl;
    A.pushback(c);
    A.printArregloDeCursos();

    cout<<endl<< "AddMedio"<<endl;
    A.insert(1,d);
    A.printArregloDeCursos();

    cout<<endl<< "borrar"<<endl;
    A.remove(2);
    A.printArregloDeCursos();

    cout<<endl<< "clean"<<endl;
    A.clear();
    A.printArregloDeCursos();
	
}
/*
• Debe implementar una función para redimensionar el tamaño el arreglo dinámicamente
void ArregloDeCursos::redimensionar(int n)
• Implementar las siguientes funciones:
– Adicionar un Curso al final del arreglo:
void ArregloDeCursos::push back(const Curso &p)
– Insertar un Curso en cualquier posición del arreglo:
void ArregloDeCursos::insert(const int posicion, const Curso &p)
– Eliminar una Curso de cualquier posición del arreglo:
void ArregloDeCursos::remove(const int pos)
– Obtener el tamaño del arreglo:
const int ArregloDeCursos::getSize() const
– Eliminar todos los elementos del arreglo:
void ArregloDeCursos::clear()
*/

