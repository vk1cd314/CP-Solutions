import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;
 
public class A_Strange_Table {
      public static void main(String[] args) throws NumberFormatException, IOException {
            FastScanner fs = new FastScanner();
            PrintWriter out = new PrintWriter(System.out);
 
            int t = fs.nextInt();
            while (t-- > 0) {
                  long n = fs.nextLong(), m = fs.nextLong(), x = fs.nextLong();
                  long j = x / n + 1;
                  long i = x - n * (j - 1);
                  if (i == 0) {
                        i = n;
                        --j;
                  }
                  out.println(m * (i - 1) + j);
            }
 
            out.close();
      }
 
      static class FastScanner {
            BufferedReader br;
            StringTokenizer st;
 
            public FastScanner() {
                  br = new BufferedReader(new InputStreamReader(System.in));
            }
 
            public FastScanner(String fileName) throws FileNotFoundException {
                  br = new BufferedReader(new FileReader(fileName));
            }
 
            String next() {
                  while (st == null || !st.hasMoreElements()) {
                        try {
                              st = new StringTokenizer(br.readLine());
                        } catch (IOException e) {
                              e.printStackTrace();
                        }
                  }
                  return st.nextToken();
            }
 
            int nextInt() {
                  return Integer.parseInt(next());
            }
 
            long nextLong() {
                  return Long.parseLong(next());
            }
 
            double nextDouble() {
                  return Double.parseDouble(next());
            }
 
            char[][] readCharArray(int n, int m) {
                  String str;
                  char[][] arr = new char[n][m];
                  for (int i = 0; i < n; ++i) {
                        str = nextLine();
                        for (int j = 0; j < n; ++j) {
                              arr[i][j] = str.charAt(j);
                        }
                  }
                  return arr;
            }
 
            char[][] readCharArray(int n) {
                  return readCharArray(n, n);
            }
 
            int[] readArray(int n) {
                  int[] a = new int[n];
                  for (int i = 0; i < n; ++i) {
                        a[i] = nextInt();
                  }
                  return a;
            }
 
            long[] readLongArray(int n) {
                  long[] a = new long[n];
                  for (int i = 0; i < n; ++i) {
                        a[i] = nextLong();
                  }
                  return a;
            }
 
            String nextLine() {
                  String str = "";
                  try {
                        str = br.readLine();
                  } catch (IOException e) {
                        e.printStackTrace();
                  }
                  return str;
            }
      }
}