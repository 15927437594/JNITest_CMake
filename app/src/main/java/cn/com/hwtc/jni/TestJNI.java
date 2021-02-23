package cn.com.hwtc.jni;

/**
 * user: Created by jid on 2021/2/23
 * email: jid@hwtc.com.cn
 * description:
 */
public class TestJNI {

    public native String stringFromJNI();

    public native int calculateAdd(int num1, int num2);

    public native int[] sortArray(int[] array, boolean ascendingOrder);
}

