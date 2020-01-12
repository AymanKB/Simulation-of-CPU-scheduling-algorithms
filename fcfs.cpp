/// \file fcfs.cpp

/// \mainpage
///
/// DEMONSTRATES FCFS ALGORITHM.
///
///
///
///
///-------------------Pseudocode-------------------
///
///
///
///
///
///     Get num_of_processes
///	    Declare i
///	    Declare array of x with size = num_of_processes
///	    Declare priority Arrays pn1a,pn2a,pn3a,pn4a,pn5a,pn6a
///
///	       //the highest priorty is pn1a and the lowest priorty is pn6a
///
///
///	    i = 0
///	    while (num_of_processes < 0)
///            Get Processes attributes (PA) {Burst time, Priority, Arrival time}
///         	object xi <-- PA
///	    	num_of_processes = num_of_processes - 1
///	    	i = i + 1
///
///       //each object x will receive its own PA
///
///
///
///     while (sum_of_all_burstTimes < 0)
///       when x arrives
///         	if(x.priorty == 1)	 	    pn1a <== x
///         	else if(x.priorty == 2) 	pn2a <== x
///        	else if(x.priorty == 3) 	pn3a <== x
///         	else if(x.priorty == 4) 	pn4a <== x
///         	else if(x.priorty == 5) 	pn5a <== x
///         	else if(x.priorty == 6) 	pn6a <== x
///
///     	x <- max(priority)
///     	x.burstTime = x.burstTime - 1
///		sum_of_all_burstTimes = sum_of_all_burstTimes - 1
///
///
///     //ALGORITHM FINISHED
///    DRAW GANT CHART
///


#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <stdio.h>
using namespace std;


class FCFS{
  public:
    // holds the value of the burst time needed for the process to finish execution.
    int burstTime;

    // holds the value of the time in which the process will arrive to for it
    // to be inside the algorithm.
    int arrivalTime;

    // holds the value of the priorty in which the process will filtered
    // before going inside the algorithm.
    int priority;

    // holds the process id
    int p_id;

    // checks if the process has arrived or not
    bool outside;

    // dynamically decides the process id
    static int ProcessCounter;

    // the summation of all burst times to be used with the timer
    static int SumOfBurstTime;

    // Keying in the values following the error checking list:
    // *Number of processes must be between 3 and 10.
    // *if the value wasn't an integer, it will clear the buffer and ask for a new value
    static void GetNumOfProcesses(int &processes);

    // Keying in the values for all the attributes following the error checking list:
    // *all priority values must be between 1 and 6.
    // *at least one process must have arrival = 0.

    static void getProcessesAttributes(FCFS p[]);

    // final input validation for all the get functions.
    // with the ability to reenter values in case of errors
    static void informationCheckUp(FCFS p[],int size);

    // Displays the attributes of all processes
    static void displayAttributes(FCFS p[]);

    // Default constructor
    FCFS();
};

FCFS :: FCFS() {
    burstTime = 0;
    arrivalTime = 0;
    priority = 0;
    outside = true;
    p_id = ProcessCounter;
    ProcessCounter++;
  }

void FCFS :: getProcessesAttributes(FCFS p[]){
       // Keying in the values
       for (int i = 0 ; i < ProcessCounter; i++){
         while(true){
           cout << endl << "Enter the burst time of #P" << i << endl;
           cin >> p[i].burstTime;
           if(cin.fail() || p[i].burstTime < 1)
            {
              cout << "Error: Burst time cannot be less than one\n";
              cin.clear();
              cin.ignore(99,'\n');
            }
            else{
              break;
            }
         }

         while(true){
           cout << endl << "Enter the arrival time of #p" << i << endl;
           cin >> p[i].arrivalTime;
           if(cin.fail() || p[i].arrivalTime < 0)
            {
              cout << "Error: arrival time cannot be less than zero\n";
              cin.clear();
              cin.ignore(99,'\n');
            }
            else{
              break;
            }
         }

         while(true){
           cout << endl << "Enter the priority of #p" << i << endl;
           cin >> p[i].priority;
           if(cin.fail() || p[i].priority < 1 || p[i].priority > 6)
            {
              cout << "Error: priority must be between 1 and 6\n";
              cin.clear();
              cin.ignore(99,'\n');
            }
            else{
              break;
            }
         }

       for(int i = 0; i < ProcessCounter; i++){
         SumOfBurstTime+= p[i].burstTime;
       }

     }
   }


void FCFS :: displayAttributes(FCFS p[]){

    printf("\n-----------------------------------------------------\n");
    printf("%-15s%-15s%-15s%-15s", "Process" , "burstTime", "Arrival time" , "Priority");
    printf("\n-----------------------------------------------------\n");
    for (int i = 0; i < ProcessCounter; i++){
      printf("%s%-15d%-15d%-15d%-15d\n", "P", p[i].p_id, p[i].burstTime, p[i].arrivalTime, p[i].priority);
    }
    printf("-----------------------------------------------------\n");
  }


void FCFS :: GetNumOfProcesses(int &processes){

    cout << "Please enter the number of processes (range is 3-10)" << endl;

    while(true){
      try{
          cin >> processes;
          if(processes < 3 || processes > 10 || cin.fail())
          throw false;
        break;
      }
      catch(...){
        cout <<  "ERROR: the number of processes should be 3~10 " << endl;
        cin.clear();
    		cin.ignore(99, '\n');
      }
    }
  }



void FCFS :: informationCheckUp(FCFS p[],int size){
    string CheckingAttributes;
    bool CheckingAttributesFlag = false;

    while(true){
      try{
          FCFS :: getProcessesAttributes(p);
          FCFS :: displayAttributes(p);

          cout << "\n\nwas the table entered correctly?\n"
               << "Press anything if yes,  0 if no \n";
          cin >> CheckingAttributes;
          if(CheckingAttributes == "0")
            throw false;
        break;
      }
      catch(bool x){
        cout << "\nOkay: retry after the screen clear!\n";
        system("pause");
        system("cls");
        cin.clear();
        cin.ignore(99, '\n');
      }

    }

  }

int FCFS :: ProcessCounter = 0;
int FCFS :: SumOfBurstTime = 0;


int main(){
  bool ArrivalAtZero = false;
  int CheckArrivalAtZero = 0;
  bool arrived = false;
  bool GanttChart[7] = {false,false,false,false,false,false,false};
  int processes;
  vector<FCFS> arrival_vector;
  vector<FCFS> priority1;
  vector<FCFS> priority2;
  vector<FCFS> priority3;
  vector<FCFS> priority4;
  vector<FCFS> priority5;
  vector<FCFS> priority6;
  vector<FCFS> placeHolder;
  vector<vector<FCFS>> priority_Vector;
  priority_Vector.push_back(placeHolder);
  priority_Vector.push_back(priority1);
  priority_Vector.push_back(priority2);
  priority_Vector.push_back(priority3);
  priority_Vector.push_back(priority4);
  priority_Vector.push_back(priority5);
  priority_Vector.push_back(priority6);

  FCFS :: GetNumOfProcesses(processes);
  //Creating the processes
   FCFS *p = new FCFS[processes];
   // Gets all Processes attributes
   //Getting correct information
  FCFS :: informationCheckUp(p,processes);

    cout << "\n\n";


   //Start The algorithm
   int const TotalBurstTime = FCFS :: SumOfBurstTime;

   for(int i = 0; i < processes; i++){
     if(p[i].arrivalTime == 0){
      ArrivalAtZero = true;
    }
   }

   if(!ArrivalAtZero){
     CheckArrivalAtZero = p[0].arrivalTime;
     for(int i = 0; i < processes; i++){
       if(CheckArrivalAtZero > p[i].arrivalTime ){
         CheckArrivalAtZero = p[i].arrivalTime;
      }
     }
   }

   cout << CheckArrivalAtZero;
   for (int timer = 0 + CheckArrivalAtZero; timer < TotalBurstTime; timer++){
     //Checks Arrival
     for (int i = 0; i < FCFS :: ProcessCounter; i++){
       if(p[i].arrivalTime == timer){
         arrived = true;
         arrival_vector.push_back(p[i]);


       }
     }

      //Filters the arrived based on priority
     if(arrived == true){
      for (int i = 0; i < arrival_vector.size(); i++){
        for (int j = 1; j < 7; j++){
          if(arrival_vector[i].priority == j && arrival_vector[i].outside == true){
            arrival_vector[i].outside = false;
            priority_Vector[j].push_back(arrival_vector[i]);
          }
        }
      }
      arrived = false;
    }


    // Reduces burstTime and draws GanttChart when appropriate
    if (priority_Vector[1].size()>0){
      if (GanttChart[2] == true){
        cout << " | " << "P" << priority_Vector[2][0].p_id << " | " << timer;
        GanttChart[2] = false;
      }

      else if (GanttChart[3] == true){
        cout << " | " << "P" << priority_Vector[3][0].p_id << " | " << timer;
        GanttChart[3] = false;
      }

      else if (GanttChart[4] == true){
        cout << " | " << "P" << priority_Vector[4][0].p_id << " | " << timer;
        GanttChart[4] = false;
      }

      else if (GanttChart[5] == true){
        cout << " | " << "P" << priority_Vector[5][0].p_id << " | " << timer;
        GanttChart[5] = false;
      }

      else if (GanttChart[6] == true){
        cout << " | " << "P" << priority_Vector[6][0].p_id << " | " << timer;
        GanttChart[6] = false;
      }

      priority_Vector[1][0].burstTime--;
      if(priority_Vector[1][0].burstTime == 0){
        cout << " | " << "P" << priority_Vector[1][0].p_id << " | " << timer+1;
        priority_Vector[1].erase(priority_Vector[1].begin());
      }
    }
    else if (priority_Vector[2].size()>0){

      if (GanttChart[3] == true){
        cout << " | " << "P" << priority_Vector[3][0].p_id << " | " << timer;
        GanttChart[3] = false;
      }

      else if (GanttChart[4] == true){
        cout << " | " << "P" << priority_Vector[4][0].p_id << " | " << timer;
        GanttChart[4] = false;
      }

      else if (GanttChart[5] == true){
        cout << " | " << "P" << priority_Vector[5][0].p_id << " | " << timer;
        GanttChart[5] = false;
      }

      else if (GanttChart[6] == true){
        cout << " | " << "P" << priority_Vector[6][0].p_id << " | " << timer;
        GanttChart[6] = false;
      }


      priority_Vector[2][0].burstTime--;
      GanttChart[2] = true;
      if(priority_Vector[2][0].burstTime == 0){
        cout << " | " << "P" << priority_Vector[2][0].p_id << " | " << timer+1;
        GanttChart[2] = false;
        priority_Vector[2].erase(priority_Vector[2].begin());
      }
    }

    else if (priority_Vector[3].size()>0){

      if (GanttChart[4] == true){
        cout << " | " << "P" << priority_Vector[4][0].p_id << " | " << timer;
        GanttChart[4] = false;
      }

      else if (GanttChart[5] == true){
        cout << " | " << "P" << priority_Vector[5][0].p_id << " | " << timer;
        GanttChart[5] = false;
      }

      else if (GanttChart[6] == true){
        cout << " | " << "P" << priority_Vector[6][0].p_id << " | " << timer;
        GanttChart[6] = false;
      }



      priority_Vector[3][0].burstTime--;
      GanttChart[3] = true;
      if(priority_Vector[3][0].burstTime == 0){
        cout << " | " << "P" << priority_Vector[3][0].p_id << " | " << timer+1;
        GanttChart[3] = false;
        priority_Vector[3].erase(priority_Vector[3].begin());
      }
    }

    else if (priority_Vector[4].size()>0){

      if (GanttChart[5] == true){
        cout << " | " << "P" << priority_Vector[5][0].p_id << " | " << timer;
        GanttChart[5] = false;
      }

      else if (GanttChart[6] == true){
        cout << " | " << "P" << priority_Vector[6][0].p_id << " | " << timer;
        GanttChart[6] = false;
      }

      priority_Vector[4][0].burstTime--;
      GanttChart[4] = true;
      if(priority_Vector[4][0].burstTime == 0){
        cout << " | " << "P" << priority_Vector[4][0].p_id << " | " << timer+1;
        GanttChart[4] = false;
        priority_Vector[4].erase(priority_Vector[4].begin());
      }
    }

    else if (priority_Vector[5].size()>0){

      if (GanttChart[6] == true){
        cout << " | " << "P" << priority_Vector[6][0].p_id << " | " << timer;
        GanttChart[6] = false;
      }
      priority_Vector[5][0].burstTime--;
      GanttChart[5] = true;
      if(priority_Vector[5][0].burstTime == 0){
        cout << " | " << "P" << priority_Vector[5][0].p_id << " | " << timer+1;
        GanttChart[5] = false;
        priority_Vector[5].erase(priority_Vector[5].begin());
      }
    }

    else if (priority_Vector[6].size()>0){
      priority_Vector[6][0].burstTime--;
      GanttChart[6] = true;
      if(priority_Vector[6][0].burstTime == 0){
        cout << " | " << "P" << priority_Vector[6][0].p_id << " | " << timer+1;
        GanttChart[6] = false;
        priority_Vector[6].erase(priority_Vector[6].begin());
      }
    }
   }

  delete[] p;
}
