// C VE C++ FARKLILIKLARI 
/*

	bu kısım https://github.com/BatuhanKaratas/NEC_CPP_Kursu kısmından alınmıştır. 
	## C-C++ Farklılıkları

C++11 (Modern C++)
C++14
C++17
C++20
C++23


C++ multi-paradigm bir dildir. 

	* Prosedürel p
	* Nesne Tabanlı
	* Generic (Türden Bağımsız Programlama) 
	Örn: Template
	* Functional Programming
	Örn: Lambda Expression
	* Data Abstraction
	Örn: Operator Overloading
	

C++ efficient bir dildir. 
* Memory ve CPU'yu etkin bir şekilde kullanabilirsiniz.

**Not:** 
* Undefined Behaviour: Compile time'da geçerli fakat run time'da belirsizlik yaratan davranışlardır.
* Unspecified Behaviour: Compiler'a göre davranışı değişen kod.

Undefined Behaviour örnekleri:
* int x;' i initialized etmeden kullanmak.
* nullptr'yi dereference yapmak.
* Buffer overflow

Unspecified Behaviour örnekleri:
* `a= f1() + f2() * f3();` Fonksiyonun çağrılması sırası compiler'a bağlıdır. 

* ```
  const char * p1= "Adnan";
  const char * p2= "Adnan"; 
  ```
  String literalleri static ömürlüdür. (program sonuna kadar tutulur.) "Adnan Aydın" ifadesi memory'de iki farklı yerde mi tutulacak? (Compiler'a bağlıdır)
 
Implementation Defined Behaviour örnekleri;
* `char c; c << 4;`
  Bu durumda c'nin signed unsigned olduğu bilinmiyor. Shift işlemi sign'lı bitten itibaren mi kaydırılmaya başlanacak?

* `int a;`
  Bellekte ne kadar yer tutacak? (4 byte or 8 byte)

### C-C++ Farklılıkları

* Implicit Int
  ```
  func(int x) { 
   return x+1; 
  }
  ```
  Function return type   belirtilmezse C'de default unsigned int kabul edilir.
  

* Non-Return Statement: C'de void dışında bir return type'a sahip bir function kendi içinde return etmesede olur.

* Implicit Function Decleration: C'de tanımlanmamış fonksiyonlar bile default olarak tanımlanır. (`"int bar()"` şeklinde) 

* Void Func Parameter: C'de "int foo()" ile "int foo(void)" aynı değildir.
   * "int foo()": Parametre alabilir.
   * "int foo(void)": Kesinlikle parametre alamaz.

* Function Parameter Name: C'de "void func(int)" bir syntax error'dur. 
 Not: C++'da bu parametre isim zorunluluğunun olma sebebi;
   * Kullanılmayacak parametrelere isim verilmez.(Clean Code)
   * Function signature'ını overloading için değiştirmekte kullanılır.
 
 * Inner Loop Extra Block
 ```
 for(int i=5; ; )
 {
    {
    	int i= 66;
    }
 }
 ```
 C'de compiler for içinde ekstra bir blok açar.(Assembly code) Bu yüzden for içerisindeki ve blok içerisindeki değişkne ismi aynı olsa bile syntax hatası oluşmaz.
 
#### Türlere ve Tür Dönüşümlerine İlişkin Farklılıklar

* "Bool" veya "bool" type'ın değeri unsigned int'dir. C++'da li gibi gerçekten true-false değildir.
	* Non-zero tüm değerler true'dur.
      Zero değerler ise false'dur.
    * C++17 ile bool değişkeni ++ veya -- ile çalışması engellendi. Çünkü bu veri tipi 1 byte ve bitsel olarak memory'de tutulamıyor.
    * C++'da aritmetik type'lardan bool'a dönüşüme müsade edilir. 
    ```
    int x= 45;
    bool b= x; // Implicit conversion. 
    // Legaldir. Value:true
    ```
   * C++'da pointer to bool'a dönüşüme müsade edilir.
    ```
    int x=100;
    int * ptr= &x;
    bool b1= ptr; // Legal Value: true;
    int *ptr2; 
    // Pointer default initialization değeri nullptr'dir.
    bool b2= ptr2; // Legal Value: false;
    // nullptr = false, !nullptr = true.
    ```

  * C++'da bool'dan aritmetiğe dönüşüm var fakat pointer'a dönüşüm yoktur.
  ```
  bool b= true;
  int x= b; // Legal value: 1
  bool b1= false;
  int y= b1; // Legal value: 0
  int *ptr= b; // Illegal Syntax Error
  ``` 
 * User Defined Type (Struct, Enum, Union)
 C'de User Defined Type'ların type def olarak tanımlanması lazımdır.
 ```
 typedef struct Data{
	 int a, b, c;
 } Data;
 ```
 
#### Const anahtar sözcüğüne yönelik farklılıklar
* Const Variable Initialization
  C'de "cont int x;" // Legaldir. Initialize zorunluluğu yoktur. Default initialize edilir.
  Fakat C++'da const değişkenler initialize edilmek zorunda. (Global değişkenler hariç)
* Const Expression Usage
```
const int x= 10;
int a[x]= {0}; // C için syntax hatası
// C compiler'ı x'i const expression olarak değerlendirmez.
```
 
Not: C++'da const değilkenleri initialize ederken sabit bir sayı verirsek const özelliğini kaybetmeden kullanabiliriz. Fakat  global fonksiyon ile initialize edilirse const özelliği kaybolur.

```
const int size= 100;
const int ds= getsize();

int a1[size]
int a2[ds] // Syntax error
```

#### External - Internal Linkage

C++'da;

```
const int x; // External linkage
const static int x; // Internal linkage
```


C++'da global const nesneler internal linkage'dır.
C'de global const nesneler external linkage'dır.

#### Genel C++ Farklılıkları

Not: 
```
`int x= 10; // Bu adresin türü(&x) int *'dır. `
`const int x= 10; // Bu adresin türü(&x) 
// const int *'dır.`
```

* C'de "const T *" to "T *"'a implicit conversion vardır.
C++'da bu dönüşüm gerçekleşmez.

```
cosnt int x= 10;
int *p= &x; // C++ için syntax error. C'de OK.
```

```
int x= 10;
int * const ptr= &x; // const ptr to int
// "ptr" hayatı boyunca x'i göstermek zorunda.
int y{};
ptr= &y; //Syntax error
*ptr= 45; (Pointer dereferencing)

const int * ptr= &x; // ptr to const int
// "*ptr" ptr'nin gösterdiği değer değişemez.

*ptr= 45; // Syntax error

const int * const p = &x; // const ptr to const int
// "*ptr" ptr'nin gösterdiği değer 
// ve değişken değişemez.

```

```
void func(T *p) // Out param (Read-Write)
void foo(const T * p) // In param (Just Read)
```

* C++'da undefined behaviour' a sebebiyet vermemek için değişkenlerin ilk değerleri her zaman atanmalıdır.

```
const int * ptr; // C++'da legaldir.
int * const ptr; // C++'da Syntax Error'dur. 
// ptr'ye ilk değer atanmak zorundadır.
```

* C++'da T to T * implicit dönüşümü yoktur.
```
// C'de
int x= 35;
int *p= x; // Legal implicit conversion int to int *

//C++'da
int *p = x; // Syntax Error
``` 

* C++'da farklı tür pointer'lar arası implicit dönüşüm yoktur.

```
//C'de
double dval= 45.2;
char *p= &dval; double * to char * implicit conversion var.
//C++'da
char *p= &dval; double * to char * implicit conversion yok.
// Syntax Error
```   

* C++'da void * to int * implicit dönüşümü yoktur.
```
//C'de
int * p= malloc(10 * sizeof(int); // void * to int * 
//dönüşümü var.

//C++'da
int * p= malloc(10 * sizeof(int); // void * to int * 
//dönüşümü yok. Syntax Error

```

#### Enum Data Structure Farkları

* C'de enum bileşenlerin underlying type'ı (default type) int'dir. Değiştirilemez. C++'da enum bileşenlerinin type'ını user seçebilir veya enum bileşene atanan değer range dışındaysa  örneğin; double'a çekilir. 

* C'de aritmetik türlerden enum türlere dönüşüm var. Hatta farklı enum türleri arasında da dönüşüm var.

```
enum Color {W, G, B};
enum Color myColor;
myColor = 2; // // Aritmetik to Enum
// C'de Legal 
// C++'da Illegel Syntax error

enum Color myColor2= G;
int x= myColor2; // Enum to aritmetik
// Legal for C and C++
// Fakat "enum class" or "scoped enum" yapısı ile 
// C++'da bu dönüşümede müsade edilmedi.                          
```

#### Ek Bilgi:
#### Scope Leakage

Bir değişkenin kullanım alanı dışındada varlığını sürdürmesi.

```
std::string getstr();

void func()
{
	std::string s= getstr(); // Scope Leakage oluştu.
	
	if (s.size() > 10)
	{
		
	}
}

-----------------------------------------------------

void func()
{	
	if (std::string s= getstr(); s.size() > 10)
	{
		// S'in scope'unu kısıtladık. If scope'u içine 
		//  koyduk. Çünkü bu scope yeterli bizim için.
		// If içinde initialization C++17 ile gelen bir 
		// özelliktir.
	}
}
```

* Scope leakage'ın bir diğer dezavantajı ise örneğin string nesnesi memory'de tutuluyor. Gereksiz yere bu nesne yok olana kadar memory'de yer tutmaya devam ediyor. 

```
if (int x= foo()) 
// x'i foo'nun return value'su ile initialize eder ve
// x != 0 kontrolü yapar.

if (int * x= foo()) 
// x'i foo'nun return value'su ile initialize eder ve
// x != nullptr kontrolü yapar.

```

* Karakter Türünün Tipi
	* 'A' C'de 4 byte int type
	* 'A' C++'da ise 1 byte char type'dır.

* String Literal Türünün Tipi
    * C'de "akif"'in değeri char[5] (4 karakter + null termination "/0")
    * C++'da "akif"'in değeri const char[5]'dir.
    C++'da string literal'ini değiştirmek undefined behaviour'dur. Çünkü string literal'i kullanıldığında gelen yapı const char *'dır. Yani array decay sonucunda &array[0] gelir;
    
#### SizeOf Operandı
* sizeof operand'ının tipi size_t'dir.
* sizeof unevaluated context'dir.
```
Örnek;
int x= 10;
size_t y= sizeof(x++);
printf("%zu %d/n", y, x); // Output: 4 - 10
```

#### Array Decay'in Uygulanmadığı Durumlar
*
  ```
  int a[10] = {1, 5, 7};
  printf("%zu/n", sizeof(a)); // Output: 40 (4 * 10)
  ```
  Çünkü a array'i sizeof'un içinde çağırıldığında Array Decay çalışmaz ve array'in tamamı gelir.

* a -> &a[0] // a array'i Array Decay açılımı
* &a -> int(*)[10] // Tüm array belirtmek için kullanılan tür. "&" operatörünü uygularsak array'e Array Decay çalışmaz ve array'in tamamı gelir.

```
//Array Decay çalışması:
printf("%p %p \n", a, a+1); Output: a[0]'ın adres değeri
                                    a[1]'in adres değeri
```


* C++'da String Literal Kullanımı
  * char *p= "batuhan"; // Syntax Error. Çünkü "batuhan" string literal'inin array decay'i const char *'dır. const T * to T*'a implicit dönüşüm C++'da yapılamaz.
  * char str[4]= "anıl"; // C'de bu ifade geçerlidir. Fakat array null termination karakterini içerecek kapasitede değil. Bu yüzden kullanımı tehlikelidir. C++'da ise kapasite yeterli olmadığı için bu bir Syntax Error'dur.
 
#### Ek Bilgi: Expressions (C++)

* 10u (unsigned int) 
* 4.f(float)
* 6llu (unsigned long long)
* x+5
* f(x)
* x++
* f(x)>g(x)
* x*x + y*y
* 10ul (unsigned long)


* Her expression'nın bir data type'ı ve value category'si vardır.

* short s1= 5, s2= 7;
  s1 + s2 expression'nın data type'ı integer'dır. Int'ın alt type'ları ile işlem yapılırsa int'e promote olur. (Integral Promotion)

*  char c= 'A'
*  +c veya -c expression'larının data type'ı int olur. Çünkü '+' ve '-' operatörleri ile char to int promotion gerçekleşir.
*  5 + 3.2 expression data type'ı double olur.
*  int x= 10; 
   x > 5 ? 3 : 4.7; // ifadesinin data type'ı double olur.
   

#### C Value Category
* L value expression (Memory'de yer tutan ve bir nesneye karşılık gelen ifadeler)
* R value expression 

##### Value Category Saptama Testi
* & operandını expression'nun önüne koyduğumuzda compiler syntax error vermezse bu ifade bir L value'dur. Hata verirse bir R value'dur.

Örnek;
```
char c = 10; (c bir L value'dur.)
+c ifadesi ise integral promotion'a uğrar 
ve tipi int'a dönüşür. 
Value kategorisi ise R value'ya dönüşür. 
```

#### C++ Value Category
* PR value
* L value
* x value

* int x= 10; (x L valeu'dur. Her değişken ismi bir L value'dur.)

* x++; PR value'dur.
* ++x; Left value'dur.
* 34; PR value
* int foo(); foo() PR value'dur.
* ```
  int x=10;
  int *p = &x; // *p L value'dur. 
  ```
* std::move(x); // X value'dur.
* int & foo(); foo() L value'dur.

#### Ek Bilgi:

#include <cstring> //C'den gelen string header'ı
#include <string> //C++ string header'ı
#include <cstdio> //C++'da bu şekilde çağrılır.
#include <stdio.h> //C'de bu şekilde çağrılır.

---

#### Initialization on C++

* int x; // Default initialization. C++'da otomatik ömürlü değişken default initialize edilirse compiler "garbage value" verir. Buda undefined behaviour'dur.

Static Ömürlü Değişkenler
* Global scope'daki değişkenler
* Static anahtar sözcüklü değişkenler
* String literalleri sonucunda oluşan const char * değişkenleri

Static ömürlü bir değişken tanımlandığında compiler Zero Initialization uygular.
Zero initialization değerleri;

  * Aritmetik değişkenler için 0
  * Boolean değişkenler için false
  * Pointer değişkenler için nullptr'dir.

##### C++ Initialization Türleri
* int x= 10; // Copy Initialization
* int x(98); // Direct Initialization
* int x{6}; //Uniform or Brace Initialization

```
Örnek;
double dval= 5.6;
int i= dval; // Legal narrowing conversion gerçekleşir. Loss of data oluşur.
int i2(dval); // Legal narrowing conversion gerçekleşir. Loss of data oluşur.
int i3{dval}; Illegal Syntax Error. Her zaman Uniform initialization tercih etmek daha güvenlidir. 
```

```
Örnek;
int x{}; // Value initialization  Value: 0.
// Value initialization'da static scope değişkenlere uygulanan zero initialization uygulanır.

int y; // Otomatik ömürlü değişken Garbage value olur ve bu C++'da bir undefined behaviour'dur.

// "int x{}" ile "int x{0}" aynıdır.

int a[4] = {};
int a[4] {};
int a[4] = {0};
// a array'ini initialize eden bu kod satırlarının hepsi aynıdır. Hepside a int array'inin tüm elemanlarını 0 ile initialize eder.
```

Not: const nesneler default initialize edilemez. Syntax error'dur.
Not: int &p referans değişkenler default initialize edilemezler. Syntax error'dur.


#### Ek Bilgi
#### Scoot Meyer - Most Vexing Parse

* Öyle bildirimler bilgi var ki 
  *  Nesne tanımlama (Object Instantiation)
  *  Fonksiyon Bildirimi (Function Decleration)

Bu bildirimlerde function decleration'nın önceliği vardır.

```
struct A {};
struct B { B(A); };
B bx(A()); // Most vexing parse çalışır ve compiler bunu bir fonksiyon bildirimi olarak algılar.
B bx{A()}; // Most vexing parse çalışmaz. Böylece bu bir nesne tanımlama olarak compiler tarafından algılanır.
```

#### Type Deduction

Compile Time ile ilgili şeyler static'dir.
Run Time ile ilgili şeyler dynamic'dir.

int * foo(const int *, size_t);

auto fp = &foo; // Auto type deduction
// Extraction of fp: int * (*fp) (const int *, size_t);

##### AAA(Almost Always Auto)

* Bu bir kod yazma stilidir. Açılımı neredeyse her zaman auto type deduction kullan.

auto x= 10; // Compile Time'da compiler x'in tipini int olarak oluşturur.

Not: auto değişkenin default initialization'ı olmaz.

const auto x = 10; // auto = int Legal
int ival{};
auto * x= &ival; // auto = int

Null Pointer Conversion
int * ptr= 0;
int * ptr= NULL; //NULL stdio.h'da #define edilmiş bir makrodur. Bu yüzden bu header dosyasını #include etmek zorunludur.

C++11'den itibaren;
int *p= nullptr; // Bu keyword 0 ve NULL macrosunun yerine geçmesi için gelmiştir. Keyword olduğu için include'a gerek yoktur. Türü nullptr_t'dir. Sadece pointer'ları assign ederken kullanılır. 


Not:
int *p{nullptr};

p == nullptr ve !p aynı ifadelerdir. 

nullptr PR value'dur.























*/

// C++ 
// çift çizgi tek satırlık yorum satırı oluşturur ve /* */ çok satırlı bir yorum mettni oluşturur.

// KONULAR :

/*
C++ programlama dili oldukça kapsamlı bir konu olduğundan, aşağıdaki başlıklar C++ ile ilgili çeşitli konulara genel bir bakış sağlayabilir:

C++ Temelleri

Veri türleri
Operatörler
Kontrol yapıları
Döngüler
Fonksiyonlar
Sınıflar ve Nesneler
İşaretçiler
Bellek Yönetimi
C++ İleri Konular

Şablonlar
Kalıtım
Polimorfizm
Sanal fonksiyonlar
İstisnalar
STL (Standard Template Library)
C++11, C++14 ve C++17 yenilikleri
C++ Uygulamaları

Oyun Geliştirme
Yazılım Geliştirme
Gömülü Sistemler
Mobil Uygulama Geliştirme
Veri Yapıları ve Algoritmalar
Makine Öğrenmesi ve Yapay Zeka
C++ Araçları ve Çalışma Ortamı

Derleyiciler
Kod Düzenleyiciler
Hata Ayıklayıcılar (Debugger)
Profilleme Araçları
Makefile ve CMake
C++ için IDE'ler

Bu sadece birkaç başlık, C++ hakkında daha birçok konu ve alt konu bulunmaktadır.

*/


// Konu 1 : Değişkenler Veriler
/*
* ör: 1 2 3 4 5 6 7 8
	Değişkenler programlamada verilerin saklanması için kullanılan alanlardır
	Değişken türü ve adı belirlenir ve değişkene değer atanabilir.

	Örneğin sayılar için tip int(integer)
	gerçel sayılar için float veya double tip türleri kullanılabilir.

	Değişken adı,programda değişkeni tanımlamak için kullanılan bir etikettir ve genellikle-
	sembolik bir isimdir ( örneğin :x , y , z ).

	örnek :

	int x;
	float y;
	double z;

	değişkenler x , y , z' dir.

	x = 5;
	y = 3.14;
	z = 8.5;

	değişkenlere değerler atanmıştır

	tip değişken_adi = değer ;

	Bu şekilde C++'da değişkenellr kullanılarak verilerin saklanması ve kullanılması mümkündür
	Daha sonra bu değişkenler aracılığıyla işlemler yapılabilir veya diğer değişkenlere atamalar yapılabilir.

*/


// Değişken Veri Türleri 
/*
	C++ programlama dilinde bir değişkenin türü, o değişkenin saklanabileceği
	veri tipini belirler.Örneğin, bir sayı değişkeni 'int' türünde tanımlanabilir
	ve bu sayıyı saklayabilir. Aynı şekilde, bir metin değişkeni 'string' türünde tanımlanabilir ve metinsel bir veriyi saklayabilir.

	Aşağıda verilen değişken türleri en yaygın olarak kullanılan c++ değişken türleridir:

	1. 'int' : Tam sayı verileri için kullanılır.
	2. 'float' : Ondalıklı sayı verileri için kullanılır.
	3. 'double' : Daha büyük ondalıklı sayı verileri için kullanılan değişken türüdür.
	4. 'char' : Tek karakter verileri için kullanılan değişken türüdür.
	5. 'string' : Metinsel veriler için kullanılan değişken türüdür.

	Her bir değişken türü bellekte farklı miktarda yer kaplar ve farklı veri tiplerini destekler.
	Örneğin, 'int' türü daha küçük verileri desteklerken, 'double' türü daha büyük verileri
	destekler.

*/



// Konu 2 : Matematiksel İşlemler
/*

* Örnk : 2 3 4 6 8
	Matematiksel işlemler, C++ dilinde değişkenler arasında yapılabilir.
	C++ dilinde, aşağıda ki temel matematiksel işlemler yapılabilir:

	1.Toplama(+)
	2.Çıkarma(-)
	3.Çarpma(*)
	4.Bölme(/)
	5.Mod(%)

	-Üs alma işlemi için pow fonksiyonu kullanılır ve cmath kütüphanesinde bulunur.-
	-Karekök işlemleri için sqrt fonksiyonu kullanılır ve cmath kütüphanesinde bulunur.
	Bunlara ilerde değineceğiz.-

	Örneğin Toplama işlemi için
	int x = 10 , y= 30 , toplam;
	toplam = x + y;

	Örneğin Çıkarma işlemi için
	int x = 10 , y= 30 , fark;
	fark = x - y;

	Örneğin Çarpım işlemi için
	int x = 10;
	int y = 20;
	int çarpım;
	çarpım = x * y;

	Örneğin Bölme işlemi için
	int x = 8;
	int y = 2;
	int bölüm;
	bölüm = x /y ;

	Örneğin mod işlemi için
	int a = 14;
	int b = 5;
	int mod = a % b;

	-- mod işlemi = bölümünden kalan sayı --

*/


// Konu 3 : Syntax 
/*// Keywords ( Anahtar Kelime )
	C++ dili bir çok anahtar kelimeye sahiptir.
	Bu anahtar kelimeler, c++ dilinin standart kütüphanelerine ait fonksiyonları ve yapıları tanımlamak
	için kullanılır. Aşağıdaki anahtar kelimelere örnek verilebilir:

	int: Tam sayı türünü tanımlar.
	float: Ondalıklı sayı türünü tanımlar.
	double: Ondalıklı sayı türünü tanımlar.
	char: Karakter türünü tanımlar.
	void: Bir fonksiyonun geri dönüş değeri olmayacağını tanımlar.
	while: Döngü yapmak için kullanılır.
	for: Döngü yapmak için kullanılır.
	if: Koşullu durumları tanımlamak için kullanılır.
	else: if koşulu yerine geçmek için kullanılır.
	switch: Birden fazla koşulu kontrol etmek için kullanılır.

	Bu sadece birkaç örnek. C++ dilinde çok daha fazla anahtar kelime bulunmaktadır.


	"#include<iostream>" ifadesi C++ programınızda "iostream" kütüphanesinin kullanılmasını sağlar.
	"iostream" kütüphanesi standart giriş/çıkış sistemi için gerekli olan fonksiyonları ve veri türlerini içerir.

	"cout" ifadesi standard çıktı streami olan ekrana veri yazdırmayı sağlar.

	"cin" ifadesi standard giriş streami olan klavyeden veri okumayı sağlar.

	Bu kelimelere örnek vermek gerekirse, aşağıdaki kod örneği kullanıcıdan bir tam sayı alır ve ekranda bu sayıyı yazdırır:



	#include <iostream>
	using namespace std;

	int main()
	{
		int x;
		cout << "Lütfen bir tam sayı girin: ";
		cin >> x;
		cout << "Girdiğiniz tam sayı: " << x << endl;
		return 0;
	}

*/


// 4. KONU OPERATÖRLER
/*
* * Örnk : 2 3 4 6 8
	Bir programda bir değişkenin değerini değiştirmek, bir değişkenin değerini başka bir değişkenle
	karşılaştırmak, bir değişkenin değerini arttırmak veya azaltmak gibi işlemler için kullanılırlar.

	C++ da kullanılan temel operatörler şunlardır :


	1. Aritmetik operatörler : +, - , * ,/ , % (mod) .

	2. Atama operatörleri: =, += , -= , *=, /= , %=

	3. Karşılaştırma operatörleri: == , != ,> , < , >= , <=

	4. Mantıksal operatörler: && (ve), || (veya), ! (değil)

	5. Bitsel operatörler: & (ve) , | (veya) , ^ ( özelleştirilmiş veya ) , ~ ( tamsayı tersi )
	, << (sol kaydırma), >> (sağ kaydırma)


	Operatörlerin kullanımı çok basittir. Operatörler veriler arasında kullanılır ve sonuç olarak yeni
	bir değer oluşur.

	Operatörler öncelikli olarak matematiksel ve mantıksal işlemler için kullanılır.


	// Örnekler


	ARİTMETİK OPERATÖRLER

	int x = 10 , y= 20;
	cout<< x + y << endl;		//output (çıkış) : 30
	cout<< x - y << endl;		//output (çıkış) : -10
	cout<< x * y << endl;		//output (çıkış) : 200
	cout<< x / y << endl;		//output (çıkış) : 0.5
	cout<< x % y << endl;		//output (çıkış) : 10


	KARŞILAŞTIRMA OPERATÖRLERİ


	int x = 10 , y= 20;
	cout<< (x == y ) << endl;		//output (çıkış) : 0 YANLIŞ
	cout<< (x != y ) << endl;		//output (çıkış) : 1 DOĞRU
	cout<< (x <  y ) << endl;		//output (çıkış) : 1 DOĞRU
	cout<< (x >  y ) << endl;		//output (çıkış) : 0 YANLIŞ
	cout<< (x <= y ) << endl;		//output (çıkış) : 1 DOĞRU
	cout<< (x >= y ) << endl;		//output (çıkış) : 0 YANLIŞ


	ATAMA OPERATÖRLERİ

	int x = 10;
	x += 5;                    // x = x + 5 = 15
	x -= 3;                    // x = x - 3 = 12
	x *= 2;                    // x = x * 2 = 24
	x /= 4;                    // x = x / 4 = 6
	x %= 3;                    // x = x % 3 = 0

	*/


	//5.Konu Koşullu İfadeler 
	/*
		ör : 5 , 7
		C++ dilinde koşullu ifadeler belirli bir koşulun doğru çalışıp çalışmadığını kontrol etmek için kullanılır.
		Bu ifadeler, belirli bir koşulun doğru veya yanlış olduğuna bağlı olarak belirli kod bloklarının çalışmasını sağlar.

		C++ dilinde en sık kullanılan koşullu ifadeler şunlardır:

		1. if durumları : Bir koşul doğru ise belirli bir kod bloğunu çalıştırmak için kullanılır. Örnek:

		if ( x > 0 ) {
		cout << " x pozitiftir " ;
		}

		-----------------------------------------------------------------------------------------

		2. if else durumları: Doğruysa bir kod bloğunu yanlışsa diğer kod bloğunu çalıştırır.

		if(x>0)
		{
			cout<< " x pozitif " ;
		}
		else
		{
			cout<<" x negatif " ;
		}

		-----------------------------------------------------------------------------------------

		3.else if durumları : Bir koşul yanlışsa başka bir koşulu kontrol etmek ve ona göre çalıştırmak için kullanılır.


		if(x>0)
		{
			cout<< " x pozitif " ;
		}
		else if (x<0)
		{
			cout<<" x negatif " ;
		}
		else
		{
			cout << " x sıfırdır " ;
		}

		------------------------------------------------------------------------------------

		4. ternary operator ( üçlü operatör ):

		C++ ve birçok programlama dilinde kullanılan bir operatördür.
		Bu operatör, koşullu bir ifadeyi kısaltmak için kullanılır.

		Ternary operator, bir koşul ifadesi, bir "?" işareti, bir "true" ifadesi, bir ":" işareti ve bir "false" ifadesi şeklinde yazılır.
		Eğer koşul ifadesi doğruysa "true" ifadesi, yanlışsa "false" ifadesi çalıştırılır. Örneğin:

		x = (a > b) ? a : b;

		Yukarıdaki örnekte, "a" değişkeni "b" değişkeninden büyükse, "x" değişkeni "a" değişkenine atanır.
		Aksi takdirde, "x" değişkeni "b" değişkenine atanır.

		Ternary operator, kodun okunabilirliğini arttırmak ve daha az kod yazmak için kullanışlıdır.
		Ancak, çok karmaşık veya uzun koşullar için kullanılması tavsiye edilmez, çünkü bu durumda kodun anlaşılması zorlaşabilir.

		Özetle, ternary operator koşullu ifadeleri kısaltmak için kullanılan bir operatördür
		ve C++ programlama dilinde sık sık kullanılır.




	*/


	//6. Konu Döngüler 
	/*
	C++ programlamada döngüler, belirli bir koşulu sağlayan bir bloğun tekrar tekrar çalıştırılması için kullanılır.
	Bu sayede, kodlarınızı belirli bir koşula kadar tekrarlamak ve kodlarınızı daha az sayıda satırda yazmak mümkün hale gelir.

	C++ dilinde 3 adet döngü bulunmaktadır : for, while, ve do - while.


	for döngüsü : Bu döngü, belirli bir sayıda tekrar yapmak için kullanılır.Şu şekilde yazılır :
	for (başlangıç_değeri; koşul; artırım_değeri) {
	  // Döngü gövdesi
	}
	Burada, başlangıç_değeri döngünün başlatıldığı noktadaki değeri,
	koşul döngünün ne zaman durdurulacağına karar veren bir koşulu,
	ve artırım_değeri ise döngü tekrarlanırken değişecek olan değeri belirtir. Örneğin:

	for (int i = 0; i < 5; i++) {
	  std::cout << i << std::endl;
	}
	Bu kod bloğu, i değişkeninin 0 değeriyle başladığını, i değeri 5 olana kadar tekrar edeceğini ve
	her seferinde i değerini 1 artıracağını söyler.
	Bu döngü 0, 1, 2, 3 ve 4 sayılarını ekrana yazdıracaktır.

	//While Döngüsü
	Bu döngü belirli bir koşul doğru olduğu sürece tekrarlanır.

	while(koşul)
	{
		//döngü gövdesi
	}

	int i = 0;
	while (i < 5) {
	  std::cout << i << std::endl;
	  i++;
	}

	//Do while döngüsü
	Bu döngü diğer döngülerden farklı olarak döngü gövdesini en az bir kez çalıştırır sonra koşulu
	kontrol eder ve eğer doğruysa tekrar eder

	do{
		// döngü gövdesi
	} while (koşul)

	--------------------------
	#include <iostream>

	int main() {
		int i = 1;
		do {
			std::cout << i << std::endl;
			i++;
		} while (i <= 10);

		return 0;
	}
	--------------------------
	Bu kod bir do-while döngüsü örneği. Program başladığında, i değişkeni 1 olarak atanır.
	Ardından, do bloğu içinde i'nin değeri ekrana yazdırılır ve i bir artırılır.
	i 10'a eşit veya küçük olduğu sürece, döngü tekrarlanır.
	Bu döngü, 1'den 10'a kadar olan sayıları ekrana yazdıracaktır.

	*/

	//karar yapıları
	/*
	C++ dilinde kullanılan karar yapıları aşağıdaki gibidir :

	if - else : Belirli bir koşulun sağlanıp sağlanmadığını kontrol etmek için kullanılır.


	switch - case: Farklı değerlerin kontrol edildiği ve her bir değere göre belirli kod bloklarının çalıştırıldığı bir karar yapısıdır.


	ternary operator : Üç operandlı bir işlemci ile tek satırda bir koşul kontrolü yapmak için kullanılır.

	goto : Etiketlere ve belirlenmiş kod bloklarına doğrudan atlamak için kullanılabilir.
	Ancak, modern C++ programlamada goto kullanımı genellikle önerilmemektedir.
	*/

	// Karar yapıları örnekleri 
	/*
	// if - else
	-----------------
	int x = 5;
	if (x > 10) {
		cout << "x 10'dan büyüktür" << endl;
	}
	else {
		cout << "x 10'dan küçüktür veya eşittir" << endl;
	}
	-----------------
	//switch case
	----------------
	int day = 3;
	switch (day) {
	  case 1:
		cout << "Pazartesi" << endl;
		break;
	  case 2:
		cout << "Salı" << endl;
		break;
	  case 3:
		cout << "Çarşamba" << endl;
		break;
	  default:
		cout << "Hafta içi değil" << endl;
	}
	----------------------

	//ternary operatörü
	int x = 10;
	int y = (x > 5) ? 3 : 7;
	cout << y << endl; // y = 3

	-------------------------

	// if else if else

	------------------------
	int time = 14;
	if (time < 12) {
	  cout << "Günaydın!" << endl;
	} else if (time < 18) {
	  cout << "İyi günler!" << endl;
	} else {
	  cout << "İyi akşamlar!" << endl;
	}
	-----------------------------

	//nested if else

	-----------------------------
	int x = 10, y = 15;
	if (x > 5) {
	  if (y > 10) {
		cout << "x, 5'ten büyüktür ve y, 10'dan büyüktür." << endl;
	  }
	}

	-----------------------------


	goto ifadesi, programcıların istediği herhangi bir yerdeki bir kod bloğuna atlamalarını sağlar.
	Ancak goto ifadesinin kullanımı, kodun okunabilirliğini azaltır ve program hatası kaynağı olabilir.
	Bu nedenle, goto ifadesinin kullanımı modern programlama dillerinde tavsiye edilmez.

	---------------------------------
	#include <iostream>

	int main() {
	  int x = 0;

	  std::cout << "Enter a positive integer: ";
	  std::cin >> x;

	  if (x <= 0) {
		std::cout << "The number must be positive." << std::endl;
		goto end;
	  }

	  for (int i = 1; i <= x; ++i) {
		std::cout << i << " ";
	  }

	end:
	  return 0;
	}
	-----------------------------

	Bu örnekte, kullanıcıdan bir sayı alınır ve eğer sayı negatif veya sıfıra eşitse, goto ifadesi kullanılarak program,
	programın sonuna kadar olan kısımda bulunan end: etiketine atlar.
	Aksi takdirde, bir for döngüsü kullanılarak sayının 1'den başlayarak ekrana yazdırılması sağlanır.

	-----------------------------------


	*/

	// Break ve Continue ifadeleri
	/*


	C++ programlama dilinde, break ve continue ifadeleri, kontrol yapılarını kontrol etmek için kullanılan ifadelerdir.

	break ifadesi: Bu ifade, bir döngü içinde bulunduğu anda, döngüyü anında sonlandırır ve döngüden çıkar.
	Bu, döngü koşulu doğru olsa bile, döngüyü sonlandırabilir. Örneğin:

		for (int i = 0; i < 10; i++) {
		  if (i == 5) {
			break;
		 }
		  std::cout << i << std::endl;
		}

	Bu kod, 0'dan 4'e kadar olan sayıları ekrana yazdırır ve döngü i == 5 olduğunda sona erer.

	continue ifadesi: Bu ifade, bir döngü içinde bulunduğu anda, döngünün geri kalanını atlar ve döngü koşulunun yeniden kontrol edilmesini sağlar.
	Yani, döngü koşulu doğru olsa bile, döngünün bir sonraki adımına atlar. Örneğin:

			for (int i = 0; i < 10; i++) {
			 if (i == 5) {
				continue;
			 }
			 std::cout << i << std::endl;
			}

	Bu kod, 0'dan 9'a kadar olan sayıları ekrana yazdırır, ancak 5'i atlar.

	break ve continue ifadeleri, döngülerin içinde kullanıldıklarında çok faydalı olabilirler ve programın akışını kontrol etmek için kullanılabilirler.
	Ancak, kötü kullanıldıklarında, programda hatalara neden olabilirler. Bu nedenle, bunları dikkatli bir şekilde kullanmak önemlidir.



	*/


	// FONKSİYONLAR VE METODLAR 
	/*
	Fonksiyonlar, bir işi yapmak için kullanılan programlama yapılarıdır.
	İşlevler, bir veya daha fazla ifadeden oluşan ve adlandırılmış bir kod bloğudur. Fonksiyonlar, bölümlere ayrılmış programlama yaklaşımı ile ilgilidir ve daha büyük bir programda tekrar kullanılabilen kod bloklarını oluşturmanın harika bir yoludur. C++ dilinde, fonksiyonların aşağıdaki alt başlıkları vardır:

	Fonksiyon tanımlama: Fonksiyonu tanımlayan, veri türü ve adı belirtilen ve kod bloğu içeren ifadedir.

	Fonksiyon çağrısı: Fonksiyonun kod bloğunun çalıştırılması ve geri dönüş değerinin alınması için çağrıldığı yer.

	Geri dönüş değeri: Fonksiyonlardan bir değer döndürmek için kullanılır. Geri dönen değerin veri türü, fonksiyon tanımlanırken belirtilir.

	Parametreler: Fonksiyonlara girdi sağlamak için kullanılan değişkenlerdir. Bir fonksiyonu çağırırken parametreler belirtilir ve fonksiyon içinde kullanılır.
	*/

	// metodlar 
	/*
Metodlar, nesne tabanlı programlama yaklaşımında kullanılan işlevlerdir. 
Metodlar, bir sınıfın üye işlevleridir ve bir nesne üzerinde çalışır. Bu işlevler, bir nesne üzerinde yürütülecek işlemleri tanımlar ve bu nesnelerin türüne özgüdür. C++ dilinde, metodların aşağıdaki alt başlıkları vardır:

Metod tanımlama: Sınıfın bir üye işlevi olarak tanımlanır ve sınıfın içinde kod bloğu bulunur.
Metod çağrısı: Bir nesne üzerinde bir metodu çağırmak için kullanılır.
Sınıf üyesi: Bir sınıfın üyesi olarak tanımlanır ve bu nedenle bir nesne tarafından kullanılabilir.
Erişim belirleyicileri: Bir metodun erişilebilirliğini belirler. C++ dilinde, üç erişim belirleyicisi vardır:
public, private ve protected
*/

// Fonksiyon tanımlama 

/* 
	 Fonksiyonlar genelde dört bölümden oluşur: 

	 fonksiyon adı : çağırmak için

	 parametreler : fonksiyonun işlevini yerine getirmesi için gereklidir.

	 fonksiyon gövdesi : fonksiyonun içinde ki kod bloğudur. fonkiyonun işlevi burda tanımlanır. 

	 fonksiyonun dönüş değeri : fonksiyonun işlevinin tamamlandıktan sonra geri döndüğü yerdir 
	

	örnek gösterecek olursak şu şekilde olabilir.

	donus_tipi fonksiyon_adi(parametreler){ -> parametre yoksa sadece ' () ' kullanılır
	//fonksiyon gövdesi
	return deger; -> eğer fonksiyonun dönüş değeri varsa yoksa void kullanılır
	}


*/

//fonksiyon örneği
/*
#include <iostream>

int topla(int sayi1, int sayi2) {
	int toplam = sayi1 + sayi2;
	return toplam;
}

int main() {
	int x = 5;
	int y = 10;
	int z = topla(x, y);
	std::cout << "Toplam: " << z << std::endl;
	return 0;
}
*/





// toplu bir fonksiyon örneği
/*
#include <iostream>
#include <string>
using namespace std;

// Toplama Fonksiyonu
int topla(int sayi1, int sayi2) {
	int sonuc = sayi1 + sayi2;
	return sonuc;
}

// Faktöriyel Fonksiyonu
int faktoriyel(int sayi) {
	int sonuc = 1;
	for (int i = 1; i <= sayi; i++) {
		sonuc *= i;
	}
	return sonuc;
}

// String Uzunluğu Fonksiyonu
int stringUzunlugu(string kelime) {
	int uzunluk = 0;
	while (kelime[uzunluk] != '\0') {
		uzunluk++;
	}
	return uzunluk;
}

int main() {
	// Toplama Fonksiyonu Kullanımı
	int sayi1 = 5;
	int sayi2 = 7;
	int toplam = topla(sayi1, sayi2);
	cout << "Toplam: " << toplam << endl;

	// Faktöriyel Fonksiyonu Kullanımı
	int sayi = 6;
	int fakt = faktoriyel(sayi);
	cout << sayi << "!'nin Faktöriyeli: " << fakt << endl;

	// String Uzunluğu Fonksiyonu Kullanımı
	string kelime = "Merhaba Dunya";
	int uzunluk = stringUzunlugu(kelime);
	cout << "Kelimenin Uzunlugu: " << uzunluk << endl;

	return 0;
}

*/	




// fonksiyon da önemli olan kısımlar
/*


Fonksiyonlar, değişkenler gibi bir türdür ve prototip, tanımlama ve çağrılma gibi özelliklere sahiptir.

Fonksiyonlar, bir veya daha fazla parametre alabilir ve bu parametreler, fonksiyon içinde yerel değişkenler gibi kullanılabilir.

Fonksiyonlar, bir değer döndürebilirler veya döndürmeyebilirler.Eğer bir değer döndürülüyorsa, fonksiyonun türü, döndürülen değerin türüyle aynı olmalıdır.

Fonksiyonlar, başka fonksiyonlar içinde tanımlanabilirler ve bu şekilde fonksiyonların hiyerarşik bir yapı oluşturması mümkündür.

Fonksiyonlar, kod tekrarını azaltmak, programın okunabilirliğini artırmak ve kodun modüler olmasını sağlamak gibi avantajlar sağlar.

Fonksiyonlar, birbirinden bağımsız olarak test edilebilirler ve bu şekilde programın hata ayıklama süreci kolaylaştırılabilir.

C++ dilinde, bir fonksiyonun aynı isimde başka bir fonksiyonla aşırı yüklenmesi(overloading) mümkündür.Bu şekilde, aynı isimde farklı parametreler alan farklı fonksiyonlar tanımlanabilir.

Bu noktalar, C++ dilinde fonksiyonların önemini ve kullanımını vurgulamaktadır.

*/






	// Örnekler //

	/* 1
	#include<iostream>
	using namespace std;
	int main()
	{
		setlocale(LC_ALL, "Turkish");

		int x, y, toplam;
		std::cout << "Sayı gir : "; std::cin >> x;
		std::cout << "Sayı gir : "; std::cin >> y;

		toplam = x + y;

		std::cout << "Sonuç= " << toplam << endl;

		return 0;
	}
	*/



	/* 2
#include<iostream>

int main()
{
	int sayi1;
	int sayi2;
	int toplam;

	sayi1 = 5;
	sayi2 = 10;

	toplam = sayi1 + sayi2;

	std::cout << "sayi 1 = " << sayi1 << std::endl;
	std::cout << "sayi 2 = " << sayi2 << std::endl;
	std::cout << "Toplam =" << toplam << std::endl;

	return 0;
}

	 Bu örnekte iki tane int değişkeni tanımladık ve bu değişkenlere değer atadık.
	 Sonra, iki sayıyı toplayarak toplam değişkenine atadık
	 En sonunda, bu değişkenlerin değerlerini ekrana yazdık.

*/


// sayıların karesini alma yöntem 1
	/*3

#include<iostream>
#include<cmath>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Turkish");

	int a, b, karesi, karesi2;

	cout << "sayı gir : "; cin >> a;
	cout << "sayı gir : "; cin >> b;
	karesi = a * a;
	karesi2 = b * b;
	cout << "birinci sayının karesi = " << karesi << endl;
	cout << "ikinci sayının karesi = " << karesi2 << endl;

	return 0;
}
*/



//girilen sayıların karesini alan uygulam 2. yöntem pow fonksiyonu ile
	/*4

#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	setlocale(LC_ALL, "Turkish");
	int x, y, karesi, karesi2 ;

	cout << "ekrana sayı giriniz : ";
	cin >> x;
	karesi = pow(x, 2);
	cout << "girilen 1.sayının karesi =" << karesi << endl;

	cout << "ekrana sayı giriniz veya programı kapatınız : ";
	cin >> y;
	karesi2 = pow(y, 2);
	cout << "girilen 2.sayının karesi =" << karesi2<< endl;
	return 0;
}
*/



//girilen sayının tek mi çift mi olduüunu gösteren uygulama 
	/* 5


#include<iostream>
using namespace std;
int main()
{
	setlocale(LC_ALL, "Turkish");
	int x, i;
	cout << "sayı giriniz : "; cin >> x;
	if ( x % 2 == 0)
	{
		cout << "girilen sayı çifttir ";
	}
	else(x == 0);
	{
		cout << "girilen sayı sıfırdır ne pozitif ne negatif ";
	}
	return 0;
}*/



//hipotenüs hesabı yapan uygulama
	/* 6

#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	setlocale(LC_ALL, "Turkish");
	float a, b, c, hipo;
	cout << "kenar değeri giriniz : "; cin >> a;
	cout << "2.kenar değerini giriniz :";  cin >> b;
	c = pow(a, 2) + pow(b, 2);
	hipo = sqrt(c);
	cout << "verilen değerlere göre hipotenüs uzunluğu = " << hipo << endl;

	return 0;

}
*/


// vize final notu hesaplayan uygulama
	/* 7

#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	setlocale(LC_ALL, "Turkish");
	double vize, final, ödev, sonuc;
	cout << "vize notu giriniz :"; cin >> vize;
	cout << "ödev notu giriniz :"; cin >> ödev;
	cout << "final notu giriniz :"; cin >> final;
	sonuc = (vize * 0.4) + (ödev * 0.1) + (final * 0.5);
	if(sonuc > 36)
	{
		cout << "tebrikler dersi geçtiniz ders notunuz = " << sonuc;
	}
	else
	{
		cout << "kaldınız notunuz = " << sonuc;
	}
	return 0;
}
*/


// iki sayının ortalamasını alan uygulama
	/*	8

#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	setlocale(LC_ALL, "Turkish");
	double x, y, sonuc;
	cout << " sayı giriniz :"; cin >> x;
	cout << " sayı giriniz :"; cin >> y;
	sonuc = (x + y) / 2;
	cout << "girilen sayıların ortalaması = " << sonuc;
	return 0;
}
*/


// 0 DAN 100E KADAR ÇİFT SAYILAR
	/*
#include<iostream>
using namespace std;
int main()
{
	setlocale(LC_ALL, "Turkish"); //burası türkçe karakter kullanımını sağlar
	int  a = 0;

	cout << "SAYILAR \n";
	for (a; a <= 100; a = a + 2)
	{
		cout << "\n" << a;
	}
	cout << "\n";

	return 0;
}
*/


//for döngüsü ile isim yazdırma
	/*/
#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Turkish"); //burası türkçe karakter kullanımını sağlar
	int i = 0;
	for (int i = 0; i < 5; i++)
	{
		cout << " Python çok kolaydır, c++ zor. \n";
	}
}*/

// 0 dan 5 e kadar sayıların toplamı
	/*
#include<iostream>
using namespace std;
int main()
{
	setlocale(LC_ALL, "Turkish"); //burası türkçe karakter kullanımını sağlar
	int i, toplam = 0;
	 for (i = 0; i < 5; i++)
	{
		toplam = toplam + i;
	}
	cout << "toplam" << toplam;

}*/

// 1 DEN 15 E KADAR tek SAYILARIN TOPLAMI
	/*

#include<iostream>
using namespace std;
int main()
{
	setlocale(LC_ALL, "Turkish"); //burası türkçe karakter kullanımını sağlar
	int b = 0, a = 1;

	cout << "sayı döngüsü \n";
	for (a; a <= 15; a = a + 2)
	{
		b = b + a;
		cout << "\n" << a;
	}
	cout << "\n";
	cout << "toplam :" << b;


}*/


//ALFABE GÖSTERİMİ
	/*
#include<iostream>
using namespace std;
int main()
{
	setlocale(LC_ALL, "Turkish"); //burası türkçe karakter kullanımını sağlar
	char s;
	for (char s = 'A'; s <= 'Z'; s++)
	{
		cout << s << " ";
	}

	return 0;

}
*/


// FAKTÖRİYEL HESAPLARI FOR
	/*
#include<iostream>
using namespace std;
int main()
{
	int faktöriyel = 1, f, i;
	cout << "bir sayi giriniz :"; cin >> f;
	for (int i = 1; i <= f; i++)
	{
		faktöriyel *= i;
	}
	cout << f << "! :" << faktöriyel;
}
*/



//FAKTÖRİYEL HESAPLARI WHİLE
	/*
#include<iostream>
using namespace std;
int main()
{
	int faktöriyel = 1, n;
	cout << "sayi girin :"; cin >> n;
	int i = n;
	while (i>= 1)
	{
		faktöriyel = faktöriyel * i;

			i = i - 1;
	}
	cout << n << "!=" << faktöriyel;

	return 0;
}
*/


//while döngüsü ile iki sayıyı aynı anda kontrol etme
	/*
#include<iostream>
using namespace std;
int main()
{
	int i = 1, j = 1;
	while (i < 10 && j < 5)
	{
		cout << "i=" << i << " j=" << j << endl;
		j++;
		i++;
	}
	return 0;
}
*/



//break yapısını kullanarak döngü oluşturma
	/*

#include<iostream>
using namespace std;
int main()
{
	setlocale(LC_ALL, "Turkish");
	int a;
	do
	{
		cout << "sayı girin:"; cin >> a;
		if (a == 0)break;
		cout << "karesi=" << a * a << endl;
	} while (a != 0);
	{
		cout << "0 veya yanlış bir ifade girdiniz. Döngü sona erdi.";
	}
}
*/




//C++ Girilen sayının 3′ e ve 5′ e tam bölünüp bülünmediğini gösteren C++ kodları :
	/*

#include <iostream>
using namespace std;
int main()
{
	setlocale(LC_ALL, "Turkish"); //Türkçe karakter
	int sayi;
	cout << "Sayıyı Girin : ";
	cin >> sayi;
	if (sayi % 3 == 0 && sayi % 5 == 0)
	{
		cout << "Girilen sayı 3' e ve 5'e tam bölünüyor.";
	}
	else
	{
		cout << "Girilen sayı 3' e ve 5'e tam bölünmüyor.";
	}
}
*/


//C++ Kullanıcının girdiği sayı 0-100 arasındaysa geçerli, 0-100 arasında değilse Geçersiz sayı yazdıran C++ Kodları .
	/*
#include <iostream>
using namespace std;
int main()
{
	setlocale(LC_ALL, "Turkish"); //Türkçe karakter
	int sayi;
	cout << "Sayıyı Girin : ";
	cin >> sayi;
	if (sayi % 3 >= 0 && sayi <= 100)
	{
		cout << "Geçerli sayı";
	}
	else
	{
		cout << "Geçersiz sayı.";
	}
}
*/



//1 ile Kullanıcının girdiği sayıya kadar olan sayılar içerisinde bulunan asal sayıları listeleyen C++ Kodları :
//Girilen sayının asal mı ? Asal değil mi ? bulan C++ Kodları :
	/*
#include<iostream>

	using namespace std;

int main()
{
	int sayi;
	int sayac = 0;
	cout << "BIR SAYI GIRINIZ:";

	cin >> sayi;
	if (sayi <= 1) {
		cout << "ASAL DEGILDIR." << endl;
	}
	else {
		for (int j = 2; j < sayi; j++)
		{
			if (sayi % j == 0)
			{
				sayac++;
				break;
			}
		}
		if (sayac == 0)
		{
			cout << "ASALDIR." << endl;
		}
		else
			cout << "ASAL DEGILDIR." << endl;
	}

}

*/


//0 - 100 arası girilen puanı 0 - 5 arası nota çeviren C++ Kodları :
	/*
#include <iostream>
using namespace std;
int main()
{
	setlocale(LC_ALL, "Turkish"); //Türkçe karakter
	int puan;
	cout << "Puanı Girin : ";
	cin >> puan;
	if (puan > 100)
	{
		cout << "Geçersiz.";
	}
	else if (puan > 84)
	{
		cout << "5";
	}
	else if (puan > 69)
	{
		cout << "4";
	}
	else if (puan > 59)
	{
		cout << "3";
	}
	else if (puan > 49)
	{
		cout << "2";
	}
	else if (puan >= 0)
	{
		cout << "1";
	}
	else
	{
		cout << "Geçersiz.";

}
*/


//C++ Kodları :  Klavyeden girilen fiyat değerine % 18 kdv ekleyip kdvli fiyatını bulan ve ekrana yazan program :
	/*

#include <iostream>

using namespace std;
int main()
{
	float fiyat, kdv_fiyat;
	cout << "Fiyati Girin : ";
	cin >> fiyat;
	kdv_fiyat = fiyat + (fiyat * 18 / 100); //kdv_fiyat=fiyat*1,18;
	cout << "KDV' li Fiyat : " << kdv_fiyat;
}

*/



//Klavyeden girilen sayıya kadar olan sayılar içinde tek olanları yazdıran C++ kodları:
	/*
#include <iostream>
using namespace std;
int main()
{
	setlocale(LC_ALL, "Turkish"); //Türkçe karakter
	for (int i = 1; i <= 100; i++)
	{
		if (i % 2 != 0)
		{
			cout << i << endl;
		}

	}
}

*/



//Doğru şifre girilene kadar şifre isteyen algoritma
	/*
#include<iostream>
using namespace std;
int main()
{
setlocale(LC_ALL, "Turkish"); //burası türkçe karakter kullanımını sağlar

string sifre = "1234";
string input;
	do
	{
	cout << "parolayı gir:";
	cin >> input;
	}
	while (input != sifre);
	{
	cout<<"parolayı doğru girdiniz.";
	}

return 0;

}
*/


//FİBONACCİ DİZİSİ TERİMLERİ
   /*

#include<iostream>
using namespace std;
int main()
{
	setlocale(LC_ALL, "Turkish"); //burası türkçe karakter kullanımını sağlar
	int n, c, ilk = 0, ikinci = 1, sonraki;

	cout << "Fibonacci dizisinde kac terim  olacagini girin" << endl;
	cin >> n;

	cout << " İlk " << n << " fibonacci dizisi terimleri : " << endl;

	for (int c = 0; c < n; c++)
	{
		if (c <= 1)
			sonraki = c;
		else
		{
			sonraki = ilk + ikinci;
			ilk = ikinci;
			ikinci = sonraki;
		}
		cout << sonraki << endl;
	}
return 0;
}
	*/


	// NOT DEĞERLENDİRMESİ DENEMEESİ
	 /*
   #include <iostream>
	using namespace std;

	int main() {
		setlocale(LC_ALL, "Turkish"); //burası türkçe karakter kullanımını sağlar

		int num;


		cout << "Numara giriniz: ";
		cin >> num;

		if (num > 100)
		{
			cout << " Geçersiz not girdiniz " << "\n";
		}
		if (num > 85 && num <= 100 ) {
			cout << "Tebrikler, aldığınız not A!" << endl;
		}
		else if (num >= 70 && num <= 84) {
			cout << "Tebrikler, aldığınız not B." << endl;
		}
		else if (num >= 60 && num <= 69) {
			cout << "Tebrikler, aldığınız not C." << endl;
		}
		else if (num >= 40 && num <= 59) {
			cout << "Tebrikler, aldığınız not D." << endl;
		}
		else if ( num < 40 )
		{
			cout << "Üzgünüm, kaldınız" << endl;
		}


		return 0;
	}
	*/



	//üçgen alanı hesaplama programı
		/*

	   #include <iostream>
	   using namespace std;
	   int main()
	   {
		   setlocale(LC_ALL, "Turkish");
		   system("cls");
		   float h, a, alan;
		   cout << "Üçgenin taban değerini giriniz : "; cin >> a;
		   cout << "Üçgenin yükseklik değerini giriniz : "; cin >> h;
		   alan = (a * h) / 2;
		   cout << "Girilen değerlere göre üçgenin alanı : " << alan << endl;
		   return 0;
	   }*/


	   // iki kenar ve aradaki açısı girilen üçgenin alanını hesaplama
		/*

	   #include <iostream>
	   #include <cmath>
	   using namespace std;
	   int main()
	   {
		   setlocale(LC_ALL, "Turkish");
		   float aci, ken1, ken2, alan;
		   cout << "birinci kenarı giriniz : "; cin >> ken1;
		   cout << "ikinci kenarı giriniz : "; cin >> ken2;
		   cout << "açıyı giriniz :"; cin >> aci;

		   alan = ken1 * ken2 * sin(M_PI*aci/180) / 2;
		   cout << "verilen değerlere göre üçgenin alanı : " << alan << endl;
		   return 0;
	   }*/


	   //0 dan girilen sayıya kadar sayıların toplamını hesaplayan program
		/*
	   #include <iostream>
	   using namespace std;
	   int main()
	   {
		   setlocale(LC_ALL, "Turkish");
		   int N;
		   float t = 0;
		   cout << "üst sınırı giriniz : "; cin >> N;
		   for (int i = 0; i <= N; i++) t += i;
		   {
			   cout << "\n sonuc= " << t << endl;
		   }
		   return 0;
	   }
	   */




	   // girilen iki sayıdan küçük olanı ekrana yazdıran kod
	   /*
	   #include <iostream>
	   using namespace std;

	   int main() {
		   int sayi1, sayi2;
		   cout << "Lutfen iki sayi giriniz: ";
		   cin >> sayi1 >> sayi2;

		   if (sayi1 < sayi2) {
			   cout << sayi1 << " daha kucuktur." << endl;
		   }
		   else {
			   cout << sayi2 << " daha kucuktur." << endl;
		   }

		   return 0;
	   }
	   */




	   //FAKTÖRİYEL
		   /*#include<iostream>
		  using namespace std;
		  int main()
		  {
			  setlocale(LC_ALL, "Turkish");
			  int faktöriyel = 1, f;
			  cout << "Faktöriyeli alınacak sayıyı giriniz :"; cin >> f;
			  for (int i = 1; i <= f; i++)
			  {
				  faktöriyel *= i;
			  }
			  cout << f << "!=" << faktöriyel << endl;
			  system("pause"); return 0;
		  }*/


		  //tavan sayısı girilsin kendisine kadar olan sayıların karesini alsın
			  /*

			 #include<iostream>
			 #include<cmath>
			 using namespace std;
			 int main()
			 {
				 setlocale(LC_ALL, "Turkish");
				 int  x, y, kare = 0;
				 cout << "Tavan sayısı giriniz :"; cin >> y;
				 for (int x = 1; x <= y; x++)
				 {
					 kare = x * x;
					 cout << x << " sayısının karesi =" << kare << endl;
				 }
				 system("pause");
				 return 0;
			 }*/


			 //1den 10 a kadar sayıların toplamı
				 /*

				#include<iostream>
				using namespace std;
				int main()
				{
					setlocale(LC_ALL, "Turkish");
					int i = 1;
						int toplam = 0;
						while (i<=10)
						{
							toplam += i;
							i++;
						}
						cout << "Toplamların sonucu :" << toplam << endl;
						system("pause");
						return 0;
				}*/


				//FAKTÖRİYEL
					/*
				   #include<iostream>
				   using namespace std;
				   int main()
				   {
					   setlocale(LC_ALL, "Turkish");
					   int faktöriyel=1, f;
					   cout << "Sayı giriniz :"; cin >> f;
					   int i = f;
					   while (i >= 1)
					   {
						   faktöriyel = faktöriyel * i;
						   i = i - 1;
					   }
					   cout << f << "!=" <<  faktöriyel << endl;
					   system("pause");
					   return 0;
				   }
				   */


				   // 1 İLE 100 ARASINDA Kİ TEK SAYILARIN TOPLAMI 
					   /*
					  #include <iostream>
					  using namespace std;
					  int main()
					  {
						  setlocale(LC_ALL, "Turkish");
						  int i = 1;
						  int toplam = 0;
						  while (i <= 100) {
							  if (i % 2 == 1) {
								  cout << i << " ";
								  toplam += i;
							  }
							  i++;
						  }
						  cout << endl;
						  cout << "1 ile 100 arasındaki tek sayıların toplamı: " << toplam << endl;
						  return 0;
					  }
					  */


					  // Hesap Makinesi 
						  /*
					  #include<iostream>
					  #include<cmath>
					  using namespace std;
					  int main()
					  {
						  setlocale(LC_ALL, "Turkish");
						  float x, y, sonuç;
						  char islem;
						  std::cout << "Lütfen ekrana sayı giriniz :"; std::cin >> x;
						  std::cout << "Lütfen ekrana işlem yapmak istediğiniz ikinci sayıyı giriniz :"; std::cin >> y;
						  std::cout << "Hangi işlemi yapmak istiyorsunuz ( *  , / , + , - )  : "; std::cin >> islem;

						  switch (islem) {
						  case '+':
							  sonuç = x + y;
							  break;
						  case '-':
							  sonuç = x - y;
							  break;
						  case '*':
							  sonuç = x * y;
							  break;
						  case '/':
							  sonuç = x / y;
							  break;
						  default:
							  cout << "Geçersiz işlem seçildi." << endl;
							  return 1;
						  }
						  std::cout << "Sonuç = " << sonuç << endl;
						  system("pause");
						  return 0;

					  }
						  */



						  // Not sistemi

						  /*
						  #include <iostream>

						  using namespace std;

						  int main()
						  {
							  float not;

							  cout << "Notunuzu giriniz (0-100 aralığında): ";
							  cin >> not;

							  if (not >= 90) {
								  cout << "Notunuz: AA" << endl;
							  }
							  else if (not >= 85) {
								  cout << "Notunuz: BA" << endl;
							  }
							  else if (not >= 80) {
								  cout << "Notunuz: BB" << endl;
							  }
							  else if (not >= 75) {
								  cout << "Notunuz: CB" << endl;
							  }
							  else if (not >= 70) {
								  cout << "Notunuz: CC" << endl;
							  }
							  else if (not >= 65) {
								  cout << "Notunuz: DC" << endl;
							  }
							  else if (not >= 60) {
								  cout << "Notunuz: DD" << endl;
							  }
							  else if (not >= 55) {
								  cout << "Notunuz: FD" << endl;
							  }
							  else {
								  cout << "Notunuz: FF" << endl;
							  }

							  return 0;
						  }

						  */




// fonksiyonlar toplama fonksiyonu
/*
#include <iostream>
using namespace std;

int topla(int sayi1, int sayi2) {
	int sonuc = sayi1 + sayi2;
	return sonuc;
}

int main() {
	int x = 5, y = 7;
	int toplam = topla(x, y);
	cout << "Toplam: " << toplam << endl;
	return 0;
}
*/



// faktöriyel fonksiyonu 
/*
#include <iostream>
using namespace std;

int faktoriyel(int sayi) {
	int sonuc = 1;
	for (int i = 1; i <= sayi; i++) {
		sonuc *= i;
	}
	return sonuc;
}

int main() {
	int n;
	cout << "Faktoriyeli hesaplanacak sayiyi girin: ";
	cin >> n;
	int f = faktoriyel(n);
	cout << n << "! = " << f << endl;
	return 0;
}
*/


//kelime uzunluğu fonksiyonu
/*
#include <iostream>
using namespace std;

int stringUzunlugu(string kelime) {
	int uzunluk = 0;
	while (kelime[uzunluk] != '\0') {
		uzunluk++;
	}
	return uzunluk;
}

int main() {
	string s = "Merhaba dunya";
	int uzunluk = stringUzunlugu(s);
	cout << "Kelime uzunlugu: " << uzunluk << endl;
	return 0;
}
*/
