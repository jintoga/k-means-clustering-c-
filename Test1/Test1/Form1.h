#pragma once
#using <system.drawing.dll>
#include <stdlib.h> 
#include <stdio.h>
#include <cmath> 
#include "MyRect.h"
namespace Test1 {
	int dotSize=3,clusterSize=20;
	const int BIGNUMBER =  9999999; 
	int iteration;

	const int createPointsAndClustersFlag=1,runAlgorithmFlag=2,runDetectFlag=3;
	int operationFlag;
	using namespace System;
	using namespace System::Diagnostics;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Drawing::Drawing2D;
	/// <summary>
	/// Summary for Form1
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
		int numberOfClusters ,numberOfPoints ;
		array<Rectangle>^ points;
		array<Rectangle>^ clusters; 
		array<Color>^ colors;
		Graphics^ g;
		PaintEventArgs^ paintEvent;

		int *distances ;// Distance to the closest cluster's center
		int *closestCluster,*clusterRadius ;



	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Button^  buttonRun;



	private: System::Windows::Forms::Label^  labelIteration;

	public:
		Form1(void)
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
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  buttonInitiate;
	protected: 

	protected: 
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::TextBox^  textBoxNumberOfPoints;

	private: System::Windows::Forms::TextBox^  textBoxNumberOfClusters;
	private: System::ComponentModel::IContainer^  components;


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
			this->buttonInitiate = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBoxNumberOfPoints = (gcnew System::Windows::Forms::TextBox());
			this->textBoxNumberOfClusters = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->labelIteration = (gcnew System::Windows::Forms::Label());
			this->buttonRun = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// buttonInitiate
			// 
			this->buttonInitiate->Location = System::Drawing::Point(791, 100);
			this->buttonInitiate->Name = L"buttonInitiate";
			this->buttonInitiate->Size = System::Drawing::Size(75, 23);
			this->buttonInitiate->TabIndex = 0;
			this->buttonInitiate->Text = L"Initiate";
			this->buttonInitiate->UseVisualStyleBackColor = true;
			this->buttonInitiate->Click += gcnew System::EventHandler(this, &Form1::buttonInitiate_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(765, 29);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(93, 13);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Number Of Points:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(765, 67);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(101, 13);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Number Of Clusters:";
			// 
			// textBoxNumberOfPoints
			// 
			this->textBoxNumberOfPoints->Location = System::Drawing::Point(883, 26);
			this->textBoxNumberOfPoints->Name = L"textBoxNumberOfPoints";
			this->textBoxNumberOfPoints->Size = System::Drawing::Size(85, 20);
			this->textBoxNumberOfPoints->TabIndex = 3;
			// 
			// textBoxNumberOfClusters
			// 
			this->textBoxNumberOfClusters->Location = System::Drawing::Point(883, 60);
			this->textBoxNumberOfClusters->Name = L"textBoxNumberOfClusters";
			this->textBoxNumberOfClusters->Size = System::Drawing::Size(85, 20);
			this->textBoxNumberOfClusters->TabIndex = 4;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(788, 177);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(48, 13);
			this->label3->TabIndex = 5;
			this->label3->Text = L"Iteration:";
			// 
			// labelIteration
			// 
			this->labelIteration->AutoSize = true;
			this->labelIteration->Location = System::Drawing::Point(855, 177);
			this->labelIteration->MaximumSize = System::Drawing::Size(50, 13);
			this->labelIteration->MinimumSize = System::Drawing::Size(50, 13);
			this->labelIteration->Name = L"labelIteration";
			this->labelIteration->Size = System::Drawing::Size(50, 13);
			this->labelIteration->TabIndex = 6;
			this->labelIteration->Text = L"0";
			// 
			// buttonRun
			// 
			this->buttonRun->Location = System::Drawing::Point(893, 100);
			this->buttonRun->Name = L"buttonRun";
			this->buttonRun->Size = System::Drawing::Size(75, 23);
			this->buttonRun->TabIndex = 7;
			this->buttonRun->Text = L"Run";
			this->buttonRun->UseVisualStyleBackColor = true;
			this->buttonRun->Click += gcnew System::EventHandler(this, &Form1::buttonRun_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(995, 447);
			this->Controls->Add(this->buttonRun);
			this->Controls->Add(this->labelIteration);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->textBoxNumberOfClusters);
			this->Controls->Add(this->textBoxNumberOfPoints);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->buttonInitiate);
			this->MinimumSize = System::Drawing::Size(500, 38);
			this->Name = L"Form1";
			this->Text = L"K-Means";
			this->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Form1::reDrawForm);
			this->ResumeLayout(false);
			this->PerformLayout();

		}

		void reDrawForm( System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e){
			
			switch(operationFlag){
				case createPointsAndClustersFlag:
					drawPointsAndClusters(e->Graphics);
					break;
				case runAlgorithmFlag:
					runAlgor(e->Graphics);
					break;
				case runDetectFlag:
					runDetect(e->Graphics);
					break;
				default:
					break;

			} 

		}

		void drawPointsAndClusters(Graphics^ graphics){
			drawPoints(false,graphics);
			drawClusters(graphics);
			//generateRandomColors(numberOfClusters);

		}

		void runAlgor( Graphics^ graphics){
			 
			distances = new int[numberOfPoints];
			closestCluster = new int[numberOfPoints];
			clusterRadius =  new int[numberOfPoints];
			generateZeroArray(numberOfPoints,distances);
			generateZeroArray(numberOfPoints,closestCluster);
			generateZeroArray(numberOfPoints,clusterRadius);

			
			//findCeteroids() ; 
			runFirstStage(graphics);
			//Form1::Invalidate();

			myFindingCenteroids(graphics);

			//drawClusters(graphics);
			//drawPoints(true,graphics);
		}

		void runDetect(Graphics^ graphics){
			myFindingCenteroids(graphics);
		  
		}

		void runFirstStage(Graphics^ graphics){
			for(int i = 0;i < numberOfPoints; i++){
				distances[i] = BIGNUMBER;
				//Trace::AutoFlush = true; 
				//Trace::WriteLine("Compare No:" + i);
				Brush^ brush = gcnew SolidBrush(Color::Black);
				Pen^ pen;
				for(int j = 0;j < numberOfClusters; j++){
					int distanceBetweenClusterAndPoint = getDistanceBetween(points[i],clusters[j]);
					if (distanceBetweenClusterAndPoint < distances[i]){
						distances[i] = distanceBetweenClusterAndPoint;
						closestCluster[i] = j;	//index of closetCluster

					}

					//Trace::WriteLine(distances[i] + " closestCluster" + closestCluster[i]);
				}
				//Trace::WriteLine("closestCluster" + closestCluster[i]);


			}


			for(int i = 0;i < numberOfPoints; i++){
				Brush^ brush = gcnew SolidBrush(colors[closestCluster[i]]);

				graphics->FillRectangle(brush,clusters[closestCluster[i]]);
				Pen^ pen;
				for(int j = 0;j < numberOfClusters; j++){
					//draw points with color of closestCluster's color
					
					//pen = gcnew Pen(colors[closestCluster[i]]);  
					graphics->FillRectangle(brush,points[i]);
					//draw line between point and closestCluster's with color of closestCluster's 
					/*Int32 from_X,from_Y;
					Int32 to_X,to_Y;
					from_X = points[i].X;
					from_Y = points[i].Y; 
					to_X = clusters[closestCluster[i]].X;
					to_Y = clusters[closestCluster[i]].Y;  
					graphics->DrawLine(pen,from_X,from_Y,to_X,to_Y);*/

				}
			}

		}

		void myFindingCenteroids(Graphics^ graphics){
			int changed; 

			 do{
				//++iteration;
				changed = 0;
				int *newLocation_X = new int[numberOfClusters] ; 
				int *newLocation_Y = new int[numberOfClusters] ;
				int *sizeOfCluster = new int[numberOfClusters] ; 
				clusterRadius = new int[numberOfClusters] ; 
				generateZeroArray(numberOfClusters,newLocation_X);
				generateZeroArray(numberOfClusters,newLocation_Y);
				generateZeroArray(numberOfClusters,sizeOfCluster);
				generateZeroArray(numberOfClusters,clusterRadius);
				for(int i = 0;i < numberOfPoints; i++){
					distances[i] = BIGNUMBER;
					//Trace::AutoFlush = true; 
					//Trace::WriteLine("Compare No:" + i);
					Brush^ brush = gcnew SolidBrush(Color::Black);
					Pen^ pen;
					for(int j = 0;j < numberOfClusters; j++){
						int distanceBetweenClusterAndPoint = getDistanceBetween(points[i],clusters[j]);
						if (distanceBetweenClusterAndPoint < distances[i]){
							distances[i] = distanceBetweenClusterAndPoint;
							closestCluster[i] = j;	//index of closetCluster

						}
						newLocation_X[closestCluster[i]] += points[i].X;
						newLocation_Y[closestCluster[i]] += points[i].Y;
						++sizeOfCluster[closestCluster[i]];

						//Trace::WriteLine(distances[i] + " closestCluster" + closestCluster[i]);
					}
					//Trace::WriteLine("closestCluster" + closestCluster[i]);


				} 
				//iteration++;
				labelIteration->Text = iteration+"";
				/*Form1::Invalidate();
				Form1::Refresh();*/
				
				for (int i = 0; i < numberOfClusters; i++) {
					newLocation_X[i] /= sizeOfCluster[i];
					newLocation_Y[i] /= sizeOfCluster[i];
					Rectangle^ newPoint;
					try{
						newPoint = Rectangle(newLocation_X[i],newLocation_Y[i],clusterSize,clusterSize);
					}catch(Exception^ e){
						newPoint= clusters[i];
					}
					if(!newPoint->Equals(clusters[i])){
						++changed;
					}
					clusters[i] = *newPoint;
				}
				 }while(changed>0); 
			 //Form1::Refresh();
				//for(int i = 0;i < numberOfPoints; i++){
				//	Brush^ brush = gcnew SolidBrush(colors[closestCluster[i]]);
				//	graphics->FillRectangle(brush,clusters[closestCluster[i]]);
				//	Pen^ pen;
				//	for(int j = 0;j < numberOfClusters; j++){
				//		//draw points with color of closestCluster's color
				//		//brush = gcnew SolidBrush(colors[closestCluster[i]]);
				//		//pen = gcnew Pen(colors[closestCluster[i]]);  

				//		graphics->FillRectangle(brush,points[i]);
				//		//draw line between point and closestCluster's with color of closestCluster's 
				//		/*Int32 from_X,from_Y;
				//		Int32 to_X,to_Y;
				//		from_X = points[i].X;
				//		from_Y = points[i].Y; 
				//		to_X = clusters[closestCluster[i]].X;
				//		to_Y = clusters[closestCluster[i]].Y;  
				//		graphics->DrawLine(pen,from_X,from_Y,to_X,to_Y);*/

				//	}
				//}

			 //labelIteration->Text = iteration+"";


		}




		void getPointsAndClusters(int numberOfPoints,int numberOfClusters)
		{    

			int random_location_X,random_location_Y;

			points = gcnew array<Rectangle>(numberOfPoints);
			for(int i=0;i<numberOfPoints;i++)
			{
				random_location_X = random(0,750);
				random_location_Y = random(0,700);
				points[i] = Rectangle(random_location_X,random_location_Y,dotSize,dotSize); 
			} 

			clusters = gcnew array<Rectangle>(numberOfClusters);
			generateRandomColors(numberOfClusters);
			for(int i=0;i<numberOfClusters;i++)
			{	
				clusters[i] = points[i];
				clusters[i].Width = clusterSize;
				clusters[i].Height = clusterSize;
			}

		}

		void generateRandomColors(int numberOfClusters){
			colors = gcnew array<Color>(numberOfClusters);
			for (int i = 0; i < numberOfClusters; i++) {
				colors[i] = Color::FromArgb(random(0,255),random(0,255),random(0,255));
			}
		}

		void drawPoints(bool withColor,Graphics^ g){

			g->SmoothingMode;
			g->Clear(Color::WhiteSmoke);
			Brush^ brush = gcnew SolidBrush(Color::Black);
			Pen^ pen;
			for(int i=0;i<numberOfPoints;i++)
			{	  
				if(withColor){ 
					Int32 from_X,from_Y;
					Int32 to_X,to_Y;
					from_X = points[i].X;
					from_Y = points[i].Y; 
					for(int j=0;j<numberOfClusters;j++){
						pen = gcnew Pen(colors[j]); 
						brush = gcnew SolidBrush(colors[j]);
						to_X = clusters[j].X;
						to_Y = clusters[j].Y;  
					} 
					g->DrawLine(pen,from_X,from_Y,to_X,to_Y);
				}
				g->FillRectangle(brush,points[i]);

			} 
		}

		void drawClusters(Graphics^ g){ 
			Brush^ brush = gcnew SolidBrush(Color::Black); 
			for(int i=0;i<numberOfClusters;i++)
			{	  
				brush = gcnew SolidBrush(colors[i]);
				g->FillRectangle(brush,clusters[i]);
			} 
		}

		void generateZeroArray(int n, int *myArray){
			for(int i=0;i<n;i++){
				myArray[i]=0;
			}
		} 

		double getDistanceBetween(Rectangle^ rect1,Rectangle^ rect2){

			int rect1_X = rect1->X;
			int rect1_Y = rect1->Y;
			int rect2_X = rect2->X;
			int rect2_Y = rect2->Y;
			double distanceX = abs((rect2_X-rect1_X)*(rect2_X-rect1_X));
			double distanceY = abs((rect2_Y-rect1_Y)*(rect2_Y-rect1_Y));
			double distance =  sqrt(distanceX + distanceY);

			return distance;
		}

		int random(int min,int max){//range : [min, max)    
			return min + (rand() % (int)(max - min+1));
		}
#pragma endregion


	private: System::Void buttonInitiate_Click(System::Object^  sender, System::EventArgs^  e) {
				 String^ numbOfClusterSTR = textBoxNumberOfClusters->Text;
				 String^ numbOfPointsSTR = textBoxNumberOfPoints->Text;
			
				 if(numbOfClusterSTR!="")
					 numberOfClusters = System::Convert::ToInt32(numbOfClusterSTR);
				 if(numbOfPointsSTR!="")
					 numberOfPoints = System::Convert::ToInt32(numbOfPointsSTR);

				 getPointsAndClusters(numberOfPoints,numberOfClusters);

				 operationFlag = createPointsAndClustersFlag ;
				 iteration=0;
				 labelIteration->Text = iteration+"";
				 Form1::Refresh(); 

			 }  

	private: System::Void buttonRun_Click(System::Object^  sender, System::EventArgs^  e) {  
				 operationFlag = runAlgorithmFlag ; 
				 iteration++;
				 Form1::Refresh();
			 } 
	private: System::Void buttonDetect_Click(System::Object^  sender, System::EventArgs^  e) {
				 operationFlag = runDetectFlag ; 
				 Form1::Refresh();
			 }
	};

}

