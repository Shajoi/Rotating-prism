#define _USE_MATH_DEFINES
#include <math.h> 
#pragma once

namespace Kursprizma {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Windows::Forms;
    using namespace System::Drawing;

    public ref class Prizma : public System::Windows::Forms::Form
    {
    private:
        System::Windows::Forms::Timer^ timer1;
        System::Windows::Forms::Button^ buttonColor;
        System::Windows::Forms::TrackBar^ trackBarScale;
        System::Windows::Forms::TrackBar^ trackBarSpeed;
        System::Windows::Forms::CheckBox^ checkBoxX;
        System::Windows::Forms::CheckBox^ checkBoxY;
        System::Windows::Forms::Label^ labelScale;
        System::Windows::Forms::Label^ labelSpeed;
        Color start_Color;
        float angleX, angleY;
        float scaleFactor;
        float rotationSpeed;

    public:
        Prizma(void) {
            InitializeComponent();
            angleX = angleY = 0;
            scaleFactor = 1;
            rotationSpeed = 1;
            start_Color = Color::Black;
            timer1->Start();
        }

    protected:
        ~Prizma() {
            if (components) delete components;
        }
    private: System::ComponentModel::IContainer^ components;

    private:
        void InitializeComponent(void)
        {
            this->components = (gcnew System::ComponentModel::Container());
            this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
            this->buttonColor = (gcnew System::Windows::Forms::Button());
            this->trackBarScale = (gcnew System::Windows::Forms::TrackBar());
            this->trackBarSpeed = (gcnew System::Windows::Forms::TrackBar());
            this->checkBoxX = (gcnew System::Windows::Forms::CheckBox());
            this->checkBoxY = (gcnew System::Windows::Forms::CheckBox());
            this->labelScale = (gcnew System::Windows::Forms::Label());
            this->labelSpeed = (gcnew System::Windows::Forms::Label());
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBarScale))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBarSpeed))->BeginInit();
            this->SuspendLayout();
            // 
            // timer1
            // 
            this->timer1->Interval = 10;
            this->timer1->Tick += gcnew System::EventHandler(this, &Prizma::timer1_Tick);
            // 
            // buttonColor
            // 
            this->buttonColor->Location = System::Drawing::Point(12, 177);
            this->buttonColor->Name = L"buttonColor";
            this->buttonColor->Size = System::Drawing::Size(107, 30);
            this->buttonColor->TabIndex = 6;
            this->buttonColor->Text = L"Цвет ребер";
            this->buttonColor->Click += gcnew System::EventHandler(this, &Prizma::buttonColor_Click);
            // 
            // trackBarScale
            // 
            this->trackBarScale->Location = System::Drawing::Point(15, 15);
            this->trackBarScale->Maximum = 11;
            this->trackBarScale->Minimum = 1;
            this->trackBarScale->Name = L"trackBarScale";
            this->trackBarScale->Size = System::Drawing::Size(202, 45);
            this->trackBarScale->TabIndex = 5;
            this->trackBarScale->Value = 6;
            this->trackBarScale->Scroll += gcnew System::EventHandler(this, &Prizma::trackBarScale_Scroll);
            // 
            // trackBarSpeed
            // 
            this->trackBarSpeed->Location = System::Drawing::Point(15, 66);
            this->trackBarSpeed->Maximum = 21;
            this->trackBarSpeed->Minimum = 1;
            this->trackBarSpeed->Name = L"trackBarSpeed";
            this->trackBarSpeed->Size = System::Drawing::Size(202, 45);
            this->trackBarSpeed->TabIndex = 4;
            this->trackBarSpeed->Value = 11;
            this->trackBarSpeed->Scroll += gcnew System::EventHandler(this, &Prizma::trackBarSpeed_Scroll);
            // 
            // checkBoxX
            // 
            this->checkBoxX->Checked = true;
            this->checkBoxX->CheckState = System::Windows::Forms::CheckState::Checked;
            this->checkBoxX->Location = System::Drawing::Point(15, 117);
            this->checkBoxX->Name = L"checkBoxX";
            this->checkBoxX->Size = System::Drawing::Size(104, 24);
            this->checkBoxX->TabIndex = 3;
            this->checkBoxX->Text = L"Вращение по X";
            // 
            // checkBoxY
            // 
            this->checkBoxY->Checked = true;
            this->checkBoxY->CheckState = System::Windows::Forms::CheckState::Checked;
            this->checkBoxY->Location = System::Drawing::Point(15, 147);
            this->checkBoxY->Name = L"checkBoxY";
            this->checkBoxY->Size = System::Drawing::Size(104, 24);
            this->checkBoxY->TabIndex = 2;
            this->checkBoxY->Text = L"Вращение по Y";
            // 
            // labelScale
            // 
            this->labelScale->AutoSize = true;
            this->labelScale->Location = System::Drawing::Point(232, 15);
            this->labelScale->Name = L"labelScale";
            this->labelScale->Size = System::Drawing::Size(53, 13);
            this->labelScale->TabIndex = 1;
            this->labelScale->Text = L"Масштаб";
            // 
            // labelSpeed
            // 
            this->labelSpeed->AutoSize = true;
            this->labelSpeed->Location = System::Drawing::Point(232, 66);
            this->labelSpeed->Name = L"labelSpeed";
            this->labelSpeed->Size = System::Drawing::Size(55, 13);
            this->labelSpeed->TabIndex = 0;
            this->labelSpeed->Text = L"Скорость";
            // 
            // Prizma
            // 
            this->ClientSize = System::Drawing::Size(839, 561);
            this->Controls->Add(this->labelSpeed);
            this->Controls->Add(this->labelScale);
            this->Controls->Add(this->checkBoxY);
            this->Controls->Add(this->checkBoxX);
            this->Controls->Add(this->trackBarSpeed);
            this->Controls->Add(this->trackBarScale);
            this->Controls->Add(this->buttonColor);
            this->DoubleBuffered = true;
            this->MinimumSize = System::Drawing::Size(600, 600);
            this->Name = L"Prizma";
            this->Text = L"Пятиугольная призма";
            this->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Prizma::Prizma_Paint);
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBarScale))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBarSpeed))->EndInit();
            this->ResumeLayout(false);
            this->PerformLayout();

        }
    private:
        System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
            if (checkBoxX->Checked) angleX += rotationSpeed;
            if (checkBoxY->Checked) angleY += rotationSpeed;
            Invalidate();
        }
        System::Void buttonColor_Click(System::Object^ sender, System::EventArgs^ e) {
            ColorDialog^ dialog = gcnew ColorDialog();
            if (dialog->ShowDialog() == Windows::Forms::DialogResult::OK) {
                start_Color = dialog->Color;
            }
        }
        System::Void trackBarScale_Scroll(System::Object^ sender, System::EventArgs^ e) {
            scaleFactor = trackBarScale->Value / 5.0;
        }
        System::Void trackBarSpeed_Scroll(System::Object^ sender, System::EventArgs^ e) {
            rotationSpeed = trackBarSpeed->Value / 5.0;
        }
        System::Void Prizma_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
            DrawPrism(e->Graphics);
        }
        void DrawPrism(Graphics^ g) {
            g->Clear(Color::White);
            Pen^ pen = gcnew Pen(start_Color, 2);
            int vertexes = 5;
            array<PointF>^ top = gcnew array<PointF>(vertexes);
            array<PointF>^ bottom = gcnew array<PointF>(vertexes);
            float radius = 50 * scaleFactor;
            float height = 50 * scaleFactor;
            float centerX = ClientSize.Width / 2;
            float centerY = ClientSize.Height / 2;
            float rotX = angleX * M_PI / 180;
            float rotY = angleY * M_PI / 180;

            for (int i = 0; i < vertexes; i++) {
                float angle = i * 2 * M_PI / vertexes;
                float x = radius * cos(angle);
                float y = radius * sin(angle);

                float y1 = y * cos(rotX) - height * sin(rotX);
                float z1 = y * sin(rotX) + height * cos(rotX);
                float x1 = x * cos(rotY) + z1 * sin(rotY);
                top[i] = PointF(centerX + x1, centerY + y1);

                y1 = y * cos(rotX) - -height * sin(rotX);
                z1 = y * sin(rotX) + -height * cos(rotX);
                x1 = x * cos(rotY) + z1 * sin(rotY);
                bottom[i] = PointF((centerX + x1), (centerY + y1));
            }
            g->DrawPolygon(pen, top);
            g->DrawPolygon(pen, bottom);
            for (int i = 0; i < vertexes; i++) {
                g->DrawLine(pen, top[i], bottom[i]);
            }
        }
};
}