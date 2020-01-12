import java.util.*;

public class SRTN
{
  
	public static void main(String[] args)
  {
		Scanner input = new Scanner(System.in);
		int tempInt;
		boolean validState = true; 
		
		int size = 0; // The number of processes in the scheduler
		
		
		
		while (size < 3 || size > 10)
    {       // Check if number of process falls within valid range
			try {
			System.out.print("Enter The Number Of process 3 - 10 : ");
			size = input.nextInt();
			} 
			catch(InputMismatchException e){
				input.nextLine();
			}

		}
		
		Process[] p = new Process[size]; // Create an array of Processes with specified number of elements
		
		for(int i= 0; i< size; i++) // Initialise each element of p array
			p[i] = new Process();
		System.out.println("\n" + "Enter The Burst Time For Each Process:");
		for(int i = 0; i< size; i++) // For each process, set a valid burst time
    {	
			while(validState)
      {
			  try
        {
				  System.out.print("P["+i+"] : ");
				  tempInt = input.nextInt(); // Get input from user for burst time
				  p[i].setBurstTime(tempInt); // Set the burst time for each process
          p[i].setProcessNumber(i);
          validState = false; // To invoke next iteration of for loop for next process
        }
				catch(InputMismatchException e) {input.nextLine();} // In case of invalid input, ask for user input again
			}
			validState = true; // Set valid to "true" before next iteration of for loop
		}
    
		System.out.println("\n" + "Enter The Arrival Time For Each Process:");
		for(int i= 0; i< size; i++) // For each process, set a valid arrival time
    {	
			while(validState)
      {
			  try
        {
          System.out.print("P["+i+"] : ");
          tempInt = input.nextInt(); // Get input from user for arrival time
          p[i].setArrivalTime(tempInt); // Set the arrival time for each process
          validState =false; // To invoke next iteration of for loop for next process
        }
				catch(InputMismatchException e){input.nextLine();} // In case of invalid input, ask for user input again
			}
			validState = true; // Set valid to "true" before next iteration of for loop
		}
    
		System.out.println("\n" + "Enter The Priority For Each Process:");
		for(int i= 0; i< size; i++) // For each process, set a valid priority value
    {
			while(validState)
      {
        try
        {
          System.out.print("P["+i+"] : ");
          tempInt = input.nextInt();  // Get input from user for priority value
          p[i].set_Priority(tempInt); // Set the priority value for each process
          validState =false; // To invoke next iteration of for loop for next process
        }
				catch(InputMismatchException e){input.nextLine();} // In case of invalid input, ask for user input again
			}
			validState = true; // Set valid to "true" before next iteration of for loop
		}
		
    // Print the table containing relevant infomation of each process
		System.out.println("\n" + " |-----------------------------------------------------------------|");
		System.out.println(" | Process       | Burst Time    | Arrival Time  | Priority        |");
		System.out.println(" |---------------|---------------|---------------|-----------------|");
		for(int i =0; i < size; i++)
    {
      System.out.println(" | P"+i+"            | "+ p[i].getBurstTime()+"             |"+p[i].getArrivalTime() +"              | "+ p[i].get_Priority()+"               |");
      System.out.println(" |---------------|---------------|---------------|-----------------|");
		}
		System.out.println();
		  
    //SJF with priority
    System.out.println("\n\n" + "Q4: SRTN with priority ");
    SJF scheduler = new SJF(); 
    for (int i = 0; i < p.length; i++)
    {
      scheduler.addProcess(new Process(p[i].getArrivalTime(), p[i].getBurstTime(), p[i].get_Priority(), p[i].getProcessNumber()) );
    }
    
    scheduler.scheduleSJF();
    chart(scheduler.OutputParam1(), scheduler.OutputParam2() );
	}	

  public static void chart(ArrayList<Integer> p1, ArrayList<Integer> t2)
  {
    border(p1.size());
    for (Integer i : p1)
    {
      System.out.print("| p[" + i + "] ");
    }
    System.out.println("|");
    border(p1.size());
    for (Integer i : t2)
    {
      if ( i < 10)
        System.out.print(i + "      ");
      else
        System.out.print(i + "     ");
    }
  }

  public static void border(int num)
  {
    for (int i = 1; i <= num; i++)
    {
      System.out.print("|------");
    }
  
    System.out.println("|");  
  }
	
}