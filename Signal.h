/*
 * Signal.h
 *
 *  John Alex Burke project 5 Pulsar Data oop
 *   This project uses two classes(Signal and SignalArray) to process and manipulate Pulsar data from a .txt file
 */

#ifndef SIGNAL_H_
#define SIGNAL_H_
#include <string>
using namespace std;
class SignalArray;

class Signal {
public:
	Signal();
	Signal(const Signal& s2); //shallow copy constructor
	virtual ~Signal();
	friend void load(string file, SignalArray&);    //friend methods
	friend void stats(const SignalArray&);
	string print(Signal);                           //returns a string containing its formatted member data


private:
	double dm, sigma, time;
	int sample, downfact;
};

#endif /* SIGNAL_H_ */
