// Demonstrates vector vs array speed
//   Build and run in debug mode = substantial advantage for array
//   Build and run in release mode = no significant difference
//                if we use vector in a sane way

#include <cstdlib>
#include <vector>

#include <iostream>
#include <string>

#include <ctime>

const int RUNS = 200;

class TestTimer {
public:
  TestTimer(const std::string& name): name(name) {
    start = clock();
  }

  ~TestTimer() {
    using namespace std;
    double d = clock() - start;

    cout << name << " completed in " << d / CLOCKS_PER_SEC << " seconds"
         << endl;
  }

private:
  std::string name;
  time_t start;
};

struct Pixel {
  Pixel() {
  }

  Pixel(unsigned char r, unsigned char g, unsigned char b): r(r), g(g), b(b) {
  }

  unsigned char r, g, b;
};

void UseVector() {
  TestTimer t("UseVector");

  for (int i = 0; i < RUNS; ++i) {
    int dimension = 999;

    std::vector<Pixel> pixels;
    pixels.resize(dimension * dimension);

    for (int i = 0; i < dimension * dimension; ++i) {
      pixels[i].r = 255;
      pixels[i].g = 0;
      pixels[i].b = 0;
    }
  }
}

void UseVectorPushBack() {
  TestTimer t("UseVectorPushBack");

  for (int i = 0; i < RUNS; ++i) {
    int dimension = 999;

    std::vector<Pixel> pixels;

    for (int i = 0; i < dimension * dimension; ++i)
      pixels.push_back(Pixel(255, 0, 0));
  }
}

void UseArray() {
  TestTimer t("UseArray");

  for (int i = 0; i < RUNS; ++i) {
    int dimension = 999;

    Pixel* pixels = new Pixel[dimension * dimension];

    for (int i = 0; i < dimension * dimension; ++i) {
      pixels[i].r = 255;
      pixels[i].g = 0;
      pixels[i].b = 0;
    }

    delete[] pixels;
  }
}

int main() {
  TestTimer t1("The whole thing");

  UseArray();
  UseVector();
  UseVectorPushBack();

  return 0;
}
