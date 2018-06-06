// OpenGL_on_a_Windows_Form.cpp : main project file.
#include "stdafx.h"
#include "Form1.h"

using namespace OpenGL_on_a_Windows_Form;

[STAThread]
int main(cli::array<System::String ^>^args)
{
	// Enabling Windows XP visual effects before any controls are created
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false); 

	// Create the main window and run it
	Application::Run(gcnew Form1);
	return 0;
}


// a workaround from stackoverflow 
//https://stackoverflow.com/questions/35575805/afxwin-h-issues-in-visual-studio-2015-windows-form-app
// wasted a huge mt of time on assertion fail.
class MyMfcApp:public CWinApp {
public:
	virtual int Run() override {
		return main(__nullptr);
	}
} MyApp;