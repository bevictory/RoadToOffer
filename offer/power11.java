package offer;

public class power11 {
	
	private boolean invalidInput = false;
	double power(double base, int exponent){
		if(Math.abs(base-0) < 10e-6&&exponent <0){
			invalidInput = true;
			return 0;
		}
		int absExponent=exponent;
		if(exponent<0){
			absExponent = -exponent;
		}
		double result = unsignPower(base, absExponent);
		if(exponent < 0){
			result = 1.0 /result;
		}return result;
	}
	public double unsignPower(double base, int exponent){
		if(exponent == 0 ) return 1;
		if(exponent == 1) return base;
		double result =unsignPower(base, exponent>>1);
		result*= result;
		if((exponent&1)==1){
			result = result*base;
		}
		
		return result;
	}
	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}

}
