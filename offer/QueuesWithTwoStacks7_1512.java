package offer;

import java.util.Scanner;
import java.util.Stack;

public class QueuesWithTwoStacks7_1512 {
	private Stack<Integer> stack1 = new Stack<Integer>();
	private Stack<Integer> stack2 = new Stack<Integer>();
	public void offer(int num ){
		stack1.push(num);
	}
	public void delete(){
		if(stack2.isEmpty()){
			while(!stack1.isEmpty()){
				int num = stack1.pop();
				stack2.push(num);
			}
		}
		if(stack2.size() == 0) {
			System.out.println(-1);
			return ;
		}
		System.out.println(stack2.pop());
	}
	public void input(){
		Scanner scanner = new Scanner(System.in);
		int n = scanner.nextInt();
		while(n-->0){
			String s=scanner.next();
			if(s.equals("PUSH")){
				int m = scanner.nextInt();
				offer(m);
			}else if(s.equals("POP")){
				delete();
			}
		}
	}
	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		QueuesWithTwoStacks7_1512 s = new QueuesWithTwoStacks7_1512();
		s.input();
	}

}
