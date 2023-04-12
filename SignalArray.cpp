/*
 * SignalArray.cpp
 *
 *  John Alex Burke project 5 Pulsar Data oop
 *   This project uses two classes(Signal and SignalArray) to process and manipulate Pulsar data from a .txt file
 */

#include "SignalArray.h"
#include "Signal.h"
#include<iostream>
#include<fstream>
#include<string>

using namespace std;

SignalArray::SignalArray()//default constructor
{
size=0;
capacity=10000;
signals=new Signal[capacity];
}

SignalArray::SignalArray(const SignalArray& s2) // deep copy
{
size=s2.size;
capacity=s2.capacity;
signals=new Signal[capacity];
for(int i=0;i<capacity; i++)
{
	signals[i]=s2.signals[i];
}
	delete [] s2.signals;
}


SignalArray::~SignalArray()//memory deallocation
{
	delete [] signals;
	signals=nullptr;
}
/*"stats" computes SignalArray stats(average, min, and max value) for dm and sigma
 * The only parameter it takes is a SignalArray, and it doesn't return anything.
 */
void stats(const SignalArray& SigA)
{
	double minDM=99999999999999999;
	double maxDM=0;
	double averageDM=0.00;
	double minSigma=9999999999999;
	double maxSigma=0;
	double averageSigma=0.00;
	if(SigA.size==0)
		cerr<<"Cannot compute stats for an empty array!"<<endl;
	else
	{
		for(int i= 0; i<SigA.size; i++)
		{
			averageDM+=SigA.signals[i].dm;
			averageSigma+=SigA.signals[i].sigma;
			if(SigA.signals[i].dm>maxDM)
				maxDM=SigA.signals[i].dm;
			if(SigA.signals[i].dm<minDM)
				minDM=SigA.signals[i].dm;
			if(SigA.signals[i].sigma>maxSigma)
				maxSigma=SigA.signals[i].sigma;
			if(SigA.signals[i].sigma<minSigma)
				minSigma=SigA.signals[i].sigma;
		}
		averageDM=averageDM/SigA.size;
		averageSigma=averageSigma/SigA.size;
		cout<<"       MIN    MAX    AVG"<<endl<<"DM:    "<<minDM<<"      "<<maxDM<<"      "<<averageDM<<endl<<"SIGMA: "<<minSigma<<"   "<<maxSigma<<"  "<<averageSigma<<endl;
	}

}
/*"addSignal" adds a signal to the current Signal array. It is a private method only called when using the "load method"
 * It doesn't return anything, and takes one Signal object as its only parameter
 */
void SignalArray::addSignal(Signal s)
{
	if(size-1==capacity)
	{
		cout<<"Growing from "<<capacity<<" to "<<capacity+10000<<endl;
		capacity+=10000;
		SignalArray s2;
		delete[] s2.signals;
		s2.capacity+=10000;
		s2.signals= new Signal[capacity];
		*s2.signals=*signals;
		for(int i=0; i<=capacity-10000; i++)
		{
			s2.signals[i]=signals[i];
		}
		delete [] signals;
		signals=new Signal[capacity];
		*signals=*s2.signals;
		for(int i=0;i<=capacity-10000; i++)
		{
			signals[i]=s2.signals[i];
		}
		delete [] s2.signals;
		s2.signals=nullptr;
	}
	signals[size]=s;
	size++;

}
/*"load" Takes the name of the file and stores a line of data from it into a new Signal object. Then the object is placed into the array of signal objects in SignalArray.
 * It repeats this until the end of file is reached.
 */
void load(string file, SignalArray& sig)//creates a new Signal for each line of file and adds the new Signal to SignalArray
{
	sig.size=0;
	ifstream infile;
	infile.open(file);
	cout<<"Loading File: "<<file+'\n'+"...";
	if(infile.fail())
		cerr<<"error opening file: "<<file+'\n';
	else
	{
		cout<<"File "<<file<<" Loaded Successfully!"<<endl;
		while(infile.good())
		{
			string line;
			getline(infile,line);

			Signal add;
			infile>>add.dm>>add.sigma>>add.time>>add.sample>>add.downfact;
			sig.addSignal(add);											//adds the new signal to SignalArray

		}
		cout<<"SignalArray has "<<sig.size<<" signals."<<endl;
	}
}

void SignalArray::printHead(const SignalArray& SigA) //prints first 20 formatted signals. Signal array is the only parameter and it returns nothing.
{
	if(SigA.size==0)
		cerr<<"Signal Array is empty."<<endl;
	else
	{
		cout<<HDR<<endl;
		if(size<20)
		{
			for(int i=0; i<size; i++)
				cout<<signals[i].print(signals[i])<<endl;
		}
		else if(size>=20)
		{
			for(int i=0; i<20;i++)
				cout<<signals[i].print(signals[i])<<endl;
		}
	}
}
void SignalArray::printTail(const SignalArray& SigA) //prints last 20 formatted signals. Signal array is the only parameter and it returns nothing.
{
	if(SigA.size==0)
			cerr<<"Signal Array is empty."<<endl;
	else
	{
		cout<<HDR<<endl;
		if(size<20)
		{
			for(int i=0; i<size; i++)
				cout<<signals[i].print(signals[i])<<endl;
		}
		else if(size>=20)
		{
			for(int i=size-21; i<size; i++)
				cout<<signals[i].print(signals[i])<<endl;
		}
	}
}

