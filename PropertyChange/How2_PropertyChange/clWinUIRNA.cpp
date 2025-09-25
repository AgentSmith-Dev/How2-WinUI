// *******************************************************************************
//!<@copyright  Agent Smith, Dresden Germany
//!             www.agent-smith.dev    
// 
//  Initial code by AGS, 2025
// 
//  *******************************************************************************


#include "pch.h"
#include "clWinUIRNA.h"
#include "clWinUIRNA.g.cpp"

namespace winrt::How2_PropertyChange_DataBinding::implementation
{
    //  ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    /*! \brief  WinUI specific class which represents a RNA
    */
    //  ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

    //  ------------------------------------------------------------------------------------------------------
	/*! \brief  Constructor for clWinUIRNA
    *   \desc
    *   \date   08/22/2025  AGS Start
    */
    //  ------------------------------------------------------------------------------------------------------
    clWinUIRNA::clWinUIRNA()
    {
        // Initialize the RNA vector
        m_obsvecRNA = winrt::single_threaded_observable_vector<winrt::How2_PropertyChange_DataBinding::clWinUINucleotide>();
    }


    //  ------------------------------------------------------------------------------------------------------
    /*! \brief  add a nucleotide specified by its symbol (upper OR lower case) to the RNA
    *   \desc
    *   \date   08/22/2025  AGS Start
    *   \date   09/24/2025  AGS Modified:   accept lower case as well
    */
    //  ------------------------------------------------------------------------------------------------------
    void	clWinUIRNA::CreateAndAddNucleotide(char16_t wcSymbol)
    {
        winrt::How2_PropertyChange_DataBinding::clWinUINucleotide xNucleotide = nullptr;

        switch (wcSymbol)
        {
        case 'a':
        case 'A':
            xNucleotide = winrt::make<How2_PropertyChange_DataBinding::implementation::clWinUINucleotide>(enNucleotide_Type::Adenine);
            break;
        case 'c':
        case 'C':
            xNucleotide = winrt::make<How2_PropertyChange_DataBinding::implementation::clWinUINucleotide>(enNucleotide_Type::Cytosine);
            break;
        case 'g':
        case 'G':
            xNucleotide = winrt::make<How2_PropertyChange_DataBinding::implementation::clWinUINucleotide>(enNucleotide_Type::Guanine);
            break;
        case 'u':
        case 'U':
            xNucleotide = winrt::make<How2_PropertyChange_DataBinding::implementation::clWinUINucleotide>(enNucleotide_Type::Uracil);
            break;
        case 't':
        case 'T':
            xNucleotide = winrt::make<How2_PropertyChange_DataBinding::implementation::clWinUINucleotide>(enNucleotide_Type::Thymine);
            break;
        default:
            // Handle invalid nucleotide
            xNucleotide = winrt::make<How2_PropertyChange_DataBinding::implementation::clWinUINucleotide>(enNucleotide_Type::None);
            break;
        }
		m_obsvecRNA.Append(xNucleotide);


        return;
    }




    //  ------------------------------------------------------------------------------------------------------
	/*! \brief  Property (to be used by XAML): vector with RNA nucleotides
    *   \desc
    *   \date   08/22/2025  AGS Start
    */
    //  ------------------------------------------------------------------------------------------------------
    winrt::Windows::Foundation::Collections::IObservableVector<winrt::How2_PropertyChange_DataBinding::clWinUINucleotide> clWinUIRNA::Get_obsvecRNA_Property()
    {
        return  this->m_obsvecRNA;
    }


    //  ------------------------------------------------------------------------------------------------------
    /*! \brief  init/deinit handler for property changed events
    *   \date   08/22/2025  AGS Start
    */
    //  ------------------------------------------------------------------------------------------------------
/*    winrt::event_token clWinUIRNA::PropertyChanged(winrt::Microsoft::UI::Xaml::Data::PropertyChangedEventHandler const& handler)
    {
        return m_obsvecRNA_PropertyChanged.add(handler);
    }
    void clWinUIRNA::PropertyChanged(winrt::event_token const& token) noexcept
    {
        m_obsvecRNA_PropertyChanged.remove(token);

        return;
    }*/
}
