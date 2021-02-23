package cn.com.hwtc.jni;

import android.app.Activity;
import android.os.Bundle;
import android.os.Handler;
import android.widget.TextView;

public class MainActivity extends Activity {

    static {
        System.loadLibrary("nativeLib");
        System.loadLibrary("jniUtils");
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        TestJNI testJNI = new TestJNI();
        final TextView tv = findViewById(R.id.sample_text);
        tv.setText(testJNI.stringFromJNI());
        Handler mHandler = new Handler();
        mHandler.postDelayed(() -> tv.setText(String.valueOf(testJNI.calculateAdd(10, 5))), 2000L);

        mHandler.postDelayed(() -> {
            int[] sortArray = testJNI.sortArray(new int[]{10, 5, 7, 25, 465, -32}, false);
            StringBuilder builder = new StringBuilder();
            for (int value : sortArray) {
                builder.append(value).append(",");
            }
            tv.setText(builder.toString());
        }, 5000L);
    }
}
