#ifndef COMMON_HPP
#define COMMON_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <iomanip>
#include <cstdlib>

using namespace std;

struct Params
{
	string run_mode;
	string deploy_file;
	string weight_file;
	int batch_size;
	int channel_size;
	int image_size;
	string mean_type;
	float mean_value_b;
	float mean_value_g;
	float mean_value_r;
	string mean_file;

	void init(string config_file);
};


#endif