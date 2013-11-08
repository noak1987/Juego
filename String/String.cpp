#include "stdafx.h"
#include <stdlib.h>
#include <cctype>
#include <iostream>
#include "String.h"

String::String(const char* str){
	length = strlen(str);
	size = length + 1;
	cadena = new char[size];
	strcpy(cadena, str);
}

String::String(const String& str){
	length = str.Length();
	size = length + 1;
	cadena = new char[size];
	strcpy(cadena, str.ToCString());
}

String::~String(){
	delete cadena;
}

bool String::operator == (const String& other) const{
	int comp = strcmp(cadena, other.ToCString()); //devuelve 0 si son iguales
	if (comp == 0)
		return true;
	else
		return false;
}

bool operator==(const char* c, const String& other)
{
	int comp = strcmp(c, other.ToCString()); //devuelve 0 si son iguales
	if (comp == 0)
		return true;
	else
		return false;
}

bool String::operator != (const String& other) const{
	int comp = strcmp(cadena, other.ToCString());
	if (comp == 0)
		return false;
	else
		return true;
}

bool operator!=(const char* c, const String& other) 
{
	int comp = strcmp(c, other.ToCString());
	if (comp == 0)
		return false;
	else
		return true;
}

bool String::operator < (const String& other) const{ //por orden alfabético  a < z
	int comp = strcmp(cadena, other.ToCString());
	if (comp < 0)
		return true;
	else
		return false;
}

bool operator<(const char* c, const String& other)
{
	int comp = strcmp(c, other.ToCString());
	if (comp < 0)
		return true;
	else
		return false;
}

bool String::operator > (const String& other) const{
	int comp = strcmp(cadena, other.ToCString());
	if (comp > 0)
		return true;
	else
		return false;
}

bool operator>(const char* c, const String& other)
{
	int comp = strcmp(c, other.ToCString());
	if (comp > 0)
		return true;
	else
		return false;
}

String String::operator + (const String& other) const{
	char *aux = new char[size + other.Length()];
	strcpy(aux, cadena);
	strcat(aux, other.ToCString());
	String resultado(aux);
	delete aux;
	return resultado;
}

String operator+(const char* c, const String& other)
{
	int length = strlen(c);
	char *aux = new char[length + other.Length() + 1];
	strcpy(aux, c);
	strcat(aux, other.ToCString());
	String resultado(aux);
	delete aux;
	return resultado;
}

String String::operator + (char c) const{
	char *aux = new char[size+1];
	strcpy(aux, cadena);
	aux[length] = c;
	aux[size] = 0;
	//strcat(aux, (char *)c);
	String resultado(aux);
	delete aux;
	return resultado;
}

String operator+(char c, const String& other)
{
	char *aux = new char[other.Length()+2];
	aux[0] = c;
	char * p1adv = aux + 1;
	strncpy(p1adv, other.ToCString(), other.Length());
	aux[other.Length()+1] = 0;
	//strcat(aux, (char *)c);
	String resultado(aux);
	delete aux;
	return resultado;
}

String& String::operator = (const String& other){
	length = other.Length();
	size = length + 1;
	delete cadena;
	cadena = new char[size];
	char *aux = new char[size];
	strcpy_s(aux, size, other.ToCString());
	strcpy(cadena, aux);
	delete aux;
	return *this;
}

String& String::operator = (char c){
	length = 1;
	size = length + 1;
	delete cadena;
	cadena = new char[size];
	char *aux = new char[size];
	aux[0] = c;
	aux[length] = 0;
	strcpy(cadena, aux);
	delete aux;
	return *this;
}

String& String::operator += (const String& other){
	length = length + other.Length();
	size = length + 1;
	char* aux = new char[size];
	strcpy(aux, cadena);
	strcat(aux, other.ToCString());
	delete cadena;
	cadena = new char[size];
	strcpy(cadena, aux);
	delete aux;
	return *this;
}

String& String::operator += (char c){
	char* aux = new char[size + 1];
	strcpy(aux, cadena);
	aux[size - 1] = c;
	aux[size] = 0;
	delete cadena;
	cadena = new char[size+1];
	strcpy(cadena, aux);
	delete aux;
	length = length + 1;
	size = size + 1;
	return *this;
}

char& String::operator [](unsigned int pos){ //indice de tabla
//*cadena = cadena[pos];
	return cadena[pos];
}

const char& String::operator [] (unsigned int pos) const{
//*cadena = cadena[pos];
	return cadena[pos];
}

int String::Length() const{
	return length;
}

String String::FromInt(int val){
	int cont = 1;
	int num = val;
	while (num / 10 > 0)
	{
	num = num / 10;
	cont++;
	}
	char *aux = new char[cont+1];
	sprintf(aux, "%d", val);
	String conversion(aux);
	delete aux;
	return conversion;
}

String String::HexFromInt(int val){
	int cont = 1;
	int num = val;
	while (num / 10 > 0)
	{
	num = num / 10;
	cont++;
	}
	char *aux = new char[cont + 1];;
	sprintf(aux, "%X", val);
	String conversion(aux);
	return conversion;
}

String String::FromFloat(float val){
	int cont = 1;
	int num = (int)val;
	while (num / 10 > 0)	{
		num = num / 10;
		cont++;
	}
	char *aux = new char[cont + 1];
	sprintf(aux, "%f", val);
	String conversion(aux);
	return conversion;
}

int String::ToInt() const{
	return atoi(cadena);
}

float String::ToFloat() const{
	return (float)atof(cadena);
}

const char* String::ToCString() const{
	return cadena;
}

String String::Left(int n) const{ //devuelve una subcadena con los caracteres de la izquierda. "hola" --- left(2)="ho"
	char* aux = new char[n+1];
	int j = 0;
	for (int i = 0; i < n; i++){
		aux[j] = cadena[i];
		j++;
	}
	aux[j] = '\0';
	String resultado(aux);
	delete aux;
	return resultado;
}

String String::Right(int n) const{
	char* aux = new char[n+1];
	int j = 0;
	for (int i = length - n; i < size; i++)	{
		aux[j] = cadena[i];
		j++;
	}
	aux[j-1] = 0;
	String resultado(aux);
	delete aux;
	return resultado;
}

String String::Mid(int ofs, int n){ //n caracteres a partir del ofs.  "hola" --- mid(1,2)="ol"
	char* aux = new char[n+1];
	int j = 0;
	for (int i = ofs; i < ofs + n; i++)	{
		aux[j] = cadena[i];
		j++;
	}
	aux[j] = 0;
	String resultado(aux);
	delete aux;
	return resultado;
}

String String::Replace(const String& find, const String& rep) const{	
	String ret("");
	int apariciones = Find(find, 0);
	if (!apariciones)
		return ret;
	
	// Esta var guia el indice de sustitución
	int aparicion_index = 0;
	int aparicion_now = 0;
	unsigned int x, pos=0;
	char * aux;

	// Calculamos el nevo tamaño de la cadena
	int nueva_longitud = size - (apariciones * find.Length()) + (apariciones * rep.Length());

	// Aseguramos que la cadena tenga espacio de sobra
	if(nueva_longitud > size) {
		aux = new char[nueva_longitud];
	} else {
		aux = new char[size];
	}

	strcpy(aux, cadena);

	while (aparicion_now <= apariciones) 
	{
		// ============== BUSCAMOS LA PRIMERA APARICION ==============
		pos = aparicion_index;

		if (aparicion_now < apariciones) {
			// Mientras la posición actual sea menor que el final de cadena
			while(pos <= Length() + 1)
			{
				// Comprobamos si hemos encontrado la cadena
				for (x = 0; x < find.Length() && pos <= Length() + 1; x++, pos++) {
					if (aux[pos] != find[x])
						break;
				}

				if (x == find.Length())
					// Significa que la str se ha completado entera y es una aparicion
					break;
				else
					pos++; 
			}

			aux[pos - find.Length()] = 0;
		}

		ret += (aux + aparicion_index); // Todo lo de la cadena antes de la palabra a buscar

		if (aparicion_now < apariciones)
			ret += rep;                  // Por lo que es sustituida la palabra a buscar

		aparicion_index = pos; // Actualizamos el índice de la palabra a despues de la palabra encontrada

		aparicion_now++;
	}

	delete aux;

	return ret;
}

int String::Find(const String& str, int ofs) const{
	int cont = 0;
	int contador = 0;
	int k = 0;
	for (int i = ofs; i < size; i++){
		if (cadena[i] == str[0]){
			k = i;
			for (int j = 0; j < str.size; j++){
				if (cadena[k] == str[j]){
					k++;
					contador++;
				}
				if (contador == str.length){
					cont++;
					contador = 0;
				}
			}
		}
	}
	return cont;
}

String String::ToUpper() const{
	int i = 0;
	char* aux = new char[size];
	strcpy(aux, cadena);
	while (aux[i])	{
		aux[i] = toupper(aux[i]);
		i++;
	}
	String resultado(aux);
	delete aux;
	return resultado;
}

String String::ToLower() const{
	int i = 0;
	char* aux = new char[size];
	strcpy(aux, cadena);
	while (aux[i])	{
		aux[i] = tolower(aux[i]);
		i++;
	}
	String resultado(aux);
	delete aux;
	return resultado;
}

String String::LTrim() const{ //quitar el primer espacio por la izq
	int i = 0;
	int j = 0;
	int pos = 0;
	bool encontrado = false;

	while ((cadena[i] != 32) && (i < size))
		i++;
	pos = i;

	if ((pos == 0) || (pos == size)){
		encontrado = false;
	}
	else
		encontrado = true;

	if (encontrado){
		char* aux = new char[size - 1];
		for (int i = 0; i < pos; i++)	{
			aux[j] = cadena[i];
			j++;
		}
		for (int i = pos + 1; i < length; i++){
			aux[j] = cadena[i];
			j++;
		}
		aux[j] = 0;
		String resultado(aux);
		delete aux;
		return resultado;
	}
	else{
		return *this;
	}
}

String String::RTrim() const{
	int i = length;
	int j = 0;
	int pos = 0;
	bool encontrado = false;

	while ((cadena[i] != 32) && (i != 0))
		i--;
	pos = i;

	if ((pos == 0) || (pos == length)){
		encontrado = false;
	}
	else
		encontrado = true;

	if (encontrado){
		char* aux = new char[size - 1];
		for (int i = 0; i < pos; i++){
			aux[j] = cadena[i];
			j++;
		}
		for (int i = pos + 1; i < length; i++){
			aux[j] = cadena[i];
			j++;
		}
		aux[j] = 0;
		String resultado(aux);
		delete aux;
		return resultado;
		}
	else{
		return *this;
	}
}

String String::Trim() const{ //quitar todos los espacios
	int cont = 0;
	int j = 0;
	for (int i = 0; i < length; i++)
	if (cadena[i] == 32)
	cont++;

	char* aux = new char[size - cont];

	for (int i = 0; i < length; i++)
		if (cadena[i] != 32){
			aux[j] = cadena[i];
			j++;
		}
	//strcat(aux, (char*)cadena[i]);
	aux[length - cont] = 0;

	String resultado(aux);
	delete aux;
	return resultado;
}

String String::LSet(int len, char c) const{ //rellena los caracteres de diferencia entre len y lenght(cadena) de caracteres c:   lset(10,'x') => xxxxxxhola
	char* aux = new char[len + 1];

	if (len - length > 0) {
		int cont = len - length;

		for (int i = 0; i < cont; i++)
			aux[i] = c;
		aux[cont] = 0;
		//aux = &aux[cont];
		strcat(aux, cadena);

		aux[len] = 0;

		String resultado(aux);
		delete aux;
		return resultado;
	}

	return *this;
}

String String::RSet(int len, char c) const{ // rset(10,'x') => holaxxxxxx
	char* aux = new char[len + 1];

	if (len - length > 0) {
		int cont = len - length;

		strcpy(aux, cadena);

		for (int i = length; i < len; i++)
			aux[i] = c;

		aux[len] = 0;

		String resultado(aux);
		delete aux;
		return resultado;
	}

	return *this;
}

String String::StripExt() const{ //quita la extension de una cadena que contiene el nombre de un fichero:  "hola.txt" => "hola"
	int i = length;
	int j = 0;
	int pos = 0;
	bool encontrado = false;

	while ((cadena[i] != '.') && (i != 0))
		i--;
	pos = length - i;

	if ((pos == 0) || (pos == length)){
		encontrado = false;
	}
	else
		encontrado = true;

	if (encontrado){
		char* aux = new char[size - pos];
		for (int i = 0; i < length-pos; i++){
			aux[j] = cadena[i];
			j++;
		}
		aux[j] = 0;
		String resultado(aux);
		delete aux;
		return resultado;
	}
	else{
		return *this;
	}
}

String String::StripDir() const{ //quita el directorio   "hola.txt"
	int i = length;
	int j = 0;
	int pos = 0;
	bool encontrado = false;

	while ((cadena[i] != '/') && (i != 0))
		i--;
	pos = i;

	if ((pos == 0) || (pos == length)){
		encontrado = false;
	}
	else
		encontrado = true;

	if (encontrado){
		char* aux = new char[size];
		for (int i = pos + 1; i < size; i++){
			aux[j] = cadena[i];
			j++;
		}
		aux[j] = 0;
		String resultado(aux);
		delete aux;
		return resultado;
	}
	else{
		return *this;
	}
}

String String::ExtractExt() const{ //extension sin el punto.
	int i = length;
	int j = 0;
	int pos = 0;
	bool encontrado = false;

	while ((cadena[i] != '.') && (i != 0))
		i--;
	pos = i;

	if ((pos == 0) || (pos == length)){
		encontrado = false;
	}
	else
		encontrado = true;

	if (encontrado){
		char* aux = new char[size];
		for (int i = pos + 1; i < size; i++){
			aux[j] = cadena[i];
			j++;
		}
		aux[j] = 0;
		String resultado(aux);
		delete aux;
		return resultado;
	}
	else{
		return *this;
	}
}

String String::ExtractDir() const{ //directorio del fichero sin la barra /
	int i = length;
	int j = 0;
	int pos = 0;
	bool encontrado = false;

	while ((cadena[i] != '/') && (i != 0))
		i--;
	pos = i;

	if ((pos == 0) || (pos == length)){
		encontrado = false;
	}
	else
		encontrado = true;

	if (encontrado){
		char* aux = new char[size];
		for (int i = 0; i < pos; i++){
			aux[j] = cadena[i];
			j++;
		}
		aux[j] = 0;
		String resultado(aux);
		delete aux;
		return resultado;
	}
	else{
		return *this;
	}
}

String String::Read(const String& filename){
	FILE * pFile;
	long size;
	char * buffer = new char[1];
	String ret("");

	pFile = fopen (filename.ToCString(),"r");
	if (pFile==NULL) perror ("Error opening file");
	else
	{
		fseek(pFile, 0, SEEK_END);   // non-portable
		size = ftell(pFile);
		rewind (pFile);
		delete buffer;
		buffer = new char[size+1];
		fread(buffer, 1, size, pFile);
		fclose(pFile);
	}
	buffer[size] = 0;
	ret = buffer;
	delete buffer;
	return ret;
}

void String::Write(const String& filename, bool append) const{
	FILE * pFile;
	if (append)
		pFile = fopen (filename.ToCString(), "a");
	else 
		pFile = fopen (filename.ToCString(), "w");

	fwrite(cadena, size-1, 1, pFile);
	fclose(pFile);
}

int _tmain(int argc, _TCHAR* argv[])
{
	String s1 = "hola ";
	String s2 = "juan carlos";
	String s3 = "XXXXXXX";
	String s4 = "XXXXXXX";
	String s5 = "123";
	String s6 = "a b c d e";
	String s7 = "c:/master/fichero.txt";
	String res = "";
	bool resb = false;
	char c1 = 'x';
	int i1 = 0;
	float f1 = 0;
	const char *cad = "";

	
	resb = s3 == s4; //operador== funciona
	resb = s3 != s1; //operador!= funciona
	resb = s1 > s2; //operador> funciona
	resb = s1 < s2; //operador< funciona
	res = s1+s2; //operador+(string) funciona
	res = s1 + 'x'; //operador+(char)
	res = s1; //operador=(String) funciona
	res = 'x'; //operador=(char) funciona
	res += s1; //operador+=(String) funciona
	res += s1;
	res += 'x'; //operador+=(char) funciona
	c1 = s1[2]; //operador[] funciona
	i1 = s1.Length(); //Length() funciona
	String as = String::FromInt(6597); //fromInt() funciona
	as = String::HexFromInt(6597); //
	as = String::FromFloat(6597.1234); //
	i1 = s5.ToInt(); //funcion toInt() funciona
	f1 = s5.ToFloat(); //funcion toFloat() funciona
	cad = s5.ToCString(); //funcion toCString() funciona*
	s2.Write("prueba.txt", false);
	s1 = s2.Read("prueba.txt");
	res = s2.Replace("juan", "Yin"); 
	res = s2.Left(7); //funcion left() funciona 
	res = s2.Right(7); //funcion rigth() funciona 
	res = s2.Mid(3,5); //funcion mid() funciona 
	i1 = s2.Find("a", 1); //la funcion find() funciona 
	res = s1.ToUpper(); //funcion toupper() funciona 
	res = s4.ToLower(); //funcion tolower() funciona 

  	res = s2.LTrim(); //funcion ltrim() funciona
	
	res = s6.Trim(); //funcion trim() funciona
	res = s1.LSet(8, 'X'); //funcion LSet() funciona
	res = s1.RSet(8, 'X'); //funcion RSet() funciona
	res = s7.StripExt(); //funcion StripExt() funciona
	res = s7.StripDir(); //funcion StripDirrim() funciona
	res = s7.ExtractExt(); //la función extractExt funciona
	res = s7.ExtractDir();  //la función extractDir funciona

	res = ' ' + res;
	res = "shit" + res;
	 
	return 0;
}
