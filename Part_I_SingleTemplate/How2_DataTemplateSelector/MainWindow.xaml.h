#pragma once

#include    "clWinUIRNA.h"
#include    "clWinUIControl_RNAList.h"

#include "MainWindow.g.h"

//#include "./Biochemistry/RNA.h"

namespace winrt::How2_DataTemplateSelector::implementation
{
    struct MainWindow : MainWindowT<MainWindow>
    {
        MainWindow();
		~MainWindow();

        winrt::How2_DataTemplateSelector::clWinUIRNA GetWinUIRNA_Window_Property();

    private:
//		std::unique_ptr<clRNA> m_upRNA=nullptr;

        winrt::How2_DataTemplateSelector::clWinUIRNA  m_WinUIRNA;
    };
}

namespace winrt::How2_DataTemplateSelector::factory_implementation
{
    struct MainWindow : MainWindowT<MainWindow, implementation::MainWindow>
    {
    };
}
