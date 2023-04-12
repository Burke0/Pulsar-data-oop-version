/*
 * prg5.cpp
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

int main()
{
	SignalArray pulsar;
	stats(pulsar);
	pulsar.printHead(pulsar);
	pulsar.printTail(pulsar);
	load("palfa.dat",pulsar);
	stats(pulsar);
	load("palfa.short.txt",pulsar);
	stats(pulsar);
	pulsar.printHead(pulsar);
	pulsar.printTail(pulsar);
	load("palfa.txt", pulsar);
	stats(pulsar);
	pulsar.printHead(pulsar);
	pulsar.printTail(pulsar);

	return 0 ;
}
