#pragma once
#include "clWinUINucleotide.g.h"

//#include    "Biochemistry/Nucleotide.h"

namespace winrt::How2_CopyNPaste::implementation
{
    struct clWinUINucleotide : clWinUINucleotideT<clWinUINucleotide>
    {
        clWinUINucleotide();// = default;
        clWinUINucleotide(winrt::How2_CopyNPaste::enNucleotide_Type const& _enNucleotide_Type);

//                            clWinUINucleotide(std::unique_ptr<clNucleotide>& rupNucleotide);
/*
                    void    AttachNucleotid(clNucleotide* pNucleotide);
                    void    DetachNucleotid();
*/
        winrt::How2_CopyNPaste::enNucleotide_Type enNucleotide_Type_Property();
                                                    void    enNucleotide_Type_Property(winrt::How2_CopyNPaste::enNucleotide_Type const& value);

                                                    hstring hstrSymbol_Property();
                                                    void    hstrSymbol_Property(hstring const& value);
                                        winrt::event_token  PropertyChanged(winrt::Microsoft::UI::Xaml::Data::PropertyChangedEventHandler const& handler);
                                                    void    PropertyChanged(winrt::event_token const& token) noexcept;

    private:
        winrt::event<Microsoft::UI::Xaml::Data::PropertyChangedEventHandler>	m_Nucleotide_PropertyChanged;

		            hstring m_hstrSymbol{ L"" }; // Symbol of the nucleotide
		enNucleotide_Type   m_enNucleotide_Type{ enNucleotide_Type::None }; // Type of the nucleotide
//        std::unique_ptr<clNucleotide>& m_rupNucleotide;// = nullptr;
//		clNucleotide*   m_pNucleotide=nullptr; // Pointer to the nucleotide object

    };
}
namespace winrt::How2_CopyNPaste::factory_implementation
{
    struct clWinUINucleotide : clWinUINucleotideT<clWinUINucleotide, implementation::clWinUINucleotide>
    {
    };
}
