package srmp;

public final class Energy {
    private final long nativeHandle;

    public Energy(int nodeNumMax) {
        this.nativeHandle = SRMPJni.Energy(nodeNumMax);
    }

    public Node addNode(int K, double[] costs) {
        int nodeId = SRMPJni.Energy_AddNode(this.nativeHandle, K, costs);
        return new Node(nodeId);
    }

    public Factor addUnaryFactor(Node n, double[] costs) {
        long factorId = SRMPJni.Energy_AddUnaryFactor(this.nativeHandle, n.nodeId, costs);
        return new Factor(factorId);
    }

    public Factor addPairwiseFactor(Node i, Node j, double[] costs) {
        long factorId = SRMPJni.Energy_AddPairwiseFactor(this.nativeHandle, i.nodeId, j.nodeId, costs);
        return new Factor(factorId);
    }

    public Factor addFactor(int arity, Node[] nodes, double[] costs, FactorType factorType) {
        int numNodes = nodes.length;
        int[] nodeIndices = new int[numNodes];

        for(int i = 0; i < numNodes; i++) {
            nodeIndices[i] = nodes[i].nodeId;
        }

        long factorId = SRMPJni.Energy_AddFactor(this.nativeHandle, arity, nodeIndices, costs, factorType.ordinal());
        return new Factor(factorId);
    }

    public int getNodeNum() {
        return SRMPJni.Energy_GetNodeNum(this.nativeHandle);
    }

    public int getK(Node i) {
        return SRMPJni.Energy_GetK(this.nativeHandle, i.nodeId);
    }

    public double solve(EnergyOptions options) {
        return SRMPJni.Energy_Solve(this.nativeHandle, options.getNativeHandle());
    }

    public int getSolution(Node i) {
        return SRMPJni.Energy_GetSolution(this.nativeHandle, i.nodeId);
    }

    public void setMinimalEdges() {
        SRMPJni.Energy_SetMinimalEdges(this.nativeHandle);
    }

    public void setFullEdges(int method) {
        SRMPJni.Energy_SetFullEdges(this.nativeHandle, method);
    }

    public void setFullEdgesDual(int sortFlag) {
        SRMPJni.Energy_SetFullEdgesDual(this.nativeHandle, sortFlag);
    }

    public void addRelaxationEdge(Factor factorA, Factor factorB) {
        SRMPJni.Energy_AddRelaxationEdge(this.nativeHandle, factorA.factorId, factorB.factorId);
    }

    public void addTriplet(Node i, Node j, Node k, boolean addAllEdges) {
        SRMPJni.Energy_AddTriplet(this.nativeHandle, i.nodeId, j.nodeId, k.nodeId, addAllEdges);
    }

    public void saveUAI(String filename, boolean sortFactors, boolean saveReparameterization) {
        SRMPJni.Energy_SaveUAI(this.nativeHandle, filename, sortFactors, saveReparameterization);
    }

    public void printStats() {
        SRMPJni.Energy_PrintStats(this.nativeHandle);
    }

    public static boolean isSuperset(Factor factorA, Factor factorB) {
        return SRMPJni.Energy_IsSuperset(factorA.factorId, factorB.factorId);
    }
}
