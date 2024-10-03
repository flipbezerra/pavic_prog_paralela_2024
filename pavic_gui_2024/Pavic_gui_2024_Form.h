#pragma once
#include <cmath>
#include <iostream>
#include <chrono>


namespace pavicgui2024 {
//#include "include/Diagnostic.h"



	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std; // Assuming Diagnostics is in the std namespace

	/// <summary>
	/// Summary for Pavic_gui_2024_Form
	/// </summary>
	public ref class Pavic_gui_2024_Form : public System::Windows::Forms::Form
	{
	public:
		Pavic_gui_2024_Form(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Pavic_gui_2024_Form()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ bt_open;
	protected:
	private: System::Windows::Forms::Button^ bt_close;
	private: System::Windows::Forms::Button^ bt_exit;
	private: System::Windows::Forms::PictureBox^ pbox_input;
	private: System::Windows::Forms::PictureBox^ pbox_copy;
	private: System::Windows::Forms::PictureBox^ pbox_output;
	private: System::Windows::Forms::Button^ bt_copy;
	private: System::Windows::Forms::Button^ bt_filter_bw;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Button^ bt_close_copy;
	private: System::Windows::Forms::Button^ bt_close_output;

	private: System::Windows::Forms::Label^ label11;
	private: System::Windows::Forms::Label^ label12;
	private: System::Diagnostics::Stopwatch^ copyStopwatch;
	private: System::Diagnostics::Stopwatch^ filterStopwatch;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->bt_open = (gcnew System::Windows::Forms::Button());
			this->bt_close = (gcnew System::Windows::Forms::Button());
			this->bt_exit = (gcnew System::Windows::Forms::Button());
			this->pbox_input = (gcnew System::Windows::Forms::PictureBox());
			this->pbox_copy = (gcnew System::Windows::Forms::PictureBox());
			this->pbox_output = (gcnew System::Windows::Forms::PictureBox());
			this->bt_copy = (gcnew System::Windows::Forms::Button());
			this->bt_filter_bw = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->bt_close_copy = (gcnew System::Windows::Forms::Button());
			this->bt_close_output = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbox_input))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbox_copy))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbox_output))->BeginInit();
			this->SuspendLayout();
			// 
			// bt_open
			// 
			this->bt_open->Location = System::Drawing::Point(12, 12);
			this->bt_open->Name = L"bt_open";
			this->bt_open->Size = System::Drawing::Size(189, 45);
			this->bt_open->TabIndex = 0;
			this->bt_open->Text = L"Open";
			this->bt_open->UseVisualStyleBackColor = true;
			this->bt_open->Click += gcnew System::EventHandler(this, &Pavic_gui_2024_Form::bt_open_Click);
			// 
			// bt_close
			// 
			this->bt_close->Location = System::Drawing::Point(388, 236);
			this->bt_close->Name = L"bt_close";
			this->bt_close->Size = System::Drawing::Size(127, 35);
			this->bt_close->TabIndex = 1;
			this->bt_close->Text = L"Close";
			this->bt_close->UseVisualStyleBackColor = true;
			this->bt_close->Click += gcnew System::EventHandler(this, &Pavic_gui_2024_Form::bt_close_Click);
			// 
			// bt_exit
			// 
			this->bt_exit->Location = System::Drawing::Point(12, 216);
			this->bt_exit->Name = L"bt_exit";
			this->bt_exit->Size = System::Drawing::Size(189, 45);
			this->bt_exit->TabIndex = 2;
			this->bt_exit->Text = L"Exit";
			this->bt_exit->UseVisualStyleBackColor = true;
			this->bt_exit->Click += gcnew System::EventHandler(this, &Pavic_gui_2024_Form::bt_exit_Click);
			// 
			// pbox_input
			// 
			this->pbox_input->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->pbox_input->Location = System::Drawing::Point(17, 277);
			this->pbox_input->Name = L"pbox_input";
			this->pbox_input->Size = System::Drawing::Size(498, 407);
			this->pbox_input->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pbox_input->TabIndex = 3;
			this->pbox_input->TabStop = false;
			// 
			// pbox_copy
			// 
			this->pbox_copy->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->pbox_copy->Location = System::Drawing::Point(555, 277);
			this->pbox_copy->Name = L"pbox_copy";
			this->pbox_copy->Size = System::Drawing::Size(498, 407);
			this->pbox_copy->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pbox_copy->TabIndex = 4;
			this->pbox_copy->TabStop = false;
			// 
			// pbox_output
			// 
			this->pbox_output->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->pbox_output->Location = System::Drawing::Point(1087, 277);
			this->pbox_output->Name = L"pbox_output";
			this->pbox_output->Size = System::Drawing::Size(498, 407);
			this->pbox_output->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pbox_output->TabIndex = 5;
			this->pbox_output->TabStop = false;
			// 
			// bt_copy
			// 
			this->bt_copy->Location = System::Drawing::Point(12, 63);
			this->bt_copy->Name = L"bt_copy";
			this->bt_copy->Size = System::Drawing::Size(189, 45);
			this->bt_copy->TabIndex = 6;
			this->bt_copy->Text = L"Copy";
			this->bt_copy->UseVisualStyleBackColor = true;
			this->bt_copy->Click += gcnew System::EventHandler(this, &Pavic_gui_2024_Form::bt_copy_Click);
			// 
			// bt_filter_bw
			// 
			this->bt_filter_bw->Location = System::Drawing::Point(12, 114);
			this->bt_filter_bw->Name = L"bt_filter_bw";
			this->bt_filter_bw->Size = System::Drawing::Size(189, 45);
			this->bt_filter_bw->TabIndex = 7;
			this->bt_filter_bw->Text = L"Filter BW";
			this->bt_filter_bw->UseVisualStyleBackColor = true;
			this->bt_filter_bw->Click += gcnew System::EventHandler(this, &Pavic_gui_2024_Form::bt_filter_bw_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(1438, 709);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(158, 16);
			this->label1->TabIndex = 8;
			this->label1->Text = L" Felipe Bezerra Lima";
			// 
			// // 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(388, 709);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(158, 16);
			this->label11->TabIndex = 8;
			this->label11->Text = L"Teste";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(9, 709);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(111, 16);
			this->label2->TabIndex = 9;
			this->label2->Text = L" PAVIC LAB: 2024";
			// 
			// bt_close_copy
			// 
			this->bt_close_copy->Location = System::Drawing::Point(926, 236);
			this->bt_close_copy->Name = L"bt_close_copy";
			this->bt_close_copy->Size = System::Drawing::Size(127, 35);
			this->bt_close_copy->TabIndex = 10;
			this->bt_close_copy->Text = L"Close";
			this->bt_close_copy->UseVisualStyleBackColor = true;
			this->bt_close_copy->Click += gcnew System::EventHandler(this, &Pavic_gui_2024_Form::bt_close_copy_Click);
			// 
			// bt_close_output
			// 
			this->bt_close_output->Location = System::Drawing::Point(1458, 236);
			this->bt_close_output->Name = L"bt_close_output";
			this->bt_close_output->Size = System::Drawing::Size(127, 35);
			this->bt_close_output->TabIndex = 11;
			this->bt_close_output->Text = L"Close";
			this->bt_close_output->UseVisualStyleBackColor = true;
			this->bt_close_output->Click += gcnew System::EventHandler(this, &Pavic_gui_2024_Form::bt_close_output_Click);
			// 
			// Pavic_gui_2024_Form
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1608, 734);
			this->Controls->Add(this->bt_close_output);
			this->Controls->Add(this->bt_close_copy);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->label11);
			this->Controls->Add(this->bt_filter_bw);
			this->Controls->Add(this->bt_copy);
			this->Controls->Add(this->pbox_output);
			this->Controls->Add(this->pbox_copy);
			this->Controls->Add(this->pbox_input);
			this->Controls->Add(this->bt_exit);
			this->Controls->Add(this->bt_close);
			this->Controls->Add(this->bt_open);
			this->Name = L"Pavic_gui_2024_Form";
			this->Text = L"PROJECT: PAVIC LAB 2024";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbox_input))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbox_copy))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbox_output))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void bt_open_Click(System::Object^ sender, System::EventArgs^ e) {
		OpenFileDialog^ ofd = gcnew OpenFileDialog();
		if (ofd->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			pbox_input->ImageLocation = ofd->FileName;
		}
	}
private: System::Void bt_close_Click(System::Object^ sender, System::EventArgs^ e) {

	pbox_input->Image = nullptr;

	
}
private: System::Void bt_copy_Click(System::Object^ sender, System::EventArgs^ e) {
	//copyStopwatch = gcnew System::Diagnostics.Stopwatch();
	//copyStopwatch->Start();

	/*pbox_copy->Image = pbox_input->Image;*/

	//copyStopwatch->Stop();
	//label11->Text = "Tempo de cópia: " + duration_single_thread.count() + " ms";

	// Obtém a imagem de entrada
	Bitmap^ inputImage = (Bitmap^)pbox_input->Image;

	int width = inputImage->Width;
	int height = inputImage->Height;

	// Inicia o timer
	auto start_single_thread = std::chrono::high_resolution_clock::now();
	// Cria um bitmap para a imagem de saída
	Bitmap^ outputImage = gcnew Bitmap(width, height);

	// Itera por cada pixel na imagem de entrada
	for (int x = 0; x < width; x++) {
		for (int y = 0; y < height; y++) {
			// Obtém a cor do pixel atual
			Color pixelColor = inputImage->GetPixel(x, y);

			// Copia os valores RGB
			int red = pixelColor.R;
			int green = pixelColor.G;
			int blue = pixelColor.B;

			//// Aplica o filtro azul
			//blue += 100;
			//if (blue > 255) {
			//	blue = 255;
			//}

			// Atribui o valor do pixel na imagem de saída
			outputImage->SetPixel(x, y, Color::FromArgb(red, green, blue));
		}
	}
	// Para o timer
	auto stop_single_thread = std::chrono::high_resolution_clock::now();
	// Registra o tempo do timer em milisegundos
	auto duration_single_thread = std::chrono::duration_cast<std::chrono::milliseconds>(stop_single_thread - start_single_thread);
	label11->Text = "Tempo de cópia: " + duration_single_thread.count() + " ms";

	// Exibe a imagem de saída
	pbox_copy->Image = outputImage;

}
private: System::Void bt_filter_bw_Click(System::Object^ sender, System::EventArgs^ e) {

	// Obtém a imagem de entrada
	Bitmap^ inputImage = (Bitmap^)pbox_input->Image;

	// Inicia o timer
	auto start_single_thread = std::chrono::high_resolution_clock::now();
	// Cria um bitmap para a imagem de saída
	Bitmap^ outputImage = gcnew Bitmap(inputImage->Width, inputImage->Height);

	// Aplica o filtro preto e branco
	for (int i = 0; i < inputImage->Width; i++) {
		for (int j = 0; j < inputImage->Height; j++) {
			Color pixelColor = inputImage->GetPixel(i, j);
			int grayValue = (int)(0.299 * pixelColor.R + 0.587 * pixelColor.G + 0.114 * pixelColor.B);
			outputImage->SetPixel(i, j, Color::FromArgb(grayValue, grayValue, grayValue));
		}
	}
	// Para o timer
	auto stop_single_thread = std::chrono::high_resolution_clock::now();
	// Registra o tempo do timer em milisegundos
	auto duration_single_thread = std::chrono::duration_cast<std::chrono::milliseconds>(stop_single_thread - start_single_thread);
	label11->Text = "Tempo de filtro: " + duration_single_thread.count() + " ms";

	// Exibe a imagem de saída
	pbox_output->Image = outputImage;
}
private: System::Void bt_exit_Click(System::Object^ sender, System::EventArgs^ e) {
	Application::Exit();
}
private: System::Void bt_close_copy_Click(System::Object^ sender, System::EventArgs^ e) {
	pbox_copy->Image = nullptr;
	
}
private: System::Void bt_close_output_Click(System::Object^ sender, System::EventArgs^ e) {
	pbox_output->Image = nullptr;
}
};
}
