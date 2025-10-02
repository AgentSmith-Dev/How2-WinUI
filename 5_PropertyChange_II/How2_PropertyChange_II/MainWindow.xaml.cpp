// *******************************************************************************
//!<@copyright  Agent Smith, Dresden Germany
//!             www.agent-smith.dev    
// 
//  Initial code by AGS, 2025
// 
//  *******************************************************************************

#include "pch.h"
#include "MainWindow.xaml.h"
#if __has_include("MainWindow.g.cpp")
#include "MainWindow.g.cpp"
#endif

#include    <winrt/Windows.ApplicationModel.DataTransfer.h>

using namespace winrt;
using namespace Microsoft::UI::Xaml;

// To learn more about WinUI, the WinUI project structure,
// and more about our project templates, see: http://aka.ms/winui-project-info.

namespace winrt::How2_PropertyChange_II::implementation
{
    MainWindow::MainWindow()
    {
        // Xaml objects should not call InitializeComponent during construction.
        // See https://github.com/microsoft/cppwinrt/tree/master/nuget#initializecomponent

        //  microRNA rno-miR-21 from Rattus norvegicus
        //  5'-UAGCUUAUCAGACUGAUGUUGA-3'
/*
        m_WinUIRNA.CreateAndAddNucleotide('U');
        m_WinUIRNA.CreateAndAddNucleotide('A');
        m_WinUIRNA.CreateAndAddNucleotide('G');
        m_WinUIRNA.CreateAndAddNucleotide('C');
        m_WinUIRNA.CreateAndAddNucleotide('U');
        m_WinUIRNA.CreateAndAddNucleotide('U');
        m_WinUIRNA.CreateAndAddNucleotide('X'); //  should be 'A'
        m_WinUIRNA.CreateAndAddNucleotide('U');
        m_WinUIRNA.CreateAndAddNucleotide('C');
        m_WinUIRNA.CreateAndAddNucleotide('A');
        m_WinUIRNA.CreateAndAddNucleotide('G');
        m_WinUIRNA.CreateAndAddNucleotide('A');
        m_WinUIRNA.CreateAndAddNucleotide('C');
        m_WinUIRNA.CreateAndAddNucleotide('U');
        m_WinUIRNA.CreateAndAddNucleotide('G');
        m_WinUIRNA.CreateAndAddNucleotide('A');
        m_WinUIRNA.CreateAndAddNucleotide('U');
        m_WinUIRNA.CreateAndAddNucleotide('G');
        m_WinUIRNA.CreateAndAddNucleotide('U');
        m_WinUIRNA.CreateAndAddNucleotide('U');
        m_WinUIRNA.CreateAndAddNucleotide('G');
        m_WinUIRNA.CreateAndAddNucleotide('A');
*/

        m_EventToken_ClipboardChanged = winrt::Windows::ApplicationModel::DataTransfer::Clipboard::ContentChanged({ this, &MainWindow::OnClipboardChanged });

        UpdateClipboardState();

    }

    MainWindow::~MainWindow()
    {
        winrt::Windows::ApplicationModel::DataTransfer::Clipboard::ContentChanged(m_EventToken_ClipboardChanged);
    }

    //  ------------------------------------------------------------------------------------------------------
	/*! \brief  Property (to be used by XAML): WinUI representation of the RNA
    *   \desc
    *   \date   08/22/2025  AGS Start
    */
    //  ------------------------------------------------------------------------------------------------------

    winrt::How2_PropertyChange_II::clWinUIRNA MainWindow::GetWinUIRNA_Window_Property()
    {
        return  this->m_WinUIRNA;
    }

    //  ------------------------------------------------------------------------------------------------------
    /*! \brief  getter/setter (to be used by XAML): are there data in the clipboard
    *   \desc
    *   \date   09/15/2025  AGS Start
    */
    //  ------------------------------------------------------------------------------------------------------

    bool MainWindow::bHasRNAClipboardData()
    {
        return  m_bHasRNAClipboardData;
    }

    void MainWindow::bHasRNAClipboardData(bool bHasRNAClipboardData)
    {
        if (bHasRNAClipboardData == m_bHasRNAClipboardData) {
        }
        else {
			m_bHasRNAClipboardData = bHasRNAClipboardData;
        }   //  endif (bHasRNAClipboardData == m_bHasRNAClipboardData) {

        return;
    }



    //  ------------------------------------------------------------------------------------------------------
    /*! \brief  property (to be used by XAML): are there data (=nucleotides) in the RNA object
    *   \desc
    *   \date   09/15/2025  AGS Start
    */
    //  ------------------------------------------------------------------------------------------------------
    bool MainWindow::bHasRNAData()
    {
        return  this->m_WinUIRNA.Get_obsvecRNA_Property().Size() > 0;
    }


    //  ------------------------------------------------------------------------------------------------------
    /*! \brief  init/deinit handler for property changed events
    *   \date   09/15/2025  AGS Start
    */
    //  ------------------------------------------------------------------------------------------------------
    winrt::event_token MainWindow::PropertyChanged(winrt::Microsoft::UI::Xaml::Data::PropertyChangedEventHandler const& handler)
    {
        return m_MainFrame_PropertyChanged.add(handler);
    }

    void MainWindow::PropertyChanged(winrt::event_token const& token) noexcept
    {
        m_MainFrame_PropertyChanged.remove(token);

        return;
    }


    //  ------------------------------------------------------------------------------------------------------
    /*! \brief  event handler for changes of the clipboard - called by the framework
    *   \date   09/15/2025  AGS Start
    *	\param  sender
    *	\param  e
    */
    //  ------------------------------------------------------------------------------------------------------
    void MainWindow::OnClipboardChanged(winrt::Windows::Foundation::IInspectable const& sender, winrt::Windows::Foundation::IInspectable const& e)
    {
        sender;
        e;

        UpdateClipboardState();

        return;
    }

    //  ------------------------------------------------------------------------------------------------------
    /*! \brief  update the clipboard of the app
    *           
    *           for formats available in the clipboard \see https://learn.microsoft.com/en-us/uwp/api/windows.applicationmodel.datatransfer.standarddataformats.text?view=winrt-22621
    *   \date   09/15/2025  AGS Start
    */
    //  ------------------------------------------------------------------------------------------------------
    void MainWindow::UpdateClipboardState()
    {
        bool    bHasTextInClipboard = true;

        winrt::Windows::ApplicationModel::DataTransfer::DataPackageView dataPackageView=nullptr;

        dataPackageView = winrt::Windows::ApplicationModel::DataTransfer::Clipboard::GetContent();
        hstring hstrTextFormat = winrt::Windows::ApplicationModel::DataTransfer::StandardDataFormats::Text();

        if (dataPackageView.Contains(hstrTextFormat)) {
            bHasTextInClipboard = true;
            OutputDebugStringW(L"Clipboad contains text\n");
        }
        else {
            bHasTextInClipboard = false;
            OutputDebugStringW(L"Clipboad empty\n");
        }

        bHasRNAClipboardData(bHasTextInClipboard);

        return;
    }



    //  ------------------------------------------------------------------------------------------------------
    /*! \brief  called by the framework: the button "Paste at end" has been clicked
    *   \date   09/15/2025  AGS Start
    *	\param  sender
    *	\param  e
    */
    //  ------------------------------------------------------------------------------------------------------
    void MainWindow::OnBtnPastAtRNAEnd_Click(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& e)
    {
        sender; e;
        winrt::Windows::Foundation::IAsyncAction  _IAsync_PasteClipboardToRNA    =    Async_PasteClipboardToRNA();

        //  this function is being called upon completion
        _IAsync_PasteClipboardToRNA.Completed([this](winrt::Windows::Foundation::IAsyncAction const& sender,
            winrt::Windows::Foundation::AsyncStatus const asyncStatus)
            {
                sender; asyncStatus;

                //  notify interested parties
                m_MainFrame_PropertyChanged(*this, Microsoft::UI::Xaml::Data::PropertyChangedEventArgs{ L"bHasRNAData" });
                ;
            });


        return;
    }

    //  ------------------------------------------------------------------------------------------------------
    /*! \brief  paste clipboard content to the end of the RNA
    *   \date   09/15/2025  AGS Start
    */
    //  ------------------------------------------------------------------------------------------------------
    winrt::Windows::Foundation::IAsyncAction    MainWindow::Async_PasteClipboardToRNA()
    {
        winrt::Windows::ApplicationModel::DataTransfer::DataPackageView dataPackageView = nullptr;

        dataPackageView = winrt::Windows::ApplicationModel::DataTransfer::Clipboard::GetContent();

        winrt::hstring  hstrClipBoard = co_await    dataPackageView.GetTextAsync();

		int iPos=0;
        while (iPos < (int)hstrClipBoard.size()) {
			wchar_t c = hstrClipBoard[iPos];
            m_WinUIRNA.CreateAndAddNucleotide(c);
            iPos++;

		}   //  endwhile (iPos < hstrClipBoard.size()) {

        co_return;
    }


    //  ------------------------------------------------------------------------------------------------------
    /*! \brief  called by the framework: the button "Clear RNA" has been clicked
    *   \date   09/15/2025  AGS Start
    *	\param
    *	\param
    */
    //  ------------------------------------------------------------------------------------------------------
    void winrt::How2_PropertyChange_II::implementation::MainWindow::OnBtnClearRNA_Click(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& e)
    {
        sender; 
        e;

        m_WinUIRNA.Get_obsvecRNA_Property().Clear();

        //  notify interested parties
        m_MainFrame_PropertyChanged(*this, Microsoft::UI::Xaml::Data::PropertyChangedEventArgs{ L"bHasRNAData" });
        
        return;
    }

}


