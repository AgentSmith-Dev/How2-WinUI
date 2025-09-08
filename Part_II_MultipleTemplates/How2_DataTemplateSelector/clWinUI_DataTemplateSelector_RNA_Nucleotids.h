#pragma once
#include "clWinUI_DataTemplateSelector_RNA_Nucleotids.g.h"

namespace winrt::How2_PartII_DataTemplateSelector::implementation
{
    struct clWinUI_DataTemplateSelector_RNA_Nucleotids : clWinUI_DataTemplateSelector_RNA_NucleotidsT<clWinUI_DataTemplateSelector_RNA_Nucleotids>
    {
        clWinUI_DataTemplateSelector_RNA_Nucleotids() = default;

        winrt::Microsoft::UI::Xaml::DataTemplate    Adenine_Property();
                                            void    Adenine_Property(winrt::Microsoft::UI::Xaml::DataTemplate const& value);
        winrt::Microsoft::UI::Xaml::DataTemplate    Cytosine_Property();
                                            void    Cytosine_Property(winrt::Microsoft::UI::Xaml::DataTemplate const& value);
        winrt::Microsoft::UI::Xaml::DataTemplate    Guanine_Property();
                                            void    Guanine_Property(winrt::Microsoft::UI::Xaml::DataTemplate const& value);
        winrt::Microsoft::UI::Xaml::DataTemplate    Uracil_Property();
                                            void    Uracil_Property(winrt::Microsoft::UI::Xaml::DataTemplate const& value);
        winrt::Microsoft::UI::Xaml::DataTemplate    Error_Property();
                                            void    Error_Property(winrt::Microsoft::UI::Xaml::DataTemplate const& value);


        winrt::Microsoft::UI::Xaml::DataTemplate    SelectTemplateCore(winrt::Windows::Foundation::IInspectable const& item, winrt::Microsoft::UI::Xaml::DependencyObject const& dp);
        winrt::Microsoft::UI::Xaml::DataTemplate    SelectTemplateCore(winrt::Windows::Foundation::IInspectable const& item);

    protected:
        Microsoft::UI::Xaml::DataTemplate m_DataTemplate_Adenin_Property;
        Microsoft::UI::Xaml::DataTemplate m_DataTemplate_Cytosine_Property;
        Microsoft::UI::Xaml::DataTemplate m_DataTemplate_Guanine_Property;
        Microsoft::UI::Xaml::DataTemplate m_DataTemplate_Uracil_Property;
        Microsoft::UI::Xaml::DataTemplate m_DataTemplate_Error_Property;

    };
}
namespace winrt::How2_PartII_DataTemplateSelector::factory_implementation
{
    struct clWinUI_DataTemplateSelector_RNA_Nucleotids : clWinUI_DataTemplateSelector_RNA_NucleotidsT<clWinUI_DataTemplateSelector_RNA_Nucleotids, implementation::clWinUI_DataTemplateSelector_RNA_Nucleotids>
    {
    };
}
