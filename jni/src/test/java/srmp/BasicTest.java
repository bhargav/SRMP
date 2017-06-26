package srmp;

import org.junit.Test;

public class BasicTest {
    @Test
    public void testBasicSRMP() {
        Energy energyInstance = new Energy(5);
        Node first = energyInstance.addNode(2, new double[] { -1, 1});
        Node second = energyInstance.addNode(2, new double[] {1, -1});
        energyInstance.addFactor(
                2,
                new Node[] { first, second },
                new double[] { 1, 1, -1, 1 },
                FactorType.GeneralFactorType);

        EnergyOptions options = new EnergyOptions();
        options.setVerbose(false);

        // Just making sure that SRMP works with the native library.
        energyInstance.solve(options);
    }
}