/*
Name: Fong Jin Xuan A24CS0074
Lai Shi Ni A24CS0298
Date: 12 January 2025
*/

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

void getInput(string [], int [],int [],int [],int size);
int calTotal(int arr[],int size);
int getLowest(int num[],int size,string[],string&);
int getHighest(int num[],int size,string[],string&);
double getAve(int,int);
int getRange(int,int);

int main()
{
	const int size=18;
	string uni[size];
	int intake[size],enrol[size],output[size];
	getInput(uni, intake, enrol, output, size);

	int totalInt,totalEnr,totalOut;
	double aveInt,aveEnr,aveOut;

	//Total
	totalInt=calTotal(intake,size);
	totalEnr=calTotal(enrol,size);
	totalOut=calTotal(output,size);

	//Average
	aveInt=getAve(totalInt,size);
	aveEnr=getAve(totalEnr,size);
	aveOut=getAve(totalOut,size);

	int lowInt, highInt, lowEnr, highEnr, lowOut, highOut;
	string lowIntN,highIntN,lowEnrN,highEnrN,lowOutN,highOutN;

	//Find lowest and name
	lowInt=getLowest(intake,size,uni,lowIntN);
	lowEnr=getLowest(enrol,size,uni,lowEnrN);
	lowOut=getLowest(output,size,uni,lowOutN);

	//Find highest and name
	highInt=getHighest(intake,size,uni,highIntN);
	highEnr=getHighest(enrol,size,uni,highEnrN);
	highOut=getHighest(output,size,uni,highOutN);

	int rangeInt,rangeEnr,rangeOut;

	//Range
	rangeInt=getRange(highInt,lowInt);
	rangeEnr=getRange(highEnr,lowEnr);
	rangeOut=getRange(highOut,lowOut);

	ofstream outputfile("output.txt");

	outputfile<<"     NUMBER OF STUDENTS' INTAKE, ENROLMENT AND OUTPUT"<<endl;
	outputfile<<"         IN PUBLIC UNIVERSITIES (2023)"<<endl<<endl;
	outputfile<<"---------------------------------------------------------------" <<endl;
	outputfile<< left<<setw(16)<<"UNIVERSITY"<<right<<setw(12)<<"INTAKE"<<setw(12)<<"ENROLMENT"<<setw(12)<<"OUTPUT"<<endl;
	outputfile<<"---------------------------------------------------------------"<<endl;

	for (int i=0; i<size; i++) {
		outputfile<<setw(4)<<" "<<left<<setw(12)<<uni[i]<<right<<setw(12)<<intake[i]<<setw(12)<<enrol[i]<<setw(12)<<output[i] << endl;
	}

	outputfile<< "---------------------------------------------------------------" << endl;
	outputfile<<setw(4) << " " << left << setw(12) << "TOTAL" << right << setw(12) << totalInt
	          <<setw(12) << totalEnr << setw(12) << totalOut << endl;
	outputfile<<fixed << setprecision(2);
	outputfile<<setw(4) << " " << left << setw(12) << "AVERAGE" << right << setw(12) << aveInt
	          <<setw(12) << aveEnr << setw(12) << aveOut << endl;

	outputfile<<"---------------------------------------------------------------" << endl;
	outputfile<<left<<setw(45) <<"THE LOWEST NUMBER OF STUDENTS' INTAKE"<<" = "<<lowInt<<" ("<<lowIntN<< ")"<<endl;
	outputfile<<left<< setw(45) <<"THE LOWEST NUMBER OF STUDENTS' ENROLMENT"<<" = "<<lowEnr<<" (" <<lowEnrN<< ")"<<endl;
	outputfile<<left<<setw(45) <<"THE LOWEST NUMBER OF STUDENTS' OUTPUT"<<" = " <<lowOut<<" (" <<lowOutN<< ")" << endl<<endl;
	outputfile<<left<<setw(45) <<"THE HIGHEST NUMBER OF STUDENTS' INTAKE"<<" = " << highInt<< " (" <<highIntN<< ")" << endl;
	outputfile<<left<<setw(45) <<"THE HIGHEST NUMBER OF STUDENTS' ENROLMENT"<<" = "<< highEnr<<" (" <<highEnrN<< ")" << endl;
	outputfile<<left<< setw(45) <<"THE HIGHEST NUMBER OF STUDENTS' OUTPUT"<<" = "<< highOut<<" (" <<highOutN<< ")" << endl<<endl;
	outputfile<<left<< setw(45) <<"THE RANGE OF NUMBER OF STUDENTS' INTAKE"<<" = " << rangeInt<< endl;
	outputfile<<left<< setw(45)<<"THE RANGE OF NUMBER OF STUDENTS' ENROLMENT"<<" = "<< rangeEnr<<endl;
	outputfile<<left<< setw(45)<<"THE RANGE OF NUMBER OF STUDENTS' OUTPUT"<<" = "<< rangeOut<< endl;
	outputfile<<"---------------------------------------------------------------" << endl;

	outputfile.close();
}

void getInput(string uni[], int intake[],int enrol[],int output[],int size) {
	ifstream inputfile;
	inputfile.open("input.txt");

	if (!inputfile) {
		cerr <<"Error opening file!" << endl;
		exit(1); // Return an error code
	}


	int i=0;
	while(!inputfile.eof()) {
		inputfile>>uni[i]>>intake[i]>>enrol[i]>>output[i];
		i++;
	}
	inputfile.close();
}

int calTotal(int arr[],int size) {
	int total=0;
	for(int i=0; i<size; i++) {
		total+=arr[i];
	}
	return total;
}

int getLowest(int num[],int size,string uni[], string&name) {
	int lowest=num[0];
	name=uni[0];
	for(int i=0; i<size; i++) {
		if (num[i]<lowest) {
			lowest=num[i];
			name=uni[i];
		}
	}
	return lowest;
}

int getHighest(int num[],int size,string uni[], string&name) {
	int highest=0;
	for(int i=0; i<size; i++) {
		if (num[i]>highest) {
			highest=num[i];
			name=uni[i];
		}
	}
	return highest;
}


double getAve(int total,int size) {
	return static_cast<double>(total) / size;
}

int getRange(int highest,int lowest) {
	return highest-lowest;
}