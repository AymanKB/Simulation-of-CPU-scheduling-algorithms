import java.util.*;

public class SJF 
{
  
  private ArrayList<Process> readyQueue = new ArrayList<>(); // List of processes in the Ready Queue which are candidates to be processed
  private ArrayList<Process> not_readyQueue = new ArrayList<>(); // List of processes that haven't entered the Ready Queue
  private ArrayList<Integer> timeIndex = new ArrayList<>();
  private ArrayList<Integer> processIndex = new ArrayList<>();
  private CompareBurstTime BurstCom = new CompareBurstTime(); // Compare process based on burst time
  private CompareArrivalTime ArrCom = new CompareArrivalTime(); // Compare process based on arrival time
  
  public void addProcess(Process p)
  {
    if(p.getArrivalTime()== 0)
      readyQueue.add(p); // If arrival time == 0, this process will enter ReadyQueue first
    else
      not_readyQueue.add(p); // If arrival time > 0, this process will not enter ReadyQueue
  }
  
  public void scheduleSJF()
  {
    int time = 0; // Time elapsed
    timeIndex.add(0);
    int startProcessing = 0; // The time at which the process starts executing in CPU
    Collections.sort(readyQueue,BurstCom); // Sort the processes in ReadyQueue by ascending order of burst time
    Collections.sort(not_readyQueue,ArrCom);  // Sort the processes that haven't entered the ReadyQueue by ascending order of arrival time
    Process processNow = null; // Process at the head of ReadyQueue
    Process processNew = null; // Process that will be first to enter ReadyQueue next from outside
    
    while(true)
    {
      time = time + 1; // Increment elapsed time of current process CPU burst
      if(readyQueue.size()!=0) // There is at least one process in the Ready Queue
      {
        processNow=(Process)readyQueue.get(0);  
             
        if(processNow.getBurstTime() == 1) // If burst time of process == 1
        {
          timeIndex.add(time);
          processIndex.add(processNow.getProcessNumber());
          startProcessing = time; // Current process end time and next process start time
          readyQueue.remove(0); // Remove that process from Ready Queue
        }
        else // If burst time is not equals to 1
        processNow.dec_BurstTime(); // Decrement the burst time by 1
      }
      
      if(not_readyQueue.size()!=0) // There is at least one process haven't arrived at Ready Queue
      { 
        for (int i = 0; i < not_readyQueue.size(); i++)
        {
          if(not_readyQueue.get(i).getArrivalTime() < time)
          {
            readyQueue.add(not_readyQueue.get(i).clone());
            not_readyQueue.remove(i);
            Collections.sort(readyQueue,BurstCom);
          }
        }
        
        processNew = (Process)not_readyQueue.get(0);

        if(processNew.getArrivalTime() == time) // If arrival time of this process is the current burst time of previously allocated process
        {
          if(processNow.getBurstTime() > processNew.getBurstTime() || (processNow.getBurstTime() == processNew.getBurstTime() && processNow.get_Priority() > processNew.get_Priority() )) //if burst time of currently executing process > burst time of newly arrived process
          {
          timeIndex.add(time);
          processIndex.add(processNow.getProcessNumber());
            startProcessing = time; // Set new start processing to ending time of this process
          }
          readyQueue.add(processNew.clone()); // Add the new process to the tail of Ready Queue
          not_readyQueue.remove(0); // Remove the first process from this list
          Collections.sort(readyQueue,BurstCom); // Sort the updated list of processes in Ready Queue by ascending order of burst time
        }
      }
      
      if(not_readyQueue.size()==0 && readyQueue.size()==0) break; // After all process finished executing
              
    }
    
  }
  
   public ArrayList<Integer> OutputParam1()
  {
    return processIndex;
  }
  
   public ArrayList<Integer> OutputParam2()
  {
    return timeIndex;
  }
  
}