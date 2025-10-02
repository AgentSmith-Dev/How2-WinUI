// *******************************************************************************
//!<@copyright  Agent Smith, Dresden Germany
//!             www.agent-smith.dev    
// 
//  Initial code by AGS, 2025
// 
//  *******************************************************************************

#include "pch.h"
#include "clWinUIControl_RNAInfo.xaml.h"
#if __has_include("clWinUIControl_RNAInfo.g.cpp")
#include "clWinUIControl_RNAInfo.g.cpp"
#endif

using namespace winrt;
using namespace Microsoft::UI::Xaml;

// To learn more about WinUI, the WinUI project structure,
// and more about our project templates, see: http://aka.ms/winui-project-info.

namespace winrt::How2_PropertyChange_II::implementation
{

    //  ------------------------------------------------------------------------------------------------------
    /*! \brief  Property (to be used by XAML): WinUI representation of the RNA
    *   \desc
    *   \date   09/29/2025  AGS Start
    */
    //  ------------------------------------------------------------------------------------------------------

    winrt::How2_PropertyChange_II::clWinUIRNA clWinUIControl_RNAInfo::GetWinUIRNA_Property()
    {
        return  this->m_WinUIRNA;
    }
    void clWinUIControl_RNAInfo::GetWinUIRNA_Property(winrt::How2_PropertyChange_II::clWinUIRNA const& value)
    {
        if (this->m_WinUIRNA == value) {
            //  no change -> skip
        }
        else {
            this->m_WinUIRNA = value;

			//  check we already have an event token. If so, remove it first
            //  ''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
            if (!m_Event_RNAChanged) {
				//  no token (yet) -> nothing to remove -> done
            }
            else {
                //  remove event
                m_WinUIRNA.Get_obsvecRNA_Property().VectorChanged(m_Event_RNAChanged);
            }   //  endif (m_Event_RNAChanged == 0) {

            //  attach event handler to the RNA vector
            m_Event_RNAChanged = m_WinUIRNA.Get_obsvecRNA_Property().VectorChanged({ this, &clWinUIControl_RNAInfo::OnVectorChanged_Event_RNA });


        }   //  endif (this->m_WinUIRNA == value) {

        return;
    }

    //  ------------------------------------------------------------------------------------------------------
    /*! \brief  that is our event handler, being called when a change in the RNA occurs
    *   \date	09/30/2025	AGS Start
    */
    //  ------------------------------------------------------------------------------------------------------
    void    clWinUIControl_RNAInfo::OnVectorChanged_Event_RNA(winrt::Windows::Foundation::IInspectable const& sender, winrt::Windows::Foundation::Collections::IVectorChangedEventArgs const& rArgs)
    {
        sender;

        switch (rArgs.CollectionChange()) {
        case    winrt::Windows::Foundation::Collections::CollectionChange::Reset: {
            //  all nucleotides have been removed from the RNA
            m_WinUIControl_RNAInfo_PropertyChanged(*this, Microsoft::UI::Xaml::Data::PropertyChangedEventArgs{ L"GetWinUIRNA_Property" });
            break;
        }
        case    winrt::Windows::Foundation::Collections::CollectionChange::ItemInserted: {
            //  a nucleotide has been inserted into the RNA
            m_WinUIControl_RNAInfo_PropertyChanged(*this, Microsoft::UI::Xaml::Data::PropertyChangedEventArgs{ L"GetWinUIRNA_Property" });
            break;
        }
        case    winrt::Windows::Foundation::Collections::CollectionChange::ItemRemoved: {
            //  a nucleotide has been removed from the RNA
            m_WinUIControl_RNAInfo_PropertyChanged(*this, Microsoft::UI::Xaml::Data::PropertyChangedEventArgs{ L"GetWinUIRNA_Property" });
            break;
        }
        case    winrt::Windows::Foundation::Collections::CollectionChange::ItemChanged: {
            assert(false);
            break;
        }
        }   //  endswitch (rArgs.CollectionChange()) {

        return;
    }



    //  ------------------------------------------------------------------------------------------------------
    /*! \brief  init/deinit handler for property changed events
    *   \date   09/29/2025  AGS Start
    */
    //  ------------------------------------------------------------------------------------------------------
    winrt::event_token clWinUIControl_RNAInfo::PropertyChanged(winrt::Microsoft::UI::Xaml::Data::PropertyChangedEventHandler const& handler)
    {
        return m_WinUIControl_RNAInfo_PropertyChanged.add(handler);
    }
    void clWinUIControl_RNAInfo::PropertyChanged(winrt::event_token const& token) noexcept
    {
        m_WinUIControl_RNAInfo_PropertyChanged.remove(token);

        return;
    }

}   //  endnamespace winrt::How2_PropertyChange_II::implementation
