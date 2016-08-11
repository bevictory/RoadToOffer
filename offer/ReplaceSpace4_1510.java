package offer;

import java.io.InputStreamReader;
import java.util.Scanner;

import javax.net.ssl.SSLContext;

public class ReplaceSpace4_1510 {
	private char[]string = new char[10000000];
	private int length;
	public void replaceBlank(int length){
		if(length <=0 ){
			return;
		}
		
		int blank_num = 0;
		int string_length = 0;
		for(int i = 0; string[i]!='\0'; i++){
			if(string[i] == ' '){
				blank_num ++;
			}
			string_length++;
		}
		
		int new_length = blank_num*2 + string_length;
		this.length = new_length;
		while(string_length >= 0 && new_length > string_length){
			if(string[string_length] == ' '){
				string[new_length--] ='0';
				string[new_length--]= '2';
				string[new_length--]= '%';
			}else {
				string[new_length--] = string[string_length];
			}
			string_length--;
		}
		
	}
	public void input(){
		Scanner scanner = new Scanner(System.in);
		int i=0;
		String str = scanner.nextLine();
		while(i <str.length()){
			string[i]= str.charAt(i);
			i++;
		}
		string[i]= '\0';
		replaceBlank(100);
		System.out.println(new String(string, 0, length));
		
	}
	public static void main(String []args){
		ReplaceSpace4_1510 s = new ReplaceSpace4_1510();
		s.input();
		
	}

}
