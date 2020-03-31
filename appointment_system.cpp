#include "pch.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;


class ogrenci {
public:
	void setOgrPk(string tl,string ky,string ono, string nm, string ln, string bl, string ml);
    
	fstream dosya;

	ogrenci() {
		dosya.open("ogrenci.txt", ios::in | ios::out | ios::app);
	};

	static int ogrcounter;
	bool OgrBul(string ono);
	void OgrEkle();
private:
	
	
	string  tel, kayýtYýlý, okulno, ad, soyad, bolum, mail;
};

class akademisyen {
public:	
	void setAkPk(string sno, string a, string s, string f, string m, string tl, string unv);
	
	fstream dosya;
	akademisyen() {
		dosya.open("akademisyen.txt", ios::in | ios::out | ios::app);
	};

	void AkEkle();
	bool AkBul(string sno);
	static int aksayisi;



private:
	string tel, sicilno, ad, soyad, mail, alan, unvan;
};

class randevu{
public:
	void setDate(string ono, string sno, string dt, string sh, string fh);
	fstream dosya;
	randevu() {
		dosya.open("randevu.txt", ios::in | ios::out | ios::app);
	}
	void RandevuEkle();
	bool RandevuBul(string okulno,string sicilno, string dt, string sh, string fh);
	void RandevuListele();
	void RandevuSil();
private:
	string okulno,sicilno,date, shour, fhour;
	//ogrenci okulno;compositionla yapýlabilir
};

class randevusistemi : public ogrenci , public akademisyen,public randevu{
public:
	void RandevuMenusu();
private:
	ogrenci o[100];
	akademisyen a[100];
	randevu r[100];
};
 


int main()
{
	randevusistemi rs;
	rs.RandevuMenusu();
}

int ogrenci::ogrcounter = 0;
int akademisyen::aksayisi = 0;

void ogrenci::setOgrPk(string tl,string ky,string ono, string nm, string ln, string bl, string ml) {
	tel = tl;
	kayýtYýlý = ky;
	okulno = ono;
	ad = nm;
	soyad = ln;
	bolum = bl;
	mail = ml;
}


void ogrenci::OgrEkle() {
	ogrenci *hPtr = new ogrenci();
	hPtr = new ogrenci;
	cout.setf(ios::right);
    cout  << "TEL:       " << endl;
	cin >> hPtr->tel;
	cout << "AD SOYAD:  " << endl;
	cin >> hPtr->ad;
	cin >> hPtr->soyad;
	cout << "BOLUM:     " << endl;
	cin >> hPtr->bolum;
	cout << "E-MAIL:    " << endl;
	cin >> hPtr->mail;
	cout << "Kayit Yili:" << endl;
	cin >> hPtr->kayýtYýlý;
	cout << "Okul No:   " << endl;
	cin >> hPtr->okulno;
	//dosya <<ogrcounter<<".Ogrenci Kisisel Bilgileri" << endl;
	dosya << hPtr->tel << " "
     << hPtr->ad << " " << hPtr->soyad << " "
	 << hPtr->bolum <<  " "
     << hPtr->mail <<  " "
     <<hPtr->kayýtYýlý << " "
     <<hPtr->okulno <<endl ;
	hPtr++;
	//dosya.close();
	ogrcounter++;
}

bool ogrenci::OgrBul(string ono) {
	ogrenci obul;
	while (!dosya.eof())
	{
		dosya >> obul.tel;
		dosya >> obul.ad;
		dosya >> obul.soyad;
		dosya >> obul.bolum;
		dosya >> obul.mail;
		dosya >> obul.kayýtYýlý;
		dosya >> obul.okulno;
	
	if (obul.okulno == ono) {
		/*cout << "Ogrenci Kisisel Bilgileri" << endl;
		cout << "TEL       :" << obul.tel << endl;
		cout << "AD SOYAD  :" << obul.ad << " " << obul.soyad << endl;
		cout << "BOLUM     :" << obul.bolum << endl;
		cout << "E-MAIL    :" << obul.mail << endl;
		cout << "Kayýt Yýlý:" << obul.kayýtYýlý << endl;
		cout << "Okul No   :" << obul.okulno << endl;*/
		return true;
	}
	
	}
	
	return false;
}

void akademisyen::setAkPk(string sno, string a, string s, string f, string m, string tl, string unv) {
	sicilno = sno;
	ad = a;
	soyad = s;
	alan = f;
	mail = m;
	tel = tl;
	unvan = unv;
}


void akademisyen:: AkEkle() {
	akademisyen *hPtr = new akademisyen();
	hPtr = new akademisyen;
	cout.setf(ios::right);
	cout << "Sicil No:       " << endl;
	cin >> hPtr->sicilno;
	cout << "AD SOYAD:  " << endl;
	cin >> hPtr->ad;
	cin >> hPtr->soyad;
	cout << "Alan:     " << endl;
	cin >> hPtr->alan;
	cout << "E-MAIL:    " << endl;
	cin >> hPtr->mail;
	cout << "TEL:" << endl;
	cin >> hPtr->tel;
	cout << "Unvan:   " << endl;
	cin >> hPtr->unvan;
	dosya << hPtr->sicilno << " "
		<< hPtr->ad << " " << hPtr->soyad << " "
		<< hPtr->alan << " "
		<< hPtr->mail << " "
		<< hPtr->tel << " "
		<< hPtr->unvan << endl;
	hPtr++;
	//dosya.close();
	aksayisi++;
}

bool akademisyen::AkBul(string sno) {
	akademisyen abul;
	while (!dosya.eof())
	{
		dosya >> abul.sicilno;
		dosya >> abul.ad;
		dosya >> abul.soyad;
		dosya >> abul.alan;
		dosya >> abul.mail;
		dosya >> abul.tel;
		dosya >> abul.unvan;
	
	      if (abul.sicilno == sno) {
		/*cout << "Ogrenci Kisisel Bilgileri" << endl;
		cout << "Sicil No   :" << abul.sicilno << endl;
		cout << "AD SOYAD  :" << abul.ad << " " << abul.soyad << endl;
		cout << "Alan     :" << abul.alan << endl;
		cout << "E-MAIL    :" << abul.mail << endl;
		cout << "TEL       :" << abul.tel << endl;
		cout << "Unvan   :" << abul.unvan << endl;*/
		   return true;
	       }
	      
	}	
	
	 return false;
	
}

void randevu::setDate(string ono, string sno, string dt, string sh, string fh) {
	okulno = ono;
	sicilno = sno;
	date = dt;
	shour = sh;
	fhour = fh;
}

void randevu::RandevuEkle() {
	randevu *hPtr = new randevu();
	hPtr = new randevu;
	ogrenci o;
	akademisyen a;
	string okulno, sicilno;
	cout.setf(ios::right);
	cout << "Randevu icin okul numarasi ve akademisyenin sicil numarasini giriniz:" << endl;
	cin >> okulno;
	cin >> sicilno;
	if (o.OgrBul(okulno) == true && a.AkBul(sicilno) == true) {
		cout << "Randevu gununu, baslangic ve bitis saatini giriniz."<<endl;
		hPtr->okulno = okulno;
		hPtr->sicilno = sicilno;
		cin >> date;
		cin >> shour;
		cin >> fhour;
		hPtr->date = date;
		hPtr->shour = shour;
		hPtr->fhour = fhour;
		if (RandevuBul(okulno, sicilno, date, shour, fhour) == true) {
			dosya << hPtr->okulno << " "
				  << hPtr->sicilno << " "
				  << hPtr->date << " "
				  << hPtr->shour << " "
				  << hPtr->fhour << " " << endl;
		}
	}
	else
		cout << "Sisteme kayitli ogrenci yada akademisyen bulunamadi!" << endl;
	hPtr++;
}

bool randevu::RandevuBul(string okulno,string sicilno, string date, string shour, string fhour) {
	randevu r;
	string dogrulama;
		while (!dosya.eof())
		{
			dosya >> r.okulno;
			dosya >> r.sicilno;
			dosya >> r.date;
			dosya >> r.shour;
			dosya >> r.fhour;

			if (r.okulno == okulno && r.date == date && r.shour == shour && r.fhour == fhour) {
				cout << "Randevu verilemez ogrencinin yazdiginiz saatler arasinda baska randevusu var." << endl;
				return false;
			}


			else if (r.sicilno == okulno && r.date == date && r.shour == shour && r.fhour == fhour) {
				cout << "Randevu verilemez akademisyenin yazdiginiz saatler arasinda baska randevusu var." << endl;
				return false;
			}
		}
		return true;
	
}

void randevu::RandevuListele() {
	randevu r;
	string bul;
	cin >> bul;

	while (!dosya.eof())
	{
		dosya >> r.okulno;
		dosya >> r.sicilno;
		dosya >> r.date;
		dosya >> r.shour;
		dosya >> r.fhour;

		if (r.sicilno == bul || r.okulno == bul) {
			cout << r.okulno << " "
				<< r.sicilno << " "
				<< r.date << " "
				<< r.shour << " "
				<< r.fhour << " " << endl;
		}
		else
			cout << "Girdiginiz kisinin sistemde randevu kaydi bulunmamaktadir." << endl;
	}	

	
}
void randevu::RandevuSil() {
	randevu *hPtr = new randevu();
	hPtr = new randevu();
	delete hPtr;
}
void randevusistemi::RandevuMenusu() {
	int secenek;
	cout << "---------------------------------------------------" << endl;
	cout << "[1]. Ogrenci Ekle" << endl;
	cout << "[2]. Akademisyen Ekle" << endl;
	cout << "[3]. Ogrenci Randevu Listele" << endl;
	cout << "[4]. Akademisyen Randevu Listele" << endl;
	cout << "[5]. Randevu Ekle" << endl;
	cout << "Secmek istediginiz secenegin numarasini yaziniz:";
	cin >> secenek;
	switch (secenek)
	{
	case 1:
		o->OgrEkle();
		return RandevuMenusu();
		break;
	case 2:
		a->AkEkle();
		return RandevuMenusu();
		break;
	case 3:
		cout << "Ogrencinin numarasini giriniz:";
		r->RandevuListele();
		return RandevuMenusu();
		break;
	case 4:
		cout << "Akademisyenin sicil numarasini giriniz:";
		r->RandevuListele();
		return RandevuMenusu();
		break;
	case 5:
		r->RandevuEkle();
		return RandevuMenusu();
		break;
	default :
		break;
	}
}