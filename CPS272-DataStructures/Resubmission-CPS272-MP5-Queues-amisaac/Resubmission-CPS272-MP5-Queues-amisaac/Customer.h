#pragma once
#include<iostream>
#include<string>
using namespace std;

class Customer
{
private:
	int upperBound;		//used to generate random int for arrivalInterval and serviceTime
	int custNumber;		//used to compare printouts of when customer arrived and left
	int arrivalInterval;//How long it takes for the next customer to arrive (random int)
	int serviceInterval;//How long will it takes to service this customer (random int)
	int arrivalTime;	//Used to calculate wait time.  This what the clock (or timer in this simulation)
						//								reads  when the customer arrives.
	int serviceTime;	//What time was the customer service
	int departureTime;  //Used to calculate what time the customer left.
	int waitTime;		//The amount of time in line waiting, doesn't include time it took to service the customer.
public:
	Customer(const int UPPER_BOUND, const int n)
	{
		upperBound = UPPER_BOUND;
		custNumber = n;
		arrivalInterval = generateRandTime();
		serviceInterval = generateRandTime();
		arrivalTime = 0;
		serviceTime = 0;
		departureTime = 0;
		waitTime = 0;
	}
	Customer(const int b, const int n, int a, int s) :upperBound(b), custNumber(n), arrivalInterval(a), serviceInterval(s) //after testing, initialize these with random numbers. Call setarrivalInterval() and setServiceTime().
	{
	}

	~Customer()
	{

	}
	void reInitCust(const int n)	//used to re-intitial the arrivingCust (in main) to new random arrivalInterval and serviceTime
	{
		custNumber = n;
		arrivalInterval = generateRandTime();
		serviceInterval = generateRandTime();
		arrivalTime = 0;
		serviceTime = 0;
		departureTime = 0;
		waitTime = 0;
	}

	void setarrivalInterval(){arrivalInterval = generateRandTime();}
	void setServiceInterval(){serviceInterval = generateRandTime();}
	void setArrivalTime(int w) {arrivalTime = w;} //used to determine wait time
	void setServiceTime(int s) { serviceTime = s; }
	void setDepartureTime(int d) { departureTime = d; }
	void setWaitTime(int w) { waitTime = w; }

	int getCustNum()		{ return custNumber;}
	int getArrivalInterval(){ return arrivalInterval;}
	int getServiceInterval(){ return serviceInterval; }
	int getArrivalTime()	{ return arrivalTime; }
	int getServiceTime()	{ return serviceTime;}
	int getDepartureTime()	{ return departureTime; }
	int getWaitTime()		{ return waitTime; }

	void print()
	{
		cout << "arrival interval: " << arrivalInterval << " minutes" << endl;
		cout << "arrival time: " << arrivalTime << " after simulation timer started" << endl;
		cout << "service time: " << serviceTime << " minutes" << endl;

	}
	int generateRandTime()//helper function, generates a random number to arrivalInterval and serviceTime
	{
		return(rand() % (upperBound)+1);//generate and return a random integer from 1 to UPPER_BOUND (no zeros)
	}
};

