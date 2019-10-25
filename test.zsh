cwd=$(pwd)
cd build
cmake ..
make -j10
cd ${cwd}
#./build/singleton && ./build/abs_factory
./build/factory
