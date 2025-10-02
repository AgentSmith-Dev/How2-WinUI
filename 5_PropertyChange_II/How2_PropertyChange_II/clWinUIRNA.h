#pragma once

#include    "clWinUINucleotide.h"

#include "clWinUIRNA.g.h"



namespace winrt::How2_PropertyChange_II::implementation
{
    struct clWinUIRNA : clWinUIRNAT<clWinUIRNA>
    {
        clWinUIRNA();

        winrt::Windows::Foundation::Collections::IObservableVector<winrt::How2_PropertyChange_II::clWinUINucleotide> Get_obsvecRNA_Property();

                    void    CreateAndAddNucleotide(char16_t wcSymbol);
                    int32_t iGetRNANbNucleotides();

    private:
		winrt::Windows::Foundation::Collections::IObservableVector<winrt::How2_PropertyChange_II::clWinUINucleotide> m_obsvecRNA;

    };
}
namespace winrt::How2_PropertyChange_II::factory_implementation
{
    struct clWinUIRNA : clWinUIRNAT<clWinUIRNA, implementation::clWinUIRNA>
    {
    };
}

