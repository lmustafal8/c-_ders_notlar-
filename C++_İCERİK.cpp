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







