package cn.zhaoping.hellondk;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.widget.TextView;
import android.widget.Toast;

public class MainActivity extends AppCompatActivity {

    // Used to load the 'native-lib' library on application startup.
    static {
        System.loadLibrary("native-lib");
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        // Example of a call to a native method
        TextView tv = (TextView) findViewById(R.id.sample_text);
        tv.setText(stringFromJNI());
        TextView sumtv = findViewById(R.id.sum_text);
        sumtv.setText("" + sum(1, 1));

        MainActivity.this.callbackShowToast();

        findViewById(R.id.c_call_java).setOnClickListener(v -> callbackShowToast());
        findViewById(R.id.c_call_java_add).setOnClickListener(v -> callbackAdd());
    }

    /**
     * A native method that is implemented by the 'native-lib' native library,
     * which is packaged with this application.
     */
    public native String stringFromJNI();

    public native int sum(int x, int y);

    public native void callbackShowToast();

    public native void callbackAdd();

    public void showToast() {
        Toast.makeText(this, "😯我被C调起来了", Toast.LENGTH_SHORT).show();
    }

    public int addNum(int x, int y) {
        Log.e("x+y", "" + x + y);
        Toast.makeText(this, "😯我被C调起来了" + x + y, Toast.LENGTH_SHORT).show();
        return x + y;
    }
}
