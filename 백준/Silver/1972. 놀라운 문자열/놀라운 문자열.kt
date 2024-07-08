import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val bw = BufferedWriter(OutputStreamWriter(System.out))

    while(true) {
        val str = br.readLine()
        if(str == "*") break

        if(str.length == 1 || str.length == 2) {
            bw.write("$str is surprising.\n")
            continue
        }

        var flag = true
        for(i in 0 until str.length-1) {
            val words = HashSet<String>()

            for(index in 0 until str.length) {
                if(index + i + 1 >= str.length) break

                val word = str[index].toString() + str[index+i+1]
                // print("$word ")
                if(words.contains(word)) {
                    flag = false
                    break
                }
                else {
                    words.add(word)
                }
            }

            if(flag == false) break
            // println("")
        }

        if(flag) {
            bw.write("$str is surprising.\n")
        }
        else bw.write("$str is NOT surprising.\n")
    }

    br.close()
    bw.flush()
    bw.flush()
}