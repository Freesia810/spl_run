rm -rf build
rm src/lexer.cpp
rm src/parser.cpp
rm src/parser.h
rm src/parser.output
mkdir build
pushd build
cmake ..
make
popd