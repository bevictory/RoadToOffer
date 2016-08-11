package offer;

import java.io.IOException;
import java.io.StreamTokenizer;
import java.io.BufferedReader;
import java.io.InputStreamReader;
public class findElemInMatrix3_1384 {
	 private int[][] matric;
		private boolean flag = false; 
		private void inputOutput() throws IOException{
	    	StreamTokenizer st = new StreamTokenizer(new BufferedReader(
	                new InputStreamReader(System.in)));
	        while(st.nextToken() != StreamTokenizer.TT_EOF){
	        	flag = false;
	            int row = (int)st.nval;
	            st.nextToken();
	            int column = (int)st.nval;
	            st.nextToken();
	            int cand = (int)st.nval;
	            if(!(0<row && row<=1000 && 0<column && column<=1000 && 0<cand && cand<=1000000)){
	                continue;
	            }
	            matric = new int[row][column];
	            for(int i=0; i<row; i++)
	                for(int j=0; j<column; j++){
	                	st.nextToken();
	                    matric[i][j] = (int)st.nval;
	                }
	            flag= find(row, column, cand);
	            if(flag == false)
	                System.out.println("No");
	            else
	                System.out.println("Yes");
	        }
	    }

	boolean find( int row, int col, int numbers){
		boolean found = false;
		if(matric!=null&&row>0&&col > 0){
			int r =0, c = col -1;
			while(r<row&& col >=0){
				if(matric[r][c] == numbers) return true;
				else if(matric[r][c] > numbers ) c--;
				else r++;
			}
		}
		return found;
	}
	public static void main(String []args){
		findElemInMatrix3_1384 c = new findElemInMatrix3_1384();
		try {
			c.inputOutput();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
 	}

}
