#include<iostream>
#include<string>
#include<queue>
#include"Customer.h"
using namespace std;

/*
CPS272-MP5-Queues
Simulate a line of customers who arrive at a random time,
	and where it takes a random time to serve.
*/

void main()
{
	//initialize variables
	const int SIMULATION_PERIOD = 120;	//how long the simulation will run.
	const int UPPER_BOUND = 4;			//used to set the random int to represent
										//				arrive and service times.
	int timer = 0;						//how far along the simulation is.
	int currArrivalTime = 0;			//When the next customer will arrive.
	int nextDepartureTime = 0;			//When the customer currently being served
										//								will leave.
	int arrivingCustCounter = 1;		//How many customers have arrived, set to 1 to initialize the first customer
	int servedCustCounter = 0;			//How many customers have been served.
	int waitTime = 0;					//Used to calculate which customer 
										//				had the longest wait time.
	int longestWaitTime = 0;			//To save which customer
										//				had the longest wait time.
	int maxCustLineLength = 0;			//To save the most number of customer that are 
										//					in the line at any one time.

	Customer arrivingCust(UPPER_BOUND,arrivingCustCounter,1,3,0);	//currently arriving Customer (set to defaults for testing).
	arrivingCust.setArrivalTime(arrivingCust.getArrivalInterval()); //set arrival time to interval arrival
	Customer currentCust = arrivingCust;		//customer who is currently being served.  
												//	(in the first case arriving cust is the first to be served.

	queue<Customer> custLine;			//Queue of Customers to be served.

	//Send first customer into the line
	currArrivalTime = arrivingCust.getArrivalInterval();//The first customer will arrive a random number of minutes after the timer starts
	nextDepartureTime = currArrivalTime + arrivingCust.getServiceTime();//The first customer will leave immediately after she is served.

	//Run simulation
	while (timer < SIMULATION_PERIOD)
	{
		//manage the flow of arriving customers
		if (currArrivalTime == timer)		//a customer has arrived and will stand in line.
		{
			arrivingCust.setArrivalTime(timer);	//set arrivalTime to the current timer
												// ( arrivalTime be subracted from where the timer is when the customer leaves to get the final wait time)

			custLine.push(arrivingCust);	//customer stands in line.

			//Print out arriving customer
			cout << "Customer" << arrivingCust.getCustNum()<<" arrived at " << arrivingCust.getArrivalTime() << endl;
			//arrivingCust.print();	
			cout << "*********************************************" << endl;

			//increment customer counter, set new arriving customer and new arrival time
			arrivingCustCounter++;
			arrivingCust.reInitCust(arrivingCustCounter);
			currArrivalTime = timer + arrivingCust.getArrivalInterval();//set currentArrivalTime (time the next customer is expected to arrive)
																		// to the current timer plus how many minutes untill the next customer arrives
		}
		if (nextDepartureTime == timer)		//customer leaves after she has been served
		{
			if (!custLine.empty())
			{
				if (maxCustLineLength < custLine.size())	//check the current custLine length and if it's longer than
					maxCustLineLength = custLine.size();	//maxCustLine, update maxCustLine with current custLine length

				waitTime = timer - currentCust.getArrivalTime();	//waitTime is the current time less the time arrived.
				if (longestWaitTime < waitTime)	//if current wait time is longer that saved longestWaitTime update longestWaitTime
					longestWaitTime = waitTime;
				
				//print out customer who has just been served
				cout << "Customer" << currentCust.getCustNum() << endl;
				cout << "  Arrived: " <<currentCust.getArrivalTime() << endl;
				cout << "Wait time: " << waitTime << endl;
				cout << " Departed: " << timer << endl;
				cout << "*********************************************" << endl;

				custLine.pop();	//remove served customer from queue (may have been the last customer in line)
				
				//start serving next customer, who will leave after their service time is over, 
				if (!custLine.empty())//There may have only been one customer in line, so the last pop may have resulted in an empty queue
				{
					currentCust = custLine.front();
					nextDepartureTime = timer + currentCust.getServiceTime();	//reset next departure time.	
				}
				else
				{
					currentCust = arrivingCust; //If there isn't a customer in line, the arriving customer will be the next customer to be serv
					currentCust.setArrivalTime(timer + arrivingCust.getArrivalInterval()); //The arriving customer will arrive after her arrivalInterval time
					nextDepartureTime = timer + currentCust.getArrivalInterval() + currentCust.getServiceTime();
				}
				
			}//end if (!custLine.empty())


		}
		++timer;
	}

	//Print out summary
	cout << "The maximum number of customer in line at any one time was " << maxCustLineLength << endl;
	cout << "The longest wait time of any customer was " << longestWaitTime << " minutes." << endl;
	
}