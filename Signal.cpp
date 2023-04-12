/*
 * Signal.cpp
 *
 *  John Alex Burke project 5 Pulsar Data oop
 *   This project uses two classes(Signal and SignalArray) to process and manipulate Pulsar data from a .txt file
 */

#include "Signal.h"
#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

Signal::Signal()
{                            // everything initialized to 0
	dm=sigma=time=0;
	sample=downfact=0;
}
Signal::Signal(const Signal& s2) // shallow copy
{
	dm=s2.dm;
	sigma=s2.sigma;
	time=s2.time;
	sample=s2.sample;
	downfact=s2.downfact;

}
Signal::~Signal()
{}
string Signal::print(Signal sig)
{
	string oneSig;
	oneSig=to_string(sig.dm)+" "+to_string(sig.sigma)+" "+to_string(sig.time)+" "+to_string(sig.sample)+" "+to_string(sig.downfact);
	return oneSig;
}
