package cn.com.hwtc.jnitest;

import android.os.Bundle;
import android.os.Handler;
import android.support.v7.app.AppCompatActivity;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {

    // Used to load the 'native-lib' library on application startup.
    static {
        System.loadLibrary("native-lib");
        System.loadLibrary("jni-utils");
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        // Example of a call to a native method
        final TextView tv = findViewById(R.id.sample_text);
        tv.setText(stringFromJNI());
        Handler mHandler = new Handler();
        mHandler.postDelayed(new Runnable() {
            @Override
            public void run() {
                tv.setText(String.valueOf(calculateAdd(10, 5)));
            }
        }, 2000L);

        mHandler.postDelayed(new Runnable() {
            @Override
            public void run() {
                int[] sortArray = sortArray(new int[]{10, 5, 7, 25, 465, -32});
                StringBuilder builder = new StringBuilder();
                for (int value : sortArray) {
                    builder.append(value).append(",");
                }
                tv.setText(builder.toString());
            }
        }, 5000L);
    }

    /**
     * A native method that is implemented by the 'native-lib' native library,
     * which is packaged with this application.
     */
    public native String stringFromJNI();

    public native int calculateAdd(int num1, int num2);

    public native int[] sortArray(int[] array);
}
