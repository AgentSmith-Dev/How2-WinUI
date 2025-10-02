#pragma once

#include    "clWinUIRNA.h"

#include "clWinUIControl_RNAInfo.g.h"

namespace winrt::How2_PropertyChange_II::implementation
{
    struct clWinUIControl_RNAInfo : clWinUIControl_RNAInfoT<clWinUIControl_RNAInfo>
    {
        clWinUIControl_RNAInfo()
        {
            // Xaml objects should not call InitializeComponent during construction.
            // See https://github.com/microsoft/cppwinrt/tree/master/nuget#initializecomponent
        }

        winrt::How2_PropertyChange_II::clWinUIRNA GetWinUIRNA_Property();
        void GetWinUIRNA_Property(winrt::How2_PropertyChange_II::clWinUIRNA const& value);

        winrt::event_token  PropertyChanged(winrt::Microsoft::UI::Xaml::Data::PropertyChangedEventHandler const& handler);
                    void    PropertyChanged(winrt::event_token const& token) noexcept;


    protected:
                    void    OnVectorChanged_Event_RNA(winrt::Windows::Foundation::IInspectable const& sender, winrt::Windows::Foundation::Collections::IVectorChangedEventArgs const& rArgs);


        winrt::event<Microsoft::UI::Xaml::Data::PropertyChangedEventHandler>  m_WinUIControl_RNAInfo_PropertyChanged;
        winrt::event_token  m_Event_RNAChanged; //!<    event token for changes in the RNA vector

        winrt::How2_PropertyChange_II::clWinUIRNA  m_WinUIRNA = nullptr;

    };
}

namespace winrt::How2_PropertyChange_II::factory_implementation
{
    struct clWinUIControl_RNAInfo : clWinUIControl_RNAInfoT<clWinUIControl_RNAInfo, implementation::clWinUIControl_RNAInfo>
    {
    };
}
