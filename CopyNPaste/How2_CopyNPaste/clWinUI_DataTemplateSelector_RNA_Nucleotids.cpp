// *******************************************************************************
//!<@copyright  Agent Smith, Dresden Germany
//!             www.agent-smith.dev    
// 
//  Initial code by AGS, 2025
// 
//  *******************************************************************************

#include "pch.h"
#include "clWinUI_DataTemplateSelector_RNA_Nucleotids.h"
#include "clWinUI_DataTemplateSelector_RNA_Nucleotids.g.cpp"

namespace winrt::How2_CopyNPaste::implementation
{
    //  ------------------------------------------------------------------------------------------------------
	/*! \brief  getter/setter for adenine data template
    *   \date   08/26/2025  AGS Start
    */
    //  ------------------------------------------------------------------------------------------------------
    winrt::Microsoft::UI::Xaml::DataTemplate clWinUI_DataTemplateSelector_RNA_Nucleotids::Adenine_Property()
    {
        return  m_DataTemplate_Adenin_Property;
    }
    void clWinUI_DataTemplateSelector_RNA_Nucleotids::Adenine_Property(winrt::Microsoft::UI::Xaml::DataTemplate const& value)
    {
        m_DataTemplate_Adenin_Property=value;

        return;
    }
    //  ------------------------------------------------------------------------------------------------------
    /*! \brief  getter/setter for cytosine data template
    *   \date   08/26/2025  AGS Start
    */
    //  ------------------------------------------------------------------------------------------------------
    winrt::Microsoft::UI::Xaml::DataTemplate clWinUI_DataTemplateSelector_RNA_Nucleotids::Cytosine_Property()
    {
        return  m_DataTemplate_Cytosine_Property;
    }
    void clWinUI_DataTemplateSelector_RNA_Nucleotids::Cytosine_Property(winrt::Microsoft::UI::Xaml::DataTemplate const& value)
    {
        m_DataTemplate_Cytosine_Property = value;

        return;
    }
    //  ------------------------------------------------------------------------------------------------------
    /*! \brief  getter/setter for guanine data template
    *   \date   08/26/2025  AGS Start
    */
    //  ------------------------------------------------------------------------------------------------------
    winrt::Microsoft::UI::Xaml::DataTemplate clWinUI_DataTemplateSelector_RNA_Nucleotids::Guanine_Property()
    {
        return  m_DataTemplate_Guanine_Property;
    }
    void clWinUI_DataTemplateSelector_RNA_Nucleotids::Guanine_Property(winrt::Microsoft::UI::Xaml::DataTemplate const& value)
    {
        m_DataTemplate_Guanine_Property = value;

        return;
    }
    //  ------------------------------------------------------------------------------------------------------
    /*! \brief  getter/setter for uracil data template
    *   \date   08/26/2025  AGS Start
    */
    //  ------------------------------------------------------------------------------------------------------
    winrt::Microsoft::UI::Xaml::DataTemplate clWinUI_DataTemplateSelector_RNA_Nucleotids::Uracil_Property()
    {
        return  m_DataTemplate_Uracil_Property;
    }
    void clWinUI_DataTemplateSelector_RNA_Nucleotids::Uracil_Property(winrt::Microsoft::UI::Xaml::DataTemplate const& value)
    {
        m_DataTemplate_Uracil_Property = value;

        return;
    }
    //  ------------------------------------------------------------------------------------------------------
    /*! \brief  getter/setter for error data template
    *   \date   08/26/2025  AGS Start
    */
    //  ------------------------------------------------------------------------------------------------------
    winrt::Microsoft::UI::Xaml::DataTemplate clWinUI_DataTemplateSelector_RNA_Nucleotids::Error_Property()
    {
        return  m_DataTemplate_Error_Property;
    }
    void clWinUI_DataTemplateSelector_RNA_Nucleotids::Error_Property(winrt::Microsoft::UI::Xaml::DataTemplate const& value)
    {
        m_DataTemplate_Error_Property = value;

        return;
    }

    winrt::Microsoft::UI::Xaml::DataTemplate clWinUI_DataTemplateSelector_RNA_Nucleotids::SelectTemplateCore(winrt::Windows::Foundation::IInspectable const& item, winrt::Microsoft::UI::Xaml::DependencyObject const& dp)
    {
        item; dp;
        int i;
        clWinUINucleotide   rWinUINucleotide;
        if ((item.try_as<clWinUINucleotide>(rWinUINucleotide))) {
            i = 5;
        }
        else {
            i = 6;
        }

        return  SelectTemplateCore(item);
//        throw hresult_not_implemented();
    }
    //  ------------------------------------------------------------------------------------------------------
    /*! \brief  called by the framework: the the template according the item to be inspected
    *   \date   08/26/2025  AGS Start
    */
    //  ------------------------------------------------------------------------------------------------------
    winrt::Microsoft::UI::Xaml::DataTemplate clWinUI_DataTemplateSelector_RNA_Nucleotids::SelectTemplateCore(winrt::Windows::Foundation::IInspectable const& item)
    {
        winrt::Microsoft::UI::Xaml::DataTemplate  rDataTemplate;

        clWinUINucleotide   rWinUINucleotide;
        if ((item.try_as<clWinUINucleotide>(rWinUINucleotide))) {
            switch (rWinUINucleotide.enNucleotide_Type_Property()) {
            case    winrt::How2_CopyNPaste::enNucleotide_Type::Adenine: {
                rDataTemplate = Adenine_Property();
                break;
            }
            case    winrt::How2_CopyNPaste::enNucleotide_Type::Cytosine: {
                rDataTemplate = Cytosine_Property();
                break;
            }
            case    winrt::How2_CopyNPaste::enNucleotide_Type::Guanine: {
                rDataTemplate = Guanine_Property();
                break;
            }
            case    winrt::How2_CopyNPaste::enNucleotide_Type::Uracil: {
                rDataTemplate = Uracil_Property();
                break;
            }
            default: {
                rDataTemplate = Error_Property();
            }
            }   //  endswitch (rWinUINucleotide.enNucleotide_Type_Property()) {
        }
        else{
            rDataTemplate = Error_Property();

		}   //  endif (item.try_as<clWinUINucleotide>(rWinUINucleotide)) {e


        return  rDataTemplate;
    }
}
