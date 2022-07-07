
perftools功能：CPU和内存消耗

# 参考链接
    https://xusenqi.site/2020/12/06/C++Profile%E7%9A%84%E5%A4%A7%E6%9D%80%E5%99%A8_gperftools%E7%9A%84%E4%BD%BF%E7%94%A8/
# 安装库
## 安装libunwind
    wget http://download.savannah.gnu.org/releases/libunwind/libunwind-0.99-beta.tar.gz
    tar -zxvf libunwind-0.99-beta.tar.gz
    cd libunwind-0.99-beta/
    ./configure
    make&make install
    echo "/usr/local/lib" > /etc/ld.so.conf.d/usr_local_lib.conf
    /sbin/ldconfig

## 安装graphviz
    yum install graphviz
    yum -y install ghostscript

## 安装perftools
    git clone https://github.com/gperftools/gperftools.git
    cd gperftools/
    ./autogen.sh
    ./configure
    make&make install

# 避免编译机或运行机找不到动态库
    find / -type f -name "libprofiler.so*"
    ln -sv /usr/local/lib/libprofiler.so.0.5.5 /lib64/libprofiler.so.0
    ln -sv /usr/local/lib/libtcmalloc.so.4 /lib64/libtcmalloc.so.4

# gcc编译添加
    -lprofiler -ltcmalloc

# 添加环境变量，并执行
    CPUPROFILE=./test_cpu.prof /data/ssz/income_access/bin/income_access  'account_date=20210701&task_type=114&bank_type=19&task_id=114190719' '/data/ssz/income_access/conf/income_access_config.xml'

    env HEAPPROFILE=./test_heap.prof /data/ssz/income_access/bin/income_access  'account_date=20210701&task_type=114&bank_type=19&task_id=114190719' '/data/ssz/income_access/conf/income_access_config.xml'

# 生成
    pprof --text income_access test_cpu.prof > test_cpu.txt
    pprof --pdf income_access test_cpu.prof > test_cpu.pdf

    pprof --text income_access test_heap.prof.0001.heap
    pprof --pdf income_access test_heap.prof.0001.heap > ./test_heap.pdf

# 只部分代码生成profile文件
    #include <gperftools/profiler.h>
    ProfilerStart("test.prof");
    ProfilerStop();

