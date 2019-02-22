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
	int serviceTime;	//How long will it takes to service this customer (random int)
	int arrivalTime;	//Used to calculate wait time.  This what the clock (or timer in this simulation)
						//								reads  when the customer arrives.
public:
	Customer(const int UPPER_BOUND)
	{
		upperBound = UPPER_BOUND;
		custNumber = 0;
		arrivalInterval = generateRandTime();	
		serviceTime = generateRandTime();		
		arrivalTime= 0;							
	}
	Customer(const int b, const int n, int a, int s, int t = 0) :upperBound(b),custNumber(n), arrivalInterval(a), serviceTime(s),arrivalTime(t) //after testing, initialize these with random numbers. Call setarrivalInterval() and setServiceTime().
	{
	}
	
	~Customer()
	{

	}
	void reInitCust(const int n)	//used to re-intitial the arrivingCust (in main) to new random arrivalInterval and serviceTime
	{
		custNumber = n;
		arrivalInterval = generateRandTime();
		serviceTime = generateRandTime();
		arrivalTime = 0;
	}
	
	void setarrivalInterval()
	{
		arrivalInterval = generateRandTime();
	}
	void setServiceTime()
	{
		serviceTime = generateRandTime();
	}
	void setArrivalTime(int w)  //used to determine wait time
	{
		arrivalTime = w;
	}
	int getCustNum()
	{
		return custNumber;
	}
	int getArrivalInterval()
	{
		return arrivalInterval;
	}
	int getServiceTime()
	{
		return serviceTime;
	}
	int getArrivalTime()
	{
		return arrivalTime;
	}
	void print()
	{
		cout << "arrival interval: " << arrivalInterval << " minutes" << endl;
		cout << "arrival time: " << arrivalTime << " after simulation timer started" << endl;
		cout << "service time: " << serviceTime << " minutes" << endl;

	}
	int generateRandTime()//helper function, generates a random number to arrivalInterval and serviceTime
	{
		return( rand() % (upperBound) +1);//generate and return a random integer from 1 to UPPER_BOUND (no zeros)
	}
};

