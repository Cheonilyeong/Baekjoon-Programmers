import java.io.BufferedReader
import java.io.InputStreamReader

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))

    val str1 = br.readLine()
    val str2 = br.readLine()

    var index = 0
    var ret = 0
    while(index < str1.length) {

        if(index + str2.length > str1.length) break

        var flag = true
        for(i in 0 until str2.length) {
            if(str1[index+i] != str2[i]) {
                flag = false
                break
            }
        }

        if(flag) {
            index = index+str2.length-1
            ret++
        }

        index++
    }

    println("$ret")
}