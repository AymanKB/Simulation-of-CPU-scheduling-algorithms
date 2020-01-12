import java.util.*;

public class CompareArrivalTime implements Comparator<Process>
{
     
  public CompareArrivalTime() {}
 
  public int compare(Process p1, Process p2) 
  {
    int difference= p1.getArrivalTime()- p2.getArrivalTime();
       
    if(difference<0 || difference > 0)return difference; // p1 arrival time < p2 arrival time OR p1 arrival time > p2 arrival time
    else // p1 arrival time == p2 arrival time
    {
      difference = p1.getBurstTime() - p2.getBurstTime();
      if (difference == 0) 
        difference = p1.get_Priority() - p2.get_Priority();
      return difference;
    } 
  }
}