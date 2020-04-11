package main_package;

public class MyThread extends Thread{
	
	private Vector v;
	
	public MyThread(Vector vec) {
		this.v = vec;
	}
	
	public void run() {
		System.out.println("[" + Thread.currentThread().getName() + "] Started correctly.");
		
		for(int i=1; i< v.length(); i++) {
			int key = v.get(i);
			
			int j = i-1;
			while(j>=0 && v.get(j)>key) {
				v.set(j+1, v.get(j));
				j--;
			}
			v.set(j+1, key);
		}
	}
	
}
