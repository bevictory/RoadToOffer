package offer;

import java.util.Scanner;

public class FindMinInSortedRotatedArray8_1386 {
	private int[]nums ;
	public int min(){
		if(nums.length == 0) return -1;
		int index1 = 0,index2 = nums.length-1 ,mid;
		mid = index1;
		while(nums[index1] >= nums[index2]){
			if(index1 - index2 == -1){
				index1=index2;
				break;
			}
			mid = (index1+index2)/2;
			if(nums[mid]== nums[index1]&&nums[index1] ==nums[index2] ){
				return minOrder(index1,index2);
			}
			if(nums[mid] >= nums[index1]){
				index1 = mid;
			}else if(nums[mid]<=nums[index2] ){
				index2=mid;
			}
		}
		return nums[index1];
	}
	public void input() {
		Scanner scanner = new Scanner(System.in);
		
			int n = scanner.nextInt();
			nums = new int[n];
			int i = 0;
			while (i < n) {
				nums[i] = scanner.nextInt();
				i++;
			
		}
			
	}
	public int minOrder(int index1,int index2){
		int min = Integer.MAX_VALUE;
		for(int i =index1;i<=index2;i++){
			if(nums[i]<min) min = nums[i];
		}
		return min;
	}
	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		FindMinInSortedRotatedArray8_1386 s =new FindMinInSortedRotatedArray8_1386();
		s.input();
		System.out.println(s.min());
	}

}
