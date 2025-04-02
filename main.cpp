#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>


using namespace std;


double mapValue(double x)
{
	return -1 + ((x - 1) / 4.0) * 3.0;
}


int main()
{
	ifstream ifstr("data.txt");
	ofstream ofstr("result.txt");
	
	if (ifstr.fail())
	{
		cerr << "File not found" << endl;
		return 1;
	}
	
	ofstr << "# N Mean" << endl;
	double sum = 0.0;
	double mean;
	int N = 0;
	double val;
	while(ifstr >> val)
	{
		N++;
		val = mapValue(val);
		sum += val;
		mean = sum / N;
		ofstr << scientific << setprecision(16) << N << " " << mean << endl;	
	}
	
	ifstr.close();
	ofstr.close();

	cout << "Check result.txt" << endl;
	
    return 0;
}
