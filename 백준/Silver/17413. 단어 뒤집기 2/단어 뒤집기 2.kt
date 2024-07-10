import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val bw = BufferedWriter(OutputStreamWriter(System.out))

    val str = br.readLine()

    var flag = false
    var t = StringBuilder()
    var ret = StringBuilder()
    str.forEach {
        if(flag) {
            t.append(it)
            if(it == '>') {
                ret.append(t)
                t.clear()
                flag = false
            }
        }
        else {
            if(it == '<') {
                ret.append(t.reverse())
                t.clear()

                t.append(it)
                flag = true
            }
            else if(it == ' ') {
                ret.append(t.reverse())
                ret.append(' ')
                t.clear()
            }
            else {
                t.append(it)
            }
        }
    }
    if(t.length > 0) {
        ret.append(t.reverse())
    }

    println("${ret.toString()}")

    br.close()
    bw.close()
}
