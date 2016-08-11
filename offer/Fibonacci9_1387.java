package offer;

import java.awt.Image;
import java.util.Scanner;

public class Fibonacci9_1387 {
	
	
	public long  get(int n){
		int result[]={0,1};
		if(n<2) return result[n];
		long one = 1;
		long two = 0;
		long f=0;
		for(int i = 2 ; i <= n;i++){
			f = one + two;
			
			two =one;one = f;
		}
		return f;
	}
	public void input(){
		Scanner scanner = new Scanner(System.in);
		while(scanner.hasNext()){
		int n = scanner.nextInt();
		System.out.println(get(n));}
		
	
	}
	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Fibonacci9_1387 s = new Fibonacci9_1387();
		s.input();
 	}

}
