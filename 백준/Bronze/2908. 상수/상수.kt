import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter

fun main(args: Array<String>) {
    val br = BufferedReader(InputStreamReader(System.`in`));
    val bw = BufferedWriter(OutputStreamWriter(System.out));

    val num = br.readLine().split(" ");

    var num1 = num[0];
    var num2 = num[1];

    if(num1.reversed().toInt() > num2.reversed().toInt()) println(num1.reversed());
    else println(num2.reversed());
    
    br.close();
    bw.flush();
    br.close();
}