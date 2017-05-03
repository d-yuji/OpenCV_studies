#include <iostream>
#include <H5Cpp.h>
#include "boost/multi_array.hpp"

using namespace std;

int main(){

	H5::H5File file("SDS.h5", H5F_ACC_RDONLY);
	H5::DataSet dataset = file.openDataSet("doubleArray2"); 
	H5::DataSpace dataspace = dataset.getSpace();

	int rank = dataspace.getSimpleExtentNdims();

	hsize_t dims_out[2];
	int ndims = dataspace.getSimpleExtentDims( dims_out, NULL);
	int NX = (unsigned long)(dims_out[0]);
	int NY = (unsigned long)(dims_out[1]);
	cout << "rank " << rank << ", dimensions " << NX << " x " << NY << endl;

	boost::multi_array<double,2> data(boost::extents[NX][NY]);

	dataset.read(data.data(),H5::PredType::NATIVE_DOUBLE);

	for(int i=0;i<NX;i++){
		for(int j=0;j<NY;j++) cout << data[i][j] << " ";
		cout << endl;
	}
}