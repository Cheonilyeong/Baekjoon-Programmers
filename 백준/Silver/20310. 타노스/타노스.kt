import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val bw = BufferedWriter(OutputStreamWriter(System.out))

    val str = br.readLine().toCharArray()

    var cnt_0 = 0
    var cnt_1 = 0
    str.forEach {
        when(it) {
            '0' -> cnt_0++
            '1' -> cnt_1++
        }
    }

    cnt_0 /= 2
    cnt_1 /= 2
    val check = BooleanArray(str.size) {false}
    for(i in 0 until str.size) {
        if(cnt_0 > 0 && str[i] == '0') {
            check[i] = true
            cnt_0--
        }
    }
    for(i in str.size-1 downTo 0) {
        if(cnt_1 > 0 && str[i] == '1') {
            check[i] = true
            cnt_1--
        }
    }

    for(i in 0 until str.size) {
        if(check[i]) bw.write("${str[i]}")
    }

    br.close()
    bw.flush()
    bw.close()
}