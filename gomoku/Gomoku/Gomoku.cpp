#include "pch.h"
#include "GUI.h"

using namespace Gomoku;

int main(array<System::String ^> ^args)
{
	Application::EnableVisualStyles();
	GUI^ form = gcnew GUI();
	Application::Run(form);
	return 0;
}
