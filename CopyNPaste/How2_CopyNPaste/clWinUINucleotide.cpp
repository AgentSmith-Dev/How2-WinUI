// *******************************************************************************
//!<@copyright  Agent Smith, Dresden Germany
//!             www.agent-smith.dev    
// 
//  Initial code by AGS, 2025
// 
//  *******************************************************************************

#include "pch.h"
#include "clWinUINucleotide.h"
#include "clWinUINucleotide.g.cpp"

namespace winrt::How2_CopyNPaste::implementation
{

    //  ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    /*! \brief  WinUI specific class which represents a nucleotide in a RNA
    */
    //  ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


    //  ------------------------------------------------------------------------------------------------------
    /*! \brief  Constructor for clWinUIRNA
    *   \desc
    *   \date   08/22/2025  AGS Start
    */
    //  ------------------------------------------------------------------------------------------------------
	//clWinUINucleotide::clWinUINucleotide(std::unique_ptr<clNucleotide>& rupNucleotide)
      //  : m_rupNucleotide(rupNucleotide)
    clWinUINucleotide::clWinUINucleotide()
    {
        
	}

    clWinUINucleotide::clWinUINucleotide(winrt::How2_CopyNPaste::enNucleotide_Type const& _enNucleotide_Type)
    {
		m_enNucleotide_Type = _enNucleotide_Type;
    }


    //  ------------------------------------------------------------------------------------------------------
    /*! \brief  Property (to be used by XAML): nucleotide symbol
    *   \date   08/22/2025  AGS Start
    */
    //  ------------------------------------------------------------------------------------------------------
    winrt::How2_CopyNPaste::enNucleotide_Type clWinUINucleotide::enNucleotide_Type_Property()
    {
        return  m_enNucleotide_Type;
    }
    void clWinUINucleotide::enNucleotide_Type_Property(winrt::How2_CopyNPaste::enNucleotide_Type const& value)
    {
        m_enNucleotide_Type =   value;

        return;
    }

    //  ------------------------------------------------------------------------------------------------------
	/*! \brief  attach/detach a nucleotide to the WinUI representation
    *   \date   08/22/2025  AGS Start
    */
    //  ------------------------------------------------------------------------------------------------------
/*
    void    clWinUINucleotide::AttachNucleotid(clNucleotide* pNucleotide)
    {
		m_pNucleotide = pNucleotide;

        return;
    }

    void    clWinUINucleotide::DetachNucleotid()
    {
        m_pNucleotide = nullptr;

        return;
    }
*/

    //  ------------------------------------------------------------------------------------------------------
	/*! \brief  Property (to be used by XAML): nucleotide symbol
    *   \date   08/22/2025  AGS Start
    */
    //  ------------------------------------------------------------------------------------------------------
    hstring clWinUINucleotide::hstrSymbol_Property()
    {
        winrt::hstring  hstrSymbol;

		switch (m_enNucleotide_Type)
		{
		case enNucleotide_Type::Adenine:
            hstrSymbol = L"A";
			break;
		case enNucleotide_Type::Cytosine:
            hstrSymbol = L"C";
			break;
		case enNucleotide_Type::Guanine:
            hstrSymbol = L"G";
			break;
		case enNucleotide_Type::Uracil:
            hstrSymbol = L"U";
			break;
		case enNucleotide_Type::Thymine:
            hstrSymbol = L"T";
			break;
		default:
            hstrSymbol = L"?"; // Unknown nucleotide type
		}
        return  hstrSymbol;

    }
    void clWinUINucleotide::hstrSymbol_Property(hstring const& value)
    {
        value;

        throw hresult_not_implemented();
    }


    //  ------------------------------------------------------------------------------------------------------
    /*! \brief  init/deinit handler for property changed events
    *   \date   08/22/2025  AGS Start
    */
    //  ------------------------------------------------------------------------------------------------------
    winrt::event_token clWinUINucleotide::PropertyChanged(winrt::Microsoft::UI::Xaml::Data::PropertyChangedEventHandler const& handler)
    {
        return m_Nucleotide_PropertyChanged.add(handler);
    }
    void clWinUINucleotide::PropertyChanged(winrt::event_token const& token) noexcept
    {
        m_Nucleotide_PropertyChanged.remove(token);

        return;
    }
}
