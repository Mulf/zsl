#include <iostream>
#include <zsl.h>

#include <matplot/matplot.h>


using namespace zsl;


int main()
{
	double Fs = 1000;            // Sampling frequency                    
	double T = 1 / Fs;             // Sampling period       
	double L = 1500;             // Length of signal
	auto t = colon(0, L - 1) * T;        // Time vector

	auto S = 0.8 + 0.7 * sin(2 * pi * 50 * t) + sin(2 * pi * 120 * t);

	auto X = S + 2 * rand_v(S.size());


	{
		using namespace matplot;

		figure();
		plot(1000 * t, X);
		title("Signal Corrupted with Zero-Mean Random Noise");
		xlabel("t (milliseconds)");
		ylabel("|fft(X)|");

		figure();
		auto Y = fft(X);
		plot(Fs / L * colon(0, L - 1), abs(Y))->line_width(3);
		title("Complex Magnitude of fft Spectrum");
		xlabel("f (Hz)");
 		ylabel("|fft(X)|");
	}

	return 0;
}