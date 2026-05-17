/* Generated test code to dump a table of data for external validation
 * of the noise model parameters.
 */
#include <stdio.h>
#include <assert.h>
double compute_noise_model_entry_S(int plane, int sens);
double compute_noise_model_entry_O(int plane, int sens);
int main(void) {
    for (int plane = 0; plane < 4; plane++) {
        for (int sens = 50; sens <= 100; sens += 100) {
            double o = compute_noise_model_entry_O(plane, sens);
            double s = compute_noise_model_entry_S(plane, sens);
            printf("%d,%d,%lf,%lf\n", plane, sens, o, s);
        }
    }
    return 0;
}

/* Generated functions to map a given sensitivity to the O and S noise
 * model parameters in the DNG noise model. The planes are in
 * R, Gr, Gb, B order.
 */
double compute_noise_model_entry_S(int plane, int sens) {
    static double noise_model_A[] = { 3.2895313865040733e-06,3.3270436863067e-06,3.207590475505531e-06,3.3815130813902735e-06 };
    static double noise_model_B[] = { 2.716064749613393e-06,2.020257622494183e-06,1.2579720933263257e-05,2.233563535124365e-05 };
    double A = noise_model_A[plane];
    double B = noise_model_B[plane];
    double s = A * sens + B;
    return s < 0.0 ? 0.0 : s;
}

double compute_noise_model_entry_O(int plane, int sens) {
    static double noise_model_C[] = { 5.5313411605291196e-11,5.4045425225640007e-11,5.759571085950973e-11,5.622934139381782e-11 };
    static double noise_model_D[] = { 2.6201174290092163e-07,2.5147879021118885e-07,2.394705112003516e-07,2.804384438998711e-07 };
    double digital_gain = (sens / 1000.0) < 1.0 ? 1.0 : (sens / 1000.0);
    double C = noise_model_C[plane];
    double D = noise_model_D[plane];
    double o = C * sens * sens + D * digital_gain * digital_gain;
    return o < 0.0 ? 0.0 : o;
}
