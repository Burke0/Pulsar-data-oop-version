/*
 * SignalArray.h
 *
 *  John Alex Burke project 5 Pulsar Data oop
 *   This project uses two classes(Signal and SignalArray) to process and manipulate Pulsar data from a .txt file
 */

#ifndef SIGNALARRAY_H_
#define SIGNALARRAY_H_
#include <string>
#include "Signal.h"

using namespace std;

class SignalArray
{
public:
	SignalArray();
	SignalArray(const SignalArray& s2);       					  //deep copy constructor
	virtual ~SignalArray();                    			   		// custom destructor to deallocate memory
	friend void load(string file, SignalArray&);                  //friend method loads data from file
	friend void stats(const SignalArray&);							//friend method prints stats about dm and sigma
	void printHead(const SignalArray&);								//prints first 20 signals
	void printTail(const SignalArray&);								//prints last 20 signals


private:
	const string HDR="DM Sigma Time Sample Downfact";     //Header
	int size;
	int capacity;
	Signal * signals;                                     //array of Signal objects
	void addSignal(Signal);                               // adds new Signal Object to array

};

#endif /* SIGNALARRAY_H_ */
