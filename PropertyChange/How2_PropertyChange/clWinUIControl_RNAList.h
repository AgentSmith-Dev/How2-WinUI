#pragma once

#include "clWinUIControl_RNAList.g.h"

#include    "clWinUIRNA.h"
#include    "clWinUI_DataTemplateSelector_RNA_Nucleotids.h"

namespace winrt::How2_PropertyChange_DataBinding::implementation
{
    struct clWinUIControl_RNAList : clWinUIControl_RNAListT<clWinUIControl_RNAList>
    {
        clWinUIControl_RNAList();


        winrt::How2_PropertyChange_DataBinding::clWinUIRNA  GetWinUIRNA_Page_Property();
                                    void    GetWinUIRNA_Page_Property(winrt::How2_PropertyChange_DataBinding::clWinUIRNA const& value);

/*        winrt::event_token  PropertyChanged(winrt::Microsoft::UI::Xaml::Data::PropertyChangedEventHandler const& handler);
                    void    PropertyChanged(winrt::event_token const& token) noexcept;
*/

    protected:


        winrt::How2_PropertyChange_DataBinding::clWinUIRNA  m_WinUIRNA=nullptr;

//        winrt::event<Microsoft::UI::Xaml::Data::PropertyChangedEventHandler>	m_WinUIRNA_PropertyChanged;

    };
}

namespace winrt::How2_PropertyChange_DataBinding::factory_implementation
{
    struct clWinUIControl_RNAList : clWinUIControl_RNAListT<clWinUIControl_RNAList, implementation::clWinUIControl_RNAList>
    {
    };
}
