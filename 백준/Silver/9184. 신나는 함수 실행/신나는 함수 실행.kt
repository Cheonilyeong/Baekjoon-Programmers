import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter

val dp = Array(54){Array(54){Array(54){0}}};

fun w(a:Int, b:Int, c:Int): Int {

    if(a<=0 || b<=0 || c<=0) return 1;
    if(a>20 || b>20 || c>20) {dp[20][20][20] = w(20,20,20); return dp[20][20][20]}
    if(dp[a][b][c] != 0) return dp[a][b][c];
    if(a<b && b<c) {
        dp[a][b][c] = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
        return dp[a][b][c];
    }
    dp[a][b][c] = w(a-1,b,c) + w(a-1,b-1,c) + w(a-1,b,c-1) - w(a-1,b-1,c-1)
    return dp[a][b][c]
}

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`));
    val bw = BufferedWriter(OutputStreamWriter(System.out));

    while(true) {
        val num = br.readLine().split(" ").map { it.toInt() };

        if(num[0]==-1 && num[1]==-1 && num[2]==-1) break;

        bw.write("w(${num[0]}, ${num[1]}, ${num[2]}) = ${w(num[0], num[1], num[2])}\n");
    }

    br.close();
    bw.flush();
    bw.close();
}



