import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val bw = BufferedWriter(OutputStreamWriter(System.out))

    val(N, L) = br.readLine().split(" ").map { it.toInt() }

    val names = ArrayList<CharArray>(N)
    for(i in 0 until N) {
        val name = br.readLine().toCharArray()
        names.add(name)
    }


    var ret = "CALL FRIEND"
    for(index in 0 until L) {
        val t = names[0][index]
        for(alpha in 'A'..'Z') {
            names[0][index] = alpha

            var flag = true
            for(i in 1 until N) {
                var count = 0
                for(j in 0 until L) {
                    if(names[i][j] != names[0][j]) count++
                }
                if(count > 1) flag = false
            }
            if(flag) ret = String(names[0])
        }
        names[0][index] = t
    }

    println("${ret}")

    br.close()
    bw.close()
}