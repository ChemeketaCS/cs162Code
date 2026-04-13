#include <format>
#include <iostream>
#include <vector>

using namespace std;

// Ensure given value is between 0 and 255 and return as uint8_t
uint8_t clamp(double value) {
  if (value < 0) return 0;
  if (value > 255) return 255;
  return static_cast<uint8_t>(value);
}

class Color {
private:
  uint8_t m_red = 0;
  uint8_t m_green = 0;
  uint8_t m_blue = 0;

public:
  Color() {}
  Color(uint8_t r, uint8_t g, uint8_t b) {
    m_blue = b;
    m_green = g;
    m_red = r;
  }

  string toHex() const {
    return std::format("#{0:02X}{1:02X}{2:02X}", getRed(), getGreen(), getBlue());
  }
  string toRGB() const {
    return std::format("rgb({0}, {1}, {2})", getRed(), getGreen(), getBlue());
  }

  uint8_t getRed() const {
    return m_red;
  }
  uint8_t getGreen() const {
    return m_green;
  }
  uint8_t getBlue() const {
    return m_blue;
  }

  void setRed(uint8_t r) {
    m_red = r;
  }
  void setGreen(uint8_t g) {
    m_green = g;
  }
  void setBlue(uint8_t b) {
    m_blue = b;
  }

  void darken(double factor) {
    m_red = clamp(getRed() * (1 - factor));
    m_green = clamp(getGreen() * (1 - factor));
    m_blue = clamp(getBlue() * (1 - factor));
  }

  void changeTo(const Color& other) {
    m_red = other.getRed();
    m_green = other.getGreen();
    m_blue = other.getBlue();
  }

  Color blend(const Color& other, double alpha) const {
    const uint8_t r = clamp(getRed() * (1 - alpha) + other.getRed() * alpha);
    const uint8_t g = clamp(getGreen() * (1 - alpha) + other.getGreen() * alpha);
    const uint8_t b = clamp(getBlue() * (1 - alpha) + other.getBlue() * alpha);
    return Color(r, g, b);
  }
};



int main () {
  vector<Color> colors;
  colors.push_back(Color(255, 0, 0)); 
  colors.push_back(Color(0, 255, 0)); 
  colors.push_back(Color(0, 0, 255));

  for (const Color& c : colors) {
    std::cout << "Color: " << c.toHex() << " (" << c.toRGB() << ")" << std::endl;
  }

  cout << "-----------------------------------------" << endl;
  Color start(199, 115, 56); // dark orange
  Color end; //black
  int steps = 5;
  vector<Color> gradient;
  for (int i = 0; i <= steps; i++) {
    double alpha = (1.0 * i) / steps;
    const Color blended = start.blend(end, alpha);
    gradient.push_back(blended);
  }
  
  for (const Color& c : gradient) {
    std::cout << "Gradient: " << c.toHex() << " (" << c.toRGB() << ")" << std::endl;
  }

  cout << "-----------------------------------------" << endl;
  Color c1(255, 0, 0); // red
  std::cout << "c1: " << c1.toHex() << " (" << c1.toRGB() << ")" << std::endl;
  Color c2(0, 0, 255); // blue
  c1.changeTo(c2); // c1 should now be blue
  std::cout << "After changeTo: " << c1.toHex() << " (" << c1.toRGB() << ")" << std::endl;
}
