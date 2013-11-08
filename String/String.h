//entregar una interfaz, sin implementar. se pueden utilizar las librerias standar de c (str SIIIII), pero no las de c++ (stl NOOO)
//tambien implementar algo que resuelva:  str = "bla" + str
//const al final: ese objeto no va a ser modificado dentro de la función. 
//static: operador de clase, se puede llamar al método sin haber creado un objeto

class String {
private:
	char* cadena; //cadena de caracteres
	int length; //longitud de la cadena
	int size; //tamaño que ocupa la cadena

public:
	String(const char* str = "");
	String(const String& str);
	~String();

	bool operator==(const String& other) const;
	bool operator!=(const String& other) const;
	bool operator<(const String& other) const; //por orden alfabético  a < z
	bool operator>(const String& other) const;
	String operator+(const String& other) const;
	String operator+(char c) const;
	String& operator=(const String& other);
	String& operator=(char c);
	String& operator+=(const String& other);
	String& operator+=(char c);
	char& operator[](unsigned int pos); //indice de tabla
	const char& operator[](unsigned int pos) const;

	int Length() const;

	static String FromInt(int val);
	static String HexFromInt(int val);
	static String FromFloat(float val);

	int ToInt() const;
	float ToFloat() const;
	const char* ToCString() const;

	String Left(int n) const; //devuelve una subcadena con los caracteres de la izquierda. "hola" --- left(2)="ho"
	String Right(int n) const;
	String Mid(int ofs, int n); //n caracteres a partir del ofs.  "hola" --- mid(1,2)="ol"
	String Replace(const String& find, const String& rep) const;
	int Find(const String& str, int ofs) const;

	String ToUpper() const;
	String ToLower() const;
	String LTrim() const; //quitar el primer espacio por la izq
	String RTrim() const;
	String Trim() const; //quitar todos los espacios
	String LSet(int len, char c) const; //rellena los caracteres de diferencia entre len y lenght(cadena) de caracteres c:   lset(10,'x') => xxxxxxhola
	String RSet(int len, char c) const; // rset(10,'x') => holaxxxxxx

	String StripExt() const; //quita la extension de una cadena que contiene el nombre de un fichero:  "hola.txt" => "hola"
	String StripDir() const; //quita el directorio   "hola.txt"
	String ExtractExt() const; //extension sin el punto.
	String ExtractDir() const; //directorio del fichero sin la barra /

	static String Read(const String& filename);
	void Write(const String& filename, bool append = true) const;
};

// Operadores no miembros

bool operator==(const char* c, const String& other);
bool operator!=(const char* c, const String& other);
bool operator<(const char* c, const String& other);
bool operator>(const char* c, const String& other);
String operator+(const char* c, const String& other);
String operator+(char c, const String& other);