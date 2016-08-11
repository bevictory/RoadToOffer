package offer;

public class NumberOf1InBinary10 {
	public int getNumOf1(int n){
		int count =0;
		while(n>0){
			count++;
			n= (n-1)&n;
		}
		return count;
	}
	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
	}

}
