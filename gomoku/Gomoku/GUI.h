#pragma once
#include "Gomoku.h";

namespace Gomoku {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// GUI 摘要
	/// </summary>
	public ref class GUI : public System::Windows::Forms::Form
	{
	public:
		GUI(void)
		{
			InitializeComponent();
			//
			//TODO:  在此处添加构造函数代码
			//
		}

	protected:
		/// <summary>
		/// 清理所有正在使用的资源。
		/// </summary>
		~GUI()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		/// <summary>
		/// 必需的设计器变量。
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// 设计器支持所需的方法 - 不要修改
		/// 使用代码编辑器修改此方法的内容。
		/// </summary>
		void InitializeComponent(void)
		{
			this->SuspendLayout();
			// 
			// GUI
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(740, 676);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->Name = L"GUI";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"GUI";
			this->Load += gcnew System::EventHandler(this, &GUI::GUI_Load);
			this->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &GUI::GUI_Paint);
			this->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &GUI::GUI_MouseUp);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: int hsp;
	private: int wsp;
	private:int tempX, tempY;
	private:int lock = false;
	private: System::Void GUI_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		Console::WriteLine(String::Format("GUI-CLICK: X:{0};Y:{1}", e->X, e->Y));
		int x = e->X;
		int y = e->Y;
		int px = -1, py = -1;
		int threshold = 8;
		bool x0 = x % (wsp) <= threshold,
			x1 = x % (wsp) >= wsp - threshold,
			y0 = y % (hsp) <= threshold,
			y1 = y % (hsp) >= hsp - threshold;
		if ((x0 || x1) && (y0 || y1)) {
			if (x0) {
				px = x / (wsp);
			}
			else {
				px = x / (wsp)+1;
			}
			if (y0) {
				py = y / (hsp);
			}
			else {
				py = y / (hsp)+1;
			}
		}
		if (px > 0 && py > 0) {
			Console::WriteLine(String::Format("GUI: Player clicked the point X:{0};Y:{1}", px, py));
			PutChess(px, py);
		}
	}
	private: System::Void GUI_Load(System::Object^ sender, System::EventArgs^ e) {
		evaluateInit();
		GUI::Width = 606;
		GUI::Height = 630;
		tempX = -1;
		tempY = -1;
	}
	private: System::Void GUI_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
		Console::WriteLine("GUI: Size Width:" + this->Width + ";Height:" + this->Height);
		hsp = (600 - WIDTH * 2) / (WIDTH + 1) + 2;
		wsp = (600 - WIDTH * 2) / (WIDTH + 1) + 2;
		Console::WriteLine(String::Format("GUI: drawBoard hsp:{0};wsp:{1}", hsp, wsp));
		DrawBoard(e->Graphics);
		if (!lock) {
			lock = true;
			//PutChess(8, 6);
		}
	}
	private: System::Void DrawBoard(Graphics^ g) {

		Pen^ p = gcnew Pen(Color::Black, 2);
		g->Clear(Color::LightGray);
		for (int i = 1; i <= WIDTH; i++) {
			g->DrawLine(p, (float)0, (float)(i * hsp), (float)this->Width, (float)(i * hsp));
		}
		for (int i = 1; i <= WIDTH; i++) {
			g->DrawLine(p, (float)(i * wsp), (float)0, (float)(i * wsp), (float)this->Height);
		}
	}
	private:System::Void PutChess(int px, int py) {
		setChessboard(px - 1, py - 1, PLAYER);
		DrawPoint(0, px, py);
		if (CheckIsWin() ==EMPTY) {
			GetComputerPoint(px - 1, py - 1);
		}
	}
	private: System::Void DrawPoint(int pointType, int x, int y) {
		int px = wsp * x - 10, py = hsp * y - 10;
		Graphics^ g = GUI::CreateGraphics();
		g->SmoothingMode = Drawing::Drawing2D::SmoothingMode::AntiAlias;
		SolidBrush^ sb;
		if (pointType == 0) {
			sb = gcnew SolidBrush(Color::FromArgb(255, 236, 240, 241));
			if (tempX != -1) {
				g->FillEllipse(sb, tempX, tempY, 20, 20);
				tempX = -1;
			}
			sb = gcnew SolidBrush(Color::Black);
			g->FillEllipse(sb, px, py, 20, 20);
		}
		else {
			sb = gcnew SolidBrush(Color::White);
			tempX = px;
			tempY = py;
			g->FillEllipse(sb, px, py, 20, 20);
		}
		


	}
	private: System::Void GetComputerPoint(int x, int y) {
		int cX = 0, cY = 0;
		getStep(x, y, &cX, &cY);
		setChessboard(cX, cY, COMPUTER);
		Console::WriteLine(String::Format("GUI: Computer put the point X:{0};Y:{1}", cX, cY));
		DrawPoint(1, cX + 1, cY + 1);
		for (int i = 0; i < WIDTH; i++) {
			for (int c = 0; c < WIDTH; c++) {
				printf("%c", getChessboard(c, i));
			}
			printf("\n");
		}
		CheckIsWin();
	}
	private: char CheckIsWin() {
		char status = getBoardStatus();
		if (status == PLAYER) {
			MessageBox::Show("玩家获得胜利！");
		}
		else if (status == COMPUTER) {
			MessageBox::Show("电脑获得胜利！");
		}
		else if (status == DRAW) {
			MessageBox::Show("流局！");
		}
		if (status!=EMPTY) {
			reload();
		}

		return status;
	}
	private: System::Void reload() {
		tempX = -1;
		DrawBoard(GUI::CreateGraphics());
		reloadGame();
	}
	};
}
