# TensorFlow Windows Prebuilt Library

This is a prebuilt TensorFlow library for Windows. Both static and dynamic libraries are pre-built, which can be used to link to your existing Visual Studio projects.

Three simple steps to build a standalone TensorFlow C++ program:
1. Git clone this project. [Git LFS](https://git-lfs.github.com/) is used to hold large files.
2. Install Visual Studio 2017 Preview 2.1
3. Open this example [Visual Studio solution](./example/examples.sln). Build, and go!

## Enviornment
OS: Windows 10
Compiler: Visual Studio 2017 Preview 2.1

## Steps to Build Libraries Manually
Note that: You can skip this by just cloning my prebuilt library. It's much easier

Open a Visual Studio 2017 command prompt (you can find it in start menu)

```
cd tensorflow/contrib/cmake
mkdir build
cd build

cmake .. -A x64 -DCMAKE_BUILD_TYPE=Release ^
-DSWIG_EXECUTABLE=c:\swigwin-3.0.12\swig.exe ^
-DPYTHON_EXECUTABLE=C:\Users\Peter\AppData\Local\Programs\Python\Python36\python.exe ^
-DPYTHON_LIBRARIES=C:\Users\Peter\AppData\Local\Programs\Python\Python36\libs\python36.lib
```

If you're using Visual Studio 2017, seems that it needs to invoke x64 compiler:
1. Open 'tf_core_kernels' project.
2. Open the property of the project.
3. Choose configuration to 'All Configurations'
4. Choose platform to 'x64 (Active)'
5. Modify `$(VC_ExecutablePath_x64)` to `$(VC_ExecutablePath_x64_x64)`

Then, invoke the builder.

```
MSBuild /p:Configuration=Release ALL_BUILD.vcxproj
```

This will cost more than one hour, and eat more than 8GB memory. Also make sure you're connected to internet before leaving for a cup of coffee.

## Collect Pre-built Libraries
Just execute the [collect script](./collect.sh) to collect them into `include` and `lib` folders.

To figure out what's the actual dependencies, one can take a look of the the project `tf_tutorials_example_trainer`, you can find the linker dependencies in the `<AdditionalDependencies>` tag:
```
Release\tf_protos_cc.lib
zlib\install\lib\zlibstatic.lib
gif\install\lib\giflib.lib
png\install\lib\libpng12_static.lib
jpeg\install\lib\libjpeg.lib
lmdb\install\lib\lmdb.lib
jsoncpp\src\jsoncpp\src\lib_json\$(Configuration)\jsoncpp.lib
farmhash\install\lib\farmhash.lib
fft2d\\src\lib\fft2d.lib
highwayhash\install\lib\highwayhash.lib
nsync\install\lib\nsync.lib
protobuf\src\protobuf\$(Configuration)\libprotobuf.lib
re2\src\re2\$(Configuration)\re2.lib
sqlite\install\lib\sqlite.lib
grpc\src\grpc\Release\grpc++_unsecure.lib
grpc\src\grpc\Release\grpc_unsecure.lib
grpc\src\grpc\Release\gpr.lib
snappy\src\snappy\$(Configuration)\snappy.lib
```

Furthermore, there are object file dependencies described in the cmake file. They're all resolved and collected into the [collect script](./collect.sh)

## Build Training Example
Tensorflow has this [trainer example](https://github.com/tensorflow/tensorflow/blob/a77096897f1a8068ca8f57ffb6e3d9e28508cc27/tensorflow/cc/tutorials/example_trainer.cc) to demonstrate the use of C++ API. That demo code is copied under the [example](./example/cc_trainer/Source.cpp), and a working Visual Studio project is located under the [example](./example) folder.

Just open the [Visual Studio project](./example/cc_trainer.sln), and you are good to go!
