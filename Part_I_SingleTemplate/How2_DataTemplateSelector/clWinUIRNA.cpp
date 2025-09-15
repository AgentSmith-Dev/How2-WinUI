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

namespace winrt::How2_DataTemplateSelector::implementation
{
    //  ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    /*! \brief  WinUI specific class which represents a RNA
    */
    //  ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

    //  ------------------------------------------------------------------------------------------------------
	/*! \brief  Constructor for clWinUIRNA
    *   \detail
    *   \date   08/22/2025  AGS Start
    */
    //  ------------------------------------------------------------------------------------------------------
    clWinUIRNA::clWinUIRNA()
    {
        // Initialize the RNA vector
        m_obsvecRNA = winrt::single_threaded_observable_vector<winrt::How2_DataTemplateSelector::clWinUINucleotide>();
    }


    //  ------------------------------------------------------------------------------------------------------
    /*! \brief  add a nucleotide specified by its symbol to the RNA
    *   \detail
    *   \date   08/22/2025  AGS Start
    */
    //  ------------------------------------------------------------------------------------------------------
    void	clWinUIRNA::CreateAndAddNucleotide(char16_t wcSymbol)
    {
        winrt::How2_DataTemplateSelector::clWinUINucleotide xNucleotide = nullptr;

        switch (wcSymbol)
        {
        case 'A':
            xNucleotide = winrt::make<How2_DataTemplateSelector::implementation::clWinUINucleotide>(enNucleotide_Type::Adenine);
            break;
        case 'C':
            xNucleotide = winrt::make<How2_DataTemplateSelector::implementation::clWinUINucleotide>(enNucleotide_Type::Cytosine);
            break;
        case 'G':
            xNucleotide = winrt::make<How2_DataTemplateSelector::implementation::clWinUINucleotide>(enNucleotide_Type::Guanine);
            break;
        case 'U':
            xNucleotide = winrt::make<How2_DataTemplateSelector::implementation::clWinUINucleotide>(enNucleotide_Type::Uracil);
            break;
		case 'T':
            xNucleotide = winrt::make<How2_DataTemplateSelector::implementation::clWinUINucleotide>(enNucleotide_Type::Thymine);
            break;
        default:
            // Handle invalid nucleotide
            break;
        }
		m_obsvecRNA.Append(xNucleotide);


        return;
    }




    //  ------------------------------------------------------------------------------------------------------
	/*! \brief  Property (to be used by XAML): vector with RNA nucleotides
    *   \detail
    *   \date   08/22/2025  AGS Start
    */
    //  ------------------------------------------------------------------------------------------------------
    winrt::Windows::Foundation::Collections::IObservableVector<winrt::How2_DataTemplateSelector::clWinUINucleotide> clWinUIRNA::Get_obsvecRNA_Property()
    {
        return  this->m_obsvecRNA;
    }


    //  ------------------------------------------------------------------------------------------------------
    /*! \brief  init/deinit handler for property changed events
    *   \date   08/22/2025  AGS Start
    */
    //  ------------------------------------------------------------------------------------------------------
    winrt::event_token clWinUIRNA::PropertyChanged(winrt::Microsoft::UI::Xaml::Data::PropertyChangedEventHandler const& handler)
    {
        return m_obsvecRNA_PropertyChanged.add(handler);
    }
    void clWinUIRNA::PropertyChanged(winrt::event_token const& token) noexcept
    {
        m_obsvecRNA_PropertyChanged.remove(token);

        return;
    }
}
