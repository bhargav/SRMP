#include "HelloJNI.h"
#include <iostream>

using namespace std;

JNIEXPORT void JNICALL Java_HelloJNI_sayHello(JNIEnv *, jobject) {
    cout << "Hello World from C++!" << endl;
    return;
}

