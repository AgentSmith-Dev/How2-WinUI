#pragma once

#include	<vector>
#include	"Nucleotide.h"

typedef std::vector<std::unique_ptr<clNucleotide>> typVecNucleotide;

class clRNA : public typVecNucleotide
{
public:
	clRNA();
	~clRNA();

	void	Add(wchar_t wc);

	// Methods
};