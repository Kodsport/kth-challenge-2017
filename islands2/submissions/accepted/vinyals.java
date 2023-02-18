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
import java.util.ArrayDeque;
import java.lang.Math;

public class vinyals {
static Kattio io = new Kattio(System.in, System.out);

  long[] islandsx;
  long[] islandsy;
  long[] islandsr;
  long[] palmsx;
  long[] palmsy;
  long[] palmsr;
  
long sq(long x) { return x*x; }

long dist2(long px, long py, long qx, long qy) { return sq(px-qx)+sq(py-qy); }

boolean contains(int i, int j) { return dist2(islandsx[i],islandsy[i],palmsx[j],palmsy[j])<=sq(islandsr[i]); }
boolean intersects(int i, int j) { return dist2(islandsx[i],islandsy[i],palmsx[j],palmsy[j])<=sq(islandsr[i]+palmsr[j]); }
  double dist(int i, int j) { return Math.sqrt(dist2(islandsx[i],islandsy[i],islandsx[j],islandsy[j]))-islandsr[i]-islandsr[j]+200; }

ArrayList<ArrayList<Short>> g = new ArrayList<ArrayList<Short>>();
ArrayList<ArrayList<Short>> rg = new ArrayList<ArrayList<Short>>();

ArrayDeque<Integer> order = new ArrayDeque<Integer>();
boolean[] seen1;
void dfs1(int u) {
  if (seen1[u]) return;
  seen1[u]=true;
  for (int v : g.get(u)) dfs1(v);
  order.push(u);
}

int[] out2;
void dfs2(int u, int comp) {
  if (out2[u]!=-1) return;
  out2[u] = comp;
  for (int v : rg.get(u)) dfs2(v,comp);
}

int[] scc() {
  int n=g.size();
  seen1 = new boolean[n];
  for (int i=0;i<n;++i) dfs1(i);
  out2 = new int[n];
  Arrays.fill(out2,-1);
  while(!order.isEmpty()) {
    dfs2(order.peek(), order.peek());
    order.pop();
  }
  return out2;
}
  
void moin() {
  int n = io.getInt();
  int m = io.getInt();
  int k = io.getInt();
  islandsx = new long[n];
  islandsy = new long[n];
  islandsr = new long[n];
  palmsx = new long[m];
  palmsy = new long[m];
  palmsr = new long[m];
  for (int i=0; i<n; ++i) {
    islandsx[i] = io.getInt();
    islandsy[i] = io.getInt();
    islandsr[i] = io.getInt();
  }
  for (int j=0; j<m; ++j) {
    palmsx[j] = io.getInt();
    palmsy[j] = io.getInt();
    palmsr[j] = io.getInt()*k;
  }

  short[][] M = new short[n][n];
  for (int j=0; j<m; ++j) {
    int src=-1;
    int[] dest = new int[n];
    for (int i=0;i<n;++i) {
      if (contains(i,j)) src=i;
      else if (intersects(i,j)) dest[i]=1;
    }
    for (int i=0;i<n;++i) M[src][i]+=dest[i];
  }
  for (int i=0;i<n;++i) {
    g.add(new ArrayList<Short>(n));
    rg.add(new ArrayList<Short>(n));
  }
  for (short i=0;i<n;++i) {
    for (short j=0;j<n;++j) {
      if (M[i][j]!=0) {
        g.get(i).add(j);
        rg.get(j).add(i);
      }
    }
  }

  int[] component = scc();
  int[] parents = new int[n];
  int[] children = new int[n];
  Arrays.fill(parents,-1);
  Arrays.fill(children,-1);
  for (int i=0;i<n;++i) {
    parents[component[i]]=children[component[i]]=0;
  }
  for (int i=0;i<n;++i) {
    for (int j : g.get(i)) {
      if (component[i]==component[j]) continue;
      children[component[i]]++;
      parents[component[j]]++;
    }
  }
  ArrayList<Integer> extremal = new ArrayList<Integer>();
  for (int i=0;i<n;++i) {
    if (component[i]!=i) continue;
    if (parents[i]==0 || children[i]==0) extremal.add(i);
  }

  if (extremal.size()==1) {
    io.println(0);
    return;
  }
  if (extremal.size()>2) {
    io.println("impossible");
    return;
  }

  double best=1e9;
  for (int i=0;i<n;++i) {
    for (int j=0;j<i;++j) {
    if ((component[i]==extremal.get(0) && component[j]==extremal.get(1)) ||
        (component[i]==extremal.get(1) && component[j]==extremal.get(0)))
      best = Math.min(best, dist(i,j));
    }
  }
  io.println(best);
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
