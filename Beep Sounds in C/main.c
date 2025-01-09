#include <windows.h>
#include <stdio.h>
#include <math.h>
        ////Beep Sounds in C////
int main() {

    printf("Playing Music...\n");
    // Define the base frequency (A4 note = 440 Hz)
    double base_frequency = 440.0;
    // Duration of each note in milliseconds
    double time_ms = 1000.0;
    // Calculate the factor for a semitone increase
    // This is the 12th root of 2, as there are 12 semitones in an octave
    double factor = pow(2, 1.0 / 12.0);

    // Loop through 12 semitones (an octave) from the base frequency
    for (int i = 0; i <= 12; i++) {
        // Calculate the frequency of the current note
        double note = base_frequency * pow(factor, i);
        // Play the calculated frequency for the specified duration
        // Beep takes the frequency (Hz) and duration (ms)
        Beep((DWORD)note, (DWORD)time_ms);
    }

    return 0;
}
        ////MATTHEW LUBKER////
