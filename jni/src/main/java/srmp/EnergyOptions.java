package srmp;

public final class EnergyOptions {
    private long nativeHandle;

    public EnergyOptions() {
        this.nativeHandle = SRMPJni.Options();
    }

    long getNativeHandle() {
        return this.nativeHandle;
    }

    public SolverType getSolverType() {
        int solverMethod =  SRMPJni.Options_GetMethod(this.nativeHandle);
        return SolverType.values()[solverMethod];
    }

    public void setSolverType(SolverType solverType) {
        SRMPJni.Options_SetMethod(this.nativeHandle, solverType.ordinal());
    }

    public int getMaxIterations() {
        return SRMPJni.Options_GetMaxIterations(this.nativeHandle);
    }

    public void setMaxIterations(int maxIterations) {
        SRMPJni.Options_SetMaxIterations(this.nativeHandle, maxIterations);
    }

    public double getMaxTime() {
        return SRMPJni.Options_GetMaxTime(this.nativeHandle);
    }

    public void setMaxTime(double maxTime) {
        SRMPJni.Options_SetMaxTime(this.nativeHandle, maxTime);
    }

    public double getEps() {
        return SRMPJni.Options_GetEPS(this.nativeHandle);
    }

    public void setEps(double eps) {
        SRMPJni.Options_SetEPS(this.nativeHandle, eps);
    }

    public int getComputeSolutionPeriod() {
        return SRMPJni.Options_GetComputeSolutionPeriod(this.nativeHandle);
    }

    public void setComputeSolutionPeriod(int computeSolutionPeriod) {
        SRMPJni.Options_SetComputeSolutionPeriod(this.nativeHandle, computeSolutionPeriod);
    }

    public boolean isPrintTimes() {
        return SRMPJni.Options_GetPrintTimes(this.nativeHandle);
    }

    public void setPrintTimes(boolean printTimes) {
        SRMPJni.Options_SetPrintTimes(this.nativeHandle, printTimes);
    }

    public int getSortFlag() {
        return SRMPJni.Options_GetSortFlag(this.nativeHandle);
    }

    public void setSortFlag(int sortFlag) {
        SRMPJni.Options_SetSortFlag(this.nativeHandle, sortFlag);
    }

    public boolean isVerbose() {
        return SRMPJni.Options_GetIsVerbose(this.nativeHandle);
    }

    public void setVerbose(boolean verbose) {
        SRMPJni.Options_SetIsVerbose(this.nativeHandle, verbose);
    }

    public double getTrwsWeighting() {
        return SRMPJni.Options_GetTRWSWeighting(this.nativeHandle);
    }

    public void setTrwsWeighting(double trwsWeighting) {
        SRMPJni.Options_SetTRWSWeighting(this.nativeHandle, trwsWeighting);
    }

    @Override
    protected void finalize() throws Throwable {
        SRMPJni.Options_Dispose(this.nativeHandle);
        super.finalize();
    }
}
