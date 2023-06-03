rm -rf build
rm src/parser/lexer.cpp
rm src/parser/parser.cpp
rm src/parser/parser.output
rm include/parser.h
mkdir build
pushd build
cmake ..
make
cp spl_run ../spl_run
popd