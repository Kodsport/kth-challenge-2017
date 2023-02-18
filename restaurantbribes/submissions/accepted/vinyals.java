import java.util.StringTokenizer;
import java.io.BufferedReader;
import java.io.BufferedOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.io.OutputStream;

import java.util.Arrays;
import java.util.Map;
import java.util.TreeMap;
import java.util.TreeSet;
import java.util.PriorityQueue;
import java.util.Comparator;
import java.util.ArrayList;
import java.util.HashSet;
import java.lang.Math;

public class vinyals {
static Kattio io = new Kattio(System.in, System.out);

double opt(double a, double b) {
  double mx=0;
  for (int x=1;x<=10;++x) {
    mx=Math.max(mx,b*x-a*a*x*x);
  }
  return mx;
}

void moin() {
  int n = io.getInt();
  int m = io.getInt();
  int k = io.getInt();
  ArrayList<ArrayList<Integer>> g = new ArrayList<ArrayList<Integer>>(n);
  for (int i=0;i<n;++i) g.add(new ArrayList<Integer>());
  for (int i=0;i<m;++i) {
    int a = io.getInt()-1;
    int b = io.getInt()-1;
    g.get(a).add(b);
    g.get(b).add(a);
  }
  boolean[] isbribed = new boolean[n];
  int[] bribesfirst = new int[k];
  double[] bribessecond = new double[k];
  for (int i=0;i<k;++i) {
    bribesfirst[i] = io.getInt()-1;
    bribessecond[i] = io.getInt();
    isbribed[bribesfirst[i]]=true;
  }
  ArrayList<ArrayList<Integer>> ng = new ArrayList<ArrayList<Integer>>(n);
  for (int i=0;i<n;++i) {
    ArrayList<Integer> t = new ArrayList<Integer>();
    for (int v : g.get(i)) if (isbribed[v]) t.add(v);
    ng.add(t);
  }
  double ans=0;
  for (int i=0;i<k;++i) {
    double influence=0;
    for(int j : g.get(bribesfirst[i])) {
      if (isbribed[j]) continue;
      // Might need to sum in proper order...
      influence+=100./ng.get(j).size();
    }
    ans+=opt(bribessecond[i],influence);
  }
  io.println(ans);
}

  public static void main(String[] argv) {
    new vinyals().moin();
    io.close();
  }
}
  
/** Simple yet moderately fast I/O routines.
 *
 * Example usage:
 *
 * Kattio io = new Kattio(System.in, System.out);
 *
 * while (io.hasMoreTokens()) {
 *    int n = io.getInt();
 *    double d = io.getDouble();
 *    double ans = d*n;
 *
 *    io.println("Answer: " + ans);
 * }
 *
 * io.close();
 *
 *
 * Some notes:
 *
 * - When done, you should always do io.close() or io.flush() on the
 *   Kattio-instance, otherwise, you may lose output.
 *
 * - The getInt(), getDouble(), and getLong() methods will throw an
 *   exception if there is no more data in the input, so it is generally
 *   a good idea to use hasMoreTokens() to check for end-of-file.
 *
 * @author: Kattis
 */

class Kattio extends PrintWriter {
    public Kattio(InputStream i) {
	super(new BufferedOutputStream(System.out));
	r = new BufferedReader(new InputStreamReader(i));
    }
    public Kattio(InputStream i, OutputStream o) {
	super(new BufferedOutputStream(o));
	r = new BufferedReader(new InputStreamReader(i));
    }

    public boolean hasMoreTokens() {
	return peekToken() != null;
    }

    public int getInt() {
	return Integer.parseInt(nextToken());
    }

    public double getDouble() { 
	return Double.parseDouble(nextToken());
    }

    public long getLong() {
	return Long.parseLong(nextToken());
    }

    public String getWord() {
	return nextToken();
    }



    private BufferedReader r;
    private String line;
    private StringTokenizer st;
    private String token;

    private String peekToken() {
	if (token == null) 
	    try {
		while (st == null || !st.hasMoreTokens()) {
		    line = r.readLine();
		    if (line == null) return null;
		    st = new StringTokenizer(line);
		}
		token = st.nextToken();
	    } catch (IOException e) { }
	return token;
    }

    private String nextToken() {
	String ans = peekToken();
	token = null;
	return ans;
    }
}
