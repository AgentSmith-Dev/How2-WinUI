// *******************************************************************************
//!<@copyright  Agent Smith, Dresden Germany
//!             www.agent-smith.dev    
// 
//  Initial code by AGS, 2025
// 
//  *******************************************************************************



#include "pch.h"
#include "clWinUIControl_RNAList.h"
#if __has_include("clWinUIControl_RNAList.g.cpp")
#include "clWinUIControl_RNAList.g.cpp"
#endif


using namespace winrt;
using namespace Windows::UI::Xaml;

namespace winrt::How2_PropertyChange_II::implementation
{

    //  ------------------------------------------------------------------------------------------------------
    /*! \brief  Constructor
    *   
    *   \date   09/15/2025  AGS Start
    */
    //  ------------------------------------------------------------------------------------------------------
    clWinUIControl_RNAList::clWinUIControl_RNAList()
    {
        // Xaml objects should not call InitializeComponent during construction.
        // See https://github.com/microsoft/cppwinrt/tree/master/nuget#initializecomponent

    }


    //  ------------------------------------------------------------------------------------------------------
    /*! \brief  Property (to be used by XAML): WinUI representation of the RNA
    *   \desc
    *   \date   08/22/2025  AGS Start
    */
    //  ------------------------------------------------------------------------------------------------------

    winrt::How2_PropertyChange_II::clWinUIRNA clWinUIControl_RNAList::GetWinUIRNA_Page_Property()
    {
        return  this->m_WinUIRNA;
    }

    void clWinUIControl_RNAList::GetWinUIRNA_Page_Property(winrt::How2_PropertyChange_II::clWinUIRNA const& value)
    {
        if (this->m_WinUIRNA == value) {
        }
        else {
            this->m_WinUIRNA = value;
        }

        return;
    }


    //  ------------------------------------------------------------------------------------------------------
    /*! \brief  init/deinit handler for property changed events
    *   \date   08/22/2025  AGS Start
    */
    //  ------------------------------------------------------------------------------------------------------
/*    winrt::event_token clWinUIControl_RNAList::PropertyChanged(winrt::Microsoft::UI::Xaml::Data::PropertyChangedEventHandler const& handler)
    {
        return m_WinUIRNA_PropertyChanged.add(handler);
    }

    void clWinUIControl_RNAList::PropertyChanged(winrt::event_token const& token) noexcept
    {
        m_WinUIRNA_PropertyChanged.remove(token);

        return;
    }
    */
}
