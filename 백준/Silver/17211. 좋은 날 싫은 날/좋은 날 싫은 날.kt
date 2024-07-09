import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter
import kotlin.math.ceil

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val bw = BufferedWriter(OutputStreamWriter(System.out))

    val (N, emotion) = br.readLine().trim().split(" ").map { it.toInt() }
    val (HH, HS, SH, SS) = br.readLine().trim().split(" ").map { it.toDouble() }

    // i번째 날 행복할 확률 == (행복->행복) + (슬픔->행복) ??????? 더하기 or 곱하기?

    val dp = Array<DoubleArray>(104) {DoubleArray(2)}
    if(emotion == 0) {
        dp[0][0] = 1.0
        dp[0][1] = 0.0
    }
    else {
        dp[0][0] = 0.0
        dp[0][1] = 1.0
    }
    for(i in 1..N) {
        // 행복
        // 행복->행복 and 슬픔->행복
        dp[i][0] = (dp[i-1][0]*HH) + (dp[i-1][1]*SH)

        // 슬픔
        // 행복->슬픔 and 슬픔->슬픔
        dp[i][1] = (dp[i-1][0]*HS) + (dp[i-1][1]*SS)
    }

    println("${ceil(dp[N][0]*1000).toInt()}")
    println("${ceil(dp[N][1]*1000).toInt()}")

    br.close()
    bw.flush()
    bw.close()
}