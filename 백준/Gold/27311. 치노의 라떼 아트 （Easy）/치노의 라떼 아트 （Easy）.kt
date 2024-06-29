import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter
import kotlin.math.sqrt

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val bw = BufferedWriter(OutputStreamWriter(System.out))

    val T = br.readLine().toInt()

    for(t in 0 until T) {
        val (R, C) = br.readLine().split(" ").map { it.toInt() }
        val arr = Array<CharArray>(R) { CharArray(C) }

        var mnY = Int.MAX_VALUE
        var mnX = Int.MAX_VALUE
        var mxY = Int.MIN_VALUE
        var mxX = Int.MIN_VALUE

        // 라떼 모양 받기
        for (i in 0 until R) {
            val a = br.readLine()
            for (j in 0 until C) {
                arr[i][j] = a[j]

                if (arr[i][j] == '#') {
                    mnY = minOf(mnY, i)
                    mnX = minOf(mnX, j)
                    mxY = maxOf(mxY, i)
                    mxX = maxOf(mxX, j)
                }
            }
        }

        // 하트인지 확인
        if (mxY == Int.MAX_VALUE) {
            bw.write("0\n")
            continue
        }
        if (mxY - mnY + 1 < 2 || mxX - mnX + 1 < 2 || mxY - mnY != mxX - mnX) {
            bw.write("0\n")
            continue
        }

        var cnt1 = 0
        var cnt2 = 0
        for (i in mnY until mxY + 1) {
            for (j in mnX until mxX + 1) {
                if (arr[i][j] == '#') cnt1++
                if (arr[i][j] == '.') cnt2++
            }
        }

        if (cnt1 == 0 || cnt2 == 0) {
            bw.write("0\n")
            continue
        }
        if(sqrt(cnt2.toDouble()) % 1.0 != 0.0) {
            bw.write("0\n")
            continue
        }

        val M = sqrt(cnt2.toDouble()).toInt()
        var flag = false

        var cnt = 0
        for(i in mnY until mnY+M) {
            for (j in mnX until mnX+M) {
                if(arr[i][j] == '.') cnt++
            }
        }
        if(cnt == cnt2) flag = true

        cnt = 0
        for(i in mnY until mnY+M) {
            for (j in mxX-M+1 until mxX+1) {
                if(arr[i][j] == '.') cnt++
            }
        }
        if(cnt == cnt2) flag = true

        cnt = 0
        for(i in mxY-M+1 until mxY+1) {
            for (j in mnX until mnX+M) {
                if(arr[i][j] == '.') cnt++
            }
        }
        if(cnt == cnt2) flag = true

        cnt = 0
        for(i in mxY-M+1 until mxY+1) {
            for (j in mxX-M+1 until mxX+1) {
                if(arr[i][j] == '.') cnt++
            }
        }
        if(cnt == cnt2) flag = true

        if(flag) bw.write("1\n")
        else bw.write("0\n")
    }

    br.close()
    bw.flush()
    bw.close()
}