#include <matplot/matplot.h>
#include <pybind/pybind.h>
#include <iostream>
#include <string>
#include <vector>
#include <complex>
#include <algorithm>
#include <cmath>
#define PI 3.14159265358979323846

using namespace std;
using namespace matplot;

vector<double> sinGen(double freq, double fSmpl, double dur) {
	int sampl = fSmpl * dur;
	vector<double> sinus(sampl);
	for (int i = 0; i < sampl; i++) {
		sinus[i] = sin(2 * PI * freq * i / fSmpl);
	}
	return sinus;
}

vector<double> cosGen(double freq, double fSmpl, double dur) {
	int sampl = fSmpl * dur;
	vector<double> cosin(sampl);
	for (int i = 0; i < sampl; i++) {
		cosin[i] = cos(2 * PI * freq * i / fSmpl);
	}
	return cosin;
}
vector<double> recGen(double freq, double fSmpl, double dur) {
	int sampl = fSmpl * dur;
	double period = 1 / freq;
	double tSmpl = (dur / sampl);
	vector<double> rect(sampl);
	for (int i = 0; i < sampl; i++) {
		double time = i * tSmpl;
		double perFract = fmod(time, period); // /period?
		rect[i] = (perFract < period / 2) ? 1 : -1;
	}
	return rect;
}
vector<double> sawGen(double freq, double fSmpl, double dur) {
	int sampl = fSmpl * dur;
	double tSmpl = (dur / sampl);
	vector<double> saw(sampl);
	for (int i = 0; i < sampl; i++) {
		double time = i * tSmpl;
		saw[i] = 2 * ((time * freq) - floor(0.5 + (time * freq)));
	}
	return saw;
}
vector<complex<double>> DFT(const vector<double>& signal) {
	int sampl = signal.size();
	vector<complex<double>> dft(sampl);
	for (size_t i = 0; i < sampl; i++) {
		complex<double> sum=(0, 0);
		for (size_t j = 0; j < sampl; j++) {
			double angle = -2 * PI * i * j / sampl;
		}
		dft[i] = sum;
	}
	return dft;
}
vector<double>rDFT(const vector<complex<double>>& dft) {
	int sampl = dft.size();
	vector<double> signal(sampl);
	for (size_t i = 0; i < sampl; i++) {
		complex<double> sum = (0, 0);
		for (size_t j = 0; j < sampl; j++) {
			double angle = 2 * PI * i * j / sampl;
			sum += dft[j] * exp(complex<double>(0,(2*PI*j*(static_cast<double>(i)/static_cast<double>(sampl)))));
		}
		signal[i] = sum.real() / static_cast<double>(sampl);
	}
	return signal;
}
vector < double> DF (const vector<double>&signal, const vector<double>&filter) {
	int lSig = signal.size();
	int lFil = filter.size();
	int lRes = lSig + lFil - 1;
	
	vector<double>filtr(lRes);
	for (int i = 0; i < lRes; i++) {
		filtr[i] = 0; 
		for (int j = 0; j < lFil; j++) {
			if (i - j >= 0 && i - j < lSig) {
				filtr[i] += signal[j] * filter[i-j];
			}
		}
	}
	return filtr;
}
void showSig(const vector<double>& signal) {
	int sampl = signal.size();
	vector<double> x(sampl);
	for (int i = 0; i < sampl; i++) {
		x[i] = i;
	}
	plot(x, signal);;
	xlabel("Próbka");
	ylabel("Amplituda");
	title("Wykres sygnału");
	show();
}
void showTransf(const vector<complex<double>>& dft, double fSmpl) {
	int sampl = dft.size();
	vector<double> x(sampl);
	vector<double> y(sampl);
	for (int i = 0; i < sampl/2; i++) {
		x[i] = i * fSmpl /static_cast<double> sampl;
		y[i] = abs(dft[i])*2/sampl;
	}
	auto fig = figure(true);
	stem(x, y);
	xlabel("Częstotliwość");
	ylabel("Amplituda");
	title(Wykres transformaty);
	show();
}


