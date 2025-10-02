#pragma once

#include    "clWinUIRNA.h"
#include    "clWinUIControl_RNAList.h"

#include "MainWindow.g.h"

namespace winrt::How2_PropertyChange_II::implementation
{
    struct MainWindow : MainWindowT<MainWindow>
    {
                                               MainWindow();
		                                       ~MainWindow();

        winrt::How2_PropertyChange_II::clWinUIRNA  GetWinUIRNA_Window_Property();
                                        bool   bHasRNAClipboardData();
                                        void   bHasRNAClipboardData(bool value);
									    bool   bHasRNAData();

                        winrt::event_token  PropertyChanged(winrt::Microsoft::UI::Xaml::Data::PropertyChangedEventHandler const& handler);
                                    void    PropertyChanged(winrt::event_token const& token) noexcept;

                                    void    OnClipboardChanged(winrt::Windows::Foundation::IInspectable const& sender, winrt::Windows::Foundation::IInspectable const& e);

                                    void    OnBtnPastAtRNAEnd_Click(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& e);

    private:
                                        void    UpdateClipboardState();
     winrt::Windows::Foundation::IAsyncAction   Async_PasteClipboardToRNA();

                                                                        event_token m_EventToken_ClipboardChanged;  //!<    event token for clipboard changed event
            winrt::event<Microsoft::UI::Xaml::Data::PropertyChangedEventHandler>	m_MainFrame_PropertyChanged;    //!<    event token for property changed notifications


                                             winrt::How2_PropertyChange_II::clWinUIRNA  m_WinUIRNA;
		                                                                    bool    m_bHasRNAClipboardData = false;
    public:
        void OnBtnClearRNA_Click(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& e);
    };
}

namespace winrt::How2_PropertyChange_II::factory_implementation
{
    struct MainWindow : MainWindowT<MainWindow, implementation::MainWindow>
    {
    };
}
