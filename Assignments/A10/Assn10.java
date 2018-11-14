import java.io.FileWriter;

class Assn10 {
	public static void main(String[] args) {
		System.out.println("i. Floating point number converter.\n");
		float pi = (float) 3.14159265358979;
		System.out.println(pi + " -> " + convertFloat(pi) + "\n");

		 System.out.println( "\nii. Floating point number enumeration.\n");
		 float fp = (float) 0.0;
		 int i = 0;
		 while (fp < 1.4E-44) {
		 	System.out.println((++i) + ("th number: ") + (fp = nextFloat(fp)));
		 }

		System.out.println("\niii. Floating point number counting\n"); 
		int posFPs = countBetween((float) 0.0, Float.MAX_VALUE);
		int zeroOneFPs = countBetween((float)0.0, (float) 1.0);
		System.out.println("Number of positive floating point numbers: " + posFPs + "\n");
		System.out.println("Number of floating point numbers between 0 and 1: " + zeroOneFPs + "\n");
		System.out.println("Proportion (# of 0~1) / (# of positive): " + ((double) zeroOneFPs / (double) posFPs * 100.0) + "%\n");


		// System.out.println("Args passed: " + args.length);
		if (args.length != 1) {
			System.out.println("\niv. Pass the data file name\n");
		} else { 
			System.out.println("\niv. Floating point number distribution\n");
			FileWriter datafile = null;
			try{
				datafile = new FileWriter(args[1]);
				float lower = (float) 0.0, upper, interval = (float) 100.0;
				for (int j = 0; j < 100; j++) {
					upper = lower + interval;
					datafile.write(countBetween(lower, upper) + "\n");
					lower = upper;
				}
			} catch(Exception e){
				e.printStackTrace();
			} finally{
				try{

				datafile.close();
				} catch (Exception e){
					e.printStackTrace();
				}

			}
			
			System.out.println("The output file is ready. Execute \"Python3 Assn9.py" + args[1] + "\"\n");
		}
	}


	static String convertFloat(float number) {
		String floatVars = null;
		int fBits = Float.floatToRawIntBits(number);   //Converts float to hex-int equiv
        int sign = (fBits & 0x80000000) >> 31;
        int exp = (fBits & 0x7f800000) >> 23;
        int mantissa = (fBits & 0x007fffff);
        floatVars = '(' + Integer.toString(sign) + "," + Integer.toString(exp) + "," + Integer.toString(mantissa) + ')';
		return floatVars;
	}

     static float nextFloat(float number) {
        int fBits = Float.floatToIntBits(number);   //Converts float to hex-int equiv
    	int num = ((fBits & 0x007fffff) + 0x00000001);
    	

        return Float.intBitsToFloat(num);
     }


	static int countBetween(float lower, float upper) {
		int lower_i = Float.floatToIntBits(lower); 
		int upper_i = Float.floatToIntBits(upper);

		return upper_i - lower_i;
	}
}