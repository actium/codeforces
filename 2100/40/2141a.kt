fun answer(v:List<Int>)
{
    println("${v.size}")
    println(v.joinToString(" "))
}

fun solve(a:List<Int>)
{
    var v = mutableListOf<Int>()

    var x = 0
    for (i in 1 until a.size) {
        if (a[i] < a[x]) {
            x = i
        } else {
            v.add(1 + i);
        }
    }

    answer(v);
}

fun test_case()
{
    val n = readLine()!!.toInt()
    val a = readLine()!!.split(" ").map(String::toInt)
    solve(a)
}

fun main()
{
    var t = readLine()!!.toInt()
    repeat (t) {
        test_case()
    }
}
