#include "HelloJNI.h"
#include <iostream>
#include <srmp/FactorTypes/PottsType.h>
#include "JniHelpers.h"

using namespace std;
using namespace srmpLib;

JNIEXPORT void JNICALL Java_HelloJNI_sayHello(JNIEnv *, jobject) {
    PottsFactorType* potts = NULL;
    cout << "Hello World from C++!" << endl;
    return;
}

