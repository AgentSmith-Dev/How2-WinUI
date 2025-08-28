#include "pch.h"
#include "RNA.h"


clRNA::clRNA()
{
}
clRNA::~clRNA()
{
}

void	clRNA::Add(wchar_t wc)
{
	std::unique_ptr<clNucleotide> upNucleotide=nullptr;
	switch (wc)
	{
	case 'A':
		upNucleotide = std::make_unique<clAdenine>();
		break;
	case 'C':
		upNucleotide = std::make_unique<clCytosine>();
		break;
	case 'G':
		upNucleotide = std::make_unique<clGuanine>();
		break;
	case 'U':
		upNucleotide = std::make_unique<clUracil>();
		break;
	default:
		// Handle invalid nucleotide
		break;
	}

	if (upNucleotide)
	{
		push_back(std::move(upNucleotide));
	}
	else
	{
		// Handle error for unsupported nucleotide
	}

	return;
}