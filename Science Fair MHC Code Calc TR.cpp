#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cmath>

using namespace std;


struct trial {
	int *data;
	trial *next;
};

void printTrial(int array[], int n)
{
	int i;
	// Print out all numbers in the Protein Sequence
	for (i = 0; i < n; i++)
	{
		cout << array[i];
	}
	cout << ",";
}


void createTrial(int array[], int n)
{
	int i, tempIndex, tempValue;
	// Fill Protein Sequence With Random Numbers
	for (i = 0; i < n; i++)
	{
		 array[i]= rand() % 9; 
	}
}

int compareTrials (int *array, int *array2, int n)
{ 
	int i;
	for (i = 0; i < n; i++)
	{
		if (array[i] != array2[i])
		{
			return 1;
		}
	}
	return 0;
}


int main()
{
	int i, n, f;
	int counter = 0;
	int *ArrayPtr;
	int done = 0;
	int factorial;
	int outercounter;
	int *dataresults;
	int loopend = 200;
	trial rootTrial = {NULL, NULL};
	trial *trialPtr = &rootTrial;
	trial *trialNextPtr;

	// Get a number from user: n
	cout << "Please Enter an Integer" << endl;
	cin >> n;
	//Starts Timer
	clock_t totalTime = clock();
	// Return 0 if n is not positive (1 or more)
	if(n<1) return 0;
	
	srand(time(NULL));
	
	
	dataresults = new  int [loopend];


	// start
	for (outercounter = 0; outercounter < loopend; outercounter++)
	{
		counter = 0;
		rootTrial.next = NULL;
		done = 0;
		while (done == 0)
		{
			//Create A New Protein Sequence
			ArrayPtr = new int[n];                                                            	
			createTrial(ArrayPtr, n);																													
			counter = counter + 1;
			//Traverse The List Looking For Copies Of Protein Sequences
			trialPtr = &rootTrial;
			trialNextPtr = rootTrial.next;
			
			while (trialNextPtr != NULL)
			{
				//Compare Protein Sequences To Find Match
				if (compareTrials(ArrayPtr, trialNextPtr->data, n) == 0)
				{
					done = 1;
					break;
				}
				trialPtr = trialNextPtr;
				trialNextPtr = trialNextPtr->next;
			}
			
			if (done == 1)
			{
				break;
			}
			
			
			//Create New UnfoundTrial
			trialPtr->next = new trial;
			trialPtr->next->data = ArrayPtr;
			trialPtr->next->next = NULL;
		
		}
		
		
		//Release List Memory Back To Heap
		trialPtr = rootTrial.next;
		if (trialPtr != NULL)
		{
			trialNextPtr = trialPtr->next;
			while (trialNextPtr != NULL)
			{
				delete[] trialPtr->data;
				delete trialPtr;
				trialPtr = trialNextPtr;
				trialNextPtr = trialNextPtr->next;
			}
		}	
		
		dataresults[outercounter] = counter;
	}
	// end
	
	//Prints Factorials for n (Permutation)
	
		cout << endl;		
		cout << endl << "Possible Permutations of numbers:" << pow(10,n) << endl;
	float total = 0;
	
	for (f = 0; f <= n; f++)
	{
		if (f == 0)
		factorial = 1;
		else
		factorial = factorial * f;
	}
	
	cout << "The factorial of " << n << " is " << factorial << endl;

	for (int i = 0; i < loopend; i++ )
	{
		cout << *(dataresults+i) << ",";
		total += *(dataresults+i);
	}
	
	cout << endl << "Average:" << total/loopend << endl;
	
		
	delete[] dataresults;

	totalTime = clock() - totalTime;
	cout << "Total Time: " << ( ( double ) totalTime / (CLOCKS_PER_SEC) ) << "s" << endl;
	
	return 0;
}
