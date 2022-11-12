import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class Main {
    static class FastReader{
        BufferedReader br,br1;
        StringTokenizer st;
        public FastReader() {br = new BufferedReader(new InputStreamReader(System.in));}
        public FastReader(String fileName) throws FileNotFoundException{br = new BufferedReader(new FileReader(fileName));}
        String next() {while (st == null || !st.hasMoreElements()){try{st = new StringTokenizer(br.readLine());}catch (IOException  e){e.printStackTrace();}}return st.nextToken();}
        int nextInt() {return Integer.parseInt(next());}
        long nextLong() {return Long.parseLong(next());}
        double nextDouble() {return Double.parseDouble(next());}
        char[][] readCharArray(int n, int m) {
        	String str;
        	char[][] arr = new char[n][m];
        	for(int i = 0; i < n; ++i) {
        		str=nextLine();
        		for(int j = 0;j < n; ++j) {
        			arr[i][j] = str.charAt(j);
        		}
        	}
        	return arr;
        }
        char[][] readCharArray(int n) {
        	return readCharArray(n,n);
        }
        int[] readArray(int n) {int[] a = new int[n]; for (int i = 0; i < n; ++i) a[i] = nextInt(); return a;}
        long[] readLongArray(int n) {long[] a=new long[n];for (int i = 0; i < n; ++i) a[i] = nextLong(); return a;}
        String nextLine() {String str = "";try{str = br.readLine();} catch (IOException e){e.printStackTrace();} return str;}
    }
    public static void main(String[] args) throws NumberFormatException, IOException {
        FastReader fs = new FastReader();
        PrintWriter out = new PrintWriter(System.out);
        int n = fs.nextInt();
        int ans = 0, cnt1 = -1;
        for (int i = 1; i <= n; ++i) {
            int temp = i;
            int cnt = 0;
            while (temp % 2 == 0) {
                temp /= 2;
                ++cnt;
            }
            if (cnt >= cnt1) {
                cnt1 = cnt;
                ans = i;
            }
        }
        out.println(ans);
        out.close();
    }

}