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

final int N=20;
int all;

int n,m,l;
int[][] limatrix = new int[1<<N][N];
int[] limatrixsz = new int[1<<N];
int[][] dist = new int[1<<N][N];
int[] reachable = new int[N];
ArrayList<ArrayList<Integer>> g = new ArrayList<ArrayList<Integer>>();
ArrayList<ArrayList<Integer>> switches = new ArrayList<ArrayList<Integer>>();

void add(int mask, int r) {
  for (int s : switches.get(r)) {
    for (int i=0;i<n;++i) {
      if ((s&(1<<i))==0) continue;
      int x = limatrix[mask][i];
      if (x!=0) {
        s^=x;
      }
      else {
        limatrix[mask][i]=s;
        limatrixsz[mask]++;
        break;
      }
    }
  }
}

void dfs(int u) {
  if (reachable[u]!=0) return;
  reachable[u] = 1;
  for (int v : g.get(u)) dfs(v);
}

int bfs() {
  for (int r=0;r<n;++r) {
    add(all,r);
  }
  int goal = limatrixsz[all];
  ArrayDeque<Integer> q = new ArrayDeque<Integer>();
  dist[2][1]=1;
  add(2,1);
  q.add(1);
  q.add(2);
  while (!q.isEmpty()) {
    int r=q.poll();
    int mask=q.poll();
    for (int s : g.get(r)) {
      int nmask=mask|(1<<s);
      if (dist[nmask][s]!=-1) continue;
      dist[nmask][s]=dist[mask][r]+1;
      if (limatrixsz[nmask]==0) {
        limatrixsz[nmask]=limatrixsz[mask];
        limatrix[nmask]=Arrays.copyOf(limatrix[mask],n);
        add(nmask,s);
      }
      if (s==0 && limatrixsz[nmask]==goal) return dist[nmask][s];
      q.add(s);
      q.add(nmask);
    }
  }
  return -1;
}

void moin() {
  for (int[] x : dist) Arrays.fill(x,-1);
  n = io.getInt();
  m = io.getInt();
  l = io.getInt();
  for (int i=0;i<n;++i) {
    g.add(new ArrayList<Integer>());
    switches.add(new ArrayList<Integer>());
  }
  for (int i=0;i<m;++i) {
    int a = io.getInt();
    int b = io.getInt();
    g.get(a).add(b);
    g.get(b).add(a);
  }
  dfs(1);
  all=0;
  for (int i=0;i<n;++i) all |= (reachable[i]<<i);
  //for (auto v : g) {for (auto x : v) cerr << x << ' '; cerr << endl;} cerr << endl;
  for (int i=0;i<l;++i) {
    int r = io.getInt();
    int p = io.getInt();
    int mask=0;
    for (int j=0;j<p;++j) {
      int x = io.getInt();
      mask|=(1<<x);
    }
    switches.get(r).add(mask);
  }
  io.println(bfs());
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
