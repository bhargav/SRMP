public class HelloJNI {
    static {
        System.loadLibrary("srmp-jni");
    }

    private native void sayHello();

    public static void main(String[] args) {
        new HelloJNI().sayHello();
    }
}
