#pragma once

enum class enNucleotide
{
	None = 0,
	Adenine = 1,
	Cytosine = 2,
	Guanine = 3,
	Uracil = 4, // RNA
	Thymine = 5, // DNA
};

class clNucleotide
{
public:
	clNucleotide();
	~clNucleotide();

	const	wchar_t	wcGetSymbol()const;

protected:
	enNucleotide	m_enNucleotide = enNucleotide::None;
			wchar_t	m_wcSymbol;
private:

};

class clAdenine : public clNucleotide
{	
public:
	clAdenine();
	~clAdenine() {}
};

class clCytosine : public clNucleotide
{
public:
	clCytosine();
	~clCytosine() {}
};

class clGuanine : public clNucleotide
{
public:
	clGuanine();
	~clGuanine() {}
};

class clUracil : public clNucleotide
{
public:
	clUracil();
	~clUracil() {}
};