set -x

BASE=./tensorflow/tensorflow/contrib/cmake/build
INCLUDE=./include
LIB=./lib

mkdir -p ${INCLUDE}
cp -R ${BASE}/tensorflow ${INCLUDE}/
cp -R ${BASE}/external/eigen_archive/* ${INCLUDE}/
cp -R ${BASE}/protobuf/src/protobuf/src/* ${INCLUDE}/
cp -R ${BASE}/nsync/install/include/* ${INCLUDE}/

mkdir -p ${LIB}
	
cp ${BASE}/tf_cc.dir/Release/tf_cc.lib ${LIB}/
cp ${BASE}/tf_core_lib.dir/Release/tf_core_lib.lib ${LIB}/
cp ${BASE}/tf_core_cpu.dir/Release/tf_core_cpu.lib ${LIB}/
cp ${BASE}/tf_core_framework.dir/Release/tf_core_framework.lib ${LIB}/
cp ${BASE}/tf_core_kernels.dir/Release/tf_core_kernels.lib ${LIB}/
cp ${BASE}/tf_cc_framework.dir/Release/tf_cc_framework.lib ${LIB}/
cp ${BASE}/tf_cc_while_loop.dir/Release/tf_cc_while_loop.lib ${LIB}/
cp ${BASE}/tf_cc_ops.dir/Release/tf_cc_ops.lib ${LIB}/
cp ${BASE}/tf_core_ops.dir/Release/tf_core_ops.lib ${LIB}/
cp ${BASE}/tf_core_direct_session.dir/Release/tf_core_direct_session.lib ${LIB}/

cp ${BASE}/Release/tf_protos_cc.lib ${LIB}/
cp ${BASE}/zlib/install/lib/zlibstatic.lib ${LIB}/
cp ${BASE}/gif/install/lib/giflib.lib ${LIB}/
cp ${BASE}/png/install/lib/libpng12_static.lib ${LIB}/
cp ${BASE}/jpeg/install/lib/libjpeg.lib ${LIB}/
cp ${BASE}/lmdb/install/lib/lmdb.lib ${LIB}/
cp ${BASE}/jsoncpp/src/jsoncpp/src/lib_json/Release/jsoncpp.lib ${LIB}/
cp ${BASE}/farmhash/install/lib/farmhash.lib ${LIB}/
cp ${BASE}/fft2d//src/lib/fft2d.lib ${LIB}/
cp ${BASE}/highwayhash/install/lib/highwayhash.lib ${LIB}/
cp ${BASE}/nsync/install/lib/nsync.lib ${LIB}/
cp ${BASE}/protobuf/src/protobuf/Release/libprotobuf.lib ${LIB}/
cp ${BASE}/re2/install/lib/re2.lib ${LIB}/
cp ${BASE}/sqlite/install/lib/sqlite.lib ${LIB}/
cp ${BASE}/grpc/src/grpc/Release/grpc++_unsecure.lib ${LIB}/
cp ${BASE}/grpc/src/grpc/Release/grpc_unsecure.lib ${LIB}/
cp ${BASE}/grpc/src/grpc/Release/gpr.lib ${LIB}/
cp ${BASE}/snappy/src/snappy/Release/snappy.lib ${LIB}/
