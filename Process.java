public class Process 
{
	private int processNumber; // Assign ID number to each process P[0],P[1]... etc.
	private int arrivalTime;
	private int burstTime;
	private boolean state = false;
	public int priority;

	// Constructor to initialize Process's instances
	public Process(int arrivalTime, int burstTime, int priority, int processNumber)
  {
    this.arrivalTime = arrivalTime;
    this.burstTime = burstTime;
    this.priority = priority;
    this.processNumber = processNumber;
  }
	// Constructor to initialize Process Number
	public Process(int processNumber)
  { //initialise the number assigned for a process
		this.processNumber = processNumber;
	}

	// Default Constructor
    public Process() {}

	// Set the Process number
	public void setProcessNumber(int processNumber)
	{ //assign a number to a particular process
		this.processNumber = processNumber;
	}

    // Get the Process number
	public int getProcessNumber()
  { //return the number assigned to a process
		return processNumber; 
	}

	// Set the Arrival time
	public void setArrivalTime(int arrivalTime)
  { //set the arrival time for a process
		this.arrivalTime = arrivalTime;
	}

	// Get the Arrival time
	public int getArrivalTime()
  { //set a arrival time for a process
		return arrivalTime;
	}

	// Set State
	public void set_State(boolean state)
  { 
		this.state = state;	
	}

	// Get State
	public boolean get_state()
  { 
		return state;
	}

	// Set the Burst time
	public void setBurstTime(int burstTime)
  { //set the burst time for a process
		this.burstTime = burstTime;
	}

	// Get the Burst time
	public int getBurstTime()
  { //return the burst time for a process
		return burstTime;
	}

    // Decrease the Burst time
    public void dec_BurstTime()
   {
     burstTime = burstTime - 1;
   }

    // Set the Priority
	public void set_Priority(int priority)
	{ //set the priority for a process
		this.priority = priority;
	}

	// Get the Priority
	public int get_Priority()
	{ //return the priority for a process
		return priority;
	}

    // Return duplicate of process
    public Process clone()
  {
    return new Process(arrivalTime,burstTime, priority,processNumber);
  }
}
