#pragma once

#include "clWinUIControl_RNAList.g.h"

#include    "clWinUIRNA.h"
#include    "clWinUI_DataTemplateSelector_RNA_Nucleotids.h"

namespace winrt::How2_PropertyChange_II::implementation
{
    struct clWinUIControl_RNAList : clWinUIControl_RNAListT<clWinUIControl_RNAList>
    {
        clWinUIControl_RNAList();


        winrt::How2_PropertyChange_II::clWinUIRNA  GetWinUIRNA_Page_Property();
                                    void    GetWinUIRNA_Page_Property(winrt::How2_PropertyChange_II::clWinUIRNA const& value);


    protected:
        winrt::How2_PropertyChange_II::clWinUIRNA  m_WinUIRNA=nullptr;

    };
}

namespace winrt::How2_PropertyChange_II::factory_implementation
{
    struct clWinUIControl_RNAList : clWinUIControl_RNAListT<clWinUIControl_RNAList, implementation::clWinUIControl_RNAList>
    {
    };
}
