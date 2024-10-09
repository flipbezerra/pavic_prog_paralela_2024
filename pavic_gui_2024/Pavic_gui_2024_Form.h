#pragma once
#include <cmath>
#include <iostream>
#include <chrono>
#include <thread>
#include <vector>
#include <Windows.h>


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

	private: System::Windows::Forms::PictureBox^ pbox_output;

	private: System::Windows::Forms::Button^ bt_filter_bw;

	private: System::Windows::Forms::Button^ bt_parallel_bw;

	private: System::Windows::Forms::Label^ label2;

	private: System::Windows::Forms::Button^ bt_close_output;

	private: System::Windows::Forms::Label^ label11;
	private: System::Windows::Forms::Label^ label12;
	private: System::Diagnostics::Stopwatch^ copyStopwatch;
	private: System::Diagnostics::Stopwatch^ filterStopwatch;
	private: System::Windows::Forms::Button^ bt_filter_invert;
	private: System::Windows::Forms::Button^ filter_blur;
	private: System::Windows::Forms::Button^ parallel_blur;
	private: System::Windows::Forms::ProgressBar^ progressBar;
	private: System::Windows::Forms::Timer^ timer1;
	private: System::Windows::Forms::Timer^ timer2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::GroupBox^ groupBox2;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button1;


	private: System::ComponentModel::IContainer^ components;


	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->bt_open = (gcnew System::Windows::Forms::Button());
			this->bt_close = (gcnew System::Windows::Forms::Button());
			this->bt_exit = (gcnew System::Windows::Forms::Button());
			this->pbox_input = (gcnew System::Windows::Forms::PictureBox());
			this->pbox_output = (gcnew System::Windows::Forms::PictureBox());
			this->bt_filter_bw = (gcnew System::Windows::Forms::Button());
			this->bt_parallel_bw = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->bt_close_output = (gcnew System::Windows::Forms::Button());
			this->bt_filter_invert = (gcnew System::Windows::Forms::Button());
			this->filter_blur = (gcnew System::Windows::Forms::Button());
			this->parallel_blur = (gcnew System::Windows::Forms::Button());
			this->trackbar_intensity = (gcnew System::Windows::Forms::TrackBar());
			this->progressBar = (gcnew System::Windows::Forms::ProgressBar());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->timer2 = (gcnew System::Windows::Forms::Timer(this->components));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbox_input))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbox_output))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackbar_intensity))->BeginInit();
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->SuspendLayout();
			// 
			// bt_open
			// 
			this->bt_open->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->bt_open->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->bt_open->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->bt_open->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->bt_open->ForeColor = System::Drawing::Color::White;
			this->bt_open->Location = System::Drawing::Point(57, 378);
			this->bt_open->Name = L"bt_open";
			this->bt_open->Size = System::Drawing::Size(216, 56);
			this->bt_open->TabIndex = 0;
			this->bt_open->Text = L"Abrir Imagem";
			this->bt_open->UseVisualStyleBackColor = false;
			this->bt_open->Click += gcnew System::EventHandler(this, &Pavic_gui_2024_Form::bt_open_Click);
			// 
			// bt_close
			// 
			this->bt_close->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->bt_close->Location = System::Drawing::Point(345, 226);
			this->bt_close->Name = L"bt_close";
			this->bt_close->Size = System::Drawing::Size(127, 35);
			this->bt_close->TabIndex = 1;
			this->bt_close->Text = L"Limpar";
			this->bt_close->UseVisualStyleBackColor = true;
			this->bt_close->Click += gcnew System::EventHandler(this, &Pavic_gui_2024_Form::bt_close_Click);
			// 
			// bt_exit
			// 
			this->bt_exit->BackColor = System::Drawing::Color::RosyBrown;
			this->bt_exit->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->bt_exit->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->bt_exit->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->bt_exit->Location = System::Drawing::Point(57, 469);
			this->bt_exit->Name = L"bt_exit";
			this->bt_exit->Size = System::Drawing::Size(216, 56);
			this->bt_exit->TabIndex = 2;
			this->bt_exit->Text = L"Sair";
			this->bt_exit->UseVisualStyleBackColor = false;
			this->bt_exit->Click += gcnew System::EventHandler(this, &Pavic_gui_2024_Form::bt_exit_Click);
			// 
			// pbox_input
			// 
			this->pbox_input->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pbox_input->Location = System::Drawing::Point(345, 277);
			this->pbox_input->Name = L"pbox_input";
			this->pbox_input->Size = System::Drawing::Size(498, 407);
			this->pbox_input->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pbox_input->TabIndex = 3;
			this->pbox_input->TabStop = false;
			this->pbox_input->Click += gcnew System::EventHandler(this, &Pavic_gui_2024_Form::pbox_input_Click);
			// 
			// pbox_output
			// 
			this->pbox_output->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pbox_output->Location = System::Drawing::Point(870, 277);
			this->pbox_output->Name = L"pbox_output";
			this->pbox_output->Size = System::Drawing::Size(498, 407);
			this->pbox_output->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pbox_output->TabIndex = 4;
			this->pbox_output->TabStop = false;
			// 
			// bt_filter_bw
			// 
			this->bt_filter_bw->Location = System::Drawing::Point(27, 21);
			this->bt_filter_bw->Name = L"bt_filter_bw";
			this->bt_filter_bw->Size = System::Drawing::Size(189, 45);
			this->bt_filter_bw->TabIndex = 5;
			this->bt_filter_bw->Text = L"Preto e Branco";
			this->bt_filter_bw->UseVisualStyleBackColor = true;
			this->bt_filter_bw->Click += gcnew System::EventHandler(this, &Pavic_gui_2024_Form::bt_paralel_bw_Click);
			// 
			// bt_parallel_bw
			// 
			this->bt_parallel_bw->Location = System::Drawing::Point(0, 0);
			this->bt_parallel_bw->Name = L"bt_parallel_bw";
			this->bt_parallel_bw->Size = System::Drawing::Size(75, 23);
			this->bt_parallel_bw->TabIndex = 6;
			this->bt_parallel_bw->Text = L"Preto e Branco (Paralelismo)";
			this->bt_parallel_bw->UseVisualStyleBackColor = true;
			this->bt_parallel_bw->Click += gcnew System::EventHandler(this, &Pavic_gui_2024_Form::bt_paralel_bw_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(26, 709);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(111, 16);
			this->label2->TabIndex = 8;
			this->label2->Text = L" PAVIC LAB: 2024";
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(555, 709);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(0, 16);
			this->label11->TabIndex = 9;
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Location = System::Drawing::Point(1087, 709);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(0, 16);
			this->label12->TabIndex = 10;
			// 
			// bt_close_output
			// 
			this->bt_close_output->Location = System::Drawing::Point(870, 236);
			this->bt_close_output->Name = L"bt_close_output";
			this->bt_close_output->Size = System::Drawing::Size(127, 35);
			this->bt_close_output->TabIndex = 11;
			this->bt_close_output->Text = L"Limpar";
			this->bt_close_output->UseVisualStyleBackColor = true;
			this->bt_close_output->Click += gcnew System::EventHandler(this, &Pavic_gui_2024_Form::bt_close_output_Click);
			// 
			// bt_filter_invert
			// 
			this->bt_filter_invert->Location = System::Drawing::Point(13, 24);
			this->bt_filter_invert->Name = L"bt_filter_invert";
			this->bt_filter_invert->Size = System::Drawing::Size(189, 45);
			this->bt_filter_invert->TabIndex = 12;
			this->bt_filter_invert->Text = L"Inverter Cores";
			this->bt_filter_invert->UseVisualStyleBackColor = true;
			this->bt_filter_invert->Click += gcnew System::EventHandler(this, &Pavic_gui_2024_Form::button1_Click);
			// 
			// filter_blur
			// 
			this->filter_blur->Location = System::Drawing::Point(232, 21);
			this->filter_blur->Name = L"filter_blur";
			this->filter_blur->Size = System::Drawing::Size(189, 45);
			this->filter_blur->TabIndex = 13;
			this->filter_blur->Text = L"Filtro Borrar";
			this->filter_blur->UseVisualStyleBackColor = true;
			this->filter_blur->Click += gcnew System::EventHandler(this, &Pavic_gui_2024_Form::filter_blur_Click);
			// 
			// parallel_blur
			// 
			this->parallel_blur->Location = System::Drawing::Point(232, 72);
			this->parallel_blur->Name = L"parallel_blur";
			this->parallel_blur->Size = System::Drawing::Size(189, 45);
			this->parallel_blur->TabIndex = 7;
			this->parallel_blur->Text = L"Filtro Borrar (Paralelismo)";
			this->parallel_blur->UseVisualStyleBackColor = true;
			this->parallel_blur->Click += gcnew System::EventHandler(this, &Pavic_gui_2024_Form::parallel_blur_Click);
			// 
			// trackbar_intensity
			// 
			this->trackbar_intensity->Location = System::Drawing::Point(81, 134);
			this->trackbar_intensity->Maximum = 100;
			this->trackbar_intensity->Name = L"trackbar_intensity";
			this->trackbar_intensity->Size = System::Drawing::Size(287, 56);
			this->trackbar_intensity->TabIndex = 14;
			this->trackbar_intensity->TickFrequency = 10;
			this->trackbar_intensity->Value = 100;
			this->trackbar_intensity->Scroll += gcnew System::EventHandler(this, &Pavic_gui_2024_Form::trackbar_intensity_Scroll);
			// 
			// progressBar
			// 
			this->progressBar->Location = System::Drawing::Point(870, 689);
			this->progressBar->Name = L"progressBar";
			this->progressBar->Size = System::Drawing::Size(498, 17);
			this->progressBar->Step = 1;
			this->progressBar->TabIndex = 15;
			// 
			// timer2
			// 
			this->timer2->Tick += gcnew System::EventHandler(this, &Pavic_gui_2024_Form::timer2_Tick);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(154, 170);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(149, 16);
			this->label1->TabIndex = 16;
			this->label1->Text = L"Intensidade do Filtro";
			this->label1->Click += gcnew System::EventHandler(this, &Pavic_gui_2024_Form::label1_Click);
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->button2);
			this->groupBox1->Controls->Add(this->button1);
			this->groupBox1->Controls->Add(this->bt_filter_bw);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Controls->Add(this->filter_blur);
			this->groupBox1->Controls->Add(this->trackbar_intensity);
			this->groupBox1->Location = System::Drawing::Point(742, 34);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(472, 196);
			this->groupBox1->TabIndex = 17;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Filtros Ajustaveis";
			this->groupBox1->Enter += gcnew System::EventHandler(this, &Pavic_gui_2024_Form::groupBox1_Enter);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(232, 78);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(189, 45);
			this->button2->TabIndex = 20;
			this->button2->Text = L"Filtro Borrar (PP)";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Pavic_gui_2024_Form::button2_Click);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(27, 78);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(189, 45);
			this->button1->TabIndex = 19;
			this->button1->Text = L"Preto e Branco (PP)";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Pavic_gui_2024_Form::button1_Click_1);
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->bt_filter_invert);
			this->groupBox2->Location = System::Drawing::Point(414, 74);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(214, 83);
			this->groupBox2->TabIndex = 18;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Filtros Fixos";
			// 
			// Pavic_gui_2024_Form
			// 
			this->AcceptButton = this->bt_open;
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->CancelButton = this->bt_close;
			this->ClientSize = System::Drawing::Size(1401, 775);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->bt_close_output);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label11);
			this->Controls->Add(this->label12);
			this->Controls->Add(this->pbox_output);
			this->Controls->Add(this->pbox_input);
			this->Controls->Add(this->bt_exit);
			this->Controls->Add(this->bt_close);
			this->Controls->Add(this->bt_open);
			this->Controls->Add(this->progressBar);
			this->Name = L"Pavic_gui_2024_Form";
			this->ShowIcon = false;
			this->ShowInTaskbar = false;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"PROJECT: PAVIC LAB 2024";
			this->Load += gcnew System::EventHandler(this, &Pavic_gui_2024_Form::Pavic_gui_2024_Form_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbox_input))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbox_output))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackbar_intensity))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private: System::Windows::Forms::TrackBar^ trackbar_intensity;
private: System::Void bt_open_Click(System::Object^ sender, System::EventArgs^ e) {
		OpenFileDialog^ ofd = gcnew OpenFileDialog();
		if (ofd->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			pbox_input->ImageLocation = ofd->FileName;
		}
	}
private: System::Void bt_close_Click(System::Object^ sender, System::EventArgs^ e) {

	pbox_input->Image = nullptr;

	
}

private: System::Void bt_filter_bw_Click(System::Object^ sender, System::EventArgs^ e) {
	Bitmap^ inputImage = (Bitmap^)pbox_input->Image;
	Bitmap^ outputImage = gcnew Bitmap(inputImage->Width, inputImage->Height);
	int intensity = trackbar_intensity->Value;

	// Configura a ProgressBar para o número total de pixels a serem processados
	int total_pixels = inputImage->Width * inputImage->Height;
	this->progressBar->Maximum = total_pixels;
	this->progressBar->Value = 0;  // Reinicia o valor da barra

	auto start_time = std::chrono::high_resolution_clock::now();

	// Processa a imagem inteira para aplicar o filtro preto e branco com intensidade
	for (int x = 0; x < inputImage->Width; x++) {
		for (int y = 0; y < inputImage->Height; y++) {
			Color pixelColor = inputImage->GetPixel(x, y);
			int grayValue = (int)(0.299 * pixelColor.R + 0.587 * pixelColor.G + 0.114 * pixelColor.B);

			int red = pixelColor.R + ((grayValue - pixelColor.R) * intensity) / 100;
			int green = pixelColor.G + ((grayValue - pixelColor.G) * intensity) / 100;
			int blue = pixelColor.B + ((grayValue - pixelColor.B) * intensity) / 100;

			outputImage->SetPixel(x, y, Color::FromArgb(red, green, blue));

			// Atualiza o progresso
			this->progressBar->PerformStep();
		}
	}

	auto end_time = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);
	label12->Text = "Black and White filter time: " + duration.count() + " ms";

	pbox_output->Image = outputImage;
}

//Paralelo
 
private: System::Void bt_paralel_bw_Click(System::Object^ sender, System::EventArgs^ e) {
	Bitmap^ inputImage = (Bitmap^)pbox_input->Image;
	Bitmap^ outputImage = gcnew Bitmap(inputImage->Width, inputImage->Height);
	int intensity = trackbar_intensity->Value;

	// Set ProgressBar for total pixels
	int total_pixels = inputImage->Width * inputImage->Height;
	this->progressBar->Maximum = total_pixels;
	this->progressBar->Value = 0;

	auto start_time = std::chrono::high_resolution_clock::now();

	#pragma omp parallel for
	for (int x = 0; x < inputImage->Width; x++) {
		for (int y = 0; y < inputImage->Height; y++) {
			Color pixelColor = inputImage->GetPixel(x, y);
			int grayValue = (int)(0.299 * pixelColor.R + 0.587 * pixelColor.G + 0.114 * pixelColor.B);

			int red = pixelColor.R + ((grayValue - pixelColor.R) * intensity) / 100;
			int green = pixelColor.G + ((grayValue - pixelColor.G) * intensity) / 100;
			int blue = pixelColor.B + ((grayValue - pixelColor.B) * intensity) / 100;

			#pragma omp critical
			{
				outputImage->SetPixel(x, y, Color::FromArgb(red, green, blue));
				this->progressBar->PerformStep();
			}
		}
	}

	auto end_time = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);
	label12->Text = "Black and White filter time: " + duration.count() + " ms";

	pbox_output->Image = outputImage;
}
//#pragma omp parallel for parallelizes the outer for loop.
//#pragma omp critical is used to ensure that outputImage->SetPixel and progressBar->PerformStep are thread-safe, as multiple threads cannot access them simultaneously without synchronization.


private: System::Void bt_exit_Click(System::Object^ sender, System::EventArgs^ e) {
	Application::Exit();
}

private: System::Void bt_close_output_Click(System::Object^ sender, System::EventArgs^ e) {
	pbox_output->Image = nullptr;
}
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	Bitmap^ inputImage = (Bitmap^)pbox_input->Image;
	Bitmap^ outputImage = gcnew Bitmap(inputImage->Width, inputImage->Height);

	auto start_time = std::chrono::high_resolution_clock::now();

	for (int i = 0; i < inputImage->Width; i++) {
		for (int j = 0; j < inputImage->Height; j++) {
			Color pixelColor = inputImage->GetPixel(i, j);
			int red = 255 - pixelColor.R;
			int green = 255 - pixelColor.G;
			int blue = 255 - pixelColor.B;
			outputImage->SetPixel(i, j, Color::FromArgb(red, green, blue));
		}
	}

	auto end_time = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);
	label12->Text = "Invert filter time: " + duration.count() + " ms";

	pbox_output->Image = outputImage;
}

private: System::Void filter_blur_Click(System::Object^ sender, System::EventArgs^ e) {
	Bitmap^ inputImage = (Bitmap^)pbox_input->Image;
	Bitmap^ outputImage = gcnew Bitmap(inputImage->Width, inputImage->Height);
	int intensity = trackbar_intensity->Value;

	// Defina o número de iterações com base na intensidade
	int iterations = intensity / 10; // Aumenta o número de iterações de acordo com a intensidade
	if (iterations < 1) iterations = 1; // Garante ao menos 1 iteração

	// Configura a ProgressBar para o número total de pixels a serem processados
	int total_pixels = inputImage->Width * inputImage->Height * iterations;
	this->progressBar->Maximum = total_pixels;
	this->progressBar->Value = 0;  // Reinicia o valor da barra

	auto start_time = std::chrono::high_resolution_clock::now();

	for (int iter = 0; iter < iterations; iter++) {
		for (int x = 0; x < inputImage->Width; x++) {
			for (int y = 0; y < inputImage->Height; y++) {
				int red = 0, green = 0, blue = 0;
				int count = 0;

				// Ajusta o tamanho do kernel com base na intensidade
				int kernel_size = (intensity / 20) + 1;
				int half_kernel = kernel_size / 2;

				for (int i = -half_kernel; i <= half_kernel; i++) {
					for (int j = -half_kernel; j <= half_kernel; j++) {
						int neighbor_x = x + i;
						int neighbor_y = y + j;

						// Verifica se o pixel vizinho está dentro dos limites da imagem
						if (neighbor_x >= 0 && neighbor_x < inputImage->Width && neighbor_y >= 0 && neighbor_y < inputImage->Height) {
							Color pixelColor = inputImage->GetPixel(neighbor_x, neighbor_y);
							red += pixelColor.R;
							green += pixelColor.G;
							blue += pixelColor.B;
							count++;
						}
					}
				}

				red /= count;
				green /= count;
				blue /= count;
				outputImage->SetPixel(x, y, Color::FromArgb(red, green, blue));

				// Atualiza o progresso da progressbar
				this->progressBar->PerformStep();
			}
		}

		// Após a primeira iteração, use a imagem de saída como entrada para a próxima
		inputImage = outputImage;
	}

	auto end_time = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);
	label12->Text = "Blur filter time: " + duration.count() + " ms";

	pbox_output->Image = outputImage;
}

private: System::Void parallel_blur_Click(System::Object^ sender, System::EventArgs^ e) {
	Bitmap^ inputImage = (Bitmap^)pbox_input->Image;
	Bitmap^ outputImage = gcnew Bitmap(inputImage->Width, inputImage->Height);
	int intensity = trackbar_intensity->Value;

	// Define the number of iterations based on the intensity
	int iterations = intensity / 10;
	if (iterations < 1) iterations = 1;

	int total_pixels = inputImage->Width * inputImage->Height * iterations;
	this->progressBar->Maximum = total_pixels;
	this->progressBar->Value = 0;

	auto start_time = std::chrono::high_resolution_clock::now();

	// Parallel loop with OpenMP
	for (int iter = 0; iter < iterations; iter++) {
		#pragma omp parallel for // This directive makes the loop parallel
		for (int x = 0; x < inputImage->Width; x++) {
			for (int y = 0; y < inputImage->Height; y++) {
				int red = 0, green = 0, blue = 0;
				int count = 0;

				int kernel_size = (intensity / 20) + 1;
				int half_kernel = kernel_size / 2;

				// Blur filter kernel computation
				for (int i = -half_kernel; i <= half_kernel; i++) {
					for (int j = -half_kernel; j <= half_kernel; j++) {
						int neighbor_x = x + i;
						int neighbor_y = y + j;

						if (neighbor_x >= 0 && neighbor_x < inputImage->Width && neighbor_y >= 0 && neighbor_y < inputImage->Height) {
							Color pixelColor = inputImage->GetPixel(neighbor_x, neighbor_y);
							red += pixelColor.R;
							green += pixelColor.G;
							blue += pixelColor.B;
							count++;
						}
					}
				}

				red /= count;
				green /= count;
				blue /= count;

				// Set the processed pixel
				outputImage->SetPixel(x, y, Color::FromArgb(red, green, blue));

				// Update progress bar safely (synchronized section)
				#pragma omp critical 
				{
					this->progressBar->PerformStep();
				}
			}
		}
		// Use the output image as the input for the next iteration
		inputImage = outputImage;
	}

	auto end_time = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);
	label12->Text = "Blur filter time: " + duration.count() + " ms";

	pbox_output->Image = outputImage;
}


private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void groupBox1_Enter(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void pbox_input_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void timer2_Tick(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void Pavic_gui_2024_Form_Load(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void button1_Click_1(System::Object^ sender, System::EventArgs^ e) {
	Bitmap^ inputImage = (Bitmap^)pbox_input->Image;
	Bitmap^ outputImage = gcnew Bitmap(inputImage->Width, inputImage->Height);
	int intensity = trackbar_intensity->Value;

	// Set ProgressBar for total pixels
	int total_pixels = inputImage->Width * inputImage->Height;
	this->progressBar->Maximum = total_pixels;
	this->progressBar->Value = 0;

	auto start_time = std::chrono::high_resolution_clock::now();

#pragma omp parallel for
	for (int x = 0; x < inputImage->Width; x++) {
		for (int y = 0; y < inputImage->Height; y++) {
			Color pixelColor = inputImage->GetPixel(x, y);
			int grayValue = (int)(0.299 * pixelColor.R + 0.587 * pixelColor.G + 0.114 * pixelColor.B);

			int red = pixelColor.R + ((grayValue - pixelColor.R) * intensity) / 100;
			int green = pixelColor.G + ((grayValue - pixelColor.G) * intensity) / 100;
			int blue = pixelColor.B + ((grayValue - pixelColor.B) * intensity) / 100;

#pragma omp critical
			{
				outputImage->SetPixel(x, y, Color::FromArgb(red, green, blue));
				this->progressBar->PerformStep();
			}
		}
	}

	auto end_time = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);
	label12->Text = "Black and White filter time: " + duration.count() + " ms";

	pbox_output->Image = outputImage;
}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	Bitmap^ inputImage = (Bitmap^)pbox_input->Image;
	Bitmap^ outputImage = gcnew Bitmap(inputImage->Width, inputImage->Height);
	int intensity = trackbar_intensity->Value;

	// Define the number of iterations based on the intensity
	int iterations = intensity / 10;
	if (iterations < 1) iterations = 1;

	int total_pixels = inputImage->Width * inputImage->Height * iterations;
	this->progressBar->Maximum = total_pixels;
	this->progressBar->Value = 0;

	auto start_time = std::chrono::high_resolution_clock::now();

	// Parallel loop with OpenMP
	for (int iter = 0; iter < iterations; iter++) {
	#pragma omp parallel for // This directive makes the loop parallel
		for (int x = 0; x < inputImage->Width; x++) {
			for (int y = 0; y < inputImage->Height; y++) {
				int red = 0, green = 0, blue = 0;
				int count = 0;

				int kernel_size = (intensity / 20) + 1;
				int half_kernel = kernel_size / 2;

				// Blur filter kernel computation
				for (int i = -half_kernel; i <= half_kernel; i++) {
					for (int j = -half_kernel; j <= half_kernel; j++) {
						int neighbor_x = x + i;
						int neighbor_y = y + j;

						if (neighbor_x >= 0 && neighbor_x < inputImage->Width && neighbor_y >= 0 && neighbor_y < inputImage->Height) {
							Color pixelColor = inputImage->GetPixel(neighbor_x, neighbor_y);
							red += pixelColor.R;
							green += pixelColor.G;
							blue += pixelColor.B;
							count++;
						}
					}
				}

				red /= count;
				green /= count;
				blue /= count;

				// Set the processed pixel
				outputImage->SetPixel(x, y, Color::FromArgb(red, green, blue));

				// Update progress bar safely (synchronized section)
#pragma omp critical 
				{
					this->progressBar->PerformStep();
				}
			}
		}
		// Use the output image as the input for the next iteration
		inputImage = outputImage;
	}

	auto end_time = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);
	label12->Text = "Blur filter time: " + duration.count() + " ms";

	pbox_output->Image = outputImage;
}
private: System::Void trackbar_intensity_Scroll(System::Object^ sender, System::EventArgs^ e) {
}
};

}
