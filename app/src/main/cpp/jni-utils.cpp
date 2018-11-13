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
        jobject /* this */, jintArray arr_) {
    //1.获取arr数组的元素
    jint *arr = env->GetIntArrayElements(arr_, NULL);
    //2.获取arr数组的长度
    jsize arrSize = env->GetArrayLength(arr_);
    //3.遍历数组
    for (int i = 0; i < arrSize; ++i) {
        *(arr + i) += 10;
    }
    //4.释放内存
    env->ReleaseIntArrayElements(arr_, arr, 0);
    //5.返回数组
    return arr_;

}


