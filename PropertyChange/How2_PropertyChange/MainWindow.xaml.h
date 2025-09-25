#pragma once

#include    "clWinUIRNA.h"
#include    "clWinUIControl_RNAList.h"

#include "MainWindow.g.h"

//#include "./Biochemistry/RNA.h"

namespace winrt::How2_PropertyChange_DataBinding::implementation
{
    struct MainWindow : MainWindowT<MainWindow>
    {
        MainWindow();
		~MainWindow();

        winrt::How2_PropertyChange_DataBinding::clWinUIRNA  GetWinUIRNA_Window_Property();
                                    bool    bHasRNAClipboardData();
                                     void   bHasRNAClipboardData(bool value);
									 bool   bHasRNAData();

									 // used for one-way binding
							    hstring    hstrGetRNANbNucleotides();

								//  used for two-way binding
                                 hstring    strRNANbNucleotides_Property();
                                     void   strRNANbNucleotides_Property(hstring const& value);


                        winrt::event_token  PropertyChanged(winrt::Microsoft::UI::Xaml::Data::PropertyChangedEventHandler const& handler);
                                    void    PropertyChanged(winrt::event_token const& token) noexcept;


                                    void    OnClipboardChanged(winrt::Windows::Foundation::IInspectable const& sender, winrt::Windows::Foundation::IInspectable const& e);

                                    void    OnBtnPastAtRNAEnd_Click(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& e);

    private:
                                        void    UpdateClipboardState();
     winrt::Windows::Foundation::IAsyncAction   PasteClipboardToRNA();

                                                                        event_token m_EventToken_ClipboardChanged;  //!<    event token for clipboard changed event
            winrt::event<Microsoft::UI::Xaml::Data::PropertyChangedEventHandler>	m_MainFrame_PropertyChanged;    //!<    event token for property changed notifications


        winrt::How2_PropertyChange_DataBinding::clWinUIRNA  m_WinUIRNA;
		                                            bool    m_bHasRNAClipboardData = false;
    public:
        void OnBtnClearRNA_Click(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& e);
    };
}

namespace winrt::How2_PropertyChange_DataBinding::factory_implementation
{
    struct MainWindow : MainWindowT<MainWindow, implementation::MainWindow>
    {
    };
}
