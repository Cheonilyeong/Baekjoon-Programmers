import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter

fun main(args: Array<String>) {

    val br = BufferedReader(InputStreamReader(System.`in`));
    val bw = BufferedWriter(OutputStreamWriter(System.out));

    val N = br.readLine().toInt();
    val cost = Array<IntArray>(N+1) {IntArray(size=3) {0}};

    for(i in 1..N) {
        val num = br.readLine().split(" ");
        cost[i][0] = num[0].toInt();
        cost[i][1] = num[1].toInt();
        cost[i][2] = num[2].toInt();
    }

    val dp = Array<IntArray>(N+1) {IntArray(3) {0}};

    dp[1][0] = cost[1][0];
    dp[1][1] = cost[1][1];
    dp[1][2] = cost[1][2];
    for(i in 2..N) {
        dp[i][0] = Math.min(dp[i-1][1],dp[i-1][2]) + cost[i][0];
        dp[i][1] = Math.min(dp[i-1][0],dp[i-1][2]) + cost[i][1];
        dp[i][2] = Math.min(dp[i-1][0],dp[i-1][1]) + cost[i][2];
    }

    bw.write(Math.min(Math.min(dp[N][0],dp[N][1]),dp[N][2]).toString());

    br.close();
    bw.flush();
    bw.close();
}