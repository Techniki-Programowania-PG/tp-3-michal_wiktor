#include<p3funct.hpp>
#include<pybind11/pybind11.h>
#include<pybind11/stl.h>
#include<pybind11/complex.h>

namespace py = pybind11;
PYBIND11_MODULE(proj3, m) {
	m.doc() = "Library for signal processing functions";
	m.def("sinGen", &sinGen, "Generate a sine wave signal",
		parg("freq"), py::arg("fSmpl"), py::arg("dur"));
	m.def("cosGen", &cosGen, "Generate a cosine wave signal",
		py::arg("freq"), py::arg("fSmpl"), py::arg("dur"));
	m.def("recGen", &recGen, "Generate a rectangular wave signal",
		py::arg("freq"), py::arg("fSmpl"), py::arg("dur"));
	m.def("sawGen", &sawGen, "Generate a sawtooth wave signal",
		py::arg("freq"), py::arg("fSmpl"), py::arg("dur"));
	m.def("DFT", &DFT, "Compute the Discrete Fourier Transform of a signal",
		py::arg("signal"));
	m.def("rDFT", &rDFT, "Compute the inverse Discrete Fourier Transform",
		py::arg("dft"));
	m.def("DF", &DF, "Apply a 1D filter to a signal",
		py::arg("signal"), py::arg("filter"));
	m.def("showSig", &showSig, "Visualize a signal",
		py::arg("signal"));
	m.def("showTransf", &showTransf, "Visualize the DFT of a signal",
		py::arg("dft"), py::arg("fSmpl"));
}