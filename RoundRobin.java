import java.util.*;

// Super class
public class RoundRobin {

//Main function
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		int temp;
		boolean vaild = true;

		int size = 0;

//A while loop to ask the user for how many processes they want process
		while (size < 3 || size > 10) {
			try {
				System.out.print("Enter The Number Of process 3 - 10 : ");
				size = scanner.nextInt();
			} catch (InputMismatchException e) {
				scanner.nextInt();
			}
		}

		Process[] p = new Process[size];

//A for loop to ask the user for the burst time for each process
		for (int i = 0; i < size; i++)
			p[i] = new Process();
		System.out.println();
		System.out.println("Enter The Burst Time For Each Process ");
		for (int i = 0; i < size; i++) {

			while (vaild) {
				try {
					System.out.print("P[" + i + "] : ");
					temp = scanner.nextInt();
					p[i].setBurstTime(temp);
					vaild = false;
				} catch (InputMismatchException e) {
					scanner.nextLine();
				}

			}
			vaild = true;
		}

//A for loop to ask the user for the arrival time for each process
		System.out.println();
		System.out.println("Enter The Arrival Time For Each Process ");
		for (int i = 0; i < size; i++) {

			while (vaild) {
				try {
					System.out.print("P[" + i + "] : ");
					temp = scanner.nextInt();
					p[i].setArrivalTime(temp);
					vaild = false;
				} catch (InputMismatchException e) {
					scanner.nextLine();
				}

			}
			vaild = true;
		}

//A for loop to ask the user for the priorities for each process
		System.out.println();
		System.out.println("Enter The Priority For Each Process ");
		for (int i = 0; i < size; i++) {
			while (vaild) {
				try {
					System.out.print("P[" + i + "] : ");
					temp = scanner.nextInt();
					p[i].setPriority(temp);
					vaild = false;
				} catch (InputMismatchException e) {
					scanner.nextLine();
				}

			}
			vaild = true;
		}

//Printing the table
		System.out.println();
		System.out.println(" |---------------------------------------------------------------------------------|");
		System.out.println(" | Process           | Burst Time        | Arrival Time      | Priority            |");
		System.out.println(" |-------------------|-------------------|-------------------|---------------------|");
		for (int i = 0; i < size; i++) {
			System.out.println(" | P" + i + "                | " + p[i].getBurstTime() + "                 |"
					+ p[i].getArrivalTime() + "                  | " + p[i].getPriority() + "                   |");
			System.out.println(" |-------------------|-------------------|-------------------|---------------------|");
		}
		System.out.println();

//Processing the gantt chart
		Process[] v2_0 = new Process[p.length];
		for (int i = 0; i < p.length; i++)
			v2_0[i] = new Process();
		for (int i = 0; i < p.length; i++) {
			v2_0[i].setArrivalTime(p[i].getArrivalTime());
			v2_0[i].setBurstTime(p[i].getBurstTime());
			v2_0[i].setPriority(p[i].getPriority());
		}

		Process[] v2_1 = new Process[p.length];
		for (int i = 0; i < p.length; i++)
			v2_1[i] = new Process();
		for (int i = 0; i < p.length; i++) {
			v2_1[i].setArrivalTime(p[i].getArrivalTime());
			v2_1[i].setBurstTime(p[i].getBurstTime());
			v2_1[i].setPriority(p[i].getPriority());
		}

		Process[] v2_2 = new Process[p.length];
		for (int i = 0; i < p.length; i++)
			v2_2[i] = new Process();
		for (int i = 0; i < p.length; i++) {
			v2_2[i].setArrivalTime(p[i].getArrivalTime());
			v2_2[i].setBurstTime(p[i].getBurstTime());
			v2_2[i].setPriority(p[i].getPriority());
		}

		Process[] v2_3 = new Process[p.length];
		for (int i = 0; i < p.length; i++)
			v2_3[i] = new Process();
		for (int i = 0; i < p.length; i++) {
			v2_3[i].setArrivalTime(p[i].getArrivalTime());
			v2_3[i].setBurstTime(p[i].getBurstTime());
			v2_3[i].setPriority(p[i].getPriority());
		}

//Printing the gantt chart
		System.out.println("Q2: Round Roubin With Priority		");
		System.out.print("|");
		q2(v2_0, 0);
		System.out.print("|");
		q2(v2_1, 1);
		System.out.print("|");
		q2(v2_2, 0);
		q2(v2_3, 2);
	}

// static function to proess RR
	public static void q2(Process[] p, int num) {
		int time = 0;
		int index_of_same_priority = 0;
		int minimim_priority = p[0].getPriority();
		int index_of_minimim_priority = 0;

		for (int i = 1; i < p.length; i++) {
			if (time > p[i].getArrivalTime()) {
				time = p[i].getArrivalTime();
			}
		}

		int size = p.length;

		for (int j = 0; j < size; j++) {
			for (int i = 0; i < p.length; i++) {
				if (p[i].getBurstTime() > 0 && time >= p[i].getArrivalTime()) {
					p[i].setState(true);
					minimim_priority = p[i].getPriority();
					index_of_minimim_priority = i;
				}

				else
					p[i].setState(false);
			}

			for (int i = 0; i < p.length; i++) {
				if (p[i].getState() == true && p[i].getState4() == true) {
					if (minimim_priority > p[i].getPriority()) {
						minimim_priority = p[i].getPriority();
						index_of_minimim_priority = i;
					}
				}
			}

			for (int i = 0; i < p.length; i++) {
				if (p[index_of_minimim_priority].getPriority() == p[i].getPriority()
						&& index_of_minimim_priority != i) {
					p[index_of_minimim_priority].setState3(false);
					p[i].setState3(false);
					if (p[i].getBurstTime() <= 0)
						p[index_of_minimim_priority].setState3(true);
					if (p[index_of_minimim_priority].getBurstTime() <= 0)
						p[i].setState3(true);
					index_of_same_priority = i;
				}

			}

			for (int i = 0; i < p.length; i++) {
				if (p[index_of_minimim_priority].getPriority() == p[i].getPriority() && index_of_minimim_priority != i
						&& p[i].getBurstTime() > 0 && p[i].getState4() == true) {
					p[index_of_minimim_priority].setState2(false);
					p[i].setState2(true);
					if (p[index_of_minimim_priority].getArrivalTime() > p[i].getArrivalTime()) {
						index_of_minimim_priority = i;
					}
				}
			}

			for (int i = 0; i < p.length; i++) {
				if (p[index_of_minimim_priority].getPriority() == p[i].getPriority() && index_of_minimim_priority != i
						&& p[i].getBurstTime() > 0) {

					if ((p[index_of_minimim_priority].getBurstTime() + time) <= p[i].getArrivalTime()) {
						p[index_of_minimim_priority].setState3(true);
					}
				}
			}

			int temp = 0;
			int time_diff = time + p[index_of_minimim_priority].getBurstTime();
			int new_burst = 0;
			for (int i = 0; i < p.length; i++) {
				if (p[index_of_minimim_priority].getPriority() > p[i].getPriority() && i != index_of_minimim_priority
						&& p[i].getBurstTime() > 0 && p[i].getArrivalTime() < time_diff
						&& p[index_of_minimim_priority].getState3() == true) {
					temp = i;
					p[index_of_minimim_priority].setState2(false);
					new_burst = time_diff - p[i].getArrivalTime();

				}
			}

			if (num == 1 && p[index_of_minimim_priority].getState() == true)
				System.out.print(" P[" + index_of_minimim_priority + "]  |");
			else if (num == 1 && p[index_of_minimim_priority].getState() == false)
				System.out.print(" idel  |");
			else if (num == 0)
				System.out.print("-------|");
			else if (num == 2)
				System.out.print(time + "      ");

			int t = 0;

			if (p[index_of_minimim_priority].getState() == false) {
				for (int i = 0; i < p.length; i++) {
					if (p[i].getArrivalTime() > p[index_of_minimim_priority].getArrivalTime()) {
						if (t == 0)
							time = p[i].getArrivalTime();
						t = 1;
						if (time > p[i].getArrivalTime())
							time = p[i].getArrivalTime();
					}
				}
				j = j - 1;
			}

			if (p[index_of_minimim_priority].getState3() == false) {
				if (p[index_of_minimim_priority].getBurstTime() >= 2) {
					p[index_of_minimim_priority].setBurstTime(p[index_of_minimim_priority].getBurstTime() - 2);

					time = time + 2;
					p[index_of_minimim_priority].setArrivalTime(time);
					if (p[index_of_minimim_priority].getBurstTime() > 0)
						size = size + 1;

				} else {
					p[index_of_minimim_priority].setBurstTime(0);

					time = time + 1;
				}

			} else if (p[index_of_minimim_priority].getState2() == false) {
				p[index_of_minimim_priority].setBurstTime(new_burst);
				time = p[temp].getArrivalTime();
				p[index_of_minimim_priority].setState2(true);
				size = size + 1;
			}

			else {
				time = time + p[index_of_minimim_priority].getBurstTime();

				p[index_of_minimim_priority].setBurstTime(0);
			}
			for (int i = 0; i < p.length; i++) {
				if (p[index_of_minimim_priority].getPriority() == p[i].getPriority() && index_of_minimim_priority != i
						&& p[i].getBurstTime() > 0) {
					p[index_of_minimim_priority].setState4(false);
					p[i].setState4(true);
				}
			}

		}
		if (num == 2)
			System.out.print(time + "      ");
		System.out.println();
	}

}

//Class Process is for assigning processes using ArrayLists
class Process {

	private int process_num;
	private int arrival_time;
	private int burst_time;
	private boolean state2 = true;
	private boolean state = false;
	private boolean state3 = true;
	private boolean state4 = true;
	public int priority;

	public Process() {
	}

	ArrayList<Process> array = new ArrayList<Process>();

	public Process(int process_num) {
		this.process_num = process_num;
	}

	public void addprocess(Process p) {
		array.add(p);
	}

	public Process getProcess(int i) {
		return array.get(i);
	}

	public int getSize() {
		return array.size();
	}

	public int getProcessNum() {
		return process_num;
	}

	public void setProcessNum(int process_num) {
		this.process_num = process_num;
	}

	public boolean getState2() {
		return state2;
	}

	public void setState2(boolean state2) {
		this.state2 = state2;
	}

	public boolean getState4() {
		return state4;
	}

	public void setState4(boolean state4) {
		this.state4 = state4;
	}

	public boolean getState3() {
		return state3;
	}

	public void setState3(boolean dd) {
		this.state3 = dd;
	}

	public void setArrivalTime(int arrival_time) {
		this.arrival_time = arrival_time;
	}

	public int getArrivalTime() {
		return arrival_time;
	}

	public void setState(boolean state) {
		this.state = state;

	}

	public boolean getState() {
		return state;
	}

	public void setBurstTime(int burst_time) {
		this.burst_time = burst_time;
	}

	public int getBurstTime() {
		return burst_time;
	}

	public int getPriority() {
		return priority;
	}

	public void setPriority(int priority) {
		this.priority = priority;
	}

}