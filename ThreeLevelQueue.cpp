/// \file threeLevelQueue.cpp

/// \mainpage
///
/// DEMONSTRATES threeLevelQueue ALGORITHM.
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
///	    Declare Queue Arrays lvl1,lvl2,lvl3
///
///	       //the highest priorty is lvl1 and the lowest priorty is lvl3
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
///         	 if(x.priority == 1 or x.priority == 2)	 	     lvl1 <== x
///        	 else if(x.priorty == 3 or x.priorty == 4) 	     lvl2 <== x
///         	 else if(x.priority == 5 or x.priorty == 6) 	 lvl3 <== x
///
///           	x <- max(priorty)
///            if(lvl1)
///             //perform Round Robin (Quantum = 2)
///           	x.burstTime = x.burstTime - 2
///             lvl1 <- x
///             delete the first x
///		     sum_of_all_burstTimes = sum_of_all_burstTimes - 2
///
///             else if(lvl2)
///             //perform FCFS
///             	x.burstTime = x.burstTime - 1
///		        sum_of_all_burstTimes = sum_of_all_burstTimes - 1
///
///            else if(lvl3)
///            //perform FCFS
///            	x.burstTime = x.burstTime - 1
///		        sum_of_all_burstTimes = sum_of_all_burstTimes - 1
///
///     //ALGORITHM FINISHED
///    DRAW GANT CHART
///

#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <sstream>
using namespace std;

class threeLevelQueue{
  public:
    ///
    /// holds the value of the burst time needed for the process to finish execution.
    ///
    int burstTime;

    ///
    /// holds the value of the time in which the process will arrive to for it
    /// to be inside the algorithm.
    ///

    int arrivalTime;

    ///
    /// holds the value of the priorty in which the process will filtered
    /// before going inside the algorithm.
    ///
    int priority;

    ///
    /// holds the process id
    ///

    int p_id;

    ///
    /// checks if the process has arrived or not
    ///

    bool outside;

    ///
    /// checks if the Quantum is finished in level 1 which uses round robin algorithm
    ///
    bool RR;

    ///
    /// dynamically decides the process id
    ///
    static int ProcessCounter;

    ///
    /// the summation of all burst times to be used with the timer
    ///
    static int SumOfBurstTime;


    ///
    /// Keying in the values following the error checking list:
    ///
    /// *Number of processes must be between 3 and 10.
    ///
    /// *if the value wasn't an integer, it will clear the buffer and ask for a new value
    ///
    static void GetNumOfProcesses(int &processes);

    ///
    /// Keying in the values following the error checking list:
    ///
    /// *Number of processes must be between 3 and 10.
    ///
    /// *if the value wasn't an integer, it will clear the buffer and ask for a new value
    ///
    static void getProcessesAttributes(threeLevelQueue p[]);

    ///
    /// final input validation for all the get functions.
    ///
    /// with the ability to reenter values in case of errors
    ///
    static void informationCheckUp(threeLevelQueue p[],int size);

    ///
    /// Displays the attributes of all processes
    ///
    static void displayAttributes(threeLevelQueue p[]);

    ///
    /// Default constructor
    ///
    threeLevelQueue(); // Default constructor
  };

  threeLevelQueue :: threeLevelQueue() {
    burstTime = 0;
    arrivalTime = 0;
    priority = 0;
    outside = true;
    RR = false;
    p_id = ProcessCounter;
    ProcessCounter++;
  }



void threeLevelQueue :: getProcessesAttributes(threeLevelQueue p[]){
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

void threeLevelQueue :: displayAttributes(threeLevelQueue p[]){

    printf("\n-----------------------------------------------------\n");
    printf("%-15s%-15s%-15s%-15s", "Process" , "burstTime", "Arrival time" , "Priority");
    printf("\n-----------------------------------------------------\n");
    for (int i = 0; i < ProcessCounter; i++){
      printf("%s%-15d%-15d%-15d%-15d\n", "P", p[i].p_id, p[i].burstTime, p[i].arrivalTime, p[i].priority);
    }
    printf("-----------------------------------------------------\n");
  }

void threeLevelQueue :: GetNumOfProcesses(int &processes){

    cout << "Please enter the number of processes (range is 3~10)" << endl;

    while(true){
      try{
          cin >> processes;
          if(processes < 3 || processes > 10)
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

void threeLevelQueue :: informationCheckUp(threeLevelQueue p[],int size){
  string CheckingAttributes;
  bool CheckingAttributesFlag = false;

  while(true){
    try{
        threeLevelQueue :: getProcessesAttributes(p);
        threeLevelQueue :: displayAttributes(p);

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


int threeLevelQueue :: ProcessCounter = 0;
int threeLevelQueue :: SumOfBurstTime = 0;


int main(){
  bool ArrivalAtZero = false;
  int CheckArrivalAtZero = 0;
  int flag = 0;
  bool interrupt = false;
  bool arrived = false;
  bool GanttChart[7] = {false,false,false,false,false,false,false};
  bool GanttChartSpacing[4] = {false,false,false,false};
  int displayCounter[4] = {0,0,0,0};
  int GanttChartSpacingFactor[4] = {0,0,0,0};
  stringstream lvl1;
  stringstream lvl2;
  stringstream lvl3;
  stringstream spacing;
  int processes;
  vector<threeLevelQueue> arrival_vector;
  vector<threeLevelQueue> priority1;
  vector<threeLevelQueue> priority2;
  vector<threeLevelQueue> priority3;
  vector<threeLevelQueue> priority4;
  vector<threeLevelQueue> priority5;
  vector<threeLevelQueue> priority6;
  vector<threeLevelQueue> placeHolder;
  vector<vector<threeLevelQueue>> priority_Vector;
  priority_Vector.push_back(placeHolder);
  priority_Vector.push_back(priority1);
  priority_Vector.push_back(priority2);
  priority_Vector.push_back(priority3);
  priority_Vector.push_back(priority4);
  priority_Vector.push_back(priority5);
  priority_Vector.push_back(priority6);

  threeLevelQueue :: GetNumOfProcesses(processes);
  //Creating the processes
   threeLevelQueue *p = new threeLevelQueue[processes];
   // Gets all Processes attributes
   //Getting correct information
  threeLevelQueue :: informationCheckUp(p,processes);

    cout << "\n\n";


   //Start The algorithm

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
   int const TotalBurstTime = threeLevelQueue ::SumOfBurstTime;
   for (int timer = 0+CheckArrivalAtZero; timer < TotalBurstTime; timer++){
     //Checks Arrival
     for (int i = 0; i < threeLevelQueue :: ProcessCounter; i++){
       if(p[i].arrivalTime == timer){
         arrived = true;
         arrival_vector.push_back(p[i]);


       }
     }

     //Checks queueing processes based on the level
     if(arrived == true){
        for (int i = 0; i < arrival_vector.size(); i++){
          for (int j = 1; j < 7; j++){
            if(arrival_vector[i].priority == j && arrival_vector[i].outside == true){
                if (arrival_vector[i].priority == 1 || arrival_vector[i].priority == 2){
                  arrival_vector[i].outside = false;
                  priority_Vector[1].push_back(arrival_vector[i]);
                }

                else if(arrival_vector[i].priority == 3 || arrival_vector[i].priority == 4){
                  arrival_vector[i].outside = false;
                  priority_Vector[3].push_back(arrival_vector[i]);
                }

                else if(arrival_vector[i].priority == 5 || arrival_vector[i].priority == 6){
                  arrival_vector[i].outside = false;
                  priority_Vector[5].push_back(arrival_vector[i]);
                }
              }
            }
          }
          arrived = false;

    }
    // Swipes out if process used all Quantum time
    if(interrupt == true){
      priority_Vector[1].push_back(priority_Vector[1][0]);
      priority_Vector[1].erase(priority_Vector[1].begin());
      interrupt = false;
    }


      if (priority_Vector[1].size()>0){
        GanttChartSpacing[1] = false;

        if (GanttChart[3] == true){
          lvl2 << " | " << "P" << priority_Vector[3][0].p_id << " | " << timer;
          GanttChart[3] = false;
        }

        else if (GanttChart[5] == true){
          lvl3 << " | " << "P" << priority_Vector[5][0].p_id << " | " << timer;
          GanttChart[5] = false;
        }


        if(GanttChartSpacing[2] == true){

            if(lvl1.str()[0] == '0'){
              GanttChartSpacingFactor[1] = lvl2.str().size()+ timer -(timer*displayCounter[1]) - (timer/2);
            }
            else{
              GanttChartSpacingFactor[1] = lvl2.str().size()-(timer*displayCounter[1]);
            }

            for(int q = 0; q < GanttChartSpacingFactor[1]; q++){
                lvl1 << " ";
                GanttChartSpacing[2] = false;
              }

              displayCounter[1]+=3;
              lvl1 << timer;
            }
        else if(GanttChartSpacing[3] == true){

            if(lvl1.str()[0] == '0'){
              GanttChartSpacingFactor[1] = lvl3.str().size() + timer - (timer*displayCounter[1]) - (timer/2);
            }
            else{
              GanttChartSpacingFactor[1] = lvl3.str().size() - (timer*displayCounter[1]);
            }

            for(int q = 0; q < GanttChartSpacingFactor[1]; q++){
                lvl1 << " ";
                GanttChartSpacing[3] = false;
              }
              displayCounter[1]+=3;
              lvl1 << timer;
            }


        if (priority_Vector[1][0].burstTime == 1){
          if(timer == CheckArrivalAtZero){
            lvl1 << CheckArrivalAtZero;
          }
          priority_Vector[1][0].burstTime--;
        }

        else if (priority_Vector[1][0].burstTime > 1){
          if(timer == CheckArrivalAtZero){
            lvl1 << CheckArrivalAtZero;
          }
          priority_Vector[1][0].burstTime--;
          flag++;
        }

        if(priority_Vector[1][0].burstTime == 0){
          if(flag > 0){
            flag = 0;
          }
          interrupt = false;
          lvl1 << " | P" << priority_Vector[1][0].p_id <<  " | " << (timer+1);
          priority_Vector[1].erase(priority_Vector[1].begin());
        }

        else if (priority_Vector[1][0].burstTime > 0){
          if(flag == 2){
            lvl1 << " | P" << priority_Vector[1][0].p_id <<  " | " << (timer+1);
            flag = 0;
            interrupt = true;
          }
        }
        GanttChartSpacing[1] = true;
      }

      else if (priority_Vector[3].size()>0){

        GanttChartSpacing[2] == false;

        if (GanttChart[5] == true){
          lvl3 << " | " << "P" << priority_Vector[5][0].p_id << " | " << timer;
          GanttChart[5] = false;
        }


        if(timer == CheckArrivalAtZero){
          lvl2 << CheckArrivalAtZero;
        }


        if(GanttChartSpacing[1] == true){
          if(lvl2.str()[0] == '0'){
            GanttChartSpacingFactor[2] = lvl1.str().size() + timer - (timer*displayCounter[2]) - (timer/2);
          }
          else{
            GanttChartSpacingFactor[2] = lvl1.str().size() - (timer*displayCounter[2]);
          }
            for(int q = 0; q < GanttChartSpacingFactor[2]; q++){
                lvl2 << " ";
                GanttChartSpacing[1] = false;
              }
             displayCounter[2]+=3;
              lvl2 << timer;
            }
        else if(GanttChartSpacing[3] == true){

          if(lvl2.str()[0] == '0'){
            GanttChartSpacingFactor[2] = lvl3.str().size() + timer - (timer*displayCounter[2]) - (timer/2);
          }
          else{
            GanttChartSpacingFactor[2] = lvl3.str().size()-(timer*displayCounter[2]);
          }
            for(int q = 0; q < GanttChartSpacingFactor[2]; q++){
                lvl2 << " ";
                GanttChartSpacing[3] = false;
              }
             displayCounter[2]+=3;
              lvl2 << timer;
            }



        priority_Vector[3][0].burstTime--;
        GanttChart[3] = true;

        if(priority_Vector[3][0].burstTime == 0){
          lvl2 << " | " << "P" << priority_Vector[3][0].p_id << " | " << (timer+1);
          GanttChart[3] = false;

          priority_Vector[3].erase(priority_Vector[3].begin());
        }
        GanttChartSpacing[2] = true;
      }



      else if (priority_Vector[5].size()>0){
        GanttChartSpacing[3] = false;

        if(timer == CheckArrivalAtZero){
          lvl3 << CheckArrivalAtZero;
        }


        if(GanttChartSpacing[1] == true){
          if(lvl3.str()[0] == '0'){
            GanttChartSpacingFactor[3] = lvl1.str().size() + timer -(timer*displayCounter[3]) - (timer/2);
          }
          else{
            GanttChartSpacingFactor[3] = lvl1.str().size()-(timer*displayCounter[3]);
          }
            for(int q = 0; q < GanttChartSpacingFactor[3]; q++){
                lvl3 << " ";
                GanttChartSpacing[1] = false;
              }
              displayCounter[3]+=3;
              lvl3 << timer;
            }
        else if(GanttChartSpacing[2] == true){

          if(lvl3.str()[0] == '0'){
            GanttChartSpacingFactor[3] = lvl2.str().size()+ timer-(timer*displayCounter[3]) - (timer/2);
          }
          else{
            GanttChartSpacingFactor[3] = lvl2.str().size()-(timer*displayCounter[3]);
          }
            for(int q = 0; q < GanttChartSpacingFactor[3]; q++){
                lvl3 << " ";
                GanttChartSpacing[2] = false;
              }
              displayCounter[3]+=3;
              lvl3 << timer;
            }


        priority_Vector[5][0].burstTime--;
        GanttChart[5] = true;
        if(priority_Vector[5][0].burstTime == 0){
          lvl3 << " | " << "P" << priority_Vector[5][0].p_id << " | " << (timer+1);
          GanttChart[5] = false;
          priority_Vector[5].erase(priority_Vector[5].begin());
        }
        GanttChartSpacing[3] = true;
      }


   }

   cout << "\n\n\n";
   cout << "3 level queue (Quantum = 2)" <<  endl << endl;
   cout << "\n\n\n";
   cout << "Queue 1" << endl << endl;
   cout << lvl1.str();
   cout << "\n\n\n";

   cout << "\n\n\n";
   cout << "Queue 2" << endl << endl;
   cout << lvl2.str();
   cout << "\n\n\n";

   cout << "\n\n\n";
   cout << "Queue 3" << endl << endl;
   cout << lvl3.str();
   cout << "\n\n\n";



  delete[] p; // End of program!
}
