#include "srmp_SRMPJni.h"
#include <srmp/SRMP.h>
#include <srmp/FactorTypes/GeneralType.h>
#include <srmp/FactorTypes/PairwiseDualType.h>
#include <srmp/FactorTypes/PairwiseType.h>
#include <srmp/FactorTypes/PatternType.h>
#include <srmp/FactorTypes/PottsType.h>
#include <srmp/FactorTypes/SharedPairwiseType.h>


#include <jni.h>

using namespace srmpLib;


/*
 * Class:     srmp_SRMPJni
 * Method:    Energy
 * Signature: (I)J
 */
JNIEXPORT jlong JNICALL Java_srmp_SRMPJni_Energy
        (JNIEnv *env, jclass cls, jint node_num_max) {
    Energy *energy = new Energy(node_num_max);
    return reinterpret_cast<jlong>(energy);
}

/*
 * Class:     srmp_SRMPJni
 * Method:    Energy_AddNode
 * Signature: (JI[D)I
 */
JNIEXPORT jint JNICALL Java_srmp_SRMPJni_Energy_1AddNode
        (JNIEnv *env, jclass cls, jlong handle, jint K, jdoubleArray costs) {
    Energy *energy = reinterpret_cast<Energy*>(handle);

    if (costs == NULL) {
        return energy->AddNode(K, NULL);
    }

    jsize len = env->GetArrayLength(costs);

    if (len == 0) {
        return energy->AddNode(K, NULL);
    }

    // XXX Check memory usage here.
    double *native_costs = env->GetDoubleArrayElements(costs, 0);
    return energy->AddNode(K, native_costs);
}

/*
 * Class:     srmp_SRMPJni
 * Method:    Energy_AddUnaryFactor
 * Signature: (JI[D)J
 */
JNIEXPORT jlong JNICALL Java_srmp_SRMPJni_Energy_1AddUnaryFactor
        (JNIEnv *env, jclass cls, jlong handle, jint i, jdoubleArray costs) {
    Energy *energy = reinterpret_cast<Energy*>(handle);
    Energy::FactorId factorId;
    double *native_costs = NULL;

    if (costs != NULL) {
        jsize len = env->GetArrayLength(costs);

        if (len > 0) {
            // XXX Check memory usage here.
            native_costs = env->GetDoubleArrayElements(costs, 0);
        }
    }

    factorId = energy->AddUnaryFactor(i, native_costs);
    return reinterpret_cast<jlong>(factorId);
}

/*
 * Class:     srmp_SRMPJni
 * Method:    Energy_AddPairwiseFactor
 * Signature: (JII[D)J
 */
JNIEXPORT jlong JNICALL Java_srmp_SRMPJni_Energy_1AddPairwiseFactor
        (JNIEnv *env, jclass cls, jlong handle, jint i, jint j, jdoubleArray costs) {
    Energy *energy = reinterpret_cast<Energy*>(handle);

    double *native_costs = NULL;

    if (costs != NULL) {
        jsize len = env->GetArrayLength(costs);

        if (len > 0) {
            // XXX Check memory usage here.
            native_costs = env->GetDoubleArrayElements(costs, 0);
        }
    }

    Energy::FactorId factor = energy->AddPairwiseFactor(i, j, native_costs);
    return reinterpret_cast<jlong>(factor);
}

/*
 * Class:     srmp_SRMPJni
 * Method:    Energy_AddFactor
 * Signature: (JI[I[DI)J
 */
JNIEXPORT jlong JNICALL Java_srmp_SRMPJni_Energy_1AddFactor
        (JNIEnv *env, jclass cls, jlong handle, jint arity, jintArray node_indices, jdoubleArray costs, jint type) {
    Energy *energy = reinterpret_cast<Energy*>(handle);

    int *native_node_indices = env->GetIntArrayElements(node_indices, 0);

    double *native_costs = NULL;

    if (costs != NULL) {
        jsize len = env->GetArrayLength(costs);

        if (len > 0) {
            // XXX Check memory usage here.
            native_costs = env->GetDoubleArrayElements(costs, 0);
        }
    }

    Energy::FactorType *factor_type = NULL;

    switch (type) {
        case 0:
            factor_type = new PottsFactorType();
            break;
        case 1:
            factor_type = new PairwiseFactorType();
            break;
        case 2:
            factor_type = new PairwiseDualFactorType();
            break;
        case 3:
            factor_type = new PatternFactorType();
            break;
        case 4:
            // XXX SharedPairwiseFactorType is an abstract class.
//            int k1 = energy->GetK(native_node_indices[0]);
//            int k2 = energy->GetK(native_node_indices[1]);
//            factor_type = new SharedPairwiseFactorType(k1, k2, native_costs);
            break;
        case 5:
        default:
            factor_type = new GeneralFactorType();
            break;
    }

    Energy::FactorId factor = energy->AddFactor(arity, native_node_indices, native_costs, factor_type);
    return reinterpret_cast<jlong>(factor);
}

/*
 * Class:     srmp_SRMPJni
 * Method:    Energy_GetNodeNum
 * Signature: (J)I
 */
JNIEXPORT jint JNICALL Java_srmp_SRMPJni_Energy_1GetNodeNum
        (JNIEnv *env, jclass cls, jlong handle) {
    Energy *energy = reinterpret_cast<Energy*>(handle);
    return energy->GetNodeNum();
}

/*
 * Class:     srmp_SRMPJni
 * Method:    Energy_GetK
 * Signature: (JI)I
 */
JNIEXPORT jint JNICALL Java_srmp_SRMPJni_Energy_1GetK
        (JNIEnv *env, jclass cls, jlong handle, jint i) {
    Energy *energy = reinterpret_cast<Energy*>(handle);
    return energy->GetK(i);
}

/*
 * Class:     srmp_SRMPJni
 * Method:    Energy_Solve
 * Signature: (JJ)D
 */
JNIEXPORT jdouble JNICALL Java_srmp_SRMPJni_Energy_1Solve
        (JNIEnv *env, jclass cls, jlong handle, jlong options_handle) {
    Energy *energy = reinterpret_cast<Energy*>(handle);
    Energy::Options *options = reinterpret_cast<Energy::Options*>(options_handle);
    return energy->Solve(*options);
}

/*
 * Class:     srmp_SRMPJni
 * Method:    Energy_GetSolution
 * Signature: (JI)I
 */
JNIEXPORT jint JNICALL Java_srmp_SRMPJni_Energy_1GetSolution
        (JNIEnv *env, jclass cls, jlong handle, jint i) {
    Energy *energy = reinterpret_cast<Energy*>(handle);
    return energy->GetSolution(i);
}

/*
 * Class:     srmp_SRMPJni
 * Method:    Energy_SetMinimalEdges
 * Signature: (J)V
 */
JNIEXPORT void JNICALL Java_srmp_SRMPJni_Energy_1SetMinimalEdges
(JNIEnv *env, jclass cls, jlong handle) {
    Energy *energy = reinterpret_cast<Energy*>(handle);
    energy->SetMinimalEdges();
}

/*
 * Class:     srmp_SRMPJni
 * Method:    Energy_SetFullEdges
 * Signature: (JI)V
 */
JNIEXPORT void JNICALL Java_srmp_SRMPJni_Energy_1SetFullEdges
(JNIEnv *env, jclass cls, jlong handle, jint method) {
    Energy *energy = reinterpret_cast<Energy*>(handle);
    energy->SetFullEdges(method);
}

/*
 * Class:     srmp_SRMPJni
 * Method:    Energy_SetFullEdgesDual
 * Signature: (JI)V
 */
JNIEXPORT void JNICALL Java_srmp_SRMPJni_Energy_1SetFullEdgesDual
(JNIEnv *env, jclass cls, jlong handle, jint sort_flag) {
    Energy *energy = reinterpret_cast<Energy*>(handle);
    energy->SetFullEdgesDual(sort_flag);
}

/*
 * Class:     srmp_SRMPJni
 * Method:    Energy_AddRelaxationEdge
 * Signature: (JJJ)V
 */
JNIEXPORT void JNICALL Java_srmp_SRMPJni_Energy_1AddRelaxationEdge
(JNIEnv *env, jclass cls, jlong handle, jlong factorA, jlong factorB) {
    Energy *energy = reinterpret_cast<Energy*>(handle);
    Energy::FactorId factorIdA = reinterpret_cast<Energy::FactorId>(factorA);
    Energy::FactorId factorIdB = reinterpret_cast<Energy::FactorId>(factorB);
    energy->AddRelaxationEdge(factorIdA, factorIdB);
}

/*
 * Class:     srmp_SRMPJni
 * Method:    Energy_IsSuperset
 * Signature: (JJ)V
 */
JNIEXPORT jboolean JNICALL Java_srmp_SRMPJni_Energy_1IsSuperset
(JNIEnv *env, jclass cls, jlong factorA, jlong factorB) {
    Energy::FactorId factorIdA = reinterpret_cast<Energy::FactorId>(factorA);
    Energy::FactorId factorIdB = reinterpret_cast<Energy::FactorId>(factorB);
    return (jboolean) Energy::isSuperset(factorIdA, factorIdB);
}

/*
 * Class:     srmp_SRMPJni
 * Method:    Energy_AddTriplet
 * Signature: (JIIIZ)V
 */
JNIEXPORT void JNICALL Java_srmp_SRMPJni_Energy_1AddTriplet
(JNIEnv *env, jclass cls, jlong handle, jint i, jint j, jint k, jboolean add_all_edges) {
    Energy *energy = reinterpret_cast<Energy*>(handle);
    energy->AddTriplet(i, j, k, add_all_edges);
}

/*
 * Class:     srmp_SRMPJni
 * Method:    Energy_SaveUAI
 * Signature: (JLjava/lang/String;ZZ)V
 */
JNIEXPORT void JNICALL Java_srmp_SRMPJni_Energy_1SaveUAI
(JNIEnv *env, jclass cls, jlong handle, jstring filename, jboolean sort_factors, jboolean save_reparameterization) {
    Energy *energy = reinterpret_cast<Energy*>(handle);
    const char *nativeFileName = env->GetStringUTFChars(filename, 0);

    energy->SaveUAI((char *) nativeFileName, sort_factors, save_reparameterization);
    env->ReleaseStringUTFChars(filename, nativeFileName);
}

/*
 * Class:     srmp_SRMPJni
 * Method:    Energy_PrintStats
 * Signature: (J)V
 */
JNIEXPORT void JNICALL Java_srmp_SRMPJni_Energy_1PrintStats
(JNIEnv *env, jclass cls, jlong handle) {
    Energy *energy = reinterpret_cast<Energy*>(handle);
    energy->PrintStats();
}
