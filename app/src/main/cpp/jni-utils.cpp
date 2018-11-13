#include <jni.h>
#include <string>
#include <clocale>
#include <cstddef>

extern "C" JNIEXPORT jint JNICALL
Java_cn_com_hwtc_jnitest_MainActivity_calculateAdd(
        JNIEnv *env,
        jobject /* this */, jint num1, jint num2) {
    return num1 + num2;
}

extern "C" JNIEXPORT jintArray JNICALL
Java_cn_com_hwtc_jnitest_MainActivity_sortArray(
        JNIEnv *env,
        jobject /* this */, jintArray arr_, jboolean ascendingOrder) {
    //1.获取arr数组的元素
    jint *arr = env->GetIntArrayElements(arr_, NULL);
    //2.获取arr数组的长度
    jsize arrSize = env->GetArrayLength(arr_);
    //3.冒泡排序(升序),如果是降序则将">"改为"<"即可
    if (ascendingOrder) {
        for (int i = 0; i < arrSize; i++) {
            //比较两个相邻的元素
            for (int j = 0; j < arrSize - i - 1; j++) {
                if (arr[j] > arr[j + 1]) {
                    int t = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = t;
                }
            }
        }
    } else {
        for (int i = 0; i < arrSize; i++) {
            //比较两个相邻的元素
            for (int j = 0; j < arrSize - i - 1; j++) {
                if (arr[j] < arr[j + 1]) {
                    int t = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = t;
                }
            }
        }
    }

    //4.释放内存
    env->ReleaseIntArrayElements(arr_, arr, 0);
    //5.返回数组
    return arr_;

}



