package main_package;

public class InsertionSort{

	//private static final int N = 500;
	
	public static Vector insertionSort(Vector v) {
		
		for(int i=1; i< v.length(); i++) {
			int key = v.get(i);
			
			int j = i-1;
			while(j>=0 && v.get(j)>key) {
				v.set(j+1, v.get(j));
				j--;
			}
			v.set(j+1, key);
		}
		return v;
	}
	
	public static int[] insertionSort(int[] v) {
		
		for(int i=1; i< v.length; i++) {
			int key = v[i];
			
			int j = i-1;
			while(j>=0 && v[j]>key) {
				v[j+1] = v[j];
				j--;
			}
			v[j+1] =key;
		}
		return v;
	}

}
