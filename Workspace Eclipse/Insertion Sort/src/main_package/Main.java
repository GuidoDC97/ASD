package main_package;

public class Main {
	public static void main(String args[]) {
		double startTime, endTime, timeElapsed = 0.0;
		
		Vector v = new Vector(100000);
		System.out.println("INITIAL VECTOR");
		v.printVector();
		
//		int[] vettore = new int[100000];
//		for(int i=0; i< vettore.length; i++)
//			vettore[i] = (int)(Math.random()*100);
//		
		
//		//Thread execution
//		Thread thread = new MyThread(v);
//		
//		System.out.println("\n\n################################################################\n\nSORTING...");
//		startTime = System.nanoTime();
//		thread.start();
//		
//		try {
//			thread.join();
//			endTime = System.nanoTime();
//			timeElapsed = endTime - startTime;
//		} catch (InterruptedException e) {
//			e.printStackTrace();
//		}
//		
//		//v.printVector();
//		System.out.println("\nREPORT:");
//		System.out.println("Execution time in nanoseconds  : " + timeElapsed);
//		System.out.println("Execution time in milliseconds : " + timeElapsed / 1000000);
//		System.out.println("Execution time in seconds : " + timeElapsed / 1000000000);
		
		//Sequential execution
		System.out.println("\n\n################################################################\n\nSORTING...");
		startTime = System.nanoTime();
		InsertionSort.insertionSort(v);
//		InsertionSort.insertionSort(vettore);
		endTime = System.nanoTime();
		timeElapsed = endTime - startTime;
		
		//v.printVector();
		System.out.println("\nREPORT:");
		System.out.println("Execution time in nanoseconds  : " + timeElapsed);
		System.out.println("Execution time in milliseconds : " + timeElapsed / 1000000);
		System.out.println("Execution time in seconds : " + timeElapsed / 1000000000);
	}
}
