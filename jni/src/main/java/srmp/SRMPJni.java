package srmp;

public class SRMPJni {
    static {
        System.loadLibrary("srmp-jni");
    }

    // Energy::Options class

    public static native long Options();

    public static native void Options_SetMethod(long cPtr, int method);

    public static native int Options_GetMethod(long cPtr);

    public static native void Options_SetMaxIterations(long cPtr, int maxIter);

    public static native int Options_GetMaxIterations(long cPtr);

    public static native void Options_SetMaxTime(long cPtr, double maxTime);

    public static native double Options_GetMaxTime(long cPtr);

    public static native void Options_SetEPS(long cPtr, double eps);

    public static native double Options_GetEPS(long cPtr);

    public static native void Options_SetComputeSolutionPeriod(long cPtr, int computeSolutionPeriod);

    public static native int Options_GetComputeSolutionPeriod(long cPtr);

    public static native void Options_SetPrintTimes(long cPtr, boolean printTimes);

    public static native boolean Options_GetPrintTimes(long cPtr);

    public static native void Options_SetSortFlag(long cPtr, int sortFlag);

    public static native int Options_GetSortFlag(long cPtr);

    public static native void Options_SetIsVerbose(long cPtr, boolean isVerbose);

    public static native boolean Options_GetIsVerbose(long cPtr);

    public static native void Options_SetTRWSWeighting(long cPtr, double trwsWeighting);

    public static native double Options_GetTRWSWeighting(long cPtr);

    // Energy class

    public static native long Energy(int node_num_max);

    public static native int Energy_AddNode(long cPtr, int K, double[] costs);

    public static native long Energy_AddUnaryFactor(long cPtr, int i, double[] costs);

    public static native long Energy_AddPairwiseFactor(long cPtr, int i, int j, double[] costs);

    public static native long Energy_AddFactor(long cPtr, int arity, int[] nodeIndices, double[] costs, int type);

    public static native int Energy_GetNodeNum(long cPtr);

    public static native int Energy_GetK(long cPtr, int i);

    public static native double Energy_Solve(long cPtr, long optionsPtr);

    public static native int Energy_GetSolution(long cPtr, int i);

    public static native void Energy_SetMinimalEdges(long cPtr);

    public static native void Energy_SetFullEdges(long cPtr, int method);

    public static native void Energy_SetFullEdgesDual(long cPtr, int sortFlag);

    public static native void Energy_AddRelaxationEdge(long cPtr, long factorA, long factorB);

    public static native boolean Energy_IsSuperset(long factorA, long factorB);

    public static native void Energy_AddTriplet(long cPtr, int i, int j, int k, boolean addAllEdges);

    public static native void Energy_SaveUAI(long cPtr, String filename, boolean sortFactors, boolean saveReparameterization)
;

    public static native void Energy_PrintStats(long cPtr);
}
