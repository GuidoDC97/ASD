package main_package;

public class Vector {

	private int n;
	private int[] structure;
	
	
	public Vector(int dim) {
		this.n = dim;
		this.structure = new int[n];
		for(int i=0; i<n; i++) {
			structure[i] = (int)(Math.random() * 100);
		}
	}
	
	
	public void printVector() {
		System.out.print("[");
		for(int i=0; i<n; i++)
			System.out.print(structure[i] + (i==n-1 ? "" : ","));
		System.out.print("]\n");
	}
	
	public int length() {
		return n;
	}	
	
	public int get(int i) {
		return structure[i];
	}
	
	public void set(int i, int val) {
		this.structure[i] = val;
	}

}
