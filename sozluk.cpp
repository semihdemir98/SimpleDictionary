/*
 * Semih Demir
 * No: 18120205005
 * sozluk.cpp
 * 07.04.2019
 */
#include "sozluk.h"
#include <iostream>
#include <vector>
#include "kayit.h"
#include <fstream>

using namespace std;

Sozluk::Sozluk()
{
	kayitlar=nullptr;
	toplamKayitSayisi=0;
}
Sozluk::Sozluk(const Kayit &kayit)
{
	kayitlar= new Kayit[1];
	if(kayitlar != nullptr)
	{
		kayitlar[0]=kayit;
		toplamKayitSayisi=1;
	}
}
Sozluk::Sozluk(const Sozluk &other)
{
	if(kayitlar != nullptr)
	{
		delete[] kayitlar;
	}
		
	toplamKayitSayisi=other.toplamKayitSayisi;
	kayitlar=new Kayit [toplamKayitSayisi];
	
	if(kayitlar == nullptr)
	{
		exit(-1);
	}
	for(unsigned i=0;i<toplamKayitSayisi;i++)
	{
		kayitlar[i]=other.kayitlar[i];
	}
}

Sozluk::~Sozluk()
{
	if(kayitlar != nullptr)
		delete[] kayitlar; 
}
//ayni kelime var mi diye kontrol edip varsa aciklamalari birlestir
Sozluk::Sozluk(const vector<Kayit> & kayitlar)
{
	this->kayitlar=new Kayit[kayitlar.size()];
	if(this->kayitlar != nullptr)
	{
		for(unsigned i=0;i<kayitlar.size();i++)
			this->kayitlar[i]=kayitlar[i];
	}
}

Kayit& Sozluk::operator[](const string & kelime)
{
	for(unsigned i=0;i<toplamKayitSayisi;i++)
	{
		if(kayitlar[i].getter_Kelime() == kelime)
			return kayitlar[i];
	}
}

Sozluk & Sozluk::operator=(const Sozluk &other)
{
	if(kayitlar != nullptr)
		delete[] kayitlar;
	toplamKayitSayisi=other.toplamKayitSayisi;
	kayitlar=new Kayit[toplamKayitSayisi];
	if(kayitlar == nullptr)
		exit(-1);
	for(unsigned i=0;i<toplamKayitSayisi;i++)
		kayitlar[i]=other.kayitlar[i];
	
	return *this;
	
}
ostream & operator<<(ostream & o, const Sozluk & s)
{
	int toplamAciklama=0;
	o<<"Toplam kayit sayisi:"<<s.toplamKayitSayisi<<endl;
	for(unsigned i=0;i<s.toplamKayitSayisi;i++)
		toplamAciklama=toplamAciklama+s.kayitlar[i].getter_Aciklamasize();
	o<<"Toplam aciklama sayisi:"<<toplamAciklama<<endl;
	return o;
}

ofstream & operator<<(ofstream & out, const Sozluk & s)
{
	for(int i=0; i< s.toplamKayitSayisi; i++)
	{
		out << i+1 << ".Kayit:" << s.kayitlar[i] << endl;
	}
	return out;		
}

ifstream & operator>>(ifstream & in, Sozluk & s)
{
	string aciklama;
	string kelime;
	vector <string> aciklamalar;
	vector <Kayit> temp;
	
	while(in >> kelime)
	{
		aciklamalar.clear();
		while(in >> aciklama)	
		{
			if(aciklama != ".")
				aciklamalar.push_back(aciklama);
			else
				break;
		}
		Kayit a(kelime,aciklamalar);
		temp.push_back(a);
	}
	s.toplamKayitSayisi= temp.size();
	s.kayitlar = new Kayit[s.toplamKayitSayisi];

	for(int i=0; i<s.toplamKayitSayisi; i++)
	{
		s.kayitlar[i] = temp[i];
	}
	return in;
}

bool  Sozluk::operator<(const Sozluk &other)
{
	int toplamAciklama_this=0;
	int toplamAciklama_other=0;
	for(unsigned i=0;i<this->toplamKayitSayisi;i++)
		toplamAciklama_this=toplamAciklama_this+this->kayitlar[i].getter_Aciklamasize();
	for(unsigned i=0;i<other.toplamKayitSayisi;i++)
		toplamAciklama_other=toplamAciklama_other+other.kayitlar[i].getter_Aciklamasize();
	if(toplamAciklama_this > toplamAciklama_other)
		return false;
	return true;
}
bool Sozluk::operator>(const Sozluk &other)
{
	int toplamAciklama_this=0;
	int toplamAciklama_other=0;
	for(unsigned i=0;i<this->toplamKayitSayisi;i++)
		toplamAciklama_this=toplamAciklama_this+this->kayitlar[i].getter_Aciklamasize();
	for(unsigned i=0;i<other.toplamKayitSayisi;i++)
		toplamAciklama_other=toplamAciklama_other+other.kayitlar[i].getter_Aciklamasize();
	if(toplamAciklama_this > toplamAciklama_other)
		return true;
	return false;
}
bool  Sozluk::operator<=(const Sozluk &other)
{
	int toplamAciklama_this=0;
	int toplamAciklama_other=0;
	for(unsigned i=0;i<this->toplamKayitSayisi;i++)
		toplamAciklama_this=toplamAciklama_this+this->kayitlar[i].getter_Aciklamasize();
	for(unsigned i=0;i<other.toplamKayitSayisi;i++)
		toplamAciklama_other=toplamAciklama_other+other.kayitlar[i].getter_Aciklamasize();
	if(toplamAciklama_this >= toplamAciklama_other)
		return false;
	return true;
}
bool  Sozluk::operator>=(const Sozluk &other)
{
	int toplamAciklama_this=0;
	int toplamAciklama_other=0;
	for(unsigned i=0;i<this->toplamKayitSayisi;i++)
		toplamAciklama_this=toplamAciklama_this+this->kayitlar[i].getter_Aciklamasize();
	for(unsigned i=0;i<other.toplamKayitSayisi;i++)
		toplamAciklama_other=toplamAciklama_other+other.kayitlar[i].getter_Aciklamasize();
	if(toplamAciklama_this >= toplamAciklama_other)
		return true;
	return false;
}
bool  Sozluk::operator==(const Sozluk &other)
{
	int toplamAciklama_this=0;
	int toplamAciklama_other=0;
	
	for(unsigned i=0;i<this->toplamKayitSayisi;i++)
		toplamAciklama_this=toplamAciklama_this+this->kayitlar[i].getter_Aciklamasize();
		
	for(unsigned i=0;i<other.toplamKayitSayisi;i++)
		toplamAciklama_other=toplamAciklama_other+other.kayitlar[i].getter_Aciklamasize();
	
	if(toplamAciklama_this == toplamAciklama_other)
		return true;
	return false;
}
bool  Sozluk::operator!=(const Sozluk &other)
{
	int toplamAciklama_this=0;
	int toplamAciklama_other=0;
	for(unsigned i=0;i<this->toplamKayitSayisi;i++)
		toplamAciklama_this=toplamAciklama_this+this->kayitlar[i].getter_Aciklamasize();
	for(unsigned i=0;i<other.toplamKayitSayisi;i++)
		toplamAciklama_other=toplamAciklama_other+other.kayitlar[i].getter_Aciklamasize();
	if(toplamAciklama_this != toplamAciklama_other)
		return true;
	return false;
}

Sozluk Sozluk::operator+(const Sozluk & digerSozluk)
{
	
	Sozluk temp;
	temp.toplamKayitSayisi = toplamKayitSayisi + digerSozluk.toplamKayitSayisi;

	temp.kayitlar = new Kayit[temp.toplamKayitSayisi];
	if(temp.kayitlar == nullptr) exit(-1);

	for(int i=0; i<toplamKayitSayisi; i++)
	{
		temp.kayitlar[i] = this->kayitlar[i];
	}

	for(int j=0 ; j< digerSozluk.toplamKayitSayisi ; j++)
	{
		temp.kayitlar[j+toplamKayitSayisi] = digerSozluk.kayitlar[j];
	}
	
	return temp;
}

Sozluk & Sozluk::operator+=(const Sozluk & digerSozluk)
{
	Sozluk temp;
	temp.toplamKayitSayisi=toplamKayitSayisi;
	temp.kayitlar= new Kayit[temp.toplamKayitSayisi];
	if(temp.kayitlar == nullptr) exit(-1);
	for(unsigned i=0;i<temp.toplamKayitSayisi;i++)
		temp.kayitlar[i]=kayitlar[i];
	if(kayitlar != nullptr)
		delete[] kayitlar;
	toplamKayitSayisi=temp.toplamKayitSayisi+digerSozluk.toplamKayitSayisi;
	kayitlar=new Kayit[toplamKayitSayisi];
	if(kayitlar == nullptr)	exit(-1);
	for(int i=0; i<temp.toplamKayitSayisi; i++)
	{
		kayitlar[i]=temp.kayitlar[i];
	}
	for(int j=0 ; j< digerSozluk.toplamKayitSayisi ; j++)
	{
		kayitlar[j+temp.toplamKayitSayisi] = digerSozluk.kayitlar[j];
	}

	return *this;
}

Sozluk & Sozluk::operator-=(const Kayit & kayit)
{
	for(int i=0; i<toplamKayitSayisi; i++)
	{
		if(kayit.getter_Kelime() == kayitlar[i].getter_Kelime())
		{
			kayitlar[i].silici();
		}
	}
	return *this;
}

Sozluk & Sozluk::operator-=(const string & kelime)
{
	for(int i=0; i<toplamKayitSayisi; i++)
	{
		if(kayitlar[i].getter_Kelime() == kelime)
		{
			kayitlar[i].silici();
		}
	}
	return *this;
}





