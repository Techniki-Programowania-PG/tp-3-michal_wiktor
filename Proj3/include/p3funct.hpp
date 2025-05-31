#pragma once
#include<vector>
#include<complex>
uding namespace std;
vector<double> sinGen(double freq, double fSmpl, double dur);
vector<double> cosGen(double freq, double fSmpl, double dur);
vector<double> recGen(double freq, double fSmpl, double dur);
vector<double> sawGen(double freq, double fSmpl, double dur);
vector<complex<double>>DFT(const vector<double>& signal);
vector<double> rDFT(const vector<complex<double>>& dft);
vector < doubble> DF(const vector<double>& signal,const vector<double>&filter);
void showSig(const vector<double>& signal);
oid showTransf(const vector<complex<double>>& dft, double fSmpl);