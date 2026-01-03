#ifndef TEMPLATES_H
#define TEMPLATES_H

////Plain function - other files just need prototype
////  Putting implementation in .h and including from multiple
////  .cpp files will result in linker error because of multiple definitions
int simpleSmaller(int x, int y);

//////Template function - BAD - attempt to just prototype
/////   Compiler needs to see whole definition for templated functions
// template <typename T>
// T smaller(T x, T y);

////Template function done correctly - all code in .h file
///   compiler does work to handle possible multiple instantiations
template<typename T>
T smaller(const T& x, const T& y) {
  if (x < y)
    return x;
  else
    return y;
}

#endif // TEMPLATES_H
