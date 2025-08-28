#include "pch.h"
#include "Nucleotide.h"


clNucleotide::clNucleotide()
{
}

clNucleotide::~clNucleotide()
{
}

const	wchar_t	clNucleotide::wcGetSymbol()const
{
	return	m_wcSymbol;
}



clAdenine::clAdenine()
{
	m_enNucleotide = enNucleotide::Adenine;
	m_wcSymbol = 'A';
}

clCytosine::clCytosine()
{
	m_enNucleotide = enNucleotide::Cytosine;
	m_wcSymbol = 'C';

}

clGuanine::clGuanine()
{
	m_enNucleotide = enNucleotide::Guanine;
	m_wcSymbol = 'G';
}

clUracil::clUracil()
{
	m_enNucleotide = enNucleotide::Uracil;
	m_wcSymbol = 'U';
}