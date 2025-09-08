#include "pch.h"
#include "MainWindow.xaml.h"
#if __has_include("MainWindow.g.cpp")
#include "MainWindow.g.cpp"
#endif

using namespace winrt;
using namespace Microsoft::UI::Xaml;

// To learn more about WinUI, the WinUI project structure,
// and more about our project templates, see: http://aka.ms/winui-project-info.

namespace winrt::How2_PartII_DataTemplateSelector::implementation
{
    MainWindow::MainWindow()
    {
        // Xaml objects should not call InitializeComponent during construction.
        // See https://github.com/microsoft/cppwinrt/tree/master/nuget#initializecomponent

        //  microRNA rno-miR-21 from Rattus norvegicus
        //  5'-UAGCUUAUCAGACUGAUGUUGA-3'

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




    }

    MainWindow::~MainWindow()
    {
    }

    //  ------------------------------------------------------------------------------------------------------
	/*! \brief  Property (to be used by XAML): WinUI representation of the RNA
    *   \desc
    *   \date   08/22/2025  AGS Start
    */
    //  ------------------------------------------------------------------------------------------------------

    winrt::How2_PartII_DataTemplateSelector::clWinUIRNA MainWindow::GetWinUIRNA_Window_Property()
    {
        return  this->m_WinUIRNA;
    }


}
