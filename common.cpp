#include "common.hpp"

void Params::init(string config_file)
{
	map<string, string> config_map;
	vector<string> key_list;
	string key, value;

	ifstream file(config_file.c_str());
	if ( !file.good() )
	{
		cerr << "can not read the config file: " <<  config_file <<endl;
		exit(1);
	}

	string line;
	while ( getline(file, line) )
	{
		if( line.length() > 0 && line[0] != '#' && !isblank(line[0]) )
		{
			stringstream ss(line);
			ss >> key >> value;
			config_map[key] = value;
			key_list.push_back(key);
		}
	}

	run_mode           =  config_map["run_mode"];
	deploy_file        =  config_map["deploy_file"];
	weight_file        =  config_map["weight_file"];
	batch_size         =  atoi( config_map["batch_size"].c_str() );
	channel_size       =  atoi( config_map["channel_size"].c_str() );
	image_size         =  atoi( config_map["image_size"].c_str() );
	mean_type          =  config_map["mean_type"];
	mean_value_b       =  float( atof( config_map["mean_value_b"].c_str() ) );
	mean_value_g       =  float( atof( config_map["mean_value_g"].c_str() ) );
	mean_value_r       =  float( atof( config_map["mean_value_r"].c_str() ) );
	mean_file          =  config_map["mean_file"];


	cout << endl << "Init Params from: " << config_file <<endl;
	for(size_t idx = 0; idx != key_list.size(); ++idx)
	{
		cout << std::left << setw(32) << setfill(' ') << key_list[idx];
		cout << config_map[key_list[idx]] <<endl;
	}
	cout << endl;
}