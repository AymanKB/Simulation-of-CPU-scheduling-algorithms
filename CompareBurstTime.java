import java.util.*;

public class CompareBurstTime implements Comparator<Process> 
{
     
  public CompareBurstTime() {}
 
  public int compare(Process p1, Process p2) 
  {
    int difference= p1.getBurstTime() - p2.getBurstTime();
    if (difference == 0)
    {
      difference = p1.get_Priority() - p2.get_Priority();
      if (difference == 0)
        difference = p1.getArrivalTime() - p2.getArrivalTime();
    }
    return difference;
  }
}