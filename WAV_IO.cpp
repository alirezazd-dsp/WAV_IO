#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
using namespace std;

int main()
{
	ifstream wav_file;
	ofstream out_file;
	wav_file.open("input.wav",ios::binary|ios::ate);
	size_t file_size = wav_file.tellg();
	char * wav_buf = new char[file_size];
	wav_file.seekg (0,ios::beg);
	wav_file.read (wav_buf, file_size);
	wav_file.close();
	int16_t wav_smpl(0);
	char * wav_out = new char[file_size];
	memcpy(wav_out, wav_buf, 44);
	for (size_t i = 0 ; i < file_size ; i += 2)	
	{
		memcpy(&wav_smpl , wav_buf + (i + 44) , 2);
		wav_smpl *= 5;
		memcpy(wav_out + (i + 44) , &wav_smpl , 2);
	}
	out_file.open("output.wav",ios::binary);
	out_file.write(wav_out, file_size);
	out_file.close();
	return 0;
}
