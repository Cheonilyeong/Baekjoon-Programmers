import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`));
    val bw = BufferedWriter(OutputStreamWriter(System.out));

    val num = br.readLine().toInt();

    val dp = Array<Int>(1000003) {0};

    dp[1] = 1;  // 1
    dp[2] = 2;  // 11 or 00
    for(i in 3..dp.lastIndex) {
        dp[i] = (dp[i-1]%15746 + dp[i-2]%15746)%15746;
    }

    bw.write("${dp[num]}");

    br.close();
    bw.flush();
    bw.close();
}