package x.jnitry;

import android.app.Activity;
import android.os.Bundle;
import android.view.SurfaceView;
import android.widget.TextView;

import org.opencv.android.CameraBridgeViewBase;
import org.opencv.android.OpenCVLoader;
import org.opencv.core.Mat;

public class MainActivity extends Activity implements CameraBridgeViewBase.CvCameraViewListener2
{
    private CameraBridgeViewBase cameraView;
    
    static {
        System.loadLibrary("native-lib");
    }

    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        cameraView = findViewById(R.id.cameraView);
        cameraView.setVisibility(SurfaceView.VISIBLE);
        cameraView.setCvCameraViewListener(this);
        cameraView.enableView();
    }

    public Mat onCameraFrame(CameraBridgeViewBase.CvCameraViewFrame inputFrame) {
        Mat rgb = inputFrame.rgba();
        processFrame(rgb.getNativeObjAddr());
        return rgb;
    }

    public native void processFrame(long rgb);
    public void onCameraViewStarted(int width, int height) {}
    public void onCameraViewStopped() {}
}