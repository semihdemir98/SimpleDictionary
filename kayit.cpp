/*
 * Semih Demir
 * No: 18120205005
 * kayit.cpp
 * 07.04.2019
 */

#include "kayit.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;
int Kayit::getter_Aciklamasize()
{
	return aciklama.size();
}
string Kayit::getter_Kelime()const
{
	return kelime;
}

void Kayit::silici()
{
	aciklama.clear();
}

//verilen kelimenin aciklamasi tek kelime ise true , degilse false dondurur
bool es_Anlam(vector<string>aciklama)
{
	bool control=true;
	for(unsigned i=0;i<aciklama.size();i++)
	{
		for(unsigned j=0;j<aciklama[i].size();j++)
		{
			if(aciklama[i][j] == ' ')
				control=false;
		}
	}
	return control;
}

//verilen aciklama kaydin aciklamalarinda varsa true , yoksa false dondurur
bool control(const string &str,vector<string>aciklama)
{
	bool control1=false;
	for(unsigned i=0;i<aciklama.size();i++)
		if(aciklama[i] == str)
			control1=true;
	return control1;
}


Kayit::Kayit(const string & kelime,const string & aciklama)
{
	this->kelime=kelime;
	this->aciklama.push_back(aciklama);
}

Kayit::Kayit(const string & kelime, const vector<string> & aciklamalar)
{
	this->kelime=kelime;
	this->aciklama=aciklamalar;
}

ostream& operator<<(ostream& outStream, const Kayit& kayit)
{
	outStream<<"Kelime: "<<kayit.kelime<<endl;
	for(unsigned i=0;i<kayit.aciklama.size();i++)
		outStream<<i+1<<".Aciklama: "<<kayit.aciklama[i]<<endl;
	return outStream;
}

istream &operator>>(istream &inStream, Kayit &kayit)
{
	cout<<"Kelime:";
	getline(inStream,kayit.kelime);
	string temp;
	kayit.aciklama.clear();
	int i=0;
	while(true)
	{
		cout<<++i<<".Aciklama:";
		getline(inStream,temp);
		if(temp == "")
			break;
		kayit.aciklama.push_back(temp);
	}
	return inStream;
}

bool Kayit::operator!()
{
	if(kelime == "" || aciklama.size() == 0)
		return true;
	return false;
}

const Kayit & Kayit::operator -(const string & aciklama)
{
	for(unsigned i=0;i<this->aciklama.size();i++)
	{
		if(this->aciklama[i] == aciklama)
			this->aciklama.erase(this->aciklama.begin()+i);
	}
	return *this;
}

const Kayit & Kayit::operator+(const Kayit &digerKayit)
{
	if(kelime == digerKayit.kelime)
	{
		for(unsigned i=0;i<digerKayit.aciklama.size();i++)
			if(!(control(digerKayit.aciklama[i],aciklama)))
				aciklama.push_back(digerKayit.aciklama[i]);
	}
	return *this;
}

const Kayit & Kayit::operator +(const string & aciklama)
{
	bool control=true;
	for(unsigned i=0;i<this->aciklama.size();i++)
	{
		if(this->aciklama[i] == aciklama)
			control=false;
	}
	if(control)
		this->aciklama.push_back(aciklama);
	return *this;
}

bool Kayit::operator==(const string & digerKelime)
{
	if(kelime == digerKelime || es_Anlam(aciklama))
		return true;
	return false;
}

bool Kayit::operator==(const Kayit & digerKayit)
{
	if(kelime == digerKayit.kelime || (es_Anlam(aciklama) && es_Anlam(digerKayit.aciklama)))
		return true;
	return false;
}
