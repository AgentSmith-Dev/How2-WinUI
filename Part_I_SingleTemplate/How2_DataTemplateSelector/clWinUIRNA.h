#pragma once

#include    "clWinUINucleotide.h"

#include "clWinUIRNA.g.h"



namespace winrt::How2_DataTemplateSelector::implementation
{
    struct clWinUIRNA : clWinUIRNAT<clWinUIRNA>
    {
        clWinUIRNA();

        winrt::Windows::Foundation::Collections::IObservableVector<winrt::How2_DataTemplateSelector::clWinUINucleotide> Get_obsvecRNA_Property();
        winrt::event_token  PropertyChanged(winrt::Microsoft::UI::Xaml::Data::PropertyChangedEventHandler const& handler);
                    void    PropertyChanged(winrt::event_token const& token) noexcept;

                    void    CreateAndAddNucleotide(char16_t wcSymbol);

    private:
		winrt::Windows::Foundation::Collections::IObservableVector<winrt::How2_DataTemplateSelector::clWinUINucleotide> m_obsvecRNA;

        winrt::event<Microsoft::UI::Xaml::Data::PropertyChangedEventHandler>	m_obsvecRNA_PropertyChanged;

        

    };
}
namespace winrt::How2_DataTemplateSelector::factory_implementation
{
    struct clWinUIRNA : clWinUIRNAT<clWinUIRNA, implementation::clWinUIRNA>
    {
    };
}

