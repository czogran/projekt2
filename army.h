#pragma once

#include<iostream>
#include<cstdlib>
#include <string>
#include <vector>

using namespace std;


#include "divpanc.h"
#include "piechota.h"
#include "propaganda.h"
//#include "ot.h"
//class Ot;


class Armia
{
protected:
	//Piechota *piechota;
	vector <Piechota> piechota;
	//Piechota pp;
	//Divpanc *pancerne;
	vector <Divpanc> pancerne;
	//Divpanc pan;
	Propaganda p1;
	int ile_panc;
	int ile_piechota;
	static int nr_armi;
	int nr_tej;
	string wodz;
public:
	Armia(int c, int p);//(int c = 0, int p = 0);
	Armia(int c, int p, string w);
	Armia() 
	{
		nr_armi++;
		ile_panc = 1;
		ile_piechota = 1;
	}
	~Armia();
	Armia(const Armia&a);					// konstrukor kopiujacy, operator przypisania jest te� dla Divapanc i Piechota
	

	void propa(int wyg_bit, int jency, string jen_gen);
	void zwprop(int nit, int jen, string gen);
	int ile_armii() { return nr_armi; };
	
	int suma_piech();
	int suma_dzial();
	int suma_czol();
	void zmien_panc(int nr, int c, int lu);
	
	virtual void a()
	{
		cout << "armia" << endl;
	}
	virtual Armia & operator+(const int b);								//1 
//	virtual friend ostream& operator<< (ostream&, Armia const& );		//2
	virtual Armia  &operator()(int wyg_bit, int jency, string jen_gen);					//3a
	virtual Armia  &operator()( string gen,int bit, int jen);					//3b
	virtual Armia &operator=(const Armia &aa);							//4
	void  operator[](string gen);								//5
	void operator[](int a);										//6
	virtual bool operator ==(const Armia& a) const;						//7
	bool operator < (const Armia& a)const;						//8
	bool operator > ( Armia& a);
	void operator &&(const Armia&a);							//9
	inline operator float()const { return p1.jency *1.0f / p1.wygrane_bitwy; } //10
	
};