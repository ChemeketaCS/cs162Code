#include <fstream>
#include <iostream>

using namespace std;

int main() {
  fstream inWavFile;
  // Open for input/output in binary mode
  inWavFile.open("drums.wav", ios::in | ios::binary);

  fstream outWavFile;
  // Open for input/output in binary mode
  outWavFile.open("drumsOUT.wav", ios::out | ios::binary);

  int numDataBytes = 0;
  // Jump to location of data size and read it... known to be 4 bytes
  inWavFile.seekp(40);
  inWavFile.read(reinterpret_cast<char*>(&numDataBytes), 4);

  // Assume wave sample size is 16 bits
  const int BITS_PER_SAMPLE = 16;

  // Calculate number of samples in file
  int numSamples = (numDataBytes * 8) / BITS_PER_SAMPLE;

  // Return to start of input file
  inWavFile.seekp(0);
  // Copy first 44 bytes unmodified in one big batch
  char fileStart[44];
  inWavFile.read(fileStart, 44);
  outWavFile.write(fileStart, 44);

  // Copy all the samples one by one
  for (int i = 0; i < numSamples; i++) {
    // Data is 16 bits signed...
    //    must read into right size to keep sign of value
    // Short int is 16 bits
    short val = 0;
    inWavFile.read(reinterpret_cast<char*>(&val), 2);
    // Reduce sample intensity to make quieter
    val /= 4;
    outWavFile.write(reinterpret_cast<char*>(&val), 2);
  }
}
