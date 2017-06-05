#include "srmp_SRMPJni.h"
#include <srmp/SRMP.h>

#include <jni.h>

using namespace srmpLib;


/*
 * Class:     srmp_SRMPJni
 * Method:    Options
 * Signature: ()J
 */
JNIEXPORT jlong JNICALL Java_srmp_SRMPJni_Options
        (JNIEnv *env, jclass cls) {
    Energy::Options *options = new Energy::Options();
    return reinterpret_cast<jlong>(options);
}

/*
 * Class:     srmp_SRMPJni
 * Method:    Options_SetMethod
 * Signature: (JI)V
 */
JNIEXPORT void JNICALL Java_srmp_SRMPJni_Options_1SetMethod
(JNIEnv *env, jclass cls, jlong handle, jint method) {
    Energy::Options *options = reinterpret_cast<Energy::Options*>(handle);

    switch (method) {
        case 0:
            options->method = Energy::Options::SRMP;
            break;
        case 1:
            options->method = Energy::Options::MPLP;
            break;
        case 2:
            options->method = Energy::Options::MPLP_BW;
            break;
        case 3:
            options->method = Energy::Options::CMP;
            break;
        default:
            options->method = Energy::Options::SRMP;
            break;
    }
}

/*
 * Class:     srmp_SRMPJni
 * Method:    Options_GetMethod
 * Signature: (J)I
 */
JNIEXPORT jint JNICALL Java_srmp_SRMPJni_Options_1GetMethod
        (JNIEnv *env, jclass cls, jlong handle) {
    Energy::Options *options = reinterpret_cast<Energy::Options*>(handle);
    return options->method;
}

/*
 * Class:     srmp_SRMPJni
 * Method:    Options_SetMaxIterations
 * Signature: (JI)V
 */
JNIEXPORT void JNICALL Java_srmp_SRMPJni_Options_1SetMaxIterations
(JNIEnv *env, jclass cls, jlong handle, jint max_iterations) {
    Energy::Options *options = reinterpret_cast<Energy::Options*>(handle);
    options->iter_max = max_iterations;
}

/*
 * Class:     srmp_SRMPJni
 * Method:    Options_GetMaxIterations
 * Signature: (J)I
 */
JNIEXPORT jint JNICALL Java_srmp_SRMPJni_Options_1GetMaxIterations
        (JNIEnv *env, jclass cls, jlong handle) {
    Energy::Options *options = reinterpret_cast<Energy::Options*>(handle);
    return options->iter_max;
}

/*
 * Class:     srmp_SRMPJni
 * Method:    Options_SetMaxTime
 * Signature: (JD)V
 */
JNIEXPORT void JNICALL Java_srmp_SRMPJni_Options_1SetMaxTime
(JNIEnv *env, jclass cls, jlong handle, jdouble max_time) {
    Energy::Options *options = reinterpret_cast<Energy::Options*>(handle);
    options->time_max = max_time;
}

/*
 * Class:     srmp_SRMPJni
 * Method:    Options_GetMaxTime
 * Signature: (J)D
 */
JNIEXPORT jdouble JNICALL Java_srmp_SRMPJni_Options_1GetMaxTime
        (JNIEnv *env, jclass cls, jlong handle) {
    Energy::Options *options = reinterpret_cast<Energy::Options*>(handle);
    return options->time_max;
}

/*
 * Class:     srmp_SRMPJni
 * Method:    Options_SetEPS
 * Signature: (JD)V
 */
JNIEXPORT void JNICALL Java_srmp_SRMPJni_Options_1SetEPS
(JNIEnv *env, jclass cls, jlong handle, jdouble eps) {
    Energy::Options *options = reinterpret_cast<Energy::Options*>(handle);
    options->eps = eps;
}

/*
 * Class:     srmp_SRMPJni
 * Method:    Options_GetEPS
 * Signature: (J)D
 */
JNIEXPORT jdouble JNICALL Java_srmp_SRMPJni_Options_1GetEPS
        (JNIEnv *env, jclass cls, jlong handle) {
    Energy::Options *options = reinterpret_cast<Energy::Options*>(handle);
    return options->eps;
}

/*
 * Class:     srmp_SRMPJni
 * Method:    Options_SetComputeSolutionPeriod
 * Signature: (JI)V
 */
JNIEXPORT void JNICALL Java_srmp_SRMPJni_Options_1SetComputeSolutionPeriod
(JNIEnv *env, jclass cls, jlong handle, jint compute_solution_period) {
    Energy::Options *options = reinterpret_cast<Energy::Options*>(handle);
    options->compute_solution_period = compute_solution_period;
}

/*
 * Class:     srmp_SRMPJni
 * Method:    Options_GetComputeSolutionPeriod
 * Signature: (J)I
 */
JNIEXPORT jint JNICALL Java_srmp_SRMPJni_Options_1GetComputeSolutionPeriod
        (JNIEnv *env, jclass cls, jlong handle) {
    Energy::Options *options = reinterpret_cast<Energy::Options*>(handle);
    return options->compute_solution_period;
}

/*
 * Class:     srmp_SRMPJni
 * Method:    Options_SetPrintTimes
 * Signature: (JZ)V
 */
JNIEXPORT void JNICALL Java_srmp_SRMPJni_Options_1SetPrintTimes
(JNIEnv *env, jclass cls, jlong handle, jboolean print_times) {
    Energy::Options *options = reinterpret_cast<Energy::Options*>(handle);
    options->print_times = print_times;
}

/*
 * Class:     srmp_SRMPJni
 * Method:    Options_GetPrintTimes
 * Signature: (J)Z
 */
JNIEXPORT jboolean JNICALL Java_srmp_SRMPJni_Options_1GetPrintTimes
        (JNIEnv *env, jclass cls, jlong handle) {
    Energy::Options *options = reinterpret_cast<Energy::Options*>(handle);
    return (jboolean) options->print_times;
}

/*
 * Class:     srmp_SRMPJni
 * Method:    Options_SetSortFlag
 * Signature: (JI)V
 */
JNIEXPORT void JNICALL Java_srmp_SRMPJni_Options_1SetSortFlag
(JNIEnv *env, jclass cls, jlong handle, jint sort_flag) {
    Energy::Options *options = reinterpret_cast<Energy::Options*>(handle);
    options->sort_flag = sort_flag;
}

/*
 * Class:     srmp_SRMPJni
 * Method:    Options_GetSortFlag
 * Signature: (J)I
 */
JNIEXPORT jint JNICALL Java_srmp_SRMPJni_Options_1GetSortFlag
        (JNIEnv *env, jclass cls, jlong handle) {
    Energy::Options *options = reinterpret_cast<Energy::Options*>(handle);
    return options->sort_flag;
}

/*
 * Class:     srmp_SRMPJni
 * Method:    Options_SetIsVerbose
 * Signature: (JZ)V
 */
JNIEXPORT void JNICALL Java_srmp_SRMPJni_Options_1SetIsVerbose
(JNIEnv *env, jclass cls, jlong handle, jboolean verbose) {
    Energy::Options *options = reinterpret_cast<Energy::Options*>(handle);
    options->verbose = verbose;
}

/*
 * Class:     srmp_SRMPJni
 * Method:    Options_GetIsVerbose
 * Signature: (J)Z
 */
JNIEXPORT jboolean JNICALL Java_srmp_SRMPJni_Options_1GetIsVerbose
        (JNIEnv *env, jclass cls, jlong handle) {
    Energy::Options *options = reinterpret_cast<Energy::Options*>(handle);
    return (jboolean) options->verbose;
}

/*
 * Class:     srmp_SRMPJni
 * Method:    Options_SetTRWSWeighting
 * Signature: (JD)V
 */
JNIEXPORT void JNICALL Java_srmp_SRMPJni_Options_1SetTRWSWeighting
(JNIEnv *env, jclass cls, jlong handle, jdouble trws_weighting) {
    Energy::Options *options = reinterpret_cast<Energy::Options*>(handle);
    options->TRWS_weighting = trws_weighting;
}

/*
 * Class:     srmp_SRMPJni
 * Method:    Options_GetTRWSWeighting
 * Signature: (J)D
 */
JNIEXPORT jdouble JNICALL Java_srmp_SRMPJni_Options_1GetTRWSWeighting
        (JNIEnv *env, jclass cls, jlong handle) {
    Energy::Options *options = reinterpret_cast<Energy::Options*>(handle);
    return options->TRWS_weighting;
}
