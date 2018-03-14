public class main 
{
    public static void main(String argv[]) 
    {
        System.loadLibrary("MyMathjava"); // Attempts to load example.dll (on Windows) or libexample.so (on Linux)
        System.out.println(MyMathSwig.mysqrt(4.0));
    }
}
