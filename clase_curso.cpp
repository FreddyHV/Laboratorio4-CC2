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
	d.setCodigo("20190755");
	d.printCurso();
}






























