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

public static int ctz(int i) {
  int y;
  int n = 31;
  y = i <<16; if (y != 0) { n = n -16; i = y; }
  y = i << 8; if (y != 0) { n = n - 8; i = y; }
  y = i << 4; if (y != 0) { n = n - 4; i = y; }
  y = i << 2; if (y != 0) { n = n - 2; i = y; }
  return n - ((i << 1) >>> 31);
}
  
int N=10000;
int M=10000;
  
char[][] seen = new char[N][M];

int n,m;
int i_,j_;
  
void canonical_true() {
  if (i_<0) {
    i_+=n;
    j_-=1;
  }
  else if (i_>=n) {
    i_-=n;
    j_+=1;
  }
  j_+=m;
  j_%=m;
}

void canonical_false() {
  if (j_<0) {
    j_+=m;
    i_-=1;
  }
  else if (j_>=m) {
    j_-=m;
    i_+=1;
  }
  i_+=n;
  i_%=n;
}

boolean set_true(int i, int j) {
  i_=i;j_=j;canonical_true();
  return ++seen[i_][j_]>1;
}

boolean set_false(int i, int j) {
  i_=i;j_=j;canonical_false();
  return ++seen[i_][j_]>1;
}
  
boolean cancycle_true(int jshift) {
  int i=0,j=0,it=0;
  do {
    if (set_true(i,j)) return false;
    if (set_true(i,j+1)) return false;
    if (set_true(i,j-1)) return false;
    if (set_true(i+1,j)) return false;
    if (set_true(i-1,j)) return false;
    if (set_true(i-1,j+1)) return false;
    if (set_true(i-1,j-1)) return false;
    if (set_true(i-2,j)) return false;
    i+=2;
    j+=jshift;
    i_=i;j_=j;canonical_true();i=i_;j=j_;
    ++it;
  } while ((i!=0) || (j!=0));
  return (m*n%(it*8)==0);
}

boolean cancycle_false(int jshift) {
  int i=0,j=0,it=0;
  do {
    if (set_false(i,j)) return false;
    if (set_false(i,j+1)) return false;
    if (set_false(i,j-1)) return false;
    if (set_false(i+1,j)) return false;
    if (set_false(i-1,j)) return false;
    if (set_false(i-1,j+1)) return false;
    if (set_false(i-1,j-1)) return false;
    if (set_false(i-2,j)) return false;
    i+=2;
    j+=jshift;
    i_=i;j_=j;canonical_false();i=i_;j=j_;
    ++it;
  } while ((i!=0) || (j!=0));
  return (m*n%(it*8)==0);
}

boolean clear() {
  for (int i=0;i<n;++i) for (int j=0;j<n;++j) seen[i][j]=0;
  return false;
}
  
boolean tiling() {
  int vn = ctz(n);
  int vm = ctz(m);
  if (vm == 1) return false;
  if (vn + vm <= 2) return false;
  if (vn >= 1 && vm >=2) return true;
  if (vn==0) return cancycle_true(2) || clear() || cancycle_true(-2);
  if (vm==0) return cancycle_false(2) || clear() || cancycle_false(-2);
  return false;
}

void moin() {
  n = io.getInt();
  m = io.getInt();
  io.println(tiling() ? "possible" : "impossible");
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
