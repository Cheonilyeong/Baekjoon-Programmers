import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter

fun main(args: Array<String>) {

    val br = BufferedReader(InputStreamReader(System.`in`));
    val bw = BufferedWriter(OutputStreamWriter(System.out));

    val N = br.readLine().toInt();
    val stack = MutableList<Int>(0) {it};

    (1..N).forEach() {
        val op = br.readLine().split(" ");

        if(op[0]=="push") {
            stack.add(op[1].toInt());
        }
        if(op[0]=="pop") {
            if(stack.isNotEmpty()) {
                bw.write(stack.last().toString());
                stack.removeLast();
            }
            else bw.write("-1");
            bw.write("\n");
        }
        if(op[0]=="size") {
            bw.write(stack.size.toString());
            bw.write("\n");
        }
        if(op[0]=="empty") {
            if(stack.isEmpty()) bw.write("1\n");
            else bw.write("0\n");
        }
        if(op[0]=="top") {
            if(stack.isNotEmpty()) {
                bw.write(stack.last().toString());
            }
            else bw.write("-1");
            bw.write("\n");
        }
    }

    br.close();
    bw.flush();
    bw.close();

}